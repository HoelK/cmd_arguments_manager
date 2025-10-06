#include "args.h"

int	main(int argc, char **argv)
{
	char	**targets;
	args_data	args[NUM_ARGS];

	targets = init_args_n_targets(&args, argc);
	if (check_cmd(&args, targets, argv, argc))
		printf("success");
	else
		printf("error");
	return (0);
}

