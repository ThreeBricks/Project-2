#include <stack>
#include <queue>
//
// currNode is the starting node, dest is the node that you want to reach
// visited is an unordered set that keeps track of the visited nodes,
// pushVec is a vector that keeps track of the visited node and maintains the order they were visited in.
//
bool DFSRecHelper(const Node* currNode, const Node* dest, std::unordered_set<const Node*,NodeHash,NodeHashEqual>& visited, std::vector<Node>& pushVec){
    pushVec.push_back(*currNode);
    visited.insert(currNode);
    if(currNode == dest){
        return true;
    }
    else{
        for(auto node: currNode->getNeighbors()){
            if(visited.find(node) == visited.end()){
                DFSRecHelper(node,dest,visited,pushVec);
            }
        }
    }
    return false;
}

std::vector<Node> DFSRec(const Node* start, const Node* dest){
    std::vector<Node> pushVec;
    std::vector<const Node*> startNeighbors=start->getNeighbors();
    std::unordered_set<const Node*,NodeHash,NodeHashEqual> visited = {};
    pushVec.push_back(*start);
    visited.insert(start);
    for(std::vector<const Node*>::iterator it=startNeighbors.begin();it!=startNeighbors.end();it++){
        if(visited.find(*it) == visited.end()){
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

std::vector<Node> DFSIter(const Node* start, const Node* dest) {
    std::stack<Node> s;
    std::vector<Node> nodeVec;
    std::unordered_set<const Node*,NodeHash,NodeHashEqual> visited = {};
    const Node* curr = start;
    if(curr == dest){
        nodeVec.push_back(*curr);
        return nodeVec;
    }
    else{
        s.push(*curr);
        visited.insert(curr);
        while(!s.empty()){
            Node curr = s.top();
            s.pop();
            if(curr == dest){
                nodeVec.push_back(curr);
                return nodeVec;
            }
            else{
                nodeVec.push_back(curr);
                for(auto nodeNeighbor:curr.getNeighbors()){
                    if(visited.find(nodeNeighbor) == visited.end()){
                        visited.insert(nodeNeighbor);
                        s.push(*nodeNeighbor);
                    }
                }
            }
        }
    }
    if(visited.find(dest) == visited.end()){
        nodeVec = {};
    }
    return nodeVec;
}

void BFTRecHelper(const Node* node,std::vector<Node>& pushVec,std::unordered_set<const Node*,NodeHash,NodeHashEqual>& visited){
    if(visited.find(node) == visited.end()){
        visited.insert(node);
        pushVec.push_back(*node);
        for(auto neighNode:node->getNeighbors()){
            BFTRecHelper(neighNode,pushVec,visited);
        }

    }
}

std::vector<Node> BFTRec(const Graph& g){
    std::vector<Node> nodeVec;
    std::unordered_set<const Node*,NodeHash,NodeHashEqual> visited = {};
    for(auto curr:g.getAdjList()){
        BFTRecHelper(curr,nodeVec,visited);
    }
    return nodeVec;
}

std::vector<Node> BFTIter(const Graph&g){
    std::queue<Node> q;
    std::vector<Node> nodeVec;
    std::unordered_set<const Node*,NodeHash,NodeHashEqual> visited = {};
    for(auto curr:g.getAdjList()){
        if(visited.find(curr) == visited.end()){
        q.push(*curr);
        visited.insert(curr);
        while(!q.empty()){
            Node curr = q.front();
            q.pop();
            nodeVec.push_back(curr);
            for(auto nodeNeighbor:curr.getNeighbors()){
                if(visited.find(nodeNeighbor) == visited.end()){
                    visited.insert(nodeNeighbor);
                        q.push(*nodeNeighbor);
                    }
                }
            }
        }
    }
    return nodeVec;
}


