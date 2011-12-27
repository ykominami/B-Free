/*

B-Free Project $B$N@8@.J*$O(B GNU Generic PUBLIC LICENSE $B$K=>$$$^$9!#(B

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/*
 * $Log: getgrgid.c,v $
 * Revision 1.1  2011/12/27 17:13:35  liu1
 * Initial Version.
 *
 * Revision 1.2  1999-03-21 14:49:35  monaka
 * Now works well...maybe. You know I'm honest when you got fork/exec system call.
 *
 * Revision 1.1  1999/03/21 14:01:51  monaka
 * They are separated from syscall.c. Still no major changes available.
 *
 */

#include "posix.h"

W
psc_getgrgid_f (struct posix_request *req)
{
  W	err;
  W	grgid;

  err = proc_get_uid (req->procid, &grgid);
  if (err)
    {
      put_response (req, err, -1, 0, 0);
      return (FAIL);
    }
  
  put_response (req, EP_OK, grgid, 0, 0);
  return (SUCCESS);
}  
