// USACO skel
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> hills;
int costs[84];

int main(void)
{
  ofstream fout ("skidesign.out");
  ifstream fin ("skidesign.in");
  
  memset(costs, 0, sizeof(int) * 84);

  int N;
  fin >> N;
  hills.resize(N);
  for (int i = 0; i < N; i++)
    fin >> hills[i];
  fout << endl;



  return 0;
}
