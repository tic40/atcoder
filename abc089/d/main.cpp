#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0;i<n;i++)
int mx=90001;
int a,h,w,d,q,l,r,y[90001],x[90001],s[90001];
int main() {
	cin>>h>>w>>d;
	REP(i,h)REP(j,w) { cin>>a; y[a]=i,x[a]=j; }
  REP(i,h*w-d+1) s[i+d]=s[i]+abs(x[i+d]-x[i])+abs(y[i+d]-y[i]);
	cin >> q;
  REP(i,q) { cin>>l>>r; cout << s[r]-s[l] << endl; }
}