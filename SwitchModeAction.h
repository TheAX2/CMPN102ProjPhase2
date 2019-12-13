#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"

class SwitchModeAction :
	public Action
{

private:
	int state; // A: 1 for design mode and 0 for play mode

public:
	SwitchModeAction(ApplicationManager* pApp, int);

	virtual void ReadActionParameters();

	virtual void Execute(); 

	virtual ~SwitchModeAction();
};

