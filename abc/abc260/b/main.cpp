#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main() {
  int n,x,y,z;
  cin >> n >> x >> y >> z;

  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  vector<P> px(n),py(n),pxy(n);
  REP(i,n) px[i] = {a[i],n-i};
  REP(i,n) py[i] = {b[i],n-i};
  REP(i,n) pxy[i] = {a[i]+b[i],n-i};

  sort(px.rbegin(),px.rend());
  sort(py.rbegin(),py.rend());
  sort(pxy.rbegin(),pxy.rend());
  set<int> ans;

  REP(i,x) ans.insert(n-px[i].second);
  REP(i,n) {
    if ((int)ans.size() - x == y) break;
    ans.insert(n-py[i].second);
  }

  REP(i,n) {
    if ((int)ans.size() - (x+y) == z) break;
    ans.insert(n-pxy[i].second);
  }

  for(int v: ans) cout << v+1 << endl;
  return 0;
}