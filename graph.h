
class Node{
private:
    int val;
    mutable std::vector<const Node*> neighbors;
public:
    Node(const int num){
        val=num;
    }

    int getVal()const{
        return val;
    }
    void addNeighbor(const Node* n)const{
        for(auto node: neighbors){
            if(node==n){
                return;
            }
        }
        neighbors.push_back(n);
    }
    void removeNeighbor(const Node* n)const{
        std::vector<const Node*>::iterator it;
        for(it=neighbors.begin();it!=neighbors.end();it++){
            if(*it==n){
                neighbors.erase(it);
                return;
            }
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

    std::vector<const Node*> getNeighbors()const{
        return neighbors;
    }


};
struct NodeHash{
    public:
        size_t operator() (const Node* n) const{
            int num=n->getVal();
            return std::hash<int>()(num);
        }
};

struct NodeHashEqual{
    public:
        bool operator() (const Node* first, const Node* second) const{
            if(first->getVal()==second->getVal()){
                return true;
            }
            else{
                return false;
            }
        }
};

class Graph{
public:
    virtual void addNode(const int& nodeVal)=0;
    virtual void addUndirectedEdge(const Node* first, const Node* second)=0;
    virtual void removeUndirectedEdge(const Node* first, const Node* second)=0;
    virtual std::unordered_set<Node*,NodeHash,NodeHashEqual> getAllNodes()=0;
    virtual std::vector<Node*> getAdjList()const=0;
};

class UndirectedGraph: public Graph{
private:
    std::vector<Node*> adjList;

public:
    void addNode(const int& nodeVal){
        Node* newNode=new Node(nodeVal);
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
            if(node->getVal()==i){
                return node;
            }
        }
        return NULL;
    }
    std::vector<Node*> getAdjList()const{
        return adjList;
    }

    void displayNodes(){
        for(auto node: adjList){
            std::cout<<node->getVal()<<": ";
            for(auto neighNode: node->getNeighbors()){
                std::cout<<neighNode->getVal()<<" ";
            }

        }
    }
};
