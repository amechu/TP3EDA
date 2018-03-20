#include "BarGraph.h"

#define BARCOLOR "red"
#define AXISCOLOR "white"
#define TICKSCOLOR "white"
#define BANNERTEXTCOLOR "white"
#define SUCCESSTEXTCOLOR "white"

#define WIDTHNEWSIZE 2000		
#define HEIGHTNEWSIZE 1500
#define ORIGINX 30.0
#define ORIGINY HEIGHTNEWSIZE - 30.0
#define FINALY 30.0
#define FINALX WIDTHNEWSIZE - 30.0
#define AXISXNAME "Number of robots"
#define AXISYNAME "Ticks"

#define SCALEBAR 2//(0.5)
#define SEPARATION (WIDTHNEWSIZE/40.0)
#define BARTHICKNESS (WIDTHNEWSIZE/70.0)

#define FONTPATH "mont.ttf"
#define FONTSIZE 10
#define STRSEPARATION 15
#define NUMLENGHT 15

/*Inicializa un arreglo de char colocando en cada posicion el terminador '\0'
Recibe el puntero al arreglo de char y la cantidad de elemetos */
static void initilizateCharString(char *stringnum, int elements);

/*Convierte un int en un arreglo de char*/
static void intostr(char* stringnum, int someint);

void DrawBarsGraphic(double * array)

{
	ALLEGRO_DISPLAY * display = al_get_current_display();
	ALLEGRO_FONT * font = NULL;

	font = al_load_ttf_font(FONTPATH, FONTSIZE, 0);

	if (al_init_primitives_addon())
	{
		int RobotsNum = 1;
		int barSeparation = ORIGINX + SEPARATION;		//valores de separacion entre barras, como es discreto la distancia entre barras es constante
		char stringnum[NUMLENGHT];
		
		al_resize_display(display, WIDTHNEWSIZE, HEIGHTNEWSIZE);
		al_set_target_backbuffer(display);

		//Para dibujar ejes
		al_draw_line(ORIGINX, ORIGINY, ORIGINX, FINALY, al_color_name(AXISCOLOR), 1);
		al_draw_line(ORIGINX, ORIGINY, FINALX, ORIGINY, al_color_name(AXISCOLOR), 1);
		al_draw_text(font, al_color_name(AXISCOLOR), FINALX-50, ORIGINY+STRSEPARATION , ALLEGRO_ALIGN_CENTRE, AXISXNAME);
		al_draw_text(font, al_color_name(AXISCOLOR), ORIGINX+STRSEPARATION, FINALY, ALLEGRO_ALIGN_CENTRE, AXISYNAME);

		al_flip_display();		//muestra en pantalla lo dibujado

		while (array[RobotsNum] != TERMINATOR)
		{
			initilizateCharString(stringnum, NUMLENGHT);		//Limpia el string con '\0'
			intostr(stringnum, (int)(array[RobotsNum]));		//el numero entero de ticks escrito como string
			
			//Dibujamos la barra representativa de la cantidad de ticks
			al_draw_line(barSeparation, ORIGINY, barSeparation, ORIGINY - (array[RobotsNum]) * SCALEBAR, al_color_name(BARCOLOR), BARTHICKNESS);
			
			//Escribimos encima de cada barra el valor entero de ticks promedio
			al_draw_text(font, al_color_name(TICKSCOLOR), barSeparation, (ORIGINY - (array[RobotsNum]) * SCALEBAR)- STRSEPARATION, ALLEGRO_ALIGN_CENTRE, stringnum);
			
			al_flip_display();	//muestra en pantalla
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