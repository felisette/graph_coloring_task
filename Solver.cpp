#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Solver.h"

using namespace std;

Solver::Solver (ifstream &f_in): DB(f_in){
}

void Solver::sort(){
    int flag=1, x;
    for (int i=0; i<V && flag; i++){
            flag=0;
            for (int j=0; j<V-i-1; j++)
                if (degree[1][j]<degree[1][j+1]){
                    for (int k=0; k<2; k++){
                        x=degree[k][j];
                        degree[k][j]=degree[k][j+1];
                        degree[k][j+1]=x;
                    }
                    flag=1;
                }
    }
}

void Solver::solve(){
    sort();
    colors[degree[0][0]]=0;
    for (int i=1; i<V; i++) {
        vector<bool> av_col(V, true);
        for (int j=0; j<V; j++) {
            if ((G[degree[0][i]][j]==1) && (colors[j]!=-1)) {
                av_col[colors[j]]=false;
            }
        }
        int cur_col=0;
        while (!av_col[cur_col]) {
            cur_col++;
        }
        colors[degree[0][i]]=cur_col;
    }
    return;
}
