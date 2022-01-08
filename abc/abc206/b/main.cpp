#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  ll n; cin >> n;

  ll cur = 0;
  int i = 0;
  while(1) {
    cur += (i+1);
    if (n <= cur) {
      cout << i+1 << endl;
      beak;
    }
    i++;
  }

  return 0;
}