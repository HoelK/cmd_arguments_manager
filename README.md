
INTRODUCTION
This module was made to manage command lines arguments of a program trying to make them has easier to implement and modify has possible by implementing a structure and a way to check args.

STRUCTURE
It defines an array of args_data contains the following basic data about each arg :
  - String representing it
  - Bool if its active
  - Bool if it has params
  - Int of its position in argv

COMMANDS
  - init_args() create an array of struct args_data of size NUM_ARGS
  - check_args() finds any matching between argv and the args
  - check_args_params() rectrict an input in argv for specific arg usage

IMPLEMENTATION
  - Add 1 to the NUM_ARGS define
  - Add an ENUM corresponding to the arguement
  - Add a new string representing the arguement in your init_args call
  - Add a new bool if there are params in your init_args call
  - Add the parameter check in check_argparam if you need one
The implementation of the actual use of the arguements are left to the programmer

KNOWN ISSUES
  - ENUM makes the array of struct impossible to sort
  - args_str in init_args() has to be in the same order has the ENUM
  - args_str can only be of size 3, one '-', one letter and NULL
  - annoying to create static variables in main function
