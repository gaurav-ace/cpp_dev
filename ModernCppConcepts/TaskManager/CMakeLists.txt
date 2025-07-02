# This file works as config file for the project. 
# It contains details like which compiler to use, which cpp version to use.

cmake_minimum_required(VERSION 3.10) # mention "VERSION" all caps

project(TaskManager CXX) # this line gives error if compiler is not found, so make sure compiler is present

set(SRCS 
     src/main.cpp
)

add_executable(taskManager ${SRCS}) # make sure to curly braces for syntax