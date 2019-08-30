#ifndef _TRACE_LOG_H
#define _TRACE_LOG_H

#include <windows.h>

//#include <loglog.h>
#include <log4cplus/logger.h>

//最大的日志描述字符数
#define TRACE_LOG_MAX_DESCRIPTION_SIZE   1024

using namespace log4cplus;

//日志等级
enum eTraceLogLevel
{
    TRACE_LOG_LEVEL_CALL = 100, //调用
    TRACE_LOG_LEVEL_DEBUG = 200, //调试
    TRACE_LOG_LEVEL_INFO = 300, //信息
    TRACE_LOG_LEVEL_WARNING = 400, //警告
    TRACE_LOG_LEVEL_ERROR = 500, //错误
    TRACE_LOG_LEVEL_FATAL = 800, //致命
};

class CTraceLog
{
private:
    CTraceLog();
    std::string GetTraveLogLevelName(eTraceLogLevel level) const;
	//这里必须为常量，不然会出现 不能将“this”指针从“const CTraceLog”转换为“CTraceLog...的错误
	void writeLog(eTraceLogLevel trace_log_level, char* message) const;

    int m_nLevel;
    static CTraceLog *ms_pInstance;

public:
    ~CTraceLog();
    static CTraceLog *GetInstance();
	void TraceL(eTraceLogLevel level, const char* fmt, ...) const;

	Logger loggerRoot;
};

//参数类似于printf()，格式化输出日志，第一个参数为日志等级
#define TRACE_A(LEVEL,F,...) CTraceLog::GetInstance()->TraceL(LEVEL, F, __VA_ARGS__)

#endif