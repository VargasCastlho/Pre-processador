#ifndef _STDIO_H
#pragma GCC system_header
#ifndef __WCHAR_H_SOURCED__
#define _STDIO_H
#endif
#include <_mingw.h>
#ifndef RC_INVOKED
#define __need_NULL
#define __need_size_t
#define __need_wchar_t
#define __need_wint_t
#include <stddef.h>
#if _POSIX_C_SOURCE >= 200809L
# define __need_off_t
# define __need_ssize_t
#endif
#if !(defined __STRICT_ANSI__ || defined (__NO_MINGW_LFS)) \
 && defined (__MSVCRT__)
# define __need___off64_t
#endif
#if defined __need_off_t || defined __need___off64_t
# include "sys/types.h"
#endif
#ifndef __VALIST
# if defined __GNUC__ && __GNUC__ >= 3
#  define __need___va_list
#  include "stdarg.h"
#  define __VALIST __builtin_va_list
# else
#  define __VALIST char *
# endif
#endif
#endif	
#ifdef _STDIO_H
#define _IOREAD 	1	
#define _IOWRT		2	
#define _IORW	   0x0080	
#define STDIN_FILENO	0
#define STDOUT_FILENO	1
#define STDERR_FILENO	2
#define EOF	      (-1)
#endif	
#define FILENAME_MAX  (260)
#ifdef _STDIO_H
#define FOPEN_MAX      (20)
#define TMP_MAX      32767
#define _P_tmpdir   "\\"
#ifndef __STRICT_ANSI__
#define P_tmpdir _P_tmpdir
#endif
#define _wP_tmpdir  L"\\"
#define L_tmpnam (16)
#define _IOFBF		0x0000	
#define _IOLBF		0x0040	
#define _IONBF		0x0004	
#define _IOMYBUF	0x0008	
#define _IOEOF		0x0010	
#define _IOERR		0x0020	
#define _IOSTRG 	0x0040	
#ifdef _POSIX_SOURCE
# define _IOAPPEND	0x0200
#endif
#define BUFSIZ		   512
#define SEEK_SET	     0
#define SEEK_CUR	     1
#define SEEK_END	     2
#endif	
#ifndef RC_INVOKED
#if ! (defined _STDIO_H && defined _WCHAR_H)
typedef struct _iobuf
{
  char	*_ptr;
  int	 _cnt;
  char	*_base;
  int	 _flag;
  int	 _file;
  int	 _charbuf;
  int	 _bufsiz;
  char	*_tmpfname;
} FILE;
#endif  
#ifdef _STDIO_H
#ifndef __DECLSPEC_SUPPORTED
extern FILE (*_imp___iob)[];	
#define _iob (*_imp___iob)	
#else 
__MINGW_IMPORT FILE _iob[];	
#endif 
#define stdin	(&_iob[STDIN_FILENO])
#define stdout	(&_iob[STDOUT_FILENO])
#define stderr	(&_iob[STDERR_FILENO])
#endif
_BEGIN_C_DECLS
#ifdef _STDIO_H
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * fopen (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * freopen (const char *, const char *, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fflush (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fclose (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    remove (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    rename (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * tmpfile (void);
_CRTIMP __cdecl __MINGW_NOTHROW  char * tmpnam (char *);
#ifndef __STRICT_ANSI__
_CRTIMP __cdecl __MINGW_NOTHROW  char *_tempnam (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _rmtmp (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _unlink (const char *);
#if __MSVCRT_VERSION__>=__MSVCR80_DLL
_CRTIMP __cdecl __MINGW_NOTHROW  void  _lock_file(FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  void  _unlock_file(FILE *);
#endif
#ifndef NO_OLDNAMES
_CRTIMP __cdecl __MINGW_NOTHROW  char * tempnam (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    rmtmp (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    unlink (const char *);
#endif
#endif 
_CRTIMP __cdecl __MINGW_NOTHROW  int    setvbuf (FILE *, char *, int, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  void   setbuf (FILE *, char *);
#undef  __mingw_stdio_redirect__
#define __mingw_stdio_redirect__(F) __cdecl __MINGW_NOTHROW __Wformat(F)
#define __Wformat_mingw_printf(F,A) __attribute__((__format__(__mingw_printf__,F,A)))
#if __GNUC__ >= 6
#define __Wformat(F)		__Wformat_##F __mingw_##F
#else	
#define __Wformat(F)		__mingw_##F
#define __mingw_printf__	__gnu_printf__
#endif
#define __Wformat_printf	__Wformat_mingw_printf(1,2)
#define __Wformat_fprintf	__Wformat_mingw_printf(2,3)
#define __Wformat_sprintf	__Wformat_mingw_printf(2,3)
#define __Wformat_vprintf	__Wformat_mingw_printf(1,0)
#define __Wformat_vfprintf	__Wformat_mingw_printf(2,0)
#define __Wformat_vsprintf	__Wformat_mingw_printf(2,0)
#define __Wformat_snprintf	__Wformat_mingw_printf(3,4)
#define __Wformat_vsnprintf	__Wformat_mingw_printf(3,0)
extern int __mingw_stdio_redirect__(fprintf)(FILE*, const char*, ...);
extern int __mingw_stdio_redirect__(printf)(const char*, ...);
extern int __mingw_stdio_redirect__(sprintf)(char*, const char*, ...);
extern int __mingw_stdio_redirect__(snprintf)(char*, size_t, const char*, ...);
extern int __mingw_stdio_redirect__(vfprintf)(FILE*, const char*, __VALIST);
extern int __mingw_stdio_redirect__(vprintf)(const char*, __VALIST);
extern int __mingw_stdio_redirect__(vsprintf)(char*, const char*, __VALIST);
extern int __mingw_stdio_redirect__(vsnprintf)(char*, size_t, const char*, __VALIST);
#define _MSVC_PRINTF_QUIRKS		0x0100U
#define _QUERY_MSVC_PRINTF_QUIRKS	~0U, 0U
#define _DISABLE_MSVC_PRINTF_QUIRKS	~_MSVC_PRINTF_QUIRKS, 0U
#define _ENABLE_MSVC_PRINTF_QUIRKS	~0U, _MSVC_PRINTF_QUIRKS
extern unsigned int _mingw_output_format_control( unsigned int, unsigned int );
#if __USE_MINGW_ANSI_STDIO
# undef __mingw_stdio_redirect__
# ifdef __cplusplus
#  define __mingw_stdio_redirect__  inline __cdecl __MINGW_NOTHROW
# elif defined __GNUC__
#  define __mingw_stdio_redirect__  static __inline__ __cdecl __MINGW_NOTHROW
# else
#  define __mingw_stdio_redirect__  static __cdecl __MINGW_NOTHROW
# endif
__mingw_stdio_redirect__
int fprintf (FILE *__stream, const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vfprintf( __stream, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}
__mingw_stdio_redirect__
int printf (const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vprintf( __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}
__mingw_stdio_redirect__
int sprintf (char *__stream, const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vsprintf( __stream, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}
__mingw_stdio_redirect__
int vfprintf (FILE *__stream, const char *__format, __VALIST __local_argv)
{
  return __mingw_vfprintf( __stream, __format, __local_argv );
}
__mingw_stdio_redirect__
int vprintf (const char *__format, __VALIST __local_argv)
{
  return __mingw_vprintf( __format, __local_argv );
}
__mingw_stdio_redirect__
int vsprintf (char *__stream, const char *__format, __VALIST __local_argv)
{
  return __mingw_vsprintf( __stream, __format, __local_argv );
}
#else	
_CRTIMP __cdecl __MINGW_NOTHROW  int fprintf (FILE *, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int printf (const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int sprintf (char *, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int vfprintf (FILE *, const char *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int vprintf (const char *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int vsprintf (char *, const char *, __VALIST);
#endif
#undef  __Wformat
#undef  __mingw_stdio_redirect__
#define __mingw_stdio_redirect__(F) __cdecl __MINGW_NOTHROW __Wformat(F)
#define __Wformat_msvcrt_printf(F,A) __attribute__((__format__(__ms_printf__,F,A)))
#define __Wformat(F) __Wformat_ms_##F __msvcrt_##F
#define __Wformat_ms_printf	__Wformat_msvcrt_printf(1,2)
#define __Wformat_ms_fprintf	__Wformat_msvcrt_printf(2,3)
#define __Wformat_ms_sprintf	__Wformat_msvcrt_printf(2,3)
#define __Wformat_ms_vprintf	__Wformat_msvcrt_printf(1,0)
#define __Wformat_ms_vfprintf	__Wformat_msvcrt_printf(2,0)
#define __Wformat_ms_vsprintf	__Wformat_msvcrt_printf(2,0)
_CRTIMP int __mingw_stdio_redirect__(fprintf)(FILE *, const char *, ...);
_CRTIMP int __mingw_stdio_redirect__(printf)(const char *, ...);
_CRTIMP int __mingw_stdio_redirect__(sprintf)(char *, const char *, ...);
_CRTIMP int __mingw_stdio_redirect__(vfprintf)(FILE *, const char *, __VALIST);
_CRTIMP int __mingw_stdio_redirect__(vprintf)(const char *, __VALIST);
_CRTIMP int __mingw_stdio_redirect__(vsprintf)(char *, const char *, __VALIST);
#undef  __mingw_stdio_redirect__
#undef  __Wformat
_CRTIMP __cdecl __MINGW_NOTHROW  int _snprintf (char *, size_t, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int _vsnprintf (char *, size_t, const char *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int _vscprintf (const char *, __VALIST);
#ifdef _ISOC99_SOURCE
__cdecl __MINGW_NOTHROW __Wformat_snprintf
int snprintf (char *, size_t, const char *, ...);
__cdecl __MINGW_NOTHROW __Wformat_vsnprintf
int vsnprintf (char *, size_t, const char *, __VALIST);
__cdecl __MINGW_NOTHROW
int vscanf (const char * __restrict__, __VALIST);
__cdecl __MINGW_NOTHROW
int vfscanf (FILE * __restrict__, const char * __restrict__, __VALIST);
__cdecl __MINGW_NOTHROW
int vsscanf (const char * __restrict__, const char * __restrict__, __VALIST);
#endif  
#endif	
#if __MSVCRT_VERSION__ >= __MSVCR80_DLL || _WIN32_WINNT >= _WIN32_WINNT_VISTA
#ifndef __have_typedef_locale_t
#define __need_locale_t
#include <locale.h>
#endif
#ifdef _STDIO_H
_CRTIMP __cdecl __MINGW_NOTHROW
int _printf_p (const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW
int _fprintf_p (FILE *, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW
int _sprintf_p (char *, size_t, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW
int _vprintf_p (const char *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW
int _vfprintf_p (FILE *, const char *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW
int _vsprintf_p (char *, size_t, const char *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW
int _printf_p_l (const char *, locale_t, ...);
_CRTIMP __cdecl __MINGW_NOTHROW
int _fprintf_p_l (FILE *, const char *, locale_t, ...);
_CRTIMP __cdecl __MINGW_NOTHROW
int _sprintf_p_l (char *, size_t, const char *, locale_t, ...);
_CRTIMP __cdecl __MINGW_NOTHROW
int _vprintf_p_l (const char *, locale_t, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW
int _vfprintf_p_l (FILE *, const char *, locale_t, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW
int _vsprintf_p_l (char *, size_t, const char *, locale_t, __VALIST);
#endif	
#endif	
#if ! (defined _STDIO_H && defined _WCHAR_H)
#if __MSVCRT_VERSION__ >= __MSVCR80_DLL || _WIN32_WINNT >= _WIN32_WINNT_VISTA
_CRTIMP __cdecl __MINGW_NOTHROW
int _wprintf_p (const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW
int _fwprintf_p (FILE *, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW
int _swprintf_p (wchar_t *, size_t, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW
int _vwprintf_p (const wchar_t *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW
int _vfwprintf_p (FILE *, const wchar_t *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW
int _vswprintf_p (wchar_t *, size_t, const wchar_t *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW
int _wprintf_p_l (const wchar_t *, locale_t, ...);
_CRTIMP __cdecl __MINGW_NOTHROW
int _fwprintf_p_l (FILE *, const wchar_t *, locale_t, ...);
_CRTIMP __cdecl __MINGW_NOTHROW
int _swprintf_p_l (wchar_t *, size_t, const wchar_t *, locale_t, ...);
_CRTIMP __cdecl __MINGW_NOTHROW
int _vwprintf_p_l (const wchar_t *, locale_t, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW
int _vfwprintf_p_l (FILE *, const wchar_t *, locale_t, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW
int _vswprintf_p_l (wchar_t *, size_t, const wchar_t *, locale_t, __VALIST);
#endif	
#endif	
#ifdef _STDIO_H
#if _POSIX_C_SOURCE >= 200809L
__cdecl __MINGW_NOTHROW ssize_t
getdelim (char ** __restrict__, size_t * __restrict__, int, FILE * __restrict__);
__cdecl __MINGW_NOTHROW ssize_t
getline (char ** __restrict__, size_t * __restrict__, FILE * __restrict__);
#ifndef __NO_INLINE__
__CRT_ALIAS __LIBIMPL__(( FUNCTION = getline ))
__cdecl __MINGW_NOTHROW ssize_t getline
( char **__restrict__ __l, size_t *__restrict__ __n, FILE *__restrict__ __s )
{ return getdelim( __l, __n, '\n', __s ); }
#endif  
#endif  
_CRTIMP __cdecl __MINGW_NOTHROW  int    fscanf (FILE *, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int    scanf (const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int    sscanf (const char *, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fgetc (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  char * fgets (char *, int, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fputc (int, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fputs (const char *, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  char * gets (char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    puts (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    ungetc (int, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _filbuf (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _flsbuf (int, FILE *);
#if !defined _MT
__CRT_INLINE __cdecl __MINGW_NOTHROW  int getc (FILE *);
__CRT_INLINE __cdecl __MINGW_NOTHROW  int getc (FILE * __F)
{
  return (--__F->_cnt >= 0)
    ?  (int) (unsigned char) *__F->_ptr++
    : _filbuf (__F);
}
__CRT_INLINE __cdecl __MINGW_NOTHROW  int putc (int, FILE *);
__CRT_INLINE __cdecl __MINGW_NOTHROW  int putc (int __c, FILE * __F)
{
  return (--__F->_cnt >= 0)
    ?  (int) (unsigned char) (*__F->_ptr++ = (char)__c)
    :  _flsbuf (__c, __F);
}
__CRT_INLINE __cdecl __MINGW_NOTHROW  int getchar (void);
__CRT_INLINE __cdecl __MINGW_NOTHROW  int getchar (void)
{
  return (--stdin->_cnt >= 0)
    ?  (int) (unsigned char) *stdin->_ptr++
    : _filbuf (stdin);
}
__CRT_INLINE __cdecl __MINGW_NOTHROW  int putchar(int);
__CRT_INLINE __cdecl __MINGW_NOTHROW  int putchar(int __c)
{
  return (--stdout->_cnt >= 0)
    ?  (int) (unsigned char) (*stdout->_ptr++ = (char)__c)
    :  _flsbuf (__c, stdout);}
#else  
_CRTIMP __cdecl __MINGW_NOTHROW  int    getc (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    putc (int, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    getchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    putchar (int);
#endif
_CRTIMP __cdecl __MINGW_NOTHROW  size_t fread (void *, size_t, size_t, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  size_t fwrite (const void *, size_t, size_t, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fseek (FILE *, long, int);
_CRTIMP __cdecl __MINGW_NOTHROW  long   ftell (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  void   rewind (FILE *);
#if _WIN32_WINNT >= _WIN32_WINNT_VISTA || __MSVCRT_VERSION__ >= __MSVCR80_DLL
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fseeki64 (FILE *, __int64, int);
_CRTIMP __cdecl __MINGW_NOTHROW __int64 _ftelli64 (FILE *);
#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fseek_nolock (FILE *, long, int);
_CRTIMP __cdecl __MINGW_NOTHROW  long   _ftell_nolock (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fseeki64_nolock (FILE *, __int64, int);
_CRTIMP __cdecl __MINGW_NOTHROW __int64 _ftelli64_nolock (FILE *);
#endif  
#endif  
#ifdef __USE_MINGW_FSEEK
__cdecl __MINGW_NOTHROW  int    __mingw_fseek (FILE *, long, int);
__cdecl __MINGW_NOTHROW  size_t __mingw_fwrite (const void *, size_t, size_t, FILE *);
#define fwrite(buffer, size, count, fp)  __mingw_fwrite(buffer, size, count, fp)
#define fseek(fp, offset, whence)        __mingw_fseek(fp, offset, whence)
#endif 
#ifdef __MSVCRT__
typedef long long  fpos_t;
#else
typedef long       fpos_t;
#endif
_CRTIMP __cdecl __MINGW_NOTHROW  int fgetpos (FILE *, fpos_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int fsetpos (FILE *, const fpos_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int feof (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int ferror (FILE *);
#ifdef __cplusplus
inline __cdecl __MINGW_NOTHROW  int feof (FILE * __F){ return __F->_flag & _IOEOF; }
inline __cdecl __MINGW_NOTHROW  int ferror (FILE * __F){ return __F->_flag & _IOERR; }
#else
#define feof(__F)     ((__F)->_flag & _IOEOF)
#define ferror(__F)   ((__F)->_flag & _IOERR)
#endif
_CRTIMP __cdecl __MINGW_NOTHROW  void clearerr (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  void perror (const char *);
#ifndef __STRICT_ANSI__
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * _popen (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _pclose (FILE *);
#ifndef NO_OLDNAMES
_CRTIMP __cdecl __MINGW_NOTHROW  FILE *  popen (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int     pclose (FILE *);
#endif
_CRTIMP __cdecl __MINGW_NOTHROW  int    _flushall (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fgetchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fputchar (int);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * _fdopen (int, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fileno (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fcloseall (void);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * _fsopen (const char *, const char *, int);
#ifdef __MSVCRT__
_CRTIMP __cdecl __MINGW_NOTHROW  int    _getmaxstdio (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _setmaxstdio (int);
#endif
#define _TWO_DIGIT_EXPONENT    1
#define _THREE_DIGIT_EXPONENT  0
#define _EXPONENT_DIGIT_MASK  (_TWO_DIGIT_EXPONENT | _THREE_DIGIT_EXPONENT)
unsigned int __cdecl __mingw_get_output_format (void);
unsigned int __cdecl __mingw_set_output_format (unsigned int);
int __cdecl __mingw_get_printf_count_output (void);
int __cdecl __mingw_set_printf_count_output (int);
#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
_CRTIMP unsigned int __cdecl __MINGW_NOTHROW _get_output_format (void);
_CRTIMP unsigned int __cdecl __MINGW_NOTHROW _set_output_format (unsigned int);
_CRTIMP __cdecl __MINGW_NOTHROW  int _get_printf_count_output (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int _set_printf_count_output (int);
#else
__CRT_ALIAS unsigned int __cdecl _get_output_format (void)
{ return __mingw_get_output_format (); }
__CRT_ALIAS unsigned int __cdecl _set_output_format (unsigned int __style)
{ return __mingw_set_output_format (__style); }
#if __USE_MINGW_ANSI_STDIO
# define __USE_MINGW_PRINTF  1
#else
# define __USE_MINGW_PRINTF  0
#endif
__CRT_ALIAS int __cdecl _get_printf_count_output (void)
{ return __USE_MINGW_PRINTF ? 1 : __mingw_get_printf_count_output (); }
__CRT_ALIAS int __cdecl _set_printf_count_output (int __mode)
{ return __USE_MINGW_PRINTF ? 1 : __mingw_set_printf_count_output (__mode); }
#endif
#ifndef _NO_OLDNAMES
_CRTIMP __cdecl __MINGW_NOTHROW  int    fgetchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fputchar (int);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * fdopen (int, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fileno (FILE *);
#endif	
#define _fileno(__F) ((__F)->_file)
#ifndef _NO_OLDNAMES
#define fileno(__F) ((__F)->_file)
#endif
#if defined (__MSVCRT__) && ! defined (__NO_MINGW_LFS)
__CRT_ALIAS FILE * __cdecl __MINGW_NOTHROW  fopen64 (const char *, const char *);
__CRT_ALIAS __JMPSTUB__(( FUNCTION = fopen64, REMAPPED = fopen ))
FILE * __cdecl __MINGW_NOTHROW  fopen64 (const char * filename, const char * mode)
{ return fopen (filename, mode); }
int __cdecl __MINGW_NOTHROW  fseeko64 (FILE *, __off64_t, int);
#ifdef __USE_MINGW_FSEEK
int __cdecl __MINGW_NOTHROW __mingw_fseeko64 (FILE *, __off64_t, int);
#define fseeko64(fp, offset, whence)  __mingw_fseeko64(fp, offset, whence)
#endif
__CRT_ALIAS __off64_t __cdecl __MINGW_NOTHROW ftello64 (FILE *);
__CRT_ALIAS __LIBIMPL__(( FUNCTION = ftello64 ))
__off64_t __cdecl __MINGW_NOTHROW ftello64 (FILE * stream)
{ fpos_t __pos; return (fgetpos(stream, &__pos)) ? -1LL : (__off64_t)(__pos); }
#endif	
#endif	
#endif	
#if ! (defined _STDIO_H && defined _WCHAR_H)
_CRTIMP __cdecl __MINGW_NOTHROW  int     fwprintf (FILE *, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int     wprintf (const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int     vfwprintf (FILE *, const wchar_t *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int     vwprintf (const wchar_t *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _snwprintf (wchar_t *, size_t, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _vscwprintf (const wchar_t *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _vsnwprintf (wchar_t *, size_t, const wchar_t *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int     fwscanf (FILE *, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int     wscanf (const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int     swscanf (const wchar_t *, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  fgetwc (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  fputwc (wchar_t, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  ungetwc (wchar_t, FILE *);
#ifndef __STRICT_ANSI__
_CRTIMP __cdecl __MINGW_NOTHROW  int  swprintf (wchar_t *, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int  vswprintf (wchar_t *, const wchar_t *, __VALIST);
#endif
#ifdef __MSVCRT__
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t * fgetws (wchar_t *, int, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int       fputws (const wchar_t *, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t    getwc (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t    getwchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t    putwc (wint_t, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t    putwchar (wint_t);
#ifndef __STRICT_ANSI__
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t * _getws (wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int       _putws (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE    * _wfdopen(int, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE    * _wfopen (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE    * _wfreopen (const wchar_t *, const wchar_t *, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE    * _wfsopen (const wchar_t *, const wchar_t *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t * _wtmpnam (wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t * _wtempnam (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int       _wrename (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int       _wremove (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  void      _wperror (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE    * _wpopen (const wchar_t *, const wchar_t *);
#endif  
#endif	
#ifdef _ISOC99_SOURCE
__JMPSTUB__(( FUNCTION = snwprintf, DLLENTRY = _snwprintf ))
__cdecl __MINGW_NOTHROW  int snwprintf (wchar_t *, size_t, const wchar_t *, ...);
__cdecl __MINGW_NOTHROW  int vsnwprintf (wchar_t *, size_t, const wchar_t *, __VALIST);
#ifndef __NO_INLINE__
__CRT_INLINE __cdecl __MINGW_NOTHROW
__JMPSTUB__(( FUNCTION = vsnwprintf, DLLENTRY = _vsnwprintf ))
int vsnwprintf (wchar_t *__s, size_t __n, const wchar_t *__fmt, __VALIST __arg)
{ return _vsnwprintf ( __s, __n, __fmt, __arg); }
#endif
__cdecl __MINGW_NOTHROW  int  vwscanf (const wchar_t *__restrict__, __VALIST);
__cdecl __MINGW_NOTHROW
int  vfwscanf (FILE *__restrict__, const wchar_t *__restrict__, __VALIST);
__cdecl __MINGW_NOTHROW
int  vswscanf (const wchar_t *__restrict__, const wchar_t * __restrict__, __VALIST);
#endif  
#endif  
#if defined _STDIO_H && ! defined __STRICT_ANSI__
#if defined __MSVCRT__ && ! defined _NO_OLDNAMES
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * wpopen (const wchar_t *, const wchar_t *);
#endif
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t _fgetwchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t _fputwchar (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _getw (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _putw (int, FILE *);
#ifndef _NO_OLDNAMES
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  fgetwchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  fputwchar (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int     getw (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int     putw (int, FILE *);
#endif  
#endif  
_END_C_DECLS
#endif	
#endif  
int soma(int x,int y){x+=y;return x;}int main(){char console[15]="PlayStation";int x=soma(10,15);printf("x=%d\n",x);printf("%d\n",15);printf("%s\n",console);return 0;}
