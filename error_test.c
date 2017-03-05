#include <stdio.h>
#include <stdlib.h>
#include "computepi.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define M_PI 3.14159265358979323846

int main(int argc, char const *argv[])
{
    if (argc < 2) return -1;

    int N = atoi(argv[1]);
    double pi;
    // Baseline
    pi=compute_pi_baseline(N);
    printf("%.15lf,",(double)(pi-M_PI)/M_PI*100);
    // OpenMP with 2 threads
    pi=compute_pi_openmp(N, 2);
    printf("%.15lf,",(double)(pi-M_PI)/M_PI*100);
    // OpenMP with 4 threads
    pi=compute_pi_openmp(N, 4);
    printf("%.15lf,",(double)(pi-M_PI)/M_PI*100);
    // AVX SIMD
    pi=compute_pi_avx(N);
    printf("%.15lf,",(double)(pi-M_PI)/M_PI*100);
    // AVX SIMD + Loop unrolling
    pi=compute_pi_avx_unroll(N);
    printf("%.15lf,",(double)(pi-M_PI)/M_PI*100);
    // Machin
    int half_N = N/2;
    pi=compute_pi_machin(half_N, 2);
    printf("%.15lf\n",(double)(pi-M_PI)/M_PI*100);
    return 0;
}
