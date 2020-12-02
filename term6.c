#define N 200
#include <stdio.h>
#include <math.h>

void ge( int k, double a[][2*N], int n )
{
  int i, j, im = k, jm = k;
  double t;
  
  // поиск максимального значения для перестановик строк
  for ( int i = k; i < n; i++ )
      if ( a[im][k]<a[i][k] ) 
      {im=i; }
      
 // перестановка строк
  for ( int j = k; j < 2*n; j++ )
  {
    t = a[k][j];
    a[k][j] = a[im][j];   
    a[im][j] = t;
  }
  

}




int main()
{
  double a[N][2*N];
  double b[N][2*N];
  int  n;
  double srt=0,kl=0;
 
    scanf( "%d", &n );
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){ 
            scanf( "%lf", &a[i][j] );
            b[i][j]=a[i][j];}}
            
//---------------------DET------------------
    int  k=0,f=0,o=0,pr=0,i,sz=0,d=0,pol=0,t=0,im=0;
    double s=0,det=1;
        
    for ( int j = 0; j < n; j++ ){
        for ( int i = 0; i < n; i++ ){
            if(b[i][j]==0){pol++;}
        }                                               //поиск нулевых столбцов
                                       
        if(pol==n) {det=0;}
        pol=0;
    }

    if(pol!=n){
        for(int i=0; i<n; i++){
  
            if(b[i][i]==0){
                for(int i1=i; i1<n; i1++){
                    if(b[i1][i]!=0){im=i1;k=1; break;} //нахождение ненулевого эл. в столбце
                }
    
                if(k==1){
                    for(int j=0; j<n; j++){
                        t=b[i][j];
                        b[i][j]=b[im][j];  //меняем местами "верхнюю" строку и строку с ненулевым элементом 
                        b[im][j]=t;
                    }
                }
            }
        
            if(b[i][i]!=0){
                if(k==1){  
                    t++;  //счетчик перестановок строк
                    k=0;
                }
            
                for(int i2=i+1; i2<n; i2++){
                    s=b[i2][i]/b[i][i];
              
                    for(int j2=i; j2<n; j2++){
                        b[i2][j2]-=b[i][j2]*s; // поочередно вычитаем верхнюю строку из последующих
                    }
                
                }   
            
            }
    
        }
    }
    
    for(int i=0; i<n; i++){
        det*=b[i][i];
    }
    
   if(t%2!=0)(det*=(-1));
   if(det==-0){det=0;}
//-------------------------------------------------------------------------
    
  //прямой ход
  if(det==0){printf("Обратной матрицы не существует");}
  else{
      
      for ( int i = 0; i < n; i++ ){
            for ( int j = n; j < 2*n; j++ ){ //дополнение матрицы единичной
                if(i==(j-n)){a[i][j]=1;}
                else{a[i][j]=0;}
            }
        }
        
    
      
      
    for ( int k = 0; k < n; k++ ){ 
        ge( k,a, n); 
        srt=a[k][k];
        
        for ( int j = k; j <= 2*n; j++ )
            a[k][j] /= srt;
            
        
       
        

      
        for ( int i = 0; i < n; i++ ){
        kl=a[i][k];
            for ( int j = k; j<2*n; j++ )
                if(k!=i){a[i][j] -= a[k][j] * kl;}
        }
                
        
    }
    
    
    for ( int i = 0; i < n; i++ ){
        for ( int j = n; j < 2*n; j++ ){
            printf( "%lf ", a[i][j] ); 
        }
    printf("\n");
    }
    
  }

  
      
  return (0);
}