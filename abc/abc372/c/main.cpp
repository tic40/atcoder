#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  string s; cin >> s;

  auto f = [&](int idx) -> int {
    return (idx-1 < 0 || idx+1 >= n) ? 0 : (s[idx-1] == 'A' && s[idx] == 'B' && s[idx+1] == 'C');
  };

  int ans = 0;
  for(int i = 1; i < n-1; i++) ans += f(i);
  REP(_,q) {
    int x; char c; cin >> x >> c; x--;
    for(int i = x-1; i <= x+1; i++) ans -= f(i);
    s[x] = c;
    for(int i = x-1; i <= x+1; i++) ans += f(i);

    cout << ans << endl;
  }
  return 0;
}