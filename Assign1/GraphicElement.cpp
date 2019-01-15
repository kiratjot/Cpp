/********************************************************************************************************************
File Name:			     ass1.cpp
Versions:				 1.0
Author:				     Gurkirat Singh
Student Number:			 040 876 315
Course Name/Number :     C++ Programming 18F_CST8219_300
Lab sect:				 301
Assignment Name:		 Raster GraphicProject in C++
Assignment #:			 1
Due Date of assignment:  Oct 13, 2018
Submission Date:		 Oct 12, 2018
Professor:			     MOHAMED ABOU SEIF
Purpose:				 This class contains the function definations of the functions declared in the class header.
********************************************************************************************************************/

#include "GraphicElement.h"

/********************************************************************************************************************
Function name:  GraphicElement
Purpose:		Inititalises the File name, pointer to the next GraphicElement in the list
In parameter:   NONE
Out parameters: NONE
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
GraphicElement::GraphicElement() {
	fileName = nullptr;
	pNext = nullptr;
}

/********************************************************************************************************************
Function name:  ~GraphicElement
Purpose:		destructor deletes the memeory associated with the fileName and pNext
In parameter:   NONE
Out parameters: NONE
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
GraphicElement::~GraphicElement()
{
	delete fileName;
	delete pNext;
}

