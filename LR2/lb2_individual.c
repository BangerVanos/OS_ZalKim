#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	printf("Process [1] was created by user, its pid is: %d, its ppid is: %d\n", getpid(), getppid());	
	if((pid = fork()) == 0){
		printf("Process[2] has id: %d, parent has id: %d\n", getpid(), getppid());				
		if((pid = fork()) == 0){
			printf("Process[5] has id: %d, parent has id: %d\n", getpid(), getppid());						
			if((pid = fork()) == 0){
				printf("Process[6] has id: %d, parent has id: %d\n", getpid(), getppid());
				printf("Process[6] with id: %d, parent has id: %d finishes its work\n", getpid(), getppid());				
				exit(0);
			}
			wait(0);
			printf("Process[5] with id: %d, parent has id: %d finishes its work\n", getpid(), getppid());			
			exit(0);
		}
		wait(0);
		printf("Process[2] with id: %d, parent has id: %d finishes its work\n", getpid(), getppid());		
		exit(0);
	}
	wait(0);
	if((pid = fork()) == 0){
		printf("Process[3] has id: %d, parent has id: %d\n", getpid(), getppid());				
		if((pid = fork()) == 0){
			printf("Process[7] has id: %d, parent has id: %d\n", getpid(), getppid());
			printf("Process[7] with id: %d, parent has id: %d finishes its work\n", getpid(), getppid());			
			exit(0);
		}
		wait(0);
		printf("Process[3] with id: %d, parent has id: %d finishes its work\n", getpid(), getppid());		
		exit(0);
	}
	wait(0);
	if((pid = fork()) == 0){
		printf("Process[4] has id: %d, parent has id: %d, it calls exec()\n", getpid(), getppid());
		execl("/bin/whoami", "whoami", NULL);
		printf("Process[4] with id: %d, parent has id: %d finishes its work\n", getpid(), getppid());		
		exit(0);
	}
	wait(0);
	printf("Process[1] with id: %d, parent has id: %d finishes its work\n", getpid(), getppid());	
	exit(0);
	return 0;
}