[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/H-6eeJj8)
# lab05 - base conversion
Due date: Wednesday, March 27th 11:59pm 

Convert a given number to a specified base in the command line. 

## Format 
1. Convert a number provided in the command line. 
Binary numbers start with `0b` and hexadecimal numbers start with `0x`. Decimal numbers start with a non-zero number. 
2. Convert to a base provided in the option flag. `-d` stands for decimal, `-h` stands for hexadecimal, and `-b` stands for binary. 

## Requirements
Submit your own Makefile and C code which builds one executable called lab05 (case sentitive). Use the autograder script to test your results.

## Example runs
```sh
./lab05 -d 0b1101
13
```

```sh
./lab05 -h 0b1101
0xD
```

```sh
./lab05 -d 0x1234
4660
```

```sh
./lab05 -d 1234
1234
```

```sh
./lab05 -b 1234
0b10011010010
```

```sh
./lab05 -b 0x1234
0b0001001000110100
```

```sh
./lab05 -h 1234
0x4D2
```

```sh
./lab05 -d 0x3272024
52895780
```

```sh
./lab05 -b 3272024
0b1100011110110101011000
```

```sh
./lab05 -h 3272024
0x31ED58
```

```sh
./lab05 -b 0xA1B2C3D4
0b10100001101100101100001111010100
```

