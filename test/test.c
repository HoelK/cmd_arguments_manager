#include "args.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	args_data	args[NUM_ARGS];
	int	params[NUM_ARGS] = {1};
	char	strs[NUM_ARGS][3] = {"-c"};

	init_args(&args, strs, params);
	if (check_arg(&args, argv, argc))
		printf("success");
	else
		printf("error");
	return (0);
}

