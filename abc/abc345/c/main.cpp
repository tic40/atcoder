#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  string s; cin >> s;
  int n = s.size();
  vector<int> m(26);
  REP(i,n) { m[s[i]-'a']++; }

  ll ans = 0;
  REP(i,n) {
    int cnt = m[s[i]-'a'] - 1;
    ans += n-cnt-1;
  }
  ans /= 2;
  REP(i,26) if (m[i] >= 2) { ans++; break; }
  cout << ans << endl;
  return 0;
}