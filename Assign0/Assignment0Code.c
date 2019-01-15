// ass0.c
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build

#include <crtdbg.h>
#include <stdio.h>
#include <time.h>

typedef enum { FALSE = 0, TRUE } BOOL;

// struct containing the File name, pointer to the next GraphicElement in the list
struct GraphicElement {
	char* fileName;
	struct GraphicElement* pNext;
};
//struct containing the pointer to the the struct GraphicElement
struct RasterGraphic {
	struct GraphicElement* GraphicElements;
};

// Forward declarations
void InitRasterGraphic(struct RasterGraphic*);
void InsertGraphicElement(struct RasterGraphic*);
void DeleteGraphicElement(struct RasterGraphic*);
void ReportRasterGraphic(struct RasterGraphic*);
void CleanUp(struct RasterGraphic*);






int main(void)
{
	char response;
	BOOL RUNNING = TRUE;
	struct RasterGraphic RG;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	InitRasterGraphic(&RG);

	while (RUNNING)
	{
		printf("MENU\n 1. Insert a GraphicElement\n 2. Delete the first GraphicElement\n 3. Report the RasterGraphic\n 4. Quit\n");
		scanf("%c", &response);
		switch (response)
		{
		case '1':InsertGraphicElement(&RG); break;
		case '2':DeleteGraphicElement(&RG); break;
		case '3':ReportRasterGraphic(&RG); break;
		case '4':RUNNING = FALSE; CleanUp(&RG); break;
		default:printf("Please enter a valid option\n");
		}
		printf("\n");
		while ((response = getchar()) != '\n' && response != EOF);// clear input buffer
	}
	return 0;
}

void ReportRasterGraphic(struct RasterGraphic* pA)
{
	int counter = 0;
	time_t startsec, oldsec, newsec;
	struct GraphicElement* iterator = pA->GraphicElements;

	if (pA->GraphicElements == 0)
	{
		printf("No GraphicElements in the RasterGraphic\n");
		return;
	}

	printf("Report the RasterGraphic\n");
	startsec = oldsec = time(NULL);
	while (iterator)
	{
		newsec = time(NULL);
		if (newsec > oldsec)
		{
			printf("GraphicElement #%d, time = %I64d sec\n", counter++, newsec - startsec);
			printf("Image file name = %s\n", iterator->fileName);
			iterator = iterator->pNext;
			oldsec = newsec;
		}
	}
}

// Inititalises the GraphicElement struct using Null
void InitRasterGraphic(struct RasterGraphic *ptr) {

	ptr->GraphicElements = NULL;

}


// Inserting the graphic element into the RasterGraphic
void InsertGraphicElement(struct RasterGraphic* ptr) {


	int count = 1;

	printf("Insert a GraphicElement in the RasterGraphic\n");
	struct GraphicElement *g = malloc(sizeof(*g));

	char Name[100];
	printf("Please enter the GraphicElement filename: ");
	scanf("%s", Name);
	g->fileName = malloc(sizeof(Name));

	strcpy(g->fileName, Name);



	if (ptr->GraphicElements == NULL)
	{


		ptr->GraphicElements = g;
		g->pNext = NULL;

		printf("This is the first GraphicElement in the list\n");

		return;

	}
	else {

		struct GraphicElement * current = ptr->GraphicElements;
		struct GraphicElement * end = ptr->GraphicElements;



		while (current->pNext != NULL) {

			count++;

			current = current->pNext;

		}




		printf("There are %d GraphicElement(s) in the list. Please specify the position (<= %d) to insert at : ", count, count);
		int num;

		scanf("%d", &num);



		if (num == 0) {

			g->pNext = ptr->GraphicElements;

			ptr->GraphicElements = g;

		}

		else if (num == count) {
			g->pNext = NULL;

			current->pNext = g;

		}

		else if (num > 0 && num < count) {
			current = ptr->GraphicElements;
			end = current->pNext;
			for (int i = 1; i < num; i++) {

				current = current->pNext;
				end = current->pNext;


			}

			current->pNext = g;
			g->pNext = end;

		}

		else printf("Invalid Input. Please try again");

	}


}

// Deleting the first GraphicElement from the RasterGraphic
void DeleteGraphicElement(struct RasterGraphic * ptr)
{

	struct GraphicElement * temp = ptr->GraphicElements;
	ptr->GraphicElements = ptr->GraphicElements->pNext;
	free(temp->fileName);
	free(temp);

}

// Freeing the memeory assigned to the GraphicElement
void CleanUp(struct RasterGraphic * ptr)
{



	struct  GraphicElement * fr = ptr->GraphicElements;
	while (ptr->GraphicElements != NULL) {
		ptr->GraphicElements = ptr->GraphicElements->pNext;

		free(fr->fileName);

		free(fr);

		fr = ptr->GraphicElements;
	}



}
