#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i,n) cin >> a[i];
  vector<int> t,d;

  REP(i,n) {
    d.push_back(a[i]);
    swap(t,d);
  }

  reverse(t.begin(),t.end());
  t.insert(t.end(), d.begin(), d.end());
  REP(i,n) {
    if (i>0) cout << " ";
    cout << t[i];
  }
  return 0;
}
