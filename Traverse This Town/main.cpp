#include "Node.h"
#include "Graph.h"
#include "DirectedGraph.h"
#include "GraphSearch.h"

using namespace std;

UndirectedGraph createRandomUnweightedGraphIter(int n){
    UndirectedGraph ud;
    for(int i=0; i<n;i++){
        ud.addNode(i);
    }
    for(int i=0;i<n;i++){
        if(rand()% n>3){
            ud.addUndirectedEdge(ud.getNode(rand()%n),ud.getNode(rand()%n));
        }
    }
    return ud;
}

UndirectedGraph createLinkedList(int n){
    UndirectedGraph ud;
    for(int i=0; i<n;i++){
        ud.addNode(i);
    }
    for(int i=0; i<n-1;i++){
        ud.addDirectedEdge(ud.getNode(i),ud.getNode(i+1));
    }
    return ud;
}

vector<Node> BFTRecLinkedList(){
    return BFTRec(createLinkedList(10000));
}
vector<Node> BFTIterLinkedList(){
    return BFTIter(createLinkedList(10000));
}

DirectedGraph createRandomDAGIter(const int& n){
    DirectedGraph dg;
    return dg;
}

int main(){
    vector<Node> recVec = BFTRecLinkedList();
    vector<Node> iterVec = BFTIterLinkedList();
    for(auto node:recVec){
        cout<<node.getVal()<<" ";
    }
        for(auto node:iterVec){
        cout<<node.getVal()<<" ";
    }
    return 0;
}
