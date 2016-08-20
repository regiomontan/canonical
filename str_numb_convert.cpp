

 #include "str_numb_convert.h"
//------------------------------------------------------------------------
 template<class T> std::string to_string( const T& t )
 {
  std::ostringstream os;
  os << t;
  return  os.str();
 }
 //------------------------------------------------------------------------
 template<class T> T from_string ( const std::string &s )
 {
  std::istringstream  is( s );
  T t;
        if ( !( is >> t ) ) throw  bad_from_string();
  return  t;
 }
 //------------------------------------------------------------------------
 double  str_2_double ( const char* str )
 {
   double  x = 0.0;
    try
    {
     x = from_string<double>( str );
    }
    catch ( std::exception& e )
    {
     std::cerr << "error: " << e.what() << '\n';
     return  1;
    }
    catch (...)
    {
     std::cerr << "Oops: unknown exception!\n";
     return  2;
    }
  return x;
 }
 //-------------------------------------------------------------------------
 const char* double_2_str( const double d )
 {
  return  to_string( d ).c_str();
 }
 //-------------------------------------------------------------------------
