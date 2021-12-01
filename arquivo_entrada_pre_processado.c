#ifndef _STDIO_H_
#define	_STDIO_H_
#include "_ansi.h"
#define	_FSTDIO			
#define __need___va_list
#include <stdarg.h>
#include <stdarg.h>
#endif
#endif 
#include <sys/reent.h>
#include <sys/types.h>
_BEGIN_STD_C
#if !defined(__FILE_defined)
typedef __FILE FILE;
# define __FILE_defined
#endif
#ifdef __CYGWIN__
typedef _fpos64_t fpos_t;
#else
typedef _fpos_t fpos_t;
#ifdef __LARGE64_FILES
typedef _fpos64_t fpos64_t;
#endif
#endif 
#define	__SNBF	0x0002		
#define	__SWR	0x0008		
#define	__SRW	0x0010		
#define	__SERR	0x0040		
#define	__SAPP	0x0100		
#define	__SOPT	0x0400		
#define	__SOFF	0x1000		
#if defined(__CYGWIN__)
#  define __SCLE  0x4000        
#define	__SWID	0x2000		
#define	_IOFBF	0		
#define	_IONBF	2		
#endif
#ifndef SEEK_CUR
#define	SEEK_CUR	1	
#endif
#define	TMP_MAX		26
#define	stdin	(_REENT->_stdin)
#define	stdout	(_REENT->_stdout)
#define	stderr	(_REENT->_stderr)
#define _stdin_r(x)	((x)->_stdin)
#define _stdout_r(x)	((x)->_stdout)
#define _stderr_r(x)	((x)->_stderr)
#ifndef __VALIST
#ifdef __GNUC__
#define __VALIST __gnuc_va_list
#else
#define __VALIST char*
#endif
#endif
#if __POSIX_VISIBLE
char *	ctermid (char *);
#endif
#if __GNU_VISIBLE || (__XSI_VISIBLE && __XSI_VISIBLE < 600)
char *	cuserid (char *);
#endif
FILE *	tmpfile (void);
char *	tmpnam (char *);
#if __BSD_VISIBLE || __XSI_VISIBLE || __POSIX_VISIBLE >= 200112
char *	tempnam (const char *, const char *) __malloc_like __result_use_check;
#endif
int	fclose (FILE *);
int	fflush (FILE *);
FILE *	freopen (const char *__restrict, const char *__restrict, FILE *__restrict);
void	setbuf (FILE *__restrict, char *__restrict);
int	setvbuf (FILE *__restrict, char *__restrict, int, size_t);
int	fprintf (FILE *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
int	fscanf (FILE *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 3)));
int	printf (const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 1, 2)));
int	scanf (const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 1, 2)));
int	sscanf (const char *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 3)));
int	vfprintf (FILE *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
int	vprintf (const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 1, 0)));
int	vsprintf (char *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
int	fgetc (FILE *);
char *  fgets (char *__restrict, int, FILE *__restrict);
int	fputc (int, FILE *);
int	fputs (const char *__restrict, FILE *__restrict);
int	getc (FILE *);
int	getchar (void);
char *  gets (char *);
int	putc (int, FILE *);
int	putchar (int);
int	puts (const char *);
int	ungetc (int, FILE *);
size_t	fread (void *__restrict, size_t _size, size_t _n, FILE *__restrict);
size_t	fwrite (const void *__restrict , size_t _size, size_t _n, FILE *);
#ifdef _COMPILING_NEWLIB
int	fgetpos (FILE *, _fpos_t *);
#else
int	fgetpos (FILE *__restrict, fpos_t *__restrict);
#endif
int	fseek (FILE *, long, int);
#ifdef _COMPILING_NEWLIB
int	fsetpos (FILE *, const _fpos_t *);
#else
int	fsetpos (FILE *, const fpos_t *);
#endif
long	ftell ( FILE *);
void	rewind (FILE *);
void	clearerr (FILE *);
int	feof (FILE *);
int	ferror (FILE *);
void    perror (const char *);
#ifndef _REENT_ONLY
FILE *	fopen (const char *__restrict _name, const char *__restrict _type);
int	sprintf (char *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
int	remove (const char *);
int	rename (const char *, const char *);
#ifdef _COMPILING_NEWLIB
int	_rename (const char *, const char *);
#endif
#endif
#if __LARGEFILE_VISIBLE || __POSIX_VISIBLE >= 200112
#ifdef _COMPILING_NEWLIB
int	fseeko (FILE *, _off_t, int);
_off_t	ftello (FILE *);
#else
int	fseeko (FILE *, off_t, int);
off_t	ftello (FILE *);
#endif
#endif
#if __GNU_VISIBLE
int	fcloseall (void);
#endif
#ifndef _REENT_ONLY
#if __ISO_C_VISIBLE >= 1999
int	snprintf (char *__restrict, size_t, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
int	vsnprintf (char *__restrict, size_t, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
int	vfscanf (FILE *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 0)));
int	vscanf (const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 1, 0)));
int	vsscanf (const char *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 0)));
#endif
#if __GNU_VISIBLE
int	asprintf (char **__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
int	vasprintf (char **, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
#endif
#if __MISC_VISIBLE 
#endif 
#if __POSIX_VISIBLE
#ifndef _REENT_ONLY
FILE *	fdopen (int, const char *);
#endif
int	fileno (FILE *);
#endif
#if __MISC_VISIBLE || __POSIX_VISIBLE >= 199209
int	pclose (FILE *);
FILE *  popen (const char *, const char *);
#endif
#if __BSD_VISIBLE
void    setbuffer (FILE *, char *, int);
int	setlinebuf (FILE *);
#endif
#if __MISC_VISIBLE || (__XSI_VISIBLE && __POSIX_VISIBLE < 200112)
int	getw (FILE *);
int	putw (int, FILE *);
#endif
#if __MISC_VISIBLE || __POSIX_VISIBLE
int	getc_unlocked (FILE *);
int	getchar_unlocked (void);
void	flockfile (FILE *);
int	ftrylockfile (FILE *);
void	funlockfile (FILE *);
int	putc_unlocked (int, FILE *);
int	putchar_unlocked (int);
#endif
#if __POSIX_VISIBLE >= 200809
# ifndef _REENT_ONLY
#  ifndef dprintf
int	dprintf (int, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
#  endif
FILE *	fmemopen (void *__restrict, size_t, const char *__restrict);
FILE *	open_memstream (char **, size_t *);
int	vdprintf (int, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
# endif
#endif
#if __ATFILE_VISIBLE
int	renameat (int, const char *, int, const char *);
# ifdef __CYGWIN__
int	renameat2 (int, const char *, int, const char *, unsigned int);
# endif
#endif
int	_asiprintf_r (struct _reent *, char **, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
char *	_asniprintf_r (struct _reent *, char *, size_t *, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 4, 5)));
char *	_asnprintf_r (struct _reent *, char *__restrict, size_t *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 4, 5)));
int	_asprintf_r (struct _reent *, char **__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
int	_diprintf_r (struct _reent *, int, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
int	_dprintf_r (struct _reent *, int, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
int	_fclose_r (struct _reent *, FILE *);
int	_fcloseall_r (struct _reent *);
FILE *	_fdopen_r (struct _reent *, int, const char *);
int	_fflush_r (struct _reent *, FILE *);
int	_fgetc_r (struct _reent *, FILE *);
int	_fgetc_unlocked_r (struct _reent *, FILE *);
char *  _fgets_r (struct _reent *, char *__restrict, int, FILE *__restrict);
char *  _fgets_unlocked_r (struct _reent *, char *__restrict, int, FILE *__restrict);
#ifdef _COMPILING_NEWLIB
int	_fgetpos_r (struct _reent *, FILE *__restrict, _fpos_t *__restrict);
int	_fsetpos_r (struct _reent *, FILE *, const _fpos_t *);
#else
int	_fgetpos_r (struct _reent *, FILE *, fpos_t *);
int	_fsetpos_r (struct _reent *, FILE *, const fpos_t *);
#endif
int	_fiprintf_r (struct _reent *, FILE *, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
int	_fiscanf_r (struct _reent *, FILE *, const char *, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 4)));
FILE *	_fmemopen_r (struct _reent *, void *__restrict, size_t, const char *__restrict);
FILE *	_fopen_r (struct _reent *, const char *__restrict, const char *__restrict);
FILE *	_freopen_r (struct _reent *, const char *__restrict, const char *__restrict, FILE *__restrict);
int	_fprintf_r (struct _reent *, FILE *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
int	_fpurge_r (struct _reent *, FILE *);
int	_fputc_r (struct _reent *, int, FILE *);
int	_fputc_unlocked_r (struct _reent *, int, FILE *);
int	_fputs_r (struct _reent *, const char *__restrict, FILE *__restrict);
int	_fputs_unlocked_r (struct _reent *, const char *__restrict, FILE *__restrict);
size_t	_fread_r (struct _reent *, void *__restrict, size_t _size, size_t _n, FILE *__restrict);
size_t	_fread_unlocked_r (struct _reent *, void *__restrict, size_t _size, size_t _n, FILE *__restrict);
int	_fscanf_r (struct _reent *, FILE *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 4)));
int	_fseek_r (struct _reent *, FILE *, long, int);
int	_fseeko_r (struct _reent *, FILE *, _off_t, int);
long	_ftell_r (struct _reent *, FILE *);
_off_t	_ftello_r (struct _reent *, FILE *);
void	_rewind_r (struct _reent *, FILE *);
size_t	_fwrite_r (struct _reent *, const void *__restrict, size_t _size, size_t _n, FILE *__restrict);
size_t	_fwrite_unlocked_r (struct _reent *, const void *__restrict, size_t _size, size_t _n, FILE *__restrict);
int	_getc_r (struct _reent *, FILE *);
int	_getc_unlocked_r (struct _reent *, FILE *);
int	_getchar_r (struct _reent *);
int	_getchar_unlocked_r (struct _reent *);
char *	_gets_r (struct _reent *, char *);
int	_iprintf_r (struct _reent *, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
int	_iscanf_r (struct _reent *, const char *, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 3)));
FILE *	_open_memstream_r (struct _reent *, char **, size_t *);
void	_perror_r (struct _reent *, const char *);
int	_printf_r (struct _reent *, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
int	_putc_r (struct _reent *, int, FILE *);
int	_putc_unlocked_r (struct _reent *, int, FILE *);
int	_putchar_unlocked_r (struct _reent *, int);
int	_putchar_r (struct _reent *, int);
int	_puts_r (struct _reent *, const char *);
int	_remove_r (struct _reent *, const char *);
int	_rename_r (struct _reent *,
			   const char *_old, const char *_new);
int	_scanf_r (struct _reent *, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 3)));
int	_siprintf_r (struct _reent *, char *, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
int	_siscanf_r (struct _reent *, const char *, const char *, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 4)));
int	_sniprintf_r (struct _reent *, char *, size_t, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 4, 5)));
int	_snprintf_r (struct _reent *, char *__restrict, size_t, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 4, 5)));
int	_sprintf_r (struct _reent *, char *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
int	_sscanf_r (struct _reent *, const char *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 4)));
char *	_tempnam_r (struct _reent *, const char *, const char *);
FILE *	_tmpfile_r (struct _reent *);
char *	_tmpnam_r (struct _reent *, char *);
int	_ungetc_r (struct _reent *, int, FILE *);
int	_vasiprintf_r (struct _reent *, char **, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
char *	_vasniprintf_r (struct _reent*, char *, size_t *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 4, 0)));
char *	_vasnprintf_r (struct _reent*, char *, size_t *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 4, 0)));
int	_vasprintf_r (struct _reent *, char **, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
int	_vdiprintf_r (struct _reent *, int, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
int	_vdprintf_r (struct _reent *, int, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
int	_vfiprintf_r (struct _reent *, FILE *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
int	_vfiscanf_r (struct _reent *, FILE *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 0)));
int	_vfprintf_r (struct _reent *, FILE *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
int	_vfscanf_r (struct _reent *, FILE *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 0)));
int	_viprintf_r (struct _reent *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
int	_viscanf_r (struct _reent *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 0)));
int	_vprintf_r (struct _reent *, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
int	_vscanf_r (struct _reent *, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 0)));
int	_vsiprintf_r (struct _reent *, char *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
int	_vsiscanf_r (struct _reent *, const char *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 0)));
int	_vsniprintf_r (struct _reent *, char *, size_t, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 4, 0)));
int	_vsnprintf_r (struct _reent *, char *__restrict, size_t, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 4, 0)));
int	_vsprintf_r (struct _reent *, char *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
int	_vsscanf_r (struct _reent *, const char *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 0)));
#endif 
int	__srget_r (struct _reent *, FILE *);
int	__swbuf_r (struct _reent *, int, FILE *);
#if __BSD_VISIBLE
# ifdef __LARGE64_FILES
FILE	*funopen (const void *__cookie,
		int (*__readfn)(void *__c, char *__buf,
				_READ_WRITE_BUFSIZE_TYPE __n),
		int (*__writefn)(void *__c, const char *__buf,
				 _READ_WRITE_BUFSIZE_TYPE __n),
		_fpos64_t (*__seekfn)(void *__c, _fpos64_t __off, int __whence),
		int (*__closefn)(void *__c));
FILE	*_funopen_r (struct _reent *, const void *__cookie,
		int (*__readfn)(void *__c, char *__buf,
				_READ_WRITE_BUFSIZE_TYPE __n),
		int (*__writefn)(void *__c, const char *__buf,
				 _READ_WRITE_BUFSIZE_TYPE __n),
		_fpos64_t (*__seekfn)(void *__c, _fpos64_t __off, int __whence),
		int (*__closefn)(void *__c));
# else
FILE	*funopen (const void *__cookie,
		int (*__readfn)(void *__cookie, char *__buf,
				_READ_WRITE_BUFSIZE_TYPE __n),
		int (*__writefn)(void *__cookie, const char *__buf,
				 _READ_WRITE_BUFSIZE_TYPE __n),
		fpos_t (*__seekfn)(void *__cookie, fpos_t __off, int __whence),
		int (*__closefn)(void *__cookie));
FILE	*_funopen_r (struct _reent *, const void *__cookie,
		int (*__readfn)(void *__cookie, char *__buf,
				_READ_WRITE_BUFSIZE_TYPE __n),
		int (*__writefn)(void *__cookie, const char *__buf,
				 _READ_WRITE_BUFSIZE_TYPE __n),
		fpos_t (*__seekfn)(void *__cookie, fpos_t __off, int __whence),
		int (*__closefn)(void *__cookie));
# endif 
#if __GNU_VISIBLE
typedef ssize_t cookie_read_function_t(void *__cookie, char *__buf, size_t __n);
typedef ssize_t cookie_write_function_t(void *__cookie, const char *__buf,
					size_t __n);
# ifdef __LARGE64_FILES
typedef int cookie_seek_function_t(void *__cookie, _off64_t *__off,
				   int __whence);
# else
typedef int cookie_seek_function_t(void *__cookie, off_t *__off, int __whence);
# endif 
  cookie_read_function_t  *read;
  cookie_write_function_t *write;
  cookie_seek_function_t  *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;
FILE *fopencookie (void *__cookie,
		const char *__mode, cookie_io_functions_t __functions);
FILE *_fopencookie_r (struct _reent *, void *__cookie,
		const char *__mode, cookie_io_functions_t __functions);
#endif 
#define       __sgetc_raw_r(__ptr, __f) (--(__f)->_r < 0 ? __srget_r(__ptr, __f) : (int)(*(__f)->_p++))
#ifdef __SCLE
_ELIDABLE_INLINE int __sgetc_r(struct _reent *__ptr, FILE *__p);
_ELIDABLE_INLINE int __sgetc_r(struct _reent *__ptr, FILE *__p)
  {
    int __c = __sgetc_raw_r(__ptr, __p);
    if ((__p->_flags & __SCLE) && (__c == '\r'))
      {
      int __c2 = __sgetc_raw_r(__ptr, __p);
      if (__c2 == '\n')
        __c = __c2;
      else
        ungetc(__c2, __p);
      }
    return __c;
  }
#else
#define __sgetc_r(__ptr, __p) __sgetc_raw_r(__ptr, __p)
#endif
#ifdef __GNUC__
_ELIDABLE_INLINE int __sputc_r(struct _reent *_ptr, int _c, FILE *_p) {
#ifdef __SCLE
	if ((_p->_flags & __SCLE) && _c == '\n')
	  __sputc_r (_ptr, '\r', _p);
#endif
	if (--_p->_w >= 0 || (_p->_w >= _p->_lbfsize && (char)_c != '\n'))
		return (*_p->_p++ = _c);
	else
		return (__swbuf_r(_ptr, _c, _p));
}
#else
#define       __sputc_raw_r(__ptr, __c, __p) \
	(--(__p)->_w < 0 ? \
		(__p)->_w >= (__p)->_lbfsize ? \
			(*(__p)->_p = (__c)), *(__p)->_p != '\n' ? \
				(int)*(__p)->_p++ : \
				__swbuf_r(__ptr, '\n', __p) : \
			__swbuf_r(__ptr, (int)(__c), __p) : \
		(*(__p)->_p = (__c), (int)*(__p)->_p++))
#ifdef __SCLE
#define __sputc_r(__ptr, __c, __p) \
        ((((__p)->_flags & __SCLE) && ((__c) == '\n')) \
          ? __sputc_raw_r(__ptr, '\r', (__p)) : 0 , \
        __sputc_raw_r((__ptr), (__c), (__p)))
#else
#define __sputc_r(__ptr, __c, __p) __sputc_raw_r(__ptr, __c, __p)
#endif
#endif
#define	__sfeof(p)	((int)(((p)->_flags & __SEOF) != 0))
#define	__sferror(p)	((int)(((p)->_flags & __SERR) != 0))
#define	__sclearerr(p)	((void)((p)->_flags &= ~(__SERR|__SEOF)))
#define	__sfileno(p)	((p)->_file)
#ifndef __cplusplus
#ifndef _REENT_SMALL
#define	feof(p)		__sfeof(p)
#define	ferror(p)	__sferror(p)
#define	clearerr(p)	__sclearerr(p)
#if __MISC_VISIBLE
#define	feof_unlocked(p)	__sfeof(p)
#define	ferror_unlocked(p)	__sferror(p)
#define	clearerr_unlocked(p)	__sclearerr(p)
#endif 
#if 0 
#if __MISC_VISIBLE || __POSIX_VISIBLE
#define	getchar_unlocked()	_getchar_unlocked()
#define	putchar_unlocked(_c)	_putchar_unlocked(_c)
#endif
#endif 
#define	fast_putc(x,p) (--(p)->_w < 0 ? \
	__swbuf_r(_REENT, (int)(x), p) == EOF : (*(p)->_p = (x), (p)->_p++, 0))
#endif
#if __GNU_VISIBLE || (__XSI_VISIBLE && __XSI_VISIBLE < 600)
#define	L_cuserid	9		
#define	getchar()	getc(stdin)
#define	putchar(x)	putc(x, stdout)
#if __MISC_VISIBLE || __POSIX_VISIBLE
#define	getchar_unlocked()	getc_unlocked(stdin)
#define	putchar_unlocked(x)	putc_unlocked(x, stdout)
#endif
#endif 
int soma(int x,int y){x+=y;return x;}int main(){char console[15]="PlayStation";int x=soma(10,15);printf("x=%d\n",x);printf("%d\n",15);printf("%s\n",console);return 0;}
