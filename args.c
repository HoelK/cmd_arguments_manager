#include "args.h"

char	**init_args_n_targets(args_data args[][1], int argc)
{
	int	i;
	char	**targets;

	i = 0;
	targets = malloc(sizeof(char *) * (argc - 1));
	while (i < (argc - 1))
		targets[i++] == NULL;
	while (i < NUM_ARGS)
	{
		args[i]->pos = 0;
		args[i]->active = 0;
		i++;
	}
	args[C]->str = "-c";
	args[C]->params = 1;
	return (targets);
}

//Check argv for arguments and set them in the struct
//Arguement present more than once overwrite precedent itterations
int	check_cmd(args_data args[][1], char **targets, char **argv, int argc)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			error = check_arg(args, targets, argv, i);
		else
			error = check_target(targets, argv[i], argc);
		if (error)
			return (0);
	}
	return (1);
}

int	check_arg(args_data args[][1],char **targets, char **argv, int position)
{
	int	i;

	i = 0;
	while (i < NUM_ARGS && (strcmp(args[i]->str, argv[position]) != 0))
		i++;
	if (i < NUM_ARGS)
	{
		args[i]->active = 1;
		args[i]->pos = position;
		if (args[i]->params)
			return (check_arg_params(*args[i], argv));
		i++;
	}
	return (0);
}

int	check_target(char **targets, char *argument, int argc)
{
	int	i;
	int	file;

	i = 0;
	if (file = open(argument, O_RDONLY) == 0)
		return (1);
	close (file);
	while (targets[i] != NULL && i < (argc - 1))
		i++;
	targets[i] = argument;

	return (0);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == 0)
		return (0);
	while (str[i] != 0)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

//Return 1 in case of error
//Return 0 if success
int	check_arg_params(args_data arg, char **argv)
{
	if (strcmp(arg.str, "-c") == 0)
	{
		if  (is_numeric(argv[arg.pos+1]))
			return (0);
		else
			return (1);
	}
	return (1);
}
