#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){
	int cash, n;
	int c[100], f[100005];
	int i, j, k;
	int num, cost, d;
	
	while(scanf("%d",&cash)!=EOF){
		cin>>n;
		d = 1;
		for (i=1;i<=n;i++){
			j=1;
			cin>>num>>cost;
			while(j<=num){
				c[d++] = j*cost;
				num-=j;
				j*=2;
			}
			if (num>0){
				c[d++] = num*cost;
			}
		}
		memset(f,0,sizeof(f));
		for (i=1;i<=d-1;i++){
			if (cash>=c[i]){
				for (k=cash;k>=c[i];k--)
					f[k] = (f[k] > (f[k-c[i]]+c[i]) )? f[k]:(f[k-c[i]]+c[i]);
			}
		
		}
		cout<<f[cash]<<endl;
	}
	return 0;
}