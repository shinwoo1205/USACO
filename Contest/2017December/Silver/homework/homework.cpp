/*
ID: jeremia11
TASK: homework
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
  ofstream fout ("homework.out");
  ifstream fin ("homework.in");

  // process inputs
  int N;
  int sum = 0;
  int minIndex = 0;
  double maxAverage = 0;
  int kIndex = 0;
  fin >> N;
  vector<int> scores(N);
  vector<int> sorted(N);
  vector<double> averages(N-2);
  
  for (int i = 0; i < N; i++) {
	  fin >> scores[i];
	  sorted[i] = scores[i];
  }
  //sort 
  sort(sorted.begin(), sorted.end());

  //calculate sum
  for (int i = 0; i < N; i++)
	  sum += scores[i];
  
  for (int k = 0; k < N-2; k++) {
	  // when minimal value is deleted
	  if (scores[k] == sorted[minIndex])
		  minIndex++;
	  sum -= scores[k];
	  int temp = sum - sorted[minIndex];
	  double tempAverage = (double) temp / (N-k-2);
	  if (tempAverage >= maxAverage) {
		  maxAverage = tempAverage;
	  }
	  averages[k] = tempAverage;
	  //debug
	  //cout << "minIndex : " <<minIndex << "tempAverage: " << tempAverage << "maxAverage: " <<maxAverage <<"kIndex: " <<kIndex <<endl;
  }

  
  for (int i = 0; i < N-2; i++) {
	  if (averages[i] == maxAverage)
		  fout << (i + 1) << endl;
  }
  


  return 0;
}

