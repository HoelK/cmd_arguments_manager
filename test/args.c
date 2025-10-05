#include <string.h>
#include "args.h"

void	init_args(args_data args[][1])
{
	int	i;

	i = 0;
	while (i < NUM_ARGS)
	{
		args[i]->pos = 0;
		args[i]->active = 0;
		i++;
	}
	args[C]->str = "-c";
	args[C]->params = 1;
}

//Check argv for arguments and set them in the struct
//Arguement present more than once overwrite precedent itterations
int	check_arg(args_data args[][1], char **argv, int argc)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	j = 0;
	error = 0;
	while (++i < argc)
	{
		while (i < argc && argv[i][0] != '-')
			i++;
		if (i < argc)
		{
			while (j < NUM_ARGS && (strcmp(args[j]->str, argv[i]) != 0))
				j++;
			if (j < NUM_ARGS) 
			{
				args[j]->active = 1;
				args[j]->pos = i;
				if (args[j]->params)
					error = check_arg_params(*args[j], argv);
			}
			else
				error = 1;
			if (error)
				return (0);
			j = 0;
		}
	}
	return (1);
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
