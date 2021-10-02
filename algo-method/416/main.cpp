#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int n;
vector<int> a(10000), memo(10000,-1);

int r(int i) {
  if (memo[i] != -1) return memo[i];

  if (a[i] == 0) {
    memo[i] = 1;
    return 1;
  }

  memo[i] = 1 + r(a[i]);
  return memo[i];
}

int main() {
  cin >> n;
  for(int i = 1; i < n; i++) cin >> a[i];
  for(int i = 1; i < n; i++) cout << r(i) << endl;

  return 0;
}