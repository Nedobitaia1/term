#define N 1000
#include <stdio.h>
#include <math.h>

int main()
{
   double a[N][N];
   int  n,k=0,f=0,o=0,pr=0,i,sz=0,d=0,pol=0,t=0,im=0;
   double s=0,det=1;
   
   scanf("%d",&n);
  
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < n; j++ ) 
            scanf( "%lf", &a[i][j] );
            
            
    for ( int j = 0; j < n; j++ ){
        for ( int i = 0; i < n; i++ ){
            if(a[i][j]==0){pol++;}
        }                                               //поиск нулевых столбцов
                                       
        if(pol==n) {printf("det M = 0"); return 0;}
    }
            

    

    
    
  for(int i=0; i<n; i++){
  
      if(a[i][i]==0){
          for(int i1=i; i1<n; i1++){
                if(a[i1][i]!=0){im=i1;k=1; break;} //нахождение ненулевого эл. в столбце
            }
    
            if(k==1){
                for(int j=0; j<n; j++){
                    t=a[i][j];
                    a[i][j]=a[im][j];  //меняем местами "верхнюю" строку и строку с ненулевым элементом 
                    a[im][j]=t;
                }
            }
        }
        
      if(a[i][i]!=0){
            if(k==1){  
                t++;  //счетчик перестановок строк
                k=0;
            }
            
            for(int i2=i+1; i2<n; i2++){
                s=a[i2][i]/a[i][i];
              
                for(int j2=i; j2<n; j2++){
                    a[i2][j2]-=a[i][j2]*s; // поочередно вычитаем верхнюю строку из последующих
                }
                
            } 
            
        }
    
    } 
    
    for(int i=0; i<n; i++){
        det*=a[i][i];
    }
    
   if(t%2!=0)(det*=(-1));
   if(det==-0){det=0;}
   
   printf("det M = %lf",det );
      
      
      
  return (0);
}

