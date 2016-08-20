
 //========================================================================
 // This is example code from Chapter 23.2 "Strings" of
 // "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
 // Код можно обобщить на любой тип, имеющий оператор <<.
 //========================================================================

 #ifndef  STR_NUMB_CONVERT_H_INCLUDED
 #define  STR_NUMB_CONVERT_H_INCLUDED

 #include <iostream>
 #include <sstream>
 #include <typeinfo>

 template<class T> std::string to_string( const T& t );
 //------------------------------------------------------------------------
 // класс для ошибочной конвертации строк
 //------------------------------------------------------------------------
 struct  bad_from_string : std::bad_cast
 {
        const char*  what() const throw() // override bad_cast's what();
        {
         return  "bad cast from string";
        }
 };
 //------------------------------------------------------------------------
 template<class T> T  from_string ( const std::string &s );
 //------------------------------------------------------------------------
 double               str_2_double( const char* str );
 //-------------------------------------------------------------------------
 const char*          double_2_str( const double d  );
 //-------------------------------------------------------------------------

 #endif // STR_NUMB_CONVERT_H_INCLUDED
