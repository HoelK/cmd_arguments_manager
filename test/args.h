#ifndef ARGS_H
# define ARGS_H
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

# define NUM_ARGS 1

typedef enum args_names {
	C,
}args_name;

typedef struct args_data {
	int	pos;
	int	active;
	int	params;
	char	*str;
}args_data;

char	**init_args_n_targets(args_data args[][1], int argc);
int	check_cmd(args_data args[][1], char **targets, char **argv, int argc);
int	check_arg(args_data args[][1],char **targets, char **argv, int position);
int	check_target(char **tagets, char *argument, int argc);
int	check_arg_params(args_data arg, char **argv);


#endif
