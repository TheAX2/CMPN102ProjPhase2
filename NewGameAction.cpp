#include "NewGameAction.h"
#include "Player.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{

}

NewGameAction::~NewGameAction() 
{

}

void NewGameAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Starting New Game...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void NewGameAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	for (int i = 0;i < MaxPlayerCount;i++)
	{
		Player* pPlayer = pGrid->GetCurrentPlayer();
		if (pPlayer->GetplayerNum() == 0)
		{
			break;
		}
		pGrid->AdvanceCurrentPlayer();
	}
	CellPosition StartCell(1);
	for (int i = 0;i < MaxPlayerCount;i++)
	{
		Player* pPlayer = pGrid->GetCurrentPlayer();
		pPlayer->Settozero(pGrid);
		pGrid->AdvanceCurrentPlayer();

	}

	pGrid->ResetAllBoughtCards();

}

