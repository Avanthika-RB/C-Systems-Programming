[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/WoRPvy7V)
## Lab 04 - Find the Town Judge

Due: Wed, Feb 28, 2024 at 11:59 PM to Github Classroom Assignment

# Background
This problem is borrowed from [leetcode](https://leetcode.com/problems/find-the-town-judge/) with a slight modification for you to practice using the pointers and pointer arithmetic. 

In a town, there are `n` people labeled from `0` to `n-1`. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

    The town judge trusts nobody.
    Everybody (except for the town judge) trusts the town judge.
    There is exactly one person that satisfies properties 1 and 2.

You are given an array trust where `trust[i] = [ai, bi]` representing that the person labeled `ai` trusts the person labeled `bi`. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

# Requirements
Write your own Makefile and C code which builds one executable called lab04 (case sentitive). Use the autograder script to test your results.

# Example runs 

Example 1:

Input: 
n = 2, trust = [[0,1]]
Represented in test01.txt
2
0 1
```
./lab04 test01.txt
1
```
Example 2:

Input: n = 3, trust = [[0,2],[1,2]]
Inside test02.txt
3
0 2
1 2
```
./lab04 test02.txt
2
```
Example 3:

Input: n = 3, trust = [[0,2],[1,2],[2,0]]
Inside test03.txt
3
0 2
1 2
2 0
```
./lab04 test03.txt
-1
```
 

# Constraints

    trust[i].length == 2
    All the pairs of trust are unique.
    ai != bi
    0 <= ai, bi < n

# Rubric 

Points earned from autograder test cases. Note that you need to do `git pull` in `tests` folder to download the test cases for lab04.
