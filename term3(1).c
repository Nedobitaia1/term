#define N 1000
#include <stdio.h>
#include <math.h>

void ge(int i, double a[][N+1], int n, int k){
    
    int maxi=-9999, l=i, im=0, t=0,f=0, sz=0;
    
    for(int i1=i; i1<k; i1++){
        if(a[i1][l]>maxi){maxi=a[i1][l];im=i1;} //нахождение максимального эл. в столбце
    }
    
    for(int j=0; j<n; j++){
        t=a[i][j];
        a[i][j]=a[im][j];  //меняем местами "верхнюю" строку и с максимальным значением 
        a[im][j]=t;
    }
   
}



int main()
{
   double a[N][N + 1];
   int  n,k,f=0,o=0,pr=0,i,sz=0,d=0,pol=0,t=0;
   double s=0;
   
   scanf("%d %d",&n,&k);
  
    for ( int i = 0; i < k; i++ )
        for ( int j = 0; j < n; j++ ) 
            scanf( "%lf", &a[i][j] );
            
            
    for ( int j = 0; j < n; j++ ){
        for ( int i = 0; i < k; i++ ){
            if(a[i][j]==0){pol++;}
        }
                                       //сдвиг нулевых столбцов в начало массива
        if(pol==k){
            for(int i3=0;i3<k;i3++){
               t=a[i3][d];
               a[i3][d]=a[i3][j];
               a[i3][j]=t;
            }
            d++;
        }
        pol=0;
    }
            

    

    
    
  for(int i=0; i<k-1; i++){
  
      ge(i,a,n,k);
      if(a[i][i+d]!=0){
          s=a[i][i+d];
          
          for(int j=i+d; j<n; j++){
                a[i][j] /= s;  // в верхней строке делим все на значение 1 элемента
            }
            
          for(int i2=i+1; i2<k; i2++){
              s=a[i2][i+d];
              
              for(int j2=i+d; j2<n; j2++){
                  a[i2][j2]-=a[i][j2]*s; // поочередно вычитаем верхнюю строку из последующих
                }
                
            } 
        }
    
    } 
    
    
    for ( int i = k-1; i >= 0; i-- ){   
        for ( int j = n-1; j >=0; j-- ){ 
            if(a[i][j]!=0){
                if(f==0){printf("образуют линейно независимую систему ранга %d", k);}
                else{printf("образуют линейно зависимую систему ранга %d", k-f);} //с конца ищем строку с некоторыми ненулевыми значениями
                return 0;               
            }
        }
       f++;
    } 
    
    if(k==f){printf("образуют линейно независимую систему ранга %d", k-f);}
      
      
      
  return (0);
}
