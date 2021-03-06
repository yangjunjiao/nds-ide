//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'goil_obj_counter.h'                          *
//                        Generated by version 2.0.0                         *
//                       july 7th, 2010, at 17h16'28"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_obj_counter_DEFINED
#define goil_obj_counter_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/GGS__header.h"
#include "goil_lexique.h"

//---------------------------------------------------------------------------*

// Include imported semantics
#include "goil_options.h"
#include "goil_semantics.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                Parser class goil_obj_counter declaration                  *
//                                                                           *
//---------------------------------------------------------------------------*

class goil_obj_counter {
  public : virtual ~goil_obj_counter (void) {}

  protected : virtual void nt_counter_ (C_Lexique_goil_5F_lexique &,
                                GGS_counter_map  &) = 0 ;

  protected : virtual void nt_counter_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_counter_5F_parameters_ (C_Lexique_goil_5F_lexique &,
                                GGS_basic_type  &,
                                GGS_basic_type  &,
                                GGS_basic_type  &,
                                GGS_lstring  &,
                                GGS_lstringlist  &,
                                GGS_counter_type  &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_counter_5F_parameters_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_counter_5F_type_5F_attrs_ (C_Lexique_goil_5F_lexique &,
                                GGS_counter_type  &) = 0 ;

  protected : virtual void nt_counter_5F_type_5F_attrs_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_description_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_description_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_counter_counter_i0_ (C_Lexique_goil_5F_lexique &,
                                GGS_counter_map  &) ;

  protected : void rule_goil_5F_obj_5F_counter_counter_i0_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_counter_counter_5F_parameters_i1_ (C_Lexique_goil_5F_lexique &,
                                GGS_basic_type  &,
                                GGS_basic_type  &,
                                GGS_basic_type  &,
                                GGS_lstring  &,
                                GGS_lstringlist  &,
                                GGS_counter_type  &,
                                GGS_lstring  &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_counter_0 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_counter_1 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_counter_2 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_counter_counter_5F_parameters_i1_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_counter_counter_5F_type_5F_attrs_i2_ (C_Lexique_goil_5F_lexique &,
                                GGS_counter_type  &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_counter_3 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_counter_4 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_counter_5 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_counter_6 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_counter_7 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_counter_counter_5F_type_5F_attrs_i2_parse (C_Lexique_goil_5F_lexique & inLexique) ;

} ;

//---------------------------------------------------------------------------*

#endif
