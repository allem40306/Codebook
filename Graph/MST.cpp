#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
 
#define LL long long
#define MAX 1e11
#define S 50050
using namespace std;
 
int n, m;
int sum;
 
typedef struct {
    int a, b, l;
} edge;
bool cmp(edge l, edge r) { return l.l < r.l; }
 
vector<edge> v;
 
typedef struct {
    int d;
    LL l;
} node;
 
vector<node> map[S];
 
int disjoint[S];
 
int root(int x) {
    if(disjoint[x] < 0) return x;
    else {
        disjoint[x] = root(disjoint[x]);
        return disjoint[x];
    } 
}
 
bool same(int a, int b) {
    return root(a) == root(b);
}
 
void connect(int a, int b) {
    // cout << "CONNECT " << a << " " << b << endl;
    int ra = root(a);
    int rb = root(b);
 
    disjoint[ra] += disjoint[rb];
    disjoint[rb] = ra;
}
 
void kruskal() {
    int remain = n - 1;
    for(auto i : v) {
        if(remain == 0) break;
 
        if(!same(i.a, i.b)) {
            connect(i.a, i.b);
 
            map[i.a].push_back((node){i.b, i.l});
            map[i.b].push_back((node){i.a, i.l});
 
            sum += i.l;
            remain--;
        }
    }
}
 
bool book[S];
 
void dfs(int start) {
    stack<int> st;
    st.push(start);
 
     
    memset(book, false, sizeof(book));
 
    while(!st.empty()) {
        int cur = st.top();
        // cout << cur << endl;
        st.pop();
 
        book[cur] = true;
 
        for(int i = 0; i < map[cur].size(); i++) {
            int next = map[cur][i].d;
            if(!book[next]) {
                st.push(next);
            }
        }
    }
}
 
void init() {
    memset(disjoint, -1, sizeof(disjoint));
    sum = 0;
}
 
bool check() {
    for(int i = 1; i <= n; i++)
        if(!book[i]) return false;
 
    return true;
}
 
int main() {
    init();
 
    cin >> n >> m;
 
    for(int i = 0; i < m; i++) {
        edge tmp;
        cin >> tmp.a >> tmp.b >> tmp.l;
 
        v.push_back(tmp);
    }
 
    sort(v.begin(), v.end(), cmp);
 
    kruskal();
    dfs(1);
     
    if(!check()) cout << -1 << endl;
    else cout << sum << endl;
 
    return 0;
}

