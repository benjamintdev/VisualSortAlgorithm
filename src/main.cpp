#include <iostream>

#include "controller.h"
#include "renderer.h"
#include "sortvisualizer.h"

int main()
{
  const int ScreenWidth = 1024;
  const int ScreenHeight = 640;

  Controller controller;
  Renderer renderer(ScreenWidth, ScreenHeight);

  SortVisualizer sortvisualizer(ScreenWidth, ScreenHeight);
  sortvisualizer.Run(controller, renderer);

  std::cout << "EXIT_SUCCESS" << std::endl;
  exit(EXIT_SUCCESS);
}