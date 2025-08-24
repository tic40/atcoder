#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  ll tot = 0;
  REP(i,n) tot += min(a[i],b[i]);
  REP(_,q) {
    char c; cin >> c;
    int x,v; cin >> x >> v; x--;
    tot -= min(a[x],b[x]);
    if (c == 'A') a[x] = v;
    else b[x] = v;
    tot += min(a[x],b[x]);
    cout << tot << endl;
  }
  return 0;
}