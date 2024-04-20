#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; int a,x,y;
  cin >> n >> a >> x >> y;

  // メモ化再帰解
  auto solve = [&]() {
    map<int,double> memo;
    memo[0] = 0;
    auto f = [&](auto self, ll now) -> double {
      if (memo.find(now) != memo.end()) return memo[now];

      double res1 = 6.0 / 5.0 * y;
      for(int i = 2; i <= 6; i++) res1 += (double)1/5 * self(self, now/i);
      double res2 = (double)x + self(self, now/a);

      return memo[now] = min(res1,res2);
    };
    return f(f,n);
  };

  double ans = solve();
  printf("%.10f\n", ans);
  return 0;
}