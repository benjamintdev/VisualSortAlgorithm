#ifndef SORTVISUALIZER_H
#define SORTVISUALIZER_H

#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#include "controller.h"
#include "renderer.h"

#include "visualizerstatemachine.h"
#include "menustatemachine.h"

class SortVisualizer
{
public:

  SortVisualizer(int ScreenWidth, int ScreenHeight);

  void SetReset();

  void Run(Controller const &controller, Renderer &renderer);

  // void regulateFrameRate(int frame_end, int frame_start);

  bool isRunning = false;

private:

  int ScreenWidth;
  int ScreenHeight;

  VisualizerStateMachine VisualizerSM;
  MenuStateMachine MenuSM;

};

#endif