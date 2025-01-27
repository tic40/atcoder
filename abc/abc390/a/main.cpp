#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  const int n = 5;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  auto b = a;
  sort(b.begin(),b.end());

  bool ok = false;
  REP(i,n-1) {
    swap(a[i],a[i+1]);
    if (a==b) ok = true;
    swap(a[i],a[i+1]);
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}