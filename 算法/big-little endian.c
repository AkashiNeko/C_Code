#include <stdio.h>

int isLittleEndian()
{
	int a = 1;

	// Little Endian ( 01 00 00 00 ) -> return 1 
	// Big    Endian ( 00 00 00 01 ) -> return 0

	char* p = (char*)&a;
	return (int)*p;
}

int main()
{
	if (isLittleEndian())
		printf("Little Endian\n");
	else
		printf("Big Endian\n");
	return 0;
}