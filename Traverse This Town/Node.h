#include <iostream>
#include <unordered_set>
#include <vector>
#include <random>
#include <time.h>
#include <string>
class Node{
private:
    int val;
    mutable std::vector<const Node*> neighbors;
public:
    Node(const int num){
        val = num;
    }

    int getVal()const{
        return val;
    }
    void addNeighbor(const Node* n) const{
        for(auto node: neighbors){
            if(node == n){
                return;
            }
        }
        neighbors.push_back(n);
    }
    void removeNeighbor(const Node* n)const{
        if(neighbors.empty()){
            return;
        }
        std::vector<const Node*>::iterator it;
        for(it=neighbors.begin();it != neighbors.end();it++){
            if(*it == n){
                neighbors.erase(it);
                return;
            }
        }
    }
    bool operator == (const Node* node2){
        if(val == node2->getVal()){
            return true;
        }
        else{
            return false;
        }
    }

    std::vector<const Node*> getNeighbors()const{
        return neighbors;
    }


};
struct NodeHash{ //used as hash function for unordered sets and maps
    public:
        size_t operator() (const Node* n) const{
            int num = n->getVal();
            return std::hash<int>()(num);
        }
};

struct NodeHashEqual{//used to ensure hashes are unique in unordered sets and maps
    public:
        bool operator() (const Node* first, const Node* second) const{
            if(first->getVal() == second->getVal()){
                return true;
            }
            else{
                return false;
            }
        }
};
