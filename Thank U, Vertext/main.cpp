#include "DirectedNode.h"
#include "DirectedGraph.h"
#include "TopSort.h"

using namespace std;

DirectedGraph createRandomDAGIter(const int n){
    DirectedGraph dg;

    cout<<"Creating Random DAG\n";
    for(int i=0;i<n;i++){
        dg.addNode(i);
    }

    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if(rand()%10 > 7){ //Adds an edge if a random number mod 10 is greater than 7
                dg.addDirectedEdge(dg.getNode(i),dg.getNode(j));
            }
        }
    }
    cout<<"DONE\n";
    return dg;
}

int main(){
    DirectedGraph dg = createRandomDAGIter(1000);
    for(auto node: Kahns(dg)){
        cout<<node.getVal()<<endl;
    }
    for(auto node: mDFS(dg)){
        cout<<node.getVal()<<endl;
    }
    return 0;
}
