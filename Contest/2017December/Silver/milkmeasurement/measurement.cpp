/*
ID: jeremia11
TASK: measurement
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct measure {
	int days;
	int cows;
	int delta;
};


int update = 0;

int main(void)
{
  ofstream fout ("measurement.out");
  ifstream fin ("measurement.in");

  // process inputs
  int N, G;
  fin >> N >> G;
  vector<struct measure> measures(N);
  for (int i = 0; i < N; i++) 
	  fin >> measures[i].days >> measures[i].cows >> measures[i].delta;
  
  //key: cownumber value: procuction
  map<int,int> cows;
  // sort by day order
  sort(measures.begin(), measures.end(), [](const measure& a, const measure& b){ 
    return a.days < b.days;
  });
  
  //debug
  if (!cows[1])
	  cout << "cow exist!" <<endl;
  else
	  cout << "cow does not exist" <<endl;
  int board_max = G;
  int board_count = N;
  for (int i = 0; i < N; i++) {
	  
	  
	  
  }


  
  fout << update <<endl;


  return 0;
}
