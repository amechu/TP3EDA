#pragma once

#include <stdio.h>

#define NOERROR 0
#define ERRORTYPE1 -1
#define ERRORTYPE2 -2
#define ERRORTYPE3 -3

typedef int(*pCallback) (char *, char*, void *);
int parseCmdLine(int argc, char *argv[], pCallback p, void *userData);