#define N 200
#include <stdio.h>
#include <math.h>

void ge( int k, double a[][N + 1], int n, int p[] )
{
  int i, j, im = k, jm = k;
  double t;
  
  // поиск максимального значения для перестановик строк
  for ( int i = k; i < n; i++ )
    for ( int j = k; j < n; j++ )
      if ( fabs( a[im][jm] ) < fabs( a[i][j] ) ) 
      {
        im = i;
        jm = j;     
      }
      
 // перестановка строк
  for ( int j = k; j < n + 1; j++ )
  {
    t = a[k][j];
    a[k][j] = a[im][j];   
    a[im][j] = t;
  }
  
  for ( i = 0; i < n; i++ )
  {
    t = a[i][k];
    a[i][k] = a[i][jm]; 
    a[i][jm] = t;
  }
  
  // смена порядка корней
  i = p[k];
  p[k] = p[jm]; 
  p[jm] = i;
}




int main()
{
  double a[N][N + 1];
  double x[N]; 
  int p[N]; 
  int  n;
  
    
    scanf( "%d", &n );
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < n + 1; j++ ) 
            scanf( "%lf", &a[i][j] );
  
  //порядок корней
  for ( int i = 0; i < n + 1; i++ ) 
    p[i] = i;                            
    
  //прямой ход
  for ( int k = 0; k < n; k++ ){ 
    ge( k,a, n, p ); 
    
    for ( int j = n; j >= k; j-- )
      a[k][j] /= a[k][k];
      
    for ( int i = k + 1; i < n; i++ )
      for ( int j = n; j >= k; j-- )
        a[i][j] -= a[k][j] * a[i] [k];
  }

  //Обратный ход
  for ( int i = 0; i < n; i++ )
    x[i] = a[i][n];
    
  for ( int i = n - 2; i >= 0; i-- )
    for ( int j = i + 1; j < n; j++ )
      x[i] -= x[j] * a[i] [j];

  //вывод
  for ( int i = 0; i < n; i++ )
    for ( int j = 0; j < n; j++ )
      if ( i == p[j] ){
        printf( "%f\n", x[j] );
        break;
      }
      
  return (0);
}
