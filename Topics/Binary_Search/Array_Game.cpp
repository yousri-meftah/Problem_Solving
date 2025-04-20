#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;
        // set<int> s;
        vector<long long> v;
        bool print = false;
        for (int i = 0; i < n; i++)
        {
            long long a;
            cin >> a;
            v.push_back(a);
        }
        if (k > 2)
        {
            cout << "0" << endl;
            continue;
        }
        sort(v.begin(), v.end());
        long long mn = v[1] - v[0]; 
        for (int i = 2; i < n; i++)
        {
            mn = min(mn, v[i] - v[i - 1]);
        }
        if (k == 1)
        {
            cout <<  min(mn,v[0] )<< endl;
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                long long tt = v[j] - v[i] ;
                auto it = lower_bound(v.begin(), v.end(), tt);
                
                mn = min(mn, *it - tt);
                if (it != v.begin())
                {
                    it--;
                    mn = min(mn, abs(*it - tt));
                }
            }
        }
        
        mn = min(mn, v[0]);

        cout <<mn << endl;
    }

    return 0;
}