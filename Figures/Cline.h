#pragma once
#include "CFigure.h"

class Cline : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	Cline(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
};