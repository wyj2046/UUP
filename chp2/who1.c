#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define SHOWHOST

show_info( struct utmp* utbufp )
{
  printf( "%-8.8s", utbufp->ut_name );
  printf( " " );
  printf( "%-8.8s", utbufp->ut_line );
  printf( " " );
  printf( "%10ld", utbufp->ut_time );
  printf( " " );

  #ifdef SHOWHOST
  printf( "(%s )", utbufp->ut_host );
  #endif
  printf( "\n" );
  
}

int main(  )
  {
    struct utmp current_record;
    int utmpfd;
    int reclen = sizeof( current_record );

    if ( ( utmpfd = open( UTMP_FILE, O_RDONLY ) ) == -1 )
      {
        perror( UTMP_FILE );
        exit( 1 );
        
      }

    while ( read( utmpfd, &current_record, reclen ) == reclen )
      {
        show_info( &current_record );
        
      }

    close( utmpfd );

    return 0;
    
  }
