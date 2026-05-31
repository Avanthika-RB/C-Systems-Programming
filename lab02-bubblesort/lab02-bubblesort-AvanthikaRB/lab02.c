#include <stdio.h>
#include <string.h>
#include <ctype.h>
void bubbleSort(int* nums, int length){
	for(int i = 0; i<length;i++){
		for(int j=0; j<length-i-1;j++){
			if(nums[j]>nums[j+1]){
				int temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1]= temp;
			}
		}
	}
}


int main(int argc, char* argv[]){
	FILE *file;
	file = fopen(argv[1], "r");

	if(file == NULL){
		printf("file opening error");
		return 0;
	}
	int length = 1;
	if(fscanf(file, "%d", &length) !=1){
		printf("invalid input format");
	}
	int nums[length];
	memset(nums,0,length);
	if(length < 1){
		printf("%s","invalid file format\n");
	}

	for(int i = 0; i<length; i++){
		if (fscanf(file, "%d", &nums[i]) != 1){
			printf("%s","invalid input format\n");
			return 0;
		}
		if(feof(file)){
			printf("\nEnd of file");
			return 0;
		}
	}
	bubbleSort(nums,length);
	for(int i = 0; i<length; i++){
		printf("%d ", nums[i]);
	
	}
			
	fclose(file);
	return 0;
}



