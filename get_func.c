#include "main.h"

/**
* getHelperFunction - get the appropriate helper function for the specifier
* @specifier: specifier character
* Return: pointer to the helper function, or NULL if not found
*/
int (*getHelperFunction(const char *specifier))(va_list)
{
	helpconversion_t helpconversion[] = {
		{'c', _helperChar},
		{'s', _helperString},
		{'%', _helperPercent},
		{'d', _helpNum},
		{'i', _helpNum},
		{'\0', NULL}
	};

	int i;

	for (i = 0; helpconversion[i].format != '\0'; i++)
	{
		if (*specifier == helpconversion[i].format)
			return (helpconversion[i].helper);
	}

	return (NULL);
}
