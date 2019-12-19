#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int sum_kuku() {
  int sum = 0;
  for(int i = 1; i <= 9; i++) {
    for(int j = 1; j <= 9; j++) sum += i*j;
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  int diff = sum_kuku() - n;
  for(int i = 1; i <= 9; i++) {
    for(int j = 1; j <= 9; j++) {
      if(i*j == diff) cout << i << " x " << j << endl;
    }
  }
}