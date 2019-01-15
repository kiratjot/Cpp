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
The functions takes the user input and creates a forward linked list depending on the index where
user wants to place the element in the list. If the user deletes any element, the appropriate
allocated memeory is freed before the program quits.
**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <forward_list>

using namespace std;

#include "Image.h"
#include "GraphicElement.h"
#include "RasterGraphic.h"

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
	// declaring a vector of type Image
	vector<Image> temp_images;

	//declaring a forward list iterator
	forward_list<GraphicElement> ::iterator i;

	// declaring a string variable to store the GraphicElement fileName
	string temp_Gname;

	//Counter to count the number of GraphicElements created
	int counter = distance(GraphicElements.begin(), GraphicElements.end());

	// Declaring a variable to store the number of Images
	int temp_size;

	//declaring index for user input
	int index;

	// getting the GraphicElement filename
	cout << "Insert a GraphicElement in the RasterGraphic" << endl;
	cout << "Please enter the GraphicElement filename: ";
	cin >> temp_Gname;

	//getting the number of images
	cout << "Entering the GraphicElement Images (the sets of dimensions and durations)" << endl;
	cout << "Please enter the number of Images : ";
	cin >> temp_size;


	//Adding the Images into GraphicElement and GraphicElement into the RasterGraphic
	for (int i = 0; i < temp_size; i++)
	{
		int temp_x; // to store the pixel x
		int temp_y; // to store the pixel y
		int temp_duration; // to store the duration
		char temp_name[256]; // to store the image name

							 //getting the pixel x value
		cout << "Please enter pixel x for Image # " << i << " pixel_x:";
		cin >> temp_x;

		//getting the pixel y value
		cout << "Please enter pixel y for Image # " << i << " pixel_y:";
		cin >> temp_y;

		//getting the duration value
		cout << "Please enter the duration sec for this Image: ";
		cin >> temp_duration;

		//getting the image name
		cout << "Please enter the name for this Image: ";
		cin >> temp_name;

		//adding the image to the Image vector
		temp_images.push_back(Image(temp_x, temp_y, temp_duration, temp_name));
	}

	i = GraphicElements.begin(); //assigning the iterator with the first element

								 //checking the number of GraphicElement already in the RasterGraphic
	switch (counter)
	{
		case 0: //if list is empty
			cout << "This is the first GraphicElement in the list" << endl << endl;
			break;

		case 1: //if one element exists
			break;

		default: //for more than 2 GraphicElements
			cout << "There are " << counter << " GraphicElement(s) in the list" << endl;

			//getting the index where the user wants to insert the GraphicElement and checking the imput
			do
			{
				cout << "Please specify the position, between 0 and " << counter - 1 << " to insert after : ";
				cin >> index;
			} while (index<0 || index >(counter - 1));

			//iterating the list to reach where the user wants to insert the element
			for (int x = 0; x < index; x++)
			{
				i++;
			}
			break;
	}

	//initilising the GraphicElement constructor with the string and vector
	GraphicElement graphic = GraphicElement(temp_Gname, temp_images);

	if (counter == 0)
	{ //if the list is empty, add at front
		GraphicElements.push_front(graphic);
	}
	else //else add at the specified position
		GraphicElements.insert_after(i, (graphic));
}

/********************************************************************************************************************
Function name:	DeleteGraphicElement
Purpose:		Delete the first GraphicElement from the RasterGraphica
In parameter:	NONE
Out parameters: NONE
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
void RasterGraphic::DeleteGraphicElement()
{
	//checking if the list is empty
	if (GraphicElements.empty())
	{
		cout << "There is no GraphicElement in the RasterGraphic" << endl << endl;
	}
	else
	{ //popping out the first element from the list
		cout << "Delete the first GraphicElement from the RasterGraphic" << endl;
		GraphicElements.pop_front();
		cout << "GraphicElement deleted" << endl << endl;
	}
}

/********************************************************************************************************************
Function Name:	 operator[]
Purpose:		 Overloaded [] operator to return the GraphicElement at specified position
In parameters:   unsigned int x
Out parameters:  GraphicElement*
Version:		 1.0
Student Name:	 Gurkirat Singh
********************************************************************************************************************/
GraphicElement& RasterGraphic::operator[](unsigned int a)
{
	//declaring an unsigned int variable as a coutner to iterate through the elements
	unsigned int count = 0;

	//declaring a forward list iterator
	forward_list<GraphicElement>::iterator i;

	//iterating the frames to get the specified index */
	for (i = GraphicElements.begin(); i != GraphicElements.end(); i++)
	{
		if (a == count++)
		{
			break;
		}
	}
	return *i;
}


/********************************************************************************************************************
Function name:	operator+=
Purpose:		adds the Rastergraphic together
In parameter:	NONE
Out parameters: NONE
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
void RasterGraphic::operator+=(GraphicElement& graphicElement)
{
	if (GraphicElements.empty())
	{
		cout << "There's no GraphicElement to concatenate" << endl;
	}
	else

		GraphicElements.push_front(graphicElement);

}



/********************************************************************************************************************
Function name:	operator<<
Purpose:		overloading the += operator to display the RasterGraphic
In parameter:	NONE
Out parameters: NONE
Version:		1.0
Author:			Gurkirat Singh
********************************************************************************************************************/
ostream& operator<<(ostream& os, RasterGraphic& rasterGraphic)
{
	int count = 0; //declaring variable to track the number of GraphicElements

				   //checking if the GraphicElements list is empty
	if (rasterGraphic.GraphicElements.empty())
	{

		cout << "There is no GraphicElement in the RasterGraphic" << endl;
	}
	else
	{
		//declaring a forward list iterator
		forward_list<GraphicElement>::iterator i;

		os << "RasterGrpahic " << rasterGraphic.name << endl;
		os << "Run the RasterGraphic" << endl;

		//iterating through the graphic elements in the RasterGraphic
		for (i = rasterGraphic.GraphicElements.begin(); i != rasterGraphic.GraphicElements.end(); i++)
		{
			os << "GraphicElement #" << count++ << ":" << endl;
			os << *i;
		}

		os << endl << "Output finished" << endl;
	}
	return os;

}
