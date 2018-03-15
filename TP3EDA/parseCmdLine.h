#pragma once

#include <stdio.h>
#include "errors and structures.h"


typedef int(*pCallback) (char *, char*, void *);
int parseCmdLine(int argc, char *argv[], pCallback p, void *userData);