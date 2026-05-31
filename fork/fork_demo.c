#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 
 * sums all the numbers in the given file and returns the sum. assumes that
 * the numbers are all positive
 * @param filename is the name of the file
 * @return the sum if it was able to open the given file, -1 otherwise. 
 */
int fileSum(char* filename) {
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("file %s open failed\n", filename);
        return -1;
    }

    int sum = 0;
    int num = 0;

    while (fscanf(fp, "%d", &num) == 1) {
        sum += num;
    }
    return sum;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: ./forkdemo [filename1] [filename2]\n");
        exit(-1);
    }
	for(int i = 1; i < argc; i++){
    pid_t pid = fork();
    	if (pid==-1) {
        	printf("fork failed\n");
        	//exit(0);
    	} else if (pid==0) {
    		if(i % 2){
        	printf("I'm the child process. My parent's pid is %d\n", getppid());
        	printf("The sum of numbers in %s is %d\n", argv[1], fileSum(argv[1]));
    	} else {
    		if(i % 3){
        		printf("I'm the parent process with id %d. My child's pid is %d\n", getpid(), pid);
        		printf("The sum of numbers in %s is %d\n", argv[2], fileSum(argv[2]));
        		//parent process pass argv to child process
        		
        	}
        }
    }
}
}
