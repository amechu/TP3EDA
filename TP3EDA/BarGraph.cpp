#include "BarGraph.h"

#define BARCOLOR "red"
#define AXISCOLOR "white"
#define SEPARATION 20.0
#define WIDTHNEWSIZE 1000
#define HEIGHTNEWSIZE 500
#define ORIGINX 30.0
#define ORIGINY HEIGHTNEWSIZE - 30.0
#define FINALY 30.0
#define FINALX WIDTHNEWSIZE - 30.0
#define SCALEBAR 0.5
#define BARTHICKNESS 5

void DrawBarsGraphic(double * array, ALLEGRO_DISPLAY * display)
{
	
	
	if (al_init_primitives_addon())
	{
	//	if (al_init_font_addon())
	//	{
			int RobotsNum = 1;
			int barSeparation = ORIGINX + SEPARATION;
			al_resize_display(display, WIDTHNEWSIZE, HEIGHTNEWSIZE);
			al_set_target_backbuffer(display);

			al_draw_line(ORIGINX, ORIGINY, ORIGINX, FINALY, al_color_name(AXISCOLOR), 1);
			al_draw_line(ORIGINX, ORIGINY, FINALX, ORIGINY, al_color_name(AXISCOLOR), 1);
		//	al_draw_text();
			al_flip_display();

			while (array[RobotsNum] != TERMINATOR)
			{
				al_draw_line(barSeparation, ORIGINY, barSeparation, ORIGINY - (array[RobotsNum]) * SCALEBAR, al_color_name(BARCOLOR), BARTHICKNESS);
				al_flip_display();
				RobotsNum++;
				barSeparation += SEPARATION;
			}

	//	}
	}
	else
	{
		fprintf(stderr, "Any resource is not loaded, error");
	}
	al_shutdown_primitives_addon();
//	al_shutdown_font_addon();
}