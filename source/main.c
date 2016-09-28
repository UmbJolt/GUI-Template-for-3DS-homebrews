#include <stdlib.h>
#include <stdio.h>
#include <3ds.h>
#include "graphics.h"

#define ENTRIES 5
		
void exitServices() {
	GUIElementsExit();
	romfsExit();
	sftd_fini();
	sf2d_fini();
}

int main() {
	sf2d_init();
	sf2d_set_clear_color(WHITE);
	sf2d_set_vblank_wait(0);
	sftd_init();
	romfsInit();
	GUIElementsInit();

	int currentEntry = 0;
	char *menuEntries[ENTRIES] = {"Your entry goes here", "Entry #2", "Entry #3", "Entry #4", "Entry #5"};
	
	while (aptMainLoop() && !(hidKeysDown() & KEY_START)) {
		hidScanInput();

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

		menu("Your title goes here", menuEntries, currentEntry, ENTRIES);
	}
	
	exitServices();
	return 0;
}
