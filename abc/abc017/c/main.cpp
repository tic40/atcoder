#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  ll n,m,sum=0,ans=0;
  cin>>n>>m;
  ll l,r,s,a[m+2];
  REP(i, m+2) a[i] = 0;
  REP(i, n) {
    cin>>l>>r>>s;
    a[l]+=s; a[r+1]-=s; sum+=s;
  }

  ll mini = LONG_MAX;
  for(int i = 1; i < m+1; i++) {
    a[i]+=a[i-1];
    mini=min(mini, a[i]);
  }
  cout << sum-mini << endl;
}