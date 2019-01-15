#pragma once

class GraphicElement
{
	char* fileName;
	GraphicElement* pNext ;
public:

	GraphicElement();
	~GraphicElement();
	char*& GetfileName() { return fileName; } // inline
	GraphicElement*& GetpNext() { return pNext; }; // inline
};



