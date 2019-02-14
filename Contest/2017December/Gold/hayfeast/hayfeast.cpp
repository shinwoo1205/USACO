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

int main(void)
{
  ofstream fout ("hayfeast.out");
  ifstream fin ("hayfeast.in");

  // process inputs
  unsigned int N, M;
  fin >> N >> M;
  // first : flavor, second: spice
  vector<pair<int, int>> hays(N);
  for (int i = 0; i < N; i++)
	  fin >> hays[i].first >> hays[i].second;

 

  return 0;
}

