#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  string s; cin >> s;
  int n = s.size();

  ll ans = 0;
  REP(i,n) {
    if (s[i] == 'D') {
      ans += i;
      ans += max(0, n-i-1)*2;
    } else {
      ans += i*2;
      ans += max(0, n-i-1);
    }
  }

  cout << ans << endl;
  return 0;
}