#include "controller.h"

void Controller::HandleInput(bool &isRunning, VisualizerStateMachine &VisualizerSM, MenuStateMachine &menuSM) const
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      isRunning = false;
    }
    else if (e.type == SDL_KEYDOWN)
    {
      switch (e.key.keysym.sym)
      {

      case SDLK_UP:

        if (VisualizerSM.getCurrentState() == STATE_HOME)
        {
          if (menuSM.getCurrentState() == STATE_MENU_IDLE)
          {
            if (menuSM.getPreviousState() == STATE_MENU_START)
            {
              menuSM.gotoQuitState();
            }
            else if (menuSM.getPreviousState() == STATE_MENU_INFO)
            {
              menuSM.gotoStartState();
            }
            else if (menuSM.getPreviousState() == STATE_MENU_QUIT)
            {
              menuSM.gotoInfoState();
            }
          }
        }

        break;

      case SDLK_DOWN:
        if (VisualizerSM.getCurrentState() == STATE_HOME)
        {
          if (menuSM.getCurrentState() == STATE_MENU_IDLE)
          {
            if (menuSM.getPreviousState() == STATE_MENU_START)
            {
              menuSM.gotoInfoState();
            }
            else if (menuSM.getPreviousState() == STATE_MENU_INFO)
            {
              menuSM.gotoQuitState();
            }
            else if (menuSM.getPreviousState() == STATE_MENU_QUIT)
            {
              menuSM.gotoStartState();
            }
          }
        }
        break;

      case SDLK_LEFT:
        break;

      case SDLK_RIGHT:
        break;

      case SDLK_SPACE:

        if (VisualizerSM.getCurrentState() == STATE_START)
        {
          VisualizerSM.gotoRunState();
        }
        else if (VisualizerSM.getCurrentState() == STATE_START_IDLE)
        {
          VisualizerSM.gotoRunState();
        }
        else if (VisualizerSM.getCurrentState() == STATE_INFO_IDLE)
        {
          VisualizerSM.gotoHomeState();
          menuSM.gotoHomeState();
        }
        else if (VisualizerSM.getCurrentState() == STATE_END_IDLE)
        {
          VisualizerSM.gotoHomeState();
          menuSM.gotoHomeState();
        }

        if (menuSM.getCurrentState() == STATE_MENU_IDLE)
        {
          if (VisualizerSM.getCurrentState() == STATE_HOME)
          {
            if (menuSM.getPreviousState() == STATE_MENU_START)
            {
              VisualizerSM.gotoStartState();
            }
            else if (menuSM.getPreviousState() == STATE_MENU_INFO)
            {
              VisualizerSM.gotoInfoState();
            }
            else if (menuSM.getPreviousState() == STATE_MENU_QUIT)
            {
              std::cout << "QUIT" << std::endl;
              std::cout << "Bye..." << std::endl;
              std::exit(0);
            }
          }
        }

        break;

      case SDLK_RETURN:

        if (VisualizerSM.getCurrentState() == STATE_START)
        {
          VisualizerSM.gotoRunState();
        }
        else if (VisualizerSM.getCurrentState() == STATE_START_IDLE)
        {
          VisualizerSM.gotoRunState();
        }
        else if (VisualizerSM.getCurrentState() == STATE_INFO_IDLE)
        {
          VisualizerSM.gotoHomeState();
          menuSM.gotoHomeState();
        }
        else if (VisualizerSM.getCurrentState() == STATE_END_IDLE)
        {
          VisualizerSM.gotoHomeState();
          menuSM.gotoHomeState();
        }

        if (menuSM.getCurrentState() == STATE_MENU_IDLE)
        {
          if (VisualizerSM.getCurrentState() == STATE_HOME)
          {
            if (menuSM.getPreviousState() == STATE_MENU_START)
            {
              VisualizerSM.gotoStartState();
            }
            else if (menuSM.getPreviousState() == STATE_MENU_INFO)
            {
              VisualizerSM.gotoInfoState();
            }
            else if (menuSM.getPreviousState() == STATE_MENU_QUIT)
            {
              std::cout << "QUIT" << std::endl;
              std::cout << "Bye..." << std::endl;
              std::exit(0);
            }
          }
        }

        break;
      }
    }
  }
}