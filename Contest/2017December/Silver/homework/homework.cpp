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

using namespace std;

int main(void)
{
  ofstream fout ("homework.out");
  ifstream fin ("homework.in");

  // process inputs
  int N;
  int sum = 0;
  int minIndex = 0;
  fin >> N;
  vector<int> scores(N);
  vector<int> sorted(N);
  
  for (int i = 0; i < N; i++) {
	  fin >> scores[i];
	  sorted[i] = scores[i];
  }
  //sort 
  sort(sorted.begin(), sorted.end());
  //calculate sum
  for (int i = 0; i < N; i++)
	  sum += scores[i];
  
  fout << endl;


  return 0;
}

