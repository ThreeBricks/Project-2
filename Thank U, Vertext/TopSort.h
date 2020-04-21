std::vector<Node> Kahns(const DirectedGraph& graph){
    std::vector<Node> ordering;
    std::queue<Node> zeroDegree;
    std::unordered_map<Node, int,NodeHash> inDegrees;
    std::cout<<"Running Kahns\n";
    for(auto node: graph.getAllNodes()){
        if(inDegrees.find(*node) == inDegrees.end()){
            inDegrees[*node]=0;
        }
        else{
            for(auto nodeNeigh: node->getNeighbors()){
                if(inDegrees.find(*nodeNeigh) == inDegrees.end()){
                    inDegrees[*nodeNeigh]=0;
                }
                else{
                    inDegrees[*nodeNeigh] += 1;
                }
            }
        }
    }
    for (auto inPair: inDegrees){
        if(inPair.second==0){
            zeroDegree.push(inPair.first);
        }
    }
    while(!zeroDegree.empty()){
        ordering.push_back(zeroDegree.front());
        for(auto node:zeroDegree.front().getNeighbors()){
            inDegrees[*node] -= 1;
            if(inDegrees[*node] == 0){
                zeroDegree.push(*node);
            }
        }
        zeroDegree.pop();
    }
    std::cout<<"DONE\n";
    return ordering;
}

std::vector<Node> mDFS(const DirectedGraph& graph){
    std::vector<Node> ordering;
    std::stack<Node> topStack;
    std::stack<Node> dfsStack;
    std::unordered_set<const Node*> visited;
    std::cout<<"Running mDFS\n";
    for(auto node:graph.getAllNodes()){
        if(visited.find(node)==visited.end()){
            visited.insert(node);
            dfsStack.push(*node);
        }
        while(!dfsStack.empty()){
            Node curr=dfsStack.top();
            dfsStack.pop();
            for(auto neighNode:curr.getNeighbors()){
                if(visited.find(node)==visited.end()){
                    visited.insert(neighNode);
                    dfsStack.push(*neighNode);
                }
            }
            topStack.push(*node);
        }
    }
    while(!topStack.empty()){
        ordering.push_back(topStack.top());
        topStack.pop();
    }
    std::cout<<"DONE\n";
    return ordering;
}

