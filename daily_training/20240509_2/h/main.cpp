#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  vector<ll> a(n);
  unordered_set<int> st;
  vector<ll> s(q+1);
  vector<int> b(n,-1);
  REP(i,q) {
    int x; cin >> x; x--;
    if (st.find(x) == st.end()) {
      st.insert(x);
      s[i+1] = s[i] + st.size();
      b[x] = i;
    } else {
      st.erase(x);
      s[i+1] = s[i] + st.size();
      a[x] += s[i] - s[b[x]];
      b[x] = -1;
    }
  }
  REP(i,n) {
    if (b[i] != -1) a[i] += s[q] - s[b[i]];
    cout << a[i] << " ";
  }
  return 0;
}