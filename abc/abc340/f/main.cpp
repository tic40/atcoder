#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

// 拡張ユークリッドの互除法
// 返り値: a と b の最大公約数
// ax + by = gcd(a,b) を満たす (x,y) が格納される
ll extgcd(ll a, ll b, ll& x, ll& y) {
  if (b == 0) { x = 1; y = 0; return a; }
  auto d = extgcd(b,a-b*(a/b),y,x); // extgcd(b,a%b,y,x);
  y -= a/b * x;
  return d;
}

int main() {
  ll x,y; cin >> x >> y;
  ll b,a;
  // ベクトルの外積より |ax - by| = 2 となる a,b を求めたい
  // 拡張ユークリッドの互除法で ax + by = gcd(a,b) を求める
  // gcd(a,b) が 3 以上の場合は |ax - by| も gcd(a,b) 以上の倍数となるため
  // 答えは存在しない
  auto g = abs(extgcd(x,y,b,a));
  if (g > 2) { cout << -1 << endl; return 0; }

  a = -a;
  if (g == 1) { a *= 2; b *= 2; }
  cout << a << " " << b << endl;
  return 0;
}