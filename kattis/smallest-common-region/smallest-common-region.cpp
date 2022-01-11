struct Node {
    string name;
    vector<Node*> children;
};

class Solution {
public:
    unordered_map<string, int> indeg;
    unordered_map<string, Node> nameToNode;
    
    void print(const string &s) {
        cout << s << endl;
    }
    
    Node* getNode(const string &name) {
        if (nameToNode.find(name) == nameToNode.end()) {
            nameToNode[name] = Node{name, vector<Node*>{}};
        }
        return &nameToNode[name];
    }
    
    Node* makeTreeUpdateIndeg(vector<vector<string>>& regions) {
        for (auto &region: regions) {            
            if (indeg.find(region[0]) == indeg.end()) indeg[region[0]] = 0;
            for (int i = 1; i < region.size(); i++) {
                string regPar = region[0];
                string regChild = region[i];
                indeg[regChild]++;
                Node* u = getNode(regPar);
                Node* v = getNode(regChild);
                (u->children).push_back(v);
            }
        }
        // get root node
        for (auto const &pr: indeg) {
            if (pr.second == 0) {
                return getNode(pr.first);
            }
        }
        return nullptr;
    }
    
    Node* findLca(Node* root, const string& r1, const string& r2) {
        string name = root->name;
        if (name == r1 || name == r2) return root;
        
        vector<Node*> children = root->children;
        int cnt = (name == r1 || name == r2) ? 1 : 0;
        Node* rmb;
        for (Node* child: children) {
            Node* tmp = findLca(child, r1, r2);
            if (tmp != nullptr) {
                cnt++;
                rmb = tmp;
            }
        }

        if (cnt >= 2) {
            return root;
        }
        else if (cnt == 1) return rmb;
        else return nullptr;
    }
    
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        Node* root = makeTreeUpdateIndeg(regions);
        Node* lca = findLca(root, region1, region2);
        return lca->name;
    }
};