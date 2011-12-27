/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* $Header: /cvsroot/bfree-info/B-Free/Program/btron-pc/kernel/POSIX/lowlib/syscalls/geteuid.c,v 1.1 2011/12/27 17:13:35 liu1 Exp $ */
static char rcsid[] = "@(#)$Header: /cvsroot/bfree-info/B-Free/Program/btron-pc/kernel/POSIX/lowlib/syscalls/geteuid.c,v 1.1 2011/12/27 17:13:35 liu1 Exp $";

/*
 * $Log: geteuid.c,v $
 * Revision 1.1  2011/12/27 17:13:35  liu1
 * Initial Version.
 *
 * Revision 1.3  1999-03-21 00:57:33  monaka
 * Major fix. Many system calls runs correctly (...perhaps ;-). But signal and process functions are not yet.
 *
 * Revision 1.2  1999/02/19 08:59:20  monaka
 * added the parameter structure on.
 *
 * Revision 1.1  1997/08/31 13:10:44  night
 * 最初の登録
 *
 *
 *
 */


#include "../lowlib.h"




int
psys_geteuid (void *argp)
{
  ER			error;
  struct posix_request	req;
  struct posix_response	res;
#if 0
  struct psc_geteuid
    {
      /* void */
    } *args = (struct psc_geteuid *)argp;
#endif

  error = _make_connection(PSC_GETEUID, &req, &res);
  if (error != E_OK)
    {
      /* What should I do? */
    }

  else if (res.errno)
    {
      ERRNO = res.errno;
      return (-1);
    }

  return (res.status);
}
