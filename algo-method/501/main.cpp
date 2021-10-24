#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

double median(vector<int> a) {
  int n = a.size();
  sort(a.begin(), a.end());
  return n%2 == 0 ? (a[n/2-1] + a[n/2])/2.0 : a[(n-1)/2];
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  printf("%0.2f\n", median(a));
  return 0;
}