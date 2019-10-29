#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
	if(fork() == 0)
	{
		if(fork() == 0)
		{
			for(int i = 0; i < 100; i++)
			{
				printf(10, "%d\n", i);
			}
			exit();
		}
		else
		{
			wait();
			for(int i = 0; i < 100; i++)
			{
				printf(10, "%d\n", i);
			}
			exit();
		}
	}
	else
	{
		wait();
		for(int i = 0; i < 100; i++)
		{
			printf(10, "%d\n", i);
		}
		exit();
	}
}
