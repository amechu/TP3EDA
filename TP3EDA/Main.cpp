#include "main.h"
#include "Floor.h"
#include "Robot.h"
#include "Simulation.h"
#include "parseCmdLine.h"
#include "callback.h"

#define MAXROBOTS (500)
#define DIRTYTILEBITMAP ""
#define CLEANTILEBITMAP ""
#define ROBOTBITMAP ""


bool resourcesLoaded(bool * array, int size);

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
	int ticks = 0;
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
			if (font = al_load_ttf_font(FONTPATH, FONTSIZE, 0))
				initResources[LASTI + FONT];
		}
#else
		initResources[TTFADDON] = true;
		initResources[LASTI + FONT] = true;
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

		al_start_timer(timer);

#ifdef AUDIO_C
		al_play_sample(song, VOLUME, 0, SONGSPEED, ALLEGRO_PLAYMODE_LOOP, NULL);
#endif
		switch (parseCmdLine(argc, argv, &fillInformation, &information))
		{
		case ERRORTYPE1:
			break;
		case ERRORTYPE2:
			break;
		case ERRORTYPE3:
			break;
		default:
			if (information.mode == MODEONE)
			{// No se que carajo pasa aca
				Simulation room(information.bots, information.row, information.col, DIRTYTILEBITMAP, CLEANTILEBITMAP, ROBOTBITMAP);
				while (!room.cycle())
				{
					room.draw();
					ticks++;
					al_rest(1);
				}
			}
			else if (information.mode == MODETWO)
			{
				double ticksMedio[MAXROBOTS];


				for(int i = 0;  (i<MAXROBOTS) && (ticksMedio[i] - ticksMedio[i - 1] >0.1); ++i)
				{
					double ticksSum = 0.0;

					for(int a = 0; a < 1000; ++a)
					{
						Simulation room(i, information.row, information.col, DIRTYTILEBITMAP, CLEANTILEBITMAP, ROBOTBITMAP);
						ticksSum += room.run();
					}
					ticksMedio[i] = ticksSum / 1000.0;

					// Hacer Grafico de barras
				}
			}
		}


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