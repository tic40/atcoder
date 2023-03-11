#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) { cin >> a[i]; a[i]--; }
  vector<bool> b(n);
  REP(i,n) if (!b[i]) b[a[i]] = true;
  vector<int> ans;
  REP(i,n) if (!b[i]) ans.push_back(i);
  cout << ans.size() << endl;
  for(int v: ans) cout << v+1 << " ";
  return 0;
}