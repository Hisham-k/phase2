#include"SaveAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"

SaveAction::SaveAction(ApplicationManager *pApp) :Action(pApp)
{
}

//Read the parameters for the save action 
void SaveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter file name without spaces.");


	FileName = pIn->GetSrting(pOut) + ".txt";
	OutFile.open(FileName);
	//check if the file is opened
	if (OutFile.is_open())
	{
		pOut->PrintMessage("File saved.");
	}
	else {
		pOut->PrintMessage("Unable to save file.");
	}
}

void SaveAction::Execute()
{
	ReadActionParameters();
	//check if the file is opened
	if (OutFile.is_open())
	{
		int NumberOfFigures = pManager->ReturnFigureCount();
		string DrawClr = getColorName(UI.DrawColor);
		OutFile << DrawClr;
		string FillClr = getColorName(UI.FillColor);
		OutFile << '\t' << FillClr << endl;
		OutFile << NumberOfFigures << endl;
		//Calling the function saveAll in the application manager that have the access to the figlist
		pManager->SaveAll(OutFile);
		//Close the file after saveing
		OutFile.close();
	}
}

string SaveAction::getColorName(color clr)const
{

	if (clr == RED)
	{
		return "RED";
	}

	if (clr == BLACK)
	{
		return "BLACK";
	}

	if (clr == BLUE)
	{
		return "BLUE";
	}

	if (clr == GREEN)
	{
		return "GREEN";
	}

	if (clr == WHITE)
	{
		return "WHITE";
	}
	return "NO";
}