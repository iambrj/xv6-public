#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
	if(fork() == 0)
	{
		//child
		for(int i = 0; i < 10; i++)
		{
			printf(5, "1 - %d\n", i);
		}
		exit();
	}
	else
	{
		if(fork() == 0)
		{
			//child
			for(int i = 0; i < 10; i++)
			{
				printf(5, "2 - %d\n", i);
			}
			exit();
		}
		else
		{
			for(int i = 0; i < 10; i++)
			{
				printf(5, "2 - %d\n", i);
			}
			wait();
			wait();
			exit();
		}
	}
}
