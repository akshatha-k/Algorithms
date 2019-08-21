# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <time.h>

int main ( );
void perm_next3 ( int n, int p[], int *more );
double r8_huge ( );
double *r8mat_data_read ( char *input_filename, int m, int n );
void r8mat_header_read ( char *input_filename, int *m, int *n );
void r8mat_print ( int m, int n, double a[], char *title );
void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi, 
  int jhi, char *title );
int s_len_trim ( char *s );
double s_to_r8 ( char *s, int *lchar, int *error );
int s_to_r8vec ( char *s, int n, double rvec[] );
int s_word_count ( char *s );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TSP_BRUTE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2013

  Author:

    John Burkardt
*/
{
  double *distance;
  char distance_filename[255];
  int i;
  int i1;
  int i2;
  int m;
  int more;
  int n;
  int *p;
  int *p_min;
  int paths;
  double total;
  double total_ave;
  double total_max;
  double total_min;

  timestamp ( );
  printf ( "\n" );
  printf ( "TSP_BRUTE:\n" );
  printf ( "  C version\n" );
  printf ( "  Solve small traveling salesman problems by brute force.\n" );
/*
  Get the distance table.
*/
  printf ( "\n" );
  printf ( "  Enter the name of the file containing\n" );
  printf ( "  the city-to-city distance table.\n" );

  scanf ( "%s", distance_filename );

  r8mat_header_read ( distance_filename, &m, &n );

  printf ( "\n" );
  printf ( "  Number of cities is %d\n", n );

  distance = r8mat_data_read ( distance_filename, n, n );
/*
  Print the distance matrix.
*/
  r8mat_print ( n, n, distance, "  Distance matrix:" );
/*
  Examine every permutation.
*/
  total_max = - r8_huge ( );
  total_min = r8_huge ( );
  total_ave = 0.0;

  more = 0;
  p = ( int * ) malloc ( n * sizeof ( int ) );
  p_min = ( int * ) malloc ( n * sizeof ( int ) );

  paths = 0;

  for ( ; ; )
  {
    perm_next3 ( n, p, &more );

    paths = paths + 1;

    total = 0.0;
    i1 = n - 1;
    for ( i2 = 0; i2 < n; i2++ )
    {
      total = total + distance[p[i1]+p[i2]*n];
      i1 = i2;
    }

    total_ave = total_ave + total;

    if ( total_max < total )
    {
      total_max = total;
    }

    if ( total < total_min )
    {
      total_min = total;
      for ( i = 0; i < n; i++ )
      {
        p_min[i] = p[i];
      }
    }

    if ( ! more )
    {
      break;
    }

  }

  total_ave = total_ave / ( double ) ( paths );
  
  printf ( "\n" );
  printf ( "  Itinerary:\n" );
  printf ( "  Step  From  To    Distance\n" );
  printf ( "\n" );
  i1 = n - 1;
  for ( i2 = 0; i2 < n; i2++ )
  {
    printf ( "  %4d    %2d  %2d  %g\n",
      i2, p_min[i1], p_min[i2], distance[p_min[i1]+p_min[i2]*n] );
    i1 = i2;
  }
  printf ( "\n" );
  printf ( "  Total:         %g\n", total_min );

  printf ( "\n" );
  printf ( "  Number of paths checked = %d\n", paths );
  printf ( "\n" );
  printf ( "  Minimum length = %g\n", total_min );
  printf ( "  Average length = %g\n", total_ave );
  printf ( "  Maximum length = %g\n", total_max );
/*
  Free memory.
*/
  free ( distance );
  free ( p );
  free ( p_min );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TSP_BRUTE\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;

}

void perm_next3 ( int n, int p[], int *more )
{
  nt i;
  int m2;
  int n2;
  static int nfact = 0;
  int q;
  static int rank = 0;
  int s;
  int t;
  int temp;

  if ( !( *more ) )
  {
    for ( i = 0; i < n; i++ )
    {
      p[i] = i;
    }
    *more = 1;
    rank = 1;

    nfact = 1;
    for ( i = 1; i <= n; i++ )
    {
      nfact = nfact * i;
    }
  }
  else
  {
    n2 = n;
    m2 = rank;
    s = n;

    for ( ; ; )
    {
      q = m2 % n2;
      t = m2 % ( 2 * n2 );

      if ( q != 0 )
      {
        break;
      }

      if ( t == 0 )
      {
        s = s - 1;
      }

      m2 = m2 / n2;
      n2 = n2 - 1;

    }

    if ( q == t )
    {
      s = s - q;
    }
    else
    {
      s = s + q - n2;
    }

    temp = p[s-1];
    p[s-1] = p[s];
    p[s] = temp;

    rank = rank + 1;

    if ( rank == nfact )
    {
      *more = 0;
    }
  }

  return;
}