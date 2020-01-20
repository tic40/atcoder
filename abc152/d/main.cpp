#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int,int> P;

P f(int x) {
  // a:末尾, b:先頭
  int a = x%10, b = 0;
  while(x) { b = x; x /= 10; }
  return P(a,b);
}

int main() {
  int n;
  cin >> n;
  map<P,int> freq;
  for(int i = 1; i <= n; i++) {
    P p = f(i);
    freq[p]++;
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    P p = f(i);
    P q(p.second, p.first);
    ans += freq[q];
  }
  cout << ans << endl;
}