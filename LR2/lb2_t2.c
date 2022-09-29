#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]){
	pid_t pid;
	printf("Process has id: %d, parent has id: %d\n", getpid(), getppid());
	for(int i = 0; i < 2; i++){
		if((pid = fork()) == 0){
			printf("Process has id: %d, parent has id: %d\n", getpid(), getppid());	
			time_t now = time(NULL);
			struct tm *time = localtime(&now);
			printf("%02d:%02d:%02d\n", time->tm_hour, time->tm_min, time->tm_sec);
			sleep(1);
			exit(0);
		}
		wait(0);
	}
	wait(0);
	system("ps -x");
	exit(0);
	return 0;
}