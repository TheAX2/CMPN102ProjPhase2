#include "LoadGridAction.h"
#include "Grid.h"
#include "Ladder.h"
#include "Card.h"
#include "Snake.h"

#include <fstream>


LoadGridAction::LoadGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

LoadGridAction::~LoadGridAction()
{

}

void LoadGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Enter File Name to Load....");
	filename = pIn->GetSrting(pOut);

	pOut->PrintMessage("Loading Current Grid .....");
	pIn->GetCellClicked();
}

void LoadGridAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();

	//
	pGrid->CleanInterface();
	//
	ifstream InFile;
	InFile.open(filename, ios::in);
	if (InFile.is_open())
	{
		
		CellPosition s, e;
		Ladder* pLadder = new Ladder(s,e);
		pLadder->Load(InFile,pGrid);
		Snake* pSnake = new Snake(s, e);
		pSnake->Load(InFile, pGrid);
		Card* pCard = new Card(s) ;
		pCard->Load(InFile, pGrid);
		InFile.close();
	}
	pOut->ClearStatusBar();

}
