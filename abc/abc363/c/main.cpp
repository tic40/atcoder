#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  string s; cin >> s;

  int ans = 0;
  sort(s.begin(),s.end());
  do {
    auto is_palindrome = [&](int i) {
      REP(j,k/2) if (s[i+j] != s[i+k-1-j]) return false;
      return true;
    };

    bool ok = true;
    REP(i,n-k+1) if (is_palindrome(i)) { ok = false; break; }
    if (ok) ans++;
  } while (next_permutation(s.begin(), s.end()));

  cout << ans << endl;
  return 0;
}