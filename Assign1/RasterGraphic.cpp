/**********************************************************************************************************************
File Name:			     RasterGraphic.cpp
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
Purpose:				 This class contains the function definations of the functions declared in the class header.
						 The functions takes the user input and creates a linked list depending on the index where
						 user wants to place the element in the list. If the user deletes any element, the appropriate
						 allocated memeory is freed before the program quits.
**********************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "GraphicElement.h"
#include "RasterGraphic.h"
#include <iostream>
#include <time.h>

using  namespace std;

/********************************************************************************************************************
Function name:  RasterGraphic
Purpose:		InititalisES the pointer GraphicElements
In parameter:   NONE
Out parameters: NONE
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
RasterGraphic::RasterGraphic()
{
	GraphicElements = nullptr;
}

/********************************************************************************************************************
Function name:	InsertGraphicElement
Purpose:		Adding a new GraphicElement to the RasterGraphic at a position selected by the user
In parameter:	NONE
Out parameters: NONE
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
void RasterGraphic::InsertGraphicElement()
{
	//num to store the index where user wants to add the element to the list
	int num = 0;

	//counting the number of GraphicElements added
	int count = 1;

	//declaring and initialising a pointer to GraphicElement and allocating memory to it
	GraphicElement * newElement = new GraphicElement;

	// declaring and initialising Pointer pointing to the first element in the list
	GraphicElement * iterator = GraphicElements;

	//declaring a pointer to keep track of the next element in the list
	GraphicElement * nextElement;

	// char array to store the file name
	char fName[256];

	cout << "INSERT A GRAPHIC ELEMENT\nPlease enter the GraphicElement filename: ";
	cin >> fName;

	//allocating the memory to store the file name
	newElement->GetfileName() = new char[strlen(fName) + 1];

	//copying the string pointed to, by Name to fileName
	strcpy(newElement->GetfileName(), fName);

	//checking if the list is empty
	if (GraphicElements == nullptr)
	{
		cout << "This is the first GraphicElement in the list\n";

		//pointing the GraphicElements to the new struct
		newElement->GetpNext() = nullptr;

		GraphicElements = newElement;
	}
	else
	{
		//counting the number of GraphicElements in the list
		while (iterator->GetpNext() != nullptr)
		{
			count++;
			iterator = iterator->GetpNext();
		}

		cout << "There are " << count << " GraphicElement(s) in the list. Please specify the position (<=  " << count << ") to insert at : ";
		cin >> num;

		//if user wants to add at the beginning
		if (num == 0)
		{
			newElement->GetpNext() = GraphicElements;
			GraphicElements = newElement;
		}

		//checking if the user wants to add at the end of the list
		else if (num == count)
		{
			newElement->GetpNext() = nullptr;
			iterator->GetpNext() = newElement;
		}

		//checking if the user wants to add within the list
		else if (num > 0 && num < count)
		{
			iterator = GraphicElements;
			nextElement = iterator->GetpNext();

			for (int i = 1; i < num; i++)
			{
				iterator = iterator->GetpNext();
				nextElement = iterator->GetpNext();
			}
			iterator->GetpNext() = newElement;
			newElement->GetpNext() = nextElement;
		}

		//printing the error if user put invalid invalid index number
		else
		{
			cout << "Invalid Input. Please try again\n";
			delete newElement;
		}
	}

}

/********************************************************************************************************************
Function name:	DeleteGraphicElement
Purpose:		Delete the first GraphicElement from the RasterGraphic and free the memory allocated to the fileName and
				GraphicElement
In parameter:	NONE
Out parameters: NONE
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
void RasterGraphic::DeleteGraphicElement()
{
	//checking if the list is not empty
	if (GraphicElements != nullptr)
	{
		// declaring and initialising the pointer temp to point to the first element in the list
		 GraphicElement * temp = GraphicElements;
		 GraphicElements = temp->GetpNext();

		 //setting this to nullptr because delete to a pointer calls the destructor of the object its pointing to.
		 // if we dont do it, it will delete the whole list.
		 temp->GetpNext() = nullptr;

		//freeing the memory allocated to the pointer temp
		delete  temp;
	}

	//printing the error if the list is empty and user tries to delete
	else cout << "There are no elements in the list. Please add and then delete\n";
}

/********************************************************************************************************************
Function name:	ReportRasterGraphic
Purpose:		Display the GraphicElements details one after another at 1 second interval
In parameter:	NONE
Out parameters: NONE
Version			1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
void RasterGraphic::ReportRasterGraphic()
{
	//iint to store the index at which the element is added
	int counter = 0;
	time_t startsec, oldsec, newsec;

	// declaring and initialising Pointer pointing to the first element in the list
	GraphicElement* iterator = GraphicElements;

	//checking if the list is empty
	if (GraphicElements == 0)
	{
		printf("No GraphicElements in the RasterGraphic\n");
		return;
	}
	cout << "Report the RasterGraphic\n";

	startsec = oldsec = time(NULL);

	//printing the elements if they are present
	while (iterator)
	{
		newsec = time(NULL);
		if (newsec > oldsec)
		{
			cout << "GraphicElement #" << counter++ << ", time = " << newsec - startsec << " sec\n";
			cout << "Image file name = " << iterator->GetfileName() << "\n";
			iterator = iterator->GetpNext();
			oldsec = newsec;
		}
	}
}
