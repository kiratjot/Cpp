/**********************************************************************************************************************
File Name:			     GraphicElement.cpp
Versions:				 1.0
Author:				     Gurkirat Singh
Student Number:			 040 876 315
Course Name/Number :     C++ Programming 18F_CST8219_300
Lab sect:				 301
Assignment Name:		 RasterGraphic in C++ using Container Classes and Overloaded Operators
Assignment #:			 2
Due Date of assignment:  Nov 10, 2018
Submission Date:		 Nov 10, 2018
Professor:			     MOHAMED ABOU SEIF
Purpose:				 This class is used to crate GraphicElements containing the Images Vector.
The class also contains the definations of the functions containig the overloaded operators
**********************************************************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Image.h"
#include "GraphicElement.h"

/********************************************************************************************************************
Function name:	operator+
Purpose:		Overloading the + operator
In parameter:	NONE
Out parameters: NONE
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
GraphicElement GraphicElement::operator+(GraphicElement& graphicElement)
{
	//string to add the file names together
	string  newfName = fileName + "_" + graphicElement.fileName;

	//declaring temp vectors
	vector <Image> image_display = Images;
	vector <Image> oldImage = graphicElement.Images;
	vector <Image> newImage;

	//allocating a new memeory
	newImage.reserve(image_display.size() + image_display.size());

	//inserting the old GraphicElements
	newImage.insert(newImage.end(), image_display.begin(), image_display.end()); /*insert old frame display to new one*/

																				 //inserting the new GraphicElements
	newImage.insert(newImage.end(), oldImage.begin(), oldImage.end());

	/*constructing the new GraphicElement object with the new fileName and the new Imagey*/
	GraphicElement new_Image = GraphicElement(newfName, newImage);

	return new_Image;
}

/********************************************************************************************************************
Function name:	operator<<
Purpose:		Overloading << opertor to display the GraphicElement class elements
In parameter:	NONE
Out parameters: NONE
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
ostream& operator<<(ostream& os, GraphicElement& graphicElement)
{
	//declaring the variable to kee the track of the GraphicElements added
	int count = 0;

	//declaring a iterator for a vector of type Image
	vector<Image>::iterator i;

	os << "		fileName = " << graphicElement.fileName << endl;

	//iterating through the Image vector
	for (i = graphicElement.Images.begin(); i != graphicElement.Images.end(); i++)
	{
		os << "		Image #" << count++ << ":		" << *i << endl;
	}

	return os;
}
