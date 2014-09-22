#include <stdio.h>
#define FIN "ssm.in"
#define FOUT "ssm.out"
#define MAXN 7000005

int N, arr[ MAXN ];

void read() {

     int i;

     freopen(FIN, "r", stdin);

     scanf("%d", &N);

     for(i = 1; i <= N; i++) {

         scanf("%d", &arr[ i ]);
     } 

     fclose( stdin );
};

void solve() {

     int i, begin, start, end; int sum = 0;

     long int bestSum = -0x3f3f3f3f;

     freopen(FOUT, "w", stdout);

     for(i = 1; i <= N; i++) {

         if( sum < 0 ) {

             sum = arr[ i ];

             start = i;
 
         } else {

             sum += arr[ i ]; 
         }
 
         if( sum > bestSum ) bestSum = sum, begin = start, end = i;
     }
 
     printf("%ld %d %d", bestSum, begin, end);

     fclose( stdout );
};

int main() {

    read();
    solve();
 
    return(0);
};