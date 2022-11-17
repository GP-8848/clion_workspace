//
// Created by V5 on 2022/6/8.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 根据数组构造二叉树
TreeNode *construct_binary_tree(const vector<int> &vec) {
    vector<TreeNode *> vecTree(vec.size(), nullptr);
    TreeNode *root = nullptr;
    for (int i = 0; i < vec.size(); i++) {
        TreeNode *node = nullptr;
        if (vec[i] != -1) node = new TreeNode(vec[i]);
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    for (int i = 0; i * 2 + 2 < vec.size(); i++) {
        if (vecTree[i] != nullptr) {
            vecTree[i]->left = vecTree[i * 2 + 1];
            vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }
    return root;
}

// 层序打印打印二叉树
void print_binary_tree(TreeNode *root) {
    queue<TreeNode *> que;
    if (root != nullptr) que.push(root);

    vector<vector<int>> result;
    while (!que.empty()) {
        // 最后一层节点的子节点为空，不输出
        bool not_last_level = false;
        unsigned long long size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            TreeNode *node = que.front();
            que.pop();
            if (node != nullptr) {
                not_last_level = true;

                vec.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            } else {
                // 把nullptr节点打印出来，用-1 表示nullptr
                vec.push_back(-1);
            }/
        }
        if (not_last_level) {
            // 最后一层的子节点不打印，因为全空
            result.push_back(vec);
        }
    }
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // 注意本代码没有考虑输入异常数据的情况
    // 用 -1 来表示nullptr
    vector<int> vec = {4, 1, 6, 0, 2, 5, 7, -1, -1, -1, 3, -1, -1, -1, 8};
    TreeNode *root = construct_binary_tree(vec);
    print_binary_tree(root);
}