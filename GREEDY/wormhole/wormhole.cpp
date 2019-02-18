/*
ID: jeremia11
TASK: wormhole
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
vector<pair<int, int>> wormholes;
int main(void)
{
  ofstream fout ("wormhole.out");
  ifstream fin ("wormhole.in");

  // process inputs
  int N;
  fin >> N;
  wormholes.resize(N);
  for (int i = 0; i < N; i++)
  {
	  fin >> wormholes[i].first >> wormholes[i].second;
  }
  fout << endl;


  return 0;
}

