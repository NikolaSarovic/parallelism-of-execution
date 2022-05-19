#include <iostream>
#include <time.h>

void  paralelFor(int **a, int m, int n)
{
	for (int i = 1; i<m; i++)
#pragma omp  parallel for  
	for (int j = 0; j < n; j++)
		a[i][j] = 2 * a[i - 1][j];

}
void  paralelForIndexChange(int **a, int m, int n)
{

#pragma omp  parallel for  
	for (int j = 0; j < n; j++)
	for (int i = 1; i<m; i++)
		a[i][j] = 2 * a[i - 1][j];
}


int main()
{
 int m = 1000;
 int n=1000;  
 

int** mat = (int**)malloc(m * sizeof(int*)); 

for (int index = 0; index<m; ++index)
{
	mat[index] = (int*)malloc(n * sizeof(int));
}

for (int index = 0; index<n; ++index) 
{
	mat[0][index] = index + 1;
}
clock_t t1 = clock();
paralelFor(mat, m, n);
t1 = clock() - t1;
double time_taken1 = ((double)t1) / CLOCKS_PER_SEC; // in seconds
printf("Vrijeme izvrsenja 1. paralelne funckije %f\n", time_taken1);


/*for (int i = 0; i < m; i++)
{
	for (int j = 0; j < n; j++)
		printf("%d ", mat[i][j]);
	printf("\n");
}*/
printf("\n");
printf("\n");


clock_t t2 = clock();
paralelForIndexChange(mat, m, n);
t2 = clock() - t2;
double time_taken2 = ((double)t2) / CLOCKS_PER_SEC; // in seconds
printf("Vrijeme izvrsenja 2. paralelne funckije (zamjena petlji) %f\n", time_taken2);




/*for (int i = 0; i < m; i++)
{
	for (int j = 0; j < n; j++)
		printf("%d ", mat[i][j]);
	printf("\n");
}*/
 

		
		return 0;
}

/*Kad je malo m i n nema dovoljno podataka da bi se pralelizacija isplatila, vise vremena se troši na režijske poslove oko 
openMP ,tek kad se uzme za m i n 1000 ima koristi za paralelizaciju */




