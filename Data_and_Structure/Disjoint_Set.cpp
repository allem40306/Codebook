void init(){for (int i = 0; i < N; i++)p[i] = i;}
int find(int x){return x == p[x] ? x : p[x]=find(p[x]);}
void Union(int a, int b){p[find(a)] = find(b);}