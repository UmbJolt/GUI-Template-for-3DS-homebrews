#include <sf2d.h>
#include <sftd.h>
#include <sfil.h>
#include <stdio.h>
#include "graphics.h"

// declaring every graphic element here is pretty easy to use in C
sftd_font *font; 
sf2d_texture *backgroundTexture;

// these values are needed if you want to use giveTransparence() function
int trasp = 254;
bool vanish = true;

// textures are initialized here
void GUIElementsInit() {
	font = sftd_load_font_file("romfs:/res/font.ttf");
	backgroundTexture = sfil_load_PNG_file("romfs:/res/yourTexture.png", SF2D_PLACE_RAM);
}

// and they're freed here
void GUIElementsExit() {
	sf2d_free_texture(backgroundTexture);
	sftd_free_font(font);
}

// this function prints your menu
void refreshMenu(char *menu[], int option, int n, bool center) {
	int x, dim;
	
	for (int i = 0; i < n; i++) {
		x = 1;
		dim = SIZE - 1;
		
		if (center && (i == option))
			x = (400 - sftd_get_text_width(font, ++dim, menu[i])) / 2;
		else if (center)
			x = (400 - sftd_get_text_width(font, dim, menu[i])) / 2;

		if (i == option)
			sftd_draw_text(font, x, 25 + i * SIZE, RED, dim, menu[i]);
		else 
			sftd_draw_text(font, x, 25 + i * SIZE, BLACK, dim, menu[i]);
	}
}

// this function makes your text glow. It should used in a RGBA8 color, like RGBA8(0, 0, 0, giveTransparence())
int giveTransparence() {
	// coded horribly, but it works
	if (vanish && trasp > 126)
		trasp -= 8;
	if (trasp == 126)
		vanish = false;
	if (!(vanish) && trasp < 254)
		trasp += 8;
	if (trasp == 254)
		vanish = true;
	
	return trasp;
}

// add more elements in the following functions if you like
void drawFooter(int width) {
	sf2d_draw_rectangle(0, 224, width, 16, RED);
}

void drawHeader(int width) {
	sf2d_draw_rectangle(0, 0, width, 16, RED);
}

void drawBars(int width) {
	drawHeader(width);
	drawFooter(width);
}

void drawMenu(char* title, int width) {
	drawBars(width);
	sftd_draw_text(font, (width - sftd_get_text_width(font, SIZE, title)) / 2, 0, WHITE, SIZE, title);
}

// your can add more textures and edit parameters here
void menu(char* title, char* menuEntries[], int currentEntry, int N) {
	// here we start a frame for each screen
	sf2d_start_frame(GFX_TOP, GFX_LEFT);
	
		sf2d_draw_texture(backgroundTexture, 0, 0);
		drawMenu(title, TOP);
		refreshMenu(menuEntries, currentEntry, N, true);
		
	sf2d_end_frame();
	
	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
	
		drawMenu("A different title", BOTTOM);
		sftd_draw_textf(font, 0, 20, RGBA8(0, 0, 0, giveTransparence()), SIZE, "Text can glow, too");
		
	sf2d_end_frame();	
	sf2d_swapbuffers();
}