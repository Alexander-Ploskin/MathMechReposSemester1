#include <ctype.h>
#include "Analyzer.h"

bool isDigit(const char token)
{
	return token <= '9' && token >= '0';
}

bool isNumberOfGroup(char* string)
{
	int i = 0;

	int currentState = 0;
	while (i < maxLength)
	{
		const char currentToken = string[i];
		++i;

		switch (currentState)
		{
		case 0:
		{
			if (isDigit(currentToken))
			{
				currentState = 1;
			}
			else
			{
				return false;
			}
			break;
		}
		case 1:
		{
			if (isDigit(currentToken))
			{
				currentState = 2;
			}
			else
			{
				return false;
			}
			break;
		}
		case 2:
		{
			if (currentToken == 'B' || currentToken == 'M' || currentToken == 'S')
			{
				currentState = 3;
			}
			else
			{
				return false;
			}
			break;
		}
		case 3:
		{
			if (currentToken == '1')
			{
				currentState = 4;
			}
			else if (isDigit(currentToken))
			{
				currentState = 5;
			}
			else
			{
				return false;
			}
			break;
		}
		case 4:
		{
			if (currentToken == '0')
			{
				currentState = 5;
			}
			else if (currentToken == '-')
			{
				currentState = 6;
			}
			else
			{
				return false;
			}
			break;
		}
		case 5:
		{
			if (currentToken == '-')
			{
				currentState = 6;
			}
			else
			{
				return false;
			}
			break;
		}
		case 6:
		{
			if (currentToken == 'm')
			{
				currentState = 7;
			}
			else
			{
				return false;
			}
			break;
		}
		case 7:
		{
			return currentToken == 'm';
		}
		}
	}
}