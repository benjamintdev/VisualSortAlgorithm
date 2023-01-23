#ifndef MENUSTATEMACHINE_H
#define MENUSTATEMACHINE_H

#include <iostream>

//  States for program control
#define STATE_MENU_HOME 0
#define STATE_MENU_START 1
#define STATE_MENU_INFO 2
#define STATE_MENU_QUIT 3
#define STATE_MENU_IDLE 4

class MenuStateMachine
{

public:

MenuStateMachine();

void gotoHomeState();
void gotoStartState();
void gotoInfoState();
void gotoQuitState();
void gotoIdleState();

int getCurrentState();
void setCurrentState(int state);

int getPreviousState();

private:

int CurrentState;
int PreviousState;

void setPreviousState(int state);

};

#endif