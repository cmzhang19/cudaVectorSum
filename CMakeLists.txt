cmake_minimum_required(VERSION 2.8)

project(VectorSum)

find_package(CUDA REQUIRED)

set(CUDA_FILES
    vector_add.cu)

set(CPP_FILES
    main.cpp
    vector_add.h)

set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};-O3)
CUDA_ADD_EXECUTABLE(VectorSum ${CUDA_FILES} ${CPP_FILES})


