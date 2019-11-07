#include "types.h"
#include "stat.h"
#include "user.h"

#define FORKS 32
#define TIMES 10000

int main(void)
{
	int i, j;
	for(i = 0; i < FORKS; i++)
	{
		if(fork() == 0)
		{
			for(j = 0; j < TIMES; j++)
			{
				printf(5,"hello\n");
			}
			exit();
		}
	}
	int wait_time,run_time;
	for(i = 0; i < FORKS; i++)
	{
		int pid = waitx(&wait_time,&run_time);
		printf(1, "[WAITX] pid[%d] wait time[%d] run time [%d]\n",pid,wait_time,run_time);
	}
	exit();
}
