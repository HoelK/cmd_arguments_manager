#ifndef ARGS_H
# define ARGS_H
#include <stddef.h>

# define NUM_ARGS 1

typedef enum args_names {
}args_name;

typedef struct args_data {
	int	pos;
	int	active;
	int	params;
	char	*str;
}args_data;

void	init_args(args_data args[][1]);
int	check_arg(args_data args[][1], char **argv, int argc);
int	check_arg_params(args_data arg, char **argv);

#endif
