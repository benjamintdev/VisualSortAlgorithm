
#include "visualizerstatemachine.h"

VisualizerStateMachine::VisualizerStateMachine()
{
        std::cout << "VisualizerStateMachine::gotoHomeState()" << std::endl;
        CurrentState = STATE_HOME;
}

void VisualizerStateMachine::gotoHomeState()
{
        std::cout << "VisualizerStateMachine::gotoHomeState()" << std::endl;
        this->CurrentState = STATE_HOME;
}

void VisualizerStateMachine::gotoStartState()
{
        std::cout << "VisualizerStateMachine::gotoStartState()" << std::endl;
        this->CurrentState = STATE_START;
}

void VisualizerStateMachine::gotoStartIdleState()
{
        std::cout << "VisualizerStateMachine::gotoStartIdleState()" << std::endl;
        this->CurrentState = STATE_START_IDLE;
}

void VisualizerStateMachine::gotoRunState()
{
        std::cout << "VisualizerStateMachine::gotoRunState()" << std::endl;
        this->CurrentState = STATE_RUN;
}

void VisualizerStateMachine::gotoEndState()
{
        std::cout << "VisualizerStateMachine::gotoEndState()" << std::endl;
        this->CurrentState = STATE_END;
}

void VisualizerStateMachine::gotoEndIdleState()
{
        std::cout << "VisualizerStateMachine::gotoEndIdleState()" << std::endl;
        this->CurrentState = STATE_END_IDLE;
}

void VisualizerStateMachine::gotoInfoState()
{
        std::cout << "VisualizerStateMachine::gotoInfoState()" << std::endl;
        this->CurrentState = STATE_INFO;
}

void VisualizerStateMachine::gotoInfoIdleState()
{
        std::cout << "VisualizerStateMachine::gotoInfoIdleState()" << std::endl;
        this->CurrentState = STATE_INFO_IDLE;
}

int VisualizerStateMachine::getCurrentState()
{
        return this->CurrentState;
}

void VisualizerStateMachine::setCurrentState(int state)
{
        this->CurrentState = state;
}