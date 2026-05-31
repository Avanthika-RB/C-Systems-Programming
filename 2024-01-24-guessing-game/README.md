[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/k4OzpcFq)
# guessingGame

Your program 
1. generates a random number between 1 and 10, both inclusive.
2. asks user to make a guess between 1 and 10.
3. if the user's guess is higher than the generated random number, then print "too high" and go to step 2.
4. if the user's guess is lower than the generated random number, then print "too low" and go to step 2.
5. otherwise print "Good guess!"

## How to generate a random number in C
```c

#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {

    //initialize the random number generator
    srand(time(0));
    //generates a random number
    int i = rand();
}
```
use `man rand` in the terminal for more info

## Learning outcome

- use while loop and conditionals comfortably in C 
