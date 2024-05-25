#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

struct Event {
  // type := 0: in, 1: out
  int time, type;
  bool operator<(const Event& other) const {
    return time == other.time ? type < other.type : time < other.time;
  }
};

int main() {
  int n; cin >> n;
  vector<Event> events;
  REP(i,n) {
    int l, r; cin >> l >> r;
    events.emplace_back(l, 0);
    events.emplace_back(r, 1);
  }
  sort(events.begin(), events.end());

  ll ans = 0;
  int now = 0;
  for (auto [_,t] : events) {
    if (t == 0) ans += now++;
    else now--;
  }

  cout << ans << endl;
  return 0;
}