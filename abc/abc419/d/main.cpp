#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  string s,t; cin >> s >> t;
  vector<int> a(n+1);
  REP(i,m) {
    int l,r; cin >> l >> r;
    a[l-1]++; a[r]--;
  }
  REP(i,n) a[i+1] += a[i];
  REP(i,n) cout << (a[i]%2 ? t[i] : s[i]);
  return 0;
}