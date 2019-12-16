#include "SwitchModeAction.h"
#include "NewGameAction.h"



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
		NewGameAction Act(pManager);
		Act.Execute();
		
	}
	else {

		pOut->CreateDesignModeToolBar();

	}



}

SwitchModeAction::~SwitchModeAction()
{

}