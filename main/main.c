#include <stdio.h>

void debug_of_logging(void);

int main(void)
{
#ifdef CONFIG_FOO
	printf("CONFIG_FOO is defined\n");
#else
	printf("CONFIG_FOO is not defined\n");
#endif

#ifdef CONFIG_BAR
	printf("CONFIG_BAR is defined\n");
#else
	printf("CONFIG_BAR is not defined\n");
#endif

	debug_of_logging();

	return 0;
}
