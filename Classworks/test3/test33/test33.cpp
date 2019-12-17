#include <stdio.h>
#include <string.h>

const int maxLengthOfString = 1000;

bool isNumber(char token)
{
	return token <= '9' && token >= '0';
}

bool isLetter(char token)
{
	return (token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z');
}

bool isAdmissibleSymbol(char token)
{
	return token == '_' || token == '%' || token == '.' || token == '+' || token == '-';
}

bool isAdress(char* string)
{
	if (strlen(string) == 0)
	{
		return false;
	}

	int i = 0;
	int currentState = 0;
	while (true)
	{
		char token = string[i];
		i++;
		switch (currentState)
		{
		case 0:
		{
			if (isNumber(token) || isLetter(token) || isAdmissibleSymbol(token))
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
			if (!isNumber(token) && !isLetter(token) && !isAdmissibleSymbol(token))
			{
				if (token == '@')
				{
					currentState = 2;
				}
				else
				{
					return false;
				}
			}
			break;
		}
		case 2:
		{
			if (isNumber(token) || isLetter(token) || isAdmissibleSymbol(token))
			{
				currentState = 3;
			}
			else
			{
				return false;
			}
		}
		case 3:
		{
			if (!isNumber(token) && !isLetter(token))
			{
				if (token == '.')
				{
					currentState = 4;
				}
				else
				{
					return false;
				}
			}
			break;
		}
		case 4:
		{
			if (isLetter(token))
			{
				currentState = 5;
			}
			else
			{
				return false;
			}
			break;
		}
		case 5:
		{
			if (!isLetter(token))
			{
				if (token == '\0' || token == ' ' || token == '\n')
				{
					return true;
				}
				return false;
			}
			break;
		}
		}
	}
}

int main()
{
	printf("Enter the string:\n");
	char buffer[maxLengthOfString]{};
	scanf("%s", buffer);
	if (isAdress(buffer))
	{
		printf("Yes\n");
	}
	else
	{
		printf("Not\n");
	}

	return 0;
}