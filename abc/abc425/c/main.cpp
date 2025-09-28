#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  int n2 = n*2;
  vector<int> a2(n2);
  REP(i,n) cin >> a2[i];
  REP(i,n) a2[n+i] = a2[i];
  vector<ll> s(n2+1);
  REP(i,n2) s[i+1] = s[i]+a2[i];

  int p = 0;
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int c; cin >> c;
      p += c;
      p %= n;
    }
    if (t == 2) {
      int l,r; cin >> l >> r; l--; r--;
      cout << s[r+p+1] - s[l+p] << endl;
    }
  }
  return 0;
}