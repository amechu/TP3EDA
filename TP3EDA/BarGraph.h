
#include <stdio.h>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <iostream>

/*
using namespace std;


#define TERMINATOR 9999999999999

/*Crea en grafico de barras reduciendo un 50% en escala el valor de ticks pasados en un arreglo  
void DrawBarsGraphic(double * array);

/*Muestra en pantalla el resultado final de la ejecución del programa, muestra los ticks precisados para
la cantidad de robots ingresados
void drawSuccess(int ticks, ALLEGRO_FONT* font);

/*Muestra debajo del display de simuación los ticks a tiempo real y la cantidad de robots en pantalla
void drawBanner(ALLEGRO_FONT * font, int ticks, float top, const char * bannerColor, int bots);

*/

#define TERMINATOR 9999999999999.0

void drawAxis(const int scrW, const int scrH);
void drawBar(const int scrW, const int scrH, double average, int barPos, double firstValue);

//
//