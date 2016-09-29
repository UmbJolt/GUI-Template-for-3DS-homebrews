#include <stdlib.h>
#include <stdio.h>
#include <3ds.h>
#include "graphics.h"

// you can define menu entries' number here, so you can edit it quicker if you need more entries in your menu
#define ENTRIES 5

// you should put functions to end services in the inverse order	
void exitServices() {
	GUIElementsExit();
	romfsExit();
	sftd_fini();
	sf2d_fini();
}

// here you can add more services if you need them
void initServices() {
	sf2d_init();
	sf2d_set_clear_color(WHITE);
	sf2d_set_vblank_wait(0);
	sftd_init();
	romfsInit();
	GUIElementsInit();
}

int main() {
	initServices();

	// currentEntry is the menu index that is used to remember which entries is selected in the menu
	int currentEntry = 0;
	char *menuEntries[ENTRIES] = {"Your entry goes here", "Entry #2", "Entry #3", "Entry #4", "Entry #5"};
	
	// if START is pressed, you will exit the main cicle after the first iteration. You can use any button you like
	while (aptMainLoop() && !(hidKeysDown() & KEY_START)) {
		hidScanInput();

		// following routines updates your index if you move between menu entries
		if (hidKeysDown() & KEY_DUP) {
			if (currentEntry == 0)
				currentEntry = ENTRIES - 1;
			else if (currentEntry > 0)
				currentEntry--;
		}

		if (hidKeysDown() & KEY_DDOWN) {
			if (currentEntry == ENTRIES - 1)
				currentEntry = 0;
			else if (currentEntry < ENTRIES - 1)
				currentEntry++;
		}
		
		// you can put your code to use more buttons here

		// menu is printed in this function
		menu("Your title goes here", menuEntries, currentEntry, ENTRIES);
		
		// here goes your code. It will run in every iteration (that graphically means in every frame) of the main cicle
	}
	
	// here we're closing every open services, to free pointers and to avoid system crashes
	exitServices();
	
	return 0;
}
