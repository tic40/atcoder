#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]+a[i];

  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int x; cin >> x; x--;
      s[x+1] -= a[x];
      swap(a[x],a[x+1]);
      s[x+1] += a[x];
    }
    if (t == 2) {
      int l,r; cin >> l >> r; l--; r--;
      cout << s[r+1] - s[l] << endl;
    }
  }
  return 0;
}
