#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) { cin >> a[i]; a[i]--; }
  vector<int> m(n);
  REP(i,n) m[a[i]] = i;

  vector<P> ans;
  REP(i,n) {
    if (a[i] == i) continue;
    ans.emplace_back(i,m[i]);
    swap(a[i],a[m[i]]);
    swap(m[i],m[a[m[i]]]);
  }

  cout << ans.size() << endl;
  for(auto [k,v]: ans) cout << k+1 << " " << v+1 << endl;
  return 0;
}