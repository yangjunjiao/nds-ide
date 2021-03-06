/**
 * @file tpl_os_std_types_generic.h
 *
 * @section descr File description
 *
 * Trampoline standard types. Here for MISRA rule 13 compliance
 * and for platform specific type definition
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date: 2010-03-29 16:36:09 +0200 (Lun, 29 mar 2010) $
 * $Rev: 1111 $
 * $Author: fp $
 * $URL: https://trampoline.rts-software.org/svn/trunk/machines/arm/tpl_os_std_types_generic.h $
 */

#ifndef TPL_OS_STD_TYPES_GENERIC_H
#define TPL_OS_STD_TYPES_GENERIC_H

/**
 * @typedef u8
 *
 * 8 bits unsigned number
 */
typedef unsigned char   u8;

/**
 * @typedef s8
 *
 * 8 bits signed number
 */
typedef signed char     s8;

/**
 * @typedef u16
 *
 * 16 bits unsigned number
 */
typedef unsigned short  u16;

/**
 * @typedef s16
 *
 * 16 bits signed number
 */
typedef signed short    s16;

/**
 * @typedef u32
 *
 * 32 bits unsigned number
 */
typedef unsigned long   u32;

/**
 * @typedef s32
 *
 * 32 bits signed number
 */
typedef signed long     s32;

/**
 * @typedef u64
 *
 * 64 bits unsigned integer
 */
typedef unsigned long long u64;

/**
 * @typedef s64
 *
 * 64 bits signed integer
 */
typedef signed long long s64;

#endif /* TPL_OS_STD_TYPES_GENERIC_H */

/* End of file tpl_os_std_generic.h */

