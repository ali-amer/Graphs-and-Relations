#pragma once
#ifndef GRAPHS
#define GRAPHS

#include <iostream> 
#include <string.h> 
#include <algorithm> 
#include <list> 
#include<fstream>
#include<queue>

using namespace std;
ifstream read;

#define N 10
int V, i, j, infinity = 999;
long long f[1 << N][N], C = 0;

struct Node
{
    Node* link;
    int info;
};
class SinglyList
{
private:
    Node* root;
    Node* last;
    int size;
public:
    void push_back(int info);
    void traverse();
    int begin();
    int end();
    SinglyList();
    ~SinglyList();

};

class BIPARTITE
{
public:

    void READ_DATA();
    void GRAPH_INITIALIZATION();
    void DISPLAY_GRAPH();
    bool TO_CHECH_IF_BIPARTITE(int S);
    void DISPLAY_RESULT();

    int** graph;
    int numberOfVertices;
    BIPARTITE();
};
class KRUSKALS
{
public:
    int** graph;
    int numberOfVertices;
    char mst[4][4];
    KRUSKALS();
    void READ_DATA();
    void GRAPH_INITIALIZATION();
    void DISPLAY_GRAPH();
    int  SET_PLACE(char data[10]);
    void MST();
    void CHECK_CONDITIONS(int arr[], int a, int b, int Z);
    void DISPLAY_MST(int a, int b, int minimum_value);
    int* getVertices(int& numberofVertices, string filename);

    
};
class PRIMS
{
public:
    int** graph;
    int numberOfVertices;
    PRIMS();
    void READ_DATA();
    void INITIALIZE_GRAPH();
    int MINIMUM(int data[], bool ST[]);
    void SPANNING_TREE();
    void SET_VERTICES(int data[], int G[], bool ST[]);
    void DISPLAY_GRAPH();
    void DISPLAY_MST(int G[]);
};
class EULER_PATH
{
    list<int>* A;
public:
    int V;
    int** graph;
    int numberOfVertices;
    EULER_PATH();
    EULER_PATH(int V);
    ~EULER_PATH();
    void INSERT(int x, int y);
    void DISPLAY_EULER_PATH();
    void EULER(int z);
    bool CHECK_NEXT(int a, int b);
    void EDGE(int x, int y);
    int DFS(int v, bool visited[]);
    void GRAPH_INITIALIZATION();
    void READ_DATA();
    void DISPLAY_GRAPH();
};

class CYCLES
{
    int V;
    list<int>* adj;
    bool isCyclicUtil(int v, bool visited[], int parent);

public:
    bool CHECK_CONDITIONS(int v, bool visited[], int parent);
    bool COUNT_CYCLES();
    CYCLES(int V);
    void INSERT(int v, int w);
    bool isCyclic();
    int cycleNumber = 0;
    void READ_DATA();
};


#endif