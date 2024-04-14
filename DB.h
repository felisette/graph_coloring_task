#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Parcer.h"

using namespace std;

class DB:public Parcer{
protected:
    vector <vector<int>> degree;
    vector <int> colors;
public:
    DB (ifstream &f_in);
    void write_file();
};
