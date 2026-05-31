[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/nIO21J5A)
## proj02 - linked list for (key, value) pairs

Due: Wed, Mar 6, 2024 at 11:59 PM to Github Classroom Assignment

# Background

In Project 5, you will implement a HashMap data structure, which uses a linked list to handle collisions. (You will learn more about this in the coming weeks.) In other words, Project 2 will be a building block of Project 5. 

Since this linked list will be used for storing (key, value) pairs, each node has 3 elements: `key`, `value`, and `next`. Both `key` and `value` are strings, i.e. of `char*` type. `next` points to the next node. This is defined in `node.h`. 

# Requirements 

Implement `add`, `get`, `delete` and `printList` functions in `linkedlist.c`. Do not modify any other files in the repo.

# Example runs

```sh
./proj02 0
[[k0,v0],[k1,v1],[k2,v2],[k3,v3],[k4,v4],[k5,v5],[k6,v6],[k7,v7],[k8,v8],[k9,v9]]

./proj02 1
k3's value is v3
k7's value is v7

./proj02 2
k11 is not found

 ./proj02 3
k0's value is v0
k9's value is v9

./proj02 4
k4's value is v4
k4 is not found

./proj02 5
[[k9,v9],[k8,v8],[k7,v7],[k6,v6],[k5,v5],[k4,v4],[k3,v3],[k2,v2],[k1,v1]]
[[k8,v8],[k7,v7],[k6,v6],[k5,v5],[k4,v4],[k3,v3],[k2,v2],[k1,v1]]

./proj02 6
[[k9,v9],[k8,v8],[k7,v7],[k6,v6],[k5,v5],[k3,v3],[k2,v2],[k1,v1],[k0,v0]]
k4's value is v4
```

