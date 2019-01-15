//RasterGraphic.h
#pragma once

class RasterGraphic
{
	string name;
	forward_list<GraphicElement> GraphicElements;
public:
	RasterGraphic(string s) : name(s) {}
	void InsertGraphicElement();
	void DeleteGraphicElement();
	void Concatenate() // inline
	{
		cout << "Concatenating two GraphicElements" << endl;
		int index1 = -1, index2 = -1;
		RasterGraphic& A = *this;
		int count = distance(GraphicElements.begin(), GraphicElements.end());
		do
		{
			cout << "Please enter valid indexes of the two GraphicElements to concatenate (0 to " << count - 1 << ")" << endl;
			cin >> index1 >> index2;
		} while ((index1<0 || index1>count - 1) || (index2<0 || index2>count - 1));
		A += A[index1] + A[index2];
	}
	GraphicElement& operator[](unsigned int);
	void operator+=(GraphicElement&);
	friend ostream& operator<<(ostream&, RasterGraphic&);
};
