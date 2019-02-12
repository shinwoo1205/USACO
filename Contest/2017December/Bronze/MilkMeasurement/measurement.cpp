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

using namespace std;
// Bessie, Elsie, Mildred's Milk production
vector<int> B_milk(101, 0);
vector<int> E_milk(101, 0);
vector<int> M_milk(101, 0);

int B_total = 0;
int E_total = 0;
int M_total = 0;
int main(void)
{
  ofstream fout ("measurement.out");
  ifstream fin ("measurement.in");

  // process inputs
  int N;
  fin >> N;
  for (int i = 0; i < N; i++) {
	  int days;
	  string cow;
	  int diff;
	  fin >> days >> cow >> diff;
	  if (cow == "Bessie")
			B_milk[days] = diff;
	  if (cow == "Elsie")
		    E_milk[days] = diff;
	  if (cow == "Mildred")
		    M_milk[days] = diff;
  }
  
 
  fout <<endl;


  return 0;
}

