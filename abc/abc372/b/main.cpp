#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

vector<int> convert_base(int n, int base=10) {
  if (n == 0) return { 0 };
  vector<int> a;
  while(n) {
    int m = abs(n%base);
    a.push_back(m);
    if (base < 0 && m) n--;
    n /= base;
  }
  return a;
}

int main() {
  int m; cin >> m;
  auto x = convert_base(m,3);
  vector<int> ans;
  REP(i,(int)x.size()) {
    REP(j,x[i]) ans.push_back(i);
  }

  cout << ans.size() << endl;
  for(auto v: ans) cout << v << " ";
  return 0;
}