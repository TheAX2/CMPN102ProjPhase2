#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	errormsg = "Error: Cell already has an object! Click to continue ...";
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();
	CellPosition InVal(-1, -1);
	if (!startPos.IsValidCell())
	{
		startPos = InVal;
		errormsg = "Invalid Cell ...";
		return;
	}

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	if (!endPos.IsValidCell())
	{
		startPos = InVal;
		endPos = InVal;
		errormsg = "Invalid Cell ...";
		return;
	}


	///TODO: Make the needed validations on the read parameters
	
	if (startPos.HCell() != endPos.HCell())
	{
		startPos = InVal;
		endPos = InVal;
		errormsg = "End Cell and Start Cell are not in the same column ";
		return;
	}
	if (startPos.GetCellNum() >= endPos.GetCellNum())
	{
		startPos = InVal;
		endPos = InVal;
		errormsg = "End Cell cannot be smaller then Start Cell";
		return;
	}
	Ladder* pLadder = new Ladder(startPos, endPos);
	
	int num = pGrid->IsEndOfLadderStart(pLadder);
	if (num == 1)
	{
		startPos = InVal;
		endPos = InVal;
		errormsg = "End Cell cannot be start of snake";
		return;
	}
	if(num == 2)
	{
		startPos = InVal;
		endPos = InVal;
		errormsg = "End Cell cannot be start of Ladder";
		return;
	}
	
	if (pGrid->IsOverLapping(pLadder))
	{
		startPos = InVal;
		endPos = InVal;
		errormsg = "Two Ladder Cannot Overlap";
		return;
	}
	

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (! added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage(errormsg);
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
