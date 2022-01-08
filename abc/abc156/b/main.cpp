#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int n;
  int k;
  cin >> n >> k;
  char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string ans;
  while (n >= k) {
    ans += table[n % k];
    n /= k;
  }
  ans += table[n];
  cout << ans.size() << endl;
  return 0;
}
