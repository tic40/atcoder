#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  a.erase(unique(a.begin(),a.end()),a.end());

  cout << a.size() << endl;
  for(auto v: a) cout << v << " ";
  return 0;
}