/**********************************************************************************************************************
File Name:			     GraphicElement.cpp
Versions:				 1.0
Author:				     Gurkirat Singh
Student Number:			 040 876 315
Course Name/Number :     C++ Programming 18F_CST8219_300
Lab sect:				 301
Assignment Name:		 RasterGraphic Project in C++ using Polymorphic Inheritance and RTTI
Assignment #:			 3
Due Date of assignment:  Dec 1, 2018
Submission Date:		 Dec 1, 2018
Professor:			     MOHAMED ABOU SEIF
Purpose:				 This class is used to crate GraphicElements containing the Images Vector.
The class also contains the definations of the functions containig the overloaded operators
**********************************************************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Image.h"
#include "SystemMemoryImage.h"
#include "GPUMemoryImage.h"
#include "GraphicElement.h"

/************************************************
Function Name:	GraphicElement
Purpose:		Copy constructor to initialize another GraphicElement object.
In parameters:	const GraphicElement& frame
Out parameters:	NA
Version:		1.0
Author:			Gurkirat Singh
************************************************/
GraphicElement::GraphicElement(const GraphicElement& image)
{

	//stroing the fileName
	fileName = image.fileName;

	//declaring a vector list iterator
	vector<Image*>::const_iterator i;

	//adding the appropriate type object to the vector list
	for ( i = image.Images.begin(); i != image.Images.end(); i++)
	{
		if (SystemMemoryImage *system = dynamic_cast<SystemMemoryImage*>(*i))
		{
			Images.push_back(new SystemMemoryImage(*system));
		}
		else if (GPUMemoryImage *gpu = dynamic_cast<GPUMemoryImage*> (*i))
		{
			Images.push_back(new GPUMemoryImage(*gpu));
		}
	}
}


/********************************************************************************************************************
Function name:	operator<<
Purpose:		Overloading << opertor to display the GraphicElement class elements
In parameter:	ostream& os, GraphicElement& graphicElement
Out parameters: ostream& os
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
ostream& operator<<(ostream& os, GraphicElement& graphicElement)
{
	//declaring the variable to kee the track of the GraphicElements added
	int count = 0;

	//declaring a iterator for a vector of type Image
	vector<Image*>::iterator i;

	os << "		fileName = " << graphicElement.fileName << endl;

	//iterating through the Image vector
	for (i = graphicElement.Images.begin(); i != graphicElement.Images.end(); i++)
	{
		os << "		Image #" << count++ << ": " << **i << endl;
	}

	return os;
}
