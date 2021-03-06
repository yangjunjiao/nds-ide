/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protege par la loi sur la propriete intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline external communication functions
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */
 
#ifndef TPL_COM_EXTERNAL_COM
#define TPL_COM_EXTERNAL_COM

#include "tpl_com_mo.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(tpl_status, OS_CODE) tpl_receive_static_external_unqueued_message(
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)   rmo,
  P2CONST(tpl_com_data, AUTOMATIC, OS_VAR)  data);

FUNC(tpl_status, OS_CODE) tpl_send_static_external_message(
  CONSTP2CONST(void, AUTOMATIC, OS_CONST) smo,
  P2VAR(tpl_com_data, AUTOMATIC, OS_VAR)  data);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif
/* TPL_COM_EXTERNAL_COM */
