#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,vector<int>>;

int main() {
  int n,k,x; cin >> n >> k >> x;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  sort(a.rbegin(),a.rend());

  priority_queue<P> pq;
  set<vector<int>> st;

  auto push = [&](ll sum, vector<int>& cnt) -> void {
    if (!st.insert(cnt).second) return;
    pq.emplace(sum,cnt);
  };

  vector<int> init(n);
  init[0] = k;
  push(a[0]*k,init);

  REP(_,x) {
    auto [sum,cnt] = pq.top(); pq.pop();
    cout << sum << endl;

    REP(i,n-1) if (cnt[i] > 0) {
      cnt[i]--; cnt[i+1]++;
      push(sum - a[i] + a[i+1], cnt);
      cnt[i]++; cnt[i+1]--;
    }
  }
  return 0;
}
