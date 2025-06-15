#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,l; cin >> n >> l;
  map<int,int> mp;
  int now = 0;
  mp[now] = 1;
  REP(i,n-1) {
    int d; cin >> d;
    now += d; now %= l;
    mp[now]++;
  }

  if (l%3 != 0) { cout << 0 << endl; return 0; }

  ll ans = 0;
  for(auto [a,cnt]: mp) {
    int b = a + l/3;
    int c = b + l/3;
    if (mp.count(b) && mp.count(c)) ans += (ll)cnt * mp[b] * mp[c];
  }
  cout << ans << endl;
  return 0;
}