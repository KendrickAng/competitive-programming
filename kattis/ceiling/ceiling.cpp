#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

struct Node {
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
};

void insert(Node *root, int n) {
    if (root == nullptr) {
        return;
    }
    if (root->val == -1) {
        root->val = n;
        return;
    }
    if (root->val < n) {
        if (root->left != nullptr) {
            insert(root->left, n);
        } else {
            Node *tmp = new Node;
            tmp->val = n;
            root->left = tmp;
        }
    }
    else {
        if (root->right != nullptr) {
            insert(root->right, n);
        } else {
            Node *tmp = new Node;
            tmp->val = n;
            root->right = tmp;
        }
    }
}

// preorder and postorder strings are guaranteed unique
std::string serialize(Node *root, int level) {
    if (root == nullptr) {
        return "";
    }
    std::string ret = "";
    ret += serialize(root->left, level+1);
    ret += std::to_string(level);
    ret += serialize(root->right, level+1);
    return ret;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<Node> trees{};
    std::unordered_set<std::string> treestrs{};
    for (int i = 0; i < n; i++) {
        Node *root = new Node;
        root->val = -1;
        for (int j = 0; j < k; j++) {
            int tmp; std::cin >> tmp;
            insert(root, tmp);
        }
        std::string str = serialize(root, 0);
        treestrs.insert(str);
    }
    std::cout << treestrs.size() << std::endl;
}