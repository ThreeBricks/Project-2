#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>
#include <random>
#include <time.h>
#include <string>
#include <unordered_map>
class Node{
private:
    int val;
    mutable std::unordered_set<const Node*> neighbors;
public:
    Node(const int num){
        val = num;
    }

    int getVal()const{
        return val;
    }
    void addNeighbor(const Node* n) const{
        if(n->getVal() != val){
           neighbors.insert(n);
        }
        return;
    }
    void removeNeighbor(const Node* n) const{
        if(neighbors.find(n) != neighbors.end()){
            neighbors.erase(neighbors.find(n));
        }
        return;
    }
    bool operator == (const Node n2)const {
        return val == n2.getVal();
    }
    std::unordered_set<const Node*> getNeighbors() const{
        return neighbors;
    }
};
struct NodeHash{
    public:
        size_t operator() (const Node& n) const{
            int val = n.getVal();
            return std::hash<int>()(val);
        }
};
