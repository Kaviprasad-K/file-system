# File System Representation and Search Using BFS and DFS

**Activity ID:** SY–S3–B–09 | Data Structures and Algorithms | UKF College of Engineering & Technology

A C program that models a file system as a directed graph (adjacency matrix) and searches for a file using BFS and DFS.

## How it works
- Each file/directory is a node; each parent → child link is an edge.
- Graph stored as `int adj[MAX][MAX]` (1 = edge exists).
- BFS uses a queue (level by level); DFS uses recursion (deep first).
- Both print their traversal order and stop when the target is found.

## Build and run
```
gcc -Wall -o fs filesystem_search.c
./fs < input1.txt
```

## Input format
```
n                    number of nodes
name1 ... namen      node names (no spaces)
m                    number of edges
parent child         (m lines)
start target         start node, file to search
```

## Sample files
| Input | Case | Output |
|---|---|---|
| input1.txt | File found (resume.docx) | output1.txt |
| input2.txt | File not found (video.mp4) | output2.txt |
| input3.txt | File found (util.c) | output3.txt |

## Complexity
Adjacency matrix: BFS and DFS are both O(V²) time, O(V) extra space.
