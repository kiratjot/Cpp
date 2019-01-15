// GraphicElement.h
#pragma once

class GraphicElement
{
	string fileName;
	vector<Image> Images;
public:
	GraphicElement::GraphicElement(string s, vector<Image> d) :fileName(s), Images(d) {}
	GraphicElement operator+(GraphicElement&);
	friend ostream& operator<<(ostream&, GraphicElement&);
};