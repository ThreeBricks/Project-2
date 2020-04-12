#include <unordered_map>
class Node{
private:
    int val;
    mutable int inDegree;
    mutable std::unordered_set<const Node*> neighbors;
public:
    Node(const int num){
        val=num;
        inDegree=0;
    }

    int getVal()const{
        return val;
    }
    void addNeighbor(const Node* n)const{
        if(n->getVal()!=val){
           neighbors.insert(n);
        }
    }
    void removeNeighbor(const Node* n)const{
        if(neighbors.find(n)!=neighbors.end()){
            neighbors.erase(neighbors.find(n));
            return;
        }
    }

    bool operator==(const Node*n2){
        if(val==n2->getVal()){
            return true;
        }
        else{
            return false;
        }
    }
    std::unordered_set<const Node*> getNeighbors()const{
        return neighbors;
    }
    int getInDegree()const{
        return inDegree;
    }
    void updateInDegree()const{
        inDegree+=1;
        return;
    }
    void decreaseInDegree()const{
        inDegree-=1;
        return;
    }

};

class Graph{
public:
    virtual void addNode(const int& nodeVal)=0;
    virtual std::unordered_set<Node*> getAllNodes()const=0;
    virtual std::vector<Node*> getAdjList()const=0;
};

