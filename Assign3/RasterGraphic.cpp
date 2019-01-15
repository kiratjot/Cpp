/**********************************************************************************************************************
File Name:			     RasterGraphic.cpp
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
#include "SystemMemoryImage.h"
#include "GPUMemoryImage.h"
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
	vector<Image*> temp_images;

	//declaring a forward list iterator
	forward_list<GraphicElement> ::iterator i;

	// declaring a string variable to store the GraphicElement fileName
	string temp_Gname;

	//declaring a string variable to store the shader name
	string temp_Sname;

	// declaring an image object which is a pointer to type Image
	Image* image(NULL);

	//Counter to count the number of GraphicElements created
	int counter = distance(GraphicElements.begin(), GraphicElements.end());

	// Declaring a variable to store the number of Images
	int temp_size;

	//declaring index for user input
	int index;

	//declaring variable to store the type
	int temp_type;

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
		cout << "Please enter pixel x-width for Image #" << i << " pixel_x:";
		cin >> temp_x;

		//getting the pixel y value
		cout << "Please enter pixel y-width for Image #" << i << " pixel_y:";
		cin >> temp_y;

		//getting the duration value
		cout << "Please enter the duration sec for this Image: ";
		cin >> temp_duration;

		//getting the image name
		cout << "Please enter the name for this Image: ";
		cin >> temp_name;

		//getting the type
		do
		{
			cout << "Please enter the type for this Image (1 = SystemMemoryImage, 2 = GPUMemoryImage): ";
			cin >> temp_type;
		} while (temp_type >= 3 || temp_type <= 0);

		/* insert into different display types */
		if (temp_type == 1)
		{
			image = new SystemMemoryImage(temp_x, temp_y, temp_duration, temp_name);
			temp_images.push_back(image); 			//adding the image to the Image vector
			cout << endl;
		}
		else if (temp_type == 2)
		{
			cout << "Please enter the file name of the associated GPU Shader: ";
			cin >> temp_Sname;
			image = new GPUMemoryImage(temp_x, temp_y, temp_duration, temp_name, temp_Sname);
			temp_images.push_back(image); //adding the image to the Image vector
			cout << endl;
		}
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
Function name:	operator<<
Purpose:		overloading the += operator to display the RasterGraphic
In parameter:	ostream& os, RasterGraphic& rasterGraphic
Out parameters: ostream& os
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
			os << "GraphicElement #" << count++ << ":" ;
			os << *i<<endl;
		}

		os  << "Output finished" << endl;
	}
	return os;

}
