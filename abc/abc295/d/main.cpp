#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  string s; cin >> s;
  int n = s.size();
  vector<int> x(n+1);
  REP(i,n) x[i+1] = x[i] ^ (1 << (s[i]-'0')); // mod 2 を取る

  map<int,int> mp;
  REP(i,n+1) mp[x[i]]++;

  ll ans = 0;
  for(auto [_,cnt]: mp) ans += (ll)cnt * (cnt-1) / 2; // cntから2つ選ぶ cnt C 2
  cout << ans << endl;
  return 0;
}