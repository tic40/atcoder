#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int a[n][2];
  REP(i, n) cin >> a[i][0] >> a[i][1];
  double sum = 0, ans = 0;
  int num = 0;
  vector<int> arr(n);
  iota(arr.begin(), arr.end(), 1);
  do {
    REP(i, arr.size()) {
      if (i == 0) continue;
      int index = arr[i]-1;
      int lastIndex = arr[i-1]-1;
      int diffx = a[index][0] - a[lastIndex][0];
      int diffy = a[index][1] - a[lastIndex][1];
      sum += sqrt((diffx * diffx) + (diffy * diffy));
    }
    num++;
  } while( next_permutation(arr.begin(), arr.end()) );
  ans = sum / num;
  cout << setprecision(10) << ans << endl;
}
