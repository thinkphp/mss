#include <iostream>
#include <fstream>
#define FIN "ssm.in"
#define FOUT "ssm.out"

using namespace std;

void mss(int *p, int n, int & start, int & end, int & maxsum) {

     int currentSum = 0,        
         possibleStart = 0;                
     maxsum = p[0];
     start = 0;
     end = -1;    

         for(int i = 0; i < n; ++i) {

         	 if(currentSum < 0) {
         	 	possibleStart = i;         	 	         	 
         	 } 


         	 currentSum = max(currentSum + p[i], p[i]);

         	 if(currentSum > maxsum) {

         	 	maxsum = currentSum;
         	 	start = possibleStart;
         	 	end = i;

         	 }
         }

}

int main(int argc, char const *argv[])
{
	int *v, 
	     i, 
	     n,
         start, 
         end, 
         maxsum;

         ifstream fin(FIN); 
         ofstream fout(FOUT);

	fin>>n;

	v = new int[n+1];

	for(i = 0; i < n; ++i) {

		fin>>v[i];
	}

	mss(v, n, start, end, maxsum);

	fout<<maxsum<<" "<<start + 1<<" "<<end + 1;

    delete v;
	
	return 0;
}
