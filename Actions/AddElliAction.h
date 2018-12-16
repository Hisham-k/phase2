#pragma once
#include "../Actions/Action.h"

//Add ellipse Action class
class AddElliAction: public Action
{
private:
	Point P1, P2; //ellipse Corners
	GfxInfo ElliGfxInfo;
public:
	AddElliAction(ApplicationManager *pApp);

	//Reads ellipse parameters
	virtual void ReadActionParameters();
	
	//Add ellipse to the ApplicationManager
	virtual void Execute() ;
	
};