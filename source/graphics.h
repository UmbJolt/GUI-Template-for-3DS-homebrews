#include <sf2d.h>
#include <sftd.h>
#include <sfil.h>

// you can define other colours here. Values have to be Red, Green, Blue, Alpha (transparency); range is 0-255

#define BLACK RGBA8(0, 0, 0, 255)
#define RED RGBA8(255, 0, 0, 255)
#define WHITE RGBA8(255, 255, 255, 255)

#define SIZE 11

void GUIElementsInit();
void GUIElementsExit();
int giveTransparence();
void refreshMenu(char *menu[], int option, int n, bool center);
void menu(char* title, char* menuEntries[], int currentEntry, int N);