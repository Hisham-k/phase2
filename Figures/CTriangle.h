#pragma once
#include "CFigure.h"

class CTriangle:public CFigure
{
	Point corner1;
	Point corner2;
	Point corner3;
public:
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};