#include"LoadAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"
#include"..\Figures\CRectangle.h"



LoadAction::LoadAction(ApplicationManager *pApp) :Action(pApp)
{
}



//Read Parameters for the load action
void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter the name of the file you want to load");


	fileName = pIn->GetSrting(pOut) + ".txt";
	//Clear the status bar
	InputFile.open(fileName);
	pOut->ClearDrawArea();
	//check if the file doesnot exists
	if (InputFile.is_open())
	{
		pOut->PrintMessage("Your file has been successfully loaded");
	}
	else { pOut->PrintMessage("No file found with name: " + fileName); }
}

//Execute action Load Action
void LoadAction::Execute()
{
	ReadActionParameters();
	//check if the file is opened first
	if (InputFile.is_open())
	{
		//read from the file the current draw clr & fill clr &number of figuers 
		CFigure *pFig = NULL;
		int NumberOfFigures;
		string DrawClr;
		InputFile >> DrawClr;
		UI.DrawColor = getColorObject(DrawClr);
		string FillClr;
		InputFile >> FillClr;
		UI.FillColor = getColorObject(FillClr);
		InputFile >> NumberOfFigures;
		//cleaning the figlist before loading the file
		pManager->ClearFigList();
		// Loop all figures ,identify the type ,then create an obj of the specified type, add to the figlist  after the loading it
		for (int i = 0; i < NumberOfFigures; i++)
		{
			int FigureType;
			InputFile >> FigureType;
			switch (FigureType)
			{
			//case line:
			//	pFig = new CLine;
			//	break;

			case rect:
				pFig = new CRectangle;
				break;

			//case trig:
			//	pFig = new CTrig;
			//	break;

			default:
				pFig = NULL;
				break;
			}
			//loading the parameters of each figure 
			pFig->Load(InputFile);
			if (pFig != NULL)
			{
				//sending it to the application manager to add them
				pManager->AddFigure(pFig);
			}
		}
		//close the file after looping 
		InputFile.close();
	}
}
//Function that gets a string color name returning a color obj
color LoadAction::getColorObject(string clr)const
{
	if (clr == "RED")
	{
		return RED;
	}

	if (clr == "BLACK")
	{
		return BLACK;
	}

	if (clr == "BLUE")
	{
		return BLUE;
	}

	if (clr == "GREEN")
	{
		return GREEN;
	}

	if (clr == "WHITE")
	{
		return WHITE;
	}

}
