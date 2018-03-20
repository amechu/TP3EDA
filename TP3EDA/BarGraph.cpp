#include "BarGraph.h"

#define BARCOLOR "red"
#define AXISCOLOR "white"
#define TICKSCOLOR "white"

#define WIDTHNEWSIZE 1000		
#define HEIGHTNEWSIZE 500
#define ORIGINX 30.0
#define ORIGINY HEIGHTNEWSIZE - 30.0
#define FINALY 30.0
#define FINALX WIDTHNEWSIZE - 30.0
#define AXISXNAME "Number of robots"
#define AXISYNAME "Ticks"

#define SCALEBAR (0.5)
#define SEPARATION (WIDTHNEWSIZE/25.0)
#define BARTHICKNESS (WIDTHNEWSIZE/50.0)


#define FONTPATH "mont.ttf"
#define FONTSIZE 10
#define STRSEPARATION 15

#define NUMLENGHT 15

static void initilizateCharString(char *stringnum, int elements);
static void intostr(char* stringnum, int someint);

void DrawBarsGraphic(double * array)

{
	ALLEGRO_DISPLAY * display = al_get_current_display();
	ALLEGRO_FONT * font = NULL;

	font = al_load_ttf_font(FONTPATH, FONTSIZE, 0);

	if (al_init_primitives_addon())
	{
		int RobotsNum = 1;
		int barSeparation = ORIGINX + SEPARATION;
		char stringnum[NUMLENGHT];
		
		al_resize_display(display, WIDTHNEWSIZE, HEIGHTNEWSIZE);
		al_set_target_backbuffer(display);

		//To draw AXIS
		al_draw_line(ORIGINX, ORIGINY, ORIGINX, FINALY, al_color_name(AXISCOLOR), 1);
		al_draw_line(ORIGINX, ORIGINY, FINALX, ORIGINY, al_color_name(AXISCOLOR), 1);
		al_draw_text(font, al_color_name(AXISCOLOR), FINALX-50, ORIGINY+STRSEPARATION , ALLEGRO_ALIGN_CENTRE, AXISXNAME);
		al_draw_text(font, al_color_name(AXISCOLOR), ORIGINX+STRSEPARATION, FINALY, ALLEGRO_ALIGN_CENTRE, AXISYNAME);

		al_flip_display();

		while (array[RobotsNum] != TERMINATOR)
		{
			initilizateCharString(stringnum, NUMLENGHT);
			intostr(stringnum, (int)(array[RobotsNum]));
			
			al_draw_line(barSeparation, ORIGINY, barSeparation, ORIGINY - (array[RobotsNum]) * SCALEBAR, al_color_name(BARCOLOR), BARTHICKNESS);
			
			al_draw_text(font, al_color_name(TICKSCOLOR), barSeparation, (ORIGINY - (array[RobotsNum]) * SCALEBAR)- STRSEPARATION, ALLEGRO_ALIGN_CENTRE, stringnum);
			
			al_flip_display();
			RobotsNum++;
			barSeparation += SEPARATION;
		}

	}
	else
	{
		fprintf(stderr, "Any resource is not loaded, error");
	}
	al_shutdown_primitives_addon();
}



static void initilizateCharString(char *stringnum, int elements)
{
	for (int i = 0; i < elements; i++)
	{
		stringnum[i] = '\0';
	}
}

static void intostr(char* stringnum, int someint)
{
	sprintf(stringnum, "%d", someint);
}