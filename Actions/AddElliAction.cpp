#include "..\Actions\AddElliAction.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddElliAction::AddElliAction(ApplicationManager * pApp):Action(pApp)
{}

void AddElliAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Line: Click at second corner");
	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	ElliGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	ElliGfxInfo.DrawClr = pOut->getCrntDrawColor();
	ElliGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddElliAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a ellipse with the parameters read from the user
	CEllipse *R=new CEllipse(P1,P2, ElliGfxInfo);

	//Add the ellipse to the list of figures
	pManager->AddFigure(R);
}