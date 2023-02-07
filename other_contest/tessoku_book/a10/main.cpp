#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> s(n+1),rs(n+1);
  REP(i,n) s[i+1] = max(s[i],a[i]);
  reverse(a.begin(),a.end());
  REP(i,n) rs[i+1] = max(rs[i],a[i]);

  int d; cin >> d;
  REP(_,d) {
    int l,r; cin >> l >> r;
    l--; r--;
    cout << max(s[l],rs[n-r-1]) << endl;
  }
  return 0;
}