#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> l(n);
  REP(i,n) cin >> l[i];

  int ans = n-1;
  auto f = [&]() -> void {
    for(auto v: l) {
      if (v == 1) break;
      ans--;
    }
  };
  f();
  reverse(l.begin(),l.end());
  f();
  cout << max(0,ans) << endl;
  return 0;
}