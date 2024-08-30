#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

void solve1() {
  string s; cin >> s;
  int n = s.size();
  vector<int> x(n+1);
  REP(i,n) x[i+1] = x[i] ^ (1 << (s[i]-'0')); // mod 2 を取る

  map<int,int> mp;
  REP(i,n+1) mp[x[i]]++;

  ll ans = 0;
  for(auto [_,cnt]: mp) ans += (ll)cnt * (cnt-1) / 2; // cntから2つ選ぶ cnt C 2
  cout << ans << endl;
}

void solve2() {
  mt19937_64 rng(58); // 64bit 乱数生成
  const ll mod = (1LL<<61) - 1; // 素数

  string s; cin >> s;
  int n = s.size();

  vector<ll> h(10);
  // 各要素に足してランダムな値を割り当てる
  REP(i,10) h[i] = rng() % mod;

  // xor の累積和
  vector<ll> x(n+1);
  REP(i,n) x[i+1] = x[i] ^ h[s[i]-'0'];

  map<ll,int> mp;
  REP(i,n+1) mp[x[i]]++;

  ll ans = 0;
  for(auto [_,cnt]: mp) ans += (ll)cnt * (cnt-1) / 2; // cntから2つ選ぶ cnt C 2
  cout << ans << endl;
}

int main() {
  // solve1();
  solve2();
  return 0;
}