#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  auto b = a;
  sort(b.begin(), b.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());

  vector<int> ans(n);
  REP(i,n) {
    auto idx = upper_bound(b.begin(),b.end(),a[i]) - b.begin();
    ans[b.size()-idx]++;
  }
  for(auto v: ans) cout << v << endl;
  return 0;
}
