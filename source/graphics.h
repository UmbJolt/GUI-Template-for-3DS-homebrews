#include <sf2d.h>
#include <sftd.h>
#include <sfil.h>

// you can define other colours here. Values have to be Red, Green, Blue, Alpha (transparency); range is 0-255
#define BLACK RGBA8(0, 0, 0, 255)
#define RED RGBA8(255, 0, 0, 255)
#define WHITE RGBA8(255, 255, 255, 255)

// you can edit font's size here
#define SIZE 12

// you don't have to remember both screen's width
#define BOTTOM 320
#define TOP 400

void GUIElementsInit();
void GUIElementsExit();
int giveTransparence();
void drawFooter(int width);
void drawHeader(int width);
void drawBars(int width);
void drawMenu(char* title, int width);
void refreshMenu(char *menu[], int option, int n, bool center);
void menu(char* title, char* menuEntries[], int currentEntry, int N);