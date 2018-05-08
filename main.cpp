#include "SerialPortConsole.h"

int main()
{
	initSerialConsole();
	while(1)
	{
		char a;
		cin >> a;
		for(int j=0;j<20;j++)
			for(int i=0;i<20;i++)
				drawPixel(i,j,2);
		WriteFile (hSerial,"d",1,&dwBytesWritten ,NULL);
	}

}