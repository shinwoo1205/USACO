// USACO skel
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> hills;
vector<int> costs(84);

void calculate(const int min, const int max);
int main(void)
{
  ofstream fout ("skidesign.out");
  ifstream fin ("skidesign.in");
  
  int N;
  fin >> N;
  hills.resize(N);
  for (int i = 0; i < N; i++)
    fin >> hills[i];
  for (int i = 0; i < 84; i++)
    calculate(i, i+17);
  sort(costs.begin(), costs.end());
  
  fout << costs[0] << endl;

  return 0;
}
void calculate(const int min, const int max)
{
  int maxIter = hills.size();
  int sum = 0;
  for (int i = 0 ; i < maxIter; i++) {
    if (hills[i] < min) { 
      int diff = (min - hills[i]);
      sum += (diff*diff); 
    }
    if (hills[i] > max) {
      int diff = (hills[i] - max);
      sum += (diff*diff);
    }
  }   
  costs[min] = sum;
}

