#include "SaveGridAction.h"
#include <fstream>


SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

SaveGridAction::~SaveGridAction()
{

}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Enter Save File Name ...."); // Get the file name and store it
	filename = pIn->GetSrting(pOut);

	pOut->PrintMessage("Saving Current Grid .....");
	pIn->GetCellClicked();
}

void SaveGridAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();               // first read parameters to get and set the filname
	ofstream OutFile(filename,ios::out);
	if (OutFile.is_open())
	{
		
		pGrid->SaveAll(OutFile, 1);
		pGrid->SaveAll(OutFile, 2);
		pGrid->SaveAll(OutFile, 3);
		OutFile.close();

	}
	Card* c = new Card(1);
	c->Setsaved(false);     // Used the dummy card c to return all cards to non-saved state after saving to avoid errors when double saving
	pOut->ClearStatusBar();

}
