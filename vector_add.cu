#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <cuda.h>

#include "vector_add.h"

__global__ void vector_add(int *a, int *b, int *c, int n)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if( i < n )
    {
        c[i] = a[i] + b[i];
        //printf("%d\n", c[i]);
    }
}


void add_vectors(int *a, int *b, int *c, int n)
{
    int *d_a, *d_b, *d_c;
    cudaMalloc(&d_a, n * sizeof(int));
    cudaMalloc(&d_b, n * sizeof(int));
    cudaMalloc(&d_c, n * sizeof(int));

    cudaMemcpy(d_a, a, n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_c, c, n * sizeof(int), cudaMemcpyHostToDevice);

    const int threadPerBlock = 256;
    const int blockPerGrid = (n + threadPerBlock - 1) / threadPerBlock;

    vector_add<<<blockPerGrid, threadPerBlock>>>(d_a, d_b, d_c, n);

    cudaMemcpy(c, d_c, n * sizeof(int), cudaMemcpyDeviceToHost);

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
}
