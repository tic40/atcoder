#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

struct Mex {
  private:
    int _n; // あり得る mex 値の上限 0 - _n
    vector<int> cnt; // 要素 0 - _n のカウンタ
    set<int> st; // mex 管理用
  public:
    Mex(int n): _n(n), cnt(n+1) {
      for(int i = 0; i <= n; i++) st.insert(i);
    }

  // 要素を追加
  void add(long long x) {
    if (x >= _n) return;
    cnt[x]++;
    if (cnt[x] == 1) st.erase(x);
  }

  // 要素を削除
  void del(long long x) {
    if (x >= _n) return;
    cnt[x]--;
    if (cnt[x] == 0) st.insert(x);
  }

  int get() {
    return *st.begin();
  }

  void debug() {
    for(auto v: st) cout << v << endl;
  }
};

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  Mex mex(n);
  REP(i,n) mex.add(a[i]);

  REP(_,q) {
    int i,x; cin >> i >> x;
    i--;
    mex.del(a[i]);
    mex.add(x);
    a[i] = x;
    cout << mex.get() << endl;
  }
  return 0;
}