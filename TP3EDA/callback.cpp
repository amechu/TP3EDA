#include "callback.h"



int fillInformation(char * pass, char * value, void * userData)
{
	usrInput * usr = (usrInput *)userData;
	int retValue = NOERROR;
	if (pass)
	{
		if ((!usr->bots) && !strcmp(_strlwr((char *)pass), "bots"))
		{
			usr->bots = atoi(value);
			if (usr->bots <= 0)
				retValue = ERRORTYPE3;
		}
		else if ((!usr->col) && !strcmp(_strlwr((char *)pass), "columns"))
		{
			usr->col = atoi(value);
			if (usr->col <= 0)
				retValue = ERRORTYPE3;
		}
		else if ((!usr->row) && !strcmp(_strlwr((char *)pass), "rows"))
		{
			usr->row = atoi(value);
			if (usr->row <= 0)
				retValue = ERRORTYPE3;
		}
		else if ((!usr->mode) && !strcmp(_strlwr((char *)pass), "mode"))
		{
			usr->mode = atoi(value);
			if ((usr->mode != MODEONE) && (usr->mode != MODETWO))
				retValue = ERRORTYPE3;
		}
		else
			retValue = ERRORTYPE3;  // This error means that the user used an incorrect keyword
	}
	else
		retValue = ERRORTYPE3;


	return  retValue;
}
