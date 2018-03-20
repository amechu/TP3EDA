#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HELP 1

#define NOERROR 0
#define ERRORTYPE1 -1
#define ERRORTYPE2 -2
#define ERRORTYPE3 -3

#define MODEONE 1
#define MODETWO 2

typedef struct {
	int col = 0;
	int row = 0;
	int mode = 0;
	int bots = 0;
	int step = 0;
	int help = 0;
} usrInput;

int fillInformation(char * pass, char * value, void * userData);
