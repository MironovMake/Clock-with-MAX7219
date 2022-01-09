#include <Arduino.h>
// Including the required Arduino libraries
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Uncomment according to your hardware type
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
//#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW

// Defining size, and output pins
#define MAX_DEVICES 12
#define CS_PIN 3

// Create a new instance of the MD_Parola class with hardware SPI connection
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
MD_MAX72XX *pM;
void printColon(int x, int y, int lengh)
{
	for (int i = y; i < y + lengh; i++)
		pM->setPoint(x, i, true);
}

void printRow(int x, int y, int lengh)
{
	for (int i = x; i < x + lengh; i++)
		pM->setPoint(i, y, true);
}

void setupMax7119()
{
	// Intialize the object
	myDisplay.begin();

	// Set the intensity (brightness) of the display (0-15)
	myDisplay.setIntensity(0);

	// Clear the display
	myDisplay.displayClear();

	myDisplay.displayScroll("Happy new year 2022", PA_LEFT, PA_SCROLL_RIGHT, 100);
	pM = myDisplay.getGraphicObject();
}

void digitPrint(int Ystart, int value)
{
	Ystart = Ystart * 24;
	switch (value)
	{
	case 0:
		printColon(0, Ystart + 1, 22);
		printColon(7, Ystart + 1, 22);
		printRow(1, Ystart + 0, 6);
		printRow(1, Ystart + 23, 6);
		break;
	case 1:
		printColon(4, Ystart + 0, 23);
		printRow(2, Ystart + 23, 5);
		pM->setPoint(2, Ystart + 2, true);
		pM->setPoint(3, Ystart + 1, true);
		break;
	case 2:
		printColon(7, Ystart + 1, 8);
		printRow(1, Ystart + 0, 6);
		pM->setPoint(0, Ystart + 1, true);
		for (int i = 6; i > 0; i--)
			pM->setPoint(7 - i, Ystart + 8 + i, true);
		printColon(0, Ystart + 15, 8);
		printRow(0, Ystart + 23, 8);
		break;
	case 3:
		printColon(7, Ystart + 0, 24);
		printRow(0, Ystart + 11, 8);
		printRow(0, Ystart + 0, 8);
		printRow(0, Ystart + 23, 8);
		break;
	case 4:
		printColon(7, Ystart + 0, 24);
		printColon(0, Ystart + 0, 12);
		printRow(0, Ystart + 11, 8);
		break;
	case 5:
		printColon(0, Ystart + 0, 12);
		printColon(7, Ystart + 11, 12);
		printRow(0, Ystart + 11, 8);
		printRow(0, Ystart + 0, 8);
		printRow(0, Ystart + 23, 8);
		break;
	case 6:
		printColon(0, Ystart + 0, 24);
		printColon(7, Ystart + 11, 12);
		printRow(0, Ystart + 11, 8);
		printRow(0, Ystart + 0, 8);
		printRow(0, Ystart + 23, 8);
		break;
	case 7:
		printRow(0, Ystart + 0, 8);
		for (int i = 0; i < 5; i++)
		{
			pM->setPoint(7 - i, Ystart + i, true);
		}
		printColon(3, Ystart + 5, 19);
		digitPrint(2, Ystart + 7);
		digitPrint(3, Ystart + 7);
		break;
	case 8:
		printColon(0, Ystart + 1, 22);
		printColon(7, Ystart + 1, 22);
		printRow(1, Ystart + 0, 6);
		printRow(1, Ystart + 11, 6);
		pM->setPoint(0, Ystart + 11, false);
		pM->setPoint(7, Ystart + 11, false);
		printRow(1, Ystart + 23, 6);
		break;
	case 9:
		printColon(0, Ystart + 0, 12);
		printColon(7, Ystart + 0, 24);
		printRow(0, Ystart + 11, 8);
		printRow(0, Ystart + 0, 8);
		printRow(0, Ystart + 23, 8);

		break;
	case 10:
		printColon(0, Ystart + 0, 24);
		printRow(0, Ystart + 0, 8);
		printRow(0, Ystart + 23, 8);
		break;
	case 12:
		printRow(0, Ystart + 11, 8);
		break;
	case 13:
		break;
	case 14:

		break;
	}
}
void Max7119()
{
	//	myDisplay.print("Happy new year ");

	digitPrint(0, 1);
	digitPrint(1, 2);
	digitPrint(2, 3);
	digitPrint(3, 4);
	// digitPrint(1, 7);

	// digitPrint(1, 0);
	//	for (int i = 0; i < 5; i++)
	//		pM->setPoint(4, i, true);
	//
	//	for (int i = 0; i < 8; i++)
	//		pM->setPoint(i, 0, true);
	//	for (int i = 0; i < 8; i++)
	//		pM->setPoint(i, 23, true);
	delay(1000);
}
