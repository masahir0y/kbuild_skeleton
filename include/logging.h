#ifndef MYAPPLOG_H
#define MYAPPLOG_H

#define LOG_LEVEL_ERROR    0
#define LOG_LEVEL_WARNING  1
#define LOG_LEVEL_INFO     2
#define LOG_LEVEL_DEBUG    3


void myapp_log(int level, const char *function, const char *format, ...);

#ifdef CONFIG_ENABLE_LOGGING
#define _myapp_log(level, ...) myapp_log(level, __FUNCTION__, __VA_ARGS__)
#else
#define _myapp_log(level, ...) do {} while(0)
#endif



#define myapp_dbg(...) _myapp_log(LOG_LEVEL_DEBUG, __VA_ARGS__)
#define myapp_info(...) _myapp_log(LOG_LEVEL_INFO, __VA_ARGS__)
#define myapp_warn(...) _myapp_log(LOG_LEVEL_WARNING, __VA_ARGS__)
#define myapp_err(...) _myapp_log(LOG_LEVEL_ERROR, __VA_ARGS__)



#endif
