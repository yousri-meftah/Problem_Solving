class Solution {
    public:
        vector<TreeNode*> bfs(TreeNode* root){
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int a = q.size();
                vector<TreeNode*> v;
                while(a--){
                    auto t = q.front();
                    q.pop();
                    if(t->left){
                        q.push(t->left);
                    }
                    if(t->right){
                        q.push(t->right);
                    }
                    v.push_back(t);
                }
                if(q.empty())return v;
            }
            return {};
        }
        void dfs(TreeNode* root,TreeNode*val ,map<TreeNode* , int>&mp,int nb,TreeNode* &res,bool &ok,bool &f ){
            if(root==val){
                ok=true;
                if(mp[root]==nb)
                    {res = root;f=true;}
                return;
            }
            if(root->right){
                dfs(root->right,val,mp,nb,res,ok,f);
                if(ok){
                    if(mp[root]==nb&&!f){res = root;f=true;}
                    mp[root]++;
                    return;
                }
                
            }
            if(root->left){
                dfs(root->left,val,mp,nb,res,ok,f);
                if(ok){
                    if(mp[root]==nb&&!f){res = root;f=true;}
                    mp[root]++;
                    return;
                }
            }
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            vector<TreeNode*> v = bfs(root);
            int a = v.size();
            int nb = 0;
            TreeNode* res = NULL;
            map<TreeNode* , int> mp;
            for(auto i:v){
                bool ok=false,find = false;
                dfs(root,i,mp,nb,res,ok,find);
                nb++;
            }
            return res;
        }
    };