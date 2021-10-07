#include<time.h>
#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 4
#define N 40

int main()
{
    int a[N], sum, i;
    omp_set_num_threads(NUM_THREADS);
    a[0] = 0;
    a[1] = 1;
    sum = 0;
    double start;
    start = omp_get_wtime();
    printf("\nReduction using %d threads", NUM_THREADS);
    #pragma omp parallel
    {
        #pragma omp single
        { int tid = omp_get_thread_num();
          printf("\nIn parallel region. \nThread %d genrating the series", tid);
          for (i = 2; i < N; i++)
          {
            a[i] = a[i - 2] + a[i - 1];
          }
        }
        #pragma omp barrier
        
        #pragma omp for reduction(+:sum)
        for(i=0; i<N; i++)
        { 
          sum += a[i];
        }
    }
    double end;
    end = omp_get_wtime();
    double time_taken = end - start;
    printf("\nPrinting the fibonacci series:\n");
    for(i = 0; i < N; i++) {
      printf("%d ", a[i]);
    }

    printf("\nCalculating the sum serially");
    int sum2 = 0;
    for(i=0; i<N; i++) {
      sum2 += a[i];
    }

    printf("\nThe sum calculated serially is: %d", sum2);
    printf("\nThe sum calculated parallely is: %d", sum);
    printf("\nThe time taken for execution is: %f\n", time_taken);
    return 0;
}