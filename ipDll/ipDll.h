// ipDll.h


#pragma comment(lib, "IP2LOC-dll.lib")
#pragma once
#include "IP2LOC-dll.h"
#using <mscorlib.dll>
using namespace System;
using namespace System::Runtime::InteropServices;

namespace ipDll {

	public ref class IP2LOCCLR
	{
		// TODO:  在此处添加此类的方法。
	private:
		char* binPath;
		void* CIP2LOCPtr;
		char* resultStr;
		
	public:
		virtual bool init(String^ filePath);
		virtual String^ Query(String^ ipStr);
		IP2LOCCLR();
		~IP2LOCCLR();
	};
}
