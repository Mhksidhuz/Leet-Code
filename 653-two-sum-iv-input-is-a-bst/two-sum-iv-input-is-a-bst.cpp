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

class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse = false;

    BSTIterator(TreeNode* root,bool isreverse) {
        reverse = isreverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* curr = st.top();
        st.pop();
        if(!reverse) pushAll(curr->right);
        else pushAll(curr->left);
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    private:

    void pushAll(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            if(!reverse){
                root=root->left;
            }
            else root=root->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i = l.next();
        int j = r.next();

        while(i<j){
            if(i+j==k) return true;
            else if(i+j>k) j=r.next();
            else i=l.next();
        }
        return false;
    }
};