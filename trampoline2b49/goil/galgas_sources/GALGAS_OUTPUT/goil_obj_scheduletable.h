//---------------------------------------------------------------------------*
//                                                                           *
//                     File 'goil_obj_scheduletable.h'                       *
//                        Generated by version 2.0.0                         *
//                       july 7th, 2010, at 17h17'6"                         *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_obj_scheduletable_DEFINED
#define goil_obj_scheduletable_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/GGS__header.h"
#include "goil_lexique.h"

//---------------------------------------------------------------------------*

// Include imported semantics
#include "goil_basic_types.h"
#include "goil_options.h"
#include "goil_semantics.h"
#include "goil_types_action.h"
#include "goil_types_scheduletable.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//             Parser class goil_obj_scheduletable declaration               *
//                                                                           *
//---------------------------------------------------------------------------*

class goil_obj_scheduletable {
  public : virtual ~goil_obj_scheduletable (void) {}

  protected : virtual void nt_scheduletable_ (C_Lexique_goil_5F_lexique &,
                                GGS_scheduletable_map  &) = 0 ;

  protected : virtual void nt_scheduletable_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_scheduletable_5F_parameters_ (C_Lexique_goil_5F_lexique &,
                                GGS_scheduletable_obj  &,
                                GGS_lstring  ) = 0 ;

  protected : virtual void nt_scheduletable_5F_parameters_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_st_5F_autostart_5F_rel_5F_params_ (C_Lexique_goil_5F_lexique &,
                                GGS_autostart_obj  &) = 0 ;

  protected : virtual void nt_st_5F_autostart_5F_rel_5F_params_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_st_5F_autostart_5F_abs_5F_params_ (C_Lexique_goil_5F_lexique &,
                                GGS_autostart_obj  &) = 0 ;

  protected : virtual void nt_st_5F_autostart_5F_abs_5F_params_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_st_5F_autostart_5F_sync_5F_params_ (C_Lexique_goil_5F_lexique &,
                                GGS_autostart_obj  &) = 0 ;

  protected : virtual void nt_st_5F_autostart_5F_sync_5F_params_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_ltgt_5F_sync_5F_params_ (C_Lexique_goil_5F_lexique &,
                                GGS_ltgt_sync_obj  &) = 0 ;

  protected : virtual void nt_ltgt_5F_sync_5F_params_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_st_5F_expiry_5F_pt_5F_params_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  ,
                                GGS_expiry_point_obj  &) = 0 ;

  protected : virtual void nt_st_5F_expiry_5F_pt_5F_params_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_st_5F_action_5F_params_ (C_Lexique_goil_5F_lexique &,
                                GGS_action_list  &) = 0 ;

  protected : virtual void nt_st_5F_action_5F_params_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_description_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_description_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_boolean_ (C_Lexique_goil_5F_lexique &,
                                GGS_lbool  &) = 0 ;

  protected : virtual void nt_boolean_parse (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_scheduletable_scheduletable_i0_ (C_Lexique_goil_5F_lexique &,
                                GGS_scheduletable_map  &) ;

  protected : void rule_goil_5F_obj_5F_scheduletable_scheduletable_i0_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_scheduletable_scheduletable_5F_parameters_i1_ (C_Lexique_goil_5F_lexique &,
                                GGS_scheduletable_obj  &,
                                GGS_lstring  ) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_0 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_1 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_2 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_3 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_scheduletable_scheduletable_5F_parameters_i1_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_scheduletable_st_5F_autostart_5F_rel_5F_params_i2_ (C_Lexique_goil_5F_lexique &,
                                GGS_autostart_obj  &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_4 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_scheduletable_st_5F_autostart_5F_rel_5F_params_i2_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_scheduletable_st_5F_autostart_5F_abs_5F_params_i3_ (C_Lexique_goil_5F_lexique &,
                                GGS_autostart_obj  &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_5 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_scheduletable_st_5F_autostart_5F_abs_5F_params_i3_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_scheduletable_st_5F_autostart_5F_sync_5F_params_i4_ (C_Lexique_goil_5F_lexique &,
                                GGS_autostart_obj  &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_6 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_scheduletable_st_5F_autostart_5F_sync_5F_params_i4_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_scheduletable_ltgt_5F_sync_5F_params_i5_ (C_Lexique_goil_5F_lexique &,
                                GGS_ltgt_sync_obj  &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_7 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_scheduletable_ltgt_5F_sync_5F_params_i5_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_scheduletable_st_5F_expiry_5F_pt_5F_params_i6_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  ,
                                GGS_expiry_point_obj  &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_8 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_9 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_10 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_scheduletable_st_5F_expiry_5F_pt_5F_params_i6_parse (C_Lexique_goil_5F_lexique & inLexique) ;

  protected : void rule_goil_5F_obj_5F_scheduletable_st_5F_action_5F_params_i7_ (C_Lexique_goil_5F_lexique &,
                                GGS_action_list  &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_11 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_12 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_13 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_scheduletable_st_5F_action_5F_params_i7_parse (C_Lexique_goil_5F_lexique & inLexique) ;

} ;

//---------------------------------------------------------------------------*

#endif
