/*#include "BarGraph.h"

#define BARCOLOR "red"
#define AXISCOLOR "white"
#define TICKSCOLOR "white"
#define BANNERTEXTCOLOR "white"
#define SUCCESSTEXTCOLOR "white"

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

/*Inicializa un arreglo de char colocando en cada posicion el terminador '\0'
Recibe el puntero al arreglo de char y la cantidad de elemetos 
static void initilizateCharString(char *stringnum, int elements);

/*Convierte un int en un arreglo de char
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

*/











































#include "notmain.h"
#include "BarGraph.h"

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

void drawBar(const int scrW, const int scrH, const double average, const int barPos)
{
	ALLEGRO_DISPLAY* display = al_get_current_display();
	ALLEGRO_FONT * font = NULL;
	font = al_load_ttf_font(FONTPATH, 10, 0);

	std::string tixt = std::to_string((int)average);

	static float heightOffset;

	//Cool math stuff
	const int barOffset = 40;
	const int yAxisSeparationFromFloor = 50;
	const int separation = 10;
	const int xAxis = scrW - barOffset;
	const int yAxis = scrH - barOffset;
	const int barTotal = 30;
	const int usedPixelsBySeparation = (barTotal * separation) + separation;
	const int barWidth = (xAxis - usedPixelsBySeparation) / barTotal;
	const int tallestBar = yAxis;

	if (barPos == 1)
		heightOffset = average - tallestBar;

	const int currentBarXPosition = (barOffset + (separation*barPos) + (barWidth*(barPos - 1)));
	const int currentBarYPosition = (scrH - yAxisSeparationFromFloor - average + heightOffset + 60);

	al_draw_filled_rectangle(currentBarXPosition, currentBarYPosition, currentBarXPosition + barWidth, scrH-yAxisSeparationFromFloor, al_color_name("red"));
	al_draw_text(font, al_color_name("black"), currentBarXPosition + (barWidth / 2), currentBarYPosition - 20, ALLEGRO_ALIGN_CENTRE, tixt.c_str());
	al_flip_display();

}
















