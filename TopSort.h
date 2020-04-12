std::vector<Node> Kahns(const DirectedGraph& graph){
    std::vector<Node> ordering;
    std::queue<Node> zeroDegree;
    for(auto node: graph.getAllNodes()){
        if(node->getInDegree()==0){
            zeroDegree.push(*node);
        }
    }
    while(!zeroDegree.empty()){
        ordering.push_back(zeroDegree.front());

        for(auto node:zeroDegree.front().getNeighbors()){
            node->decreaseInDegree();
            if(node->getInDegree()==0){
                zeroDegree.push(*node);
            }
        }
        zeroDegree.pop();
    }
    return ordering;
}

std::vector<Node> mDFS(const DirectedGraph& graph){
    std::vector<Node> ordering;
    std::stack<Node> topStack;
    std::stack<Node> dfsStack;
    std::unordered_set<const Node*> visited;
    for(auto node:graph.getAllNodes()){
        if(visited.find(node)==visited.end()){
            visited.insert(node);
            dfsStack.push(*node);
        }
        while(!dfsStack.empty()){
            Node curr=dfsStack.top();
            dfsStack.pop();
            for(auto neighNode:curr.getNeighbors()){
                visited.insert(neighNode);
                dfsStack.push(*neighNode);
            }
        }
        topStack.push(*node);
    }
    while(!topStack.empty()){
        ordering.push_back(topStack.top());
        topStack.pop();

    }
    return ordering;
}
