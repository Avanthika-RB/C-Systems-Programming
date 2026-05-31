[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/CvT2ki_V)
# proj5 - Bit manipulation & Stack Overflow

Due: Wednesday, May 8, 2024 at 11:59 PM to GitHub Classroom Assignment

## Goals


### Bit manipulation
1. You can set and check any bit in a variable.

### Stack overflow
1. Understand how stack overflow works 
2. Write a secure code without stack overflow vulnerability


## Requirements

### Bit manipulation (50%)
1. Complete mymod.c in the template
2. Test with autograder (Example runs below)

### Stack overflow (50%)
1. buf_of.c in the template is vulnerable to stack overflow, as shown during the class. 
2. Answer the following questions in thie README and push your README in the repo. 

- What is the minimum length of the keyboard input that displays the secret word without knowing the correct password?
	The minimum length is 18. In correct_password there is 7 characters including null character.
	Then theres a password array with size 10 characters and bool logged_in is 1 character.
	Adding this up, there is 7+10+1 = 18 characters. When inputting a number thats 18 or higher, it 
	overflows because of the max number of characters the password can rewrite into.

- If SIZE becomes 12, does it change your answer above?
	Yes, it changes the answer. If SIZE is 12 then the minimum length is 20. 7+12+1= 20. So it will overflow because
	the max number of characters the password can rewrite into is now 20.
	
- Why is the minimum length the number you gave above? Include a screenshot from GDB to explain. 
	In gdb, I input 123456789012345678 as the password which is 18 characters which will overflow if SIZE is 10.
	It rewrites the first 10 characters into password because its of size 10. And it rewrites the next 7 characters into the correct password.
	Then it prints "The secret word is USF" because logged_in is true.

<img width="638" alt="proj05gdb" src="https://github.com/cs221-s24/proj05-AvanthikaRB/assets/129799368/fd05bbb6-9862-4cac-bb01-ab819fda1a92">







## Example runs

```
WORK:proj05 ejung$ ./proj05 0
32768
32800
WORK:proj05 ejung$ ./proj05 1
1000000000000000
1000000000000001
1000010000000001
WORK:proj05 ejung$ ./proj05 2
1000000000000000
1000000000000001
0000000000000001
WORK:proj05 ejung$ ./proj05 3
file3 has permission 0 set
file3 doesn't have permission 3 set
WORK:proj05 ejung$ ./proj05 4
1000000000000000
1010000000000000
1010100000000000
1010101000000000
1010101010000000
1010101010100000
1010101010101000
1010101010101010
1010101010101010
1010101010100010
1010101010100010
1010100010100010
1010100010100010
```
