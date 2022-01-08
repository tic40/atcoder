#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int h = n / 3600;
  int m = n % 3600 / 60;
  int s = n % 60;
  printf("%02d:%02d:%02d", h, m, s);
}