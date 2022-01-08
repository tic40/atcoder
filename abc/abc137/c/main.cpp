#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n;
  ll ans = 0;
  cin >> n;
  map<string, ll> s;
  string str;
  REP(i, n) {
    cin >> str;
    sort(str.begin(), str.end());
    s[str] = s[str] ? s[str]+1 : 1;
  }
  map<string, ll>::iterator itr;
  for (itr = s.begin(); itr != s.end(); ++itr) {
    if (itr->second > 1) {
      ans += itr->second * (itr->second - 1) / 2;
    }
  }
  cout << ans << endl;
}