#include <iostream>
#include <string.h>
#include <math.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "DB.h"

using namespace std;

DB::DB (ifstream &f_in): Parcer(f_in){
    int k;
    for (int i=0; i<2; i++){
        degree.push_back(vector<int> (V, 0));
    }
    for (int i=0; i<V; i++){
        k=0;
        for (int j=0; j<V; j++){
            if (G[i][j]==1) k++;
        }
        degree[0][i]=i;
        degree[1][i]=k;
    }
    for (int i=0; i<V; i++){
        colors.push_back(-1);
    }
}

void DB::write_file(){
    ofstream out;
    out.open("answer.txt");
    if (out.is_open()){
        for (int i=0; i<V; i++)
            out<<i<<" "<<colors[i]<<"\n";
    }
    out.close();
}
