#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "Parcer.h"
 
using namespace std;
 
Parcer::Parcer (ifstream &f_in){
    string s;
    f_in>>s;
    int n1{stoi(s)};
    V=n1;
    for (int i=0; i<V; i++){
        G.push_back(vector<int> (V, 0));
    }
    f_in>>s;
    int n2{stoi(s)};
    E=n2;
    while (!f_in.eof ())
    {
      f_in >> s;
      double X{stod (s)};
      f_in >> s;
      double Y{stod (s)};
      G[X][Y]=1;
      G[Y][X]=1;
    }
}
