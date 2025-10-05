#include "args.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	args_data	args[NUM_ARGS];

	init_args(&args);
	if (check_arg(&args, argv, argc))
		printf("success");
	else
		printf("error");
	return (0);
}

