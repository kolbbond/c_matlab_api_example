cmake_minimum_required(VERSION 3.20)
project(test_matlab_api)

# cmake helpers
include("$ENV{CMAKEHELPERS_DIR}/PrintHelpers.cmake")

# find packages
set(Matlab_ROOT_DIR "$ENV{MATLAB_PATH}")

message(STATUS "find packages")
find_package(Matlab REQUIRED)

PrintVars()

if(Matlab_FOUND)
    message(STATUS "found Matlab!")
endif(Matlab_FOUND)


# build - link to matlab engine
add_executable(${PROJECT_NAME} test_api.cpp)
target_link_libraries(${PROJECT_NAME} 
    Matlab::mex
    Matlab::mx
    Matlab::MatlabEngine
    Matlab::MatlabDataArray
    )



