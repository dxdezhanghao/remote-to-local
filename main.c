#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int swap(double matrix[][500],int a,int b,int n){
	int j=0;
	double change=0.0;
	for(j=0;j<n;j++){
	   change=matrix[a][j];
	   matrix[a][j]=matrix[b][j];
	   matrix[b][j]=change;	
	}
	return 0;
}
int multiofmatrix(double L[][500],double U[][500],int m){
	int i=0,j=0,k=0;
	double sum=0;
	double backup[500][500];
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			sum=0;
			for(k=0;k<m;k++){
			 sum+=L[i][k]*U[k][j];
			}
			backup[i][j]=sum;
		}
	}
	printmatrix(backup,m,m);
}
int printmatrix(double matrix[][500],int m,int n){
    int r=0,l=0;
    for (r=0;r<m;r++)
	   {
	    for (l=0;l<n;l++)
	        printf("%lf ",matrix[r][l]);
	     	printf("\n");
			 }
	return 0;
}
int soolittle(double matrix[][500],double L[][500],double U[][500],int m){//DOOlittle
	double sum=0;
	int s=0,i=0,k=0;
	double midanswer[500],answer[500];
	for (s=0;s<m;s++){
	  for (i=s;i<m;i++){
	    for (k=0;k<s;k++)	
		  {
		  sum+=L[s][k]*U[k][i];
	      }
       U[s][i]=matrix[s][i]-sum;
       sum=0;
	}
	  for(i=s+1;i<m;i++){
	 	for(k=0;k<s;k++)
		 {
	 		sum+=L[i][k]*U[k][s];
		 }
	   L[i][s]=(matrix[i][s]-sum)/U[s][s];
	   sum=0;	
	 }
  } 
  for(i=0;i<m;i++){
  	L[i][i]=1;
  }
  printmatrix(L,m,m);
  printf("LLL  RRR");
  printmatrix(U,m,m);
  printf("---\n");
  multiofmatrix(L,U,m);
  //answer
  for(i=0;i<m;i++){
  	for(k=0;k<i;k++){
	  sum+=midanswer[k]*L[i][k]; 
  }
  midanswer[i]=matrix[i][m]-sum;
  sum=0;
 }
 for(i=m-1;i>-1;i--){
    	for (k=m-1;k>i;k--){
    	    	sum+=U[i][k]*answer[k];
		}
		answer[i]=(midanswer[i]-sum)/U[i][i];
		sum=0;
	}
	for(i=0;i<m;i++){
	printf("%lf\t",answer[i]); 
	} 
}
int mainsoolittle(double matrix[][500],double L[][500],double U[][500],int m){// main DOOlittle
	double sum=0;
	int s=0,i=0,k=0;
	double maxdouble=0,process=0,midvalue[500];
	int M[500];
	double midanswer[500],answer[500];
	double change=0;
	for(i=0;i<m;i++){
		M[i]=i;
	}
	for (s=0;s<m;s++){
	  for (i=s;i<m;i++){
	  	for(k=0;k<s;k++)
	  	{
        process+=L[i][k]*U[k][s];
	  }	
	  if(abs(matrix[i][s]-process)>maxdouble)
	    {
		maxdouble=abs(matrix[i][s]-process);
	    M[s]=i;
		}
		midvalue[i]=matrix[i][s]-process;
	    process=0;
     }
     printf("--%d--\n",M[s]);
     if(M[s]!=s){
     	for(i=0;i<m;i++)
     	{
     	   if(i<s){
     	   change=L[s][i];
		   L[s][i]=L[M[s]][i];	
     	   L[M[s]][i]=change;
			}
			else{
		   change=matrix[s][i];
		   matrix[s][i]=matrix[M[s]][i];	
     	   matrix[M[s]][i]=change;	
			}
		 }
		 change=midvalue[s];
     	 midvalue[s]=midvalue[M[s]];
     	midvalue[M[s]]=change;
     	
	 }
	 U[s][s]=midvalue[s];
	  for (i=s+1;i<m;i++){
	    for (k=0;k<s;k++)	
		  {
		  sum+=L[s][k]*U[k][i];
	      }
       U[s][i]=matrix[s][i]-sum;
       sum=0;
	}
	  for(i=s+1;i<m;i++){
	 	L[i][s]=midvalue[i]/U[s][s];	
	 }
	   printmatrix(L,m,m);
  printf("LLL  RRR");
  printmatrix(U,m,m);
  } 
    for(i=0;i<m;i++){
  	L[i][i]=1;
  }
  printmatrix(L,m,m);
  printf("LLL  RRR");
  printmatrix(U,m,m);
    printf("---\n");
  multiofmatrix(L,U,m);
  for(i=0;i<m-1;i++){
  	change=matrix[i][m];
  	matrix[i][m]=matrix[M[k]][m];
  	matrix[M[k]][m]=change;
  }
  //answer
  for(i=0;i<m;i++){
  	for(k=0;k<i;k++){
	  sum+=midanswer[k]*L[i][k]; 
  }
  midanswer[i]=matrix[i][m]-sum;
  sum=0;
 }
 for(i=m-1;i>-1;i--){
    	for (k=m-1;k>i;k--){
    	    	sum+=U[i][k]*answer[k];
		}
		answer[i]=(midanswer[i]-sum)/U[i][i];
		sum=0;
	}
	for(i=0;i<m;i++){
	printf("%lf\t",answer[i]); 
	}   
}
//in one function
/*int comgauss(double matrix[][500],int m,int n,int flag){
	int i=0,j=0,k=0;
	int s=0;
	double sum=0.0;
	double ans[500];
	for (i=0;i<m;i++){
		if (flag==1){
		double max=matrix[i][i];
		int change=i;
		for (j=i;j<m;j++){
			if(matrix[j][i]>max){
				max=matrix[j][i];
				change=j;
			}
		}
		if (change!=i){
			swap(matrix,i,change,n);
		}
	   }
		if(matrix[i][i]==0){
			printf("sorry");
			return 0; 
			}
		for(s=i+1;s<m;s++){
			if(matrix[i][i]==0){
				printf("sorry");
				return 0; 
			}
			double t=matrix[s][i]/matrix[i][i];
			printf(" t=%lf\n",t);
			for(k=0;k<n;k++){	
				matrix[s][k]-=matrix[i][k]*t;
			} 
		}
	}	
	printmatrix(matrix,m,n);
    for(i=m-1;i>-1;i--){
    	for (j=m-1;j>i;j--){
    	    	sum+=matrix[i][j]*ans[j];
		}
		ans[i]=(matrix[i][n-1]-sum)/matrix[i][i];
		sum=0;
	}
	for(i=0;i<m;i++){
	printf("%lf\t",ans[i]); 
	} 
	return 0;			
	
}*/
int shunxuemain(double matrix[][500],int m,int n){//mainguss
	int i=0,j=0,k=0;
	int s=0;
	double sum=0.0;
	double ans[500];
	for (i=0;i<m;i++){
		double max=matrix[i][i];
		int change=i;
		for (j=i;j<m;j++){
			if(matrix[j][i]>max){
				max=matrix[j][i];
				change=j;
			}
		}
		if (change!=i){
			swap(matrix,i,change,n);
		}
		if(matrix[i][i]==0){
			printf("sorry");
			return 0; 
			}
		for(s=i+1;s<m;s++){
			if(matrix[i][i]==0){
				printf("sorry");
				return 0; 
			}
			double t=matrix[s][i]/matrix[i][i];
			printf(" t=%lf\n",t);
			for(k=0;k<n;k++){	
				matrix[s][k]-=matrix[i][k]*t;
			} 
		}
	}	
	printmatrix(matrix,m,n);
    for(i=m-1;i>-1;i--){
    	for (j=m-1;j>i;j--){
    	    	sum+=matrix[i][j]*ans[j];
		}
		ans[i]=(matrix[i][n-1]-sum)/matrix[i][i];
		sum=0;
	}
	for(i=0;i<m;i++){
	printf("%lf\t",ans[i]); 
	} 
	return 0;		
}
int shunxue(double matrix[][500],int m,int n){//guss
	int i=0,j=0,k=0;
	int s=0;
	double sum=0.0;
	double ans[500];
	for (i=0;i<m;i++){
		for(s=i+1;s<m;s++){
			if(matrix[i][i]==0){
				printf("sorry");
				return 0; 
			}
			double t=matrix[s][i]/matrix[i][i];
			printf(" t=%lf\n",t);
			for(k=0;k<n;k++){	
				matrix[s][k]-=matrix[i][k]*t;
			} 
		}
		printmatrix(matrix,m,n);
	}
	printmatrix(matrix,m,n);
    for(i=m-1;i>-1;i--){
    	for (j=m-1;j>i;j--){
    	    	sum+=matrix[i][j]*ans[j];
		}
		ans[i]=(matrix[i][n-1]-sum)/matrix[i][i];
		sum=0;
	}
	for(i=0;i<m;i++){
	printf("%lf\t",ans[i]); 
	} 
	return 0;
}
int main(int argc, char *argv[]) {
	FILE *fp = fopen("sanma.txt", "r");
	char szTest[5000] = {0};
	double matrix[500][500];
	double L[500][500];
	double U[500][500];
	int i=0,j=0;
	int m= 0;
	int n=0,l=0;
	char *ptr=NULL;	
	if(NULL == fp)	
	{		
		printf("failed to open dos.txt\n");		
		return 1;	
	}
	while(!feof(fp))	
	{ 
	memset(szTest, 0, sizeof(szTest));		
	fgets(szTest, sizeof(szTest) - 1, fp);
	ptr=strtok(szTest, ",");
	while (ptr!=NULL) {
		printf("ptr=%s\n", ptr);
		printf("%lf\n",atof(ptr));
		matrix[m][n++]=atof(ptr);
		ptr = strtok(NULL, ",");
	}
	l=n;
	m++;
	n=0;
	printf("dsadasd");
    }
    printf("%lf\n",matrix[0][0]);
    printf("%lf\n",matrix[0][1]);
    printf("%lf\n",matrix[0][2]);
    printf("%lf\n",matrix[0][3]);
	printmatrix(matrix,m,l);
		printf("%d\n",m);
		printf("%d",l);
	shunxue(matrix,m,l);
	printf("-------------------\n");
	//soolittle(matrix,L,U,m);
	//mainsoolittle(matrix,L,U,m);
	//shunxuemain(matrix,m,l);
	fclose(fp); 
	return 0;
}
