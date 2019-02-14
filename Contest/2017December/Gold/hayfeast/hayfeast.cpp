/*
ID: jeremia11
TASK: hayfeast
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct hay{
	int flavor;
	int spiceness;
};

struct hay minimums[100000000];
vector<pair<int, int>> hays;
int num=0;
void findMinimum(int i, int j);
int main(void)
{
  ofstream fout ("hayfeast.out");
  ifstream fin ("hayfeast.in");

  // process inputs
  unsigned int N, M;
  fin >> N >> M;
  // first : flavor, second: spice
  hays.resize(N);
  for (int i = 0; i < N; i++)
	  fin >> hays[i].first >> hays[i].second;

  
  for (int i =0; i < N; i++)
	  for(int j = i; j < N; j++)
		  findMinimum(i, j);
 
  int min = 100000000;
  for(int i = 0; i < N; i++){
	  if (minimums[i].flavor >= M){
		  if (minimums[i].spiceness < min) 
			 min = minimums[i].spiceness;
	  }
  }
  
	cout << minimums[0].flavor << " " << minimums[0].spiceness << endl;
  cout << min << endl;
  return 0;
}
void findMinimum(int i, int j)
{
	minimums[num].flavor=0;
	minimums[num].spiceness = 0;
	for(int k=i; k<=j; k++) {
		minimums[num].flavor += hays[k].first;
		minimums[num].spiceness = max(minimums[num].spiceness, hays[k].second);
	
	}
	cout << minimums[num].flavor << " " <<minimums[num].spiceness <<endl;
	num++;
}
