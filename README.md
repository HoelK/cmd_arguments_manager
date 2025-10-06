
# INTRODUCTION

This module was made to manage command lines arguments of a program trying to make them has easier to implement and modify has possible by implementing a structure and a way to check args.

## STRUCTURE

It defines an array of args_data contains the following basic data about each arg :
  - String representing it
  - Bool if its active
  - Bool if it has params
  - Int of its position in argv

An array of strings containing the targets is also created by init_args_n_targets()

## COMMANDS

  - init_args_n_targets() create an array of struct args_data of size NUM_ARGS, return an array of strings for the targets
  - check_cmd() calls check_args() and check_targets() to fill both structure and find errors
  - check_arg() finds any matching between the current argument and the args
  - check_target() fill the targets array and try it to find any error, by default the function assume the target is a file and try to open it
  - check_arg_params() rectrict an input in argv for specific arg usage

## IMPLEMENTATION

  - Add 1 to the NUM_ARGS define
  - Add an ENUM corresponding to the arguement
  - Add a new string representing the arguement in init_args_n_targets()
  - Add a new bool if there are params in init_args_n_targets()
  - Add the parameter check in check_arg_params() if you need one
The implementation of the actual use of the arguements are left to the programmer

## KNOWN ISSUES

  - ENUM makes the array of struct impossible to sort
