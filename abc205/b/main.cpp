#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n;
vector<int> a;

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) {
    cin >> a[i];
    a[i]--;
  }

  sort(a.begin(), a.end());
  bool ok = true;
  REP(i,n) if (a[i] != i) ok = false;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}