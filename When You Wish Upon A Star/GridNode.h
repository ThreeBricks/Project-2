#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <random>
#include <stack>
#include <queue>
#include <time.h>
#include <utility>
class GridNode{
private:
    int x;
    int y;
    std::string val;
    mutable bool visited;
    mutable std::unordered_set<const GridNode*> neighbors;
public:
    GridNode(){
        x = -1;
        y = -1;
        val = -1;
        visited = false;
    }
    GridNode(int xval,int yval, std::string nStr){
        x = xval;
        y = yval;
        val = nStr;
        visited = false;
        neighbors.reserve(4);
    }
    std::string getVal()const{
        return val;
    }
    int getX()const{
        return x;
    }
    int getY()const{
        return y;
    }
    std::unordered_set<const GridNode*> getNeighbors()const{
        return neighbors;
    }
    void addNeighbor(const GridNode* node)const{
        neighbors.insert(node);
        return;
    }
    void removeNeighbor(const GridNode* node) const{
        neighbors.erase(node);
        return;
    }
    void visit()const{
        visited = true;
        return;
    }
    bool isVisited()const{
        return visited;
    }

    bool operator==(const GridNode node)const{
        if(x == node.getX() && y == node.getY()){
            return true;
        }
        return false;
    }
    bool operator!=(const GridNode node)const{
        return !operator==(node);
    }

};
struct GridNodeHash{
    public:
        size_t operator() (const GridNode& n) const{
            std::string str = n.getVal();
            return std::hash<std::string>()(str);
        }
        size_t operator() (const GridNode* n) const{
            std::string str = n->getVal();
            return std::hash<std::string>()(str);
        }
};
