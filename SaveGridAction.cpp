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

	pOut->PrintMessage("Enter Save File Name ....");
	filename = pIn->GetSrting(pOut);

	pOut->PrintMessage("Saving Current Grid .....");
	pIn->GetCellClicked();
}

void SaveGridAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();
	ofstream OutFile(filename,ios::out);
	OutFile.close();
	OutFile.open(filename,ios::app);
	if (OutFile.is_open())
	{
		
		pGrid->SaveAll(OutFile, 1);
		pGrid->SaveAll(OutFile, 2);
		pGrid->SaveAll(OutFile, 3);
		OutFile.close();
	}
	pOut->ClearStatusBar();

}
