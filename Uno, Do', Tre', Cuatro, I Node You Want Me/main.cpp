#include "WeightedGraphNode.h"
#include "WeightedGraph.h"
using namespace std;
WeightedGraph createRandomCompleteWeightedGraph(const int n){
    cout<<"Creating Graph\n";
    WeightedGraph wg;
    for(int i=0;i<n;i++){
        wg.addNode(i);
    }

    for(int i=0; i<n;i++){
        for(int j=i+1; j<n;j++){
            wg.addWeightedEdge(wg.getNode(i),wg.getNode(j),rand()%10+1);
            wg.addWeightedEdge(wg.getNode(j),wg.getNode(i),rand()%10+1);
        }
    }
    cout<<"Graph created\n";
    return wg;
}

WeightedGraph createLinkedList(const int n){
    WeightedGraph wg;
    for(int i=0; i<n;i++){
        wg.addNode(i);
    }
    for(int i=0; i<n-1;i++){
        wg.addWeightedEdge(wg.getNode(i),wg.getNode(i+1),1);
    }
    return wg;
}
unordered_map<const Node,int,NodeHash> dijkstras(const Node start){
    cout<<"Running Dijkstras\n";
    unordered_map<const Node,int,NodeHash> dmap;
    unordered_set<int> visited;
    dmap.insert(make_pair(start,0));
    Node curr = start;
    for(auto node:curr.getNeighbors()){
        dmap.insert(make_pair(*node.first,100));
    }
    int numNodes = start.getNeighbors().size()+1;
    while((int)visited.size()!=numNodes){
        int minDis = 100;
        visited.insert(curr.getVal());
        for(auto nodePair: curr.getNeighbors()){
            if(visited.find(nodePair.first->getVal()) == visited.end()){
                    dmap[*nodePair.first] = min(nodePair.second,nodePair.second+dmap[curr]);
            }
        }
        for(auto node: dmap){
            if(node.second<minDis && visited.find(node.first.getVal()) == visited.end()){ //Updates the min distance and sets the new current node to the one containing that minDis
                minDis = node.second;
                curr = node.first;
            }
        }
    }
    cout<<"DONE\n";
    return dmap;
}

int main(){
    WeightedGraph wg = createRandomCompleteWeightedGraph(500);
    for(auto node:dijkstras(*wg.getNode(1))){
        cout<<node.first.getVal()<<": "<<node.second<<endl;
    }
}
