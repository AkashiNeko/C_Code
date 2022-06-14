//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-6-8
//    author: Akashi (氟氟)
//    github: https://github.com/AkashiNeko/C_Code
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include <stdio.h>

int isLittleEndian()
{
	int a = 1;
	
	//              低地址 --> 高地址
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
