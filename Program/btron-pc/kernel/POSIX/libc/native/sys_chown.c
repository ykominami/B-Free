/*

B-Free Project �̐������� GNU Generic PUBLIC LICENSE �ɏ]���܂��B

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* POSIX Library misc function.
*/

/* @(#)$Header: /cvsroot/bfree-info/B-Free/Program/btron-pc/kernel/POSIX/libc/native/sys_chown.c,v 1.1 2011/12/27 17:13:35 liu1 Exp $  */
static char rcsid[] = "@(#)$Id: sys_chown.c,v 1.1 2011/12/27 17:13:35 liu1 Exp $";


#include "../native.h"


/* chown 
 *
 */
int
chown (char *path, int owner)
{
  return (call_lowlib (PSC_CHOWN, strlen (path), path, owner));
}

