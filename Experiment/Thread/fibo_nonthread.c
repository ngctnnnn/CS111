#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long long sum;
long long fibo(int n){
    if (n <= 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2);        
}
int main(int argc, char* argv[]){
    clock_t start, end;
    double cpu_time_used;
    start = clock();     
    int count = atoi(argv[1]);
    for(int i = 1; i <= count; ++i) {
        sum = fibo(i);
      	// printf("fib of %d is %d\n", i, sum);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Complete time: %f seconds\n", cpu_time_used);
}