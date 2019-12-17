#include "LoadGridAction.h"
#include "Grid.h"
#include "Ladder.h"
#include "Card.h"
#include "Snake.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"
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
		
		CellPosition s, e;                 // Dummy cellpositions to intilize dummy game objects to run the load functions needed
		Ladder* pLadder = new Ladder(s,e);
		pLadder->Load(InFile,pGrid);
		Snake* pSnake = new Snake(s, e);
		pSnake->Load(InFile, pGrid);
		Card* pCard = new Card(s) ;
		pCard->Load(InFile, pGrid);
		InFile.close();
	}
	Card* c1 = new CardTen(1);
	Card* c2 = new CardEleven(1);
	Card* c3 = new CardTwelve(1);
	Card* c4 = new CardThirteen(1);
	Card* c5 = new CardFourteen(1);
	c1->Setloaded(false);     // Used the dummy card c to return all cards to non-loaded state after loading to avoid errors when double saving
	c2->Setloaded(false);
	c3->Setloaded(false);
	c4->Setloaded(false);
	c5->Setloaded(false);
	pOut->ClearStatusBar();

}
