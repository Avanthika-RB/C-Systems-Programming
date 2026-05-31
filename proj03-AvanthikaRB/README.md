[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/4NTl7pYy)
## proj03 - static hash map

Due: Wed, Apr 3, 2024 at 11:59 PM to Github Classroom Assignment

# Background

In Project 3, you will implement a HashMap data structure without resizing internal array. (You will add resizing in Project 4.)

A map struct has 3 fields: 
- size: size of an internal array (constant for proj03)
- count: how many (key, value) pairs are stored (will need in proj04)
- list: internal array of linked lists

# Requirements

Implement `mapIndex`(0325 exit ticket),`add`, `get`, and `delete` functions in `map.c`. Implement `addNode`, `getNode`, `deleteNode`, and `printList` functions in linkedlist.c using your proj02 code. (Note that `deleteNode` now needs to update `num` variable if a node is succesfully deleted. For all other functions you can copy and paste from proj02, e.g. `add` in proj02 is now `addNode` in proj03.) Do not modify any other files in the repo.

# Example runs

```sh
./proj03 0
Map has 10 (key, value) pairs.
[[k1,v1],[k7,v7]]
[[k5,v5]]
[[k3,v3]]
[[k6,v6]]
[[k9,v9]]
[[k0,v0]]
[[k8,v8]]
[[k4,v4]]
[[k2,v2]]

./proj03 1
k3's value is v3
k7's value is v7

./proj03 2
k21 is not found

./proj03 3
k1's value is v1
k11's value is v11

./proj03 4
k4's value is v4
Map has 20 (key, value) pairs.
Map has 19 (key, value) pairs.
k4 is not found

./proj03 5
[[k10,v10],[k7,v7],[k1,v1]]
[[k5,v5]]
[[k3,v3]]
[[k14,v14],[k6,v6]]
[[k18,v18]]
[[k16,v16]]
[[k12,v12]]
[[k9,v9]]
[[k15,v15],[k0,v0]]
[[k17,v17],[k13,v13]]
[[k19,v19]]
[[k8,v8]]
[[k4,v4]]
[[k2,v2]]
[[k11,v11]]

after deleting k10
[[k7,v7],[k1,v1]]
[[k5,v5]]
[[k3,v3]]
[[k14,v14],[k6,v6]]
[[k18,v18]]
[[k16,v16]]
[[k12,v12]]
[[k9,v9]]
[[k15,v15],[k0,v0]]
[[k17,v17],[k13,v13]]
[[k19,v19]]
[[k8,v8]]
[[k4,v4]]
[[k2,v2]]
[[k11,v11]]

after deleting k11
[[k7,v7],[k1,v1]]
[[k5,v5]]
[[k3,v3]]
[[k14,v14],[k6,v6]]
[[k18,v18]]
[[k16,v16]]
[[k12,v12]]
[[k9,v9]]
[[k15,v15],[k0,v0]]
[[k17,v17],[k13,v13]]
[[k19,v19]]
[[k8,v8]]
[[k4,v4]]
[[k2,v2]]

./proj03 6
k4 is not found
k4's value is v4
```
