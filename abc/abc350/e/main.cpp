#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; int a,x,y;
  cin >> n >> a >> x >> y;

  unordered_map<ll,double> memo;
  memo[0] = 0;

  auto f = [&](auto self, ll now) -> double {
    if (memo.find(now) != memo.end()) return memo[now];

    // x 円払うケース
    double res1 = x + self(self,now/a);
    // y 円払うケース
    double res2 = (double)6 / 5 * y;
    for(int i = 2; i <= 6; i++) res2 += (double)1 / 5 * self(self,now/i);

    return memo[now] = min(res1,res2);
  };

  double ans = f(f,n);
  printf("%.10f\n",ans);
  return 0;
}