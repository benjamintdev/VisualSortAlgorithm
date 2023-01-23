#include "menustatemachine.h"

MenuStateMachine::MenuStateMachine()
{
    CurrentState = STATE_MENU_HOME;
}

void MenuStateMachine::gotoHomeState()
{
    std::cout << "MenuStateMachine::gotoHomeState()" << std::endl;
    this->setCurrentState(STATE_MENU_HOME);
}

void MenuStateMachine::gotoStartState()
{
    std::cout << "MenuStateMachine::gotoStartState()" << std::endl;
    this->setCurrentState(STATE_MENU_START);
}

void MenuStateMachine::gotoInfoState()
{
    std::cout << "MenuStateMachine::gotoInfoState()" << std::endl;
    this->setCurrentState(STATE_MENU_INFO);
}

void MenuStateMachine::gotoQuitState()
{
    std::cout << "MenuStateMachine::gotoQuitState()" << std::endl;
    this->setCurrentState(STATE_MENU_QUIT);
}

void MenuStateMachine::gotoIdleState()
{
    std::cout << "MenuStateMachine::gotoIdleState()" << std::endl;
    this->setCurrentState(STATE_MENU_IDLE);
}

int MenuStateMachine::getCurrentState()
{
    return this->CurrentState;
}

void MenuStateMachine::setCurrentState(int state)
{
    this->setPreviousState(this->getCurrentState());
    this->CurrentState = state;
}

int MenuStateMachine::getPreviousState()
{
    return this->PreviousState;
}

void MenuStateMachine::setPreviousState(int state)
{
    this->PreviousState = state;
}