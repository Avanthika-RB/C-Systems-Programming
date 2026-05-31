[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/KDeGXr89)
# lab06 - dynamic sizing
Due date: Wednesday, April 10th 11:59pm 

Resize the array to fit the size of the data. 

## Goal
Practice using `realloc`.

## Format 
1. The initial size of the array is 10. Every time that the array needs more space, double the size of the array.  

## Requirements
lab06.c, lab06.h and Makefile are already provided. You need to complete `add` function in dynamiclist.c. Hint: `add` function is equivalent to the exit ticket from Monday, April 1st class. 

## Rubric
The grader will generate 10 random numbers between 5 and INT_MAX, and test if your code handles that many adds correctly. Each test case will be worth 10 points. 

## Example runs
```sh
lab06@f8a12169851c$ ./lab06 100
size: 20, count: 11
size: 40, count: 21
size: 80, count: 41
size: 160, count: 81
size: 160, count: 100

lab06@f8a12169851c$ ./lab06 10000
size: 20, count: 11
size: 40, count: 21
size: 80, count: 41
size: 160, count: 81
size: 320, count: 161
size: 640, count: 321
size: 1280, count: 641
size: 2560, count: 1281
size: 5120, count: 2561
size: 10240, count: 5121
size: 10240, count: 10000

lab06@f8a12169851c$ ./lab06 1000000
size: 20, count: 11
size: 40, count: 21
size: 80, count: 41
size: 160, count: 81
size: 320, count: 161
size: 640, count: 321
size: 1280, count: 641
size: 2560, count: 1281
size: 5120, count: 2561
size: 10240, count: 5121
size: 20480, count: 10241
size: 40960, count: 20481
size: 81920, count: 40961
size: 163840, count: 81921
size: 327680, count: 163841
size: 655360, count: 327681
size: 1310720, count: 655361
size: 1310720, count: 1000000

WORK:lab06-template ejung$ ./lab06 1000000000
size: 20, count: 11
size: 40, count: 21
size: 80, count: 41
size: 160, count: 81
size: 320, count: 161
size: 640, count: 321
size: 1280, count: 641
size: 2560, count: 1281
size: 5120, count: 2561
size: 10240, count: 5121
size: 20480, count: 10241
size: 40960, count: 20481
size: 81920, count: 40961
size: 163840, count: 81921
size: 327680, count: 163841
size: 655360, count: 327681
size: 1310720, count: 655361
size: 2621440, count: 1310721
size: 5242880, count: 2621441
size: 10485760, count: 5242881
size: 20971520, count: 10485761
size: 41943040, count: 20971521
size: 83886080, count: 41943041
size: 167772160, count: 83886081
size: 335544320, count: 167772161
size: 671088640, count: 335544321
size: 1342177280, count: 671088641
size: 1342177280, count: 1000000000
```
