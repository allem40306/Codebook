int bulit(int L,int R,int x) {
	if(L==R)return heap[x - 1]=arr[L];
	int M=(L+R)>>1;
	return heap[x-1]=bulit(L, M, (x << 1))+bulit(M + 1, R, (x << 1) + 1);
}
void modify(int L,int R,int x,int a,int b,int mo) {
    if(b<L||R<a)return;
	if(L==R){heap[x-1]+=mo; return;}
	int M=(L+R)>>1;
	modify(L,M,(x<<1),a,b,mo);
	modify(M+1,R,(x<<1)+1,a,b,mo);
	heap[x - 1] += mo;
	return;
}
int quest(int L,int R,int x,int a,int b) {
    if(b<L||R<a)return 0;
	if(a<=L&&R<=b)return heap[x - 1];
	int M=(L+R)>>1;
	return quest(L,M,(x<<1),a,b)+quest(M+1,R,(x<<1)+1,a,b);
}