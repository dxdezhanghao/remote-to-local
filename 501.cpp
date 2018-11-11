#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
int doliteGetUK(double L[],double U[],double y[],double uk[]){
	int s=0,i=0,k=0;
	double midanswer[501],sum=0;
	for(s=0;s<501;s++){
		if(s==0)
		 midanswer[s]=y[s];
		else if(s==1)
		 midanswer[s]=(y[s]-midanswer[0]*L[1])/L[2];
		else{
		 for(i=0;i<=1;i++)
	 	   sum+=midanswer[s-2+i]*L[(s-1)*3+i];
		 midanswer[s]=(y[s]-sum)/L[s*3-1];
		 sum=0;
     	}
	}
	k=0;
	for(s=500;s>=0;s--){
		if(s==500)
		 uk[s]=midanswer[s]/U[1499];
		else if(s==499)
		 uk[s]=(midanswer[s]-U[1498]*uk[s+1])/U[1497];
		else{
		 for(i=2;i>0;i--)
		   sum+=U[3*s+i]*uk[s+i];
		 uk[s]=(midanswer[s]-sum)/U[s*3];
		 sum=0;
		}
	}
} 
int soolittlecompress(double shuru[],double pl[],double pu[]){
	double sum=0;
	int s=0,i=0,k=0;
	int flagL=3,flagU=0;
	double midanswer[501],answer[501];
	pl[0]=1;
	for(i=1;i<501;i++){
		pl[i*3-1]=1;
	}
	for (s=0;s<501;s++){
		//U
		if(s==0){
			for(i=0;i<=2;i++)
			{
			pu[i]=shuru[i];
                 }
				}
		else if(s==1){
			pu[s*3]=shuru[s*3+1]-pl[1]*pu[1];
			pu[s*3+1]=shuru[s*3+2]-pl[1]*pu[2];
			pu[s*3+2]=shuru[s*3+3];
		}
		else if(s==499){
			pu[s*3]=shuru[s*5-1]-pl[s*3-2]*pu[s*3-2]-pl[s*3-3]*pu[s*3-4];
			pu[s*3+1]=shuru[s*5]-pl[s*3-2]*pu[s*3-1];			
		}
		else if(s==500){
			pu[s*3-1]=shuru[s*5-2]-pl[s*3-2]*pu[s*3-2]-pl[s*3-3]*pu[s*3-4];
		}
		else{
		for(i=0;i<=2;i++)
		{
			for(k=1;k<=2-i;k++)
			sum+=pl[s*3-1-k]*pu[s*3+i-2*k];
			pu[s*3+i]=shuru[s*5-1+i]-sum;
			sum=0;
		}
	}
	//L
    s+=1;
	if(s==1)
	    {
	    pl[1]=shuru[3]/pu[0];
	    pl[3]=shuru[7]/pu[0];
		}
	else if(s>500){
		
	}
	else if(s==499){
		pl[(s*3)-2]=(shuru[s*5-2]-pl[(s-1)*3]*pu[(s-1)*3-2])/pu[(s-1)*3];
		pl[s*3]=shuru[s*5+1]/pu[(s-1)*3];
	} 
	else if(s==500){
		pl[(s*3)-2]=(shuru[s*5-3]-pl[(s-1)*3]*pu[(s-1)*3-2])/pu[(s-1)*3];
	}
	else {
		pl[(s*3)-2]=(shuru[s*5-2]-pl[(s-1)*3]*pu[(s-1)*3-2])/pu[(s-1)*3];
		pl[s*3]=shuru[s*5+2]/pu[(s-1)*3];
	}
	s-=1;
}
}
int shunxuemain(double shuru[2499],double xi[1002]){//guss
	int i=0,j=0,k=0;
	int s=0;
	double sum=0.0;
	double ans[501];
	int numberofxi=0;
	//i==0
	double t=shuru[3]/shuru[0];
	xi[numberofxi++]=t;
	for(k=0;k<3;k++)
		shuru[3+k]-=shuru[0+k]*t; 
	t=shuru[7]/shuru[0];
	xi[numberofxi++]=t;
	for(k=0;k<3;k++)
		shuru[7+k]-=shuru[0+k]*t;	
	for(i=4;i<=2484;i+=5){
		for(j=1;j<3;j++){
			if(fabs(shuru[i])<1e-12)
			{
			printf("\nlainglen liangle liangeliangle ----------------------------------------------------------\n");
			return 0;
			}
			t=shuru[i+4*j]/shuru[i];
			xi[numberofxi++]=t;
			for(k=0;k<3;k++)
			shuru[i+4*j+k]-=shuru[i+k]*t;
		}	
	}
	t=shuru[2493]/shuru[2489];
	xi[numberofxi++]=t;
	for(k=0;k<3;k++)
		shuru[2493+k]-=shuru[2489+k]*t;
	t=shuru[2496]/shuru[2489];
	xi[numberofxi++]=t;
	for(k=0;k<3;k++)
		shuru[2496+k]-=shuru[2489+k]*t;
	t=shuru[2497]/shuru[2494];
	xi[numberofxi++]=t;
	for(k=0;k<2;k++)
		shuru[2497+k]-=shuru[2494+k]*t;	
	return 0;		
}
int changemutilmatirx(double shuru[2499],double y[501],double u[501]){
	    int i=0,j=0,k=0;
	    double t=0;
	    for(i=0;i<500;i++)
	    u[i]=0;
		u[0]=shuru[0]*y[0]+shuru[1]*y[1]+shuru[2]*y[2];
		u[1]=shuru[3]*y[0]+shuru[4]*y[1]+shuru[5]*y[2]+shuru[6]*y[3];
		for(i=7;i<=2487;i+=5)
		{
		for(j=0;j<5;j++)
		{
		t=shuru[i+j]*y[k+j];
		u[2+k]+=t;
		}
		k++;
		}
		u[499]=shuru[2492]*y[497]+shuru[2493]*y[498]+shuru[2494]*y[499]+shuru[2495]*y[500];
		u[500]=shuru[2496]*y[498]+shuru[2497]*y[499]+shuru[2498]*y[500];	
		return 0;	
}
int mutilmatirx(double shuru[2499],double y[501]){
	    double u[501]={0};
	    int i=0,j=0,k=0;
	    double t=0;
		u[0]=shuru[0]*y[0]+shuru[1]*y[1]+shuru[2]*y[2];
		u[1]=shuru[3]*y[0]+shuru[4]*y[1]+shuru[5]*y[2]+shuru[6]*y[3];
		for(i=7;i<=2487;i+=5)
		{
		for(j=0;j<5;j++)
		{
		t=shuru[i+j]*y[k+j];
		u[2+k]+=t;
		}
		k++;
		}
		u[499]=shuru[2492]*y[497]+shuru[2493]*y[498]+shuru[2494]*y[499]+shuru[2495]*y[500];
		u[500]=shuru[2496]*y[498]+shuru[2497]*y[499]+shuru[2498]*y[500];	
		return 0;
}
int mutilvet(double y[501],double b2){
	int i=0;
	for(i=0;i<501;i++){
		y[i]*=b2;
	}
}
double getNanswer(double shuruC[2499],double xi[1002],double L[],double U[]){
    double u[501];
	double y[501],yC[501],uC[501];
	int i=0,j=0,k=0,S=4;
	double sum=0,q1=0;
	for(i=0;i<=500;i++)
	u[i]=1;
	double b1=0,b2=0; 
	while(true){
		for(i=0;i<=500;i++)
		   sum+=u[i]*u[i];
		q1=sqrt(sum);
		sum=0;
		for(i=0;i<=500;i++) 
		{
		y[i]=u[i]/q1;
		yC[i]=y[i];
		}
        doliteGetUK(L,U,yC,u);
		for(i=0;i<=500;i++)
		b2+=y[i]*u[i];		   	
		if((fabs(b2-b1)/fabs(b2))<1e-12)
		break;
		b1=b2;
		b2=0;
		k=0;
	}
     b1=1/b2;
    return b1; 
}
double getPanswer(double shuru[2499]){
	double u[501]={0};
	double y[501]={0};
	int i=0;
	double sum=0,q=0;
	for(i=0;i<=500;i++)
	u[i]=1;
	double b1=0,b2=0; 
	while(true){
		for(i=0;i<=500;i++)
		   sum+=u[i]*u[i];
		q=sqrt(sum);
		sum=0;
		for(i=0;i<=500;i++) 
		   y[i]=u[i]/q;
		changemutilmatirx(shuru,y,u);
		for(i=0;i<=500;i++)
		b2+=y[i]*u[i];	  	
		if((fabs(b2-b1)/fabs(b2))<1e-12)
		break;
		b1=b2;
		b2=0;
		q=0;
	}
    return b2; 
}
int getDet(double shuruC[]){
	double det=0;
	int s=0;
	for(s=0;s<=500;s++)
	 {
	 if(0==s)
	   det=shuruC[0];
	 else if(s==500)
	   det*=shuruC[2498];  
	else
		det*=shuruC[s*5-1];
     }
     printf("det = %.12e\n",det); 
}
int main(){
	double shuru[2499],shuruC[2499];
	double pL[1500]={0},pU[1500]={0};
	double xi[1002];
	double maxT=0,minT=0,minabs=0;
	int i,j=0;
	int k=1;
	for(i=0;i<2499;i++){
		if(i==0||i==2498){
		shuru[i]=(1.64-0.024*k)*sin(0.2*k)-0.64*exp(0.1/k);
		k++;
		}
		if(i==1||i==2497)
		shuru[i]=0.16;
		if(i>=2&&i<=2496){
			if(i%5==3||i%5==0)
			  shuru[i]=0.16;
			if(i%5==1||i%5==2)
			  shuru[i]=-0.064;
			if(i%5==4){
			  shuru[i]=(1.64-0.024*k)*sin(0.2*k)-0.64*exp(0.1/k);
			  k++;	
			}
		} 
	}
	for(i=0;i<2499;i++){
	shuruC[i]=shuru[i];
	}
	minT=getPanswer(shuruC);//min
	printf("min=%.12e\n",minT);
	for(i=0;i<=500;i++)
	   if(i==0)
	     shuruC[0]=shuru[0]-minT;
	   else if(i==500)
	      shuruC[2498]=shuru[2498]-minT;
	   else
	     shuruC[5*i-1]=shuru[5*i-1]-minT;
	maxT=getPanswer(shuruC);//max
	maxT+=minT;
	printf("max=%.12e\n",maxT);
	soolittlecompress(shuru,pL,pU);
	minabs=getNanswer(shuru,xi,pL,pU);
	printf("|min|=%.12e\n",minabs);
	double tr=(maxT-minT)/40;
	double gr=0;
	printf("-----------------------------------------\n");
	for(k=1;k<=39;k++)
	{
	   gr=minT+k*tr;
	   for(i=0;i<=500;i++)
	   {
	     if(i==0)
	        shuruC[0]=shuru[0]-gr;
	     else if(i==500)
	        shuruC[2498]=shuru[2498]-gr;
	     else
	        shuruC[5*i-1]=shuru[5*i-1]-gr;
			}
	   soolittlecompress(shuruC,pL,pU);
	   printf("%d = %.12e\n",k,getNanswer(shuruC,xi,pL,pU)+gr);
	}
	printf("conA = %.12e\n",fabs(minT)/fabs(minabs));
	shunxuemain(shuru,xi);
	getDet(shuru);
} 
