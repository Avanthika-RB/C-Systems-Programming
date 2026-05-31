#include <stdio.h>
#include <string.h>
//header comment
//The occurrence method iterates through every character in the word and counts the number of reoccurring characters.


int occurrence(char *theword, char *thetarget){
	int count = 0;
	int wordlength = strlen(theword);
	int targetlength = strlen(thetarget); 
	for(int i=0; i <= wordlength - targetlength; i++){
		int same = 1;		//if target is the same at i
		for(int j=0; j<targetlength; j++){
			if(theword[i + j] != thetarget[j]){
				same = 0;
				break;
			}
		}
		if (same){
			count++;
		}
	}
	return count;
}

int main(int argc, char* argv[]){
	if (argc != 3){
		printf("invalid arguments");
		return 0;
	}
	char *word = argv[1];
	char *target = argv[2];
	int co = occurrence(word,target);

	printf("%d\n", co);
	return 0;
	
}
