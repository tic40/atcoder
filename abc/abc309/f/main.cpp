#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

// Coodinate Compression
template<typename T=int>
struct CC {
  bool initialized;
  vector<T> xs;
  CC(): initialized(false) {}
  void add(T x) { xs.push_back(x);}
  void init() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    initialized = true;
  }
  int operator()(T x) {
    if (!initialized) init();
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }
  T operator[](int i) {
    if (!initialized) init();
    return xs[i];
  }
  int size() {
    if (!initialized) init();
    return xs.size();
  }
};

int op(int a, int b) { return min(a, b); }
int e() { return INF; }

int main() {
  int n; cin >> n;
  map<int,vector<P>> ps;
  CC bs; // 座標圧縮
  REP(i,n) {
    vector<int> a(3);
    REP(j,3) cin >> a[j];
    sort(a.begin(),a.end());
    ps[a[0]].emplace_back(a[1],a[2]);
    bs.add(a[1]);
  }

  // RMQ
  segtree<int,op,e> t(bs.size());
  // a[0] が小さいものから見ていく
  for(auto [_,bc]: ps) {
    for(auto [b,c]: bc) {
      b = bs(b);
      // 0 - b で最も小さい値が < c なら ok
      if (t.prod(0,b) < c) { cout << "Yes" << endl; return 0; }
    }
    for(auto [b,c]: bc) {
      b = bs(b);
      // b　の c の最小をセット
      t.set(b, min(c, t.get(b)));
    }
  }

  cout << "No" << endl;
  return 0;
}