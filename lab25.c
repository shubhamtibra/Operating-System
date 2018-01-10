#include <stdio.h>

int main(){
	int q;
	q = fork();
	if (q == 0){
		int r = fork();
		if (r == 0) printf("E, %d, %d,\n", getpid(), getppid());
		else printf("B, %d, %d,\n", getpid(), getppid());
	}
	else{
		int p = fork();
		if ( p == 0) {
			printf("C, %d, %d,\n", getpid(), getppid());		
		}
		else{
			int s = fork();
			if (s == 0) printf("D, %d, %d,\n", getpid(), getppid());
			else printf("A, %d, %d,\n", getpid(), getppid());				
		}
	}
	sleep(1);
	return 0;
}
