#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n  , k;
    cin>>n>>k;
    string ch ; 
    cin>>ch;
    //cout<<" ans = ";
    if(n==1){
        if(ch[0]=='L'&&k==0)
            cout<<"0"<<"\n";
        else if(ch[0]=='L'&&k>=1)cout<<"1"<<endl;
        else cout<<"1"<<"\n";
        return;
    }
    long long score = ch[0]=='W'?1:0;
    bool find = ch[0]=='W';
    for(int i=1;i<n;i++){
        if(ch[i]=='W'){
            find = true;
            if(ch[i-1]=='W')score+=2;
            else score++;
        }
    }
    if(!find){
        cout<<max(0LL, 2LL * k - 1) << "\n";
        return;
    }
    if(k==0){
        cout<<score<<"\n";
        return;
    }
    bool ok1 = ch[0]=='L';
    bool ok2 = ch[n-1]=='L';
    int nb = 0 ;
    int yy = -1;
    int zz = -1;
    vector<int> vv;
    
    int i = 0;
    while (i < n) {
        if (ch[i] == 'L') {
            int j = i;
            while (j < n && ch[j] == 'L') j++;
            int len = j - i;
            if (i == 0) yy = len;
            else if (j == n) zz = len;
            else vv.push_back(len);
            i = j;
        } else {
            i++;
        }
    }

    sort(vv.begin(),vv.end());
    int pos = 0 ;

    while(k&&pos<vv.size()){
        //cout<<"pos = "<<pos<<" k = "<<k<<" vv[pos] = "<<vv[pos]<<" score = "<<score<<"\n";
        if(vv[pos]<=k){
            k-=vv[pos];
            score+=vv[pos]*2+1;
            pos++;
        }else{
            score+=k*2;
            k=0;
            break;
        }
    } 
    while(k){
        if(yy>0){
            if(k>=yy){
                score+=yy*2;
                k-=yy;
                yy = 0;
            }else{
                score+=k*2;
                k=0;
            }
        }
        if(zz>0){
            if(k>=zz){
                score+=zz*2;
                k-=zz;
                zz = 0;
            }else{
                score+=k*2;
                k=0;
            }
        }else break;
    } 
    
    cout<<score<<"\n";
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) { solve(); }
}