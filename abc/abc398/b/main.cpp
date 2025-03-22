#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  vector<int> b(14);
  REP(i,7) { int a; cin >> a; b[a]++; }
  vector<int> cnt(4);
  for(auto v: b) cnt[min(v,3)]++;
  bool ok = cnt[3] >= 2 || (cnt[3] == 1 && cnt[2] >= 1);
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
