class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    if(root==NULL) return {};
         queue<TreeNode*> q;
         TreeNode* front;
         q.push(root);
         vector<vector<int>> res;
         
         while(!q.empty()){
             vector<int> onelevel;
             for(int i=q.size();i>0;i--){
                 front=q.front();
                 q.pop();
                 if(front->left)
                     q.push(front->left);
                 if(front->right)
                     q.push(front->right);
                 onelevel.push_back(front->val);
             }
             res.push_back(onelevel);
         }
         return res;     
    }
};