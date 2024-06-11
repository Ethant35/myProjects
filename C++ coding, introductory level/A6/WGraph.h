#ifndef WGraph_H
#define WGraph_H
#include <cstdlib>
#include <deque>
#include <set>
#include <stack>
#include <iostream>
#include <limits>
#include <float.h>
using namespace std;
//a weighted, undirected WGraph implemented with adjacency matrix
//fixed size
typedef unsigned int VertexID;
class WGraph{
public:
  WGraph();
  WGraph(unsigned int sz);
  ~WGraph();
  void addEdge(VertexID i, VertexID j, double w);
  void removeEdge(VertexID i, VertexID j);
  bool areAdjacent(VertexID i, VertexID j);
  double cheapestCost(VertexID i, VertexID j);
  void calcFW();
  double** fileProcessing(string fileName);
  void makeGraph(double** matrix);
  bool findCycleHelper(int i,bool* visited,double** MST, int parenti,int parentj);
  bool checkForCycles(double** matrix, bool* visited);
private:
  double** m_adj;
  double** m_conn;
  int matrixSize;
  unsigned int m_size; //nodes in WGraph (fixed)
  
};
#endif