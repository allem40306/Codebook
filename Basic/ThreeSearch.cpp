#include <bits/stdc++.h>
using namespace std;
#define N 20
int t,n,i,j;
struct happy{
	double a,b,c;
}h[N];
double f2(double x,double a,double b,double c){return a*(x-b)*(x-b)+c;}
double f(double x){
	double ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,f2(x,h[i].a,h[i].b,h[i].c));
//		cout<<ans<<'\n'; 
	}
	return ans;
}
int main(){
	cin.tie(NULL);
	for(cin>>t;i<t;i++){
		for(cin>>n,j=0;j<n;j++)
			cin>>h[j].a>>h[j].b>>h[j].c;
		double L=0,R=300,M,MM;
		while(R-L>1e-9){
			M=L+(R-L)/3;
			MM=(M+R)/2;
//			cout<<L<<' '<<M<<' '<<MM<<' '<<R<<'\n';
			if(f(M)>f(MM))L=M;
			else R=MM;
		}
		cout<<fixed<<setprecision(5)<<f(L)<<'\n';
	}
}