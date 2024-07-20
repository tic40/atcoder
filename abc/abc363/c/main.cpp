#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  string s; cin >> s;

  vector<int> b(n);
  set<string> st;
  iota(b.begin(),b.end(),0);
  do {
    string t = "";
    REP(i,n) t += s[b[i]];
    st.insert(t);
  } while (next_permutation(b.begin(), b.end()));

  int ans = 0;
  for(auto v: st) {
    auto is_palindrome = [&](int i) {
      REP(j,k/2) if (v[i+j] != v[i+k-1-j]) return false;
      return true;
    };

    bool ok = true;
    REP(i,n-k+1) if (is_palindrome(i)) { ok = false; break; }
    if (ok) ans++;
  }
  cout << ans << endl;

  return 0;
}