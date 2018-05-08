#include <SDKDDKVer.h>
#include <tchar.h>
#include <Windows.h>
#include <iostream>
#include <stdio.h>
using namespace std;

HANDLE hSerial;
DWORD dwBytesWritten;

void printIn(char*str)
{
	DWORD dwSize;
	for (dwSize=0;str[dwSize];dwSize++);
	WriteFile (hSerial,str,dwSize,&dwBytesWritten ,NULL);
}

void drawPixel(int x,int y,int c)
{
   char str[11];
   DWORD dwSize;
   WriteFile (hSerial,"p ",2,&dwBytesWritten ,NULL);
   sprintf(str, "%d", x);
   for (dwSize=0;str[dwSize];dwSize++);
   WriteFile (hSerial,str,dwSize,&dwBytesWritten ,NULL);
   WriteFile (hSerial," ",1,&dwBytesWritten ,NULL);
  // cout << "go->" << str << " ";
   sprintf(str, "%d", y);
   for (dwSize=0;str[dwSize];dwSize++);
   WriteFile (hSerial,str,dwSize,&dwBytesWritten ,NULL);
   WriteFile (hSerial," ",1,&dwBytesWritten ,NULL);
  // cout << str << " ";
   sprintf(str, "%d", c);
   for (dwSize=0;str[dwSize];dwSize++);
   WriteFile (hSerial,str,dwSize,&dwBytesWritten ,NULL);
   WriteFile (hSerial," ",1,&dwBytesWritten ,NULL);
  // cout << str << " " << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	LPCTSTR sPortName = "COM3";  

	hSerial = ::CreateFile(sPortName,GENERIC_READ | GENERIC_WRITE,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
	if(hSerial==INVALID_HANDLE_VALUE)
	{
		if(GetLastError()==ERROR_FILE_NOT_FOUND)
		{
			cout << "serial port does not exist.\n";
		}
		cout << "some other error occurred.\n";
	}


	DCB dcbSerialParams = {0};
	dcbSerialParams.DCBlength=sizeof(dcbSerialParams);
	if (!GetCommState(hSerial, &dcbSerialParams))
	{
		cout << "getting state error\n";
	}
	dcbSerialParams.BaudRate=2000000;
	dcbSerialParams.ByteSize=8;
	dcbSerialParams.StopBits=ONESTOPBIT;
	dcbSerialParams.Parity=NOPARITY;
	if(!SetCommState(hSerial, &dcbSerialParams))
	{
		cout << "error setting serial port state\n";
	}
	 
	
	
	while(1)
	{
		char a;
		cin >> a;
		for(int j=0;j<20;j++)
			for(int i=0;i<20;i++)
				drawPixel(i,j,2);
		WriteFile (hSerial,"d",1,&dwBytesWritten ,NULL);
		
		
		
	}
	return 0;
}

