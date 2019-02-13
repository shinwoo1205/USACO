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
  
  
  int board_max = G;
  int board_count = N;
  int update = 0;
  for (int i = 0; i < N; i++) {
	  bool isInBoard = false;
	  if(cows[measures[i].cows]) {
		  //is the cows in board originally
		  isInBoard = (cows[measures[i].cows] == board_max);
		  cows[measures[i].cows] += measures[i].delta;
	  } else
		  cows[measures[i].cows] += (G + measures[i].delta);
	  if(isInBoard) {
		  if (board_max > cows[measures[i].cows]) {
			  update++;
			  board_count--;
			  board_count = max(0, board_count);
		  } else {
			  board_max = cows[measures[i].cows];
			  if (board_count != 1) {
				  update++;
				  board_count = 1;
			  }
		  }
		  
	  } else {
	      if (board_max < cows[measures[i].cows]) {
            update++;
			board_max = cows[measures[i].cows];
			board_count = 1;
		  } else if (board_max == cows[measures[i].cows]) {
			update++;
			board_count++;
		  } else {
			  ;
		  }
	  } 
  }

  fout << update <<endl;


  return 0;
}
