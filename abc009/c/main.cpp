#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int n, k;
string s, ans;
vector<int> acnt(26, 0), bcnt(26, 0);

bool ok (void) {
  int sum = 0, sumMin = 0;
  REP (i, 26) sum += acnt[i], sumMin += min(acnt[i], bcnt[i]);
  return (k - (sum - sumMin) >= 0) ? true : false;
}

int main() {
  cin >> n >> k >> s;
  REP (i, n) acnt[s[i] - 'a']++, bcnt[s[i] - 'a']++;
  REP (i, n) {
    acnt[s[i] - 'a']--;
    REP(j, 26) {
      if (bcnt[j] > 0) {
        bcnt[j]--;
        if (s[i] != j + 'a') k--;
        if (ok() || s[i] == j + 'a') {
          ans += (char)(j + 'a');
          break;
        } else {
          bcnt[j]++;
          if (s[i] != j + 'a') k++;
        }
      }
    }
  }
  cout << ans << "\n";
}