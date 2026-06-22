/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node* , Node*> deepcopy;
    
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        
        if(deepcopy.count(node)){
            return deepcopy[node];
        }


        Node* newNode = new Node();
        newNode->val = node-> val;

        deepcopy[node] = newNode;
        
        for(Node* i : node->neighbors){
            newNode->neighbors.push_back(cloneGraph(i));
        }

        return newNode;
    }
};
