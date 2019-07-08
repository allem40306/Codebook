#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N];
int curmax;
int app[N], cnt[N];

struct Query{
    int L, R, qid, bid;
    bool operator < (const Query&rhs) const {
        if(bid != rhs.bid)return bid < rhs.bid;
        return R < rhs.R;
    }
}q[N];

bool cmp(Query a,Query b){
    return a.L < b.L;
}

void add(int x){
    int now = ++app[x];
    cnt[now - 1]--;
    cnt[now]++;
    curmax=max(curmax, now);
}

void sub(int x){
    int now = --app[x];
    cnt[now + 1]--;
    cnt[now]++;
    if(!cnt[curmax])curmax--;
}

int main(){
    int n, Q;
    int ans[N];
    cin >> n >> Q;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int k=floor(sqrt(n/1.0));
    for(int i = 0;i < Q;i++){
        cin >> q[i].L >> q[i].R;
        q[i].qid = i;
    }
    sort(q, q + Q,cmp);
    for(int i = 0;i < Q;i++){
        q[i].bid = i / k;
    }
    sort(q, q + Q);
    for(int i=0, curL = 1, curR = 0;i < Q;i++){
        // cout<<i<<' '<<q[i].L<<' '<<q[i].R<<'\n';
        while(curR < q[i].R){
            curR++;
            add(a[curR]);
        }
        while(q[i].R < curR){
            sub(a[curR]);
            curR--;
        }
        while(curL < q[i].L){
            sub(a[curL]);
            curL++;
        }
        while(q[i].L < curL){
            curL--;
            add(a[curL]);
        }
        ans[q[i].qid] = curmax;
    }
    for(int i=0;i<Q;i++){
        cout<<ans[i]<<'\n';
    }
}