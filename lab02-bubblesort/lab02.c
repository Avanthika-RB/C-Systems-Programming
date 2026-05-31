#include <stdio.h>
#include <string.h>
void bubbleSort(int* nums, int length) {
    //your code here does bubble sort
    for(int i = 0 + 1; i < length-1; i++){
        for(int j= 0; j < length - i - 1; j++){
            if(nums[j]>nums[i]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    // open the file 
    FILE *file;
    file = fopen("test01.txt", "r");
	if (file == NULL){
		printf("no elements in file");
		return -1
	}else{
		printf("%s", "elements in file\n");
		int length = 1;
		fscanf(file, "%d", &length);
		int nums[length];
		memset(nums,0,length);
		for(int i = 0;i<length;i++){
			fscanf(file, "%d", &nums[i]);
			printf("%d", nums[i]);
			if(feof(file)){
				printf("\nEnd of file");
				return -1;
			}
		}
		bubbleSort(nums, length);
		for(int i=0;i<length;i++){
			printf("%d", nums[i]);
		}
	}
}



 
