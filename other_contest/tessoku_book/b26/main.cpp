#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

vector<int> eratosthenes(int n) {
  vector<int> res;
  vector<bool> is_prime(n+1,true);
  for(int i = 2; i <= n; i++) {
    if (!is_prime[i]) continue;
    for(int j = 2*i; j <= n; j+=i) is_prime[j] = false;
    res.push_back(i);
  }
  return res;
}

int main() {
  int n; cin >> n;
  auto p = eratosthenes(n);
  for(int v: p) cout << v << endl;
  return 0;
}