#include <stdio.h>

// returns i if nums[i]==target, -1 if target is not found
int linearSearch(int nums[], int length, int target){
    int i;
    for(i = 0; i < length; i++){
        if (nums[i]== target){
            return i;
        }
    } 
    return -1;
    
}

int main(int argc, char* argv[]) {
    int target;
    int nums[] = {5, 2, 0, 9, 4};
    // create the nums array based on the numbers in the file named argv[1]
    // the first number in the file is the size of the array (= the number of numbers to be in the array))
    FILE* fs = fopen("argv[1]", "r");
    int nums[];
    for (int i=0;i<argc;i++){
        while (fscanf(fs, "%d", &nums) == 1){
            strncpy(nums);
        }
    }
    //get a target number from user
    printf("Which number from 5,2,0,9,4 do you choose to be the target?: \n");
    scanf("%d", &target);
    // calculate the length of nums
    int length = sizeof(nums)/sizeof(nums[0]);
    if (linearSearch(nums,length,target) < 0){
        printf("Not Found\n");
    }else{
        printf("Found\n");
    }   

}

