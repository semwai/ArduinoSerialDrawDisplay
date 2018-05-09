#include "SerialPortConsole.h"

int main()
{
	initSerialConsole();
	while(1)
	{
		char a;
		cin >> a;
		for(int j=16;j<48;j+=2)
			for(int i=16;i<112;i+=2)
				drawPixel(i,j,1);
		drawRect(5,5,118,54,2);
		drawDisplay();
	}

}