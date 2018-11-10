#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
 
#define S 50050
 
using namespace std;
 
vector<int> map[S];
int visit[S];
bool valid;
 
void check(int start) {
    stack<int> st;
    st.push(start);
    visit[start] = 1;
 
    while(valid && !st.empty()) {
        int cur = st.top();
        st.pop();
 
        for(int i = 0; i < map[cur].size(); i++) {
            int next = map[cur][i];
 
            if(visit[next] == -1) {
                st.push(next);
 
                if(visit[cur] == 1) visit[next] = 2;
                else visit[next] = 1;
            }
            else if(visit[cur] == visit[next]) valid = false;
        }
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
 
        map[a].push_back(b);
        map[b].push_back(a);
    }
     
    // -1 : not visit, 1 : tsudere, 2 : proud
    memset(visit, -1, sizeof(visit));
    valid = true;
 
    for(int i = 1; i <= n; i++) {
        if(valid && visit[i] == -1) {
            check(i);
        }
    }
 
    if(valid) cout << "yes" << endl;
    else cout << "no" << endl;
 
    return 0;
}