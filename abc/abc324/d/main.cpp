#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> cnt(10);
  REP(i,n) { cnt[s[i]-'0']++; }

  int ans = 0;
  REP(i,3162278) {
    ll x = (ll)i*i;
    vector<int> now(10);
    while(x) { now[x % 10]++; x /= 10; }
    bool ok = true;
    for(int j = 1; j <= 9; j++) if (cnt[j] != now[j]) ok = false;
    ok = ok && cnt[0] >= now[0];
    if (ok) ans++;
  }

  cout << ans << endl;
  return 0;
}