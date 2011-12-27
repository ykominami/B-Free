extern ER	_make_connection(W wOperation,
		 struct posix_request *req,
		 struct posix_response *res);

extern int	psys_noaction (void *argp);
extern int	psys_access (void *argp);
extern int	psys_chdir (void *argp);
extern int	psys_chmod (void *argp);
extern int	psys_chown (void *argp);
extern int	psys_close (void *argp);
extern int	psys_closedir (void *argp);
extern int	psys_creat (void *argp);
extern int	psys_dup (void *argp);
extern int	psys_dup2 (void *argp);
extern int	psys_exec (void *argp);
extern int	psys_exit (void *argp);
extern int	psys_fcntl (void *argp);
extern int	psys_fork (void *argp);
extern int	psys_getcwd (void *argp);
extern int	psys_getegid (void *argp);
extern int	psys_getenv (void *argp);
extern int	psys_geteuid (void *argp);
extern int	psys_getgid (void *argp);
extern int	psys_getgrgid (void *argp);
extern int	psys_getgrnam (void *argp);
extern int	psys_getgroups (void *argp);
extern int	psys_getlogin (void *argp);
extern int	psys_getpgrp (void *argp);
extern int	psys_getpid (void *argp);
extern int	psys_getppid (void *argp);
extern int	psys_getuid (void *argp);
extern int	psys_kill (void *argp);
extern int	psys_link (void *argp);
extern int	psys_lseek (void *argp);
extern int	psys_mkdir (void *argp);
extern int	psys_mkfifo (void *argp);
extern int	psys_open (void *argp);
extern int	psys_opendir (void *argp);
extern int	psys_pause (void *argp);
extern int	psys_pipe (void *argp);
extern int	psys_read (void *argp);
extern int	psys_readdir (void *argp);
extern int	psys_remove (void *argp);
extern int	psys_rename (void *argp);
extern int	psys_rewind (void *argp);
extern int	psys_rewinddir (void *argp);
extern int	psys_rmdir (void *argp);
extern int	psys_setgid (void *argp);
extern int	psys_setpgid (void *argp);
extern int	psys_setsid (void *argp);
extern int	psys_setuid (void *argp);
extern int	psys_sigaction (void *argp);
extern int	psys_sigaddset (void *argp);
extern int	psys_sigdelset (void *argp);
extern int	psys_sigemptyset (void *argp);
extern int	psys_sigfillset (void *argp);
extern int	psys_sigismember (void *argp);
extern int	psys_siglongjmp (void *argp);
extern int	psys_sigpending (void *argp);
extern int	psys_sigprocmask (void *argp);
extern int	psys_sigsetjmp (void *argp);
extern int	psys_sigsuspend (void *argp);
extern int	psys_sleep (void *argp);
extern int	psys_stat (void *argp);
extern int	psys_time (void *argp);
extern int	psys_times (void *argp);
extern int	psys_ttyname (void *argp);
extern int	psys_tzset (void *argp);
extern int	psys_umask (void *argp);
extern int	psys_uname (void *argp);
extern int	psys_unlink (void *argp);
extern int	psys_utime (void *argp);
extern int	psys_waitpid (void *argp);
extern int	psys_write (void *argp);
extern int	psys_mount (void *argp);
extern int	psys_umount (void *argp);
extern int	psys_memory (void *argp);
extern int	psys_mountroot (void *argp);
extern int	psys_statfs (void *argp);
extern int	psys_misc (void *argp);
extern int	psys_getdents (void *argp);
