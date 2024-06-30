#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint1000000007;

int main() {
  int n; string s;
  cin >> n >> s;

  mint ans = 1;
  for(int i = 0; i < n;) {
    int j = i+1;
    // j := i から A/B 交互になっている長さ
    while(j < n && s[j-1] != s[j]) j++;
    ans *= (j-i+1) / 2;
    i = j;
  }
  cout << ans.val() << endl;
  return 0;
}