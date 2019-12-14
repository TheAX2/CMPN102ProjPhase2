#pragma once
#include "Action.h"
#include "Grid.h"

class SaveGridAction :
	public Action
{

private:
	string filename;

public:
	SaveGridAction(ApplicationManager* pApp);
	
	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~SaveGridAction();


};

