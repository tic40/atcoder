#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  REP(i,n-1) if (a[i] >= a[i+1]) { cout << "No" << endl; return 0; }
  cout << "Yes" << endl;
  return 0;
}
