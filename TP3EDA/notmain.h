#include <allegro5\allegro.h>
#include <allegro5\allegro_color.h>
#include <stdio.h>
#include <string>

// Important compiling stuff

#define PRIMITIVES_C
#define FONT_C
#define AUDIO_C
#define KEYBOARD_C
//#define MOUSE_C
#define IMAGE_C
//#define EVENT_C
//#define TIMER_C
#define DISPLAY_C

// Important Display Constants
#define DISPLAYW (2000)
#define DISPLAYH (1300)

// Important Timer Constants
#define REFRESHRATE (60.0)

// Important Font Constants
#ifdef FONT_C
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h> //Copyright (c) 2011-2012, Julieta Ulanovsky, reserved Font Names 'Montserrat'
#define FONTPATH "mont.ttf" //This Font Software is licensed under the SIL Open Font License, Version 1.1.
#define FONTSIZE (10 - DISPLAYW/DISPLAYH - DISPLAYH/DISPLAYW + DISPLAYW/100 + DISPLAYH/100)
#endif

// Important Primitives Constants
#ifdef PRIMITIVES_C
#include <allegro5\allegro_primitives.h>
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
	ALLEGRO, DISPLAY, IMAGE, EVENTQUEUE, TIMER, TTFADDON, AUDIO, CODEC, RESERVESAMPLES, PRIMITIVES, LASTI
};

enum createAndDelete
{
	FONT, SONG, LASTC
};