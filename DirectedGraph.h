bool checkAcyclic(const Node* first, const Node* second){
    std::queue<const Node*> holdQ;
    holdQ.push(second);
    while(!holdQ.empty()){
        for(auto node: holdQ.front()->getNeighbors()){
            if(node->getVal()==first->getVal()){
                return false;
            }
            holdQ.push(node);
        }
        holdQ.pop();
    }
 return true;
}

class DirectedGraph: public Graph{
private:
    std::vector<Node*> adjList;
public:
    void addNode(const int& nodeVal){
        Node* newNode=new Node(nodeVal);
        adjList.push_back(newNode);
        return;
    }
    void addDirectedEdge(const Node* first, const Node* second){
        if(checkAcyclic(first,second)){
            first->addNeighbor(second);
        }
        return;
    }
    void removeDirectedEdge(const Node*first, const Node* second){
        first->removeNeighbor(second);
        return;
    }
    std::unordered_set<Node*> getAllNodes()const{
        std::unordered_set<Node*> s;
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
            std::cout<<node->getVal()<<": InDegree: "<<node->getInDegree()<<" : ";
            for(auto neighNode: node->getNeighbors()){
                std::cout<<neighNode->getVal()<<" ";
            }
            std::cout<<std::endl;

        }
    }

};
