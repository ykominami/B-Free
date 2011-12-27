/*

B-Free Project ������ʪ�� GNU Generic PUBLIC LICENSE �˽����ޤ���

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* 
 * ITRON �����ΥǥХ����ɥ饤�Ф����
 *
 */

#include "types.h"
#include "config.h"

extern ER	init_echo ();
extern ER	init_rs232c ();
extern ER	init_pd7220 (void);
extern ER	init_keyboard (void);

ER (*devices[MAX_DEVICE])() = {
  init_keyboard,
  init_echo,
  0,
/*
  init_rs232c,
  init_pd7220
 */
};

W ndevice = (sizeof (devices) / sizeof (devices[0]));