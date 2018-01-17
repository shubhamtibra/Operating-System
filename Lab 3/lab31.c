#include<stdio.h>
#include<sys/sem.h>

int main() {
	int t, k, q, p;
	p = semget(0, 1, IPC_CREAT | 0666);
	q = fork();
	if(q != 0){
		int s = getpid();
		semctl(p, 0, SETVAL, s);
		printf("Hello, I'm the parent process. PID: %d\n", s);
	}
	else{
	sleep(1);
	k = semctl(p, 0, GETVAL, 0);
	printf("Hello, I'm the child process. PID: %d\n", getpid());
	printf("%d\n", k);
	}
	sleep(1);
}

