#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

show_stat_info( char* fname, struct stat* buf )
{
  printf( "  mode : %o\n", buf->st_mode );
  printf( "  links: %d\n", buf->st_nlink );
  printf( "  user : %d\n", buf->st_uid );
  printf( "  group: %d\n", buf->st_gid );
  printf( "  size : %d\n", buf->st_size );
  printf( "modtime: %d\n", buf->st_mtime );
  printf( "  name : %s\n", fname );
  
}

int main ( int ac, char* av[  ] )
  {
    struct stat info;

    if ( ac > 1 )
      {
        if ( stat( av[ 1 ], &info ) != -1 )
          {
            show_stat_info( av[ 1 ], &info );
            return 0;
            
          }
        else
          perror( av[ 1 ] );
        
      }
    return 1;
    
  }
