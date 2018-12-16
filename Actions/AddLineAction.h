#pragma once
#include "../Actions/Action.h"

//Add line Action class
class AddLineAction: public Action
{
private:
	Point P1, P2; //Line Corners
	GfxInfo LineGfxInfo;
public:
	AddLineAction(ApplicationManager *pApp);

	//Reads line parameters
	virtual void ReadActionParameters();
	
	//Add line to the ApplicationManager
	virtual void Execute() ;
	
};