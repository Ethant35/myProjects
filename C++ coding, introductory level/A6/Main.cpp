#include "WGraph.h"

int main(int argc, char const *argv[]){
    WGraph w;
    double** adjencymatrix=w.fileProcessing(argv[1]);
    w.makeGraph(adjencymatrix);
    return 0;

}
