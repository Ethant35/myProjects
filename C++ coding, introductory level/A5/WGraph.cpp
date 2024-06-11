#include "WGraph.h"
#include <sstream>
#include <fstream>

WGraph::WGraph(){
  m_size = 0;
  m_adj = NULL;
  
}
WGraph::WGraph(unsigned int sz){
  m_size = sz;
  //allocate sz * sz adj matrix
  m_adj = new double*[sz];
  m_conn = new double*[sz];
  for(int i = 0; i < m_size; ++i){
    m_adj[i] = new double[sz];
    m_conn[i] = new double[sz];
  }
  //start with edges
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_adj[i][j] = std::numeric_limits<double>::max();
      m_conn[i][j] = std::numeric_limits<double>::max();
    }
  }
}
WGraph::~WGraph(){
  //release memory
}
void WGraph::addEdge(VertexID i, VertexID j, double w){
  if(i < m_size && j < m_size){
    m_adj[i][j] = w;
    m_adj[j][i] = w;
  }
}
void WGraph::removeEdge(VertexID i, VertexID j){
  if(i < m_size && j < m_size){
    m_adj[i][j] = std::numeric_limits<double>::max();
    m_adj[j][i] = std::numeric_limits<double>::max();
  }
}
bool WGraph::areAdjacent(VertexID i, VertexID j){
  return (m_adj[i][j] < std::numeric_limits<double>::max());
}
void WGraph::calcFW(){
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_conn[i][j] = m_adj[i][j]; //start with conn == adj matrix
    }
  }
  for(int im = 0; im < m_size; ++im){ //transitive closure
    for(int source = 0; source < m_size; ++source){
      for(int sink = 0; sink < m_size; ++sink){
        //every possible pair of source,sink and intermediate node
        if(source==sink){
          continue;
        }
        if(m_conn[source][im] != std::numeric_limits<double>::max() &&
           m_conn[im][sink] != std::numeric_limits<double>::max() &&
           m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){
          m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];
        }
      }
    }
  }
}
double WGraph::cheapestCost(VertexID i, VertexID j){
  return m_conn[i][j];
}

double** WGraph::fileProcessing(string fileName){
  ifstream reader;
  reader.open(fileName);
  string linecontents="";
  double temp=0;
  getline(reader,linecontents);
  int n=stoi(linecontents);
  matrixSize=n;
  double** arr= new double*[n];
  for (int i=0;i<n;++i){
    arr[i]=new double[n];
    getline(reader,linecontents);
    istringstream iss(linecontents);
    for(int j=0;j<n;++j){
      iss>>temp;
      arr[i][j]=temp;
    }
  }
  return arr;
}


//double** adjencymatrix=fileProcessing("file.txt");
void WGraph::makeGraph(double** matrix){
    int n=matrixSize;
    int mini=0;
    int minj=0;
    bool isDone=false;
    double** MST= new double*[n];
    for (int i=0;i<n;++i){
      MST[i]=new double[n];
    }
    double min=DBL_MAX;
    bool* visited=new bool[matrixSize];
    while(!isDone){
      min=DBL_MAX;
      for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
          if(matrix[i][j]!=0 && matrix[i][j]<min){
            mini=i;
            minj=j;
            min=matrix[i][j];
          }
        }
      }
      matrix[mini][minj]=0;
    
    MST[mini][minj]=min;
    if (checkForCycles(MST,visited)){
      MST[mini][minj]=0;
    }
    int numTrue=0;
    for (int i=0;i<n;++i){
      if (visited[i]){
        numTrue++;
      }
    }
    if(numTrue==matrixSize){
      isDone=true;
    }
    }
    for (int i=0;i<matrixSize;++i){
      for (int j=i;j<matrixSize;++j){
        if (MST[i][j]!=MST[j][i]){
          MST[i][j]=MST[j][i];
        }
      }
    }
    double cost=0;
    for (int i=0;i<matrixSize;++i){
      for (int j=0;j<matrixSize;++j){
        cost+=MST[i][j];
        cout<<MST[i][j]<<" ";
      }
      cout<<endl;
    }
    cost=cost/2;
    cout<<"The cost of the MST I found is: "<<cost<<endl;


}

bool WGraph::checkForCycles(double** matrix,bool* visited){
  /*double** visited= new double*[n];
  for (int i=0;i<3;++i){
    visited[i]=new double[3];
  }
  for (int i=0;i<3;++i){
    for (int j=0;j<3;++j){
      visited[i][j]=0;
    }
  }
  for (int i=0;i<3;++j){
    for (int j=0;j<3;++j){
      if (matrix[i][j]!==0){
        if (visited[i][j]!==0 && visited[j][i]!==0){
          
        }
      }
  }

  
  }*/
  bool result;
  for (int i=0;i<matrixSize;++i){
    for (int j=0;j<matrixSize;++j){
      if (matrix[i][j]!=0){
        visited[i]=true;
        //visited[j]=true;
        result=findCycleHelper(i,visited,matrix,i,j);

      }
    }


  }
  return result;

}

bool WGraph::findCycleHelper(int i,bool* visited,double** MST,int parenti, int parentj){
  visited[i]=true;
  for (int j=0;j<matrixSize;++j){
    if (MST[i][j]!=0 && !(visited[j])){
      findCycleHelper(j,visited,MST,i,j);
    }
    else if(MST[i][j]!=0 && (visited[j]) && j!=parentj){
      return true;
    }    
  }
  return false;
}


