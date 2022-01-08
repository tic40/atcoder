#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

template <typename T>
struct fenwick_tree {
  int _n; // 配列の要素数
  vector<T> data; // データの格納先
  fenwick_tree() : _n(0) {}
  fenwick_tree(int n) : _n(n), data(n) {}

  void add(int p, T x) {
    assert(0 <= p && p < _n);
    p++;
    while (p <= _n) {
      data[p - 1] += x;
      p += p & -p;
    }
  }

  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return sum(r) - sum(l);
  }

  private:
    T sum(int r) {
      T s(0);
      while (0 < r) {
        s += data[r - 1];
        r -= r & -r;
      }
      return s;
    }
};

int n,q;
vector<int> t,k;

void solve() {
  int n2 = 2*n;
  // 数列aとそれを逆順にしたb
  vector<int> a(n2),b(n2);
  REP(i,n2) a[i] = i+1;
  REP(i,n2) b[i] = n2-i;

  fenwick_tree<int> bit(n2+1);

  REP(i,q) {
    if (t[i] == 1) {
      int v = bit.sum(0,k[i]+1);
      cout << (v%2==0 ? a[k[i]] : b[k[i]]) << endl;
    } else {
      int l = n-(k[i]+1), r = n+k[i]+1;
      bit.add(l,1);
      bit.add(r,-1);
    }
  }
  return;
}

int main() {
  cin >> n >> q;
  t.resize(q);
  k.resize(q);
  REP(i,q) {
    cin >> t[i] >> k[i];
    k[i]--;
  }

  solve();
  return 0;
}