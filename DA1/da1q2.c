#include<omp.h>
#include<stdlib.h>
#include<stdio.h>

#define N 2021
#define NUM_THREADS 8
int main() 
{
  int chunk_size=N/NUM_THREADS;
  int a[N];
  int sum=0;
  for(int i=0; i<N; i++)
  {
    a[i] = i+1;
  }
  omp_set_num_threads(NUM_THREADS);
  int i;
  #pragma omp for schedule(dynamic, chunk_size)
    for(i=0; i<N; i++)
    {
      sum+=a[i];
    }
  printf("The sum of elements of array is %d\n", sum);
  return 0;
}