Ref:https://leetcode.com/problems/subtree-of-another-tree/solution/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        //bool result = false;
        //if(s != nullptr && t != nullptr){
        //    if(s->val == t->val){
        //        result = Tree1HaveTree2(s, t);
        //    }
        //    if(!result){result = Tree1HaveTree2(s->left, t);}
        //    if(!result){result = Tree1HaveTree2(s->right, t);}
        //}
        //return result;
        return traverse(s,t);
        
        
    }
    bool equals(TreeNode* x, TreeNode* y){
          if(x == nullptr && y == nullptr){return true;}
          if(x == nullptr || y == nullptr){return false;}
          return (x->val == y->val) && equals(x->left, y->left) && equals(x->right, y->right);
    }
    bool traverse(TreeNode* s, TreeNode* t){
            return (s != nullptr) && (equals(s,t) || traverse(s->left, t) || traverse(s->right, t));
        
    }
    
     //bool Tree1HaveTree2(TreeNode* s, TreeNode* t) {
     //   if(s == nullptr){return false;}
     //   if(t == nullptr){return true;}
      //  if(s->val != t->val){return false;}
        
        //if(s->val == t->val){
        //    if(s->left && t->left){
        //        bool leftFlag = isSubtree(s->left, t->left);
        //    }
        //    if(s->right && t->right){
        //        bool rightFlag = isSubtree(s->left, t->right);
        //    }
        //    return leftFlag && rightFlag;
        //return Tree1HaveTree2(s->left, t->left) && Tree1HaveTree2(s->right, t->right);   
    //}
};