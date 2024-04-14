#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Parcer{
protected:
    vector <vector<int>> G;
    int V;
    int E;
public:
    Parcer (ifstream &f_in);
};
