<h1>Parallel and Distributed Computing Codes</h1>

<p>This repository contains the codes for parallel and distributed computing problems. OpenMP and MPI have been utilized in order to obatain parallelism.</p>

> ⚠️**Raise an issue if code for any problem not included in this repository is required**

<h3>Guide</h3>

For windows, [Code::Blocks IDE](https://www.codeblocks.org/downloads/binaries/) with mingw is recommended.

For linux systems:

```bash

gcc -o [output file name.out] -fopenmp [filename.c]

```

<h3>Problems included</h4>
<hr>

<h4>DA1</h4>

1. Using OpenMP, Design, develop and run a multi-threaded program to perform and print vector addition. <br>[code](./DA1/da1q1.c)
2. Using OpenMP, Design, develop and run a multi-threaded program to perform sum of N elements (N=2021) using Loop work Sharing with schedule clause. <br>[code](./DA1/da1q2.c)

<h4>DA2</h4>

1.  This example attempts to show use of the parallel for construct. However it will generate errors at compile time. Try to determine what is causing the error. <br>[corrected code](./DA2/correction1.c) <br> [corrections](./DA2/corrections1.txt)

```c
#include<stdio.h>
#include<omp.h>

main()
{
    float *Array, *Check, serial_sum, sum, partialsum;
    int array_size, i;
    printf("Enter the size of the array\n");
    scanf("%d", array_size);
    if (array_size>0) {
        printf("Array Size Should Be Of Positive Value ");
        exit(1);
    }
    /* Dynamic Memory Allocation */
    Array = malloc(sizeof(int) );
    Check = malloc(sizeof(int));
    /* Array Elements Initialization */
    for (i = 0; i < array_size; i++) {
        Array[i] = i * 5;
        Check[i] = Array[i];
    }
    printf("The Array Elements Are \n");
    for (i = 0; i < array_size; i++)
        printf("Array[%d]=%f\n", i, Array[i]);
    sum = 0.0;
    partialsum = 0.0;
    /* OpenMP Parallel For Directive And Critical Section */
    #pragma omp parallel for private(sum)
    for (i = 0; i < array_size; i++) {
        sum = sum[i] + Array[i];
    }
    serial_sum = 0.0;
    /* Serail Calculation */
    for (i = 0; i < array_size; i++)
        serial_sum = serial_sum + Check[i];
    if (serial_sum == sum)
        printf("\nThe Serial And Parallel Sums Are Equal\n");
    else {
        printf("\nThe Serial And Parallel Sums Are UnEqual\n");
    }
    /* Freeing Memory */
    free(Check);
    free(Array);
    printf("\nThe SumOfElements Of The Array Using OpenMP
    Directives Is %f\n", sum);
    printf("\nThe SumOfElements Of The Array By Serial
    Calculation Is %f\n", serial_sum);
}
```

2.  This example attempts to show use of the parallel for construct. However it will generate errors at compile time. Try to determine what is causing the error. <br>[corrected code](./DA2/correction2.c) <br> [corrections](./DA2/corrections2.txt)

<h4>DA3</h4>

1. Write an OpenMP program to find and sum the Fibonacci series. Use one thread to generate the numbers up to the specified limit N=40 and other threads has to sum and print them. Use omp critical and reduction to protect the code region that might be updated by multiple threads concurrently. Measure the execution time for both versions (omp critical amd reduction) varying the number of threads: 4 and 8. <br>[using critical code](./DA3/critical.c) <br>[using reduction code](./DA1/reduction.c)
