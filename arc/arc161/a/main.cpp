#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());

  int l = 0, r = n/2+1;
  vector<int> ans;
  REP(i,n) {
    if (i%2 == 0) { ans.push_back(a[l]); l++; }
    else { ans.push_back(a[r]); r++; }
  }
  int ok = 1;
  for(int i = 1; i < n; i+=2) {
    ok &= ans[i-1] < ans[i] && ans[i] > ans[i+1];
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}