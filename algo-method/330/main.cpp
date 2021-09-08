#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

vector<int> erastothenes(int n) {
  vector<int> p, is_prime(n+1, 1);
  for(int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i*2; j <= n; j+=i) is_prime[j] = 0;
      p.push_back(i);
    }
  }
  return p;
}

int main() {
  int n; cin >> n;
  cout << erastothenes(n).size() << endl;

  return 0;
}