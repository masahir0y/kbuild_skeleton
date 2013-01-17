#include <log.h>

/*
 * This is debug code of log functions.
 */
void debug_of_logging(void)
{
	print_err("This is error message.\n");
	print_warn("This is warning message.\n");
	print_info("This is info message.\n");
	print_dbg("This is debug message.\n");
}
