#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n, k, score, count;
  double ans = 0;
  cin >> n >> k;
  REP(i, n) {
    score = i+1; count = 0;
    while(score < k) {
      score *= 2; count++;
    }
    ans += pow(0.5, count);
  }
  cout << setprecision(10) << ans / n << "\n";
}