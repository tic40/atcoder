#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int t; cin >> t;
  REP(_,t) {
    int n,k; cin >> n >> k;
    vector<P> items(n);
    REP(i,n) cin >> items[i].first;
    REP(i,n) cin >> items[i].second;
    sort(items.begin(),items.end());

    priority_queue<int> pq;
    ll sumb = 0, ans = LINF;
    for(auto [a,b]: items) {
      pq.push(b);
      sumb += b;
      if ((int)pq.size() == k) {
        ans = min(ans,(ll)a * sumb);
        sumb -= pq.top(); pq.pop();
      }
    }
    cout << ans << endl;
  }
  return 0;
}