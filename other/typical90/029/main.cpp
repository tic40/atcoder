#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;

struct LazySegmentTree {
private:
  int n;
  vector<int> node, lazy;
  vector<bool> lazyFlag;

public:
  LazySegmentTree(vector<int> v) {
    // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
    // セグメント木全体で必要なノード数は 2n-1 個である
    int sz = (int)v.size();

    n = 1;
    while(n < sz) n *= 2;
    node.resize(2*n-1, 0);
    lazy.resize(2*n-1, INF);
    lazyFlag.resize(2*n-1, false);

    // 最下段に値を入れたあとに、下の段から順番に値を入れる
    // 値を入れるには、自分の子の 2 値を参照すれば良い
    for (int i=0; i < sz; i++) node[i+n-1] = v[i];
    for (int i=n-2; 0 <= i; i--) node[i] = max(node[i*2+1], node[i*2+2]);
  }

  void lazyEvaluate(int k, int l, int r) {
    if (!lazyFlag[k]) return;

    node[k] = lazy[k];
    if (1 < r - l) {
      lazy[k*2+1] = lazy[k*2+2] = lazy[k];
      lazyFlag[k*2+1] = true;
      lazyFlag[k*2+2] = true;
    }
    lazyFlag[k] = false;
  }

  void update(
    int a,
    int b,
    int x,
    int k=0,
    int l=0,
    int r=-1
  ) {

    // 最下段のノードにアクセス
    if (r < 0) r = n;
    lazyEvaluate(k, l, r);

    if (b <= l || r <= a) return;

    if (a <= l && r <= b) {
      lazy[k] = x;
      lazyFlag[k] = true;
      lazyEvaluate(k, l, r);
    } else {
      update(a, b, x, 2*k+1, l, (l+r)/2);
      update(a, b, x, 2*k+2, (l+r)/2, r);

      // 最大値を返す
      node[k] = max(node[2*k+1], node[2*k+2]);
    }
  }

  // 要求区間 [a, b) 中の要素の最大値 l <= x < r
  // k := 自分がいるノードのインデックス
  int find(
    int a,
    int b,
    int k=0,
    int l=0,
    int r=-1
  ) {
    // 最初に呼び出されたときの対象区間は [0, n)
    if (r < 0) r = n;

    lazyEvaluate(k, l, r);

    // 要求区間と対象区間が交わらないときに返す値
    if (b <= l || r <= a) return 0;

    // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
    if (a <= l && r <= b) return node[k];

    // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
    // 左側の子を vl ・ 右側の子を vr としている
    // 新しい対象区間は、現在の対象区間を半分に割ったもの
    int vl = find(a, b, 2*k+1, l, (l+r)/2);
    int vr = find(a, b, 2*k+2, (l+r)/2, r);

    // 最大値
    return max(vl, vr);
  }
};

int main() {
  int w,n;
  cin >> w >> n;

  LazySegmentTree st(vector<int> (w, 0));
  REP(i,n) {
    int l,r;
    cin >> l >> r;
    l--; r--;
    int height = st.find(l, r+1) + 1;
    st.update(l, r+1, height);

    cout << height << endl;
  }
  return 0;
}