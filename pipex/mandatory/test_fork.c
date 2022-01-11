#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int	main(void)
{
	int	id1;
	int id2;
		printf("\nparent:	getpid: %i\n\n", getpid());
		fflush(stdout);

	id1 = fork();
	if (id1 == 0)
	{
		printf("child:	id1: %i\n", id1);
		printf("child:	getpid: %i\n\n", getpid());
		fflush(stdout);
		exit(EXIT_SUCCESS);
	}
	wait(NULL);
	if (id1 != 0)
	{
		printf("parent:	id1: %i\n", id1);
		printf("parent:	getpid: %i\n\n", getpid());
		fflush(stdout);
		
	}

	if (id1 != 0)
	{
		id2 = fork();
		if (id2 == 0)
		{
			printf("child:	id2: %i\n", id2);
			printf("child:	getpid: %i\n\n", getpid());
			fflush(stdout);
			
		}
		if (id2 != 0)
		{
			printf("parent:	id2: %i\n", id2);
			printf("parent:	getpid: %i\n\n", getpid());
			fflush(stdout);
		}
	}
	return (0);
}