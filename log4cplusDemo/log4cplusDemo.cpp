// log4cplusDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "TraceLog.h"
#include <direct.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//创建日志存储目录
	_mkdir("log");
	TRACE_A(TRACE_LOG_LEVEL_WARNING,"输出日志");
	getchar();
	return 0;
}

