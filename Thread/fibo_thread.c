#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

long long sum;			   /* this data is shared by the thread(s) */
void *runner(void *param); /* the thread */

int main(int argc, char *argv[])
{
	clock_t start, end;
	double cpu_time_used;

	int count, i;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	start = clock();
	count = atoi(argv[1]);

	for (i = 1; i <= count; i++)
	{
		pthread_t thread;
		pthread_create(&thread, &attr, runner, (void *)i);
		pthread_join(thread, NULL);
		// printf("fib of %d is %d\n", i, sum);
	}
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Complete time: %f seconds\n", cpu_time_used);
	// 	printf("Fibo of %d: %d\n", count, sum);
}

void *runner(void *param)
{
	sum = fibonacci((int)param);
	pthread_exit(0);
}

int fibonacci(int x)
{
	if (x <= 1)
	{
		return 1;
	}
	return fibonacci(x - 1) + fibonacci(x - 2);
}