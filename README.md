# Details
- Name : Bharathi Ramana Joshi
- https://github.com/iambrj/xv6-public
- Roll number : 2019121006
# Report
On the following program
```
#include "types.h"
#include "stat.h"
#include "user.h"

#define FORKS 10
#define TIMES 20000

int main(void)
{
	int i;
	volatile int j;
	for(i = 0; i < FORKS; i++)
	{
		if(fork() == 0)
		{
			for(j = 0; j < TIMES; j++)
			{
				printf(10, "%d", j);
			}
			exit();
		}
	}
	for(i = 0; i < FORKS; i++)
	{
		wait();
	}
	exit();
}
```
FCFS takes 17.31 seconds

PBS takes 18.14 seconds

MLFQ takes 18.71 seconds

RR takes 15.61 seconds

# Description
To add a new system call, the following procedure was followed

1. sysProc.c -> add implementation of system call. Create a time like command.
2. sysCall.h -> position of system call. just do the #define.
3. user.h -> function through which the shell should call the system call, Also define the user function time.
4. sysCall.c -> Define the function you declared in sysCall.h i.e waitx.
5. usys.S -> define macro to connect call of user to system call.
6. defs.h -> add declaration of your waitx.
7. proc.h -> add etime,ctime,rtime in proc structure.
8. proc.c -> initialise appropriate time in allocproc and update the times approriately.
9. proc.h -> declare the proc_stat structure. update the runtime in proc.c when state is changed.
Update etime when process exits

# FCFS
To implement this, a new field called `ctime` add to the `proc` struct. During
each loop, `scheduler` goes thorough `ptable` and selects a process in
`RUNNABLE` state with the lowest `ctime.`

# PBS
Similar to FCFS, but pick process with lowest field of `priority`

# MLFQ
Each process has two new fields - `qno` and `qpos`. `qno` tracks the queue
number of the process (0 - 4) and `qpos` tracks the position of this process in
that queue. During each loop, `scheduler` picks the process in `RUNNABLE` state
with the lowest `qno` and then lowest `qpos`.
