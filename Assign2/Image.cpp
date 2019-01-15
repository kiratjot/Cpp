/**********************************************************************************************************************
File Name:			     Image.cpp
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
Purpose:				 This class holds the information about the vector Image including the image name, location
and duration of the image
**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <iostream>
#include <time.h>

using namespace std;

#include "Image.h"
/********************************************************************************************************************
Function name:	Image
Purpose:		initialising the objects of class Image
In parameter:	NONE
Out parameters: NONE
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
Image::Image(int x, int y, int duration, char * name)
{
	this->pixel_x = x;
	this->pixel_y = y;
	this->duration = duration;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
/********************************************************************************************************************
Function name:	Image
Purpose:		Copy constructor to initialise the objects of the class
In parameter:	NONE
Out parameters: NONE
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
Image::Image(const Image& image)
{
	this->pixel_x = image.pixel_x;
	this->pixel_y = image.pixel_y;
	this->duration = image.duration;
	this->name = new char[strlen(image.name) + 1];
	strcpy_s(this->name, (strlen(image.name) + 1), image.name);
}

/********************************************************************************************************************
Function name:	~Image
Purpose:		Destructor to delete the memory associated with the name
In parameter:	NONE
Out parameters: NONE
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
Image::~Image()
{
	delete[] name;
}


/********************************************************************************************************************
Function name:	operator<<
Purpose:		Overloading the operator to display the Image content
In parameter:	NONE
Out parameters: NONE
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
ostream& operator<<(ostream& os, Image& images)
{
	os << "name = " << images.name << "; pixel_x = " << images.pixel_x << "; pixel_y = " << images.pixel_y << "; duration = " << images.duration << endl;
	os << "		Counting the seconds for this Image: ";

	//displaying the duration with a pause of 1 second
	for (int i = 1; i <= images.duration; i++)
	{
		Sleep(1000);
		os << i << ", ";
	}	return os;
}
