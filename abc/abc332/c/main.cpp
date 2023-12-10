#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  string s; cin >> s;
  s += '0';

  vector<int> t(2);
  int ans = 0;
  auto f = [&]() {
    int now = max(0,t[0] - m) + t[1];
    ans = max(ans, now);
    t[0] = 0; t[1] = 0;
  };

  for(auto c: s) {
    if (c == '0') f();
    if (c == '1') t[0]++;
    if (c == '2') t[1]++;
  }

  cout << ans << endl;
  return 0;
}