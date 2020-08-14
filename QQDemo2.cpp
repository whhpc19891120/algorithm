
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * GetValue(char *src, char *dest, int num, char ch)
{
	char *s0 = dest;
	dest[0] = 0;
	while (*src != 0 && *src != '\n' && num != 1)
	{
		if (*src == ch)
			num--;
		src++;
	}
	while (*src != 0 && *src != '\n' && *src != ch)
		*s0++ = *src++;
	*s0 = 0;
	return dest;
}

char * GetDataValue(char *src, char *dest, int nmaxlen, int num, char ch)
{
	char *s0 = dest;
	int nct = 0;
	dest[0] = 0;
	while (*src != 0 && *src != '\n' && num != 1)
	{
		if (*src == ch)
			num--;
		src++;
	}
	while (*src != 0 && *src != '\n' && *src != ch && nct < (nmaxlen - 1))
	{
		*s0++ = *src++;
		nct++;
	}
	*s0 = 0;
	return dest;
}


int main2()
{
	char str[] = "ab,cde,fgh,,k";
	char value[32];
	GetDataValue(str, value, sizeof(value)-1, 2, ',');
	value[sizeof(value) - 1] = 0;
	printf("%s\n", value);

	/*
	char str[] = "ab,cde,fgh,,k";
	char value[32];
	GetValue(str, value, 2, ',');
	value[sizeof(value) - 1] = 0;
	printf("%s\n", value);

	// ·Ö¸îÊý×é
	char * p;
	char *token = strtok_s(str, ",", &p);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok_s(NULL, ",", &p);
	}
	*/

	return 0;
}