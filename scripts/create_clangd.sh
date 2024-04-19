#!/bin/bash
# generate clangd config file
# for some reason you can not use environment variables
# or, OR, relative paths

# create the file in main project directory

# get environment variables needed for this project

# echo into file

# make a clangd file with our cwd
printf "${IBlue}create a .clangd to this directory!${NC}\n"
printf "CompileFlags:\n" > .clangd
printf "\tAdd:\n" >> .clangd


# these are the includes
printf "\t- \"-I$(pwd)/include\"\n" >> .clangd
printf "\t- \"-I${MATLAB_PATH}/extern/include\"\n" >> .clangd


