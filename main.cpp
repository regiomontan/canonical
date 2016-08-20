
 //--------------------------------------------------------------------
 // В.Зенкин 2013
 //--------------------------------------------------------------------
 #include "main_form.h"
 int  main( int  argc, char  **argv )
 {
  mainForm  *gui = new  mainForm();
  gui->showWindow( argc, argv );
  Fl::run();
       if ( !gui->mainWindow->visible() )
       delete  gui;
  return  0;
 }
 //--------------------------------------------------------------------
