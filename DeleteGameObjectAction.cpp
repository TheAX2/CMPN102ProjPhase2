#include "DeleteGameObjectAction.h"


DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void DeleteGameObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	
	pOut->PrintMessage("Click on a Ladder or Snake or Card to delete it ...");
	Celltodelete = pIn->GetCellClicked();
	CellPosition InVal(-1, -1);
	if (!Celltodelete.IsValidCell())
	{
		Celltodelete = InVal;
		errormsg = "Invalid Cell ...";
		return;
	}
	pOut->ClearStatusBar();
}

void DeleteGameObjectAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();
	if (!Celltodelete.IsValidCell())
	{
		pGrid->PrintErrorMessage(errormsg);
		return;
	}
	pGrid->RemoveObjectFromCell(Celltodelete);
}

DeleteGameObjectAction::~DeleteGameObjectAction()
{
}