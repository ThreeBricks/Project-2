#include "graph.h"
#include "GraphSearch.h"
#include <algorithm>
Graph createRandomUnweightedGraphIter(const int& n){
    Graph tempGraph;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        tempGraph.addNode(to_string(rand()%1000));
    }
    unordered_map<Node,unordered_set<Node,NodeHash,NodeHashEqual>,NodeHash,NodeHashEqual>::iterator it,jt;
    for(it=tempGraph.adjList.begin();it!=tempGraph.adjList.end();it++){
        for(jt=tempGraph.adjList.begin();jt!=tempGraph.adjList.end();jt++){
            if(it==jt){
                continue;
            }
            else if(rand()%10>5){
                tempGraph.addUndirectedEdge(it->first,jt->first);
            }
        }
    }

    return tempGraph;
}

Graph createLinkedList(const int& n){
    Graph tempGraph;
    srand(time(NULL));
    vector<Node> nodeVec;
    nodeVec.reserve(n);
    for(int i=0;i<n;i++){
        string str=to_string(i);
        nodeVec.push_back(Node(str));
        tempGraph.addNode(str);
    }

    unordered_map<Node,unordered_set<Node,NodeHash,NodeHashEqual>,NodeHash,NodeHashEqual>::iterator it,jt;
    for(int i=0;i<n-1;i++){
        it=tempGraph.adjList.find(nodeVec[i]);
        jt=tempGraph.adjList.find(nodeVec[i+1]);
        tempGraph.addDirectedEdge(it->first,jt->first);
    }
    return tempGraph;
}

vector<Node> BFTRecLinkedList(){
    return BFTRec(createLinkedList(10000));
}
vector<Node> BFTIterLinkedList(){
    return BFTIter(createLinkedList(10000));
}

int main(){
    /*
    Graph g;
    g=createRandomUnweightedGraphIter(5);
    unordered_map<Node,unordered_set<Node,NodeHash,NodeHashEqual>,NodeHash,NodeHashEqual> aList=g.getAdjList();

    unordered_set<Node,NodeHash,NodeHashEqual> s=g.getAllNodes();
    unordered_set<Node,NodeHash,NodeHashEqual>::iterator it;
    for(it=s.begin();it!=s.end();it++){
        cout<<it->getVal()<<": ";
        for(auto node:aList.find(*it)->second)
            cout<<node.getVal()<<" ";
        cout<<endl;
    }


    string val1,val2;
    it=s.begin();
    val1=it->getVal();
    it++;
    val2=it->getVal();
    Node start=*s.find(Node(val1));
    Node dest=*s.find(Node(val2));

    vector<Node> ve=BFTRecLinkedList();
    if(ve.size()==0){
        cout<<"No route found"<<endl;
    }

    for(auto node: ve){
        cout<<node.getVal()<<endl;
    }

*/
vector<Node> ve=BFTIterLinkedList();

for(int i=0; i<ve.size();i++)
{
    cout<<ve[i].getVal()<<endl;
}

    return 0;
}
