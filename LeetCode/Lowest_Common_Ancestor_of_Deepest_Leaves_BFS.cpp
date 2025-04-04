class Solution {
    public:
        vector<vector<TreeNode*>> bfs(TreeNode* root){
            queue<TreeNode*> q;
            q.push(root);
            map<TreeNode* , vector<TreeNode*>> mp;
            mp[root].push_back(root);
            while(!q.empty()){
                int a = q.size();
                vector<vector<TreeNode*>> v;
                while(a--){
                    auto t = q.front();
                    q.pop();
                    if(t->left){
                        vector<TreeNode*> vv = mp[t];
                        vv.push_back(t->left);
                        mp[t->left] = vv;
                        q.push(t->left);
                    }
                    if(t->right){
                        vector<TreeNode*> vv = mp[t];
                        vv.push_back(t->right);
                        mp[t->right] = vv;
                        q.push(t->right);
                    }
                    v.push_back(mp[t]);
                }
                if(q.empty())return v;
            }
            return {};
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            vector<vector<TreeNode*>> v = bfs(root);
            int n = v[0].size();
            int a = v.size();
            while(n--){
                TreeNode* last = v[0][n];
                int start = 1;
                bool ok= false;
                while(start<a){
                    if(last->val!=v[start][n]->val){
                        ok = true;
                        break;
                    }
                    start++;
                }
                if(!ok)return last;
            }
            return root;
        }
    };