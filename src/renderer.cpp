#include "renderer.h"

Renderer::Renderer(int screenwidth, int screenheight)
{

  this->ScreenHeight = screenheight;
  this->ScreenWidth = screenwidth;

  // Init SDL
  // SDL_Init(SDL_INIT_VIDEO);
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();

  // Create SDL window
  SDLWindow = SDL_CreateWindow("SortVisualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);

  // Create SDL renderer
  SDLRenderer = SDL_CreateRenderer(SDLWindow, -1, SDL_RENDERER_ACCELERATED);
}

Renderer::~Renderer()
{
  SDL_DestroyWindow(SDLWindow);
  SDL_Quit();
}

void Renderer::swapInplace(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void Renderer::renderTexture(SDL_Texture *SDLTexture, SDL_Renderer *SDLRenderer, SDL_Rect SDLRect_dst, SDL_Rect *SDLRect_src = nullptr)
{
  SDL_RenderCopy(SDLRenderer, SDLTexture, SDLRect_src, &SDLRect_dst);
}

void Renderer::renderTexture(SDL_Texture *SDLTexture, SDL_Renderer *SDLRenderer, int XPosition, int YPosition, SDL_Rect *SDLRect = nullptr)
{
  SDL_Rect temp;
  temp.x = XPosition;
  temp.y = YPosition;
  if (SDLRect != nullptr)
  {
    temp.w = SDLRect->w;
    temp.h = SDLRect->h;
  }
  else
  {
    SDL_QueryTexture(SDLTexture, NULL, NULL, &temp.w, &temp.h);
  }
  renderTexture(SDLTexture, SDLRenderer, temp, SDLRect);
}

SDL_Texture *Renderer::renderText(const std::string &Message, const std::string &FontFile, SDL_Color SDLColor, int FontSize, SDL_Renderer *SDLRenderer)
{
  // open TFF font
  TTF_Font *TFFFont = TTF_OpenFont(FontFile.c_str(), FontSize);
  if (TFFFont == nullptr) // if fail
  {
    std::cout << "TTF_Font Error " << TTF_GetError() << std::endl;
    std::cout << FontFile.c_str() << std::endl;
    return nullptr;
  }

  // cfreate surface and render message txt to it
  SDL_Surface *SDLSurface = TTF_RenderText_Blended(TFFFont, Message.c_str(), SDLColor);
  if (SDLSurface == nullptr) // if fail
  {
    std::cout << "SDL_Surface Error " << TTF_GetError() << std::endl;
    TTF_CloseFont(TFFFont); // clear up
    return nullptr;
  }

  // create texture from surface with rendered text that we return
  SDL_Texture *SDLTexture = SDL_CreateTextureFromSurface(SDLRenderer, SDLSurface);

  // clear up
  SDL_FreeSurface(SDLSurface);
  TTF_CloseFont(TFFFont);

  return SDLTexture;
}

void Renderer::renderTextEffect(std::string text, int size, int x, int y, int level)
{
  for (int i = 1; i <= 3; i++)
  {
    SDL_Color color = {255, 255, 255, static_cast<Uint8>(255 / i)};
    SDL_Texture *image = renderText(text, "sample.ttf", color, size + (i * level), SDLRenderer);
    renderTexture(image, SDLRenderer, x, y);
  }
}

void Renderer::RenderMenuIcon(int IconPosition)
{
  // std::cout << "Renderer::RenderMenuIcon" << std::endl;

  SDL_Color LightColor = {255, 255, 255, 255};
  SDL_Texture *LightIcon = renderText(">", "sample.ttf", LightColor, 128, SDLRenderer);

  SDL_Color DarkColor = {0x1E, 0x1E, 0x1E, 0xFF};
  SDL_Texture *DarkIcon = renderText(">", "sample.ttf", DarkColor, 128, SDLRenderer);

  if (IconPosition == 1)
  {
    renderTexture(LightIcon, SDLRenderer, 200, 175);
    renderTexture(DarkIcon, SDLRenderer, 200, 275);
    renderTexture(DarkIcon, SDLRenderer, 200, 375);
  }
  else if (IconPosition == 2)
  {
    renderTexture(DarkIcon, SDLRenderer, 200, 175);
    renderTexture(LightIcon, SDLRenderer, 200, 275);
    renderTexture(DarkIcon, SDLRenderer, 200, 375);
  }
  else if (IconPosition == 3)
  {
    renderTexture(DarkIcon, SDLRenderer, 200, 175);
    renderTexture(DarkIcon, SDLRenderer, 200, 275);
    renderTexture(LightIcon, SDLRenderer, 200, 375);
  }

  SDL_RenderPresent(SDLRenderer);
}

void Renderer::RenderMenuText()
{

  // std::cout << "Renderer::RenderMenu" << std::endl;

  TTF_Init();

  // Clear screen
  SDL_SetRenderDrawColor(SDLRenderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(SDLRenderer);

  this->renderTextEffect("SortVisualizer", 128, 200, 50, 1);

  this->renderTextEffect("Start", 64, 300, 200, 2);

  this->renderTextEffect("About", 64, 300, 300, 1);

  this->renderTextEffect("Quit", 64, 300, 400, 1);

  this->renderTextEffect("github.com/benjamintdev/VisualSortAlgo", 16, 300, 600, 0);

  // this->renderTextEffect("www.benjamint.dev", 16, 300, 600, 0);
}

void Renderer::renderSelectSort(std::vector<int> &Data, VisualizerStateMachine &VSM)
{

  this->renderTextEffect("github.com/benjamintdev/VisualSortAlgo", 16, 300, 600, 0);

  // Cycle through Data
  for (int i = 0; i < Data.size(); i++)
  {
    // Start with minimum elemnt index as current loop index i
    int MinimumValueIndex = i;

    // Find the minimum element in unsorted se start from index after current index i
    for (int j = i + 1; j < Data.size(); j++)
    {
      // Current element Data.at(j) is smaller than min element identifued by previous cycles
      if (Data.at(j) < Data.at(MinimumValueIndex))
      {
        MinimumValueIndex = j; // Set min element index as j, so min element set as Data.at(j)
        this->RenderValues(Data, j, i, "Selection Sort");
      }
    }

    // Swap the minimum element values found with 1st element of unsorted section (if not the same)
    if (!(MinimumValueIndex == i))
    {
      // swapInplace(Data.at(i), Data.at(MinimumValueIndex));
      swapInplace(&Data.at(i), &Data.at(MinimumValueIndex));
    }
  }
  VSM.gotoEndState();
}

void Renderer::renderBubbleSort(std::vector<int> &Data, VisualizerStateMachine &VSM)
{
  this->renderTextEffect("github.com/benjamintdev/VisualSortAlgo", 16, 300, 600, 0);

  // to log that a swap has occored in this pass
  bool haveSwapped;

  // outer loop
  for (int i = 0; i < Data.size(); i++)
  {
    // reset that a swap has occored in this pass
    haveSwapped = false;

    // inner loop
    for (int j = 0; j < (Data.size() - i) - 1; ++j)
    {
      // Compare values for current item j and next item j + 1
      if (Data.at(j) > Data.at(j + 1))
      {
        // swap if current item j is larger
        // swapInplace(Data.at(j), Data.at(j + 1));
        swapInplace(&Data.at(j), &Data.at(j + 1));
        // log that a swap has occored in this pass
        haveSwapped = true;
      }
    } // end inner loop

    // rendering current state of Data
    this->RenderValues(Data, i, i, "Bubble Sort");

    // check if a swap has occored in this pass, if not then we are sorted
    if (!haveSwapped)
    {
      // break outer loop if we are sorted
      break;
    }

  } // end outer loop

  // algorthm has run send state machine to end state
  VSM.gotoEndState();
}

void Renderer::renderInsertSort(std::vector<int> &Data, VisualizerStateMachine &VSM)
{
  this->renderTextEffect("github.com/benjamintdev/VisualSortAlgo", 16, 300, 600, 0);

  // outer loop
  for (int i = 0; i < Data.size(); i++)
  {
    // temp store value at index i as will be modifying inplace
    int temp = Data.at(i);

    // set j to index before i
    int j = i - 1;

    // inner loop
    // if value at j is larger than value at index i (temp stored) // stop if have moved back through all Data
    while (j >= 0 && Data.at(j) > temp)
    {
      Data.at(j + 1) = Data.at(j);
      // move back through Data
      j--;
    }
    // place temp value
    Data.at(j + 1) = temp;

    // rendering current state of Data
    this->RenderValues(Data, i, j, "Insert Sort");

  } // end outer loop

  // algorthm has run send state machine to end state
  VSM.gotoEndState();
}

void Renderer::mergeSort(std::vector<int> &Data, int lowIndex, int highIndex)
{

  if (lowIndex >= highIndex)
  {
    return;
  }

  // find midIndex
  int midIndex = lowIndex + (highIndex - lowIndex) / 2;

  // recursive calls
  mergeSort(Data, lowIndex, midIndex);
  mergeSort(Data, midIndex + 1, highIndex);

  // Copy data to temp vectors leftData[] and rightData[]
  std::vector<int> leftData;
  std::vector<int> rightData;
  int leftDataSize = midIndex - lowIndex + 1;
  int rightDataSize = highIndex - midIndex;
  for (auto i = 0; i < leftDataSize; i++)
  {
    leftData.emplace_back(Data[lowIndex + i]);
  }
  for (auto j = 0; j < rightDataSize; j++)
  {
    rightData.emplace_back(Data[midIndex + 1 + j]);
  }

  int i = 0, j = 0; // Initial indcies of leftData && RightData to look at during merge
  int k = lowIndex; // Initial index of merged Data to look at during merge

  // Merge leftData && RightData into merged Data
  while (i < leftDataSize && j < rightDataSize)
  {
    if (leftData.at(i) <= rightData.at(j))
    {
      Data[k] = leftData[i];
      i++;
    }
    else
    {
      Data[k] = rightData[j];
      j++;
    }
    k++;
  }

  // if data being merged are uneven in size then place remaining into merged data at the end
  // Left
  while (i < leftDataSize)
  {
    Data[k] = leftData[i];
    i++;
    k++;
  }
  // Right
  while (j < rightDataSize)
  {
    Data[k] = rightData[j];
    j++;
    k++;
  }

  // render Data
  this->RenderValues(Data, lowIndex, highIndex, "Merge Sort");
}

void Renderer::renderMergeSort(std::vector<int> &Data, VisualizerStateMachine &VSM)
{
  this->renderTextEffect("github.com/benjamintdev/VisualSortAlgo", 16, 300, 600, 0);

  this->mergeSort(Data, 0, Data.size() - 1);

  VSM.gotoEndState();
}

void Renderer::quickSort(std::vector<int> &Data, int lowIndex, int highIndex)
{
  // check indices are in order
  if (lowIndex < highIndex)
  {
    /// Partition ///
    int pivotPointValue = Data[highIndex]; // set pivotPointValue to highIndex Value

    int j = lowIndex - 1; // temp piviot index

    for (int i = lowIndex; i <= highIndex; ++i)
    {
      // if element value at i is less than the pivotPointValue then increment j and swap values at i & j
      if (Data[i] < pivotPointValue)
      {
        ++j;

        // render Data
        this->RenderValues(Data, j, i, "QuickSort");

        swapInplace(&Data[j], &Data[i]); // swap current element with element at temp piviot index
      }
    }
    // set pivotPoint to correct index
    int pivotPoint = j + 1;

    swapInplace(&Data[j + 1], &Data[highIndex]);
    /// End partition ///

    /// Recursive calls///
    // recursiveley quicksort Data on upper side of pivotPoint
    quickSort(Data, pivotPoint + 1, highIndex);
    // recursiveley quicksort Data on lower side of pivotPoint
    quickSort(Data, lowIndex, pivotPoint - 1);
    /// End recursive calls ///
  }
}

void Renderer::renderQuickSort(std::vector<int> &Data, VisualizerStateMachine &VSM)
{
  this->renderTextEffect("github.com/benjamintdev/VisualSortAlgo", 16, 300, 600, 0);

  int lowIndex = 0;
  int highIndex = Data.size() - 1;

  this->quickSort(Data, lowIndex, highIndex);

  VSM.gotoEndState();
}

void Renderer::RenderValues(std::vector<int> Data, int red, int green, std::string Title)
{
  // std::cout << "Renderer::RenderValues()" << std::endl;
  int i = 0;
  int x = 50;
  int y = 600;
  SDL_SetRenderDrawColor(SDLRenderer, 0x00, 0x00, 0x00, 0x00);
  SDL_RenderClear(SDLRenderer);
  SDL_SetRenderDrawColor(SDLRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

  this->renderTextEffect(Title, 32, 50, 600, 1);
  this->renderTextEffect("github.com/benjamintdev/VisualSortAlgo", 16, 300, 600, 0);

  // for (auto &item : Data)
  // {
  //   SDL_RenderDrawLine(SDLRenderer, x + i, y, x + i, y - item);
  //   i += 2;
  // }
  for (int k = 0; k < Data.size(); k++)
  {
    if (k == red)
    {
      SDL_SetRenderDrawColor(SDLRenderer, 0xFF, 0x00, 0x00, 0xFF);
    }
    else if (k == green)
    {
      SDL_SetRenderDrawColor(SDLRenderer, 0x00, 0xFF, 0x00, 0xFF);
    }
    else
    {
      SDL_SetRenderDrawColor(SDLRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    SDL_RenderDrawLine(SDLRenderer, x + i, y, x + i, y - Data.at(k));
    i += 2;
  }

  SDL_RenderPresent(SDLRenderer);
  SDL_Delay(16);
}

void Renderer::RenderStart(VisualizerStateMachine &VSM)
{
  SDL_RenderClear(SDLRenderer);

  SDL_SetRenderDrawColor(SDLRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

  this->renderTextEffect("Press space to start", 64, 200, 150, 1);

  this->renderTextEffect("github.com/benjamintdev/VisualSortAlgo", 16, 300, 600, 0);

  SDL_RenderPresent(SDLRenderer);

  VSM.gotoStartIdleState();
}

void Renderer::RenderEnd(VisualizerStateMachine &VSM)
{
  this->renderTextEffect("Press space to reset", 64, 200, 150, 1);

  this->renderTextEffect("github.com/benjamintdev/VisualSortAlgo", 16, 300, 600, 0);

  SDL_RenderPresent(SDLRenderer);

  VSM.gotoEndIdleState();
}

void Renderer::RenderInfo(VisualizerStateMachine &VSM)
{
  std::cout << "Renderer::RenderInfo" << std::endl;

  SDL_RenderClear(SDLRenderer);
  // Page title
  this->renderTextEffect("About", 128, 200, 50, 2);
  // first paragraph
  this->renderTextEffect("My take and interpretation of a sorting algorithm visualization.", 32, 200, 200, 0);
  this->renderTextEffect("built with C++ and SDL2 (Simple DirectMedia Layer 2). ", 32, 200, 225, 0);
  this->renderTextEffect("as programming and sort algorithm practice. ", 32, 200, 250, 0);
  this->renderTextEffect("Please visit my github for code, github.com/benjamintdev ", 32, 200, 275, 0);
  // seccond paragraph
  this->renderTextEffect("For main menu press Enter", 32, 200, 325, 0);
  // footer
  this->renderTextEffect("www.libsdl.org", 16, 300, 550, 0);
  this->renderTextEffect("www.isocpp.org", 16, 300, 575, 0);
  this->renderTextEffect("github.com/benjamintdev/VisualSortAlgo", 16, 300, 600, 0);
  // this->renderTextEffect("www.benjamint.dev", 16, 300, 600, 0);

  SDL_RenderPresent(SDLRenderer);

  VSM.gotoInfoIdleState();
}