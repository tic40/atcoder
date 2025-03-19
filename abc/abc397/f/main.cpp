#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int op(int x, int y) { return max(x,y); }
int e() { return 0; }
int mapping(int f, int x) { return x+f; }
int composition(int f, int g) { return f+g; }
int id() { return 0; }

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> pre(n);
  {
    vector<int> pos(n+1,-1);
    REP(i,n) {
      pre[i] = pos[a[i]];
      pos[a[i]] = i;
    }
  }

  using seg = lazy_segtree<int,op,e,int,mapping,composition,id>;
  vector<seg> t(3,seg(n));

  REP(i,n) {
    REP(j,2) {
      int now = t[j].all_prod();
      t[j+1].set(i,now);
    }
    REP(j,3) {
      t[j].apply(pre[i]+1,i+1,1);
    }
  }
  cout << t[2].all_prod() << endl;
  return 0;
}
