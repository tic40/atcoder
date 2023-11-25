#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<int> cnt(n+1);
  REP(i,n) if (a[i] <= n) cnt[a[i]]++;
  set<int> st;
  REP(i,n+1) if (cnt[i] == 0) st.insert(i);

  REP(_,q) {
    int i,x; cin >> i >> x;
    i--;
    if (a[i] <= n) {
      cnt[a[i]]--;
      if (cnt[a[i]] == 0) st.insert(a[i]);
    }
    a[i] = x;
    if (a[i] <= n) {
      cnt[a[i]]++;
      if (cnt[a[i]] == 1) st.erase(a[i]);
    }
    cout << *st.begin() << endl;
  }
  return 0;
}