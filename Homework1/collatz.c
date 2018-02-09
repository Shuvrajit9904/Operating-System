#define _GNU_SOURCE
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/syscall.h> 
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	/* code */
	if (argc > 2)
	{
		printf("Too many Argument supplied\n");
	}
	else if (argc == 1)
	{
		printf("One Argument Exected\n");
	}
	int num = atoi(argv[1]);

	if (num < 1)
	{
		printf("Invalid Argument. Positive Integer Expected\n");
		return 0;
	}
	pid_t pid = fork();	

	if (pid < 0)
	{
		printf("Error in fork call\n");
		while(pid < 0)
		{
			pid = fork();	
		}		
	}
	else if (pid == 0)
	{
		printf("Inside Child process\n");
		printf("%d\n", num);
		while(num != 1)
		{
			if (num % 2 == 0)
			{
				num = num / 2;
			}
			else if (num % 2 == 1)
			{
				num = (3 * num) + 1;
			}
			printf("%d\n", num);
		}
	}
	else if (pid > 0)
	{
		//printf("Inside Parent Process\n");
		int wt = wait(NULL);
		if (wt == -1)
		{
			printf("Error in wait() call\n");
			return 0;
		}
		else{
			printf("all process completed successfully\n");
		}
	}

	return 0;
}