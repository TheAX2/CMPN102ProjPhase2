#include "CutCardAction.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{

}

CutCardAction::~CutCardAction()
{
}

void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->PrintMessage("Click on a Card to copy it .....");
	CelltoCut = pIn->GetCellClicked();
	CellPosition InVal(-1, -1);
	if (!CelltoCut.IsValidCell())
	{
		CelltoCut = InVal;
		pGrid->PrintErrorMessage("Invalid Cell ...");
		return;
	}
	pOut->ClearStatusBar();


}

void CutCardAction::Execute()
{

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();
	if (!CelltoCut.IsValidCell())
	{

		return;
	}
	if (!pGrid->HasCardFromCellPos(CelltoCut))
	{
		pGrid->PrintErrorMessage("Cell doesn't have a card");
		return;
	}
	pGrid->SetClipboardfromCellPos(CelltoCut);
	pGrid->RemoveObjectFromCell(CelltoCut);
}