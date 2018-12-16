#pragma once
#include "../Actions/Action.h"

//Add rhombus Action class
class AddRhomAction: public Action
{
private:
	Point P1; //Rhombus Corners
	GfxInfo RhomGfxInfo;
public:
	AddRhomAction(ApplicationManager *pApp);

	//Reads rhombus parameters
	virtual void ReadActionParameters();
	
	//Add rhombus to the ApplicationManager
	virtual void Execute() ;
	
};