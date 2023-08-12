#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int t = 0;
  REP(i,n) t ^= a[i];
  for(auto v: a) cout << (t^v) << " ";
  return 0;
}