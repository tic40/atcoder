#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
// first: 美味しさの合計, second: 各種類のクッキーを何枚選んだか
using State = pair<ll, vector<int>>;

int main() {
  int n, k, x; cin >> n >> k >> x;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  sort(a.rbegin(), a.rend());

  priority_queue<State> pq;
  set<vector<int>> seen;

  vector<int> initial(n, 0);
  initial[0] = k;

  pq.emplace(a[0] * k, initial);
  seen.insert(initial);

  REP(_,x) {
    auto [sum, cnt] = pq.top();
    pq.pop();

    cout << sum << endl;

    // 種類 i のクッキーを1枚減らして、種類 i+1 のクッキーを1枚増やす
    REP(i,n-1) {
      if (cnt[i] == 0) continue;

      auto next = cnt;
      next[i]--;
      next[i+1]++;

      if (seen.count(next) == 0) {
        seen.insert(next);
        pq.emplace(sum-a[i]+a[i+1], next);
      }
    }
  }
}
