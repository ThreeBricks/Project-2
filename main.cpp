#include <iostream>
#include <unordered_set>
#include <vector>
#include <random>
#include <time.h>
#include <string>
#include "graph.h"
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

int main(){
    UndirectedGraph d=createRandomUnweightedGraphIter(10000);
    for(auto node:BFTIter(d)){
        cout<<node.getVal()<<" ";
    }


    return 0;
}
