#include<stdio.h>
#include<stdlib.h>
int n,i,j,j1;
void multiply(int M1[][n],int M2[][n],int R[][n]){
	for (i = 0; i < n; ++i)
   {
       for (j = 0; j < n; ++j)
       {
	       for (j1 = 0; j1 < n; ++j1)
           {
	       	R[i][j] += M1[i][j1]*M2[j1][j]; 
           }
       }
   }
}
void add(int M1[][n],int M2[][n],int R[][n]){
	for (int i = 0; i < n; ++i)
   {
       for (int j = 0; j < n; ++j)
       {
           R[i][j] = M1[i][j] + M2[i][j];
       }
   }
}
int main(int argc, char *argv[])
{
	int func, genernum, input;
	n = atoi(argv[1]);//matrix size=nxn
	func = atoi(argv[2]);//matrix operation selection: 0-Add; 1-Multiplication
	genernum = atoi(argv[3]);//determine given or random number: 0-random; 1-keyboard 
	FILE  *ofp;
	ofp = fopen("output.txt" , "w");//答案會寫進output_b.txt
    
    int (*M1)[n] = malloc(n * sizeof *M1);
    int (*M2)[n] = malloc(n * sizeof *M2);
    int (*R)[n] = malloc(n * sizeof *R);

    for(i=0;i<n;i++){//初始化矩陣M1,M2為0
        for(j=0;j<n;j++){
            M1[i][j] = 0;
            M2[i][j] = 0;
            R[i][j] = 0;
        }
    }
    switch (genernum)
	{
		case 0://給M1,M2矩陣亂數
		    for (i = 0; i < n; ++i)
		    {
			    for (j = 0; j < n; ++j)
			    {
				    M1[i][j]=(rand() % 100) +1;
			        M2[i][j]=(rand() % 100) +1;
			    }
		    }
		    switch (func)
	        {
		       case 1://做矩陣乘法
		           multiply(M1, M2, R);
		           break;//func case1 break
	       
	           case 0://做矩陣加法
	               add(M1, M2, R);
		           break;//func case0 break
		    }
	    break;//generum case0 break
	    case 1://從keyboard給M1,M2矩陣
		    for (i = 0; i < n; ++i)
		    {
			    for (j = 0; j < n; ++j)
			    {
				    scanf("%d", &M1[i][j]);
			    }
		    }
		    for (i = 0; i < n; ++i)
		    { 
			    for (j = 0; j < n; ++j)
			    {
				    scanf("%d", &M2[i][j]);
			    }
		    }
		    switch (func)
	        {
		       case 1://做矩陣乘法
		           multiply(M1, M2, R);
		           break;//func case1 break
	         
	           case 0://做矩陣加法
	               add(M1, M2, R);
		           break;//func case0 break
	    break;//generum case1 break
	    }
	}
	for(i=0;i<n;i++){//印出來
        for(j=0;j<n;j++){
            printf("%d\t", M1[i][j]);}
        printf("\n");}
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t", M2[i][j]);}
        printf("\n");}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{printf("%d\t", R[i][j]); fprintf(ofp, "%d\t", R[i][j]);}
		printf("\n");
        putc('\n',ofp);}
    free(R);
    free(M2);
    free(M1);
	fclose(ofp);//檔案關閉
	return 0;
}
