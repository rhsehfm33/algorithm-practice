// code by codeforces ETO

#include<bits/stdc++.h>
#define int __int128
using namespace std;
int read(){
	int w=0,h=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')h=-h;ch=getchar();}
	while(ch>='0'&&ch<='9'){w=w*10+ch-'0';ch=getchar();}
	return w*h;
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void writeln(int x){write(x);puts("");}
void writech(int x){write(x);putchar(' ');}
const int mod=1e9+7;
int calc(int x){
	if(x<4)return 0;
	int ans=0;
	for(int i=2;i<=60;i++){
		int l=(1ll<<i),r=min(x,(int)(1ll<<(i+1))-1);
		//writech(l);writeln(r);
		if(l>x)break;
		for(int p=1,bs=i;p<=60;p++,bs=bs*i){
			if(bs*i<l)continue;
		    if(bs>r)break;
			int L=max(l,bs),R=min(r,bs*i-1);
			if(L<=R)(ans+=(R-L+1)%mod*p)%=mod;
			//writech(i);writech(p);writech(bs);writech(L);writeln(R);
			if(bs*p>1000000000000000000)break;
		}
	}
	return ans;
}
void solve(){int l=read(),r=read();writeln((calc(r)-calc(l-1)+mod)%mod);}
signed main(){
	int T=read();while(T--)solve();
	return 0;
}

