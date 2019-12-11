#include "analyzer.h"

bool isDigit(const char symbol)
{
	return symbol <= '9' && symbol >= '0';
}

bool isNumber(char* inputString)
{
	int state = 0;
	int i = 0;

	while (true)
	{
		const char symbol = inputString[i];
		switch (state)
		{
		case 0:
		{
			if (isDigit(symbol))
			{
				i++;
				state = 2;
			}
			else if (symbol == '-' || symbol == '+')
			{
				i++;
				state = 1;
			}
			else
			{
				return false;
			}
			break;
		}
		case 1:
		{
			if (isDigit(symbol))
			{
				i++;
				state = 2;
			}
			else
			{
				return false;
			}
			break;
		}
		case 2:
		{
			if (isDigit(symbol))
			{
				i++;
			}
			else if (symbol == '.')
			{
				i++;
				state = 3;
			}
			else if (symbol == 'E')
			{
				i++;
				state = 5;
			}
			else if (symbol == '\0')
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
		case 3:
		{
			if (isDigit(symbol))
			{
				state = 4;
				i++;
			}
			else
			{
				return false;
			}
			break;
		}
		case 4:
		{
			if (isDigit(symbol))
			{
				i++;
			}
			else if (symbol == 'E')
			{
				state = 5;
				i++;
			}
			else if (symbol == '\0')
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
		case 5:
		{
			if (symbol == '-' || symbol == '+')
			{
				state = 6;
				i++;
			}
			else if (isDigit(symbol))
			{
				state = 7;
				i++;
			}
			else
			{
				return false;
			}
			break;
		}
		case 6:
		{
			if (isDigit(symbol))
			{
				state = 7;
				i++;
			}
			else
			{
				return false;
			}
			break;
		}
		case 7:
		{
			if (isDigit(symbol))
			{
				i++;
			}
			else if (symbol == '\0')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		}
	}
}
