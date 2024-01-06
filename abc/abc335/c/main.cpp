#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

int main() {
  int n,q; cin >> n >> q;
  deque<P> deq;
  REP(i,n) deq.push_back({i+1,0});
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      char c; cin >> c;
      auto [x,y] = deq[0];
      if (c == 'U') deq.push_front({x,y+1});
      if (c == 'D') deq.push_front({x,y-1});
      if (c == 'L') deq.push_front({x-1,y});
      if (c == 'R') deq.push_front({x+1,y});
      deq.pop_back();
    } else {
      int v; cin >> v;
      v--;
      auto [x,y] = deq[v];
      cout << x << " " << y << endl;
    }
  }
  return 0;
}