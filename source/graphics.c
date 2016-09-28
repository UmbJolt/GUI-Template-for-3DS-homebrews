#include <sf2d.h>
#include <sftd.h>
#include <sfil.h>
#include <stdio.h>
#include "graphics.h"

sftd_font *font; 
sf2d_texture *backgroundTexture;

int trasp = 254;
bool vanish = true;

void GUIElementsInit() {
	font = sftd_load_font_file("romfs:/res/font.ttf");
	backgroundTexture = sfil_load_PNG_file("romfs:/res/yourTexture.png", SF2D_PLACE_RAM);
}

void GUIElementsExit() {
	sf2d_free_texture(backgroundTexture);
	sftd_free_font(font);
}

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

void drawFooter() {
	sf2d_draw_rectangle(0, 224, 400, 16, RED);
}

void drawHeader() {
	sf2d_draw_rectangle(0, 0, 400, 16, RED);
}

void drawBars() {
	drawHeader();
	drawFooter();
}

void drawMenuTOP(char* title) {
	drawBars();
	sftd_draw_text(font, (400 - sftd_get_text_width(font, SIZE, title)) / 2, 0, WHITE, SIZE, title);
}

void menu(char* title, char* menuEntries[], int currentEntry, int N) {
	sf2d_start_frame(GFX_TOP, GFX_LEFT);
	
	sf2d_draw_texture(backgroundTexture, 0, 0);
	drawMenuTOP(title);
	refreshMenu(menuEntries, currentEntry, N, true);
	
	// your texture goes here
	
	sf2d_end_frame();
	
	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
	
	sftd_draw_textf(font, 0, 0, RGBA8(0, 0, 0, giveTransparence()), SIZE, "Text can glow, too");
	
	// your texture goes here
	
	sf2d_end_frame();
	sf2d_swapbuffers();
}