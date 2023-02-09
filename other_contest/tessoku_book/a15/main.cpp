#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  auto t = a;
  sort(t.begin(),t.end());
  t.erase(unique(t.begin(),t.end()),t.end());

  REP(i,n) {
    int id = lower_bound(t.begin(),t.end(),a[i]) - t.begin();
    cout << id+1 << " ";
  }
}