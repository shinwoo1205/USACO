/*
ID: jeremia11
TASK: shuffle
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


vector<string> cownames;
//shuffle order
vector<int> s_order;
//initial order (1,..., N)
vector<int> i_order;
void shuffle();
int N;
int main(void)
{
  ofstream fout ("shuffle.out");
  ifstream fin ("shuffle.in");

  // process inputs
  fin >> N;
  s_order.resize(N + 1);
  i_order.resize(N + 1);
  cownames.resize(N + 1);
  //process input
  for (int i = 1; i <= N; i++) 
	  fin >> s_order[i];
  for (int i = 1; i <= N; i++) 
	  fin >> cownames[i];
  //initialize initial order 
  for (int i = 1; i <= N; i++)
	  i_order[i] = i;
  //shuffile three time
  shuffle();
  shuffle();
  shuffle();
  
  for (int i = 1; i <= N; i++)
	  for (int j = 1; j <= N; j++)
		  if (i == i_order[j])
			  fout << cownames[j] << endl;
  return 0;
}
void shuffle()
{
	//temp
	vector<int> t_order(N + 1);
	for (int i = 1; i <= N; i++)
		t_order[s_order[i]] = i_order[i];
	for (int i = 1; i <= N; i++)
		i_order[i] = t_order[i];
	
	return;
}

