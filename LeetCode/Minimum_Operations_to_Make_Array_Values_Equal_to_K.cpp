class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            set<int> s;
            for(auto i:nums)s.insert(i);
            bool ok =false;
            int nb = 0;
            while(s.size()){
                auto it = --s.end();
                int max_val = *it;
                if(max_val==k&&s.size()==1)return nb;
                if(max_val<k)return -1;
                if(ok==false){
                    s.erase(it);
                    nb++;
                }
                ok=!ok;
            }
            return nb;
        }
    };