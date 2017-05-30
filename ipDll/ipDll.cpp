// 这是主 DLL 文件。

#include "stdafx.h"
#include <string.h>
#include "ipDll.h"

//CIP2LOCdll ip2LocLib;

ipDll::IP2LOCCLR::IP2LOCCLR()
{
	CIP2LOCPtr = (CIP2LOCdll*)(new CIP2LOCdll());
	resultStr = new char[800];
	return;
}

ipDll::IP2LOCCLR::~IP2LOCCLR()
{
	delete[] resultStr;
	delete (CIP2LOCdll*)CIP2LOCPtr;
}


bool ipDll::IP2LOCCLR::init(String ^ filePath)
{
	binPath = (char*)(Marshal::StringToHGlobalAnsi(filePath)).ToPointer();
	memset(resultStr, 0, 800);
	if (((CIP2LOCdll*)CIP2LOCPtr)->init(binPath)) return true;
	else return false;
}

String^ ipDll::IP2LOCCLR::Query(String ^ ipStr)
{
	memset(resultStr, 0, 800);
	char* ipStr_c = (char*)(Marshal::StringToHGlobalAnsi(ipStr)).ToPointer();
	char* result_c = ((CIP2LOCdll*)CIP2LOCPtr)->Query(ipStr_c);
	strcat(resultStr, result_c);
	return Marshal::PtrToStringAnsi((IntPtr)(char *)resultStr);
}
