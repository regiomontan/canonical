
 #include "functions.h"
 #include "muparser/muParser.h"
 #include <FL/fl_ask.H>
 #include <cstring>
 //-------------------------------------------------------------------------------
 // Каноническое разложение числа n
 //-------------------------------------------------------------------------------
 void  print_canon( uint64_t  n, Fl_Text_Buffer *textbuffer )
 {
        if ( n == 1 )  textbuffer->append( "1" );
        if ( n == 0 )  textbuffer->append( "0" );
  unsigned long long   d = 1;
        while ( ++d <= n )
        {
         unsigned int  degree_d = 0;
               if  ( !( n % d ) )
               {
                      do
                      {
                       n /= d;
                       degree_d++;
                      }
                      while ( !( n % d ) );
                }
                if  ( degree_d )
                {
                 textbuffer->append( double_2_str( d )        );
                 textbuffer->append( "^"                      );
                 textbuffer->append( double_2_str( degree_d ) );
                 textbuffer->append( " "                      );
                }
        }
 }
 //--------------------------------------------------------------------
 void  calculation( const int       min_iteration,
                    const int       max_iteration,
                    std::string     expression,
                    Fl_Text_Buffer *textbuffer     )
 {
  mu::Parser  parser;
  double      n = 3;
  parser.DefineVar( "n", &n );
  parser.SetExpr( expression );
         for ( n = min_iteration; n <=  max_iteration; ++n )
         {
                try
                {
                 uint64_t  res = parser.Eval();
                 textbuffer->append( "f("                );
                 textbuffer->append( double_2_str( n )   );
                 textbuffer->append( ") = "              );
                 textbuffer->append( double_2_str( res ) );
                 textbuffer->append( " = "               );
                 print_canon       ( res, textbuffer     );
                 textbuffer->append( "\n"                );
                }
                catch ( mu::Parser::exception_type  &e )
                {
                 fl_message( "Parsing error: \n %s", e.GetMsg().c_str() );
                 break;
                }
         }
  }
 //--------------------------------------------------------------------
