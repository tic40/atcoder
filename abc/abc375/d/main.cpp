#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  string s; cin >> s;
  vector<int> l(26),r(26);
  for(auto c: s) r[c-'A']++;

  ll ans = 0;
  for(auto c: s) {
    r[c-'A']--;
    REP(i,26) ans += (ll)l[i]*r[i];
    l[c-'A']++;
  }
  cout << ans << endl;
  return 0;
}