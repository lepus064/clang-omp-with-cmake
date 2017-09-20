#include <stdint.h>
#include <cstdio>
#include <omp.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int nthreads, tid;
    omp_set_num_threads(8);
#pragma omp parallel private(nthreads, tid)
    {
        tid = omp_get_thread_num();
        printf("Hello World from OMP thread %d\n", tid);
        if (tid == 0) {
            nthreads = omp_get_num_threads();
            printf("Number of threads is %d\n", nthreads);
        }
    }
    return 0;
}
