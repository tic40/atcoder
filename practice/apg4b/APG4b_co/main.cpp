#include <bits/stdc++.h>
using namespace std;

int main() {
  int p, N;
  string text;
  int price;

  cin >> p;
  if (p == 1) {
    cin >> price;
  } else if (p == 2) {
    cin >> text >> price;
  }
  cin >> N;
  if (text != "") cout << text << "!" << endl;
  cout << price * N << endl;
}
