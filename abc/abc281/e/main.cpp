#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

struct DS {
  int k; ll sum;
  multiset<int> ls,rs;
  DS(int k=0): k(k), sum(0) {}
  void ladd(int x) {
    sum += x;
    ls.insert(x);
  }
  void lerase(multiset<int>::iterator it) {
    sum -= *it;
    ls.erase(it);
  }
  void add(int x) {
    ladd(x);
    if ((int)ls.size() <= k) return;
    auto it = ls.end();
    it--;
    rs.insert(*it);
    lerase(it);
  }
  void erase(int x) {
    if (*ls.rbegin() < x) {
      rs.erase(rs.find(x));
    } else {
      lerase(ls.find(x));
      auto it = rs.begin();
      ladd(*it);
      rs.erase(it);
    }
  }
};

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  DS d(k);

  REP(i,m) d.add(a[i]);
  cout << d.sum << endl;

  REP(i,n-m) {
    d.add(a[i+m]);
    d.erase(a[i]);
    cout << d.sum << endl;
  }
  return 0;
}