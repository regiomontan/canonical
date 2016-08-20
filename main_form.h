
 #ifndef VZMAIN_FORM_H
 #define VZMAIN_FORM_H

 #include <FL/Fl.H>
 #include <Fl/Fl_Window.h>
 #include <Fl/Fl_Return_Button.h>
 #include <Fl/Fl_Toggle_Button.H>
 #include <Fl/Fl_Input.H>
 #include <Fl/Fl_Int_Input.h>
 #include <Fl/Fl_Simple_Counter.h>
 #include <FL/Fl_Text_Buffer.H>
 #include <Fl/Fl_Text_Display.h>
 #include <Fl/Fl_Help_Dialog.H>
 #include <iostream>
 #include <cstring>
 //------------------------------------------------------------------------
 //  ____________________________________________________
 // |                                                    |
 // |  ______________________________    ______________  |
 // | |             numbIn1          |  | font_counter | |
 // | |______________________________|  |______________| |
 // |  _______________________    _____________________  |
 // | |       minIn           |  |        maxIn        | |
 // | |_______________________|  |_____________________| |
 // |  ___________________________      _______________  |
 // | |     button1               |    | help_button   | |
 // | |___________________________|    |_______________| |
 // |                                                    |
 // |  ________________________________________________  |
 // | |                                                | |
 // | |                                                | |
 // | |                   textOut1                     | |
 // | |                                                | |
 // | |                                                | |
 // | |________________________________________________| |
 // |____________________________________________________|
 //------------------------------------------------------------------------
 // Размеры шрифта и элементов GUI запоминаются и хранятся в файле
 // initfile.ini тек. директории.
 //------------------------------------------------------------------------
 class  mainForm
 {
  int                form_width;
  int                form_height;
  int                form_pos_x;
  int                form_pos_y;
  double             scale_text;
  const Fl_Fontsize  size_font;
  Fl_Return_Button  *button1;
  Fl_Toggle_Button  *help_button;
  // для устранения глюков (undefined reference...) при линковке
  // Fl_Help_Dialog в Linker Setting  указать Link Libraries:
  // libfltk_images.a,libfltk_jpeg.a, libfltk_png.a, libfltk_z.a,
  // libfltk.a (в таком порядке!)
  Fl_Help_Dialog    *help_dialog;
  Fl_Input          *express;
  Fl_Int_Input      *minIn;
  Fl_Int_Input      *maxIn;
  Fl_Simple_Counter *font_counter;
  Fl_Text_Display   *textOut1;
  Fl_Text_Buffer    *textbuffer;
  Fl_Text_Buffer*    calc_function( const int    min_iteration,
                                    const int    max_iteration,
                                    std::string  expression                );
  static void     callback_button1( Fl_Return_Button*,   void*             );
  static void     callback_help   ( Fl_Toggle_Button*,   void*             );
  static void     callback_counter( Fl_Simple_Counter*,  void*             );
  void            init_button1    ( const int  x0,       const int  y0,
                                    const int  width,    const int  height );
  void            init_help       ( const int  x0,       const int  y0,
                                    const int  width,    const int  height );
  void            init_express    ( const int  x0,       const int  y0,
                                    const int  width,    const int  height );
  void            init_minIn      ( const int  x0,       const int  y0,
                                    const int  width,    const int  height );
  void            init_maxIn      ( const int  x0,       const int  y0,
                                    const int  width,    const int  height );
  void            init_counter    ( const int  x0,       const int  y0,
                                    const int  width,    const int  height );
  void            init_textOut1   ( const int  x0,       const int  y0,
                                    const int  width,    const int  height );
  bool            init_writeGUI   ( );
  bool            init_readGUI    ( );
  void            init            ( );
  public:
                  mainForm        ( );
  virtual        ~mainForm        ( );
  Fl_Window      *mainWindow;
  void            showWindow      ( int argc, char** argv                  );
 };
 //--------------------------------------------------------------------------
 #endif
