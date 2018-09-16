vector<int>v[N],bcc[N];//clear
LL dep[N],low[N],bccno[N],time_cnt,bcc_cnt;//set dep low -1 else 0
bitset<N>is_AP;//0
struct Edge{int s,t;};
stack<Edge>st;//clear
int dfs(int s,int fa){
    int child=0;
    dep[s]=low[s]=time_cnt++;
    for(auto t:v[s]){
        Edge e=(Edge){s,t};
        if(dep[t]==-1){
            st.push(e);
            child++;
            dfs(t,s);
            low[s]=min(low[s],low[t]);
            if(dep[s]<=low[t]){
                is_AP[s]=1;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                while(1){
                    Edge x=st.top(); st.pop();
                    if(bccno[x.s]!=bcc_cnt){
                        bcc[bcc_cnt].push_back(x.s);
                        bccno[x.s]=bcc_cnt;
                    }
                    if(bccno[x.t]!=bcc_cnt){
                        bcc[bcc_cnt].push_back(x.t);
                        bccno[x.t]=bcc_cnt;
                    }
                    if(x.s==s&&x.t==t)break;
                }
            }
        }else if(low[s]>dep[t]){
            st.push(e);
            low[s]=dep[t];
        }
    }
    if(fa<0&&child==1)is_AP[s]=0;
    return low[s];
}