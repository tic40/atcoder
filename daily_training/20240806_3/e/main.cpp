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
  vector<int> a(n);
  REP(i,n) a[i] = i;

  vector<int> pos(n);
  REP(i,n) pos[i] = i;
  REP(_,q) {
    int x; cin >> x; x--;
    int idx = pos[x];
    int ni = idx == n-1 ? idx-1 : idx+1;
    swap(a[idx], a[ni]);
    pos[x] = ni;
    pos[a[idx]] = idx;
  }

  for(auto v: a) cout << v+1 << " ";
  return 0;
}