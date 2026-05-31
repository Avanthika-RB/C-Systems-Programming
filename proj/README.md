[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/bVq4tugO)
# proj04.5 - dynamic HashMap take 2

Due: Wednesday, April 24, 2024 at 11:59 PM to GitHub Classroom Assignment

## Goals

Revise your proj04 code. Here are the rules:

1. The default size of the array is 16, and this is also the lower bound of the array size. In other words, the size of the internal array will always be equal to or greater than 16. 
2. When the load factor is over 0.75, double the size of the internal array. For example, if the size of the array is 16, then the size will double when a 13th item is added to the map. 
3. When the load factor falls below 0.25, cut the size of the internal array into a half. For example, if the size of the array is 32 and there are 9 items in the map, then the array will be cut into a half size at the next delete.

## How to resize

1. When the internal array is doubled, move only necessary nodes from the old index to the new index. There is no need to use addNode or deleteNode. (free'ing an old node and malloc'ing a new node is unnecessary overhead.) For example, when the size changes from 16 to 32, the linked lists at index 0 and 16 change as below.

```
0, [[k10,v10],[k7,v7],[k1,v1]]
16, NULL 
```
```
0, [[k10,v10],[k1,v1]]
16, [[k7,v7]] 
```
```
0, [[k10,v10]]
16,[[k1,v1],[k7,v7]]  
```

2. When the internal array is halved, there is no need to inspect each node. When the size is changing from 32 to 16, every node at index 16 will move to index 0. Thus you can simply append the linked list at index 16 to the linked list at index 0. Similarly, every node at index 17 will move to index 1, so append the linked list at index 17 to the linked list at index 1. Checking the index of the key of each node and doing deleteNode and addNode incurs unncessary overhead. 

```
0, [[k10,v10]]
16,[[k1,v1],[k7,v7]]  
```

```
0, [[k10,v10],[k1,v1],[k7,v7]]
16, NULL  
```

## Example runs
```sh
proj045@e3f50f09b5c3$ ./proj045 0
8
24
24
88
856
3928
85848
872280
6115160

proj045@e3f50f09b5c3$ ./proj045 1
8
8
38
88
928
312
72280
872280
6115160

proj045@e3f50f09b5c3$ ./proj045 2
0, [[k10,v10]]
1, [[k5,v5]]
2, [[k3,v3]]
3, [[k6,v6]]
6, [[k12,v12]]
8, [[k15,v15]]
9, [[k22,v22]]
14, [[k2,v2]]
16, [[k1,v1],[k7,v7]]
19, [[k20,v20],[k14,v14]]
20, [[k18,v18]]
21, [[k16,v16]]
23, [[k21,v21],[k9,v9]]
24, [[k0,v0]]
25, [[k17,v17],[k13,v13]]
26, [[k19,v19]]
27, [[k23,v23],[k8,v8]]
29, [[k4,v4]]
31, [[k11,v11]]
2, [[k3,v3]]
3, [[k6,v6]]
8, [[k15,v15]]
9, [[k22,v22]]
16, [[k1,v1],[k7,v7]]
19, [[k14,v14]]
20, [[k18,v18]]
21, [[k16,v16]]
23, [[k21,v21],[k9,v9]]
24, [[k0,v0]]
32, [[k10,v10]]
33, [[k5,v5]]
38, [[k12,v12]]
45, [[k24,v24]]
46, [[k2,v2]]
51, [[k20,v20]]
57, [[k13,v13],[k17,v17]]
58, [[k19,v19]]
59, [[k8,v8],[k23,v23]]
61, [[k4,v4]]
63, [[k11,v11]]

proj045@e3f50f09b5c3$ ./proj045 3
2, [[k3,v3]]
3, [[k43,v43],[k6,v6]]
7, [[k38,v38]]
8, [[k47,v47],[k15,v15]]
9, [[k40,v40],[k22,v22]]
14, [[k36,v36]]
16, [[k1,v1],[k7,v7]]
18, [[k35,v35]]
19, [[k37,v37],[k14,v14]]
20, [[k18,v18]]
21, [[k16,v16]]
23, [[k21,v21],[k9,v9]]
24, [[k0,v0]]
26, [[k45,v45],[k41,v41],[k29,v29]]
32, [[k10,v10]]
33, [[k5,v5]]
34, [[k44,v44],[k39,v39]]
36, [[k34,v34]]
38, [[k12,v12]]
39, [[k46,v46]]
45, [[k26,v26],[k24,v24]]
46, [[k2,v2]]
49, [[k30,v30]]
50, [[k33,v33]]
51, [[k42,v42],[k25,v25],[k20,v20]]
52, [[k32,v32],[k31,v31],[k28,v28],[k27,v27]]
57, [[k13,v13],[k17,v17]]
58, [[k19,v19]]
59, [[k8,v8],[k23,v23]]
61, [[k4,v4]]
63, [[k11,v11]]
3, [[k43,v43]]
8, [[k47,v47],[k15,v15]]
14, [[k36,v36]]
21, [[k16,v16]]
23, [[k21,v21],[k9,v9]]
34, [[k44,v44]]
45, [[k26,v26]]
49, [[k30,v30]]
50, [[k33,v33]]
51, [[k42,v42],[k25,v25]]
52, [[k32,v32],[k31,v31]]
57, [[k17,v17]]
66, [[k3,v3]]
67, [[k6,v6]]
71, [[k38,v38]]
73, [[k22,v22],[k40,v40]]
80, [[k7,v7],[k1,v1]]
82, [[k48,v48],[k35,v35]]
83, [[k14,v14],[k37,v37]]
84, [[k18,v18]]
88, [[k0,v0]]
90, [[k29,v29],[k41,v41],[k45,v45]]
96, [[k10,v10]]
97, [[k5,v5]]
98, [[k39,v39]]
100, [[k34,v34]]
102, [[k12,v12]]
103, [[k46,v46]]
109, [[k24,v24]]
110, [[k2,v2]]
115, [[k20,v20]]
116, [[k27,v27],[k28,v28]]
121, [[k13,v13]]
122, [[k19,v19]]
123, [[k23,v23],[k8,v8]]
125, [[k4,v4]]
127, [[k11,v11]]

proj045@e3f50f09b5c3$ ./proj045 4
1, [[k5,v5]]
2, [[k3,v3]]
3, [[k6,v6]]
14, [[k2,v2]]
16, [[k1,v1],[k7,v7]]
24, [[k0,v0]]
27, [[k8,v8]]
29, [[k4,v4]]
0, [[k1,v1],[k7,v7]]
1, [[k5,v5]]
2, [[k3,v3]]
3, [[k6,v6]]
8, [[k0,v0]]
13, [[k4,v4]]
14, [[k2,v2]]

proj045@e3f50f09b5c3$ ./proj045 5
2, [[k3,v3]]
3, [[k6,v6]]
8, [[k15,v15]]
16, [[k1,v1],[k7,v7]]
19, [[k14,v14]]
21, [[k16,v16]]
23, [[k9,v9]]
24, [[k0,v0]]
32, [[k10,v10]]
33, [[k5,v5]]
38, [[k12,v12]]
46, [[k2,v2]]
57, [[k13,v13]]
59, [[k8,v8]]
61, [[k4,v4]]
63, [[k11,v11]]
0, [[k10,v10]]
1, [[k5,v5]]
2, [[k3,v3]]
3, [[k6,v6]]
6, [[k12,v12]]
8, [[k15,v15]]
14, [[k2,v2]]
16, [[k1,v1],[k7,v7]]
19, [[k14,v14]]
23, [[k9,v9]]
24, [[k0,v0]]
25, [[k13,v13]]
27, [[k8,v8]]
29, [[k4,v4]]
31, [[k11,v11]]

proj045@e3f50f09b5c3$ ./proj045 6
20
19
0, [[k10,v10]]
1, [[k5,v5]]
2, [[k3,v3]]
3, [[k6,v6]]
6, [[k12,v12]]
8, [[k15,v15]]
14, [[k2,v2]]
16, [[k1,v1]]
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

proj045@e3f50f09b5c3$ ./proj045 7
20
20
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

proj045@e3f50f09b5c3$ ./proj045 8
34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 14 13 13 12 12 11 11 10 10 9 9 8 8 7 7 6 6 5 5 4 4 3 3 2 2 1 1 0 0 

proj045@e3f50f09b5c3$ ./proj045 9
v3 v9 v15 v21 v27 v33 v39 v45 
```
