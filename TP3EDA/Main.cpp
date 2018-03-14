#include <allegro5\allegro.h>
#include <allegro5\allegro_color.h>
#include <stdio.h>


// Important compiling stuff

#define FONT_C
#define AUDIO_C
#define KEYBOARD_C
#define MOUSE_C

// Important Display Constants
#define DISPLAYW (1000)
#define DISPLAYH (2000)

// Important Timer Constants
#define REFRESHRATE (60.0)

// Important Font Constants
#ifdef FONT_C
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#define FONTPATH "path"
#define FONTSIZE (10)
#endif

// Important Music Constants
#ifdef AUDIO_C
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_audio.h>
#define SONGPATH "path"
#define NUMBEROFSAMPLES (1)
#define VOLUME (1.0)
#define SONGSPEED (1.0)
#endif


enum resources
{
	ALLEGRO, DISPLAY, EVENTQUEUE, TIMER, TTFADDON, FONT, AUDIO, CODEC, SONG, RESERVESAMPLES, LAST
};

bool resourcesLoaded(bool * array, int size);

int main()
{
	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_EVENT_QUEUE * eventQueue = NULL;
	ALLEGRO_TIMER * timer = NULL;
#ifdef FONT_C
	ALLEGRO_FONT * font = NULL;
#endif
#ifdef AUDIO_C
	ALLEGRO_SAMPLE * song = NULL;
#endif


	bool keep = true;

	bool initResources[LAST];
	for (int i = 0; i < LAST; ++i)
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

		if (display = al_create_display(DISPLAYW, DISPLAYH))
		{
			initResources[DISPLAY] = true;
		}
		if (eventQueue = al_create_event_queue())
			initResources[EVENTQUEUE] = true;
		if (timer = al_create_timer(1 / REFRESHRATE))
			initResources[TIMER] = true;
#ifdef FONT_C
		al_init_font_addon();
		if (al_init_ttf_addon())
		{
			initResources[TTFADDON] = true;
			if (font = al_load_ttf_font(FONTPATH, FONTSIZE, 0))
				initResources[FONT];
		}
#else
		initResources[TTFADDON] = true;
		initResources[FONT];
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
				initResources[SONG] = true;
		}
#else
		initResources[AUDIO] = true;
		initResources[CODEC] = true;
		initResources[RESERVESAMPLES] = true;
		initResources[SONG] = true;
#endif
	}

	if (resourcesLoaded(initResources, LAST))
	{
		al_register_event_source(eventQueue, al_get_display_event_source(display));
		al_register_event_source(eventQueue, al_get_timer_event_source(timer));
#ifdef MOUSE_C
		al_register_event_source(eventQueue, al_get_mouse_event_source());
#endif
#ifdef KEYBOARD_C
		al_register_event_source(eventQueue, al_get_keyboard_event_source());
#endif

		al_start_timer(timer);

#ifdef AUDIO_C
		al_play_sample(song, VOLUME, 0, SONGSPEED, ALLEGRO_PLAYMODE_LOOP, NULL);
#endif

		while (keep)
		{
			ALLEGRO_EVENT ev;

			if (al_get_next_event(eventQueue, &ev))
			{
				//Events
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
		if (initResources[FONT])
			al_destroy_font(font);
	}
#endif

	if (initResources[EVENTQUEUE])
		al_destroy_event_queue(eventQueue);

	if (initResources[TIMER])
		al_destroy_timer(timer);

	if (initResources[DISPLAY])
	{
		al_destroy_display(display);
	}

	return 0;
}

bool resourcesLoaded(bool * array, int size)
{
	bool retValue = true;

	for (int i = 0; (i < size) && retValue; ++i)
		if (array[i] == false)
			retValue = false;
	return retValue;
}