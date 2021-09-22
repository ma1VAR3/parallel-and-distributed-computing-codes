#include<omp.h>
#include<stdlib.h>
#include<stdio.h>

#define N 8
#define NUM_THREADS 4

int main(int argc, char *argv[]) 
{;
  int i;
  int chunk_size = N/NUM_THREADS;

  int *a = (int *)malloc(sizeof(int) * N);
  int *b = (int *)malloc(sizeof(int) * N);
  int *c = (int *)malloc(sizeof(int) * N);

  for(i=0; i<N; i++)
  {
    a[i]=i;
    b[i]=i;
  }

  omp_set_num_threads(NUM_THREADS);

  #pragma omp parallel for shared(a,b,c) private(i) schedule(static, chunk_size)
  for(i=0; i<N; i++)
  {
    c[i] = a[i] + b[i];
    printf("Thread %d operating on element %d\n", omp_get_thread_num(), i);
  }

  printf("Printing results: \n");
  for(i=0; i<N; i++)
  {
    printf("%d + %d = %d\n",a[i],b[i],c[i]);
  }
  
  return 0;
}