#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
using ll = long long;

// a[i]: レベルiバーガーの層の総数
// p[i]: レベルiバーガーのパティの総数
vector<ll> a(51),p(51);

// n: レベルnバーガー, x: 下からx層
ll f(ll n, ll x) {
  if (n == 0) {
    // レベル0バーガー
    return 0 < x ? 1 : 0;
  } else if (x <= 1+a[n-1]) {
    // 一番下のバン + レベルn-1バーガーの層以下
    return f(n-1, x-1);
  } else {
    // 一番下のバン + レベルn-1バーガーの層より大きい
    return p[n-1] + 1 + f(n-1, x-2-a[n-1]);
  }
}

int main() {
  ll n,x;
  cin >> n >> x;

  a[0] = p[0] = 1;
  REP(i,n) {
    a[i+1] = a[i]*2+3;
    p[i+1] = p[i]*2+1;
  }

  cout << f(n,x) << endl;
  return 0;
}