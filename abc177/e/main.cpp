#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define REP(i, n) for(int i=0;i<n;i++)

const int MX = 1000005;
int n;
int a[MX];
int memo[MX];

int gcd(int a, int b) { return b?gcd(b,a%b):a; }

bool pairwise() {
  for (int i = 2; i < MX; i++) {
    int sum = 0;
    for (int j = i; j < MX; j += i) sum += memo[j];
    if (1 < sum) return false;
  }

  return true;
}

bool setwise() {
  int res;
  REP(i,n-1) res = i == 0 ? gcd(a[i], a[i+1]) : gcd(res, a[i+1]);

  return res == 1;
}

int main() {
  cin >> n; REP(i,n) cin >> a[i];
  REP(i,n) memo[a[i]]++;

  if (pairwise()) {
    cout << "pairwise coprime" << endl;
    return 0;
  }

  if (setwise()) {
    cout << "setwise coprime" << endl;
    return 0;
  }

  cout << "not coprime" << endl;
  return 0;
}