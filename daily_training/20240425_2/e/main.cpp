#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n),pos(n);
  iota(a.begin(),a.end(),0);
  iota(pos.begin(),pos.end(),0);

  REP(i,q) {
    int x; cin >> x;
    x--;
    int idx = pos[x];
    int nidx = (idx == n-1) ? idx-1 : idx+1;

    swap(a[idx],a[nidx]);
    swap(pos[a[idx]],pos[a[nidx]]);
  }
  for(auto v: a) cout << v+1 << " ";
  return 0;
}