#ifndef VISUALIZERSTATEMACHINE_H
#define VISUALIZERSTATEMACHINE_H

#include <iostream>

//  States for program control
#define STATE_HOME 0
#define STATE_START 1
#define STATE_START_IDLE 9
#define STATE_RUN 2
#define STATE_END 3
#define STATE_END_IDLE 4
#define STATE_INFO 7
#define STATE_INFO_IDLE 8

class VisualizerStateMachine
{

public:
VisualizerStateMachine();

void gotoHomeState();
void gotoStartState();
void gotoStartIdleState();
void gotoRunState();
void gotoEndState();
void gotoEndIdleState();
void gotoInfoState();
void gotoInfoIdleState();

int getCurrentState();
void setCurrentState(int state);

private:
int CurrentState;

};

#endif