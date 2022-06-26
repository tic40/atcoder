#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

vector<ll> a(51); // a[i]: レベルiバーガーの層の総数
vector<ll> p(51); // p[i]: レベルiバーガーのパティの総数

ll f(ll n, ll x) {
  if (n == 0) return 0 < x ? 1 : 0;

  // x <= 端のバン1枚 + レベルn-1バーガーの総数
  if (x <= 1+a[n-1]) {
    return f(n-1, x-1);
  // x > 端のバン1枚 + レベルn-1バーガーの総数
  } else {
    // 左側 + 右側(中央のパティ + レベルn-1バーガーのパティの総数)
    return f(n-1, x-2-a[n-1]) + 1 + p[n-1];
  }
}

int main() {
  int n; ll x;
  cin >> n >> x;

  a[0] = p[0] = 1;
  REP(i,n) {
    a[i+1] = a[i]*2+3;
    p[i+1] = p[i]*2+1;
  }

  cout << f(n,x) << endl;
  return 0;
}