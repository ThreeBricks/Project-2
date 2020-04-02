#include <iostream>
#include <vector>
#include <unordered_set>
#include <random>

using namespace std;

struct Node{
    private:
        string val;
        mutable vector<pair<const Node*,string>> neighbors;
    public:
        Node(const string& str){
            val=str;
        }
        string getVal()const {
            return val;
        }
        void addNeighbor(const Node& n) const{
            pair<const Node*,string> p=make_pair(&n,n.getVal());
            neighbors.push_back(p);
            return;
        }

        void removeNeighbor(const Node& n) const{
            vector<pair<const Node*,string>>::iterator it;
            for(it=neighbors.begin();it!=neighbors.end();it++){
                if((*it).first==&n){
                    neighbors.erase(it);
                }
            }
            return;
        }
        bool operator ==(const Node& n){
            if(val==n.val){
                return true;
            }
            else{
                return false;
            }

        }


};

struct NodeHash{
    public:
        size_t operator() (const Node& n) const{
            string str=n.getVal();
            return hash<string>()(str);
        }
};

struct NodeHashEqual{
    public:
        bool operator() (const Node& first, const Node& second) const{
            if(first.getVal()==second.getVal()){
                return true;
            }
            else{
                return false;
            }
        }
};


struct Graph{
    private:
        vector<Node> verticies;

    public:
        Graph(){}

        void addNode(const string& nodeVal){
            Node newNode(nodeVal);
            verticies.push_back(newNode);
            return;
        }

        void addUndirectedEdge(const Node& first, const Node& second){
            first.addNeighbor(second);
            second.addNeighbor(first);
            return;
        }

        void removeUndirectedEdge(const Node& first, const Node& second){
            first.removeNeighbor(second);
            second.removeNeighbor(first);
        }

        unordered_set<Node,NodeHash,NodeHashEqual> getAllNodes(){
            unordered_set<Node,NodeHash,NodeHashEqual> us(verticies.begin(),verticies.end());
            return us;
        }


};

Graph createRandomUnweightedGraphIter(const int& n){

}



int main(){
    Graph g;

    unordered_set<Node,NodeHash,NodeHashEqual> s=g.getAllNodes();
    unordered_set<Node,NodeHash,NodeHashEqual>::iterator it;
    for(it=s.begin();it!=s.end();it++){
        cout<<(*it).getVal()<<endl;
    }

    return 0;
}
