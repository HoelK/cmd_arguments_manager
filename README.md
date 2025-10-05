
# INTRODUCTION

This module was made to manage command lines arguments of a program trying to make them has easier to implement and modify has possible by implementing a structure and a way to check args.

## STRUCTURE

It defines an array of args_data contains the following basic data about each arg :
  - String representing it
  - Bool if its active
  - Bool if it has params
  - Int of its position in argv

## COMMANDS

  - init_args() create an array of struct args_data of size NUM_ARGS
  - check_args() finds any matching between argv and the args
  - check_arg_params() rectrict an input in argv for specific arg usage

## IMPLEMENTATION

  - Add 1 to the NUM_ARGS define
  - Add an ENUM corresponding to the arguement
  - Add a new string representing the arguement in init_args()
  - Add a new bool if there are params in init_args()
  - Add the parameter check in check_arg_param if you need one
The implementation of the actual use of the arguements are left to the programmer

## KNOWN ISSUES

  - ENUM makes the array of struct impossible to sort
