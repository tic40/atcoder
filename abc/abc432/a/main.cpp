#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  vector<int> a(3);
  REP(i,3) cin >> a[i];
  sort(a.rbegin(),a.rend());
  for(auto v: a) cout << v;
  return 0;
}