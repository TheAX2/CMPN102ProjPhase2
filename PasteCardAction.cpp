#include "PasteCardAction.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->PrintMessage("Click on a Cell to paste your card ...");
	CelltoPasteAt = pIn->GetCellClicked();
	CellPosition InVal(-1, -1);
	if (!CelltoPasteAt.IsValidCell())
	{
		CelltoPasteAt = InVal;
		pGrid->PrintErrorMessage("Invalid Cell ...");
		return;
	}
	pOut->ClearStatusBar();
}

void PasteCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();
	if (!CelltoPasteAt.IsValidCell())
	{
		
		return;
	}
	if (!pGrid->GetClipboard()) {
		return;
	}
	Card* pCard = pGrid->GetClipboard();
	pCard->Setposition(CelltoPasteAt);
	pGrid->AddObjectToCell(pCard);

}

PasteCardAction::~PasteCardAction()
{
}