#include "notmain.h"
#include "Floor.h"
#include "Robot.h"
#include "Simulation.h"
#include "parseCmdLine.h"
#include "callback.h"
#include "BarGraph.h"

using namespace std;


#define MAXROBOTS (500)
#define DIRTYTILEBITMAP "DirtyTile.png"
#define CLEANTILEBITMAP "CleanTile.png"
#define ROBOTBITMAP "captainShield.png"

#define BANNERHEIGHT (DISPLAYH / 10.0)
#define ESCAPEKEY (27)

bool resourcesLoaded(bool * array, int size);
void loadArray(double * arr, int size, double value);
void waitForKey(char a);
void help (void);

int main(int argc, char *argv[])
{
#ifdef DISPLAY_C
	ALLEGRO_DISPLAY * display = NULL;
#endif
#ifdef TIMER_C
	ALLEGRO_TIMER * timer = NULL;
#endif
#ifdef EVENT_C
	ALLEGRO_EVENT_QUEUE * eventQueue = NULL;
#endif
#ifdef FONT_C
	ALLEGRO_FONT * font = NULL;
#endif
#ifdef AUDIO_C
	ALLEGRO_SAMPLE * song = NULL;
#endif
	usrInput information;
	
	srand(time(NULL));

	bool keep = true;

	bool initResources[LASTI + LASTC];
	for (int i = 0; i < LASTI + LASTC ; ++i)
		initResources[i] = false;

	if (al_init())
	{
		initResources[ALLEGRO] = true;

#ifdef KEYBOARD_C
		al_install_keyboard();
#endif
#ifdef MOUSE_C
		al_install_mouse();
#endif
#ifdef IMAGE_C
		if (al_init_image_addon())
			initResources[IMAGE] = true;
#else
		initResources[IMAGE] = true;
#endif
#ifdef DISPLAY_C
		if (display = al_create_display(DISPLAYW, DISPLAYH))
		{
			initResources[DISPLAY] = true;
		}
#else
		initResources[DISPLAY] = true;
#endif
#ifdef EVENT_C
		if (eventQueue = al_create_event_queue())
			initResources[EVENTQUEUE] = true;
#else
		initResources[EVENTQUEUE] = true;
#endif
#ifdef TIMER_C
		if (timer = al_create_timer(1 / REFRESHRATE))
			initResources[TIMER] = true;
#else
		initResources[TIMER] = true;
#endif
#ifdef FONT_C
		al_init_font_addon();
		if (al_init_ttf_addon())
		{
			initResources[TTFADDON] = true;
			if (font = al_load_ttf_font(FONTPATH, -FONTSIZE, 0)) // Si pones el tamaño de la fuente negativo, entonces la toma como pixeles 
				initResources[LASTI + FONT] = true;
		}
#else
		initResources[TTFADDON] = true;
		initResources[LASTI + FONT] = true;
#endif
#ifdef PRIMITIVES_C
		if (al_init_primitives_addon())
			initResources[PRIMITIVES] = true;
#else
			initResources[PRIMITIVES] = true;
#endif
#ifdef AUDIO_C
		if (al_install_audio())
			initResources[AUDIO] = true;
		if (al_init_acodec_addon())
			initResources[CODEC] = true;
		if (al_reserve_samples(NUMBEROFSAMPLES))
		{
			initResources[RESERVESAMPLES] = true;
			if (song = al_load_sample(SONGPATH))
				initResources[LASTI + SONG] = true;
		}
#else
		initResources[AUDIO] = true;
		initResources[CODEC] = true;
		initResources[RESERVESAMPLES] = true;
		initResources[LASTI + SONG] = true;
#endif
	}

	if (resourcesLoaded(initResources, LASTI + LASTC))
	{
#ifdef EVENT_C
		al_register_event_source(eventQueue, al_get_display_event_source(display));
		al_register_event_source(eventQueue, al_get_timer_event_source(timer));
#ifdef MOUSE_C
		al_register_event_source(eventQueue, al_get_mouse_event_source());
#endif
#ifdef KEYBOARD_C
		al_register_event_source(eventQueue, al_get_keyboard_event_source());
#endif
#endif
#ifdef TIMER_C
		al_start_timer(timer);
#endif
#ifdef AUDIO_C
		al_play_sample(song, VOLUME, 0, SONGSPEED, ALLEGRO_PLAYMODE_LOOP, NULL);
#endif

// Aca empieza la parte importante del main
		switch (parseCmdLine(argc, argv, &fillInformation, &information))
		{
		case ERRORTYPE1:
			break;
		case ERRORTYPE2:
			break;
		case ERRORTYPE3:
			break;
		case HELP:
		{
			help();					//Comentado hasta que la funcion esté
			break;
		}
		default:
			if (information.mode == MODEONE)
			{/*
				int ticks = 0;				
				Simulation framework(information.bots, information.row, information.col, (char *) DIRTYTILEBITMAP, (char *)CLEANTILEBITMAP, (char *)ROBOTBITMAP,DISPLAYW,DISPLAYH - BANNERHEIGHT);
				// Este while loop es el modo 1. La funcion cycle realiza un ciclo de la simulacion, si sigue habiendo baldosas sucias, va a devolver 'false'
				// y el loop entra a dibujarlo en pantalla, suma 1 a la cantidad de ticks y espera un tiempo determinado
				do{
					framework.draw();
					drawBanner(font, ticks, DISPLAYH - BANNERHEIGHT, "black", information.bots);
					al_flip_display();

					ticks++;

					if (information.step)
						waitForKey('\n');
					else
						al_rest(0.03);

				} while (!framework.cycle());
				drawBanner(font, ticks, DISPLAYH - BANNERHEIGHT, "black", information.bots);
				drawSuccess(ticks, font);
				al_flip_display();
				waitForKey('\n');
				*/
			}
			else if (information.mode == MODETWO)
			{
				double ticksSum;
				double ticksMedio[MAXROBOTS];
				loadArray(ticksMedio, MAXROBOTS, 9999999999999.0);
				drawAxis(DISPLAYW, DISPLAYH);

				// Este es el modo 2, donde se ejecuta la simulacion sin parte grafica de forma que por cada cantidad de robots se ejecutan 1000 simulaciones 
				// y se realiza un promedio de la cantidad de la cantidad de ticks que tardan cada una. Esto nos va a permitir hacer un grafico de barras al final
				// y se va a poder ver que cantidad de robots es ideal para limpiar el piso
				
				for(int i = 1;  (i<MAXROBOTS) && (i == 1 ? true : (ticksMedio[i] - ticksMedio[i - 1] >0.1)); ++i)
				{
					ticksSum = 0.0;

					for(int a = 0; a < 1000; ++a)
					{
						Simulation framework(i, information.row, information.col, DIRTYTILEBITMAP, CLEANTILEBITMAP, ROBOTBITMAP, information.col * 10, information.row * 10);
						ticksSum += framework.run();
					}
					ticksMedio[i] = ticksSum / 1000.0;		//Asigna el promedio de ticks para las 1000 simulaciones

					drawBar(DISPLAYW, DISPLAYH, ticksSum/1000.0, i);
					
				}
			}
		}
//Hasta acá llega la parte importante del main

		auto enter = []()
		{ ALLEGRO_KEYBOARD_STATE keystate;
		do { al_rest(0.1); al_get_keyboard_state(&keystate); } while (!(al_key_down(&keystate, ALLEGRO_KEY_ENTER)));
		};
		enter();

	}
	else
		fprintf(stderr, "Resources were not loaded properly\n Shutting down\n");
		

#ifdef AUDIO_C
	al_stop_samples();
	if (initResources[CODEC] && initResources[AUDIO] && initResources[RESERVESAMPLES])
	{
		if (initResources[SONG])
			al_destroy_sample(song);
	}
#endif
#ifdef FONT_C
	if (initResources[TTFADDON])
	{
		if (initResources[LASTI + FONT])
			al_destroy_font(font);
	}
#endif
#ifdef EVENT_C
	if (initResources[EVENTQUEUE])
		al_destroy_event_queue(eventQueue);
#endif
#ifdef TIMER_C
	if (initResources[TIMER])
		al_destroy_timer(timer);
#endif

#ifdef DISPLAY_C
	if (initResources[DISPLAY])
	{
		al_destroy_display(display);
	}
#endif

#ifdef PRIMITIVES_C
	if (initResources[PRIMITIVES])
	{
		al_shutdown_primitives_addon();
	}
#endif

	return 0;
}

bool resourcesLoaded(bool * array, int size)
{
	bool retValue = true;

	for (int i = 0; (i < size) && retValue; ++i)
		if (!array[i])
			retValue = false;
	return retValue;
}

void loadArray(double * arr, int size, double value)
{
	for (int i = 0; i < size; ++i)
		arr[i] = value;
}

void waitForKey(char a)
{
	ALLEGRO_KEYBOARD_STATE keystate;
	do
	{
		al_rest(0.1);
		al_get_keyboard_state(&keystate);
	} while (!(al_key_down(&keystate, ALLEGRO_KEY_ENTER)));
}


void help(void)
{
	printf("Uso: ./SimRob [-MODE] [-COLUMNS] [-ROWS] [-BOTS] [-STEP]\n\n");
	printf("-MODE: que tipo de modo se desea correr.\n");
	printf("	1 -> Modo simulacion. Corre una simulacion del programa y la enseña paso a paso.\n");
	printf("	2 -> Modo promedio grafico. Encuentra que cantidad de robots da un promedio de tiempo de limpieza\n			con diferencia menor a 0.1 respecto a la cantidad mas uno.\n");
	printf("-COLUMNS: cantidad de columnas.\n");
	printf("-ROWS: cantidad de filas.\n");
	printf("-BOTS: cantidad de robots. En caso de elegir modo 2, este valor no sera tenido en cuenta.\n");
	printf("-STEP: \n");
}