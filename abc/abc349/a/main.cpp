#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n-1);
  REP(i,n-1) cin >> a[i];
  int sum = 0;
  REP(i,n-1) sum += a[i];
  cout << -sum << endl;
  return 0;
}