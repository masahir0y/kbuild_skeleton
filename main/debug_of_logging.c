#include <logging.h>

/*
 * This is debug code of log functions.
 */
void debug_of_logging(void)
{
	myapp_err("This is error message.\n");
	myapp_warn("This is warning message.\n");
	myapp_info("This is info message.\n");
	myapp_dbg("This is debug message.\n");
}
