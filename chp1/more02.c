#include <stdio.h>

#define PAGLINE 24
#define LINELEN 512

void do_more(FILE* );
int see_more(FILE* );

int main( int argc, char* argv[  ] )
  {
    FILE* fp;
    if ( argc == 1 )
      {
        do_more( stdin );
        
      }
    else
      {
        while ( --argc )
          {
            if ( ( fp = fopen( *++argv, "r" ) ) != NULL )
              {
                do_more( fp );
                fclose( fp );
                
              }
            else
              {
                exit( 1 );
                
              }
          }
      }
    return 0;
    
  }

void do_more(FILE* fp)
  {
    char line[ LINELEN ];
    int num_of_lines = 0;
    int reply;
    FILE* fp_tty;
    fp_tty = fopen( "/dev/tty", "r" );
    if( fp_tty == NULL )
      exit( 1 );
    
    while ( fgets( line, LINELEN, fp ) )
      {
        if ( num_of_lines == PAGLINE )
          {
            reply = see_more(fp_tty);
            if ( reply == 0 )
              break;
            num_of_lines -= reply;
            
          }
        if ( fputs( line, stdout ) == EOF )
          {
            exit( 1 );
            
          }
        num_of_lines++;
        
      }
  }

int see_more(FILE* cmd)
  {
    int c;
    printf( "\033[7m more? \033[m" );
    while ( ( c=getc(cmd) ) != EOF )
      {
        if ( c == 'q' )
          {
            return 0;
            
          }
        if ( c == ' ' )
          {
            return PAGLINE;
            
          }
        if ( c == '\n' )
          {
            return 1;
            
          }
      }
    return 0;
    
  }
