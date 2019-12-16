#include "CopyCardAction.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{

}

CopyCardAction::~CopyCardAction()
{
}

void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	
	pOut->PrintMessage("Click on a Card to copy it .....");
	CelltoCopy = pIn->GetCellClicked();
	CellPosition InVal(-1, -1);
	if (!CelltoCopy.IsValidCell())
	{
		CelltoCopy = InVal;
		pGrid->PrintErrorMessage( "Invalid Cell ...");
		return;
	}
	pOut->ClearStatusBar();


}

void CopyCardAction::Execute()
{

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();
	if (!CelltoCopy.IsValidCell())
	{
		
		return;
	}
	if (!pGrid->HasCardFromCellPos(CelltoCopy))
	{
		pGrid->PrintErrorMessage("Cell doesn't have a card");
		return;
	}
	pGrid->SetClipboardfromCellPos(CelltoCopy);
}