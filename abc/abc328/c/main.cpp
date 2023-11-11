#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  string s; cin >> s;

  vector<int> t(n);
  REP(i,n-1) if (s[i] == s[i+1]) t[i] = 1;
  vector<int> sum(n+1);
  REP(i,n) { sum[i+1] = sum[i]+t[i]; }

  REP(i,q) {
    int l,r; cin >> l >> r;
    l--; r--;
    cout << sum[r] - sum[l] << endl;
  }
  return 0;
}