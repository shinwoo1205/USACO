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
#define Bessie 1
#define Elsie 2
#define Mildred 4

using namespace std;
// Bessie, Elsie, Mildred's Milk production
vector<int> B_milk(101, 0);
vector<int> E_milk(101, 0);
vector<int> M_milk(101, 0);

int B_total = 0;
int E_total = 0;
int M_total = 0;
int update = 0;

int display = Bessie | Elsie | Mildred;
bool updateDisplay(int B_total, int E_total, int M_total);
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
  for (int i = 1; i <= 100; i++) {
	  B_total += B_milk[i];
	  E_total += E_milk[i];
	  M_total += M_milk[i];
	
	  
	  if(updateDisplay(B_total, E_total, M_total))
		  update++;
	     
	  
	  //debug
	  //cout << "B_total: " << B_total << "E_total: " << E_total << "M_total: " << M_total << endl; 
  }

  
  fout << update <<endl;


  return 0;
}
bool updateDisplay(int B_total, int E_total, int M_total)
{
	int tempdis = 0;
	int comp = 0;
	
	if (B_total > E_total) {
		if (B_total > M_total)
			tempdis |= Bessie;
		else if (B_total == M_total)
			tempdis |= (Bessie | Mildred);
		else 
			tempdis |= Mildred;
	}
	else if (B_total == E_total) {
		if (M_total > B_total)
			tempdis |= M_total;
		else if (M_total == B_total)
			tempdis |= (Bessie | Elsie | Mildred);
		else 
			tempdis |= (Bessie | Elsie);
	}
	else {
		if (E_total > M_total)
			tempdis |= Elsie;
		else if (E_total == M_total)
			tempdis |= (Elsie | Mildred);
		else
			tempdis |= Mildred;
	}
	//debug
	//cout << "tempdis : " <<tempdis << "display: " <<display << endl;
	bool isUpdate = (tempdis != display);
	display = tempdis;
	return isUpdate;
	
}