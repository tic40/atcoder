#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n),b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];
  vector<P> c(n+m);
  REP(i,n) c[i] = {a[i],i};
  REP(i,m) c[i+n] = {b[i],i+n};
  sort(c.begin(),c.end());

  vector<int> ansa(n);
  vector<int> ansb(m);
  REP(i,n+m) {
    auto [_,id] = c[i];
    if (id < n) ansa[id] = i;
    else ansb[id-n] = i;
  }
  for(auto v: ansa) cout << v+1 << " ";
  cout << endl;
  for(auto v: ansb) cout << v+1 << " ";
  return 0;
}