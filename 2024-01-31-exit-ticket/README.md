# linearSearch-2024-01-31

The goal is to finish coding this in 20 minutes. 
If you cannot do it in C yet, do it in Java. Use one of the three templates below.
You may use any notion pages from the class as a reference. 

If you finished the linear search on 01/29/2024, then use this template:

```C

#include <stdio.h>

// returns i if nums[i]==target, -1 if target is not found
int linearSearch(int nums[], int length, int target) {
    //your code here
}

int main(int argc, char* argv[]) {

    //your code here

    // create the nums array based on the numbers in the file named argv[1]
    // the first number in the file is the size of the array (= the number of numbers to be in the array))

    //get a target number from user

    // calculate the length of nums

    if (linearSearch(nums, length, target) < 0) {
        printf("Not Found\n");
    } else {
        printf("Found\n");
    }
}
```
If you did not finish linear search on 01/29/2024, use this template
```C
#include <stdio.h>

// returns i if nums[i]==target, -1 if target is not found
int linearSearch(int nums[], int length, int target) {
    //your code here
}

int main(int argc, char* argv[]) {
    int nums[] = {5, 2, 0, 9, 4};
    //your code here

    //get a target number from user

    // calculate the length of nums

    if (linearSearch(nums, length, target) < 0) {
        printf("Not Found\n");
    } else {
        printf("Found\n");
    }
}
```
If you are not familiar with C yet, use this template: 


```Java
public class LinearSearch {
    /*
     *@returns: i if nums[i]==target, -1 if target is not found
     */
    public static int linearSearch(int[] nums, int target) {
        //your code here
    }

    public static void main(String[] argv) {
        int[] nums = {5, 2, 0, 9, 4};

        //your code here

        //get a target number from user

        if (linearSearch(nums, target) < 0) {
            System.out.println("Not Found");
        } else {
            System.out.println("Found");
        }
    }
}
```
