#include <cuda.h>
#include <cuda_runtime.h>

__global__ void vector_add(int *a, int *b, int *c, int n);

void add_vectors(int *a, int *b, int *c, int n);
