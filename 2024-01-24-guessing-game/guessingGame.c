#include <stdlib.h>
#include <time.h>
#include <stdio.h>
int main(int argc, char*argv[]){
	srand(time(0));
	int i = (rand() % 11) + 1;
	int guess;
	printf("Make a guess between the numbers 1 and 10: \n");
	scanf("%d\n", &guess);
	while (1 < i < 11){
		if (*guess > i){
			printf("too high");
			break;
		}else if(*guess < i){
			printf("too low");
			break;
		}else{
			printf("Good guess!");
			break;
		}
	}
}
