#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<int> ans;

  auto swp = [&](int i) -> void {
    swap(a[i],a[i+1]);
    a[i]+=k;
    ans.push_back(i);
  };
  auto sorted = [&]() {
    REP(i,n-1) if (a[i] > a[i+1]) return false;
    return true;
  };
  auto out = [&]() -> void {
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for(auto v: ans) cout << v+1 << " ";
  };

  if (n == 2) {
    if (!sorted()) swp(0);
    if (sorted()) out();
    else cout << "No" << endl;
    return 0;
  }
  REP(i,n-1) REP(j,100*(i+1)+1) swp(i);

  assert(sorted());
  assert(ans.size() <= 5e5);
  out();
  return 0;
}