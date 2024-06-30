#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n),w(n);
  REP(i,n) { cin >> a[i]; a[i]--; }
  REP(i,n) cin >> w[i];

  vector<P> pa;
  vector<int> box(n);
  REP(i,n) {
    pa.emplace_back(w[i],a[i]);
    box[a[i]]++;
  }
  sort(pa.begin(),pa.end());

  ll ans = 0;
  for(auto [k,v]: pa) if (box[v] > 1) {
    ans += k;
    box[v]--;
  }
  cout << ans << endl;
  return 0;
}