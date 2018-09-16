void print_lis(int v){
    if(pre[v])print_lis(pre[v]);
    cout<<a[v]<<'\n';
}
int main(){
    for(ai=0;cin>>a[++ai];);
    pre[1]=0; b[bi=1]=1;
    for(int i=2;i<=ai;i++){
        if(a[i]>a[b[bi]]){
            b[++bi]=i;
            pre[i]=b[bi-1];
        }else{
            int id=int(lower_bound(b,b+bi,a[i])-b);
            b[id]=i;
            pre[i]=b[id-1];
        }
    }
    cout<<bi<<"\n-\n";
    print_lis(b[bi]);
}