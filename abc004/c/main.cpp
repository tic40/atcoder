#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> data = { 1,2,3,4,5,6 };
  int num = n / 5, mod = n % 5;

  if (num > 0) {
    for(int i = 0; i < num % data.size(); i++) {
      data.push_back(data.at(0));
      data.erase(data.begin());
    }
  }
  if (mod > 0) {
    for (int i = 0; i < mod; i++) {
      int tmp = data.at(i + 1);
      data.at(i + 1) = data.at(i);
      data.at(i) = tmp;
    }
  }
  for (int d: data) cout << d;
  cout << endl;
}