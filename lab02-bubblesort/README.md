[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/V7DPPCcu)
# lab02-bubbleSort

Your program needs to do 3 tasks. Upon successful completion of all 3 tasks, return with exit code 0.

1. Input processing: given a file name as a command-line argument, read the numbers to create an int array with the numbers in the file. 
2. Bubble Sort: given an int array, sort the numbers using bubble sort algorithm.
3. Print: print a given int array.
  
## Error handling
1. If the file opening fails for any reason (e.g. file doesn't exist), then print `invalid file name` and return with exit code 0.
2. The first number in the file is the size of the array. If the size is less than or equal to 0, then print `invalid file format` and return with exit code 0.
3. If the file contains anything but a number, then print `invalid input format` and return with exit code 0.

## Example runs

### Test 01
when test01.txt contains 
5
1 5 2 4 3
```sh
$make
$./lab02 test01.txt
1 2 3 4 5
```
### Test 02
when test02.txt contains
5
1 5 2
```
$make
$./lab02 test02.txt
invalid file format
```

