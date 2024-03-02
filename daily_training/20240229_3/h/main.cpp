#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

struct Event {
  ll from, to, v; int i;
  Event(ll from = -1, ll to = -1, ll v = -1, int i = 0): from(from),to(to),v(v),i(i) {}
  bool operator<(const Event& o) const { return from < o.from; }
  bool operator>(const Event& o) const { return from >= o.from; }
};

int main() {
  ll l,n1,n2; cin >> l >> n1 >> n2;
  priority_queue<Event, vector<Event>, greater<Event>> q;
  auto in = [&](int i, int n) -> void {
    ll now = 0;
    REP(_,n) {
      ll a,b; cin >> a >> b;
      q.emplace(now,now+b,a,i);
      now += b;
    }
  };
  in(0,n1); in(1,n2);

  vector<Event> m(2);
  auto check = [&]() -> ll {
    auto [from1,to1,v1,i1] = m[0];
    auto [from2,to2,v2,i2] = m[1];
    if (from1 == -1 || from2 == -1) return 0;
    if (v1 != v2) return 0;
    if (to1 <= to2) {
      return max(0LL,to1 - max(from1,from2));
    } else {
      return max(0LL,to2 - max(from1,from2));
    }
  };

  ll ans = 0;
  while(q.size()) {
    auto e = q.top(); q.pop();
    m[e.i] = e;
    ans += check();
  }
  cout << ans << endl;
  return 0;
}