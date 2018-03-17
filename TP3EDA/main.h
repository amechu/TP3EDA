#include <allegro5\allegro.h>
#include <allegro5\allegro_color.h>
#include <stdio.h>

// Important compiling stuff

//#define FONT_C
#define AUDIO_C
//#define KEYBOARD_C
//#define MOUSE_C
#define IMAGE_C
//#define EVENT_C
//#define TIMER_C
#define DISPLAY_C

// Important Display Constants
#define DISPLAYW (1500)
#define DISPLAYH (1500)

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
#define SONGPATH "AvengersInfinityWarMusic.ogg"
#define NUMBEROFSAMPLES (1)
#define VOLUME (1.0)
#define SONGSPEED (1.0)
#endif

// Important Image Constants
#ifdef IMAGE_C
#include <allegro5\allegro_image.h>
#endif



enum initsAndInstalls
{
	ALLEGRO, DISPLAY,IMAGE, EVENTQUEUE, TIMER, TTFADDON, AUDIO, CODEC, RESERVESAMPLES,LASTI
};

enum createAndDelete
{
	FONT, SONG, LASTC
};