/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <map>
#include <set>
#include <vector>

using namespace std;

unordered_map <int, TreeNode*> address;
unordered_set<int> hasParent;

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        address.clear();
        hasParent.clear();

        for (auto v : descriptions){
            hasParent.insert(v[1]);
            TreeNode* tmp; //lay dia chi node parent
            if (address.count(v[0]) == 0){
                tmp = new TreeNode(v[0]);
            }
            else{
                tmp = address[v[0]];
            }
            //noi vao node child
            if (address.count(v[1]) != 0){
                if (v[2] == 1) tmp->left = address[v[1]];
                else tmp->right = address[v[1]];
            }
            else{
                address[v[1]] = new TreeNode(v[1]);
                if (v[2] == 1) tmp->left = address[v[1]];
                else tmp->right = address[v[1]];
            }
            address[v[0]] = tmp;
        }
        for (auto v : descriptions){
            if (hasParent.count(v[0]) == 0) return address[v[0]];
        }
        return nullptr;
    }
};
