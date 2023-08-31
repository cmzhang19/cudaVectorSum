#include <iostream>
#include "vector_add.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    int deviceCount;
    cudaGetDeviceCount(&deviceCount);
    std::cout << "Number of GPUs: "<< deviceCount << std::endl;

    cudaDeviceProp prop;
    cudaGetDeviceProperties(&prop, 0);
    std::cout << "Name of GPUs: "<< prop.name << std::endl;
    std::cout << "totalGlobalMem of GPUs (bytes): "<< prop.totalGlobalMem << std::endl;
    std::cout << "sharedMemPerBlock of GPUs (bytes): "<< prop.sharedMemPerBlock << std::endl;
    std::cout << "maxBlocksPerMultiProcessor of GPUs: "<< prop.maxBlocksPerMultiProcessor << std::endl;
    std::cout << "maxThreadsPerBlock of GPUs: "<< prop.maxThreadsPerBlock << std::endl;

    int *a, *b, *c;
    int n = 2020;

    a = (int*)malloc(n * sizeof(int));
    b = (int*)malloc(n * sizeof(int));
    c = (int*)malloc(n * sizeof(int));

    for(int i=0; i<n; i++)
    {
        a[i] = i;
        b[i] = n - i;
    }
    add_vectors(a, b, c, n);

    return 0;
}
