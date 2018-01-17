#include <stdio.h>

int main(){
	int q;
	fork();
	q = fork();
	if (q==0) fork();
	if (q==0) fork();
	printf("%d, %d,\n", getpid(), getppid());
	sleep(1);
	return 0;
}
