#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> cnt(m+1);
  REP(i,n) cnt[a[i]]++;
  REP(i,m) if (cnt[i+1] == 0) { cout << 0 << endl; return 0; }

  reverse(a.begin(),a.end());
  REP(i,n) {
    cnt[a[i]]--;
    if (cnt[a[i]] == 0) { cout << (i+1) << endl; break; }
  }
  return 0;
}