[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/eidiSPwD)
# proj01-merge

## Due on Wed. Feburary 14th (Happy Valentine's day!) 

Your proj01 needs to do 3 tasks. 
1. Input processing: read from two text files to create two int arrays. Each text file starts with a number to represent the size of the array, and the rest of the file contains the numbers to go in the array, just like lab02. One notable difference is that this time the numbers are in order in each file.
2. Merge: pass these two arrays to `merge()` function. This function merges two given arrays into a single combined array, and return this combined array.
3. Print: print the content of this array. 

- Each element from the input arrays shall show up in the output array,
- Elements in the output array shall be ordered from smallest to largest, just as they are in each input array,
- You may not sort! Just merge from the front of the input arrays.
    
HINT: think about "pseudocode" first! What are the steps needed to accomplish the merge?
   
## Error handling

- If the file opening fails for any reason (e.g. file doesn't exist), then print invalid file name and return with exit code 0.
- The first number in the file is the size of the array. If the size is less than or equal to 0, then print invalid file format and return with exit code 0.
- If the file does not contain the correct number of numbers, then print invalid file format and return with exit code 0.
- If the file contains anything but a number, then print invalid input format and return with exit code 0.

## Example run

### Test 01
when test01.txt contains 5 1 3 5 7 9 and test02.txt contains 5 2 4 6 8 10

```bash
$make
$./proj01 test01.txt test02.txt 
1 2 3 4 5 6 7 8 9 10
```
