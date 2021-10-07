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

<h4>DA3</h4>

1. Write an OpenMP program to find and sum the Fibonacci series. Use one thread to generate the numbers up to the specified limit N=40 and other threads has to sum and print them. Use omp critical and reduction to protect the code region that might be updated by multiple threads concurrently. Measure the execution time for both versions (omp critical amd reduction) varying the number of threads: 4 and 8. <br>[using critical code](./DA3/critical.c) <br>[using reduction code](./DA1/reduction.c)
