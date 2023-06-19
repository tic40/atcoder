#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k,q; cin >> n >> k >> q;
  vector<int> a(n);
  multiset<int> s,t;
  REP(i,n) i < k ? s.insert(0) : t.insert(0);
  ll ans = 0;

  auto add = [&](int x) {
    s.insert(x); // s に x を追加する
    ans += x;
    int y = *s.begin();
    s.erase(s.find(y)); // s の最も小さい値を削除
    ans -= y;
    t.insert(y); // t に s から削除した最も小さい値を追加
  };
  auto del = [&](int x) {
    if (s.find(x) == s.end()) {
      t.erase(t.find(x)); // s に x が存在しなかったら t から削除する
    } else {
      s.erase(s.find(x)); // s から x を削除
      ans -= x;
      int y = *t.rbegin();
      t.erase(t.find(y)); // t から最大の値を削除
      s.insert(y); // s に t の最大の値を追加
      ans += y;
    }
  };

  REP(_,q) {
    int x,y; cin >> x >> y;
    x--;
    add(y);
    del(a[x]);
    a[x] = y;
    cout << ans << endl;
  }

  return 0;
}