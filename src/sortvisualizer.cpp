#include "sortvisualizer.h"

SortVisualizer::SortVisualizer(int screenwidth, int screenheight)
{
  this->ScreenHeight = screenheight;
  this->ScreenWidth = screenwidth;

  // this->SetReset();
}

void SortVisualizer::SetReset()
{
}

void SortVisualizer::Run(Controller const &controller, Renderer &renderer)
{
  int CurrentFrameStartTime;
  int CurrentFrameEndTime;

  this->isRunning = true;

  while (this->isRunning)
  {
    CurrentFrameStartTime = SDL_GetTicks();

    controller.HandleInput(this->isRunning, this->VisualizerSM, this->MenuSM);

    if (this->VisualizerSM.getCurrentState() == STATE_HOME)
    {
      if (this->MenuSM.getCurrentState() == STATE_MENU_HOME)
      {
        renderer.RenderMenuText();
        MenuSM.gotoStartState();
      }
      else if (this->MenuSM.getCurrentState() == STATE_MENU_START)
      {
        renderer.RenderMenuIcon(STATE_MENU_START);
        renderer.RenderMenuText();

        MenuSM.gotoIdleState();
      }
      else if (this->MenuSM.getCurrentState() == STATE_MENU_INFO)
      {
        renderer.RenderMenuIcon(STATE_MENU_INFO);
        renderer.RenderMenuText();
        MenuSM.gotoIdleState();
      }
      else if (this->MenuSM.getCurrentState() == STATE_MENU_QUIT)
      {
        renderer.RenderMenuIcon(STATE_MENU_QUIT);
        renderer.RenderMenuText();
        MenuSM.gotoIdleState();
      }
    }

    if (this->VisualizerSM.getCurrentState() == STATE_START)
    {
      renderer.RenderStart(this->VisualizerSM);
    }

    if (this->VisualizerSM.getCurrentState() == STATE_RUN)
    {
      // this->SetReset();

      std::random_device RandomDevice;
      std::mt19937 RandomGenerator(RandomDevice());
      std::uniform_int_distribution<int> ValueDistribution(0, 600);
      std::vector<int> test;
      for (int i = 0; i < 450; i++)
      {
        test.emplace_back(ValueDistribution(RandomGenerator));
      }

      std::uniform_int_distribution<int> AlgoDistribution(1, 4);

      switch (AlgoDistribution(RandomGenerator))
      {
      case 1:
        renderer.renderSelectSort(test, this->VisualizerSM);
        break;

      case 2:
        renderer.renderBubbleSort(test, this->VisualizerSM);
        break;

      case 3:
        renderer.renderInsertSort(test, this->VisualizerSM);
        break;

      case 4:
        renderer.renderQuickSort(test, this->VisualizerSM);
        break;

      case 5:
        renderer.renderMergeSort(test, this->VisualizerSM);
        break;

      default:
        break;
      }
    }

    if (this->VisualizerSM.getCurrentState() == STATE_END)
    {
      renderer.RenderEnd(this->VisualizerSM);
      static int count = 0;
      count++;

      if (count >= 100)
      {
        this->VisualizerSM.gotoEndIdleState();
        count = 0;
      }
    }

    if (this->VisualizerSM.getCurrentState() == STATE_INFO)
    {
      renderer.RenderInfo(this->VisualizerSM);
    }
  }
}