#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include <log.h>

#ifdef CONFIG_LOGGING_TIME
#include <sys/time.h>

static void print_logtime(FILE *stream)
{
	struct timeval now;
	static struct timeval first = { 0, 0 };

	gettimeofday(&now, NULL);
	if (!first.tv_sec) {
		first.tv_sec = now.tv_sec;
		first.tv_usec = now.tv_usec;
	}
	if (now.tv_usec < first.tv_usec) {
		now.tv_sec--;
		now.tv_usec += 1000000;
	}
	now.tv_sec -= first.tv_sec;
	now.tv_usec -= first.tv_usec;

	fprintf(stream, " %d.%06d",
		(int)now.tv_sec, (int)now.tv_usec);
}
#else
#define print_logtime(stream) do { (void)(stream); } while(0)
#endif

static void print_log_v(int level, const char *function, const char *format,
		va_list args)
{
	FILE *stream = stdout;
	const char *prefix;
	static int initialized = 0;
	static int dbg = CONFIG_DEFAULT_LOGLEVEL;

	if (!initialized) {
		char *dbg_env = getenv("MYAPP_LOGLEVEL");
		
		if (dbg_env)
			dbg = atoi(dbg_env);

		initialized = 1;
	}

	if (dbg <= level)
		return;

	switch (level) {
	case LOG_LEVEL_INFO:
		prefix = "info";
		break;
	case LOG_LEVEL_WARNING:
		stream = stderr;
		prefix = "warning";
		break;
	case LOG_LEVEL_ERROR:
		stream = stderr;
		prefix = "error";
		break;
	case LOG_LEVEL_DEBUG:
		stream = stderr;
		prefix = "debug";
		break;
	default:
		stream = stderr;
		prefix = "unknown";
		break;
	}

	fprintf(stream, "myapp:");
	print_logtime(stream);
	fprintf(stream, " %s [%s] ", prefix, function);

	vfprintf(stream, format, args);
}

void print_log(int level, const char *function, const char *format, ...)
{
	va_list args;

	va_start (args, format);
	print_log_v(level, function, format, args);
	va_end (args);
}
