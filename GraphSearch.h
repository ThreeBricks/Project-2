#include <stack>
#include <queue>
bool DFSRecHelper(const Node& currNode, const Node& dest, unordered_set<Node,NodeHash,NodeHashEqual>& visited, vector<Node>& pushVec){
    visited.insert(currNode);
    pushVec.push_back(currNode);
    if(currNode==dest){
        return true;
    }
    else{
        for(auto node: currNode.getNeighbors()){
            if(visited.find(node)==visited.end()){
                DFSRecHelper(node,dest,visited,pushVec);
            }
        }
    }
    return false;
}

vector<Node> DFSRec(const Node& start, const Node& dest){
    vector<Node> pushVec;
    vector<Node> startNeighbors=start.getNeighbors();
    unordered_set<Node,NodeHash,NodeHashEqual> visited={};
    pushVec.push_back(start);
    for(vector<Node>::iterator it=startNeighbors.begin();it!=startNeighbors.end();it++){
        if(visited.find(*it)==visited.end()){
            if(DFSRecHelper(*it,dest,visited,pushVec)){
                return pushVec;
            }
        }
    }
    if(visited.find(dest)==visited.end()){
        return {};
    }

    return pushVec;
}


vector<Node> DFSIter(const Node& start, const Node& dest) {
    stack<Node> s;
    vector<Node> nodeVec;
    unordered_set<Node,NodeHash,NodeHashEqual> visited={};
    Node curr=start;
    if(curr==dest){
        nodeVec.push_back(curr);
        return nodeVec;
    }
    else{
        s.push(curr);
        visited.insert(curr);
        while(!s.empty()){
            Node curr=s.top();
            s.pop();
            if(curr==dest){
                nodeVec.push_back(curr);
                return nodeVec;
            }
            else{
                nodeVec.push_back(curr);
                for(auto nodeNeighbor:curr.getNeighbors()){
                    if(visited.find(nodeNeighbor)==visited.end()){
                        visited.insert(nodeNeighbor);
                        s.push(nodeNeighbor);
                    }
                }
            }
        }
    }
    if(visited.find(dest)==visited.end()){
        nodeVec={};
    }
    return nodeVec;
}
void BFTRecHelper(const Node& node,vector<Node>& pushVec,unordered_set<Node,NodeHash,NodeHashEqual>& visited){
    if(visited.find(node)==visited.end()){
        visited.insert(node);
        pushVec.push_back(node);
        for(auto neighNode:node.getNeighbors()){
            BFTRecHelper(neighNode,pushVec,visited);
        }

    }


}

vector<Node> BFTRec(const Graph& g){
    vector<Node> nodeVec;
    unordered_set<Node,NodeHash,NodeHashEqual> visited={};
    for(auto curr:g.getAdjList()){
        BFTRecHelper(curr.first,nodeVec,visited);
    }
    return nodeVec;
}



vector<Node> BFTIter(const Graph&g){
    queue<Node> q;
    vector<Node> nodeVec;
    unordered_set<Node,NodeHash,NodeHashEqual> visited={};
    for(auto curr:g.getAdjList()){
        if(visited.find(curr.first)==visited.end()){
        q.push(curr.first);
        visited.insert(curr.first);
        while(!q.empty()){
            Node curr=q.front();
            q.pop();
            nodeVec.push_back(curr);
            for(auto nodeNeighbor:curr.getNeighbors()){
                if(visited.find(nodeNeighbor)==visited.end()){
                    visited.insert(nodeNeighbor);
                        q.push(nodeNeighbor);
                    }
                }
            }
        }
    }
    return nodeVec;
}
















