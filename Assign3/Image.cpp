/**********************************************************************************************************************
File Name:			     Image.cpp
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
Purpose:				 This class holds the information about the vector Image including the image name, location
and duration of the image
**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <windows.h>
#include <iostream>
#include <time.h>

using namespace std;

#include "Image.h"
#include "GPUMemoryImage.h"
#include "SystemMemoryImage.h"

/********************************************************************************************************************
Function name:	Image
Purpose:		initialising the objects of class Image
In parameter:	int x, int y, int duration, char * name
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
In parameter:	Image& image
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
Function name:	operator<<
Purpose:		Overloading the operator to display the Image content
In parameter:	ostream& os, Image& images
Out parameters: NONE
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
ostream& operator<<(ostream& os, Image& images)
{
	/* Checking which inform																																																																																																																																																																																									ation will display */
	try
	{
		SystemMemoryImage& system = dynamic_cast<SystemMemoryImage&>(images);
		os << "System Memory Image" << endl;
	}
	catch (const std::bad_cast& e)
	{
	}

	/* Checking which information will display */
	try
	{
		GPUMemoryImage& gpu = dynamic_cast<GPUMemoryImage&>(images);
		os << "GPU Memory Image. Shader = " << gpu.GetShader() << endl;
	}
	catch (const std::bad_cast& e)
	{
	}

	os << "		Image name = " << images.name << "; pixel_x = " << images.pixel_x << "; pixel_y = " << images.pixel_y << "; duration = " << images.duration << endl;
	os << "		Counting the seconds for this Image: ";

	//displaying the duration with a pause of 1 second
	for (int i = 1; i <= images.duration; i++)
	{
		Sleep(1000);
		os << i << ", ";
	}

	/* Calculating the sixe of the buffer and displaying it */
	os << "\n		Memory requirements = " << images.BufferSize() << " bytes" << endl;

	return os;
}
