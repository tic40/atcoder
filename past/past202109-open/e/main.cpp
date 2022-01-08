#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

struct Shirt {
  int cost, color;
  bool operator<(const Shirt& o) const { // costで順序定義
    return cost < o.cost;
  }
};

int n,k;
vector<Shirt> s;

int main() {
  cin >> n >> k;
  vector<int> c(n),p(n);
  REP(i,n) cin >> c[i];
  REP(i,n) cin >> p[i];
  REP(i,n) s.push_back(Shirt{ p[i], c[i] });
  sort(s.begin(), s.end());
  map<int,int> has;

  REP(i,n) {
    auto [cost, color] = s[i];
    if (has[ color ]) continue;
    has[color] = cost;
    if ((int)has.size() == k) {
      ll ans = 0;
      for(auto v: has) ans += v.second;
      cout << ans << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}