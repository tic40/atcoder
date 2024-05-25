#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<P> c;
  REP(i,n) { int a; cin >> a; c.emplace_back(a,0); }
  REP(i,m) { int a; cin >> a; c.emplace_back(a,1); }
  sort(c.begin(),c.end());
  int ans = 0;
  REP(i,n+m-1) ans |= c[i].second == c[i+1].second && c[i].second == 0;
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}