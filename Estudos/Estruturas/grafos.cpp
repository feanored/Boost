#include <iostream>
#include <limits>
#include "libs.h"
using namespace std;

const auto infty = numeric_limits<double>::infinity();

// Breadth First Search  (busca em largura)

BFS(u,v):
    q = an empty queue
    add (0,u) to q // (0,u) -> (length from u, current vertex)
    while q is not empty:
        (length,curr) = q.dequeue()
        mark curr as visited
        if curr == v: // if we have reached the vertex we are searching for
            return length
        for all outgoing edges (curr,w) from curr: // otherwise explore all neighbors
            if w has not yet been visited:
                add (length+1,w) to q
    return "FAIL" // if I reach this point, then no path exists from u to v


// Depth First Search (busca em profundidade)

DFS(u,v):
    s = an empty stack
    push (0,u) to s // (0,u) -> (length from u, current vertex)
    while s is not empty:
        (length,curr) = s.pop()
        mark curr as visited
        if curr == v: // if we have reached the vertex we are searching for
            return length
        for all outgoing edges (curr,w) from curr: // otherwise explore all neighbors
            if w has not yet been visited:
                add (length+1,w) to s
    return "FAIL" // if I reach this point, then no path exists from u to v

/*
DFSRecursion(s): // s is the starting vertex
    mark s as explored 
    for each unexplored neighbor v of s:
        DFSRecursion(v)
*/

// Dijkstra

dijkstra(s):
    // perform initialization step
    pq = empty priority queue
    for each vertex v:
        v.dist = infty;           // the maximum possible distance from s
        v.prev = nullptr;               // we don't know the optimal previous node yet
        v.done = false;              // v has not yet been discovered

    // perform the traversal
    enqueue (0, s) onto pq          // enqueue the starting vertex
    while pq is not empty:
        dequeue (weight, v) from pq
        if v.done == False:         // if the vertex's min path hasn't been discovered yet
            v.done = True
            for each edge (v,w,d):  // (v,w,d) = edge from v to w with edge-weight d
                c = v.dist + d      // c is the total distance to w through v
                if c < w.dist:      // if a smaller-weight path has been found
                    w.prev = v      // update the node just before w in the path from s to w
                    w.dist = c      // update the distance of the path from s to w
                    enqueue (c, w) onto pq