#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
  int n,a,ans=1;
  cin >> n;
  vector<int> cnt(n,0);
  REP(i,n) { cin >> a; cnt[a]++; }
  if (n%2 && cnt[0] != 1) { cout << 0 << endl; return 0; }
  for (int i = n%2?2:1; i < n; i+=2) {
    if (cnt[i] != 2) { cout << 0 << endl; return 0; }
    ans = ans*2%mod;
  }
  cout << ans << endl;
}
