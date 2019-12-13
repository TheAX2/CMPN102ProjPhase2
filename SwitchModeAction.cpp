#include "SwitchModeAction.h"



SwitchModeAction::SwitchModeAction(ApplicationManager* pApp, int s) : Action(pApp)
{
	state = s;
	// Initializes the pManager pointer of Action with the passed pointer
}


void SwitchModeAction::ReadActionParameters()
{

}

void SwitchModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	if (state == 0)
	{
		
		pOut->CreatePlayModeToolBar();
		
	}
	else {

		pOut->CreateDesignModeToolBar();

	}
}

SwitchModeAction::~SwitchModeAction()
{

}