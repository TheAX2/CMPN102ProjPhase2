#pragma once
#include "Action.h"
class LoadGridAction :
	public Action
{

private:
	string filename;

public:
	LoadGridAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~LoadGridAction();


};

