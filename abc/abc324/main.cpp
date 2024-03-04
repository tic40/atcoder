#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
template<class T> void chmax(T& a, T b) { a = max(a,b);}

struct Edge {
  int to,b,c;
  Edge(int to, int b, int c): to(to),b(b),c(c) {}
};

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<Edge>());
  REP(i,m) {
    int u,v,b,c; cin >> u >> v >> b >> c;
    u--; v--;
    g[u].emplace_back(v,b,c);
  }

  // 1 -> N のパスで　美しさの総和をコストの総和で割った値が X 以上のものが存在 するか?
  auto f = [&](double x) -> bool {
    const double INF = 1e18;
    vector<double> dp(n,-INF);
    dp[0] = 0;
    REP(i,n) {
      for(auto e: g[i]) chmax(dp[e.to], dp[i]+e.b-e.c*x);
    }
    return dp[n-1] >= 0;
  };

  double ok = 0, ng = 1e4;
  // 答えを二分探索
  REP(_,50) {
    double mid = (ok+ng)/2;
    if (f(mid)) ok = mid;
    else ng = mid;
  }
  printf("%.10f\n",ok);
  return 0;
}