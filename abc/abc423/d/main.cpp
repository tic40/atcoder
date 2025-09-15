#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,ll>;
using Event = tuple<ll,int,int>; // time, type, id

int main() {
  int n,k; cin >> n >> k;
  vector<ll> a(n),b(n),c(n);
  REP(i,n) cin >> a[i] >> b[i] >> c[i];

  priority_queue<Event,vector<Event>,greater<Event>> events;
  REP(i,n) events.emplace(a[i],0,i);

  vector<ll> ans(n);
  int now = 0;
  ll t = 0;
  queue<int> q;

  auto enter = [&]() {
    while(q.size()) {
      int i = q.front();
      if (k < now + c[i]) break;

      q.pop();
      now += c[i];
      ans[i] = t;
      events.emplace(t+b[i],1,i);
    }
  };

  while(events.size()) {
    auto [time,type,i] = events.top(); events.pop();
    t = time;
    // 待ち行列追加
    if (type == 0) q.push(i);
    // 退店
    if (type == 1) now -= c[i];
    enter(); // 入店判定
  }
  for(auto v: ans) cout << v << endl;
  return 0;
}