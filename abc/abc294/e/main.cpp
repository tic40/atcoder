#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

struct V { ll l,r,x; };

int main() {
  ll l; int n1,n2;
  cin >> l >> n1 >> n2;

  queue<V> v1,v2;
  ll pos = 0;
  REP(i,n1) {
    int a,b; cin >> a >> b;
    v1.push({pos,pos+b-1,a});
    pos += b;
  }
  pos = 0;
  REP(i,n2) {
    int a,b; cin >> a >> b;
    v2.push({pos,pos+b-1,a});
    pos += b;
  }

  auto pop = [&](queue<V> &v) {
    auto res = v.front(); v.pop();
    return res;
  };

  ll ans = 0;
  auto now1 = pop(v1);
  auto now2 = pop(v2);

  auto f = [&]() {
    if (now1.r <= now2.r) {
      if (now1.x == now2.x && now2.l <= now1.r) {
        ans += now1.r - max(now2.l, now1.l) + 1;
      }
      if (v1.size()) now1 = pop(v1);
    } else {
      if (now1.x == now2.x && now1.l <= now2.r) {
        ans += now2.r - max(now2.l, now1.l) + 1;
      }
      if (v2.size()) now2 = pop(v2);
    }
  };

  while(v1.size() || v2.size()) f();
  f();
  cout << ans << endl;
  return 0;
}
