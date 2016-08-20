
 #include "main_form.h"
 #include <FL/fl_ask.H>
 #include "resource.h"    //иконка, и включать в проект resource.rc;
 #include <fstream>
 #include "functions.h"

 //------------------------------------------------------------------------
 Fl_Text_Buffer* mainForm::calc_function( const int    min_iteration,
                                          const int    max_iteration,
                                          std::string  expression     )
 {
  calculation( min_iteration, max_iteration, expression, textbuffer );
 }
 //------------------------------------------------------------------------
 void  mainForm::callback_button1( Fl_Return_Button* o, void* v )
 {
  mainForm  *forma = (mainForm*)( o->parent()->user_data() );
  forma->textbuffer->remove( 0, forma->textbuffer->length()         );
  forma->calc_function     ( str_2_double( forma->minIn->value() ),
                             str_2_double( forma->maxIn->value() ),
                             forma->express->value()                );
 }
 //------------------------------------------------------------------------
 void  mainForm::callback_help( Fl_Toggle_Button* o, void* v )
 {
  mainForm  *forma = (mainForm*)( o->parent()->user_data() );
       if ( !forma->help_dialog->visible() )
       forma->help_dialog->show();
 }
 //------------------------------------------------------------------------
 // масштабирование, перерисовка при изменении размера шрифта
 //------------------------------------------------------------------------
 void  mainForm::callback_counter( Fl_Simple_Counter* o, void* v )
 {
  mainForm  *forma = (mainForm*)( o->parent()->user_data() );
  forma->scale_text = forma->font_counter->value();
       if ( !forma->mainWindow->visible() )
       return;
  forma->form_width  = forma->mainWindow->w();
  forma->form_height = forma->mainWindow->h();
  forma->form_pos_x  = forma->mainWindow->x_root();
  forma->form_pos_y  = forma->mainWindow->y_root();
  forma->mainWindow->clear();
  forma->mainWindow->hide ();
  forma->help_dialog->hide();
  forma->init();
  forma->mainWindow->show ();
 }
 //-------------------------------------------------------------------------
 // считывание параметров GUI из файла initfile.ini
 //-------------------------------------------------------------------------
 bool  mainForm::init_readGUI()
 {
  int      data   = 0;
  double   fdata  = 0.0;
  std::ifstream inifile;
  inifile.open( "initfile.ini" );
        if ( !inifile )
        {
         fl_message ( "Failed reading inifile" );
         return  false;
        }
        else
        {
         inifile >> data;  form_width  = data;
         inifile >> data;  form_height = data;
         inifile >> data;  form_pos_x  = data;
         inifile >> data;  form_pos_y  = data;
         inifile >> fdata; scale_text  = fdata;
         inifile.close();
        }
  return  true;
 }
 //-------------------------------------------------------------------------
 // сохранение параметров GUI в файл initfile.ini
 //-------------------------------------------------------------------------
 bool  mainForm::init_writeGUI()
 {
  std::ofstream  inifile( "initfile.ini" );
        if ( !inifile )
        {
         fl_message ( "Failed writing inifile" );
         return  false;
        }
        else
        {
         inifile << form_width  << std::endl;
         inifile << form_height << std::endl;
         inifile << form_pos_x  << std::endl;
         inifile << form_pos_y  << std::endl;
         inifile << scale_text  << std::endl;
         inifile.close();
        }
   return  true;
  }
 //-------------------------------------------------------------------------
 void  mainForm::init_button1( const int  x0,    const int  y0,
                               const int  width,  const int  height )
 {
  button1  = new  Fl_Return_Button( x0, y0,width, height, "считать" );
  button1->labelsize( size_font*scale_text           );
  button1->tooltip  ( "or <Enter>"                   );
  button1->labeltype( FL_ENGRAVED_LABEL              );
  //button1->labeltype   ( FL_EMBOSSED_LABEL        );
  //button1->labelfont   ( FL_TIMES                 );
  //button1->labelsize   ( 4*h_band/5               );
  button1->box      ( FL_ENGRAVED_BOX                );
  button1->callback ( (Fl_Callback*)callback_button1 );
 }
 //-------------------------------------------------------------------------
 void  mainForm::init_help( const int  x0,     const int  y0,
                            const int  width,  const int  height )
 {
  help_button  = new  Fl_Toggle_Button( x0, y0,width, height, "help" );
  help_button->labelsize( size_font*scale_text        );
  help_button->tooltip  ( "or <Enter>"                );
  help_button->labeltype( FL_ENGRAVED_LABEL           );
  help_button->box      ( FL_ENGRAVED_BOX             );
  help_button->callback ( (Fl_Callback*)callback_help );
 }
 //-------------------------------------------------------------------------
 void  mainForm::init_express( const int  x0,     const int  y0,
                               const int  width,  const int  height )
 {
  express = new  Fl_Input( x0, y0,width, height );
  express->value   ( "n"                  );
  express->box     ( FL_ENGRAVED_BOX      );
  express->textsize( size_font*scale_text );
  express->tooltip ( "f(n)"               );
 }
 //-------------------------------------------------------------------------
 void  mainForm::init_minIn( const int  x0,     const int  y0,
                        const int  width,  const int  height )
 {
  minIn = new  Fl_Int_Input( x0, y0,width, height );
  minIn->value   ( "min n"    );
  minIn->box     ( FL_ENGRAVED_BOX      );
  minIn->textsize( size_font*scale_text );
  minIn->tooltip ( "minimum n"          );
 }
 //-------------------------------------------------------------------------
 void  mainForm::init_maxIn( const int  x0,     const int  y0,
                        const int  width,  const int  height )
 {
  maxIn = new  Fl_Int_Input( x0, y0,width, height );
  maxIn->value   ( "max n"   );
  maxIn->box     ( FL_ENGRAVED_BOX      );
  maxIn->textsize( size_font*scale_text );
  maxIn->tooltip ( "maximum n"          );
 }
 //-------------------------------------------------------------------------
 void  mainForm::init_counter( const int  x0,     const int  y0,
                               const int  width,  const int  height )
 {
  font_counter = new Fl_Simple_Counter( x0, y0, width, height );
  font_counter->step    ( 0.1                            );
  font_counter->textsize( 0.9*size_font*scale_text       );
  font_counter->range   ( 0.5, 2                         );
  font_counter->value   ( scale_text                     );
  font_counter->tooltip ( "scale text"                   );
  font_counter->box     ( FL_ENGRAVED_BOX                );
  font_counter->callback( (Fl_Callback*)callback_counter );
 }
 //-------------------------------------------------------------------------
 void  mainForm::init_textOut1 ( const int  x0,     const int  y0,
                                 const int  width,  const int  height )
 {
  textOut1   = new Fl_Text_Display( x0, y0, width, height );
  textbuffer = new Fl_Text_Buffer ( 0                     );
  textOut1->textsize       ( size_font*scale_text );
  textOut1->box            ( FL_ENGRAVED_BOX      );
  textOut1->scrollbar_align( FL_ALIGN_RIGHT       );
  textOut1->buffer         ( textbuffer           );
 }
 //-------------------------------------------------------------------------
 void  mainForm::init()
 {
  const int  screen_width  = Fl::w();
  const int  screen_height = Fl::h();
  Fl::set_font( FL_COURIER, size_font );  // FL_HELVETICA, FL_TIMES, FL_COURIER
  mainWindow = new Fl_Window( form_width, form_height,
                              " каноническое разложение" );
  // диапазон изменения размеров окна его позиция на экране:
  mainWindow->size_range( screen_width/4, screen_height/4,
                          screen_width,   screen_height    );
  mainWindow->position  ( form_pos_x,     form_pos_y       );
  // инициализация help-файла: ============================================
  help_dialog = new Fl_Help_Dialog();
  help_dialog->load    ( "./help/index.html"  );
  help_dialog->textsize( size_font*scale_text );
  help_dialog->hide    (                      );
  // величины для разметки окна и размеров его компонент:==================
  const int  shift       = size_font;                 // прокладка;
  const int  comp_width  = form_width - 2*shift;      // ширина компонент;
  const int  comp_height = 3*size_font/2*scale_text;  // высота компонент;
  mainWindow->user_data( (void*)(this) );
  mainWindow->begin();
  const int counter_width = 4*size_font*scale_text;
  // поле ввода выражения:=================================================
  init_express ( shift,                              shift,
                 comp_width - counter_width - shift, comp_height        );
  // поле ввода минимума диапазона счета: =================================
  init_minIn   ( shift,                  2*shift + comp_height,
                 comp_width/2 - shift,   comp_height                    );
  // поле ввода максимума диапазона счета: ================================
  init_maxIn   ( 2*shift + comp_width/2, 2*shift + comp_height,
                 comp_width/2 - shift,   comp_height                    );
  // кнопка ПУСК: =========================================================
  init_button1 ( shift,           5*shift + comp_height,
                 comp_width*2/3,  comp_height                           );
  // кнопка HELP: =========================================================
  init_help    ( shift + comp_width*2/3 + shift, 5*shift + comp_height,
                 comp_width/3 - shift,           comp_height            );
  // счетчик для масштабирования шрифта: ==================================
  init_counter ( form_width - counter_width - shift, shift,
                 counter_width,                      4*comp_height/5    );
  // мультистроковый вывод: ===============================================
  init_textOut1( shift,      7*shift + 2*comp_height,
                 comp_width, form_height - 8*shift - 2*comp_height      );
  //=======================================================================
  mainWindow->resizable( mainWindow ); // масштабирование при изменении окна;
  mainWindow->icon( (char*)LoadIcon( fl_display,   // иконка;
                                     MAKEINTRESOURCE( IDI_ICON1 ) ) );
  mainWindow->end();
 }
 //-------------------------------------------------------------------------
 mainForm::mainForm()
          :size_font ( 14  ),
           scale_text( 1.0 )
 {
  const int  screen_width  = Fl::w();
  const int  screen_height = Fl::h();
        if ( !init_readGUI() )           // если файл с настройками GUI
        {                                // не существует или поврежден;
         form_width  = screen_height;
         form_height = screen_height/2;
         form_pos_x  = ( screen_width  - form_width  )/2;
         form_pos_y  = ( screen_height - form_height )/2;
        }
  init();
 }
 //-------------------------------------------------------------------------
 void  mainForm::showWindow( int argc, char** argv )
 {
  mainWindow->show( argc, argv );
 }
 //-------------------------------------------------------------------------
 mainForm::~mainForm()
 {
  form_width  = mainWindow->w();
  form_height = mainWindow->h();
  form_pos_x  = mainWindow->x_root();
  form_pos_y  = mainWindow->y_root();
  init_writeGUI();
  delete  mainWindow;
 }
 //-------------------------------------------------------------------------
