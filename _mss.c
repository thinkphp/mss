#include <stdio.h>
#include <malloc.h>
#define FIN "ssm.in"
#define FOUT "ssm.out"
#define max(a,b) (((a)>(b))?(a):(b))

void _mss(int *p, int n, int *start, int *end, int *maxsum) {
     
     int currentSum = 0, 
         possibleStart = 0;
     *start = 0;
     *end = -1;
     *maxsum = p[0];

     for (int i = 0; i < n; ++i)
     {

     	 if (currentSum < 0)
     	 {
     	 	possibleStart = i;
     	 }
     	 currentSum = max(currentSum + p[i], p[i]);

     	 if(currentSum > *maxsum) {
     	 	*maxsum = currentSum;
     	 	*start = possibleStart;
     	 	*end = i;
     	 }
     }

}

int main(int argc, char const *argv[])
{
	int *v, n,
	     start, 
	     end, 
	     maxsum; 

	freopen(FIN, "r", stdin);
	freopen(FOUT, "w", stdout);

    scanf("%d",&n);    

    v = (int*)malloc(sizeof(int)*n);

    for (int i = 0; i < n; ++i)
    {
    	scanf("%d", &v[i]);
    }
    
    _mss(v, n, &start, &end, &maxsum);

    printf("%d %d %d\n", maxsum, start + 1, end + 1);

    free(v);
	
	return 0;
}
