
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
//#include <allegro5\allegro_font.h>

#define TERMINATOR 9999999999999

/*Crea en grafico de barras reduciendo un 50% en escala el valor de ticks pasados en un arreglo  */
void DrawBarsGraphic(double * array);