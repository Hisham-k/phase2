#pragma once
#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CEllipse(Point ,Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
};