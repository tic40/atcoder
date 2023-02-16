#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector s(k,vector<ll>(n+1));
  REP(i,n) s[i%k][i+1] = a[i];
  REP(i,k) REP(j,n) s[i][j+1] += s[i][j];

  int q; cin >> q;
  REP(_,q) {
    int l,r; cin >> l >> r;
    l--; // 半開区間. 左は含む、右は含まない
    vector<ll> ns(k);
    REP(i,k) ns[i] = s[i][r] - s[i][l];
    bool ok = true;
    REP(i,k-1) if (ns[i] != ns[i+1]) ok = false;
    cout << (ok ? "Yes" : "No") << endl;
  }
  return 0;
}