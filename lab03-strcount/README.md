[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/CYTJmmj5)
# lab03-strcount

Due: Wed, Feb 21, 2024 at 11:59 PM to Github Classroom Assignment

## Requirements

Write your own Makefile and C code which builds one executable called lab03 (case sentitive) for the parts described below.
Use the grade script to test your results.

## Given

You must clone [Prof. Peterson's autograder repo](https://github.com/phpeterson-usf/autograder) and [the test cases repo for this class](https://github.com/cs221-s24/tests/) into your home directory on clab

## Part 1

Count the occurrences of a single character in a string. Example output:

```sh
$ ./lab03 foobar o
2

$ ./lab03 foobar
invalid arguments
```
## Part 2

Count the occurrences of an N-character string in another string. Example output:
```sh
$ ./lab03 abbabb bb
2

$ ./lab03 abbabb bc
0
```
You may use the C library function `strstr()` if you wish. `char *strstr(char *a, char *b)` returns a pointer to the first occurrence of `b` if `b` occurs in `a`, or `NULL` if `b` does not occur in `a`

## Rubric

Points earned from autograder test cases

