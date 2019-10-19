#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)

int main() {
  int n, cnt = 0;
  cin >> n;
  int l[n];
  REP(i, n) scanf("%d", &l[i]);
  sort(l, l+n);

  REP(i, n-2) {
    FOR(j, i+1, n-1) {
      int minIndex = -1;
      FOR(k, j+1, n) {
        if (l[k] > l[j]-l[i]) { minIndex = k; break; }
      }
      if (minIndex == -1) continue;

      int maxIndex = -1;
      for (int k = n-1; k > minIndex; k--) {
        if (l[k] < l[i]+l[j]) { maxIndex = k; break; }
      }
      if (maxIndex == -1) {
        if (l[minIndex] < l[i]+l[j]) cnt++;
        continue;
      }
      cnt += maxIndex - minIndex + 1;
    }
  }
  cout << cnt << endl;
}