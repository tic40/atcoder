#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int len = s.size();
  int ans = 0;
  REP(i, len/2) {
    if (s[i] == s[len-i-1]) continue;
    ans++;
  }
  cout << ans << endl;
}