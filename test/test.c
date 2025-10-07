#include "args.h"

int	main(int argc, char **argv)
{
	char		**targets;
	args_data	args[NUM_ARGS];

	targets = init_args_n_targets(&args, argc);
	if (check_cmd(&args, targets, argv, argc))
		printf("success\n");
	else
		printf("error\n");

	int	i = 0;
	while (targets[i] != NULL)
		printf("%s\n", targets[i++]);
	free(targets);
	return (0);	
}
