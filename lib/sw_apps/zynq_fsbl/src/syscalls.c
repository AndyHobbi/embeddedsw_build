#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <reent.h>

/* Minimal syscall stubs for newlib (bare-metal, Xilinx FSBL) */

void *__dso_handle;

int _close(int file) { return -1; }
int _fstat(int file, struct stat *st) { st->st_mode = S_IFCHR; return 0; }
int _isatty(int file) { return 1; }
int _lseek(int file, int ptr, int dir) { return 0; }
int _open(const char *name, int flags, int mode) { return -1; }
int _read(int file, char *ptr, int len) { return 0; }
int _write(int file, char *ptr, int len) { return len; }
int _getpid(void) { return 1; }
int _kill(int pid, int sig) { errno = EINVAL; return -1; }
void _exit(int status) { while (1) {} }
caddr_t _sbrk(int incr) { return (caddr_t)-1; }
int _unlink(const char *name) { return -1; }
int _stat(const char *file, struct stat *st) { st->st_mode = S_IFCHR; return 0; }
int _times(struct tms *buf) { return -1; }
int _wait(int *status) { errno = ECHILD; return -1; }
int _fork(void) { errno = EAGAIN; return -1; }
int _execve(const char *name, char *const argv[], char *const env[]) { errno = ENOMEM; return -1; }
int _gettimeofday(struct timeval *tv, void *tzvp) { return -1; }
int _rename(const char *old, const char *new) { return -1; }
int _link(const char *old, const char *new) { return -1; }
int _system(const char *s) { return -1; }
void _raise(void) {}
void _abort(void) { while(1){} }
void _srandom(unsigned int seed) {}
int _getpagesize(void) { return 4096; }
int _dup(int oldfd) { return -1; }
