#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <iostream>
#include <random>
#include <math.h>

#include "SDL.h"

#include "visualizerstatemachine.h"
#include "menustatemachine.h"

class Controller
{
public:
  void HandleInput(bool &running, VisualizerStateMachine & VisualizerSM, MenuStateMachine &menuSM) const;

private:

};

#endif