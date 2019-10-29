#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
	if(fork() == 0) {
		//child
		for(unsigned long long i = 0; i < 1000; i++)
			printf(1, "%d\n", i);
		exit();
	} else {
		//parent
		int wtime = 0, rtime = 0;
		//int status = wait();
		int status = waitx(&wtime, &rtime);
		printf(1, "Child stats: wait time = %d, running time = %d and exit status = %d\n", wtime, rtime, status);
		exit();
	}
}
