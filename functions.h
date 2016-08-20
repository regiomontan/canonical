
 #ifndef  VZFUNC_H_INCLUDED
 #define  VZFUNC_H_INCLUDED

 #include <Fl/Fl_Text_Buffer.H>
 #include "str_numb_convert.h"

 void  print_canon( uint64_t        n,
                    Fl_Text_Buffer *textbuffer     );

 void  calculation( const int       min_iteration,
                    const int       max_iteration,
                    std::string     expression,
                    Fl_Text_Buffer *textbuffer     );

 #endif // VZFUNC_H_INCLUDED
