#include <iostream>
#include <fstream>
#define FOR(it, b, c) for(int it = (b); it <= (c); it++)
#define FIN "ssm.in"
#define FOUT "ssm.out"
#define MAXN 7000003
 
using namespace std;
 
int N,
    vec[ MAXN ],
    best[ MAXN ],
    bestSum,
    startPos,
    endPos;
 
//function prototypes
void read();
void solve();
int start(int);
 
int main() {
 
    read();
    solve();
 
    return(0);
};
 
void read() {
   
     ifstream fin( FIN );
      
     fin>>N;
 
     FOR(i, 1, N) fin>>vec[i];
};
 
void solve() {
 
     ofstream fout( FOUT );
 
     best[ 1 ] = vec[ 1 ];
 
     bestSum = 0;
 
     FOR(i, 2, N) {
 
         best[ i ] = vec[ i ];
 
         if(vec[ i ] + best[i - 1] > best[ i ])
 
            best[ i ] = vec[ i ] + best[ i - 1 ];
 
         if(best[ i ] > bestSum) bestSum = best[ i ], endPos = i; 
     }
 
     fout<<bestSum<<" "<<start(endPos)<<" "<<endPos;
};
 
int start(int endPos) {
 
    int sum = 0, index = 0;
 
    for(int i = endPos; i >= 1; i--) {
 
        sum += vec[ i ];
 
        index = i;
 
        if(sum == bestSum) break;
    }
 
    return index;
};