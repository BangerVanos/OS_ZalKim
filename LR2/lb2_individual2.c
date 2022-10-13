#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>


#define PI 3.141592


unsigned long factorial(unsigned long f){
	if( f <= 0){
		return 1;
	}
	return f*factorial(f-1);
}


int main(int argc, char **argv){	
	int k, n, t_amount;
	k = atoi(argv[1]);
	n = atoi(argv[2]);
	t_amount = atoi(argv[3]);	
	double *y;
	y = (double *)malloc(k * sizeof(double));	
	
	for(int i = 0; i < k; i++){		
		pid_t pid;
		long double t_sin = 0;
		double argument = (2*M_PI*i) / (double)n;
		printf("sin(%f)\n", argument);
		long double *t_args;		
		t_args = (long double *)malloc(t_amount * sizeof(long double));
		for(int j = 0; j < t_amount; j++){
			long double tail_arg;
			if((pid = fork()) == 0){				
				tail_arg = pow((double)-1, (double)j)*((long double)(pow(argument, (double)(2*j+1)))/(long double)(factorial(2*j+1)));
				printf("Process with pid = %d counted Tailor argument = %Lf\n", getpid(), tail_arg);				
				FILE *tail;
				if((tail = fopen("tail.txt", "a")) == NULL){
					if((tail = fopen("tail.txt", "w")) == NULL){}
				}
				fprintf(tail, "%Lf\n", tail_arg);
				fclose(tail);
				exit(0);
			}
			wait(0);
		}
		FILE *tail;
		if((tail = fopen("tail.txt", "r")) == NULL){
		}
		for(int j = 0; j < t_amount; j++){
			fscanf(tail, "%Lf", &(t_args[j]));
			t_sin = t_sin + t_args[j];
		}
		fclose(tail);
		remove("tail.txt");
		free(t_args);
		printf("%Lf\n", t_sin);
		y[i] = t_sin;
		FILE *file;
		if((file = fopen("sin.txt", "a")) == NULL){
			if((file = fopen("sin.txt", "w")) == NULL){
				printf("Cant'open the file!");
				return 0;
			}			
		}
		fprintf(file, "sin(%f) = %Lf\n", argument, t_sin);
		fclose(file);
	}	
	free(y);
	return 0;
}