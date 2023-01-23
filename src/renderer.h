#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_ttf.h>

#include "visualizerstatemachine.h"

class Renderer
{

public:
  Renderer(int Width, int Height);
  ~Renderer();

  void renderSelectSort(std::vector<int> data, VisualizerStateMachine &VSM);
  void renderBubbleSort(std::vector<int> data, VisualizerStateMachine &VSM);
  void renderInsertSort(std::vector<int> data, VisualizerStateMachine &VSM);
  void renderMergeSort(std::vector<int> data, VisualizerStateMachine &VSM);
  void renderQuickSort(std::vector<int> data, VisualizerStateMachine &VSM);

  void RenderValues(std::vector<int> Values, int red, int green, std::string Title);

  void RenderStart(VisualizerStateMachine &VSM);

  void RenderEnd(VisualizerStateMachine &VSM);

  void RenderInfo(VisualizerStateMachine &VSM);

  void RenderMenuIcon(int IconPosition);
  void RenderMenuText();

private:
  SDL_Window *SDLWindow;
  SDL_Renderer *SDLRenderer;

  int ScreenWidth;
  int ScreenHeight;

  void renderTextEffect(std::string text, int size, int x, int y, int level);

  void renderTexture(SDL_Texture *SDLTexture, SDL_Renderer *SDLRenderer, SDL_Rect dst, SDL_Rect *clip);

  void renderTexture(SDL_Texture *SDLTexture, SDL_Renderer *SDLRenderer, int XPosition, int YPosition, SDL_Rect *clip);

  SDL_Texture *renderText(const std::string &Message, const std::string &FontFile, SDL_Color SDLColor, int FontSize, SDL_Renderer *SDLRenderer);
};

#endif