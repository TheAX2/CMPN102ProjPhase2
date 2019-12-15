#pragma once
#include "Action.h"
class DeleteGameObjectAction :
	public Action
{
	CellPosition Celltodelete;
	string errormsg;

public:

	DeleteGameObjectAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // 

	virtual void Execute(); // 
							//


	virtual ~DeleteGameObjectAction(); // Virtual Destructor
};

