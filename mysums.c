#include <stdio.h>
#include <math.h>

void get_dimensions(int *, int *);
void read_matrix(int, int, double *);
void print_matrix(int, int, double *);

int main(void)
{
	int row, col;
	double A[10][10];
	
	get_dimensions(&row,&col);
	read_matrix(row,col,&A[0][0]);
	
	printf("A=\n");
	print_matrix(row,col,&A[0][0]);
	
	return 0;
}

void get_dimensions(int *row, int *col)
{
	int check;
	do{
		printf("Enter the number of rows\nBetween 1 and 10\n");
		check= scanf("%d",row);
		getchar();
	}while(!check || *row<1 || *row>10);
	
	do{
		printf("Enter the number of columns\nBetween 1 and 10\n");
		check= scanf("%d",col);
		getchar();
	}while(!check || *col<1 || *col>10);	
}

void read_matrix(int row, int col, double *p)
{
	int i,j,check;
	
	printf("Enter each element of A\n");
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			do{
				printf("A[%d][%d]= ",i,j);
				check= scanf("%lf",p+i*col+j);
				getchar();
			}while(!check);
		}
		printf("\n");
	} 
}

void print_matrix(int row,int col,double *A)
{
	int count=1, i, j;
	double *p, sum=0;
	
	for(p=A; p <= (A+col*row-1); p++,count++){
		printf("%.2lf ",*p);
		if(count && !(count%col)) printf("\n");
	}
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			sum=sum+ *(A+i*col+j);
		}
		printf("Row %d = %.2lf\n",i+1,sum);
		sum=0;
	}
	
		for(j=0;j<col;j++)
	{
		for(i=0;i<row;i++)
		{
			sum=sum+ *(A+i*col+j);
		}
		printf("Column %d = %.2lf\n",i+1,sum);
		sum=0;
	}
}