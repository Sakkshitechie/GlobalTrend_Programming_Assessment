#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "null";
        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);
       
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                ss << node->val << ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                ss << "null,";
            }
        }
       
        string result = ss.str();
        result.pop_back(); 
        return result;
    }


    TreeNode* deserialize(const string& data) {
        if (data == "null") return NULL;
        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);


        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();


            if (getline(ss, item, ',')) {
                if (item != "null") {
                    TreeNode* leftNode = new TreeNode(stoi(item));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }


            if (getline(ss, item, ',')) {
                if (item != "null") {
                    TreeNode* rightNode = new TreeNode(stoi(item));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        return root;
    }
};
void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);


    Codec codec;
    string serializedData = codec.serialize(root);
    cout << "Serialized data: " << serializedData << endl;


    TreeNode* deserializedRoot = codec.deserialize(serializedData);
    cout << "Deserialized tree: ";
    printTree(deserializedRoot);
    delete deserializedRoot->right->right;
    delete deserializedRoot->right->left;
    delete deserializedRoot->right;
    delete deserializedRoot->left;
    delete deserializedRoot;

    return 0;
}
