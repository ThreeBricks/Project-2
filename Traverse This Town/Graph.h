#include <iostream>
#include <unordered_set>
#include <vector>
#include <random>
#include <time.h>
#include <string>

class Graph{
public:
    virtual void addNode(const int& nodeVal)=0;
    virtual std::unordered_set<Node*,NodeHash,NodeHashEqual> getAllNodes()=0;
    virtual std::vector<Node*> getAdjList()const=0;
};

class UndirectedGraph: public Graph{
private:
    std::vector<Node*> adjList;

public:
    void addNode(const int& nodeVal){
        if(nodeVal<adjList.size()){
            if(adjList[nodeVal]){
                return;
            }
        }
        Node* newNode = new Node(nodeVal);
        adjList.push_back(newNode);
        return;
    }
    void addUndirectedEdge(const Node* first, const Node* second){
        first->addNeighbor(second);
        second->addNeighbor(first);
        return;
    }
    void addDirectedEdge(const Node* first, const Node* second){
        first->addNeighbor(second);
        return;
    }
    void removeUndirectedEdge(const Node*first, const Node* second){
        first->removeNeighbor(second);
        second->removeNeighbor(first);
        return;
    }
    std::unordered_set<Node*,NodeHash,NodeHashEqual> getAllNodes(){
        std::unordered_set<Node*,NodeHash,NodeHashEqual> s;
        for(auto node: adjList){
            s.insert(node);
        }
        return s;
    }
    Node* getNode(const int& i){
        for(auto node:adjList){
            if(node->getVal() == i){
                return node;
            }
        }
        return NULL;
    }
    std::vector<Node*> getAdjList()const{
        return adjList;
    }
};

std::ostream& operator <<(std::ostream& os, const UndirectedGraph& ug){
    for(auto node: ug.getAdjList()){
        os<<node->getVal()<<"\n";
        for(auto neighNode: node->getNeighbors()){
            os<<neighNode->getVal()<<" ";
        }
        os<<std::endl;
    }
}
