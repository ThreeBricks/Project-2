#include <iostream>
#include <unordered_set>
#include <vector>
#include <random>
#include <stack>
#include <queue>
#include <time.h>
#include "graph2.h"
#include "DirectedGraph.h"
#include "TopSort.h"

using namespace std;
DirectedGraph createRandomDAGIter(const int& n){
    DirectedGraph dg;
    for(int i=0;i<n;i++){
        dg.addNode(i);
    }
    for(int i=0;i<n;i++){
        if(rand()% n>3){
            dg.addDirectedEdge(dg.getNode(rand()%n),dg.getNode(rand()%n));
        }
    }
    return dg;
}


using namespace std;

int main()
{
    Kahns(createRandomDAGIter(1000));
    mDFS(createRandomDAGIter(1000));
    return 0;
}
