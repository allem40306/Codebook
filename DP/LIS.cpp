#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    while(cin>>n){
        vector<int>v;
        for(int i=0,x;i<n;i++){
            cin>>x;
            if(!v.size()||x>v.back())v.push_back(x);
            else *lower_bound(v.begin(), v.end(),x)=x;
        }
        cout<<v.size()<<'\n';
    }
}