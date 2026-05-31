[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/0Au5nNFf)
# proj04 - dynamic HashMap

Due: Wednesday, April 17, 2024 at 11:59 PM to GitHub Classroom Assignment

## Goals

Extending your proj03 code, now the internal array of linked list will grow or shrink as necessary. Here are the rules:

1. The default size of the array is 16, and this is also the lower bound of the array size. In other words, the size of the internal array will always be equal to or greater than 16. 
2. When the load factor is over 0.75, double the size of the internal array. For example, if the size of the array is 16, then the size will double when a 13th item is added to the map. 
3. When the load factor falls below 0.25, cut the size of the internal array into a half. For example, if the size of the array is 32 and there are 9 items in the map, then the array will be cut into a half size at the next delete.

## Example runs
```sh
proj04@f8a12169851c$ ./proj04 0
Map has 13 items in size 32.
Map has 20 items in size 32.
0, [[k10,v10]]
1, [[k5,v5]]
2, [[k3,v3]]
3, [[k6,v6]]
6, [[k12,v12]]
8, [[k15,v15]]
14, [[k2,v2]]
16, [[k1,v1],[k7,v7]]
19, [[k14,v14]]
20, [[k18,v18]]
21, [[k16,v16]]
23, [[k9,v9]]
24, [[k0,v0]]
25, [[k17,v17],[k13,v13]]
26, [[k19,v19]]
27, [[k8,v8]]
29, [[k4,v4]]
31, [[k11,v11]]

Map has 8 items in size 16.
Map has 4 items in size 16.
4, [[k18,v18]]
5, [[k16,v16]]
9, [[k17,v17]]
10, [[k19,v19]]

proj04@f8a12169851c$ ./proj04 1
k33's value is v33
k97's value is v97

proj04@f8a12169851c$ ./proj04 2
k21 is not found

proj04@f8a12169851c$ ./proj04 3
0, [[k10,v10]]
1, [[k5,v5]]
2, [[k3,v3]]
3, [[k6,v6]]
6, [[k12,v12]]
8, [[k15,v15]]
14, [[k2,v2]]
16, [[k1,v1],[k7,v7]]
19, [[k14,v14]]
20, [[k18,v18]]
21, [[k16,v16]]
23, [[k9,v9]]
24, [[k0,v0]]
25, [[k17,v17],[k13,v13]]
26, [[k19,v19]]
27, [[k8,v8]]
29, [[k4,v4]]
31, [[k11,v11]]
k10's value is v10
k13's value is v13

proj04@f8a12169851c$ ./proj04 4
k124's value is v124
Map has 256 items.
Map has 255 items.
k124 is not found

proj04@f8a12169851c$ ./proj04 5
0, [[k10,v10]]
1, [[k5,v5]]
2, [[k3,v3]]
3, [[k6,v6]]
6, [[k12,v12]]
8, [[k15,v15]]
14, [[k2,v2]]
16, [[k1,v1],[k7,v7]]
19, [[k14,v14]]
20, [[k18,v18]]
21, [[k16,v16]]
23, [[k9,v9]]
24, [[k0,v0]]
25, [[k17,v17],[k13,v13]]
26, [[k19,v19]]
27, [[k8,v8]]
29, [[k4,v4]]
31, [[k11,v11]]

after deleting k10
1, [[k5,v5]]
2, [[k3,v3]]
3, [[k6,v6]]
6, [[k12,v12]]
8, [[k15,v15]]
14, [[k2,v2]]
16, [[k1,v1],[k7,v7]]
19, [[k14,v14]]
20, [[k18,v18]]
21, [[k16,v16]]
23, [[k9,v9]]
24, [[k0,v0]]
25, [[k17,v17],[k13,v13]]
26, [[k19,v19]]
27, [[k8,v8]]
29, [[k4,v4]]
31, [[k11,v11]]

after deleting k11
1, [[k5,v5]]
2, [[k3,v3]]
3, [[k6,v6]]
6, [[k12,v12]]
8, [[k15,v15]]
14, [[k2,v2]]
16, [[k1,v1],[k7,v7]]
19, [[k14,v14]]
20, [[k18,v18]]
21, [[k16,v16]]
23, [[k9,v9]]
24, [[k0,v0]]
25, [[k17,v17],[k13,v13]]
26, [[k19,v19]]
27, [[k8,v8]]
29, [[k4,v4]]

proj04@f8a12169851c$ ./proj04 6
k4 is not found
k4's value is v4

proj04@f8a12169851c$ ./proj04 7
Map has 13 items in size 32.
Map has 25 items in size 64.
Map has 49 items in size 128.
Map has 97 items in size 256.
Map has 193 items in size 512.
Map has 385 items in size 1024.
Map has 769 items in size 2048.
Map has 1537 items in size 4096.
Map has 3073 items in size 8192.
Map has 6145 items in size 16384.
Map has 12289 items in size 32768.
Map has 24577 items in size 65536.
Map has 49153 items in size 131072.
Map has 98305 items in size 262144.
Map has 196609 items in size 524288.
Map has 393217 items in size 1048576.
Map has 786433 items in size 2097152.
Map has 1048577 items in size 2097152.

proj04@f8a12169851c$ ./proj04 8
Map has 1048577 items in size 2097152.
Map has 524288 items in size 1048576.
Map has 262144 items in size 524288.
Map has 131072 items in size 262144.
Map has 65536 items in size 131072.
Map has 32768 items in size 65536.
Map has 16384 items in size 32768.
Map has 8192 items in size 16384.
Map has 4096 items in size 8192.
Map has 2048 items in size 4096.
Map has 1024 items in size 2048.
Map has 512 items in size 1024.
Map has 256 items in size 512.
Map has 128 items in size 256.
Map has 64 items in size 128.
Map has 32 items in size 64.
Map has 16 items in size 32.
Map has 8 items in size 16.
Map has 4 items in size 16.
0, [[k1048576,v1048576]]
4, [[k1048574,v1048574]]
9, [[k1048573,v1048573]]
10, [[k1048575,v1048575]]
```
