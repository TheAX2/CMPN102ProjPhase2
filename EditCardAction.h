#pragma once
#include "Action.h"
class EditCardAction :public Action
{
	CellPosition cardPosition;
	Card* pCard;
	public:
	EditCardAction(ApplicationManager* pApp);
	  // Constructor

	

	virtual void ReadActionParameters() ;// Reads parameters required for action to execute 
	
											

	virtual void Execute() ;  // Executes action 
	
	virtual ~EditCardAction();  // Virtual Destructor
};

