// ass1.cpp
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build

#include <crtdbg.h>
#include <iostream>
#include "GraphicElement.h"
#include "RasterGraphic.h"
using namespace std;

bool running = true;

int main(void)
{
	char selection;
	bool running = true;
	RasterGraphic A;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	while (running)
	{
		cout << "MENU\n 1. Insert a GraphicElement\n 2. Delete a GraphicElement\n 3. Report the RasterGraphic\n 4. Quit\n" << endl;
		cin >> selection;

		switch (selection)
		{
			case '1':
				A.InsertGraphicElement();
				break;
			case '2':
				A.DeleteGraphicElement();
				break;
			case '3':
				A.ReportRasterGraphic();
				break;
			case '4':
				running = false;

				break;
			default:
				break;
		}
	}
	return 0;
}


