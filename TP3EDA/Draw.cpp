#include "notmain.h"
#include "Draw.h"

using namespace std;
#define BANNERTEXTCOLOR "black"
#define SUCCESSTEXTCOLOR "white"

void drawSuccess(int ticks, ALLEGRO_FONT* font)
{
	string text = "Success! The amount of ticks spent are: " + to_string(ticks);
	string getOut = "Please press 'enter' to leave";

	ALLEGRO_DISPLAY * display = al_get_current_display();
	float displayH = al_get_display_height(display);
	float displayW = al_get_display_width(display);

	float fontSize = al_get_font_line_height(font);

	float firstLineY = ((displayH / 2) - (3 * fontSize / 5)) - fontSize;
	float secondLineY = firstLineY + 2 * fontSize;
	float lineX = (displayW / 2);

	al_draw_filled_rectangle((displayW / 5), (2 * displayH / 5), (4 * displayW / 5), (3 * displayH / 5), al_color_name("black"));
	al_draw_text(font, al_color_name(SUCCESSTEXTCOLOR), lineX, firstLineY, ALLEGRO_ALIGN_CENTRE, text.c_str());
	al_draw_text(font, al_color_name(SUCCESSTEXTCOLOR), lineX, secondLineY, ALLEGRO_ALIGN_CENTRE, getOut.c_str());
}


void drawBanner(ALLEGRO_FONT * font, int ticks, float top, const char * bannerColor, int bots)
{
	string tixt, robotCountString;
	ALLEGRO_DISPLAY * display = al_get_current_display();
	float height = al_get_display_height(display);
	float width = al_get_display_width(display);
	float bannerHeight = height - top;

	al_draw_filled_rectangle(0, top, width, height, al_color_name(bannerColor));

	tixt = "Current tick: " + to_string(ticks);
	robotCountString = "Ammount of robots: " + to_string(bots);

	al_draw_text(font, al_color_name(BANNERTEXTCOLOR), width / 4.0, top + bannerHeight / 2.8, ALLEGRO_ALIGN_CENTRE, tixt.c_str());
	al_draw_text(font, al_color_name(BANNERTEXTCOLOR), width * 3 / 4.0, top + bannerHeight / 2.8, ALLEGRO_ALIGN_CENTRE, robotCountString.c_str());
}


void drawAxis(const int scrW, const int scrH)
{
	ALLEGRO_DISPLAY* display = al_get_current_display();
	ALLEGRO_FONT * font = NULL;
	font = al_load_ttf_font(FONTPATH, 10, 0);

	al_clear_to_color(al_color_name("grey"));

	al_draw_line(40, 50, 40, scrH - 50, al_color_name("white"), 2);
	al_draw_line(40, scrH-50, scrW-60, scrH - 50, al_color_name("white"), 2);

	al_draw_text(font, al_color_name("white"), 30, 50, ALLEGRO_ALIGN_RIGHT, "Ticks");
	al_draw_text(font, al_color_name("white"), scrW - 28, scrH - 57, ALLEGRO_ALIGN_CENTRE, "Robots");

	al_flip_display();
}

void drawBar(const int scrW, const int scrH, const double average, const int barPos, double firstValue)
{
	ALLEGRO_DISPLAY* display = al_get_current_display();
	ALLEGRO_FONT * font = NULL;
	font = al_load_ttf_font(FONTPATH, 10, 0);

	std::string tixt = std::to_string((int)average);

	
	//Cool math stuff
	const int barOffsetX = 40;
	const int barOffsetY = 100;
	const int yAxisSeparationFromFloor = 50;
	const int separation = 10;
	const int xAxis = scrW - barOffsetX;
	const int yAxis = scrH - barOffsetY;
	const int barTotal = 40;
	const int usedPixelsBySeparation = (barTotal * separation) + separation;
	const int barWidth = (xAxis - usedPixelsBySeparation) / barTotal;
	const int tallestBar = yAxis;

	double multiplier = yAxis / firstValue;

	const int currentBarXPosition = (barOffsetX + (separation*barPos) + (barWidth*(barPos - 1)));
	const int currentBarYPosition = (scrH - yAxisSeparationFromFloor - average );

	al_draw_filled_rectangle(currentBarXPosition, (barPos == 1 ? scrH - yAxisSeparationFromFloor -yAxis : scrH -average *multiplier - yAxisSeparationFromFloor) , currentBarXPosition + barWidth, scrH-yAxisSeparationFromFloor, al_color_name("red"));
	al_draw_text(font, al_color_name("black"), currentBarXPosition + (barWidth / 2), (barPos == 1 ? scrH - yAxisSeparationFromFloor - yAxis : scrH - average * multiplier - yAxisSeparationFromFloor) - 20, ALLEGRO_ALIGN_CENTRE, tixt.c_str());
	al_flip_display();

}
















