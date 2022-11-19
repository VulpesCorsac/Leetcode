#define ALL(c) c.begin(), c.end()

template < typename C, typename K >
bool contains(C container, K key) {
    return find(ALL(container), key) != container.end();
}

class ConsistentHashing {
public:
    ConsistentHashing(int initialNodes) 
        : lastId(initialNodes) {
        for (int i = 1; i <= lastId; ++i)
            nodeToKeys[i] = {};
    }
    
    int getNodeForKey(int key) {
        if (!keyToNodes[key].empty()) 
            return keyToNodes[key].back();

        sizeAndNodeRefresh();
        auto node = sizeAndNode.front().second;
        assignKeysToNode({key}, node);
        return node;
    }
    
    int removeNode(int node) {
        int helperNode = 0;
        sizeAndNodeRefresh();
        for (const auto& [_, nodeId]: sizeAndNode) 
            if (nodeId != node) {
                helperNode = nodeId;
                break;
            }

        for (const auto& key : nodeToKeys[node]) {
            if (!contains(nodeToKeys[helperNode], key))
                assignKeysToNode({key}, helperNode);
            if (auto it = find(ALL(keyToNodes[key]), node);
                it != keyToNodes[key].end())
                keyToNodes[key].erase(it);
        }
        
        nodeToKeys.erase(node);
        return helperNode;
    }
    
    vector<int> addNode() {
        sizeAndNodeRefresh();
        auto helperNode = sizeAndNode.back().second;
        assignKeysToNode(nodeToKeys[helperNode], ++lastId);        
        return {lastId, helperNode};
    }
    
    vector<int> getKeysInNode(int node) {
        return nodeToKeys[node];
    }
    
private:
    unordered_map<int, vector<int>> nodeToKeys; 
    unordered_map<int, vector<int>> keyToNodes; 
    vector<pair<int, int>> sizeAndNode;
    int lastId;
    
    void assignKeysToNode(const vector<int>& keys, int node) {
        for (const auto& key: keys) {
            keyToNodes[key].push_back(node);
            nodeToKeys[node].push_back(key);
        }
    }
    
    void sizeAndNodeRefresh() {
        sizeAndNode.clear();
        for (const auto& [node, keys] : nodeToKeys)
            sizeAndNode.push_back({keys.size(), node});
        sort(sizeAndNode.begin(), sizeAndNode.end());
    }
};
