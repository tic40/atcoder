#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n),b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];

  fenwick_tree<ll> fw(n+1); // 累積和
  REP(i,m) {
    ll t = fw.sum(0,b[i]+1);
    ll now = a[b[i]] + t;
    ll r = now / n; // 何周するか
    ll rem = now % n; // r周した余り分

    a[b[i]] = 0;
    fw.add(b[i],-t);
    fw.add(b[i]+1,t);
    fw.add(0,r);

    if (b[i] + rem < n) {
      fw.add(b[i]+1,1);
      fw.add(b[i]+rem+1,-1);
    } else {
      fw.add(b[i]+1,1);
      fw.add(0,1);
      fw.add((rem+b[i])%n+1, -1);
    }
  }

  REP(i,n) cout << (ll)a[i] + fw.sum(0,i+1) << " ";
  return 0;
}