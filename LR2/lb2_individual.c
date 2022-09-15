#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	pid_t pid0, pid1, pid2, pid3, pid4, pid5, pid6;
	printf("Process [0] is parent of all processes, its pid is: %d\n", getpid());
	pid1 = fork();	
	pid2 = fork();	
	pid3 = fork();	
	if(pid1 == 0){
		printf("Process[1] has id: %d, parent has id: %d\n", getpid(), getppid());
		pid4 = fork();		
		if(pid4 == 0){
			printf("Process[4] has id: %d, parent has id: %d\n", getpid(), getppid());
			pid5 = fork();			
			if(pid5 == 0){
				printf("Process[5] has id: %d, parent has id: %d\n", getpid(), getppid());
				exit(EXIT_SUCCESS);
			}
			exit(EXIT_SUCCESS);
		}
		exit(EXIT_SUCCESS);
	}
	if(pid2 == 0){
		printf("Process[2] has id: %d, parent has id: %d\n", getpid(), getppid());
		pid6 = fork();		
		if(pid6 == 0){
			printf("Process[6] has id: %d, parent has id: %d\n", getpid(), getppid());
			exit(EXIT_SUCCESS);
		}
		exit(EXIT_SUCCESS);
	}
	if(pid3 == 0){
		printf("Process[3] has id: %d, parent has id: %d\n", getpid(), getppid());
		execl("/bin/whoami", "whoami", NULL);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_SUCCESS);
	return 0;
}