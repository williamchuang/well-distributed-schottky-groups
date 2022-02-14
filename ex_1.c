# 3 "example1.c"
#define PY_SSIZE_T_CLEAN 
#include "Python.h"
#ifndef Py_PYTHON_H
    #error Python headers needed to compile C extensions, please install development version of Python.
#elif PY_VERSION_HEX < 0x02060000 || (0x03000000 <= PY_VERSION_HEX && PY_VERSION_HEX < 0x03030000)
    #error Cython requires Python 2.6+ or Python 3.3+.
#else
#define CYTHON_ABI "0_29_21"
#define CYTHON_HEX_VERSION 0x001D15F0
#define CYTHON_FUTURE_DIVISION 0
#include <stddef.h>
#ifndef offsetof
  #define offsetof(type, member) ( (size_t) & ((type*)0) -> member )
#endif
#if !defined(WIN32) && !defined(MS_WINDOWS)
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
  #ifndef __fastcall
    #define __fastcall
  #endif
#endif
#ifndef DL_IMPORT
  #define DL_IMPORT(t) t
#endif
#ifndef DL_EXPORT
  #define DL_EXPORT(t) t
#endif
#define __PYX_COMMA ,
#ifndef HAVE_LONG_LONG
  #if PY_VERSION_HEX >= 0x02070000
    #define HAVE_LONG_LONG
  #endif
#endif
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#ifndef Py_HUGE_VAL
  #define Py_HUGE_VAL HUGE_VAL
#endif
#ifdef PYPY_VERSION
  #define CYTHON_COMPILING_IN_PYPY 1
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #if PY_VERSION_HEX < 0x03050000
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #undef CYTHON_AVOID_BORROWED_REFS
  #define CYTHON_AVOID_BORROWED_REFS 1
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#elif defined(PYSTON_VERSION)
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 1
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #undef CYTHON_USE_ASYNC_SLOTS
  #define CYTHON_USE_ASYNC_SLOTS 0
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#else
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 1
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYTYPE_LOOKUP
    #define CYTHON_USE_PYTYPE_LOOKUP 0
  #elif !defined(CYTHON_USE_PYTYPE_LOOKUP)
    #define CYTHON_USE_PYTYPE_LOOKUP 1
  #endif
  #if PY_MAJOR_VERSION < 3
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYLONG_INTERNALS
    #define CYTHON_USE_PYLONG_INTERNALS 0
  #elif !defined(CYTHON_USE_PYLONG_INTERNALS)
    #define CYTHON_USE_PYLONG_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_PYLIST_INTERNALS
    #define CYTHON_USE_PYLIST_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #if PY_VERSION_HEX < 0x030300F0
    #undef CYTHON_USE_UNICODE_WRITER
    #define CYTHON_USE_UNICODE_WRITER 0
  #elif !defined(CYTHON_USE_UNICODE_WRITER)
    #define CYTHON_USE_UNICODE_WRITER 1
  #endif
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #ifndef CYTHON_FAST_THREAD_STATE
    #define CYTHON_FAST_THREAD_STATE 1
  #endif
  #ifndef CYTHON_FAST_PYCALL
    #define CYTHON_FAST_PYCALL 1
  #endif
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT (PY_VERSION_HEX >= 0x03050000)
  #endif
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE (PY_VERSION_HEX >= 0x030400a1)
  #endif
  #ifndef CYTHON_USE_DICT_VERSIONS
    #define CYTHON_USE_DICT_VERSIONS (PY_VERSION_HEX >= 0x030600B1)
  #endif
  #ifndef CYTHON_USE_EXC_INFO_STACK
    #define CYTHON_USE_EXC_INFO_STACK (PY_VERSION_HEX >= 0x030700A3)
  #endif
#endif
#if !defined(CYTHON_FAST_PYCCALL)
#define CYTHON_FAST_PYCCALL (CYTHON_FAST_PYCALL && PY_VERSION_HEX >= 0x030600B1)
#endif
#if CYTHON_USE_PYLONG_INTERNALS
  #include "longintrepr.h"
  #undef SHIFT
  #undef BASE
  #undef MASK
  #ifdef SIZEOF_VOID_P
    enum { __pyx_check_sizeof_voidp = 1 / (int)(SIZEOF_VOID_P == sizeof(void*)) };
  #endif
#endif
#ifndef __has_attribute
  #define __has_attribute(x) 0
#endif
#ifndef __has_cpp_attribute
  #define __has_cpp_attribute(x) 0
#endif
#ifndef CYTHON_RESTRICT
  #if defined(__GNUC__)
    #define CYTHON_RESTRICT __restrict__
  #elif defined(_MSC_VER) && _MSC_VER >= 1400
    #define CYTHON_RESTRICT __restrict
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_RESTRICT restrict
  #else
    #define CYTHON_RESTRICT
  #endif
#endif
#ifndef CYTHON_UNUSED
# if defined(__GNUC__)
# if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#define CYTHON_UNUSED __attribute__ ((__unused__))
# else
#define CYTHON_UNUSED 
# endif
# elif defined(__ICC) || (defined(__INTEL_COMPILER) && !defined(_MSC_VER))
#define CYTHON_UNUSED __attribute__ ((__unused__))
# else
#define CYTHON_UNUSED 
# endif
#endif
#ifndef CYTHON_MAYBE_UNUSED_VAR
# if defined(__cplusplus)
     template<class T> void CYTHON_MAYBE_UNUSED_VAR( const T& ) { }
# else
#define CYTHON_MAYBE_UNUSED_VAR(x) (void)(x)
# endif
#endif
#ifndef CYTHON_NCP_UNUSED
# if CYTHON_COMPILING_IN_CPYTHON
#define CYTHON_NCP_UNUSED 
# else
#define CYTHON_NCP_UNUSED CYTHON_UNUSED
# endif
#endif
#define __Pyx_void_to_None(void_result) ((void)(void_result), Py_INCREF(Py_None), Py_None)
#ifdef _MSC_VER
    #ifndef _MSC_STDINT_H_
        #if _MSC_VER < 1300
           typedef unsigned char uint8_t;
           typedef unsigned int uint32_t;
        #else
           typedef unsigned __int8 uint8_t;
           typedef unsigned __int32 uint32_t;
        #endif
    #endif
#else
   #include <stdint.h>
#endif
#ifndef CYTHON_FALLTHROUGH
  #if defined(__cplusplus) && __cplusplus >= 201103L
    #if __has_cpp_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH [[fallthrough]]
    #elif __has_cpp_attribute(clang::fallthrough)
      #define CYTHON_FALLTHROUGH [[clang::fallthrough]]
    #elif __has_cpp_attribute(gnu::fallthrough)
      #define CYTHON_FALLTHROUGH [[gnu::fallthrough]]
    #endif
  #endif
  #ifndef CYTHON_FALLTHROUGH
    #if __has_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH __attribute__((fallthrough))
    #else
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
  #if defined(__clang__ ) && defined(__apple_build_version__)
    #if __apple_build_version__ < 7000000
      #undef CYTHON_FALLTHROUGH
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
#endif

#ifndef CYTHON_INLINE
  #if defined(__clang__)
    #define CYTHON_INLINE __inline__ __attribute__ ((__unused__))
  #elif defined(__GNUC__)
    #define CYTHON_INLINE __inline__
  #elif defined(_MSC_VER)
    #define CYTHON_INLINE __inline
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_INLINE inline
  #else
    #define CYTHON_INLINE
  #endif
#endif

#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX < 0x02070600 && !defined(Py_OptimizeFlag)
  #define Py_OptimizeFlag 0
#endif
#define __PYX_BUILD_PY_SSIZE_T "n"
#define CYTHON_FORMAT_SSIZE_T "z"
#if PY_MAJOR_VERSION < 3
  #define __Pyx_BUILTIN_MODULE_NAME "__builtin__"
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a+k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
  #define __Pyx_DefaultClassType PyClass_Type
#else
  #define __Pyx_BUILTIN_MODULE_NAME "builtins"
#if PY_VERSION_HEX >= 0x030800A4 && PY_VERSION_HEX < 0x030800B2
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, 0, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#else
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#endif
  #define __Pyx_DefaultClassType PyType_Type
#endif
#ifndef Py_TPFLAGS_CHECKTYPES
  #define Py_TPFLAGS_CHECKTYPES 0
#endif
#ifndef Py_TPFLAGS_HAVE_INDEX
  #define Py_TPFLAGS_HAVE_INDEX 0
#endif
#ifndef Py_TPFLAGS_HAVE_NEWBUFFER
  #define Py_TPFLAGS_HAVE_NEWBUFFER 0
#endif
#ifndef Py_TPFLAGS_HAVE_FINALIZE
  #define Py_TPFLAGS_HAVE_FINALIZE 0
#endif
#ifndef METH_STACKLESS
  #define METH_STACKLESS 0
#endif
#if PY_VERSION_HEX <= 0x030700A3 || !defined(METH_FASTCALL)
  #ifndef METH_FASTCALL
     #define METH_FASTCALL 0x80
  #endif
  typedef PyObject *(*__Pyx_PyCFunctionFast) (PyObject *self, PyObject *const *args, Py_ssize_t nargs);
  typedef PyObject *(*__Pyx_PyCFunctionFastWithKeywords) (PyObject *self, PyObject *const *args,
                                                          Py_ssize_t nargs, PyObject *kwnames);
#else
  #define __Pyx_PyCFunctionFast _PyCFunctionFast
  #define __Pyx_PyCFunctionFastWithKeywords _PyCFunctionFastWithKeywords
#endif
#if CYTHON_FAST_PYCCALL
#define __Pyx_PyFastCFunction_Check(func) \
    ((PyCFunction_Check(func) && (METH_FASTCALL == (PyCFunction_GET_FLAGS(func) & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)))))
#else
#define __Pyx_PyFastCFunction_Check(func) 0
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Malloc)
  #define PyObject_Malloc(s) PyMem_Malloc(s)
  #define PyObject_Free(p) PyMem_Free(p)
  #define PyObject_Realloc(p) PyMem_Realloc(p)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX < 0x030400A1
  #define PyMem_RawMalloc(n) PyMem_Malloc(n)
  #define PyMem_RawRealloc(p, n) PyMem_Realloc(p, n)
  #define PyMem_RawFree(p) PyMem_Free(p)
#endif
#if CYTHON_COMPILING_IN_PYSTON
  #define __Pyx_PyCode_HasFreeVars(co) PyCode_HasFreeVars(co)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno) PyFrame_SetLineNumber(frame, lineno)
#else
  #define __Pyx_PyCode_HasFreeVars(co) (PyCode_GetNumFree(co) > 0)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno) (frame)->f_lineno = (lineno)
#endif
#if !CYTHON_FAST_THREAD_STATE || PY_VERSION_HEX < 0x02070000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#elif PY_VERSION_HEX >= 0x03060000
  #define __Pyx_PyThreadState_Current _PyThreadState_UncheckedGet()
#elif PY_VERSION_HEX >= 0x03000000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#else
  #define __Pyx_PyThreadState_Current _PyThreadState_Current
#endif
#if PY_VERSION_HEX < 0x030700A2 && !defined(PyThread_tss_create) && !defined(Py_tss_NEEDS_INIT)
#include "pythread.h"
#define Py_tss_NEEDS_INIT 0
typedef int Py_tss_t;
static CYTHON_INLINE int PyThread_tss_create(Py_tss_t *key) {
  *key = PyThread_create_key();
  return 0;
}
static CYTHON_INLINE Py_tss_t * PyThread_tss_alloc(void) {
  Py_tss_t *key = (Py_tss_t *)PyObject_Malloc(sizeof(Py_tss_t));
  *key = Py_tss_NEEDS_INIT;
  return key;
}
static CYTHON_INLINE void PyThread_tss_free(Py_tss_t *key) {
  PyObject_Free(key);
}
static CYTHON_INLINE int PyThread_tss_is_created(Py_tss_t *key) {
  return *key != Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE void PyThread_tss_delete(Py_tss_t *key) {
  PyThread_delete_key(*key);
  *key = Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE int PyThread_tss_set(Py_tss_t *key, void *value) {
  return PyThread_set_key_value(*key, value);
}
static CYTHON_INLINE void * PyThread_tss_get(Py_tss_t *key) {
  return PyThread_get_key_value(*key);
}
#endif
#if CYTHON_COMPILING_IN_CPYTHON || defined(_PyDict_NewPresized)
#define __Pyx_PyDict_NewPresized(n) ((n <= 8) ? PyDict_New() : _PyDict_NewPresized(n))
#else
#define __Pyx_PyDict_NewPresized(n) PyDict_New()
#endif
#if PY_MAJOR_VERSION >= 3 || CYTHON_FUTURE_DIVISION
  #define __Pyx_PyNumber_Divide(x,y) PyNumber_TrueDivide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y) PyNumber_InPlaceTrueDivide(x,y)
#else
  #define __Pyx_PyNumber_Divide(x,y) PyNumber_Divide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y) PyNumber_InPlaceDivide(x,y)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1 && CYTHON_USE_UNICODE_INTERNALS
#define __Pyx_PyDict_GetItemStr(dict,name) _PyDict_GetItem_KnownHash(dict, name, ((PyASCIIObject *) name)->hash)
#else
#define __Pyx_PyDict_GetItemStr(dict,name) PyDict_GetItem(dict, name)
#endif
#if PY_VERSION_HEX > 0x03030000 && defined(PyUnicode_KIND)
  #define CYTHON_PEP393_ENABLED 1
  #define __Pyx_PyUnicode_READY(op) (likely(PyUnicode_IS_READY(op)) ?\
                                              0 : _PyUnicode_Ready((PyObject *)(op)))
  #define __Pyx_PyUnicode_GET_LENGTH(u) PyUnicode_GET_LENGTH(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) PyUnicode_READ_CHAR(u, i)
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u) PyUnicode_MAX_CHAR_VALUE(u)
  #define __Pyx_PyUnicode_KIND(u) PyUnicode_KIND(u)
  #define __Pyx_PyUnicode_DATA(u) PyUnicode_DATA(u)
  #define __Pyx_PyUnicode_READ(k, d, i) PyUnicode_READ(k, d, i)
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch) PyUnicode_WRITE(k, d, i, ch)
  #if defined(PyUnicode_IS_READY) && defined(PyUnicode_GET_SIZE)
  #define __Pyx_PyUnicode_IS_TRUE(u) (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : PyUnicode_GET_SIZE(u)))
  #else
  #define __Pyx_PyUnicode_IS_TRUE(u) (0 != PyUnicode_GET_LENGTH(u))
  #endif
#else
  #define CYTHON_PEP393_ENABLED 0
  #define PyUnicode_1BYTE_KIND 1
  #define PyUnicode_2BYTE_KIND 2
  #define PyUnicode_4BYTE_KIND 4
  #define __Pyx_PyUnicode_READY(op) (0)
  #define __Pyx_PyUnicode_GET_LENGTH(u) PyUnicode_GET_SIZE(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) ((Py_UCS4)(PyUnicode_AS_UNICODE(u)[i]))
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u) ((sizeof(Py_UNICODE) == 2) ? 65535 : 1114111)
  #define __Pyx_PyUnicode_KIND(u) (sizeof(Py_UNICODE))
  #define __Pyx_PyUnicode_DATA(u) ((void*)PyUnicode_AS_UNICODE(u))
  #define __Pyx_PyUnicode_READ(k, d, i) ((void)(k), (Py_UCS4)(((Py_UNICODE*)d)[i]))
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch) (((void)(k)), ((Py_UNICODE*)d)[i] = ch)
  #define __Pyx_PyUnicode_IS_TRUE(u) (0 != PyUnicode_GET_SIZE(u))
#endif
#if CYTHON_COMPILING_IN_PYPY
  #define __Pyx_PyUnicode_Concat(a, b) PyNumber_Add(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b) PyNumber_Add(a, b)
#else
  #define __Pyx_PyUnicode_Concat(a, b) PyUnicode_Concat(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b) ((unlikely((a) == Py_None) || unlikely((b) == Py_None)) ?\
      PyNumber_Add(a, b) : __Pyx_PyUnicode_Concat(a, b))
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyUnicode_Contains)
  #define PyUnicode_Contains(u, s) PySequence_Contains(u, s)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyByteArray_Check)
  #define PyByteArray_Check(obj) PyObject_TypeCheck(obj, &PyByteArray_Type)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Format)
  #define PyObject_Format(obj, fmt) PyObject_CallMethod(obj, "__format__", "O", fmt)
#endif
#define __Pyx_PyString_FormatSafe(a,b) ((unlikely((a) == Py_None || (PyString_Check(b) && !PyString_CheckExact(b)))) ? PyNumber_Remainder(a, b) : __Pyx_PyString_Format(a, b))
#define __Pyx_PyUnicode_FormatSafe(a,b) ((unlikely((a) == Py_None || (PyUnicode_Check(b) && !PyUnicode_CheckExact(b)))) ? PyNumber_Remainder(a, b) : PyUnicode_Format(a, b))
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyString_Format(a, b) PyUnicode_Format(a, b)
#else
  #define __Pyx_PyString_Format(a, b) PyString_Format(a, b)
#endif
#if PY_MAJOR_VERSION < 3 && !defined(PyObject_ASCII)
  #define PyObject_ASCII(o) PyObject_Repr(o)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBaseString_Type PyUnicode_Type
  #define PyStringObject PyUnicodeObject
  #define PyString_Type PyUnicode_Type
  #define PyString_Check PyUnicode_Check
  #define PyString_CheckExact PyUnicode_CheckExact
#ifndef PyObject_Unicode
  #define PyObject_Unicode PyObject_Str
#endif
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyBaseString_Check(obj) PyUnicode_Check(obj)
  #define __Pyx_PyBaseString_CheckExact(obj) PyUnicode_CheckExact(obj)
#else
  #define __Pyx_PyBaseString_Check(obj) (PyString_Check(obj) || PyUnicode_Check(obj))
  #define __Pyx_PyBaseString_CheckExact(obj) (PyString_CheckExact(obj) || PyUnicode_CheckExact(obj))
#endif
#ifndef PySet_CheckExact
  #define PySet_CheckExact(obj) (Py_TYPE(obj) == &PySet_Type)
#endif
#if PY_VERSION_HEX >= 0x030900A4
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_SET_REFCNT(obj, refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SET_SIZE(obj, size)
#else
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_REFCNT(obj) = (refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SIZE(obj) = (size)
#endif
#if CYTHON_ASSUME_SAFE_MACROS
  #define __Pyx_PySequence_SIZE(seq) Py_SIZE(seq)
#else
  #define __Pyx_PySequence_SIZE(seq) PySequence_Size(seq)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyIntObject PyLongObject
  #define PyInt_Type PyLong_Type
  #define PyInt_Check(op) PyLong_Check(op)
  #define PyInt_CheckExact(op) PyLong_CheckExact(op)
  #define PyInt_FromString PyLong_FromString
  #define PyInt_FromUnicode PyLong_FromUnicode
  #define PyInt_FromLong PyLong_FromLong
  #define PyInt_FromSize_t PyLong_FromSize_t
  #define PyInt_FromSsize_t PyLong_FromSsize_t
  #define PyInt_AsLong PyLong_AsLong
  #define PyInt_AS_LONG PyLong_AS_LONG
  #define PyInt_AsSsize_t PyLong_AsSsize_t
  #define PyInt_AsUnsignedLongMask PyLong_AsUnsignedLongMask
  #define PyInt_AsUnsignedLongLongMask PyLong_AsUnsignedLongLongMask
  #define PyNumber_Int PyNumber_Long
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBoolObject PyLongObject
#endif
#if PY_MAJOR_VERSION >= 3 && CYTHON_COMPILING_IN_PYPY
  #ifndef PyUnicode_InternFromString
    #define PyUnicode_InternFromString(s) PyUnicode_FromString(s)
  #endif
#endif
#if PY_VERSION_HEX < 0x030200A4
  typedef long Py_hash_t;
  #define __Pyx_PyInt_FromHash_t PyInt_FromLong
  #define __Pyx_PyInt_AsHash_t PyInt_AsLong
#else
  #define __Pyx_PyInt_FromHash_t PyInt_FromSsize_t
  #define __Pyx_PyInt_AsHash_t PyInt_AsSsize_t
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyMethod_New(func, self, klass) ((self) ? ((void)(klass), PyMethod_New(func, self)) : __Pyx_NewRef(func))
#else
  #define __Pyx_PyMethod_New(func, self, klass) PyMethod_New(func, self, klass)
#endif
#if CYTHON_USE_ASYNC_SLOTS
  #if PY_VERSION_HEX >= 0x030500B1
    #define __Pyx_PyAsyncMethodsStruct PyAsyncMethods
    #define __Pyx_PyType_AsAsync(obj) (Py_TYPE(obj)->tp_as_async)
  #else
    #define __Pyx_PyType_AsAsync(obj) ((__Pyx_PyAsyncMethodsStruct*) (Py_TYPE(obj)->tp_reserved))
  #endif
#else
  #define __Pyx_PyType_AsAsync(obj) NULL
#endif
#ifndef __Pyx_PyAsyncMethodsStruct
    typedef struct {
        unaryfunc am_await;
        unaryfunc am_aiter;
        unaryfunc am_anext;
    } __Pyx_PyAsyncMethodsStruct;
#endif

#if defined(WIN32) || defined(MS_WINDOWS)
  #define _USE_MATH_DEFINES
#endif
#include <math.h>
#ifdef NAN
#define __PYX_NAN() ((float) NAN)
#else
static CYTHON_INLINE float __PYX_NAN() {
  float value;
  memset(&value, 0xFF, sizeof(value));
  return value;
}
#endif
#if defined(__CYGWIN__) && defined(_LDBL_EQ_DBL)
#define __Pyx_truncl trunc
#else
#define __Pyx_truncl truncl
#endif

#define __PYX_MARK_ERR_POS(f_index,lineno) \
    { __pyx_filename = __pyx_f[f_index]; (void)__pyx_filename; __pyx_lineno = lineno; (void)__pyx_lineno; __pyx_clineno = __LINE__; (void)__pyx_clineno; }
#define __PYX_ERR(f_index,lineno,Ln_error) \
    { __PYX_MARK_ERR_POS(f_index, lineno) goto Ln_error; }

#ifndef __PYX_EXTERN_C
  #ifdef __cplusplus
    #define __PYX_EXTERN_C extern "C"
  #else
    #define __PYX_EXTERN_C extern
  #endif
#endif

#define __PYX_HAVE__example1 
#define __PYX_HAVE_API__example1 

#ifdef _OPENMP
#include <omp.h>
#endif

#if defined(PYREX_WITHOUT_ASSERTIONS) && !defined(CYTHON_WITHOUT_ASSERTIONS)
#define CYTHON_WITHOUT_ASSERTIONS 
#endif

typedef struct {PyObject **p; const char *s; const Py_ssize_t n; const char* encoding;
                const char is_unicode; const char is_str; const char intern; } __Pyx_StringTabEntry;

#define __PYX_DEFAULT_STRING_ENCODING_IS_ASCII 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_UTF8 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT (PY_MAJOR_VERSION >= 3 && __PYX_DEFAULT_STRING_ENCODING_IS_UTF8)
#define __PYX_DEFAULT_STRING_ENCODING ""
#define __Pyx_PyObject_FromString __Pyx_PyBytes_FromString
#define __Pyx_PyObject_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#define __Pyx_uchar_cast(c) ((unsigned char)c)
#define __Pyx_long_cast(x) ((long)x)
#define __Pyx_fits_Py_ssize_t(v,type,is_signed) (\
    (sizeof(type) < sizeof(Py_ssize_t)) ||\
    (sizeof(type) > sizeof(Py_ssize_t) &&\
          likely(v < (type)PY_SSIZE_T_MAX ||\
                 v == (type)PY_SSIZE_T_MAX) &&\
          (!is_signed || likely(v > (type)PY_SSIZE_T_MIN ||\
                                v == (type)PY_SSIZE_T_MIN))) ||\
    (sizeof(type) == sizeof(Py_ssize_t) &&\
          (is_signed || likely(v < (type)PY_SSIZE_T_MAX ||\
                               v == (type)PY_SSIZE_T_MAX))) )
static CYTHON_INLINE int __Pyx_is_valid_index(Py_ssize_t i, Py_ssize_t limit) {
    return (size_t) i < (size_t) limit;
}
#if defined (__cplusplus) && __cplusplus >= 201103L
    #include <cstdlib>
    #define __Pyx_sst_abs(value) std::abs(value)
#elif SIZEOF_INT >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) abs(value)
#elif SIZEOF_LONG >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) labs(value)
#elif defined (_MSC_VER)
    #define __Pyx_sst_abs(value) ((Py_ssize_t)_abs64(value))
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define __Pyx_sst_abs(value) llabs(value)
#elif defined (__GNUC__)
    #define __Pyx_sst_abs(value) __builtin_llabs(value)
#else
    #define __Pyx_sst_abs(value) ((value<0) ? -value : value)
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject*);
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject*, Py_ssize_t* length);
#define __Pyx_PyByteArray_FromString(s) PyByteArray_FromStringAndSize((const char*)s, strlen((const char*)s))
#define __Pyx_PyByteArray_FromStringAndSize(s,l) PyByteArray_FromStringAndSize((const char*)s, l)
#define __Pyx_PyBytes_FromString PyBytes_FromString
#define __Pyx_PyBytes_FromStringAndSize PyBytes_FromStringAndSize
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char*);
#if PY_MAJOR_VERSION < 3
    #define __Pyx_PyStr_FromString __Pyx_PyBytes_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#else
    #define __Pyx_PyStr_FromString __Pyx_PyUnicode_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyUnicode_FromStringAndSize
#endif
#define __Pyx_PyBytes_AsWritableString(s) ((char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableSString(s) ((signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableUString(s) ((unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsString(s) ((const char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsSString(s) ((const signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsUString(s) ((const unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyObject_AsWritableString(s) ((char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableSString(s) ((signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableUString(s) ((unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsSString(s) ((const signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsUString(s) ((const unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_FromCString(s) __Pyx_PyObject_FromString((const char*)s)
#define __Pyx_PyBytes_FromCString(s) __Pyx_PyBytes_FromString((const char*)s)
#define __Pyx_PyByteArray_FromCString(s) __Pyx_PyByteArray_FromString((const char*)s)
#define __Pyx_PyStr_FromCString(s) __Pyx_PyStr_FromString((const char*)s)
#define __Pyx_PyUnicode_FromCString(s) __Pyx_PyUnicode_FromString((const char*)s)
static CYTHON_INLINE size_t __Pyx_Py_UNICODE_strlen(const Py_UNICODE *u) {
    const Py_UNICODE *u_end = u;
    while (*u_end++) ;
    return (size_t)(u_end - u - 1);
}
#define __Pyx_PyUnicode_FromUnicode(u) PyUnicode_FromUnicode(u, __Pyx_Py_UNICODE_strlen(u))
#define __Pyx_PyUnicode_FromUnicodeAndLength PyUnicode_FromUnicode
#define __Pyx_PyUnicode_AsUnicode PyUnicode_AsUnicode
#define __Pyx_NewRef(obj) (Py_INCREF(obj), obj)
#define __Pyx_Owned_Py_None(b) __Pyx_NewRef(Py_None)
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b);
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject*);
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject*);
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x);
#define __Pyx_PySequence_Tuple(obj) \
    (likely(PyTuple_CheckExact(obj)) ? __Pyx_NewRef(obj) : PySequence_Tuple(obj))
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject*);
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t);
#if CYTHON_ASSUME_SAFE_MACROS
#define __pyx_PyFloat_AsDouble(x) (PyFloat_CheckExact(x) ? PyFloat_AS_DOUBLE(x) : PyFloat_AsDouble(x))
#else
#define __pyx_PyFloat_AsDouble(x) PyFloat_AsDouble(x)
#endif
#define __pyx_PyFloat_AsFloat(x) ((float) __pyx_PyFloat_AsDouble(x))
#if PY_MAJOR_VERSION >= 3
#define __Pyx_PyNumber_Int(x) (PyLong_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Long(x))
#else
#define __Pyx_PyNumber_Int(x) (PyInt_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Int(x))
#endif
#define __Pyx_PyNumber_Float(x) (PyFloat_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Float(x))
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
static int __Pyx_sys_getdefaultencoding_not_ascii;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    PyObject* ascii_chars_u = NULL;
    PyObject* ascii_chars_b = NULL;
    const char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    if (strcmp(default_encoding_c, "ascii") == 0) {
        __Pyx_sys_getdefaultencoding_not_ascii = 0;
    } else {
        char ascii_chars[128];
        int c;
        for (c = 0; c < 128; c++) {
            ascii_chars[c] = c;
        }
        __Pyx_sys_getdefaultencoding_not_ascii = 1;
        ascii_chars_u = PyUnicode_DecodeASCII(ascii_chars, 128, NULL);
        if (!ascii_chars_u) goto bad;
        ascii_chars_b = PyUnicode_AsEncodedString(ascii_chars_u, default_encoding_c, NULL);
        if (!ascii_chars_b || !PyBytes_Check(ascii_chars_b) || memcmp(ascii_chars, PyBytes_AS_STRING(ascii_chars_b), 128) != 0) {
            PyErr_Format(
                PyExc_ValueError,
                "This module compiled with c_string_encoding=ascii, but default encoding '%.200s' is not a superset of ascii.",
                default_encoding_c);
            goto bad;
        }
        Py_DECREF(ascii_chars_u);
        Py_DECREF(ascii_chars_b);
    }
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    Py_XDECREF(ascii_chars_u);
    Py_XDECREF(ascii_chars_b);
    return -1;
}
#endif
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT && PY_MAJOR_VERSION >= 3
#define __Pyx_PyUnicode_FromStringAndSize(c_str,size) PyUnicode_DecodeUTF8(c_str, size, NULL)
#else
#define __Pyx_PyUnicode_FromStringAndSize(c_str,size) PyUnicode_Decode(c_str, size, __PYX_DEFAULT_STRING_ENCODING, NULL)
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
static char* __PYX_DEFAULT_STRING_ENCODING;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) (const char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    __PYX_DEFAULT_STRING_ENCODING = (char*) malloc(strlen(default_encoding_c) + 1);
    if (!__PYX_DEFAULT_STRING_ENCODING) goto bad;
    strcpy(__PYX_DEFAULT_STRING_ENCODING, default_encoding_c);
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    return -1;
}
#endif
#endif



#if defined(__GNUC__) && (__GNUC__ > 2 || (__GNUC__ == 2 && (__GNUC_MINOR__ > 95)))
  #define likely(x) __builtin_expect(!!(x), 1)
  #define unlikely(x) __builtin_expect(!!(x), 0)
#else
  #define likely(x) (x)
  #define unlikely(x) (x)
#endif
static CYTHON_INLINE void __Pyx_pretend_to_initialize(void* ptr) { (void)ptr; }

static PyObject *__pyx_m = NULL;
static PyObject *__pyx_d;
static PyObject *__pyx_b;
static PyObject *__pyx_cython_runtime = NULL;
static PyObject *__pyx_empty_tuple;
static PyObject *__pyx_empty_bytes;
static PyObject *__pyx_empty_unicode;
static int __pyx_lineno;
static int __pyx_clineno = 0;
static const char * __pyx_cfilenm= __FILE__;
static const char *__pyx_filename;


static const char *__pyx_f[] = {
  "example1.py",
};





#ifndef CYTHON_REFNANNY
  #define CYTHON_REFNANNY 0
#endif
#if CYTHON_REFNANNY
  typedef struct {
    void (*INCREF)(void*, PyObject*, int);
    void (*DECREF)(void*, PyObject*, int);
    void (*GOTREF)(void*, PyObject*, int);
    void (*GIVEREF)(void*, PyObject*, int);
    void* (*SetupContext)(const char*, int, const char*);
    void (*FinishContext)(void**);
  } __Pyx_RefNannyAPIStruct;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNanny = NULL;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname);
  #define __Pyx_RefNannyDeclarations void *__pyx_refnanny = NULL;
#ifdef WITH_THREAD
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          if (acquire_gil) {\
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure();\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
              PyGILState_Release(__pyx_gilstate_save);\
          } else {\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
          }
#else
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__)
#endif
  #define __Pyx_RefNannyFinishContext()\
          __Pyx_RefNanny->FinishContext(&__pyx_refnanny)
  #define __Pyx_INCREF(r) __Pyx_RefNanny->INCREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_DECREF(r) __Pyx_RefNanny->DECREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GOTREF(r) __Pyx_RefNanny->GOTREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GIVEREF(r) __Pyx_RefNanny->GIVEREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_XINCREF(r) do { if((r) != NULL) {__Pyx_INCREF(r); }} while(0)
  #define __Pyx_XDECREF(r) do { if((r) != NULL) {__Pyx_DECREF(r); }} while(0)
  #define __Pyx_XGOTREF(r) do { if((r) != NULL) {__Pyx_GOTREF(r); }} while(0)
  #define __Pyx_XGIVEREF(r) do { if((r) != NULL) {__Pyx_GIVEREF(r);}} while(0)
#else
  #define __Pyx_RefNannyDeclarations
  #define __Pyx_RefNannySetupContext(name, acquire_gil)
  #define __Pyx_RefNannyFinishContext()
  #define __Pyx_INCREF(r) Py_INCREF(r)
  #define __Pyx_DECREF(r) Py_DECREF(r)
  #define __Pyx_GOTREF(r)
  #define __Pyx_GIVEREF(r)
  #define __Pyx_XINCREF(r) Py_XINCREF(r)
  #define __Pyx_XDECREF(r) Py_XDECREF(r)
  #define __Pyx_XGOTREF(r)
  #define __Pyx_XGIVEREF(r)
#endif
#define __Pyx_XDECREF_SET(r,v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_XDECREF(tmp);\
    } while (0)
#define __Pyx_DECREF_SET(r,v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_DECREF(tmp);\
    } while (0)
#define __Pyx_CLEAR(r) do { PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);} while(0)
#define __Pyx_XCLEAR(r) do { if((r) != NULL) {PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);}} while(0)


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GetAttrStr(o,n) PyObject_GetAttr(o,n)
#endif


static PyObject *__Pyx_GetBuiltinName(PyObject *name);


static void __Pyx_RaiseArgtupleInvalid(const char* func_name, int exact,
    Py_ssize_t num_min, Py_ssize_t num_max, Py_ssize_t num_found);


static void __Pyx_RaiseDoubleKeywordsError(const char* func_name, PyObject* kw_name);


static int __Pyx_ParseOptionalKeywords(PyObject *kwds, PyObject **argnames[],\
    PyObject *kwds2, PyObject *values[], Py_ssize_t num_pos_args,\
    const char* function_name);


#define __Pyx_GetItemInt(o,i,type,is_signed,to_py_func,is_list,wraparound,boundscheck) \
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Fast(o, (Py_ssize_t)i, is_list, wraparound, boundscheck) :\
    (is_list ? (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL) :\
               __Pyx_GetItemInt_Generic(o, to_py_func(i))))
#define __Pyx_GetItemInt_List(o,i,type,is_signed,to_py_func,is_list,wraparound,boundscheck) \
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_List_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
#define __Pyx_GetItemInt_Tuple(o,i,type,is_signed,to_py_func,is_list,wraparound,boundscheck) \
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Tuple_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "tuple index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j);
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i,
                                                     int is_list, int wraparound, int boundscheck);


static double __Pyx__PyObject_AsDouble(PyObject* obj);
#if CYTHON_COMPILING_IN_PYPY
#define __Pyx_PyObject_AsDouble(obj) \
(likely(PyFloat_CheckExact(obj)) ? PyFloat_AS_DOUBLE(obj) :\
 likely(PyInt_CheckExact(obj)) ?\
 PyFloat_AsDouble(obj) : __Pyx__PyObject_AsDouble(obj))
#else
#define __Pyx_PyObject_AsDouble(obj) \
((likely(PyFloat_CheckExact(obj))) ?\
 PyFloat_AS_DOUBLE(obj) : __Pyx__PyObject_AsDouble(obj))
#endif


#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
#define __PYX_DICT_VERSION_INIT ((PY_UINT64_T) -1)
#define __PYX_GET_DICT_VERSION(dict) (((PyDictObject*)(dict))->ma_version_tag)
#define __PYX_UPDATE_DICT_CACHE(dict,value,cache_var,version_var) \
    (version_var) = __PYX_GET_DICT_VERSION(dict);\
    (cache_var) = (value);
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR,DICT,LOOKUP) {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    if (likely(__PYX_GET_DICT_VERSION(DICT) == __pyx_dict_version)) {\
        (VAR) = __pyx_dict_cached_value;\
    } else {\
        (VAR) = __pyx_dict_cached_value = (LOOKUP);\
        __pyx_dict_version = __PYX_GET_DICT_VERSION(DICT);\
    }\
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj);
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj);
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version);
#else
#define __PYX_GET_DICT_VERSION(dict) (0)
#define __PYX_UPDATE_DICT_CACHE(dict,value,cache_var,version_var) 
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR,DICT,LOOKUP) (VAR) = (LOOKUP);
#endif


#if CYTHON_USE_DICT_VERSIONS
#define __Pyx_GetModuleGlobalName(var,name) {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    (var) = (likely(__pyx_dict_version == __PYX_GET_DICT_VERSION(__pyx_d))) ?\
        (likely(__pyx_dict_cached_value) ? __Pyx_NewRef(__pyx_dict_cached_value) : __Pyx_GetBuiltinName(name)) :\
        __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
#define __Pyx_GetModuleGlobalNameUncached(var,name) {\
    PY_UINT64_T __pyx_dict_version;\
    PyObject *__pyx_dict_cached_value;\
    (var) = __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value);
#else
#define __Pyx_GetModuleGlobalName(var,name) (var) = __Pyx__GetModuleGlobalName(name)
#define __Pyx_GetModuleGlobalNameUncached(var,name) (var) = __Pyx__GetModuleGlobalName(name)
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name);
#endif


#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject *__Pyx_PyCFunction_FastCall(PyObject *func, PyObject **args, Py_ssize_t nargs);
#else
#define __Pyx_PyCFunction_FastCall(func,args,nargs) (assert(0), NULL)
#endif


#if CYTHON_FAST_PYCALL
#define __Pyx_PyFunction_FastCall(func,args,nargs) \
    __Pyx_PyFunction_FastCallDict((func), (args), (nargs), NULL)
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs);
#else
#define __Pyx_PyFunction_FastCallDict(func,args,nargs,kwargs) _PyFunction_FastCallDict(func, args, nargs, kwargs)
#endif
#define __Pyx_BUILD_ASSERT_EXPR(cond) \
    (sizeof(char [1 - 2*!(cond)]) - 1)
#ifndef Py_MEMBER_SIZE
#define Py_MEMBER_SIZE(type,member) sizeof(((type *)0)->member)
#endif
  static size_t __pyx_pyframe_localsplus_offset = 0;
  #include "frameobject.h"
  #define __Pxy_PyFrame_Initialize_Offsets()\
    ((void)__Pyx_BUILD_ASSERT_EXPR(sizeof(PyFrameObject) == offsetof(PyFrameObject, f_localsplus) + Py_MEMBER_SIZE(PyFrameObject, f_localsplus)),\
     (void)(__pyx_pyframe_localsplus_offset = ((size_t)PyFrame_Type.tp_basicsize) - Py_MEMBER_SIZE(PyFrameObject, f_localsplus)))
  #define __Pyx_PyFrame_GetLocalsplus(frame)\
    (assert(__pyx_pyframe_localsplus_offset), (PyObject **)(((char *)(frame)) + __pyx_pyframe_localsplus_offset))
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw);
#else
#define __Pyx_PyObject_Call(func,arg,kw) PyObject_Call(func, arg, kw)
#endif


static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2);


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg);
#endif


static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg);


#if CYTHON_USE_PYLIST_INTERNALS && CYTHON_ASSUME_SAFE_MACROS
static CYTHON_INLINE int __Pyx_PyList_Append(PyObject* list, PyObject* x) {
    PyListObject* L = (PyListObject*) list;
    Py_ssize_t len = Py_SIZE(list);
    if (likely(L->allocated > len) & likely(len > (L->allocated >> 1))) {
        Py_INCREF(x);
        PyList_SET_ITEM(list, len, x);
        __Pyx_SET_SIZE(list, len + 1);
        return 0;
    }
    return PyList_Append(list, x);
}
#else
#define __Pyx_PyList_Append(L,x) PyList_Append(L,x)
#endif


#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_AddObjC(PyObject *op1, PyObject *op2, long intval, int inplace, int zerodivision_check);
#else
#define __Pyx_PyInt_AddObjC(op1,op2,intval,inplace,zerodivision_check) \
    (inplace ? PyNumber_InPlaceAdd(op1, op2) : PyNumber_Add(op1, op2))
#endif


#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_SubtractObjC(PyObject *op1, PyObject *op2, long intval, int inplace, int zerodivision_check);
#else
#define __Pyx_PyInt_SubtractObjC(op1,op2,intval,inplace,zerodivision_check) \
    (inplace ? PyNumber_InPlaceSubtract(op1, op2) : PyNumber_Subtract(op1, op2))
#endif


static CYTHON_INLINE PyObject* __Pyx_PyInt_EqObjC(PyObject *op1, PyObject *op2, long intval, long inplace);


static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method);


static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg);


static CYTHON_INLINE int __Pyx_PyObject_Append(PyObject* L, PyObject* x);


static CYTHON_INLINE PyObject* __Pyx_PyInt_NeObjC(PyObject *op1, PyObject *op2, long intval, long inplace);


#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem * __Pyx_PyErr_GetTopmostException(PyThreadState *tstate);
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyThreadState_declare PyThreadState *__pyx_tstate;
#define __Pyx_PyThreadState_assign __pyx_tstate = __Pyx_PyThreadState_Current;
#define __Pyx_PyErr_Occurred() __pyx_tstate->curexc_type
#else
#define __Pyx_PyThreadState_declare 
#define __Pyx_PyThreadState_assign 
#define __Pyx_PyErr_Occurred() PyErr_Occurred()
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSave(type,value,tb) __Pyx__ExceptionSave(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#define __Pyx_ExceptionReset(type,value,tb) __Pyx__ExceptionReset(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
#else
#define __Pyx_ExceptionSave(type,value,tb) PyErr_GetExcInfo(type, value, tb)
#define __Pyx_ExceptionReset(type,value,tb) PyErr_SetExcInfo(type, value, tb)
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_GetException(type,value,tb) __Pyx__GetException(__pyx_tstate, type, value, tb)
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb);
#endif


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject *__Pyx_PyObject_GetItem(PyObject *obj, PyObject* key);
#else
#define __Pyx_PyObject_GetItem(obj,key) PyObject_GetItem(obj, key)
#endif


static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level);


static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type);


#define __Pyx_CyFunction_USED 1
#define __Pyx_CYFUNCTION_STATICMETHOD 0x01
#define __Pyx_CYFUNCTION_CLASSMETHOD 0x02
#define __Pyx_CYFUNCTION_CCLASS 0x04
#define __Pyx_CyFunction_GetClosure(f) \
    (((__pyx_CyFunctionObject *) (f))->func_closure)
#define __Pyx_CyFunction_GetClassObj(f) \
    (((__pyx_CyFunctionObject *) (f))->func_classobj)
#define __Pyx_CyFunction_Defaults(type,f) \
    ((type *)(((__pyx_CyFunctionObject *) (f))->defaults))
#define __Pyx_CyFunction_SetDefaultsGetter(f,g) \
    ((__pyx_CyFunctionObject *) (f))->defaults_getter = (g)
typedef struct {
    PyCFunctionObject func;
#if PY_VERSION_HEX < 0x030500A0
    PyObject *func_weakreflist;
#endif
    PyObject *func_dict;
    PyObject *func_name;
    PyObject *func_qualname;
    PyObject *func_doc;
    PyObject *func_globals;
    PyObject *func_code;
    PyObject *func_closure;
    PyObject *func_classobj;
    void *defaults;
    int defaults_pyobjects;
    size_t defaults_size;
    int flags;
    PyObject *defaults_tuple;
    PyObject *defaults_kwdict;
    PyObject *(*defaults_getter)(PyObject *);
    PyObject *func_annotations;
} __pyx_CyFunctionObject;
static PyTypeObject *__pyx_CyFunctionType = 0;
#define __Pyx_CyFunction_Check(obj) (__Pyx_TypeCheck(obj, __pyx_CyFunctionType))
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject* op, PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *self,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *m,
                                                         size_t size,
                                                         int pyobjects);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *m,
                                                            PyObject *tuple);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *m,
                                                             PyObject *dict);
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *m,
                                                              PyObject *dict);
static int __pyx_CyFunction_init(void);


static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *closure,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_Clear() __Pyx_ErrRestore(NULL, NULL, NULL)
#define __Pyx_ErrRestoreWithState(type,value,tb) __Pyx_ErrRestoreInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrFetchWithState(type,value,tb) __Pyx_ErrFetchInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrRestore(type,value,tb) __Pyx_ErrRestoreInState(__pyx_tstate, type, value, tb)
#define __Pyx_ErrFetch(type,value,tb) __Pyx_ErrFetchInState(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_PyErr_SetNone(exc) (Py_INCREF(exc), __Pyx_ErrRestore((exc), NULL, NULL))
#else
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#endif
#else
#define __Pyx_PyErr_Clear() PyErr_Clear()
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#define __Pyx_ErrRestoreWithState(type,value,tb) PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchWithState(type,value,tb) PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestoreInState(tstate,type,value,tb) PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchInState(tstate,type,value,tb) PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestore(type,value,tb) PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetch(type,value,tb) PyErr_Fetch(type, value, tb)
#endif


#ifdef CYTHON_CLINE_IN_TRACEBACK
#define __Pyx_CLineForTraceback(tstate,c_line) (((CYTHON_CLINE_IN_TRACEBACK)) ? c_line : 0)
#else
static int __Pyx_CLineForTraceback(PyThreadState *tstate, int c_line);
#endif


typedef struct {
    PyCodeObject* code_object;
    int code_line;
} __Pyx_CodeObjectCacheEntry;
struct __Pyx_CodeObjectCache {
    int count;
    int max_count;
    __Pyx_CodeObjectCacheEntry* entries;
};
static struct __Pyx_CodeObjectCache __pyx_code_cache = {0,0,NULL};
static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line);
static PyCodeObject *__pyx_find_code_object(int code_line);
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object);


static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename);


static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value);


static int __Pyx_Print(PyObject*, PyObject *, int);
#if CYTHON_COMPILING_IN_PYPY || PY_MAJOR_VERSION >= 3
static PyObject* __pyx_print = 0;
static PyObject* __pyx_print_kwargs = 0;
#endif


static int __Pyx_PrintOne(PyObject* stream, PyObject *o);


static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *);


static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *);


#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_TypeCheck(obj,type) __Pyx_IsSubtype(Py_TYPE(obj), (PyTypeObject *)type)
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject *type);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *type1, PyObject *type2);
#else
#define __Pyx_TypeCheck(obj,type) PyObject_TypeCheck(obj, (PyTypeObject *)type)
#define __Pyx_PyErr_GivenExceptionMatches(err,type) PyErr_GivenExceptionMatches(err, type)
#define __Pyx_PyErr_GivenExceptionMatches2(err,type1,type2) (PyErr_GivenExceptionMatches(err, type1) || PyErr_GivenExceptionMatches(err, type2))
#endif
#define __Pyx_PyException_Check(obj) __Pyx_TypeCheck(obj, PyExc_Exception)


static int __Pyx_check_binary_version(void);


static int __Pyx_InitStrings(__Pyx_StringTabEntry *t);



#define __Pyx_MODULE_NAME "example1"
extern int __pyx_module_is_main_example1;
int __pyx_module_is_main_example1 = 0;


static PyObject *__pyx_builtin_range;
static const char __pyx_k_[] = "************";
static const char __pyx_k_A[] = "A";
static const char __pyx_k_B[] = "B";
static const char __pyx_k_C[] = "C";
static const char __pyx_k_D[] = "D";
static const char __pyx_k_K[] = "K";
static const char __pyx_k_L[] = "L";
static const char __pyx_k_N[] = "N";
static const char __pyx_k_R[] = "R";
static const char __pyx_k_T[] = "T";
static const char __pyx_k_X[] = "X";
static const char __pyx_k_Y[] = "Y";
static const char __pyx_k_a[] = "a";
static const char __pyx_k_b[] = "b";
static const char __pyx_k_c[] = "c";
static const char __pyx_k_d[] = "d";
static const char __pyx_k_i[] = "i";
static const char __pyx_k_j[] = "j";
static const char __pyx_k_k[] = "k";
static const char __pyx_k_l[] = "l";
static const char __pyx_k_m[] = "m";
static const char __pyx_k_n[] = "n";
static const char __pyx_k_r[] = "r";
static const char __pyx_k_t[] = "t";
static const char __pyx_k_x[] = "x";
static const char __pyx_k_y[] = "y";
static const char __pyx_k_z[] = "z";
static const char __pyx_k_N1[] = "N1";
static const char __pyx_k_N2[] = "N2";
static const char __pyx_k_T0[] = "T0";
static const char __pyx_k_Tz[] = "Tz";
static const char __pyx_k__2[] = "---";
static const char __pyx_k_a1[] = "a1";
static const char __pyx_k_a2[] = "a2";
static const char __pyx_k_b1[] = "b1";
static const char __pyx_k_b2[] = "b2";
static const char __pyx_k_c1[] = "c1";
static const char __pyx_k_c2[] = "c2";
static const char __pyx_k_d1[] = "d1";
static const char __pyx_k_d2[] = "d2";
static const char __pyx_k_l1[] = "l1";
static const char __pyx_k_l2[] = "l2";
static const char __pyx_k_m1[] = "m1";
static const char __pyx_k_m2[] = "m2";
static const char __pyx_k_nx[] = "nx";
static const char __pyx_k_ny[] = "ny";
static const char __pyx_k_pi[] = "pi";
static const char __pyx_k_N_2[] = "N=";
static const char __pyx_k_cos[] = "cos";
static const char __pyx_k_det[] = "det";
static const char __pyx_k_end[] = "end";
static const char __pyx_k_exp[] = "exp";
static const char __pyx_k_log[] = "log";
static const char __pyx_k_out[] = "out";
static const char __pyx_k_rho[] = "rho";
static const char __pyx_k_sin[] = "sin";
static const char __pyx_k_tmp[] = "tmp";
static const char __pyx_k_tot[] = "tot";
static const char __pyx_k_atan[] = "atan";
static const char __pyx_k_file[] = "file";
static const char __pyx_k_flag[] = "flag";
static const char __pyx_k_main[] = "__main__";
static const char __pyx_k_math[] = "math";
static const char __pyx_k_mean[] = "mean";
static const char __pyx_k_name[] = "__name__";
static const char __pyx_k_node[] = "node";
static const char __pyx_k_null[] = "null";
static const char __pyx_k_numb[] = "numb";
static const char __pyx_k_sqrt[] = "sqrt";
static const char __pyx_k_sum1[] = "sum1";
static const char __pyx_k_sum2[] = "sum2";
static const char __pyx_k_test[] = "test";
static const char __pyx_k_tmp1[] = "tmp1";
static const char __pyx_k_tmp2[] = "tmp2";
static const char __pyx_k_tmp3[] = "tmp3";
static const char __pyx_k_1_0_1[] = "1.0.1";
static const char __pyx_k_alpha[] = "alpha";
static const char __pyx_k_email[] = "__email__";
static const char __pyx_k_numb1[] = "numb1";
static const char __pyx_k_numb2[] = "numb2";
static const char __pyx_k_print[] = "print";
static const char __pyx_k_range[] = "range";
static const char __pyx_k_theta[] = "theta";
static const char __pyx_k_Gamma0[] = "Gamma0";
static const char __pyx_k_Lambda[] = "Lambda";
static const char __pyx_k_append[] = "append";
static const char __pyx_k_author[] = "__author__";
static const char __pyx_k_import[] = "__import__";
static const char __pyx_k_test_2[] = "__test__";
static const char __pyx_k_counter[] = "counter:";
static const char __pyx_k_initial[] = "initial";
static const char __pyx_k_version[] = "__version__";
static const char __pyx_k_example1[] = "example1";
static const char __pyx_k_counter_2[] = "counter";
static const char __pyx_k_increment[] = "increment";
static const char __pyx_k_occurence[] = "occurence=";
static const char __pyx_k_operator_R[] = "operator_R";
static const char __pyx_k_operator_T[] = "operator_T";
static const char __pyx_k_statistics[] = "statistics";
static const char __pyx_k_example1_py[] = "example1.py";
static const char __pyx_k_inverse_det[] = "inverse_det";
static const char __pyx_k_nodes_in_DT[] = "nodes_in_DT";
static const char __pyx_k_occurence_2[] = "occurence";
static const char __pyx_k_discriminant[] = "discriminant";
static const char __pyx_k_useful_example[] = "useful_example:";
static const char __pyx_k_useful_example_2[] = "useful_example";
static const char __pyx_k_Polar_complex_add[] = "Polar_complex_add";
static const char __pyx_k_Polar_complex_mul[] = "Polar_complex_mul";
static const char __pyx_k_examples_of_10000[] = "examples_of_10000";
static const char __pyx_k_cline_in_traceback[] = "cline_in_traceback";
static const char __pyx_k_Hyperbolic_distance[] = "Hyperbolic_distance";
static const char __pyx_k_real_matrix_inverse[] = "real_matrix_inverse";
static const char __pyx_k_Polar_complex_divide[] = "Polar_complex_divide";
static const char __pyx_k_classification_point[] = "classification_point";
static const char __pyx_k_real_matrix_addition[] = "real_matrix_addition";
static const char __pyx_k_Cartesian_complex_add[] = "Cartesian_complex_add";
static const char __pyx_k_Cartesian_complex_mul[] = "Cartesian_complex_mul";
static const char __pyx_k_wchuang2_mail_sfsu_edu[] = "wchuang2@mail.sfsu.edu";
static const char __pyx_k_Polar_complex_conjugate[] = "Polar_complex_conjugate";
static const char __pyx_k_William_Huanshan_Chuang[] = "William Huanshan Chuang";
static const char __pyx_k_Cartesian_complex_divide[] = "Cartesian_complex_divide";
static const char __pyx_k_Cartesian_complex_modulus[] = "Cartesian_complex_modulus";
static const char __pyx_k_Hyperbolic_Distance_Gamma0[] = "Hyperbolic_Distance_Gamma0";
static const char __pyx_k_real_matrix_multiplication[] = "real_matrix_multiplication";
static const char __pyx_k_check_T_generate_a_Schottky[] = "check_T_generate_a_Schottky";
static const char __pyx_k_Cartesian_complex_scalar_mul[] = "Cartesian_complex_scalar_mul";
static const char __pyx_k_Cartesian_complex_complex_conjug[] = "Cartesian_complex_complex_conjugate";
static const char __pyx_k_Cartesian_complex_complex_to_pol[] = "Cartesian_complex_complex_to_polar";
static const char __pyx_k_Cartesian_complex_matrix_additio[] = "Cartesian_complex_matrix_addition";
static const char __pyx_k_Cartesian_complex_matrix_inverse[] = "Cartesian_complex_matrix_inverse";
static const char __pyx_k_Cartesian_complex_matrix_multipl[] = "Cartesian_complex_matrix_multiplication";
static const char __pyx_k_Cartesian_radial_hyperbolic_dist[] = "Cartesian_radial_hyperbolic_distance";
static const char __pyx_k_Exp_negative_Hyperbolic_Distance[] = "Exp_negative_Hyperbolic_Distance_Gamma0";
static const char __pyx_k_Improved_Exp_negative_Hyperbolic[] = "Improved_Exp_negative_Hyperbolic_Distance_Gamma0";
static const char __pyx_k_Polar_complex_complex_to_Cartesi[] = "Polar_complex_complex_to_Cartesian";
static const char __pyx_k_ave_of_all_exp_of_negative_rho_o[] = "ave_of_all_exp_of_negative_rho_of_this_level:";
static const char __pyx_k_ave_of_all_short_exp_of_negative[] = "ave_of_all_short_exp_of_negative_rho_of_this_level:";
static const char __pyx_k_ave_of_all_exp_of_negative_rho_o_2[] = "ave_of_all_exp_of_negative_rho_of_this_level";
static const char __pyx_k_ave_of_all_short_exp_of_negative_2[] = "ave_of_all_short_exp_of_negative_rho_of_this_level/ave_of_all_exp_of_negative_rho_of_this_level:";
static const char __pyx_k_ave_of_all_short_exp_of_negative_3[] = "ave_of_all_short_exp_of_negative_rho_of_this_level";
static PyObject *__pyx_kp_s_;
static PyObject *__pyx_kp_s_1_0_1;
static PyObject *__pyx_n_s_A;
static PyObject *__pyx_n_s_B;
static PyObject *__pyx_n_s_C;
static PyObject *__pyx_n_s_Cartesian_complex_add;
static PyObject *__pyx_n_s_Cartesian_complex_complex_conjug;
static PyObject *__pyx_n_s_Cartesian_complex_complex_to_pol;
static PyObject *__pyx_n_s_Cartesian_complex_divide;
static PyObject *__pyx_n_s_Cartesian_complex_matrix_additio;
static PyObject *__pyx_n_s_Cartesian_complex_matrix_inverse;
static PyObject *__pyx_n_s_Cartesian_complex_matrix_multipl;
static PyObject *__pyx_n_s_Cartesian_complex_modulus;
static PyObject *__pyx_n_s_Cartesian_complex_mul;
static PyObject *__pyx_n_s_Cartesian_complex_scalar_mul;
static PyObject *__pyx_n_s_Cartesian_radial_hyperbolic_dist;
static PyObject *__pyx_n_s_D;
static PyObject *__pyx_n_s_Exp_negative_Hyperbolic_Distance;
static PyObject *__pyx_n_s_Gamma0;
static PyObject *__pyx_n_s_Hyperbolic_Distance_Gamma0;
static PyObject *__pyx_n_s_Hyperbolic_distance;
static PyObject *__pyx_n_s_Improved_Exp_negative_Hyperbolic;
static PyObject *__pyx_n_s_K;
static PyObject *__pyx_n_s_L;
static PyObject *__pyx_n_s_Lambda;
static PyObject *__pyx_n_s_N;
static PyObject *__pyx_n_s_N1;
static PyObject *__pyx_n_s_N2;
static PyObject *__pyx_kp_s_N_2;
static PyObject *__pyx_n_s_Polar_complex_add;
static PyObject *__pyx_n_s_Polar_complex_complex_to_Cartesi;
static PyObject *__pyx_n_s_Polar_complex_conjugate;
static PyObject *__pyx_n_s_Polar_complex_divide;
static PyObject *__pyx_n_s_Polar_complex_mul;
static PyObject *__pyx_n_s_R;
static PyObject *__pyx_n_s_T;
static PyObject *__pyx_n_s_T0;
static PyObject *__pyx_n_s_Tz;
static PyObject *__pyx_kp_s_William_Huanshan_Chuang;
static PyObject *__pyx_n_s_X;
static PyObject *__pyx_n_s_Y;
static PyObject *__pyx_kp_s__2;
static PyObject *__pyx_n_s_a;
static PyObject *__pyx_n_s_a1;
static PyObject *__pyx_n_s_a2;
static PyObject *__pyx_n_s_alpha;
static PyObject *__pyx_n_s_append;
static PyObject *__pyx_n_s_atan;
static PyObject *__pyx_n_s_author;
static PyObject *__pyx_kp_s_ave_of_all_exp_of_negative_rho_o;
static PyObject *__pyx_n_s_ave_of_all_exp_of_negative_rho_o_2;
static PyObject *__pyx_kp_s_ave_of_all_short_exp_of_negative;
static PyObject *__pyx_kp_s_ave_of_all_short_exp_of_negative_2;
static PyObject *__pyx_n_s_ave_of_all_short_exp_of_negative_3;
static PyObject *__pyx_n_s_b;
static PyObject *__pyx_n_s_b1;
static PyObject *__pyx_n_s_b2;
static PyObject *__pyx_n_s_c;
static PyObject *__pyx_n_s_c1;
static PyObject *__pyx_n_s_c2;
static PyObject *__pyx_n_s_check_T_generate_a_Schottky;
static PyObject *__pyx_n_s_classification_point;
static PyObject *__pyx_n_s_cline_in_traceback;
static PyObject *__pyx_n_s_cos;
static PyObject *__pyx_kp_s_counter;
static PyObject *__pyx_n_s_counter_2;
static PyObject *__pyx_n_s_d;
static PyObject *__pyx_n_s_d1;
static PyObject *__pyx_n_s_d2;
static PyObject *__pyx_n_s_det;
static PyObject *__pyx_n_s_discriminant;
static PyObject *__pyx_n_s_email;
static PyObject *__pyx_n_s_end;
static PyObject *__pyx_n_s_example1;
static PyObject *__pyx_kp_s_example1_py;
static PyObject *__pyx_n_s_examples_of_10000;
static PyObject *__pyx_n_s_exp;
static PyObject *__pyx_n_s_file;
static PyObject *__pyx_n_s_flag;
static PyObject *__pyx_n_s_i;
static PyObject *__pyx_n_s_import;
static PyObject *__pyx_n_s_increment;
static PyObject *__pyx_n_s_initial;
static PyObject *__pyx_n_s_inverse_det;
static PyObject *__pyx_n_s_j;
static PyObject *__pyx_n_s_k;
static PyObject *__pyx_n_s_l;
static PyObject *__pyx_n_s_l1;
static PyObject *__pyx_n_s_l2;
static PyObject *__pyx_n_s_log;
static PyObject *__pyx_n_s_m;
static PyObject *__pyx_n_s_m1;
static PyObject *__pyx_n_s_m2;
static PyObject *__pyx_n_s_main;
static PyObject *__pyx_n_s_math;
static PyObject *__pyx_n_s_mean;
static PyObject *__pyx_n_s_n;
static PyObject *__pyx_n_s_name;
static PyObject *__pyx_n_s_node;
static PyObject *__pyx_n_s_nodes_in_DT;
static PyObject *__pyx_n_s_null;
static PyObject *__pyx_n_s_numb;
static PyObject *__pyx_n_s_numb1;
static PyObject *__pyx_n_s_numb2;
static PyObject *__pyx_n_s_nx;
static PyObject *__pyx_n_s_ny;
static PyObject *__pyx_kp_s_occurence;
static PyObject *__pyx_n_s_occurence_2;
static PyObject *__pyx_n_s_operator_R;
static PyObject *__pyx_n_s_operator_T;
static PyObject *__pyx_n_s_out;
static PyObject *__pyx_n_s_pi;
static PyObject *__pyx_n_s_print;
static PyObject *__pyx_n_s_r;
static PyObject *__pyx_n_s_range;
static PyObject *__pyx_n_s_real_matrix_addition;
static PyObject *__pyx_n_s_real_matrix_inverse;
static PyObject *__pyx_n_s_real_matrix_multiplication;
static PyObject *__pyx_n_s_rho;
static PyObject *__pyx_n_s_sin;
static PyObject *__pyx_n_s_sqrt;
static PyObject *__pyx_n_s_statistics;
static PyObject *__pyx_n_s_sum1;
static PyObject *__pyx_n_s_sum2;
static PyObject *__pyx_n_s_t;
static PyObject *__pyx_n_s_test;
static PyObject *__pyx_n_s_test_2;
static PyObject *__pyx_n_s_theta;
static PyObject *__pyx_n_s_tmp;
static PyObject *__pyx_n_s_tmp1;
static PyObject *__pyx_n_s_tmp2;
static PyObject *__pyx_n_s_tmp3;
static PyObject *__pyx_n_s_tot;
static PyObject *__pyx_kp_s_useful_example;
static PyObject *__pyx_n_s_useful_example_2;
static PyObject *__pyx_n_s_version;
static PyObject *__pyx_kp_s_wchuang2_mail_sfsu_edu;
static PyObject *__pyx_n_s_x;
static PyObject *__pyx_n_s_y;
static PyObject *__pyx_n_s_z;
static PyObject *__pyx_pf_8example1_Cartesian_complex_mul(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb1, PyObject *__pyx_v_numb2);
static PyObject *__pyx_pf_8example1_2Cartesian_complex_scalar_mul(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_alpha, PyObject *__pyx_v_numb1);
static PyObject *__pyx_pf_8example1_4Cartesian_complex_add(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb1, PyObject *__pyx_v_numb2);
static PyObject *__pyx_pf_8example1_6Cartesian_complex_divide(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb1, PyObject *__pyx_v_numb2);
static PyObject *__pyx_pf_8example1_8Cartesian_complex_modulus(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb);
static PyObject *__pyx_pf_8example1_10Cartesian_complex_complex_conjugate(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb);
static PyObject *__pyx_pf_8example1_12Cartesian_complex_complex_to_polar(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb);
static PyObject *__pyx_pf_8example1_14Polar_complex_complex_to_Cartesian(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb);
static PyObject *__pyx_pf_8example1_16Polar_complex_conjugate(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb);
static PyObject *__pyx_pf_8example1_18Polar_complex_mul(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb1, PyObject *__pyx_v_numb2);
static PyObject *__pyx_pf_8example1_20Polar_complex_divide(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb1, PyObject *__pyx_v_numb2);
static PyObject *__pyx_pf_8example1_22Polar_complex_add(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb1, PyObject *__pyx_v_numb2);
static PyObject *__pyx_pf_8example1_24real_matrix_addition(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_m1, PyObject *__pyx_v_m2);
static PyObject *__pyx_pf_8example1_26Cartesian_complex_matrix_addition(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_m1, PyObject *__pyx_v_m2);
static PyObject *__pyx_pf_8example1_28real_matrix_multiplication(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_m1, PyObject *__pyx_v_m2);
static PyObject *__pyx_pf_8example1_30Cartesian_complex_matrix_multiplication(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_m1, PyObject *__pyx_v_m2);
static PyObject *__pyx_pf_8example1_32real_matrix_inverse(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_m1);
static PyObject *__pyx_pf_8example1_34Cartesian_complex_matrix_inverse(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_m1);
static PyObject *__pyx_pf_8example1_36Cartesian_radial_hyperbolic_distance(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_z);
static PyObject *__pyx_pf_8example1_38operator_T(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_Lambda);
static PyObject *__pyx_pf_8example1_40operator_R(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_theta);
static PyObject *__pyx_pf_8example1_42classification_point(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_Lambda);
static PyObject *__pyx_pf_8example1_44check_T_generate_a_Schottky(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_Lambda, PyObject *__pyx_v_m);
static PyObject *__pyx_pf_8example1_46Tz(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_T, PyObject *__pyx_v_z);
static PyObject *__pyx_pf_8example1_48Gamma0(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_Lambda, PyObject *__pyx_v_m, PyObject *__pyx_v_N);
static PyObject *__pyx_pf_8example1_50Hyperbolic_Distance_Gamma0(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_Lambda, PyObject *__pyx_v_m, PyObject *__pyx_v_N);
static PyObject *__pyx_pf_8example1_52Exp_negative_Hyperbolic_Distance_Gamma0(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_Lambda, PyObject *__pyx_v_m, PyObject *__pyx_v_N);
static PyObject *__pyx_pf_8example1_54Improved_Exp_negative_Hyperbolic_Distance_Gamma0(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_Lambda, PyObject *__pyx_v_m, PyObject *__pyx_v_N, PyObject *__pyx_v_L);
static PyObject *__pyx_pf_8example1_56examples_of_10000(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_initial, PyObject *__pyx_v_increment);
static PyObject *__pyx_float_0_3;
static PyObject *__pyx_float_0_5;
static PyObject *__pyx_float_0_000001;
static PyObject *__pyx_float_neg_0_5;
static PyObject *__pyx_int_0;
static PyObject *__pyx_int_1;
static PyObject *__pyx_int_2;
static PyObject *__pyx_int_4;
static PyObject *__pyx_int_10000;
static PyObject *__pyx_int_neg_1;
static PyObject *__pyx_tuple__3;
static PyObject *__pyx_tuple__5;
static PyObject *__pyx_tuple__7;
static PyObject *__pyx_tuple__9;
static PyObject *__pyx_tuple__11;
static PyObject *__pyx_tuple__13;
static PyObject *__pyx_tuple__15;
static PyObject *__pyx_tuple__17;
static PyObject *__pyx_tuple__19;
static PyObject *__pyx_tuple__21;
static PyObject *__pyx_tuple__23;
static PyObject *__pyx_tuple__25;
static PyObject *__pyx_tuple__27;
static PyObject *__pyx_tuple__29;
static PyObject *__pyx_tuple__31;
static PyObject *__pyx_tuple__33;
static PyObject *__pyx_tuple__35;
static PyObject *__pyx_tuple__37;
static PyObject *__pyx_tuple__39;
static PyObject *__pyx_tuple__41;
static PyObject *__pyx_tuple__43;
static PyObject *__pyx_tuple__45;
static PyObject *__pyx_tuple__47;
static PyObject *__pyx_tuple__49;
static PyObject *__pyx_tuple__51;
static PyObject *__pyx_tuple__53;
static PyObject *__pyx_tuple__55;
static PyObject *__pyx_tuple__57;
static PyObject *__pyx_tuple__59;
static PyObject *__pyx_codeobj__4;
static PyObject *__pyx_codeobj__6;
static PyObject *__pyx_codeobj__8;
static PyObject *__pyx_codeobj__10;
static PyObject *__pyx_codeobj__12;
static PyObject *__pyx_codeobj__14;
static PyObject *__pyx_codeobj__16;
static PyObject *__pyx_codeobj__18;
static PyObject *__pyx_codeobj__20;
static PyObject *__pyx_codeobj__22;
static PyObject *__pyx_codeobj__24;
static PyObject *__pyx_codeobj__26;
static PyObject *__pyx_codeobj__28;
static PyObject *__pyx_codeobj__30;
static PyObject *__pyx_codeobj__32;
static PyObject *__pyx_codeobj__34;
static PyObject *__pyx_codeobj__36;
static PyObject *__pyx_codeobj__38;
static PyObject *__pyx_codeobj__40;
static PyObject *__pyx_codeobj__42;
static PyObject *__pyx_codeobj__44;
static PyObject *__pyx_codeobj__46;
static PyObject *__pyx_codeobj__48;
static PyObject *__pyx_codeobj__50;
static PyObject *__pyx_codeobj__52;
static PyObject *__pyx_codeobj__54;
static PyObject *__pyx_codeobj__56;
static PyObject *__pyx_codeobj__58;
static PyObject *__pyx_codeobj__60;
# 1678 "example1.c"
static PyObject *__pyx_pw_8example1_1Cartesian_complex_mul(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_1Cartesian_complex_mul = {"Cartesian_complex_mul", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_1Cartesian_complex_mul, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_1Cartesian_complex_mul(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_numb1 = 0;
  PyObject *__pyx_v_numb2 = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Cartesian_complex_mul (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_numb1,&__pyx_n_s_numb2,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_numb1)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_numb2)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Cartesian_complex_mul", 1, 2, 2, 1); __PYX_ERR(0, 8, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "Cartesian_complex_mul") < 0)) __PYX_ERR(0, 8, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_numb1 = values[0];
    __pyx_v_numb2 = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("Cartesian_complex_mul", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 8, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.Cartesian_complex_mul", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_Cartesian_complex_mul(__pyx_self, __pyx_v_numb1, __pyx_v_numb2);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_Cartesian_complex_mul(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb1, PyObject *__pyx_v_numb2) {
  PyObject *__pyx_v_x = NULL;
  PyObject *__pyx_v_y = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Cartesian_complex_mul", 0);
# 1763 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyNumber_Multiply(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = PyNumber_Multiply(__pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Subtract(__pyx_t_3, __pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_x = __pyx_t_1;
  __pyx_t_1 = 0;
# 1793 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_numb2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = PyNumber_Multiply(__pyx_t_1, __pyx_t_4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_numb1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Multiply(__pyx_t_4, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_y = __pyx_t_1;
  __pyx_t_1 = 0;
# 1823 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_x);
  __Pyx_GIVEREF(__pyx_v_x);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_x);
  __Pyx_INCREF(__pyx_v_y);
  __Pyx_GIVEREF(__pyx_v_y);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_y);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;
# 1845 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("example1.Cartesian_complex_mul", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_x);
  __Pyx_XDECREF(__pyx_v_y);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 1869 "example1.c"
static PyObject *__pyx_pw_8example1_3Cartesian_complex_scalar_mul(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_3Cartesian_complex_scalar_mul = {"Cartesian_complex_scalar_mul", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_3Cartesian_complex_scalar_mul, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_3Cartesian_complex_scalar_mul(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_alpha = 0;
  PyObject *__pyx_v_numb1 = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Cartesian_complex_scalar_mul (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_alpha,&__pyx_n_s_numb1,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_alpha)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_numb1)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Cartesian_complex_scalar_mul", 1, 2, 2, 1); __PYX_ERR(0, 14, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "Cartesian_complex_scalar_mul") < 0)) __PYX_ERR(0, 14, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_alpha = values[0];
    __pyx_v_numb1 = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("Cartesian_complex_scalar_mul", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 14, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.Cartesian_complex_scalar_mul", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_2Cartesian_complex_scalar_mul(__pyx_self, __pyx_v_alpha, __pyx_v_numb1);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_2Cartesian_complex_scalar_mul(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_alpha, PyObject *__pyx_v_numb1) {
  PyObject *__pyx_v_x = NULL;
  PyObject *__pyx_v_y = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Cartesian_complex_scalar_mul", 0);
# 1952 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Multiply(__pyx_t_1, __pyx_v_alpha); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_x = __pyx_t_2;
  __pyx_t_2 = 0;
# 1967 "example1.c"
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = PyNumber_Multiply(__pyx_t_2, __pyx_v_alpha); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_y = __pyx_t_1;
  __pyx_t_1 = 0;
# 1982 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 18, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_x);
  __Pyx_GIVEREF(__pyx_v_x);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_x);
  __Pyx_INCREF(__pyx_v_y);
  __Pyx_GIVEREF(__pyx_v_y);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_y);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;
# 2004 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("example1.Cartesian_complex_scalar_mul", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_x);
  __Pyx_XDECREF(__pyx_v_y);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 2026 "example1.c"
static PyObject *__pyx_pw_8example1_5Cartesian_complex_add(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_5Cartesian_complex_add = {"Cartesian_complex_add", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_5Cartesian_complex_add, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_5Cartesian_complex_add(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_numb1 = 0;
  PyObject *__pyx_v_numb2 = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Cartesian_complex_add (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_numb1,&__pyx_n_s_numb2,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_numb1)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_numb2)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Cartesian_complex_add", 1, 2, 2, 1); __PYX_ERR(0, 20, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "Cartesian_complex_add") < 0)) __PYX_ERR(0, 20, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_numb1 = values[0];
    __pyx_v_numb2 = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("Cartesian_complex_add", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 20, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.Cartesian_complex_add", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_4Cartesian_complex_add(__pyx_self, __pyx_v_numb1, __pyx_v_numb2);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_4Cartesian_complex_add(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb1, PyObject *__pyx_v_numb2) {
  PyObject *__pyx_v_x = NULL;
  PyObject *__pyx_v_y = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Cartesian_complex_add", 0);
# 2110 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 22, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 22, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyNumber_Add(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 22, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_x = __pyx_t_3;
  __pyx_t_3 = 0;
# 2128 "example1.c"
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_numb1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_y = __pyx_t_1;
  __pyx_t_1 = 0;
# 2146 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 24, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_x);
  __Pyx_GIVEREF(__pyx_v_x);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_x);
  __Pyx_INCREF(__pyx_v_y);
  __Pyx_GIVEREF(__pyx_v_y);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_y);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;
# 2168 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("example1.Cartesian_complex_add", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_x);
  __Pyx_XDECREF(__pyx_v_y);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 2191 "example1.c"
static PyObject *__pyx_pw_8example1_7Cartesian_complex_divide(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_7Cartesian_complex_divide = {"Cartesian_complex_divide", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_7Cartesian_complex_divide, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_7Cartesian_complex_divide(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_numb1 = 0;
  PyObject *__pyx_v_numb2 = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Cartesian_complex_divide (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_numb1,&__pyx_n_s_numb2,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_numb1)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_numb2)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Cartesian_complex_divide", 1, 2, 2, 1); __PYX_ERR(0, 26, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "Cartesian_complex_divide") < 0)) __PYX_ERR(0, 26, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_numb1 = values[0];
    __pyx_v_numb2 = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("Cartesian_complex_divide", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 26, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.Cartesian_complex_divide", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_6Cartesian_complex_divide(__pyx_self, __pyx_v_numb1, __pyx_v_numb2);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_6Cartesian_complex_divide(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb1, PyObject *__pyx_v_numb2) {
  PyObject *__pyx_v_d = NULL;
  PyObject *__pyx_v_nx = NULL;
  PyObject *__pyx_v_ny = NULL;
  double __pyx_v_X;
  double __pyx_v_Y;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  double __pyx_t_5;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Cartesian_complex_divide", 0);
# 2280 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 28, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 28, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyNumber_Multiply(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 28, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 28, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 28, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = PyNumber_Multiply(__pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 28, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 28, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_d = __pyx_t_1;
  __pyx_t_1 = 0;
# 2310 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_numb2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = PyNumber_Multiply(__pyx_t_1, __pyx_t_4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_numb1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Multiply(__pyx_t_4, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_nx = __pyx_t_1;
  __pyx_t_1 = 0;
# 2340 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyNumber_Multiply(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = PyNumber_Multiply(__pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Subtract(__pyx_t_3, __pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_ny = __pyx_t_1;
  __pyx_t_1 = 0;
# 2370 "example1.c"
  __pyx_t_1 = __Pyx_PyNumber_Divide(__pyx_v_nx, __pyx_v_d); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 31, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_5 = __Pyx_PyObject_AsDouble(__pyx_t_1); if (unlikely(__pyx_t_5 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 31, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_X = __pyx_t_5;
# 2383 "example1.c"
  __pyx_t_1 = __Pyx_PyNumber_Divide(__pyx_v_ny, __pyx_v_d); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_5 = __Pyx_PyObject_AsDouble(__pyx_t_1); if (unlikely(__pyx_t_5 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_Y = __pyx_t_5;
# 2396 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyFloat_FromDouble(__pyx_v_X); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 33, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = PyFloat_FromDouble(__pyx_v_Y); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 33, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = PyList_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 33, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_4);
  PyList_SET_ITEM(__pyx_t_3, 1, __pyx_t_4);
  __pyx_t_1 = 0;
  __pyx_t_4 = 0;
  __pyx_r = __pyx_t_3;
  __pyx_t_3 = 0;
  goto __pyx_L0;
# 2422 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("example1.Cartesian_complex_divide", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_d);
  __Pyx_XDECREF(__pyx_v_nx);
  __Pyx_XDECREF(__pyx_v_ny);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 2447 "example1.c"
static PyObject *__pyx_pw_8example1_9Cartesian_complex_modulus(PyObject *__pyx_self, PyObject *__pyx_v_numb);
static PyMethodDef __pyx_mdef_8example1_9Cartesian_complex_modulus = {"Cartesian_complex_modulus", (PyCFunction)__pyx_pw_8example1_9Cartesian_complex_modulus, METH_O, 0};
static PyObject *__pyx_pw_8example1_9Cartesian_complex_modulus(PyObject *__pyx_self, PyObject *__pyx_v_numb) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Cartesian_complex_modulus (wrapper)", 0);
  __pyx_r = __pyx_pf_8example1_8Cartesian_complex_modulus(__pyx_self, ((PyObject *)__pyx_v_numb));


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_8Cartesian_complex_modulus(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Cartesian_complex_modulus", 0);
# 2481 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_math); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_sqrt); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_numb, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = PyNumber_Multiply(__pyx_t_2, __pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_numb, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_6 = PyNumber_Multiply(__pyx_t_4, __pyx_t_2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyNumber_Add(__pyx_t_5, __pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_6, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;
# 2536 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("example1.Cartesian_complex_modulus", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 2560 "example1.c"
static PyObject *__pyx_pw_8example1_11Cartesian_complex_complex_conjugate(PyObject *__pyx_self, PyObject *__pyx_v_numb);
static PyMethodDef __pyx_mdef_8example1_11Cartesian_complex_complex_conjugate = {"Cartesian_complex_complex_conjugate", (PyCFunction)__pyx_pw_8example1_11Cartesian_complex_complex_conjugate, METH_O, 0};
static PyObject *__pyx_pw_8example1_11Cartesian_complex_complex_conjugate(PyObject *__pyx_self, PyObject *__pyx_v_numb) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Cartesian_complex_complex_conjugate (wrapper)", 0);
  __pyx_r = __pyx_pf_8example1_10Cartesian_complex_complex_conjugate(__pyx_self, ((PyObject *)__pyx_v_numb));


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_10Cartesian_complex_complex_conjugate(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Cartesian_complex_complex_conjugate", 0);
# 2591 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyNumber_Negative(__pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyList_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_t_3);
  __pyx_t_1 = 0;
  __pyx_t_3 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;
# 2620 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("example1.Cartesian_complex_complex_conjugate", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 2641 "example1.c"
static PyObject *__pyx_pw_8example1_13Cartesian_complex_complex_to_polar(PyObject *__pyx_self, PyObject *__pyx_v_numb);
static PyMethodDef __pyx_mdef_8example1_13Cartesian_complex_complex_to_polar = {"Cartesian_complex_complex_to_polar", (PyCFunction)__pyx_pw_8example1_13Cartesian_complex_complex_to_polar, METH_O, 0};
static PyObject *__pyx_pw_8example1_13Cartesian_complex_complex_to_polar(PyObject *__pyx_self, PyObject *__pyx_v_numb) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Cartesian_complex_complex_to_polar (wrapper)", 0);
  __pyx_r = __pyx_pf_8example1_12Cartesian_complex_complex_to_polar(__pyx_self, ((PyObject *)__pyx_v_numb));


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_12Cartesian_complex_complex_to_polar(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb) {
  PyObject *__pyx_v_r = NULL;
  PyObject *__pyx_v_t = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Cartesian_complex_complex_to_polar", 0);
# 2677 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Cartesian_complex_modulus); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_v_numb) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_numb);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_r = __pyx_t_1;
  __pyx_t_1 = 0;
# 2704 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyObject_RichCompare(__pyx_t_1, __pyx_int_0, Py_GT); __Pyx_XGOTREF(__pyx_t_2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__pyx_t_4) {
# 2719 "example1.c"
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_math); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 44, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_atan); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 44, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 44, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_5 = __Pyx_GetItemInt(__pyx_v_numb, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 44, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_6 = __Pyx_PyNumber_Divide(__pyx_t_1, __pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 44, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyNumber_Float(__pyx_t_6); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 44, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __pyx_t_6 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_6)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_6);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
      }
    }
    __pyx_t_2 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_6, __pyx_t_5) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_5);
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 44, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_v_t = __pyx_t_2;
    __pyx_t_2 = 0;
# 2761 "example1.c"
    goto __pyx_L3;
  }
# 2771 "example1.c"
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyObject_RichCompare(__pyx_t_2, __pyx_int_0, Py_LT); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__pyx_t_4) {
# 2786 "example1.c"
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_math); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 46, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_atan); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 46, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 46, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_6 = __Pyx_GetItemInt(__pyx_v_numb, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 46, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_1 = __Pyx_PyNumber_Divide(__pyx_t_2, __pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 46, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __pyx_t_6 = __Pyx_PyNumber_Float(__pyx_t_1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 46, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_1)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_1);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_1, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_6);
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 46, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_math); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 46, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_pi); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 46, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = PyNumber_Add(__pyx_t_3, __pyx_t_6); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 46, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __pyx_v_t = __pyx_t_5;
    __pyx_t_5 = 0;
# 2837 "example1.c"
    goto __pyx_L3;
  }
# 2847 "example1.c"
           {
    __pyx_t_5 = __Pyx_GetItemInt(__pyx_v_numb, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 48, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_6 = PyObject_RichCompare(__pyx_t_5, __pyx_int_0, Py_GT); __Pyx_XGOTREF(__pyx_t_6); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 48, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_6); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 48, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (__pyx_t_4) {
# 2863 "example1.c"
      __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_math); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 49, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_pi); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 49, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __pyx_t_6 = __Pyx_PyNumber_Divide(__pyx_t_5, __pyx_int_2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 49, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_5 = __Pyx_PyNumber_Float(__pyx_t_6); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 49, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __pyx_v_t = __pyx_t_5;
      __pyx_t_5 = 0;
# 2884 "example1.c"
      goto __pyx_L4;
    }
# 2894 "example1.c"
    __pyx_t_5 = __Pyx_GetItemInt(__pyx_v_numb, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 50, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_6 = PyObject_RichCompare(__pyx_t_5, __pyx_int_0, Py_LT); __Pyx_XGOTREF(__pyx_t_6); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 50, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_6); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 50, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (__pyx_t_4) {
# 2909 "example1.c"
      __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_math); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 51, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_pi); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 51, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __pyx_t_6 = PyNumber_Negative(__pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 51, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_5 = __Pyx_PyNumber_Divide(__pyx_t_6, __pyx_int_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 51, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __pyx_t_6 = __Pyx_PyNumber_Float(__pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 51, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_v_t = __pyx_t_6;
      __pyx_t_6 = 0;
# 2933 "example1.c"
      goto __pyx_L4;
    }
# 2943 "example1.c"
             {
      __Pyx_INCREF(__pyx_n_s_null);
      __pyx_v_t = __pyx_n_s_null;
    }
    __pyx_L4:;
  }
  __pyx_L3:;
# 2958 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_6 = PyList_New(2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_INCREF(__pyx_v_r);
  __Pyx_GIVEREF(__pyx_v_r);
  PyList_SET_ITEM(__pyx_t_6, 0, __pyx_v_r);
  __Pyx_INCREF(__pyx_v_t);
  __Pyx_GIVEREF(__pyx_v_t);
  PyList_SET_ITEM(__pyx_t_6, 1, __pyx_v_t);
  __pyx_r = __pyx_t_6;
  __pyx_t_6 = 0;
  goto __pyx_L0;
# 2980 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("example1.Cartesian_complex_complex_to_polar", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_r);
  __Pyx_XDECREF(__pyx_v_t);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 3005 "example1.c"
static PyObject *__pyx_pw_8example1_15Polar_complex_complex_to_Cartesian(PyObject *__pyx_self, PyObject *__pyx_v_numb);
static PyMethodDef __pyx_mdef_8example1_15Polar_complex_complex_to_Cartesian = {"Polar_complex_complex_to_Cartesian", (PyCFunction)__pyx_pw_8example1_15Polar_complex_complex_to_Cartesian, METH_O, 0};
static PyObject *__pyx_pw_8example1_15Polar_complex_complex_to_Cartesian(PyObject *__pyx_self, PyObject *__pyx_v_numb) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Polar_complex_complex_to_Cartesian (wrapper)", 0);
  __pyx_r = __pyx_pf_8example1_14Polar_complex_complex_to_Cartesian(__pyx_self, ((PyObject *)__pyx_v_numb));


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_14Polar_complex_complex_to_Cartesian(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Polar_complex_complex_to_Cartesian", 0);
# 3039 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_math); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_cos); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_numb, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_2 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_5, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyNumber_Multiply(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_math); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_sin); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_numb, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_5);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_5, function);
    }
  }
  __pyx_t_1 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_6, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyNumber_Multiply(__pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_4);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_t_5);
  __pyx_t_4 = 0;
  __pyx_t_5 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;
# 3119 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("example1.Polar_complex_complex_to_Cartesian", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 3143 "example1.c"
static PyObject *__pyx_pw_8example1_17Polar_complex_conjugate(PyObject *__pyx_self, PyObject *__pyx_v_numb);
static PyMethodDef __pyx_mdef_8example1_17Polar_complex_conjugate = {"Polar_complex_conjugate", (PyCFunction)__pyx_pw_8example1_17Polar_complex_conjugate, METH_O, 0};
static PyObject *__pyx_pw_8example1_17Polar_complex_conjugate(PyObject *__pyx_self, PyObject *__pyx_v_numb) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Polar_complex_conjugate (wrapper)", 0);
  __pyx_r = __pyx_pf_8example1_16Polar_complex_conjugate(__pyx_self, ((PyObject *)__pyx_v_numb));


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_16Polar_complex_conjugate(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Polar_complex_conjugate", 0);
# 3174 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyNumber_Negative(__pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyList_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_t_3);
  __pyx_t_1 = 0;
  __pyx_t_3 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;
# 3203 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("example1.Polar_complex_conjugate", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 3224 "example1.c"
static PyObject *__pyx_pw_8example1_19Polar_complex_mul(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_19Polar_complex_mul = {"Polar_complex_mul", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_19Polar_complex_mul, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_19Polar_complex_mul(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_numb1 = 0;
  PyObject *__pyx_v_numb2 = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Polar_complex_mul (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_numb1,&__pyx_n_s_numb2,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_numb1)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_numb2)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Polar_complex_mul", 1, 2, 2, 1); __PYX_ERR(0, 62, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "Polar_complex_mul") < 0)) __PYX_ERR(0, 62, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_numb1 = values[0];
    __pyx_v_numb2 = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("Polar_complex_mul", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 62, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.Polar_complex_mul", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_18Polar_complex_mul(__pyx_self, __pyx_v_numb1, __pyx_v_numb2);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_18Polar_complex_mul(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb1, PyObject *__pyx_v_numb2) {
  PyObject *__pyx_v_r = NULL;
  PyObject *__pyx_v_t = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Polar_complex_mul", 0);
# 3308 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyNumber_Multiply(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_r = __pyx_t_3;
  __pyx_t_3 = 0;
# 3326 "example1.c"
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_numb1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_t = __pyx_t_1;
  __pyx_t_1 = 0;
# 3344 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 66, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_r);
  __Pyx_GIVEREF(__pyx_v_r);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_r);
  __Pyx_INCREF(__pyx_v_t);
  __Pyx_GIVEREF(__pyx_v_t);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_t);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;
# 3366 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("example1.Polar_complex_mul", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_r);
  __Pyx_XDECREF(__pyx_v_t);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 3389 "example1.c"
static PyObject *__pyx_pw_8example1_21Polar_complex_divide(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_21Polar_complex_divide = {"Polar_complex_divide", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_21Polar_complex_divide, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_21Polar_complex_divide(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_numb1 = 0;
  PyObject *__pyx_v_numb2 = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Polar_complex_divide (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_numb1,&__pyx_n_s_numb2,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_numb1)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_numb2)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Polar_complex_divide", 1, 2, 2, 1); __PYX_ERR(0, 68, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "Polar_complex_divide") < 0)) __PYX_ERR(0, 68, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_numb1 = values[0];
    __pyx_v_numb2 = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("Polar_complex_divide", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 68, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.Polar_complex_divide", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_20Polar_complex_divide(__pyx_self, __pyx_v_numb1, __pyx_v_numb2);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_20Polar_complex_divide(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb1, PyObject *__pyx_v_numb2) {
  double __pyx_v_r;
  PyObject *__pyx_v_t = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  double __pyx_t_4;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Polar_complex_divide", 0);
# 3474 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_numb1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyNumber_Divide(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_4 = __Pyx_PyObject_AsDouble(__pyx_t_3); if (unlikely(__pyx_t_4 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_r = __pyx_t_4;
# 3493 "example1.c"
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_numb1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 71, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_numb2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 71, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = PyNumber_Subtract(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 71, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_t = __pyx_t_1;
  __pyx_t_1 = 0;
# 3511 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyFloat_FromDouble(__pyx_v_r); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 72, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyList_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 72, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __Pyx_INCREF(__pyx_v_t);
  __Pyx_GIVEREF(__pyx_v_t);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_v_t);
  __pyx_t_1 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;
# 3535 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("example1.Polar_complex_divide", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_t);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 3557 "example1.c"
static PyObject *__pyx_pw_8example1_23Polar_complex_add(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_23Polar_complex_add = {"Polar_complex_add", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_23Polar_complex_add, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_23Polar_complex_add(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_numb1 = 0;
  PyObject *__pyx_v_numb2 = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Polar_complex_add (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_numb1,&__pyx_n_s_numb2,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_numb1)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_numb2)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Polar_complex_add", 1, 2, 2, 1); __PYX_ERR(0, 74, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "Polar_complex_add") < 0)) __PYX_ERR(0, 74, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_numb1 = values[0];
    __pyx_v_numb2 = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("Polar_complex_add", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 74, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.Polar_complex_add", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_22Polar_complex_add(__pyx_self, __pyx_v_numb1, __pyx_v_numb2);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_22Polar_complex_add(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_numb1, PyObject *__pyx_v_numb2) {
  PyObject *__pyx_v_N1 = NULL;
  PyObject *__pyx_v_N2 = NULL;
  PyObject *__pyx_v_tot = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Polar_complex_add", 0);
# 3644 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Polar_complex_complex_to_Cartesi); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 75, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_v_numb1) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_numb1);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 75, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_N1 = __pyx_t_1;
  __pyx_t_1 = 0;
# 3671 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Polar_complex_complex_to_Cartesi); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_v_numb2) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_numb2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_N2 = __pyx_t_1;
  __pyx_t_1 = 0;
# 3698 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Cartesian_complex_add); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 77, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  __pyx_t_4 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_4 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_N1, __pyx_v_N2};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 77, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_N1, __pyx_v_N2};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 77, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  {
    __pyx_t_5 = PyTuple_New(2+__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 77, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_INCREF(__pyx_v_N1);
    __Pyx_GIVEREF(__pyx_v_N1);
    PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_4, __pyx_v_N1);
    __Pyx_INCREF(__pyx_v_N2);
    __Pyx_GIVEREF(__pyx_v_N2);
    PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_4, __pyx_v_N2);
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 77, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_tot = __pyx_t_1;
  __pyx_t_1 = 0;
# 3755 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Cartesian_complex_complex_to_pol); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 78, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_5, __pyx_v_tot) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_tot);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 78, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;
# 3786 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_AddTraceback("example1.Polar_complex_add", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_N1);
  __Pyx_XDECREF(__pyx_v_N2);
  __Pyx_XDECREF(__pyx_v_tot);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 3811 "example1.c"
static PyObject *__pyx_pw_8example1_25real_matrix_addition(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_25real_matrix_addition = {"real_matrix_addition", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_25real_matrix_addition, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_25real_matrix_addition(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_m1 = 0;
  PyObject *__pyx_v_m2 = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("real_matrix_addition (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_m1,&__pyx_n_s_m2,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_m1)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_m2)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("real_matrix_addition", 1, 2, 2, 1); __PYX_ERR(0, 80, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "real_matrix_addition") < 0)) __PYX_ERR(0, 80, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_m1 = values[0];
    __pyx_v_m2 = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("real_matrix_addition", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 80, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.real_matrix_addition", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_24real_matrix_addition(__pyx_self, __pyx_v_m1, __pyx_v_m2);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_24real_matrix_addition(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_m1, PyObject *__pyx_v_m2) {
  PyObject *__pyx_v_a = NULL;
  PyObject *__pyx_v_b = NULL;
  PyObject *__pyx_v_c = NULL;
  PyObject *__pyx_v_d = NULL;
  PyObject *__pyx_v_l1 = NULL;
  PyObject *__pyx_v_l2 = NULL;
  PyObject *__pyx_v_l = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("real_matrix_addition", 0);
# 3901 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Add(__pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_a = __pyx_t_1;
  __pyx_t_1 = 0;
# 3925 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_b = __pyx_t_1;
  __pyx_t_1 = 0;
# 3949 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Add(__pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_c = __pyx_t_1;
  __pyx_t_1 = 0;
# 3973 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_d = __pyx_t_1;
  __pyx_t_1 = 0;
# 3997 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 86, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_a);
  __Pyx_GIVEREF(__pyx_v_a);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_a);
  __Pyx_INCREF(__pyx_v_b);
  __Pyx_GIVEREF(__pyx_v_b);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_b);
  __pyx_v_l1 = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 4015 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 87, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_c);
  __Pyx_GIVEREF(__pyx_v_c);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_c);
  __Pyx_INCREF(__pyx_v_d);
  __Pyx_GIVEREF(__pyx_v_d);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_d);
  __pyx_v_l2 = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 4033 "example1.c"
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 88, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_l = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 4045 "example1.c"
  __pyx_t_4 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l1); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(0, 89, __pyx_L1_error)
# 4054 "example1.c"
  __pyx_t_4 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l2); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(0, 90, __pyx_L1_error)
# 4063 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_l);
  __pyx_r = __pyx_v_l;
  goto __pyx_L0;
# 4077 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("example1.real_matrix_addition", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_a);
  __Pyx_XDECREF(__pyx_v_b);
  __Pyx_XDECREF(__pyx_v_c);
  __Pyx_XDECREF(__pyx_v_d);
  __Pyx_XDECREF(__pyx_v_l1);
  __Pyx_XDECREF(__pyx_v_l2);
  __Pyx_XDECREF(__pyx_v_l);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 4105 "example1.c"
static PyObject *__pyx_pw_8example1_27Cartesian_complex_matrix_addition(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_27Cartesian_complex_matrix_addition = {"Cartesian_complex_matrix_addition", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_27Cartesian_complex_matrix_addition, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_27Cartesian_complex_matrix_addition(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_m1 = 0;
  PyObject *__pyx_v_m2 = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Cartesian_complex_matrix_addition (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_m1,&__pyx_n_s_m2,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_m1)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_m2)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Cartesian_complex_matrix_addition", 1, 2, 2, 1); __PYX_ERR(0, 93, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "Cartesian_complex_matrix_addition") < 0)) __PYX_ERR(0, 93, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_m1 = values[0];
    __pyx_v_m2 = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("Cartesian_complex_matrix_addition", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 93, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.Cartesian_complex_matrix_addition", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_26Cartesian_complex_matrix_addition(__pyx_self, __pyx_v_m1, __pyx_v_m2);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_26Cartesian_complex_matrix_addition(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_m1, PyObject *__pyx_v_m2) {
  PyObject *__pyx_v_a1 = NULL;
  PyObject *__pyx_v_a2 = NULL;
  PyObject *__pyx_v_b1 = NULL;
  PyObject *__pyx_v_b2 = NULL;
  PyObject *__pyx_v_c1 = NULL;
  PyObject *__pyx_v_c2 = NULL;
  PyObject *__pyx_v_d1 = NULL;
  PyObject *__pyx_v_d2 = NULL;
  PyObject *__pyx_v_a = NULL;
  PyObject *__pyx_v_b = NULL;
  PyObject *__pyx_v_c = NULL;
  PyObject *__pyx_v_d = NULL;
  PyObject *__pyx_v_l1 = NULL;
  PyObject *__pyx_v_l2 = NULL;
  PyObject *__pyx_v_l = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Cartesian_complex_matrix_addition", 0);
# 4203 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 96, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 96, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 96, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_m2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 96, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 96, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_3, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 96, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Add(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 96, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_a1 = __pyx_t_3;
  __pyx_t_3 = 0;
# 4233 "example1.c"
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_3, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_m2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_a2 = __pyx_t_1;
  __pyx_t_1 = 0;
# 4263 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 98, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 98, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 98, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_m2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 98, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 98, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_3, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 98, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Add(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 98, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_b1 = __pyx_t_3;
  __pyx_t_3 = 0;
# 4293 "example1.c"
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_3, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_m2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_b2 = __pyx_t_1;
  __pyx_t_1 = 0;
# 4323 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 100, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 100, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 100, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_m2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 100, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 100, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_3, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 100, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Add(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 100, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_c1 = __pyx_t_3;
  __pyx_t_3 = 0;
# 4353 "example1.c"
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 101, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_3, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 101, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 101, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_m2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 101, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 101, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 101, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 101, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_c2 = __pyx_t_1;
  __pyx_t_1 = 0;
# 4383 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_m2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_3, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Add(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_d1 = __pyx_t_3;
  __pyx_t_3 = 0;
# 4413 "example1.c"
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_3, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_m2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_d2 = __pyx_t_1;
  __pyx_t_1 = 0;
# 4443 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 104, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_a1);
  __Pyx_GIVEREF(__pyx_v_a1);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_a1);
  __Pyx_INCREF(__pyx_v_a2);
  __Pyx_GIVEREF(__pyx_v_a2);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_a2);
  __pyx_v_a = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 4461 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 105, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_b1);
  __Pyx_GIVEREF(__pyx_v_b1);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_b1);
  __Pyx_INCREF(__pyx_v_b2);
  __Pyx_GIVEREF(__pyx_v_b2);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_b2);
  __pyx_v_b = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 4479 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 106, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_c1);
  __Pyx_GIVEREF(__pyx_v_c1);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_c1);
  __Pyx_INCREF(__pyx_v_c2);
  __Pyx_GIVEREF(__pyx_v_c2);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_c2);
  __pyx_v_c = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 4497 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 107, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_d1);
  __Pyx_GIVEREF(__pyx_v_d1);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_d1);
  __Pyx_INCREF(__pyx_v_d2);
  __Pyx_GIVEREF(__pyx_v_d2);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_d2);
  __pyx_v_d = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 4515 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_a);
  __Pyx_GIVEREF(__pyx_v_a);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_a);
  __Pyx_INCREF(__pyx_v_b);
  __Pyx_GIVEREF(__pyx_v_b);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_b);
  __pyx_v_l1 = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 4533 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 109, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_c);
  __Pyx_GIVEREF(__pyx_v_c);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_c);
  __Pyx_INCREF(__pyx_v_d);
  __Pyx_GIVEREF(__pyx_v_d);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_d);
  __pyx_v_l2 = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 4551 "example1.c"
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 110, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_l = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 4563 "example1.c"
  __pyx_t_4 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l1); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(0, 111, __pyx_L1_error)
# 4572 "example1.c"
  __pyx_t_4 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l2); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(0, 112, __pyx_L1_error)
# 4581 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_l);
  __pyx_r = __pyx_v_l;
  goto __pyx_L0;
# 4595 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("example1.Cartesian_complex_matrix_addition", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_a1);
  __Pyx_XDECREF(__pyx_v_a2);
  __Pyx_XDECREF(__pyx_v_b1);
  __Pyx_XDECREF(__pyx_v_b2);
  __Pyx_XDECREF(__pyx_v_c1);
  __Pyx_XDECREF(__pyx_v_c2);
  __Pyx_XDECREF(__pyx_v_d1);
  __Pyx_XDECREF(__pyx_v_d2);
  __Pyx_XDECREF(__pyx_v_a);
  __Pyx_XDECREF(__pyx_v_b);
  __Pyx_XDECREF(__pyx_v_c);
  __Pyx_XDECREF(__pyx_v_d);
  __Pyx_XDECREF(__pyx_v_l1);
  __Pyx_XDECREF(__pyx_v_l2);
  __Pyx_XDECREF(__pyx_v_l);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 4631 "example1.c"
static PyObject *__pyx_pw_8example1_29real_matrix_multiplication(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_29real_matrix_multiplication = {"real_matrix_multiplication", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_29real_matrix_multiplication, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_29real_matrix_multiplication(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_m1 = 0;
  PyObject *__pyx_v_m2 = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("real_matrix_multiplication (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_m1,&__pyx_n_s_m2,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_m1)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_m2)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("real_matrix_multiplication", 1, 2, 2, 1); __PYX_ERR(0, 115, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "real_matrix_multiplication") < 0)) __PYX_ERR(0, 115, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_m1 = values[0];
    __pyx_v_m2 = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("real_matrix_multiplication", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 115, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.real_matrix_multiplication", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_28real_matrix_multiplication(__pyx_self, __pyx_v_m1, __pyx_v_m2);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_28real_matrix_multiplication(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_m1, PyObject *__pyx_v_m2) {
  PyObject *__pyx_v_a = NULL;
  PyObject *__pyx_v_b = NULL;
  PyObject *__pyx_v_c = NULL;
  PyObject *__pyx_v_d = NULL;
  PyObject *__pyx_v_l1 = NULL;
  PyObject *__pyx_v_l2 = NULL;
  PyObject *__pyx_v_l = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("real_matrix_multiplication", 0);
# 4722 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Multiply(__pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_3, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_t_3, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Multiply(__pyx_t_2, __pyx_t_4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyNumber_Add(__pyx_t_1, __pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_a = __pyx_t_4;
  __pyx_t_4 = 0;
# 4764 "example1.c"
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 118, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_4, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 118, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_m2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 118, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_4, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 118, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyNumber_Multiply(__pyx_t_3, __pyx_t_1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 118, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 118, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 118, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 118, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 118, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Multiply(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 118, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyNumber_Add(__pyx_t_4, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 118, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_b = __pyx_t_2;
  __pyx_t_2 = 0;
# 4806 "example1.c"
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_m2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_t_2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyNumber_Multiply(__pyx_t_1, __pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_4, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_m2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_4, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyNumber_Multiply(__pyx_t_1, __pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Add(__pyx_t_2, __pyx_t_4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_c = __pyx_t_3;
  __pyx_t_3 = 0;
# 4848 "example1.c"
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 120, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_t_3, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 120, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 120, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_3, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 120, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Multiply(__pyx_t_4, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 120, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 120, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_t_2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 120, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_m2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 120, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 120, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyNumber_Multiply(__pyx_t_4, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 120, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 120, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_d = __pyx_t_1;
  __pyx_t_1 = 0;
# 4890 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 121, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_a);
  __Pyx_GIVEREF(__pyx_v_a);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_a);
  __Pyx_INCREF(__pyx_v_b);
  __Pyx_GIVEREF(__pyx_v_b);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_b);
  __pyx_v_l1 = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 4908 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 122, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_c);
  __Pyx_GIVEREF(__pyx_v_c);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_c);
  __Pyx_INCREF(__pyx_v_d);
  __Pyx_GIVEREF(__pyx_v_d);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_d);
  __pyx_v_l2 = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 4926 "example1.c"
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 123, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_l = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 4938 "example1.c"
  __pyx_t_5 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l1); if (unlikely(__pyx_t_5 == ((int)-1))) __PYX_ERR(0, 124, __pyx_L1_error)
# 4947 "example1.c"
  __pyx_t_5 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l2); if (unlikely(__pyx_t_5 == ((int)-1))) __PYX_ERR(0, 125, __pyx_L1_error)
# 4956 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_l);
  __pyx_r = __pyx_v_l;
  goto __pyx_L0;
# 4970 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("example1.real_matrix_multiplication", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_a);
  __Pyx_XDECREF(__pyx_v_b);
  __Pyx_XDECREF(__pyx_v_c);
  __Pyx_XDECREF(__pyx_v_d);
  __Pyx_XDECREF(__pyx_v_l1);
  __Pyx_XDECREF(__pyx_v_l2);
  __Pyx_XDECREF(__pyx_v_l);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 4999 "example1.c"
static PyObject *__pyx_pw_8example1_31Cartesian_complex_matrix_multiplication(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_31Cartesian_complex_matrix_multiplication = {"Cartesian_complex_matrix_multiplication", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_31Cartesian_complex_matrix_multiplication, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_31Cartesian_complex_matrix_multiplication(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_m1 = 0;
  PyObject *__pyx_v_m2 = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Cartesian_complex_matrix_multiplication (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_m1,&__pyx_n_s_m2,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_m1)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_m2)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Cartesian_complex_matrix_multiplication", 1, 2, 2, 1); __PYX_ERR(0, 128, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "Cartesian_complex_matrix_multiplication") < 0)) __PYX_ERR(0, 128, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_m1 = values[0];
    __pyx_v_m2 = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("Cartesian_complex_matrix_multiplication", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 128, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.Cartesian_complex_matrix_multiplication", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_30Cartesian_complex_matrix_multiplication(__pyx_self, __pyx_v_m1, __pyx_v_m2);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_30Cartesian_complex_matrix_multiplication(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_m1, PyObject *__pyx_v_m2) {
  PyObject *__pyx_v_a = NULL;
  PyObject *__pyx_v_b = NULL;
  PyObject *__pyx_v_c = NULL;
  PyObject *__pyx_v_d = NULL;
  PyObject *__pyx_v_l1 = NULL;
  PyObject *__pyx_v_l2 = NULL;
  PyObject *__pyx_v_l = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  int __pyx_t_11;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Cartesian_complex_matrix_multiplication", 0);
# 5096 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Cartesian_complex_add); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Cartesian_complex_mul); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = __Pyx_GetItemInt(__pyx_t_5, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_GetItemInt(__pyx_v_m2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_7 = __Pyx_GetItemInt(__pyx_t_5, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_t_6, __pyx_t_7};
    __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_t_6, __pyx_t_7};
    __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  {
    __pyx_t_9 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    if (__pyx_t_5) {
      __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_5); __pyx_t_5 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_6);
    PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_8, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_8, __pyx_t_7);
    __pyx_t_6 = 0;
    __pyx_t_7 = 0;
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_t_9, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  }
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_9, __pyx_n_s_Cartesian_complex_mul); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __pyx_t_7 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_6 = __Pyx_GetItemInt(__pyx_t_7, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = __Pyx_GetItemInt(__pyx_v_m2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_5 = __Pyx_GetItemInt(__pyx_t_7, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_9))) {
    __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_9);
    if (likely(__pyx_t_7)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_9);
      __Pyx_INCREF(__pyx_t_7);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_9, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_9)) {
    PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_6, __pyx_t_5};
    __pyx_t_4 = __Pyx_PyFunction_FastCall(__pyx_t_9, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_9)) {
    PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_6, __pyx_t_5};
    __pyx_t_4 = __Pyx_PyCFunction_FastCall(__pyx_t_9, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  {
    __pyx_t_10 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_10);
    if (__pyx_t_7) {
      __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_10, 0, __pyx_t_7); __pyx_t_7 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_6);
    PyTuple_SET_ITEM(__pyx_t_10, 0+__pyx_t_8, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_10, 1+__pyx_t_8, __pyx_t_5);
    __pyx_t_6 = 0;
    __pyx_t_5 = 0;
    __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_9, __pyx_t_10, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  }
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_9 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_9)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_9);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_9, __pyx_t_3, __pyx_t_4};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_9, __pyx_t_3, __pyx_t_4};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  {
    __pyx_t_10 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_10);
    if (__pyx_t_9) {
      __Pyx_GIVEREF(__pyx_t_9); PyTuple_SET_ITEM(__pyx_t_10, 0, __pyx_t_9); __pyx_t_9 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_10, 0+__pyx_t_8, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_10, 1+__pyx_t_8, __pyx_t_4);
    __pyx_t_3 = 0;
    __pyx_t_4 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_10, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_a = __pyx_t_1;
  __pyx_t_1 = 0;
# 5279 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Cartesian_complex_add); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 132, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Cartesian_complex_mul); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 132, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 132, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_9 = __Pyx_GetItemInt(__pyx_t_3, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 132, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 132, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_5 = __Pyx_GetItemInt(__pyx_t_3, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 132, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_t_9, __pyx_t_5};
    __pyx_t_10 = __Pyx_PyFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 132, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_10);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_t_9, __pyx_t_5};
    __pyx_t_10 = __Pyx_PyCFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 132, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_10);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  {
    __pyx_t_6 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 132, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_9);
    PyTuple_SET_ITEM(__pyx_t_6, 0+__pyx_t_8, __pyx_t_9);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_6, 1+__pyx_t_8, __pyx_t_5);
    __pyx_t_9 = 0;
    __pyx_t_5 = 0;
    __pyx_t_10 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_t_6, NULL); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 132, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_10);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  }
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_Cartesian_complex_mul); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 132, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_5 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 132, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_9 = __Pyx_GetItemInt(__pyx_t_5, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 132, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_GetItemInt(__pyx_v_m2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 132, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_5, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 132, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_t_9, __pyx_t_3};
    __pyx_t_4 = __Pyx_PyFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 132, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_t_9, __pyx_t_3};
    __pyx_t_4 = __Pyx_PyCFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 132, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  } else
  #endif
  {
    __pyx_t_7 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 132, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    if (__pyx_t_5) {
      __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_5); __pyx_t_5 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_9);
    PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_8, __pyx_t_9);
    __Pyx_GIVEREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_8, __pyx_t_3);
    __pyx_t_9 = 0;
    __pyx_t_3 = 0;
    __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_7, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 132, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  }
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_t_10, __pyx_t_4};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 132, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_t_10, __pyx_t_4};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 132, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  {
    __pyx_t_7 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 132, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    if (__pyx_t_6) {
      __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_6); __pyx_t_6 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_10);
    PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_8, __pyx_t_10);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_8, __pyx_t_4);
    __pyx_t_10 = 0;
    __pyx_t_4 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_7, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 132, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_b = __pyx_t_1;
  __pyx_t_1 = 0;
# 5462 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Cartesian_complex_add); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Cartesian_complex_mul); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_10 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __pyx_t_6 = __Pyx_GetItemInt(__pyx_t_10, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = __Pyx_GetItemInt(__pyx_v_m2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_10, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_10)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_10);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_10, __pyx_t_6, __pyx_t_3};
    __pyx_t_7 = __Pyx_PyFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 133, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_10, __pyx_t_6, __pyx_t_3};
    __pyx_t_7 = __Pyx_PyCFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 133, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  } else
  #endif
  {
    __pyx_t_9 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 133, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    if (__pyx_t_10) {
      __Pyx_GIVEREF(__pyx_t_10); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_10); __pyx_t_10 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_6);
    PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_8, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_8, __pyx_t_3);
    __pyx_t_6 = 0;
    __pyx_t_3 = 0;
    __pyx_t_7 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_t_9, NULL); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 133, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  }
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_9, __pyx_n_s_Cartesian_complex_mul); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_6 = __Pyx_GetItemInt(__pyx_t_3, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_10 = __Pyx_GetItemInt(__pyx_t_3, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_9))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_9);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_9);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_9, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_9)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_t_6, __pyx_t_10};
    __pyx_t_4 = __Pyx_PyFunction_FastCall(__pyx_t_9, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 133, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_9)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_t_6, __pyx_t_10};
    __pyx_t_4 = __Pyx_PyCFunction_FastCall(__pyx_t_9, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 133, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  } else
  #endif
  {
    __pyx_t_5 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 133, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_6);
    PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_8, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_10);
    PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_8, __pyx_t_10);
    __pyx_t_6 = 0;
    __pyx_t_10 = 0;
    __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_9, __pyx_t_5, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 133, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  }
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_9 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_9)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_9);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_9, __pyx_t_7, __pyx_t_4};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 133, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_9, __pyx_t_7, __pyx_t_4};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 133, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  {
    __pyx_t_5 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 133, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (__pyx_t_9) {
      __Pyx_GIVEREF(__pyx_t_9); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_9); __pyx_t_9 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_8, __pyx_t_7);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_8, __pyx_t_4);
    __pyx_t_7 = 0;
    __pyx_t_4 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 133, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_c = __pyx_t_1;
  __pyx_t_1 = 0;
# 5645 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Cartesian_complex_add); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 134, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Cartesian_complex_mul); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 134, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_7 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 134, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_9 = __Pyx_GetItemInt(__pyx_t_7, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 134, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = __Pyx_GetItemInt(__pyx_v_m2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 134, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_10 = __Pyx_GetItemInt(__pyx_t_7, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 134, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_7)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_7);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_9, __pyx_t_10};
    __pyx_t_5 = __Pyx_PyFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 134, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_9, __pyx_t_10};
    __pyx_t_5 = __Pyx_PyCFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 134, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  } else
  #endif
  {
    __pyx_t_6 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 134, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    if (__pyx_t_7) {
      __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_t_7); __pyx_t_7 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_9);
    PyTuple_SET_ITEM(__pyx_t_6, 0+__pyx_t_8, __pyx_t_9);
    __Pyx_GIVEREF(__pyx_t_10);
    PyTuple_SET_ITEM(__pyx_t_6, 1+__pyx_t_8, __pyx_t_10);
    __pyx_t_9 = 0;
    __pyx_t_10 = 0;
    __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_t_6, NULL); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 134, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  }
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_Cartesian_complex_mul); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 134, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_10 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 134, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __pyx_t_9 = __Pyx_GetItemInt(__pyx_t_10, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 134, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = __Pyx_GetItemInt(__pyx_v_m2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 134, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __pyx_t_7 = __Pyx_GetItemInt(__pyx_t_10, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 134, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_10)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_10);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_10, __pyx_t_9, __pyx_t_7};
    __pyx_t_4 = __Pyx_PyFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 134, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_10, __pyx_t_9, __pyx_t_7};
    __pyx_t_4 = __Pyx_PyCFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 134, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  {
    __pyx_t_3 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 134, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if (__pyx_t_10) {
      __Pyx_GIVEREF(__pyx_t_10); PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_10); __pyx_t_10 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_9);
    PyTuple_SET_ITEM(__pyx_t_3, 0+__pyx_t_8, __pyx_t_9);
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_3, 1+__pyx_t_8, __pyx_t_7);
    __pyx_t_9 = 0;
    __pyx_t_7 = 0;
    __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_3, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 134, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  }
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_t_5, __pyx_t_4};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 134, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_t_5, __pyx_t_4};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 134, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  {
    __pyx_t_3 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 134, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if (__pyx_t_6) {
      __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_6); __pyx_t_6 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_3, 0+__pyx_t_8, __pyx_t_5);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_3, 1+__pyx_t_8, __pyx_t_4);
    __pyx_t_5 = 0;
    __pyx_t_4 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_3, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 134, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_d = __pyx_t_1;
  __pyx_t_1 = 0;
# 5828 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 135, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_a);
  __Pyx_GIVEREF(__pyx_v_a);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_a);
  __Pyx_INCREF(__pyx_v_b);
  __Pyx_GIVEREF(__pyx_v_b);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_b);
  __pyx_v_l1 = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 5846 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 136, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_c);
  __Pyx_GIVEREF(__pyx_v_c);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_c);
  __Pyx_INCREF(__pyx_v_d);
  __Pyx_GIVEREF(__pyx_v_d);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_d);
  __pyx_v_l2 = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 5864 "example1.c"
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 137, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_l = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 5876 "example1.c"
  __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l1); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 138, __pyx_L1_error)
# 5885 "example1.c"
  __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l2); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 139, __pyx_L1_error)
# 5894 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_l);
  __pyx_r = __pyx_v_l;
  goto __pyx_L0;
# 5908 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_AddTraceback("example1.Cartesian_complex_matrix_multiplication", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_a);
  __Pyx_XDECREF(__pyx_v_b);
  __Pyx_XDECREF(__pyx_v_c);
  __Pyx_XDECREF(__pyx_v_d);
  __Pyx_XDECREF(__pyx_v_l1);
  __Pyx_XDECREF(__pyx_v_l2);
  __Pyx_XDECREF(__pyx_v_l);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 5942 "example1.c"
static PyObject *__pyx_pw_8example1_33real_matrix_inverse(PyObject *__pyx_self, PyObject *__pyx_v_m1);
static PyMethodDef __pyx_mdef_8example1_33real_matrix_inverse = {"real_matrix_inverse", (PyCFunction)__pyx_pw_8example1_33real_matrix_inverse, METH_O, 0};
static PyObject *__pyx_pw_8example1_33real_matrix_inverse(PyObject *__pyx_self, PyObject *__pyx_v_m1) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("real_matrix_inverse (wrapper)", 0);
  __pyx_r = __pyx_pf_8example1_32real_matrix_inverse(__pyx_self, ((PyObject *)__pyx_v_m1));


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_32real_matrix_inverse(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_m1) {
  PyObject *__pyx_v_det = NULL;
  double __pyx_v_a;
  double __pyx_v_b;
  double __pyx_v_c;
  double __pyx_v_d;
  PyObject *__pyx_v_l1 = NULL;
  PyObject *__pyx_v_l2 = NULL;
  PyObject *__pyx_v_l = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  double __pyx_t_5;
  int __pyx_t_6;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("real_matrix_inverse", 0);
# 5984 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 144, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 144, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 144, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 144, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Multiply(__pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 144, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 144, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_3, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 144, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 144, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_t_3, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 144, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Multiply(__pyx_t_2, __pyx_t_4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 144, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyNumber_Subtract(__pyx_t_1, __pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 144, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_det = __pyx_t_4;
  __pyx_t_4 = 0;
# 6026 "example1.c"
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 145, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_4, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 145, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyNumber_Divide(__pyx_t_3, __pyx_v_det); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 145, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_5 = __Pyx_PyObject_AsDouble(__pyx_t_4); if (unlikely(__pyx_t_5 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 145, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_a = __pyx_t_5;
# 6045 "example1.c"
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 146, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_4, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 146, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyNumber_Negative(__pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 146, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyNumber_Divide(__pyx_t_4, __pyx_v_det); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 146, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_5 = __Pyx_PyObject_AsDouble(__pyx_t_3); if (unlikely(__pyx_t_5 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 146, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_b = __pyx_t_5;
# 6067 "example1.c"
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_t_3, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Negative(__pyx_t_4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyNumber_Divide(__pyx_t_3, __pyx_v_det); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_5 = __Pyx_PyObject_AsDouble(__pyx_t_4); if (unlikely(__pyx_t_5 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_c = __pyx_t_5;
# 6089 "example1.c"
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 148, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_4, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 148, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyNumber_Divide(__pyx_t_3, __pyx_v_det); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 148, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_5 = __Pyx_PyObject_AsDouble(__pyx_t_4); if (unlikely(__pyx_t_5 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 148, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_d = __pyx_t_5;
# 6108 "example1.c"
  __pyx_t_4 = PyFloat_FromDouble(__pyx_v_a); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 149, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = PyFloat_FromDouble(__pyx_v_b); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 149, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 149, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_4);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_t_3);
  __pyx_t_4 = 0;
  __pyx_t_3 = 0;
  __pyx_v_l1 = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 6130 "example1.c"
  __pyx_t_1 = PyFloat_FromDouble(__pyx_v_c); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyFloat_FromDouble(__pyx_v_d); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = PyList_New(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_4, 0, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_4, 1, __pyx_t_3);
  __pyx_t_1 = 0;
  __pyx_t_3 = 0;
  __pyx_v_l2 = ((PyObject*)__pyx_t_4);
  __pyx_t_4 = 0;
# 6152 "example1.c"
  __pyx_t_4 = PyList_New(0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 151, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_v_l = ((PyObject*)__pyx_t_4);
  __pyx_t_4 = 0;
# 6164 "example1.c"
  __pyx_t_6 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l1); if (unlikely(__pyx_t_6 == ((int)-1))) __PYX_ERR(0, 152, __pyx_L1_error)
# 6173 "example1.c"
  __pyx_t_6 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l2); if (unlikely(__pyx_t_6 == ((int)-1))) __PYX_ERR(0, 153, __pyx_L1_error)
# 6182 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_l);
  __pyx_r = __pyx_v_l;
  goto __pyx_L0;
# 6196 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("example1.real_matrix_inverse", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_det);
  __Pyx_XDECREF(__pyx_v_l1);
  __Pyx_XDECREF(__pyx_v_l2);
  __Pyx_XDECREF(__pyx_v_l);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 6222 "example1.c"
static PyObject *__pyx_pw_8example1_35Cartesian_complex_matrix_inverse(PyObject *__pyx_self, PyObject *__pyx_v_m1);
static PyMethodDef __pyx_mdef_8example1_35Cartesian_complex_matrix_inverse = {"Cartesian_complex_matrix_inverse", (PyCFunction)__pyx_pw_8example1_35Cartesian_complex_matrix_inverse, METH_O, 0};
static PyObject *__pyx_pw_8example1_35Cartesian_complex_matrix_inverse(PyObject *__pyx_self, PyObject *__pyx_v_m1) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Cartesian_complex_matrix_inverse (wrapper)", 0);
  __pyx_r = __pyx_pf_8example1_34Cartesian_complex_matrix_inverse(__pyx_self, ((PyObject *)__pyx_v_m1));


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_34Cartesian_complex_matrix_inverse(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_m1) {
  PyObject *__pyx_v_det = NULL;
  PyObject *__pyx_v_inverse_det = NULL;
  PyObject *__pyx_v_a = NULL;
  PyObject *__pyx_v_b = NULL;
  PyObject *__pyx_v_c = NULL;
  PyObject *__pyx_v_d = NULL;
  PyObject *__pyx_v_l1 = NULL;
  PyObject *__pyx_v_l2 = NULL;
  PyObject *__pyx_v_l = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  int __pyx_t_13;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Cartesian_complex_matrix_inverse", 0);
# 6272 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Cartesian_complex_add); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Cartesian_complex_mul); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = __Pyx_GetItemInt(__pyx_t_5, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_7 = __Pyx_GetItemInt(__pyx_t_5, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_t_6, __pyx_t_7};
    __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_t_6, __pyx_t_7};
    __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  {
    __pyx_t_9 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    if (__pyx_t_5) {
      __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_5); __pyx_t_5 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_6);
    PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_8, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_8, __pyx_t_7);
    __pyx_t_6 = 0;
    __pyx_t_7 = 0;
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_t_9, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  }
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_9, __pyx_n_s_Cartesian_complex_scalar_mul); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_Cartesian_complex_mul); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_5 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_10 = __Pyx_GetItemInt(__pyx_t_5, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_11 = __Pyx_GetItemInt(__pyx_t_5, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_t_10, __pyx_t_11};
    __pyx_t_7 = __Pyx_PyFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_t_10, __pyx_t_11};
    __pyx_t_7 = __Pyx_PyCFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
  } else
  #endif
  {
    __pyx_t_12 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_12);
    if (__pyx_t_5) {
      __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_12, 0, __pyx_t_5); __pyx_t_5 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_10);
    PyTuple_SET_ITEM(__pyx_t_12, 0+__pyx_t_8, __pyx_t_10);
    __Pyx_GIVEREF(__pyx_t_11);
    PyTuple_SET_ITEM(__pyx_t_12, 1+__pyx_t_8, __pyx_t_11);
    __pyx_t_10 = 0;
    __pyx_t_11 = 0;
    __pyx_t_7 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_12, NULL); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  }
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_9))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_9);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_9);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_9, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_9)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_int_neg_1, __pyx_t_7};
    __pyx_t_4 = __Pyx_PyFunction_FastCall(__pyx_t_9, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_9)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_int_neg_1, __pyx_t_7};
    __pyx_t_4 = __Pyx_PyCFunction_FastCall(__pyx_t_9, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  {
    __pyx_t_12 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_12);
    if (__pyx_t_6) {
      __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_12, 0, __pyx_t_6); __pyx_t_6 = NULL;
    }
    __Pyx_INCREF(__pyx_int_neg_1);
    __Pyx_GIVEREF(__pyx_int_neg_1);
    PyTuple_SET_ITEM(__pyx_t_12, 0+__pyx_t_8, __pyx_int_neg_1);
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_12, 1+__pyx_t_8, __pyx_t_7);
    __pyx_t_7 = 0;
    __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_9, __pyx_t_12, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  }
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_9 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_9)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_9);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_9, __pyx_t_3, __pyx_t_4};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_9, __pyx_t_3, __pyx_t_4};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  {
    __pyx_t_12 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_12);
    if (__pyx_t_9) {
      __Pyx_GIVEREF(__pyx_t_9); PyTuple_SET_ITEM(__pyx_t_12, 0, __pyx_t_9); __pyx_t_9 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_12, 0+__pyx_t_8, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_12, 1+__pyx_t_8, __pyx_t_4);
    __pyx_t_3 = 0;
    __pyx_t_4 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_12, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 159, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_det = __pyx_t_1;
  __pyx_t_1 = 0;
# 6504 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Cartesian_complex_divide); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 160, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_12 = PyList_New(2); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 160, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  __Pyx_INCREF(__pyx_int_1);
  __Pyx_GIVEREF(__pyx_int_1);
  PyList_SET_ITEM(__pyx_t_12, 0, __pyx_int_1);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_12, 1, __pyx_int_0);
  __pyx_t_4 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_t_12, __pyx_v_det};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_t_12, __pyx_v_det};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  } else
  #endif
  {
    __pyx_t_3 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if (__pyx_t_4) {
      __Pyx_GIVEREF(__pyx_t_4); PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_4); __pyx_t_4 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_12);
    PyTuple_SET_ITEM(__pyx_t_3, 0+__pyx_t_8, __pyx_t_12);
    __Pyx_INCREF(__pyx_v_det);
    __Pyx_GIVEREF(__pyx_v_det);
    PyTuple_SET_ITEM(__pyx_t_3, 1+__pyx_t_8, __pyx_v_det);
    __pyx_t_12 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_3, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_inverse_det = __pyx_t_1;
  __pyx_t_1 = 0;
# 6571 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Cartesian_complex_mul); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 161, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 161, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_12 = __Pyx_GetItemInt(__pyx_t_3, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 161, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_t_12, __pyx_v_inverse_det};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 161, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_t_12, __pyx_v_inverse_det};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 161, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  } else
  #endif
  {
    __pyx_t_4 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 161, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_12);
    PyTuple_SET_ITEM(__pyx_t_4, 0+__pyx_t_8, __pyx_t_12);
    __Pyx_INCREF(__pyx_v_inverse_det);
    __Pyx_GIVEREF(__pyx_v_inverse_det);
    PyTuple_SET_ITEM(__pyx_t_4, 1+__pyx_t_8, __pyx_v_inverse_det);
    __pyx_t_12 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_4, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 161, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_a = __pyx_t_1;
  __pyx_t_1 = 0;
# 6635 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Cartesian_complex_mul); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 162, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_12, __pyx_n_s_Cartesian_complex_scalar_mul); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 162, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 162, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_9 = __Pyx_GetItemInt(__pyx_t_3, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 162, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_12))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_12);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_12);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_12, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_12)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_int_neg_1, __pyx_t_9};
    __pyx_t_4 = __Pyx_PyFunction_FastCall(__pyx_t_12, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 162, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_12)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_int_neg_1, __pyx_t_9};
    __pyx_t_4 = __Pyx_PyCFunction_FastCall(__pyx_t_12, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 162, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  } else
  #endif
  {
    __pyx_t_7 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 162, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_INCREF(__pyx_int_neg_1);
    __Pyx_GIVEREF(__pyx_int_neg_1);
    PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_8, __pyx_int_neg_1);
    __Pyx_GIVEREF(__pyx_t_9);
    PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_8, __pyx_t_9);
    __pyx_t_9 = 0;
    __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_12, __pyx_t_7, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 162, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  }
  __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  __pyx_t_12 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_12 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_12)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_12);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_12, __pyx_t_4, __pyx_v_inverse_det};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 162, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_12, __pyx_t_4, __pyx_v_inverse_det};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 162, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  {
    __pyx_t_7 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 162, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    if (__pyx_t_12) {
      __Pyx_GIVEREF(__pyx_t_12); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_12); __pyx_t_12 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_8, __pyx_t_4);
    __Pyx_INCREF(__pyx_v_inverse_det);
    __Pyx_GIVEREF(__pyx_v_inverse_det);
    PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_8, __pyx_v_inverse_det);
    __pyx_t_4 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_7, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 162, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_b = __pyx_t_1;
  __pyx_t_1 = 0;
# 6748 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Cartesian_complex_mul); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 163, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Cartesian_complex_scalar_mul); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 163, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_12 = __Pyx_GetItemInt(__pyx_v_m1, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 163, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  __pyx_t_9 = __Pyx_GetItemInt(__pyx_t_12, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 163, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  __pyx_t_12 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_12 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_12)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_12);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_12, __pyx_int_neg_1, __pyx_t_9};
    __pyx_t_7 = __Pyx_PyFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 163, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_12, __pyx_int_neg_1, __pyx_t_9};
    __pyx_t_7 = __Pyx_PyCFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 163, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  } else
  #endif
  {
    __pyx_t_3 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 163, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if (__pyx_t_12) {
      __Pyx_GIVEREF(__pyx_t_12); PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_12); __pyx_t_12 = NULL;
    }
    __Pyx_INCREF(__pyx_int_neg_1);
    __Pyx_GIVEREF(__pyx_int_neg_1);
    PyTuple_SET_ITEM(__pyx_t_3, 0+__pyx_t_8, __pyx_int_neg_1);
    __Pyx_GIVEREF(__pyx_t_9);
    PyTuple_SET_ITEM(__pyx_t_3, 1+__pyx_t_8, __pyx_t_9);
    __pyx_t_9 = 0;
    __pyx_t_7 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_t_3, NULL); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 163, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  }
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_t_7, __pyx_v_inverse_det};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 163, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_t_7, __pyx_v_inverse_det};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 163, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  {
    __pyx_t_3 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 163, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if (__pyx_t_4) {
      __Pyx_GIVEREF(__pyx_t_4); PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_4); __pyx_t_4 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_3, 0+__pyx_t_8, __pyx_t_7);
    __Pyx_INCREF(__pyx_v_inverse_det);
    __Pyx_GIVEREF(__pyx_v_inverse_det);
    PyTuple_SET_ITEM(__pyx_t_3, 1+__pyx_t_8, __pyx_v_inverse_det);
    __pyx_t_7 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_3, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 163, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_c = __pyx_t_1;
  __pyx_t_1 = 0;
# 6861 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Cartesian_complex_mul); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 164, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_m1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 164, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_7 = __Pyx_GetItemInt(__pyx_t_3, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 164, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_t_7, __pyx_v_inverse_det};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 164, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_t_7, __pyx_v_inverse_det};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 164, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  {
    __pyx_t_4 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 164, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_4, 0+__pyx_t_8, __pyx_t_7);
    __Pyx_INCREF(__pyx_v_inverse_det);
    __Pyx_GIVEREF(__pyx_v_inverse_det);
    PyTuple_SET_ITEM(__pyx_t_4, 1+__pyx_t_8, __pyx_v_inverse_det);
    __pyx_t_7 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_4, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 164, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_d = __pyx_t_1;
  __pyx_t_1 = 0;
# 6925 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 165, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_a);
  __Pyx_GIVEREF(__pyx_v_a);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_a);
  __Pyx_INCREF(__pyx_v_b);
  __Pyx_GIVEREF(__pyx_v_b);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_b);
  __pyx_v_l1 = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 6943 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 166, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_c);
  __Pyx_GIVEREF(__pyx_v_c);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_c);
  __Pyx_INCREF(__pyx_v_d);
  __Pyx_GIVEREF(__pyx_v_d);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_d);
  __pyx_v_l2 = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 6961 "example1.c"
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 167, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_l = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 6973 "example1.c"
  __pyx_t_13 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l1); if (unlikely(__pyx_t_13 == ((int)-1))) __PYX_ERR(0, 168, __pyx_L1_error)
# 6982 "example1.c"
  __pyx_t_13 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l2); if (unlikely(__pyx_t_13 == ((int)-1))) __PYX_ERR(0, 169, __pyx_L1_error)
# 6991 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_l);
  __pyx_r = __pyx_v_l;
  goto __pyx_L0;
# 7005 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_AddTraceback("example1.Cartesian_complex_matrix_inverse", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_det);
  __Pyx_XDECREF(__pyx_v_inverse_det);
  __Pyx_XDECREF(__pyx_v_a);
  __Pyx_XDECREF(__pyx_v_b);
  __Pyx_XDECREF(__pyx_v_c);
  __Pyx_XDECREF(__pyx_v_d);
  __Pyx_XDECREF(__pyx_v_l1);
  __Pyx_XDECREF(__pyx_v_l2);
  __Pyx_XDECREF(__pyx_v_l);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 7043 "example1.c"
static PyObject *__pyx_pw_8example1_37Cartesian_radial_hyperbolic_distance(PyObject *__pyx_self, PyObject *__pyx_v_z);
static PyMethodDef __pyx_mdef_8example1_37Cartesian_radial_hyperbolic_distance = {"Cartesian_radial_hyperbolic_distance", (PyCFunction)__pyx_pw_8example1_37Cartesian_radial_hyperbolic_distance, METH_O, 0};
static PyObject *__pyx_pw_8example1_37Cartesian_radial_hyperbolic_distance(PyObject *__pyx_self, PyObject *__pyx_v_z) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Cartesian_radial_hyperbolic_distance (wrapper)", 0);
  __pyx_r = __pyx_pf_8example1_36Cartesian_radial_hyperbolic_distance(__pyx_self, ((PyObject *)__pyx_v_z));


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_36Cartesian_radial_hyperbolic_distance(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_z) {
  double __pyx_v_r;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  double __pyx_t_4;
  double __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Cartesian_radial_hyperbolic_distance", 0);
# 7078 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Cartesian_complex_modulus); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 174, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_v_z) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_z);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 174, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_4 = __Pyx_PyObject_AsDouble(__pyx_t_1); if (unlikely(__pyx_t_4 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 174, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_r = __pyx_t_4;
# 7106 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_math); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 175, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_log); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 175, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_4 = (1.0 + __pyx_v_r);
  __pyx_t_5 = (1.0 - __pyx_v_r);
  if (unlikely(__pyx_t_5 == 0)) {
    PyErr_SetString(PyExc_ZeroDivisionError, "float division");
    __PYX_ERR(0, 175, __pyx_L1_error)
  }
  __pyx_t_2 = PyFloat_FromDouble((__pyx_t_4 / __pyx_t_5)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 175, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_6, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 175, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;
# 7149 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("example1.Cartesian_radial_hyperbolic_distance", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 7171 "example1.c"
static PyObject *__pyx_pw_8example1_39operator_T(PyObject *__pyx_self, PyObject *__pyx_v_Lambda);
static PyMethodDef __pyx_mdef_8example1_39operator_T = {"operator_T", (PyCFunction)__pyx_pw_8example1_39operator_T, METH_O, 0};
static PyObject *__pyx_pw_8example1_39operator_T(PyObject *__pyx_self, PyObject *__pyx_v_Lambda) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("operator_T (wrapper)", 0);
  __pyx_r = __pyx_pf_8example1_38operator_T(__pyx_self, ((PyObject *)__pyx_v_Lambda));


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_38operator_T(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_Lambda) {
  CYTHON_UNUSED long __pyx_v_D;
  PyObject *__pyx_v_a1 = NULL;
  long __pyx_v_a2;
  long __pyx_v_b1;
  PyObject *__pyx_v_b2 = NULL;
  long __pyx_v_c1;
  PyObject *__pyx_v_c2 = NULL;
  PyObject *__pyx_v_d1 = NULL;
  long __pyx_v_d2;
  PyObject *__pyx_v_l1 = NULL;
  PyObject *__pyx_v_l2 = NULL;
  PyObject *__pyx_v_l = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("operator_T", 0);
# 7215 "example1.c"
  __pyx_v_D = 2;
# 7224 "example1.c"
  __pyx_t_1 = PyNumber_Negative(__pyx_v_Lambda); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 179, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyNumber_Divide(__pyx_int_1, __pyx_v_Lambda); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 179, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyNumber_Float(__pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 179, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyNumber_Subtract(__pyx_t_1, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 179, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Multiply(__pyx_t_2, __pyx_float_neg_0_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 179, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_a1 = __pyx_t_3;
  __pyx_t_3 = 0;
# 7248 "example1.c"
  __pyx_v_a2 = 0;
# 7257 "example1.c"
  __pyx_v_b1 = 0;
# 7266 "example1.c"
  __pyx_t_3 = PyNumber_Negative(__pyx_v_Lambda); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 182, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_PyNumber_Divide(__pyx_int_1, __pyx_v_Lambda); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 182, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyNumber_Float(__pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 182, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyNumber_Add(__pyx_t_3, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 182, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Multiply(__pyx_t_2, __pyx_float_neg_0_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 182, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_b2 = __pyx_t_1;
  __pyx_t_1 = 0;
# 7290 "example1.c"
  __pyx_v_c1 = 0;
# 7299 "example1.c"
  __pyx_t_1 = __Pyx_PyNumber_Divide(__pyx_int_1, __pyx_v_Lambda); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 184, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyNumber_Float(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 184, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Subtract(__pyx_v_Lambda, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 184, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyNumber_Multiply(__pyx_t_1, __pyx_float_neg_0_5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 184, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_c2 = __pyx_t_2;
  __pyx_t_2 = 0;
# 7320 "example1.c"
  __pyx_t_2 = PyNumber_Negative(__pyx_v_Lambda); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 185, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyNumber_Divide(__pyx_int_1, __pyx_v_Lambda); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 185, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyNumber_Float(__pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 185, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Subtract(__pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 185, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Multiply(__pyx_t_1, __pyx_float_neg_0_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 185, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_d1 = __pyx_t_3;
  __pyx_t_3 = 0;
# 7344 "example1.c"
  __pyx_v_d2 = 0;
# 7353 "example1.c"
  __pyx_t_3 = __Pyx_PyInt_From_long(__pyx_v_a2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 187, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 187, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_a1);
  __Pyx_GIVEREF(__pyx_v_a1);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_a1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyInt_From_long(__pyx_v_b1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 187, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyList_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 187, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __Pyx_INCREF(__pyx_v_b2);
  __Pyx_GIVEREF(__pyx_v_b2);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_v_b2);
  __pyx_t_3 = 0;
  __pyx_t_3 = PyList_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 187, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_3, 1, __pyx_t_2);
  __pyx_t_1 = 0;
  __pyx_t_2 = 0;
  __pyx_v_l1 = ((PyObject*)__pyx_t_3);
  __pyx_t_3 = 0;
# 7391 "example1.c"
  __pyx_t_3 = __Pyx_PyInt_From_long(__pyx_v_c1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 188, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyList_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 188, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __Pyx_INCREF(__pyx_v_c2);
  __Pyx_GIVEREF(__pyx_v_c2);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_v_c2);
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyInt_From_long(__pyx_v_d2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 188, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 188, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_d1);
  __Pyx_GIVEREF(__pyx_v_d1);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_d1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = PyList_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 188, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_2 = 0;
  __pyx_t_1 = 0;
  __pyx_v_l2 = ((PyObject*)__pyx_t_3);
  __pyx_t_3 = 0;
# 7429 "example1.c"
  __pyx_t_3 = PyList_New(0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 189, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_v_l = ((PyObject*)__pyx_t_3);
  __pyx_t_3 = 0;
# 7441 "example1.c"
  __pyx_t_4 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l1); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(0, 190, __pyx_L1_error)
# 7450 "example1.c"
  __pyx_t_4 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l2); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(0, 191, __pyx_L1_error)
# 7459 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_l);
  __pyx_r = __pyx_v_l;
  goto __pyx_L0;
# 7473 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("example1.operator_T", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_a1);
  __Pyx_XDECREF(__pyx_v_b2);
  __Pyx_XDECREF(__pyx_v_c2);
  __Pyx_XDECREF(__pyx_v_d1);
  __Pyx_XDECREF(__pyx_v_l1);
  __Pyx_XDECREF(__pyx_v_l2);
  __Pyx_XDECREF(__pyx_v_l);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 7501 "example1.c"
static PyObject *__pyx_pw_8example1_41operator_R(PyObject *__pyx_self, PyObject *__pyx_v_theta);
static PyMethodDef __pyx_mdef_8example1_41operator_R = {"operator_R", (PyCFunction)__pyx_pw_8example1_41operator_R, METH_O, 0};
static PyObject *__pyx_pw_8example1_41operator_R(PyObject *__pyx_self, PyObject *__pyx_v_theta) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("operator_R (wrapper)", 0);
  __pyx_r = __pyx_pf_8example1_40operator_R(__pyx_self, ((PyObject *)__pyx_v_theta));


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_40operator_R(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_theta) {
  PyObject *__pyx_v_a = NULL;
  PyObject *__pyx_v_b = NULL;
  PyObject *__pyx_v_c = NULL;
  PyObject *__pyx_v_d = NULL;
  PyObject *__pyx_v_l1 = NULL;
  PyObject *__pyx_v_l2 = NULL;
  PyObject *__pyx_v_l = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("operator_R", 0);
# 7541 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Polar_complex_complex_to_Cartesi); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 195, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyNumber_Multiply(__pyx_float_0_5, __pyx_v_theta); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 195, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyNumber_Float(__pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 195, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyList_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 195, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_int_1);
  __Pyx_GIVEREF(__pyx_int_1);
  PyList_SET_ITEM(__pyx_t_3, 0, __pyx_int_1);
  __Pyx_GIVEREF(__pyx_t_4);
  PyList_SET_ITEM(__pyx_t_3, 1, __pyx_t_4);
  __pyx_t_4 = 0;
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_4, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 195, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_a = __pyx_t_1;
  __pyx_t_1 = 0;
# 7582 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 196, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_int_0);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_int_0);
  __pyx_v_b = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 7600 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 197, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_int_0);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_int_0);
  __pyx_v_c = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 7618 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Polar_complex_complex_to_Cartesi); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyNumber_Multiply(__pyx_float_neg_0_5, __pyx_v_theta); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyNumber_Float(__pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyList_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_int_1);
  __Pyx_GIVEREF(__pyx_int_1);
  PyList_SET_ITEM(__pyx_t_3, 0, __pyx_int_1);
  __Pyx_GIVEREF(__pyx_t_4);
  PyList_SET_ITEM(__pyx_t_3, 1, __pyx_t_4);
  __pyx_t_4 = 0;
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_4, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_d = __pyx_t_1;
  __pyx_t_1 = 0;
# 7659 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 199, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_a);
  __Pyx_GIVEREF(__pyx_v_a);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_a);
  __Pyx_INCREF(__pyx_v_b);
  __Pyx_GIVEREF(__pyx_v_b);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_b);
  __pyx_v_l1 = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 7677 "example1.c"
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 200, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_c);
  __Pyx_GIVEREF(__pyx_v_c);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_v_c);
  __Pyx_INCREF(__pyx_v_d);
  __Pyx_GIVEREF(__pyx_v_d);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_v_d);
  __pyx_v_l2 = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 7695 "example1.c"
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 201, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_l = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 7707 "example1.c"
  __pyx_t_5 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l1); if (unlikely(__pyx_t_5 == ((int)-1))) __PYX_ERR(0, 202, __pyx_L1_error)
# 7716 "example1.c"
  __pyx_t_5 = __Pyx_PyList_Append(__pyx_v_l, __pyx_v_l2); if (unlikely(__pyx_t_5 == ((int)-1))) __PYX_ERR(0, 203, __pyx_L1_error)
# 7725 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_l);
  __pyx_r = __pyx_v_l;
  goto __pyx_L0;
# 7739 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("example1.operator_R", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_a);
  __Pyx_XDECREF(__pyx_v_b);
  __Pyx_XDECREF(__pyx_v_c);
  __Pyx_XDECREF(__pyx_v_d);
  __Pyx_XDECREF(__pyx_v_l1);
  __Pyx_XDECREF(__pyx_v_l2);
  __Pyx_XDECREF(__pyx_v_l);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 7768 "example1.c"
static PyObject *__pyx_pw_8example1_43classification_point(PyObject *__pyx_self, PyObject *__pyx_v_Lambda);
static PyMethodDef __pyx_mdef_8example1_43classification_point = {"classification_point", (PyCFunction)__pyx_pw_8example1_43classification_point, METH_O, 0};
static PyObject *__pyx_pw_8example1_43classification_point(PyObject *__pyx_self, PyObject *__pyx_v_Lambda) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("classification_point (wrapper)", 0);
  __pyx_r = __pyx_pf_8example1_42classification_point(__pyx_self, ((PyObject *)__pyx_v_Lambda));


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_42classification_point(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_Lambda) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("classification_point", 0);
# 7800 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyNumber_Power(__pyx_v_Lambda, __pyx_int_2, Py_None); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Multiply(__pyx_int_2, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Power(__pyx_v_Lambda, __pyx_int_4, Py_None); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyInt_AddObjC(__pyx_t_1, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyNumber_Divide(__pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyNumber_Float(__pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Power(__pyx_v_Lambda, __pyx_int_4, Py_None); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyInt_SubtractObjC(__pyx_t_1, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Power(__pyx_v_Lambda, __pyx_int_4, Py_None); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = __Pyx_PyInt_AddObjC(__pyx_t_1, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyNumber_Divide(__pyx_t_2, __pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyNumber_Float(__pyx_t_1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_4);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_t_4);
  __pyx_t_3 = 0;
  __pyx_t_4 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;
# 7856 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("example1.classification_point", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 7878 "example1.c"
static PyObject *__pyx_pw_8example1_45check_T_generate_a_Schottky(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_45check_T_generate_a_Schottky = {"check_T_generate_a_Schottky", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_45check_T_generate_a_Schottky, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_45check_T_generate_a_Schottky(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_Lambda = 0;
  PyObject *__pyx_v_m = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("check_T_generate_a_Schottky (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_Lambda,&__pyx_n_s_m,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_Lambda)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_m)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("check_T_generate_a_Schottky", 1, 2, 2, 1); __PYX_ERR(0, 209, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "check_T_generate_a_Schottky") < 0)) __PYX_ERR(0, 209, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_Lambda = values[0];
    __pyx_v_m = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("check_T_generate_a_Schottky", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 209, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.check_T_generate_a_Schottky", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_44check_T_generate_a_Schottky(__pyx_self, __pyx_v_Lambda, __pyx_v_m);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_44check_T_generate_a_Schottky(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_Lambda, PyObject *__pyx_v_m) {
  double __pyx_v_t;
  PyObject *__pyx_v_K = NULL;
  PyObject *__pyx_v_B = NULL;
  PyObject *__pyx_v_T = NULL;
  PyObject *__pyx_v_T0 = NULL;
  double __pyx_v_discriminant;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  double __pyx_t_3;
  PyObject *__pyx_t_4 = NULL;
  double __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  int __pyx_t_12;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("check_T_generate_a_Schottky", 0);
# 7975 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_math); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_pi); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyNumber_Divide(__pyx_t_2, __pyx_int_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_3 = __Pyx_PyObject_AsDouble(__pyx_t_1); if (unlikely(__pyx_t_3 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_math); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_pi); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Multiply(__pyx_int_2, __pyx_v_m); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = __Pyx_PyNumber_Divide(__pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_5 = __Pyx_PyObject_AsDouble(__pyx_t_4); if (unlikely(__pyx_t_5 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_t = (__pyx_t_3 - __pyx_t_5);
# 8007 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Polar_complex_complex_to_Cartesi); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyFloat_FromDouble((-__pyx_v_t)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_6 = PyList_New(2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_INCREF(__pyx_int_1);
  __Pyx_GIVEREF(__pyx_int_1);
  PyList_SET_ITEM(__pyx_t_6, 0, __pyx_int_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_6, 1, __pyx_t_2);
  __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_4 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_2, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_6);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_K = __pyx_t_4;
  __pyx_t_4 = 0;
# 8045 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_classification_point); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 212, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_4 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_6, __pyx_v_Lambda) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_v_Lambda);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 212, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_B = __pyx_t_4;
  __pyx_t_4 = 0;
# 8072 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_operator_T); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_4 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_6, __pyx_v_Lambda) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_v_Lambda);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_T = __pyx_t_4;
  __pyx_t_4 = 0;
# 8099 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Cartesian_complex_divide); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 214, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_6 = __Pyx_GetItemInt(__pyx_v_T, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 214, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_6, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 214, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = __Pyx_GetItemInt(__pyx_v_T, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 214, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_7 = __Pyx_GetItemInt(__pyx_t_6, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 214, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_1)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_t_2, __pyx_t_7};
    __pyx_t_4 = __Pyx_PyFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 214, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_1)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_t_2, __pyx_t_7};
    __pyx_t_4 = __Pyx_PyCFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 214, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  {
    __pyx_t_9 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 214, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    if (__pyx_t_6) {
      __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_6); __pyx_t_6 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_8, __pyx_t_2);
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_8, __pyx_t_7);
    __pyx_t_2 = 0;
    __pyx_t_7 = 0;
    __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_9, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 214, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_T0 = __pyx_t_4;
  __pyx_t_4 = 0;
# 8170 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Cartesian_complex_modulus); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_Cartesian_complex_add); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_Cartesian_complex_scalar_mul); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_10 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_10)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_10);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_10, __pyx_int_neg_1, __pyx_v_T0};
    __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_GOTREF(__pyx_t_2);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_10, __pyx_int_neg_1, __pyx_v_T0};
    __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_GOTREF(__pyx_t_2);
  } else
  #endif
  {
    __pyx_t_11 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    if (__pyx_t_10) {
      __Pyx_GIVEREF(__pyx_t_10); PyTuple_SET_ITEM(__pyx_t_11, 0, __pyx_t_10); __pyx_t_10 = NULL;
    }
    __Pyx_INCREF(__pyx_int_neg_1);
    __Pyx_GIVEREF(__pyx_int_neg_1);
    PyTuple_SET_ITEM(__pyx_t_11, 0+__pyx_t_8, __pyx_int_neg_1);
    __Pyx_INCREF(__pyx_v_T0);
    __Pyx_GIVEREF(__pyx_v_T0);
    PyTuple_SET_ITEM(__pyx_t_11, 1+__pyx_t_8, __pyx_v_T0);
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_11, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
  }
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_7);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_7, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_7)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_v_K, __pyx_t_2};
    __pyx_t_9 = __Pyx_PyFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_7)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_v_K, __pyx_t_2};
    __pyx_t_9 = __Pyx_PyCFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  } else
  #endif
  {
    __pyx_t_11 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    if (__pyx_t_6) {
      __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_11, 0, __pyx_t_6); __pyx_t_6 = NULL;
    }
    __Pyx_INCREF(__pyx_v_K);
    __Pyx_GIVEREF(__pyx_v_K);
    PyTuple_SET_ITEM(__pyx_t_11, 0+__pyx_t_8, __pyx_v_K);
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_11, 1+__pyx_t_8, __pyx_t_2);
    __pyx_t_2 = 0;
    __pyx_t_9 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_11, NULL); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
  }
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_7)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_7);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_4 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_7, __pyx_t_9) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_9);
  __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Power(__pyx_t_4, __pyx_int_2, Py_None); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_5 = __Pyx_PyObject_AsDouble(__pyx_t_1); if (unlikely(__pyx_t_5 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Cartesian_complex_modulus); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_Cartesian_complex_add); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Cartesian_complex_scalar_mul); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_6 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_int_neg_1, __pyx_v_T0};
    __pyx_t_11 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_11);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_int_neg_1, __pyx_v_T0};
    __pyx_t_11 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_11);
  } else
  #endif
  {
    __pyx_t_10 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_10);
    if (__pyx_t_6) {
      __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_10, 0, __pyx_t_6); __pyx_t_6 = NULL;
    }
    __Pyx_INCREF(__pyx_int_neg_1);
    __Pyx_GIVEREF(__pyx_int_neg_1);
    PyTuple_SET_ITEM(__pyx_t_10, 0+__pyx_t_8, __pyx_int_neg_1);
    __Pyx_INCREF(__pyx_v_T0);
    __Pyx_GIVEREF(__pyx_v_T0);
    PyTuple_SET_ITEM(__pyx_t_10, 1+__pyx_t_8, __pyx_v_T0);
    __pyx_t_11 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_10, NULL); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_7);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_7, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_7)) {
    PyObject *__pyx_temp[3] = {__pyx_t_2, __pyx_v_B, __pyx_t_11};
    __pyx_t_9 = __Pyx_PyFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_7)) {
    PyObject *__pyx_temp[3] = {__pyx_t_2, __pyx_v_B, __pyx_t_11};
    __pyx_t_9 = __Pyx_PyCFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
  } else
  #endif
  {
    __pyx_t_10 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_10);
    if (__pyx_t_2) {
      __Pyx_GIVEREF(__pyx_t_2); PyTuple_SET_ITEM(__pyx_t_10, 0, __pyx_t_2); __pyx_t_2 = NULL;
    }
    __Pyx_INCREF(__pyx_v_B);
    __Pyx_GIVEREF(__pyx_v_B);
    PyTuple_SET_ITEM(__pyx_t_10, 0+__pyx_t_8, __pyx_v_B);
    __Pyx_GIVEREF(__pyx_t_11);
    PyTuple_SET_ITEM(__pyx_t_10, 1+__pyx_t_8, __pyx_t_11);
    __pyx_t_11 = 0;
    __pyx_t_9 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_10, NULL); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  }
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_7)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_7);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_7, __pyx_t_9) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_9);
  __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyNumber_Power(__pyx_t_1, __pyx_int_2, Py_None); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_3 = __Pyx_PyObject_AsDouble(__pyx_t_4); if (unlikely(__pyx_t_3 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_discriminant = (__pyx_t_5 - __pyx_t_3);
# 8417 "example1.c"
  __pyx_t_4 = PyFloat_FromDouble(__pyx_v_discriminant); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 216, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_PrintOne(0, __pyx_t_4) < 0) __PYX_ERR(0, 216, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
# 8429 "example1.c"
  __pyx_t_12 = ((__pyx_v_discriminant > 0.0) != 0);
  if (__pyx_t_12) {
# 8439 "example1.c"
    __Pyx_XDECREF(__pyx_r);
    __Pyx_INCREF(Py_True);
    __pyx_r = Py_True;
    goto __pyx_L0;
# 8451 "example1.c"
  }
# 8460 "example1.c"
           {
    __Pyx_XDECREF(__pyx_r);
    __Pyx_INCREF(Py_False);
    __pyx_r = Py_False;
    goto __pyx_L0;
  }
# 8476 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_AddTraceback("example1.check_T_generate_a_Schottky", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_K);
  __Pyx_XDECREF(__pyx_v_B);
  __Pyx_XDECREF(__pyx_v_T);
  __Pyx_XDECREF(__pyx_v_T0);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 8506 "example1.c"
static PyObject *__pyx_pw_8example1_47Tz(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_47Tz = {"Tz", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_47Tz, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_47Tz(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_T = 0;
  PyObject *__pyx_v_z = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Tz (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_T,&__pyx_n_s_z,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_T)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_z)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Tz", 1, 2, 2, 1); __PYX_ERR(0, 222, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "Tz") < 0)) __PYX_ERR(0, 222, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_T = values[0];
    __pyx_v_z = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("Tz", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 222, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.Tz", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_46Tz(__pyx_self, __pyx_v_T, __pyx_v_z);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_46Tz(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_T, PyObject *__pyx_v_z) {
  PyObject *__pyx_v_a = NULL;
  PyObject *__pyx_v_b = NULL;
  PyObject *__pyx_v_c = NULL;
  PyObject *__pyx_v_d = NULL;
  PyObject *__pyx_v_x = NULL;
  PyObject *__pyx_v_y = NULL;
  double __pyx_v_A;
  double __pyx_v_B;
  double __pyx_v_C;
  double __pyx_v_D;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  double __pyx_t_4;
  double __pyx_t_5;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Tz", 0);
# 8600 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_T, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 223, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 223, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 223, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_a = __pyx_t_1;
  __pyx_t_1 = 0;
# 8618 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_T, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 224, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 224, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 224, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_b = __pyx_t_1;
  __pyx_t_1 = 0;
# 8636 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_T, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 225, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 225, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 225, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_c = __pyx_t_1;
  __pyx_t_1 = 0;
# 8654 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_T, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 226, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 226, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 226, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_d = __pyx_t_1;
  __pyx_t_1 = 0;
# 8672 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_z, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 227, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_x = __pyx_t_1;
  __pyx_t_1 = 0;
# 8684 "example1.c"
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_z, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_y = __pyx_t_1;
  __pyx_t_1 = 0;
# 8696 "example1.c"
  __pyx_t_1 = PyNumber_Multiply(__pyx_v_a, __pyx_v_x); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_v_c); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Multiply(__pyx_v_b, __pyx_v_y); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyNumber_Subtract(__pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_4 = __Pyx_PyObject_AsDouble(__pyx_t_3); if (unlikely(__pyx_t_4 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_A = __pyx_t_4;
# 8718 "example1.c"
  __pyx_t_3 = PyNumber_Negative(__pyx_v_d); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 230, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = PyNumber_Multiply(__pyx_v_b, __pyx_v_x); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 230, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Add(__pyx_t_3, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 230, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Multiply(__pyx_v_a, __pyx_v_y); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 230, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyNumber_Add(__pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 230, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_4 = __Pyx_PyObject_AsDouble(__pyx_t_3); if (unlikely(__pyx_t_4 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 230, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_B = __pyx_t_4;
# 8743 "example1.c"
  __pyx_t_3 = PyNumber_Multiply(__pyx_v_c, __pyx_v_x); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 231, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_v_a); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 231, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Multiply(__pyx_v_d, __pyx_v_y); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 231, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyNumber_Subtract(__pyx_t_1, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 231, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_4 = __Pyx_PyObject_AsDouble(__pyx_t_2); if (unlikely(__pyx_t_4 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 231, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_C = __pyx_t_4;
# 8765 "example1.c"
  __pyx_t_2 = PyNumber_Negative(__pyx_v_b); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 232, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyNumber_Multiply(__pyx_v_d, __pyx_v_x); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 232, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = PyNumber_Add(__pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 232, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Multiply(__pyx_v_c, __pyx_v_y); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 232, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 232, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_4 = __Pyx_PyObject_AsDouble(__pyx_t_2); if (unlikely(__pyx_t_4 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 232, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_D = __pyx_t_4;
# 8790 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_4 = ((__pyx_v_C * __pyx_v_A) + (__pyx_v_B * __pyx_v_D));
  __pyx_t_5 = (pow(__pyx_v_C, 2.0) + pow(__pyx_v_D, 2.0));
  if (unlikely(__pyx_t_5 == 0)) {
    PyErr_SetString(PyExc_ZeroDivisionError, "float division");
    __PYX_ERR(0, 233, __pyx_L1_error)
  }
  __pyx_t_2 = PyFloat_FromDouble((__pyx_t_4 / __pyx_t_5)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 233, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = ((__pyx_v_B * __pyx_v_C) - (__pyx_v_D * __pyx_v_A));
  __pyx_t_4 = (pow(__pyx_v_C, 2.0) + pow(__pyx_v_D, 2.0));
  if (unlikely(__pyx_t_4 == 0)) {
    PyErr_SetString(PyExc_ZeroDivisionError, "float division");
    __PYX_ERR(0, 233, __pyx_L1_error)
  }
  __pyx_t_3 = PyFloat_FromDouble((__pyx_t_5 / __pyx_t_4)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 233, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 233, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_t_3);
  __pyx_t_2 = 0;
  __pyx_t_3 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;
# 8828 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("example1.Tz", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_a);
  __Pyx_XDECREF(__pyx_v_b);
  __Pyx_XDECREF(__pyx_v_c);
  __Pyx_XDECREF(__pyx_v_d);
  __Pyx_XDECREF(__pyx_v_x);
  __Pyx_XDECREF(__pyx_v_y);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 8855 "example1.c"
static PyObject *__pyx_pw_8example1_49Gamma0(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_49Gamma0 = {"Gamma0", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_49Gamma0, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_49Gamma0(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_Lambda = 0;
  PyObject *__pyx_v_m = 0;
  PyObject *__pyx_v_N = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Gamma0 (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_Lambda,&__pyx_n_s_m,&__pyx_n_s_N,0};
    PyObject* values[3] = {0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_Lambda)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_m)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Gamma0", 1, 3, 3, 1); __PYX_ERR(0, 238, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case 2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_N)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Gamma0", 1, 3, 3, 2); __PYX_ERR(0, 238, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "Gamma0") < 0)) __PYX_ERR(0, 238, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_Lambda = values[0];
    __pyx_v_m = values[1];
    __pyx_v_N = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("Gamma0", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 238, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.Gamma0", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_48Gamma0(__pyx_self, __pyx_v_Lambda, __pyx_v_m, __pyx_v_N);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_48Gamma0(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_Lambda, PyObject *__pyx_v_m, PyObject *__pyx_v_N) {
  PyObject *__pyx_v_T = NULL;
  double __pyx_v_theta;
  PyObject *__pyx_v_R = NULL;
  PyObject *__pyx_v_L = NULL;
  PyObject *__pyx_v_tmp1 = NULL;
  PyObject *__pyx_v_tmp2 = NULL;
  PyObject *__pyx_v_nodes_in_DT = NULL;
  PyObject *__pyx_v_j = NULL;
  PyObject *__pyx_v_z = NULL;
  PyObject *__pyx_v_i = NULL;
  PyObject *__pyx_v_k = NULL;
  PyObject *__pyx_v_tmp3 = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  double __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  Py_ssize_t __pyx_t_9;
  PyObject *(*__pyx_t_10)(PyObject *);
  int __pyx_t_11;
  Py_ssize_t __pyx_t_12;
  PyObject *__pyx_t_13 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Gamma0", 0);
# 8970 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_operator_T); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 239, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_v_Lambda) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_Lambda);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 239, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_T = __pyx_t_1;
  __pyx_t_1 = 0;
# 8997 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_math); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_pi); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyNumber_Divide(__pyx_t_2, __pyx_v_m); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_4 = __Pyx_PyObject_AsDouble(__pyx_t_1); if (unlikely(__pyx_t_4 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_theta = __pyx_t_4;
# 9016 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_operator_R); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyFloat_FromDouble(__pyx_v_theta); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_5, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_R = __pyx_t_1;
  __pyx_t_1 = 0;
# 9046 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Tz); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyList_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_3, 0, __pyx_int_0);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_3, 1, __pyx_int_0);
  __pyx_t_5 = NULL;
  __pyx_t_6 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_6 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_3};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 242, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_3};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 242, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  } else
  #endif
  {
    __pyx_t_7 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 242, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    if (__pyx_t_5) {
      __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_5); __pyx_t_5 = NULL;
    }
    __Pyx_INCREF(__pyx_v_T);
    __Pyx_GIVEREF(__pyx_v_T);
    PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_6, __pyx_v_T);
    __Pyx_GIVEREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_6, __pyx_t_3);
    __pyx_t_3 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_7, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 242, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __pyx_t_1 = 0;
  __pyx_v_L = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;
# 9118 "example1.c"
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 243, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_tmp1 = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;
# 9130 "example1.c"
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 244, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_tmp2 = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;
# 9142 "example1.c"
  __pyx_t_2 = PyList_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 245, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_int_0);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_int_0);
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 245, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_2);
  __pyx_t_2 = 0;
  __pyx_v_nodes_in_DT = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 9165 "example1.c"
  __Pyx_INCREF(__pyx_int_1);
  __pyx_v_j = __pyx_int_1;
# 9175 "example1.c"
  while (1) {
    __pyx_t_1 = PyObject_RichCompare(__pyx_v_j, __pyx_v_N, Py_LE); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 247, __pyx_L1_error)
    __pyx_t_8 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 247, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (!__pyx_t_8) break;
# 9188 "example1.c"
    __pyx_t_1 = __Pyx_PyInt_EqObjC(__pyx_v_j, __pyx_int_1, 1, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 249, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_8 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 249, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (__pyx_t_8) {
# 9201 "example1.c"
      __pyx_t_1 = __Pyx_GetItemInt_List(__pyx_v_L, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 250, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_XDECREF_SET(__pyx_v_z, __pyx_t_1);
      __pyx_t_1 = 0;
# 9213 "example1.c"
      __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 251, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_1));
      __pyx_t_1 = 0;
# 9225 "example1.c"
      __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 252, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF_SET(__pyx_v_tmp2, ((PyObject*)__pyx_t_1));
      __pyx_t_1 = 0;
# 9237 "example1.c"
      __pyx_t_1 = PyNumber_Multiply(__pyx_int_2, __pyx_v_m); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 253, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_2 = __Pyx_PyInt_SubtractObjC(__pyx_t_1, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 253, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 253, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (likely(PyList_CheckExact(__pyx_t_1)) || PyTuple_CheckExact(__pyx_t_1)) {
        __pyx_t_2 = __pyx_t_1; __Pyx_INCREF(__pyx_t_2); __pyx_t_9 = 0;
        __pyx_t_10 = NULL;
      } else {
        __pyx_t_9 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 253, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_10 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 253, __pyx_L1_error)
      }
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      for (;;) {
        if (likely(!__pyx_t_10)) {
          if (likely(PyList_CheckExact(__pyx_t_2))) {
            if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_1 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_1); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 253, __pyx_L1_error)
            #else
            __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 253, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            #endif
          } else {
            if (__pyx_t_9 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_1 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_1); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 253, __pyx_L1_error)
            #else
            __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 253, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            #endif
          }
        } else {
          __pyx_t_1 = __pyx_t_10(__pyx_t_2);
          if (unlikely(!__pyx_t_1)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 253, __pyx_L1_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_1);
        }
        __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_1);
        __pyx_t_1 = 0;
# 9295 "example1.c"
        __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_Tz); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 254, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_3 = NULL;
        __pyx_t_6 = 0;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_7);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_7, function);
            __pyx_t_6 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_7)) {
          PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_R, __pyx_v_z};
          __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 254, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_GOTREF(__pyx_t_1);
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_7)) {
          PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_R, __pyx_v_z};
          __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 254, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_GOTREF(__pyx_t_1);
        } else
        #endif
        {
          __pyx_t_5 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 254, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_5);
          if (__pyx_t_3) {
            __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3); __pyx_t_3 = NULL;
          }
          __Pyx_INCREF(__pyx_v_R);
          __Pyx_GIVEREF(__pyx_v_R);
          PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_6, __pyx_v_R);
          __Pyx_INCREF(__pyx_v_z);
          __Pyx_GIVEREF(__pyx_v_z);
          PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_6, __pyx_v_z);
          __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 254, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        }
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_DECREF_SET(__pyx_v_z, __pyx_t_1);
        __pyx_t_1 = 0;
# 9352 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 255, __pyx_L1_error)
# 9361 "example1.c"
        __pyx_t_1 = __Pyx_PyInt_SubtractObjC(__pyx_v_m, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 256, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_7 = PyObject_RichCompare(__pyx_v_i, __pyx_t_1, Py_NE); __Pyx_XGOTREF(__pyx_t_7); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 256, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_8 = __Pyx_PyObject_IsTrue(__pyx_t_7); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 256, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (__pyx_t_8) {
# 9376 "example1.c"
          __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp2, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 257, __pyx_L1_error)
# 9385 "example1.c"
          goto __pyx_L8;
        }
# 9395 "example1.c"
                 {
          __pyx_t_7 = __Pyx_GetItemInt_List(__pyx_v_L, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 259, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp2, __pyx_t_7); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 259, __pyx_L1_error)
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        }
        __pyx_L8:;
# 9410 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
# 9420 "example1.c"
      __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 260, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF_SET(__pyx_v_L, ((PyObject*)__pyx_t_2));
      __pyx_t_2 = 0;
# 9432 "example1.c"
      __pyx_t_2 = __pyx_v_tmp2; __Pyx_INCREF(__pyx_t_2); __pyx_t_9 = 0;
      for (;;) {
        if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_7 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_7); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 261, __pyx_L1_error)
        #else
        __pyx_t_7 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 261, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_7);
        #endif
        __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_7);
        __pyx_t_7 = 0;
# 9451 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_L, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 262, __pyx_L1_error)
# 9460 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
# 9470 "example1.c"
      __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_Tz); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 263, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 263, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_INCREF(__pyx_int_0);
      __Pyx_GIVEREF(__pyx_int_0);
      PyList_SET_ITEM(__pyx_t_1, 0, __pyx_int_0);
      __Pyx_INCREF(__pyx_int_0);
      __Pyx_GIVEREF(__pyx_int_0);
      PyList_SET_ITEM(__pyx_t_1, 1, __pyx_int_0);
      __pyx_t_5 = NULL;
      __pyx_t_6 = 0;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
        __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_7);
        if (likely(__pyx_t_5)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
          __Pyx_INCREF(__pyx_t_5);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_7, function);
          __pyx_t_6 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_7)) {
        PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_1};
        __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 263, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_7)) {
        PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_1};
        __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 263, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      } else
      #endif
      {
        __pyx_t_3 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 263, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        if (__pyx_t_5) {
          __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_5); __pyx_t_5 = NULL;
        }
        __Pyx_INCREF(__pyx_v_T);
        __Pyx_GIVEREF(__pyx_v_T);
        PyTuple_SET_ITEM(__pyx_t_3, 0+__pyx_t_6, __pyx_v_T);
        __Pyx_GIVEREF(__pyx_t_1);
        PyTuple_SET_ITEM(__pyx_t_3, 1+__pyx_t_6, __pyx_t_1);
        __pyx_t_1 = 0;
        __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_3, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 263, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      }
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __pyx_t_7 = PyList_New(1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 263, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_GIVEREF(__pyx_t_2);
      PyList_SET_ITEM(__pyx_t_7, 0, __pyx_t_2);
      __pyx_t_2 = 0;
      __Pyx_DECREF_SET(__pyx_v_nodes_in_DT, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 9542 "example1.c"
      goto __pyx_L5;
    }
# 9552 "example1.c"
             {
      __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 267, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF_SET(__pyx_v_nodes_in_DT, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 9565 "example1.c"
      __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 268, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 9577 "example1.c"
      __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 269, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF_SET(__pyx_v_tmp2, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 9589 "example1.c"
      __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 270, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_XDECREF_SET(__pyx_v_tmp3, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 9601 "example1.c"
      __pyx_t_7 = __pyx_v_L; __Pyx_INCREF(__pyx_t_7); __pyx_t_9 = 0;
      for (;;) {
        if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_7)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyList_GET_ITEM(__pyx_t_7, __pyx_t_9); __Pyx_INCREF(__pyx_t_2); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 271, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_7, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 271, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
        __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_2);
        __pyx_t_2 = 0;
# 9620 "example1.c"
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Tz); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 272, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_1 = NULL;
        __pyx_t_6 = 0;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
          __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_3);
          if (likely(__pyx_t_1)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
            __Pyx_INCREF(__pyx_t_1);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_3, function);
            __pyx_t_6 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_3)) {
          PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_T, __pyx_v_k};
          __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 272, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_GOTREF(__pyx_t_2);
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
          PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_T, __pyx_v_k};
          __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 272, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_GOTREF(__pyx_t_2);
        } else
        #endif
        {
          __pyx_t_5 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 272, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_5);
          if (__pyx_t_1) {
            __Pyx_GIVEREF(__pyx_t_1); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_1); __pyx_t_1 = NULL;
          }
          __Pyx_INCREF(__pyx_v_T);
          __Pyx_GIVEREF(__pyx_v_T);
          PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_6, __pyx_v_T);
          __Pyx_INCREF(__pyx_v_k);
          __Pyx_GIVEREF(__pyx_v_k);
          PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_6, __pyx_v_k);
          __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_5, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 272, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        }
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_XDECREF_SET(__pyx_v_z, __pyx_t_2);
        __pyx_t_2 = 0;
# 9677 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_nodes_in_DT, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 273, __pyx_L1_error)
# 9686 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 274, __pyx_L1_error)
# 9695 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp2, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 275, __pyx_L1_error)
# 9704 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 9714 "example1.c"
      __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 276, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF_SET(__pyx_v_L, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 9726 "example1.c"
      __pyx_t_7 = PyNumber_Multiply(__pyx_int_2, __pyx_v_m); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 277, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_2 = __Pyx_PyInt_SubtractObjC(__pyx_t_7, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 277, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __pyx_t_7 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_t_2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 277, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (likely(PyList_CheckExact(__pyx_t_7)) || PyTuple_CheckExact(__pyx_t_7)) {
        __pyx_t_2 = __pyx_t_7; __Pyx_INCREF(__pyx_t_2); __pyx_t_9 = 0;
        __pyx_t_10 = NULL;
      } else {
        __pyx_t_9 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 277, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_10 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 277, __pyx_L1_error)
      }
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      for (;;) {
        if (likely(!__pyx_t_10)) {
          if (likely(PyList_CheckExact(__pyx_t_2))) {
            if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_7 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_7); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 277, __pyx_L1_error)
            #else
            __pyx_t_7 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 277, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_7);
            #endif
          } else {
            if (__pyx_t_9 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_7 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_7); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 277, __pyx_L1_error)
            #else
            __pyx_t_7 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 277, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_7);
            #endif
          }
        } else {
          __pyx_t_7 = __pyx_t_10(__pyx_t_2);
          if (unlikely(!__pyx_t_7)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 277, __pyx_L1_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_7);
        }
        __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_7);
        __pyx_t_7 = 0;
# 9784 "example1.c"
        __pyx_t_7 = __Pyx_PyInt_SubtractObjC(__pyx_v_m, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 278, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_3 = PyObject_RichCompare(__pyx_v_i, __pyx_t_7, Py_NE); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 278, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __pyx_t_8 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 278, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (__pyx_t_8) {
# 9799 "example1.c"
          __pyx_t_3 = __pyx_v_tmp1; __Pyx_INCREF(__pyx_t_3); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_3)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_7 = PyList_GET_ITEM(__pyx_t_3, __pyx_t_12); __Pyx_INCREF(__pyx_t_7); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 279, __pyx_L1_error)
            #else
            __pyx_t_7 = PySequence_ITEM(__pyx_t_3, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 279, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_7);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_7);
            __pyx_t_7 = 0;
# 9818 "example1.c"
            __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Tz); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 280, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __pyx_t_1 = NULL;
            __pyx_t_6 = 0;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
              __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_5);
              if (likely(__pyx_t_1)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
                __Pyx_INCREF(__pyx_t_1);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_5, function);
                __pyx_t_6 = 1;
              }
            }
            #if CYTHON_FAST_PYCALL
            if (PyFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_R, __pyx_v_k};
              __pyx_t_7 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 280, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
              __Pyx_GOTREF(__pyx_t_7);
            } else
            #endif
            #if CYTHON_FAST_PYCCALL
            if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_R, __pyx_v_k};
              __pyx_t_7 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 280, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
              __Pyx_GOTREF(__pyx_t_7);
            } else
            #endif
            {
              __pyx_t_13 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 280, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_13);
              if (__pyx_t_1) {
                __Pyx_GIVEREF(__pyx_t_1); PyTuple_SET_ITEM(__pyx_t_13, 0, __pyx_t_1); __pyx_t_1 = NULL;
              }
              __Pyx_INCREF(__pyx_v_R);
              __Pyx_GIVEREF(__pyx_v_R);
              PyTuple_SET_ITEM(__pyx_t_13, 0+__pyx_t_6, __pyx_v_R);
              __Pyx_INCREF(__pyx_v_k);
              __Pyx_GIVEREF(__pyx_v_k);
              PyTuple_SET_ITEM(__pyx_t_13, 1+__pyx_t_6, __pyx_v_k);
              __pyx_t_7 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_13, NULL); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 280, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_7);
              __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
            }
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp3, __pyx_t_7); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 280, __pyx_L1_error)
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 9875 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
# 9885 "example1.c"
          __pyx_t_3 = PyList_New(0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 281, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_3));
          __pyx_t_3 = 0;
# 9897 "example1.c"
          __pyx_t_3 = __pyx_v_tmp3; __Pyx_INCREF(__pyx_t_3); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_3)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_7 = PyList_GET_ITEM(__pyx_t_3, __pyx_t_12); __Pyx_INCREF(__pyx_t_7); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 282, __pyx_L1_error)
            #else
            __pyx_t_7 = PySequence_ITEM(__pyx_t_3, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 282, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_7);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_7);
            __pyx_t_7 = 0;
# 9916 "example1.c"
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 283, __pyx_L1_error)
# 9925 "example1.c"
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_L, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 284, __pyx_L1_error)
# 9934 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
# 9944 "example1.c"
          __pyx_t_3 = PyList_New(0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 285, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF_SET(__pyx_v_tmp3, ((PyObject*)__pyx_t_3));
          __pyx_t_3 = 0;
# 9956 "example1.c"
          goto __pyx_L15;
        }
# 9966 "example1.c"
        __pyx_t_3 = __Pyx_PyInt_SubtractObjC(__pyx_v_m, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 286, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_7 = PyObject_RichCompare(__pyx_v_i, __pyx_t_3, Py_EQ); __Pyx_XGOTREF(__pyx_t_7); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 286, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_8 = __Pyx_PyObject_IsTrue(__pyx_t_7); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 286, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (__pyx_t_8) {
# 9981 "example1.c"
          __pyx_t_7 = __pyx_v_tmp1; __Pyx_INCREF(__pyx_t_7); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_7)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_3 = PyList_GET_ITEM(__pyx_t_7, __pyx_t_12); __Pyx_INCREF(__pyx_t_3); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 287, __pyx_L1_error)
            #else
            __pyx_t_3 = PySequence_ITEM(__pyx_t_7, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 287, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_3);
            __pyx_t_3 = 0;
# 10000 "example1.c"
            __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Tz); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 288, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __pyx_t_13 = NULL;
            __pyx_t_6 = 0;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
              __pyx_t_13 = PyMethod_GET_SELF(__pyx_t_5);
              if (likely(__pyx_t_13)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
                __Pyx_INCREF(__pyx_t_13);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_5, function);
                __pyx_t_6 = 1;
              }
            }
            #if CYTHON_FAST_PYCALL
            if (PyFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_13, __pyx_v_R, __pyx_v_k};
              __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 288, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
              __Pyx_GOTREF(__pyx_t_3);
            } else
            #endif
            #if CYTHON_FAST_PYCCALL
            if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_13, __pyx_v_R, __pyx_v_k};
              __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 288, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
              __Pyx_GOTREF(__pyx_t_3);
            } else
            #endif
            {
              __pyx_t_1 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 288, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_1);
              if (__pyx_t_13) {
                __Pyx_GIVEREF(__pyx_t_13); PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_13); __pyx_t_13 = NULL;
              }
              __Pyx_INCREF(__pyx_v_R);
              __Pyx_GIVEREF(__pyx_v_R);
              PyTuple_SET_ITEM(__pyx_t_1, 0+__pyx_t_6, __pyx_v_R);
              __Pyx_INCREF(__pyx_v_k);
              __Pyx_GIVEREF(__pyx_v_k);
              PyTuple_SET_ITEM(__pyx_t_1, 1+__pyx_t_6, __pyx_v_k);
              __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_1, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 288, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_3);
              __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
            }
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp3, __pyx_t_3); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 288, __pyx_L1_error)
            __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
# 10057 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 10067 "example1.c"
          __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 289, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_7));
          __pyx_t_7 = 0;
# 10079 "example1.c"
          __pyx_t_7 = __pyx_v_tmp3; __Pyx_INCREF(__pyx_t_7); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_7)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_3 = PyList_GET_ITEM(__pyx_t_7, __pyx_t_12); __Pyx_INCREF(__pyx_t_3); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 290, __pyx_L1_error)
            #else
            __pyx_t_3 = PySequence_ITEM(__pyx_t_7, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 290, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_3);
            __pyx_t_3 = 0;
# 10098 "example1.c"
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 291, __pyx_L1_error)
# 10107 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 10117 "example1.c"
          __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 292, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF_SET(__pyx_v_tmp3, ((PyObject*)__pyx_t_7));
          __pyx_t_7 = 0;
# 10129 "example1.c"
          __pyx_t_7 = __pyx_v_tmp2; __Pyx_INCREF(__pyx_t_7); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_7)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_3 = PyList_GET_ITEM(__pyx_t_7, __pyx_t_12); __Pyx_INCREF(__pyx_t_3); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 293, __pyx_L1_error)
            #else
            __pyx_t_3 = PySequence_ITEM(__pyx_t_7, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 293, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_3);
            __pyx_t_3 = 0;
# 10148 "example1.c"
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_L, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 294, __pyx_L1_error)
# 10157 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 10167 "example1.c"
        }
        __pyx_L15:;
# 10177 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    }
    __pyx_L5:;
# 10189 "example1.c"
    __pyx_t_2 = __Pyx_PyInt_AddObjC(__pyx_v_j, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 296, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF_SET(__pyx_v_j, __pyx_t_2);
    __pyx_t_2 = 0;
  }
# 10202 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_nodes_in_DT);
  __pyx_r = __pyx_v_nodes_in_DT;
  goto __pyx_L0;
# 10216 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_AddTraceback("example1.Gamma0", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_T);
  __Pyx_XDECREF(__pyx_v_R);
  __Pyx_XDECREF(__pyx_v_L);
  __Pyx_XDECREF(__pyx_v_tmp1);
  __Pyx_XDECREF(__pyx_v_tmp2);
  __Pyx_XDECREF(__pyx_v_nodes_in_DT);
  __Pyx_XDECREF(__pyx_v_j);
  __Pyx_XDECREF(__pyx_v_z);
  __Pyx_XDECREF(__pyx_v_i);
  __Pyx_XDECREF(__pyx_v_k);
  __Pyx_XDECREF(__pyx_v_tmp3);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 10251 "example1.c"
static PyObject *__pyx_pw_8example1_51Hyperbolic_Distance_Gamma0(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_51Hyperbolic_Distance_Gamma0 = {"Hyperbolic_Distance_Gamma0", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_51Hyperbolic_Distance_Gamma0, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_51Hyperbolic_Distance_Gamma0(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_Lambda = 0;
  PyObject *__pyx_v_m = 0;
  PyObject *__pyx_v_N = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Hyperbolic_Distance_Gamma0 (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_Lambda,&__pyx_n_s_m,&__pyx_n_s_N,0};
    PyObject* values[3] = {0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_Lambda)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_m)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Hyperbolic_Distance_Gamma0", 1, 3, 3, 1); __PYX_ERR(0, 299, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case 2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_N)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Hyperbolic_Distance_Gamma0", 1, 3, 3, 2); __PYX_ERR(0, 299, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "Hyperbolic_Distance_Gamma0") < 0)) __PYX_ERR(0, 299, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_Lambda = values[0];
    __pyx_v_m = values[1];
    __pyx_v_N = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("Hyperbolic_Distance_Gamma0", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 299, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.Hyperbolic_Distance_Gamma0", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_50Hyperbolic_Distance_Gamma0(__pyx_self, __pyx_v_Lambda, __pyx_v_m, __pyx_v_N);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_50Hyperbolic_Distance_Gamma0(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_Lambda, PyObject *__pyx_v_m, PyObject *__pyx_v_N) {
  PyObject *__pyx_v_T = NULL;
  double __pyx_v_theta;
  PyObject *__pyx_v_R = NULL;
  PyObject *__pyx_v_L = NULL;
  PyObject *__pyx_v_tmp1 = NULL;
  PyObject *__pyx_v_tmp2 = NULL;
  PyObject *__pyx_v_nodes_in_DT = NULL;
  PyObject *__pyx_v_j = NULL;
  PyObject *__pyx_v_z = NULL;
  PyObject *__pyx_v_i = NULL;
  PyObject *__pyx_v_k = NULL;
  PyObject *__pyx_v_tmp3 = NULL;
  PyObject *__pyx_v_Hyperbolic_distance = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  double __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  Py_ssize_t __pyx_t_9;
  PyObject *(*__pyx_t_10)(PyObject *);
  int __pyx_t_11;
  Py_ssize_t __pyx_t_12;
  PyObject *__pyx_t_13 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Hyperbolic_Distance_Gamma0", 0);
# 10367 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_operator_T); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 300, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_v_Lambda) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_Lambda);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 300, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_T = __pyx_t_1;
  __pyx_t_1 = 0;
# 10394 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_math); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_pi); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyNumber_Divide(__pyx_t_2, __pyx_v_m); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_4 = __Pyx_PyObject_AsDouble(__pyx_t_1); if (unlikely(__pyx_t_4 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_theta = __pyx_t_4;
# 10413 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_operator_R); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 302, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyFloat_FromDouble(__pyx_v_theta); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 302, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_5, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 302, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_R = __pyx_t_1;
  __pyx_t_1 = 0;
# 10443 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Tz); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 303, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyList_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 303, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_3, 0, __pyx_int_0);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_3, 1, __pyx_int_0);
  __pyx_t_5 = NULL;
  __pyx_t_6 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_6 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_3};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 303, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_3};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 303, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  } else
  #endif
  {
    __pyx_t_7 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 303, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    if (__pyx_t_5) {
      __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_5); __pyx_t_5 = NULL;
    }
    __Pyx_INCREF(__pyx_v_T);
    __Pyx_GIVEREF(__pyx_v_T);
    PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_6, __pyx_v_T);
    __Pyx_GIVEREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_6, __pyx_t_3);
    __pyx_t_3 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_7, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 303, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 303, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __pyx_t_1 = 0;
  __pyx_v_L = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;
# 10515 "example1.c"
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_tmp1 = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;
# 10527 "example1.c"
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 305, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_tmp2 = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;
# 10539 "example1.c"
  __pyx_t_2 = PyList_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 306, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_int_0);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_int_0);
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 306, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_2);
  __pyx_t_2 = 0;
  __pyx_v_nodes_in_DT = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 10562 "example1.c"
  __Pyx_INCREF(__pyx_int_1);
  __pyx_v_j = __pyx_int_1;
# 10572 "example1.c"
  while (1) {
    __pyx_t_1 = PyObject_RichCompare(__pyx_v_j, __pyx_v_N, Py_LE); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 308, __pyx_L1_error)
    __pyx_t_8 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 308, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (!__pyx_t_8) break;
# 10585 "example1.c"
    __pyx_t_1 = __Pyx_PyInt_EqObjC(__pyx_v_j, __pyx_int_1, 1, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 310, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_8 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 310, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (__pyx_t_8) {
# 10598 "example1.c"
      __pyx_t_1 = __Pyx_GetItemInt_List(__pyx_v_L, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 311, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_XDECREF_SET(__pyx_v_z, __pyx_t_1);
      __pyx_t_1 = 0;
# 10610 "example1.c"
      __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 312, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_1));
      __pyx_t_1 = 0;
# 10622 "example1.c"
      __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 313, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF_SET(__pyx_v_tmp2, ((PyObject*)__pyx_t_1));
      __pyx_t_1 = 0;
# 10634 "example1.c"
      __pyx_t_1 = PyNumber_Multiply(__pyx_int_2, __pyx_v_m); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 314, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_2 = __Pyx_PyInt_SubtractObjC(__pyx_t_1, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 314, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 314, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (likely(PyList_CheckExact(__pyx_t_1)) || PyTuple_CheckExact(__pyx_t_1)) {
        __pyx_t_2 = __pyx_t_1; __Pyx_INCREF(__pyx_t_2); __pyx_t_9 = 0;
        __pyx_t_10 = NULL;
      } else {
        __pyx_t_9 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 314, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_10 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 314, __pyx_L1_error)
      }
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      for (;;) {
        if (likely(!__pyx_t_10)) {
          if (likely(PyList_CheckExact(__pyx_t_2))) {
            if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_1 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_1); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 314, __pyx_L1_error)
            #else
            __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 314, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            #endif
          } else {
            if (__pyx_t_9 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_1 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_1); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 314, __pyx_L1_error)
            #else
            __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 314, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            #endif
          }
        } else {
          __pyx_t_1 = __pyx_t_10(__pyx_t_2);
          if (unlikely(!__pyx_t_1)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 314, __pyx_L1_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_1);
        }
        __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_1);
        __pyx_t_1 = 0;
# 10692 "example1.c"
        __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_Tz); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 315, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_3 = NULL;
        __pyx_t_6 = 0;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_7);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_7, function);
            __pyx_t_6 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_7)) {
          PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_R, __pyx_v_z};
          __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 315, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_GOTREF(__pyx_t_1);
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_7)) {
          PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_R, __pyx_v_z};
          __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 315, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_GOTREF(__pyx_t_1);
        } else
        #endif
        {
          __pyx_t_5 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 315, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_5);
          if (__pyx_t_3) {
            __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3); __pyx_t_3 = NULL;
          }
          __Pyx_INCREF(__pyx_v_R);
          __Pyx_GIVEREF(__pyx_v_R);
          PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_6, __pyx_v_R);
          __Pyx_INCREF(__pyx_v_z);
          __Pyx_GIVEREF(__pyx_v_z);
          PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_6, __pyx_v_z);
          __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 315, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        }
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_DECREF_SET(__pyx_v_z, __pyx_t_1);
        __pyx_t_1 = 0;
# 10749 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 316, __pyx_L1_error)
# 10758 "example1.c"
        __pyx_t_1 = __Pyx_PyInt_SubtractObjC(__pyx_v_m, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 317, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_7 = PyObject_RichCompare(__pyx_v_i, __pyx_t_1, Py_NE); __Pyx_XGOTREF(__pyx_t_7); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 317, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_8 = __Pyx_PyObject_IsTrue(__pyx_t_7); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 317, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (__pyx_t_8) {
# 10773 "example1.c"
          __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp2, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 318, __pyx_L1_error)
# 10782 "example1.c"
          goto __pyx_L8;
        }
# 10792 "example1.c"
                 {
          __pyx_t_7 = __Pyx_GetItemInt_List(__pyx_v_L, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 320, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp2, __pyx_t_7); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 320, __pyx_L1_error)
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        }
        __pyx_L8:;
# 10807 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
# 10817 "example1.c"
      __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 321, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF_SET(__pyx_v_L, ((PyObject*)__pyx_t_2));
      __pyx_t_2 = 0;
# 10829 "example1.c"
      __pyx_t_2 = __pyx_v_tmp2; __Pyx_INCREF(__pyx_t_2); __pyx_t_9 = 0;
      for (;;) {
        if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_7 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_7); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 322, __pyx_L1_error)
        #else
        __pyx_t_7 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 322, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_7);
        #endif
        __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_7);
        __pyx_t_7 = 0;
# 10848 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_L, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 323, __pyx_L1_error)
# 10857 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
# 10867 "example1.c"
      __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_Tz); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 324, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 324, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_INCREF(__pyx_int_0);
      __Pyx_GIVEREF(__pyx_int_0);
      PyList_SET_ITEM(__pyx_t_1, 0, __pyx_int_0);
      __Pyx_INCREF(__pyx_int_0);
      __Pyx_GIVEREF(__pyx_int_0);
      PyList_SET_ITEM(__pyx_t_1, 1, __pyx_int_0);
      __pyx_t_5 = NULL;
      __pyx_t_6 = 0;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
        __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_7);
        if (likely(__pyx_t_5)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
          __Pyx_INCREF(__pyx_t_5);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_7, function);
          __pyx_t_6 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_7)) {
        PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_1};
        __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 324, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_7)) {
        PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_1};
        __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 324, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      } else
      #endif
      {
        __pyx_t_3 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 324, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        if (__pyx_t_5) {
          __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_5); __pyx_t_5 = NULL;
        }
        __Pyx_INCREF(__pyx_v_T);
        __Pyx_GIVEREF(__pyx_v_T);
        PyTuple_SET_ITEM(__pyx_t_3, 0+__pyx_t_6, __pyx_v_T);
        __Pyx_GIVEREF(__pyx_t_1);
        PyTuple_SET_ITEM(__pyx_t_3, 1+__pyx_t_6, __pyx_t_1);
        __pyx_t_1 = 0;
        __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_3, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 324, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      }
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __pyx_t_7 = PyList_New(1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 324, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_GIVEREF(__pyx_t_2);
      PyList_SET_ITEM(__pyx_t_7, 0, __pyx_t_2);
      __pyx_t_2 = 0;
      __Pyx_DECREF_SET(__pyx_v_nodes_in_DT, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 10939 "example1.c"
      goto __pyx_L5;
    }
# 10949 "example1.c"
             {
      __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 328, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF_SET(__pyx_v_nodes_in_DT, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 10962 "example1.c"
      __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 329, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 10974 "example1.c"
      __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 330, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF_SET(__pyx_v_tmp2, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 10986 "example1.c"
      __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 331, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_XDECREF_SET(__pyx_v_tmp3, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 10998 "example1.c"
      __pyx_t_7 = __pyx_v_L; __Pyx_INCREF(__pyx_t_7); __pyx_t_9 = 0;
      for (;;) {
        if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_7)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyList_GET_ITEM(__pyx_t_7, __pyx_t_9); __Pyx_INCREF(__pyx_t_2); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 332, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_7, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 332, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
        __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_2);
        __pyx_t_2 = 0;
# 11017 "example1.c"
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Tz); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 333, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_1 = NULL;
        __pyx_t_6 = 0;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
          __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_3);
          if (likely(__pyx_t_1)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
            __Pyx_INCREF(__pyx_t_1);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_3, function);
            __pyx_t_6 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_3)) {
          PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_T, __pyx_v_k};
          __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 333, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_GOTREF(__pyx_t_2);
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
          PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_T, __pyx_v_k};
          __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 333, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_GOTREF(__pyx_t_2);
        } else
        #endif
        {
          __pyx_t_5 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 333, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_5);
          if (__pyx_t_1) {
            __Pyx_GIVEREF(__pyx_t_1); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_1); __pyx_t_1 = NULL;
          }
          __Pyx_INCREF(__pyx_v_T);
          __Pyx_GIVEREF(__pyx_v_T);
          PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_6, __pyx_v_T);
          __Pyx_INCREF(__pyx_v_k);
          __Pyx_GIVEREF(__pyx_v_k);
          PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_6, __pyx_v_k);
          __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_5, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 333, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        }
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_XDECREF_SET(__pyx_v_z, __pyx_t_2);
        __pyx_t_2 = 0;
# 11074 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_nodes_in_DT, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 334, __pyx_L1_error)
# 11083 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 335, __pyx_L1_error)
# 11092 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp2, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 336, __pyx_L1_error)
# 11101 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 11111 "example1.c"
      __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 337, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF_SET(__pyx_v_L, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 11123 "example1.c"
      __pyx_t_7 = PyNumber_Multiply(__pyx_int_2, __pyx_v_m); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 338, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_2 = __Pyx_PyInt_SubtractObjC(__pyx_t_7, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 338, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __pyx_t_7 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_t_2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 338, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (likely(PyList_CheckExact(__pyx_t_7)) || PyTuple_CheckExact(__pyx_t_7)) {
        __pyx_t_2 = __pyx_t_7; __Pyx_INCREF(__pyx_t_2); __pyx_t_9 = 0;
        __pyx_t_10 = NULL;
      } else {
        __pyx_t_9 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 338, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_10 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 338, __pyx_L1_error)
      }
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      for (;;) {
        if (likely(!__pyx_t_10)) {
          if (likely(PyList_CheckExact(__pyx_t_2))) {
            if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_7 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_7); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 338, __pyx_L1_error)
            #else
            __pyx_t_7 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 338, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_7);
            #endif
          } else {
            if (__pyx_t_9 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_7 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_7); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 338, __pyx_L1_error)
            #else
            __pyx_t_7 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 338, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_7);
            #endif
          }
        } else {
          __pyx_t_7 = __pyx_t_10(__pyx_t_2);
          if (unlikely(!__pyx_t_7)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 338, __pyx_L1_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_7);
        }
        __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_7);
        __pyx_t_7 = 0;
# 11181 "example1.c"
        __pyx_t_7 = __Pyx_PyInt_SubtractObjC(__pyx_v_m, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 339, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_3 = PyObject_RichCompare(__pyx_v_i, __pyx_t_7, Py_NE); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 339, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __pyx_t_8 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 339, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (__pyx_t_8) {
# 11196 "example1.c"
          __pyx_t_3 = __pyx_v_tmp1; __Pyx_INCREF(__pyx_t_3); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_3)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_7 = PyList_GET_ITEM(__pyx_t_3, __pyx_t_12); __Pyx_INCREF(__pyx_t_7); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 340, __pyx_L1_error)
            #else
            __pyx_t_7 = PySequence_ITEM(__pyx_t_3, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 340, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_7);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_7);
            __pyx_t_7 = 0;
# 11215 "example1.c"
            __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Tz); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 341, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __pyx_t_1 = NULL;
            __pyx_t_6 = 0;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
              __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_5);
              if (likely(__pyx_t_1)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
                __Pyx_INCREF(__pyx_t_1);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_5, function);
                __pyx_t_6 = 1;
              }
            }
            #if CYTHON_FAST_PYCALL
            if (PyFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_R, __pyx_v_k};
              __pyx_t_7 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 341, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
              __Pyx_GOTREF(__pyx_t_7);
            } else
            #endif
            #if CYTHON_FAST_PYCCALL
            if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_R, __pyx_v_k};
              __pyx_t_7 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 341, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
              __Pyx_GOTREF(__pyx_t_7);
            } else
            #endif
            {
              __pyx_t_13 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 341, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_13);
              if (__pyx_t_1) {
                __Pyx_GIVEREF(__pyx_t_1); PyTuple_SET_ITEM(__pyx_t_13, 0, __pyx_t_1); __pyx_t_1 = NULL;
              }
              __Pyx_INCREF(__pyx_v_R);
              __Pyx_GIVEREF(__pyx_v_R);
              PyTuple_SET_ITEM(__pyx_t_13, 0+__pyx_t_6, __pyx_v_R);
              __Pyx_INCREF(__pyx_v_k);
              __Pyx_GIVEREF(__pyx_v_k);
              PyTuple_SET_ITEM(__pyx_t_13, 1+__pyx_t_6, __pyx_v_k);
              __pyx_t_7 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_13, NULL); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 341, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_7);
              __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
            }
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp3, __pyx_t_7); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 341, __pyx_L1_error)
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 11272 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
# 11282 "example1.c"
          __pyx_t_3 = PyList_New(0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 342, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_3));
          __pyx_t_3 = 0;
# 11294 "example1.c"
          __pyx_t_3 = __pyx_v_tmp3; __Pyx_INCREF(__pyx_t_3); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_3)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_7 = PyList_GET_ITEM(__pyx_t_3, __pyx_t_12); __Pyx_INCREF(__pyx_t_7); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 343, __pyx_L1_error)
            #else
            __pyx_t_7 = PySequence_ITEM(__pyx_t_3, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 343, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_7);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_7);
            __pyx_t_7 = 0;
# 11313 "example1.c"
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 344, __pyx_L1_error)
# 11322 "example1.c"
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_L, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 345, __pyx_L1_error)
# 11331 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
# 11341 "example1.c"
          __pyx_t_3 = PyList_New(0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 346, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF_SET(__pyx_v_tmp3, ((PyObject*)__pyx_t_3));
          __pyx_t_3 = 0;
# 11353 "example1.c"
          goto __pyx_L15;
        }
# 11363 "example1.c"
        __pyx_t_3 = __Pyx_PyInt_SubtractObjC(__pyx_v_m, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 347, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_7 = PyObject_RichCompare(__pyx_v_i, __pyx_t_3, Py_EQ); __Pyx_XGOTREF(__pyx_t_7); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 347, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_8 = __Pyx_PyObject_IsTrue(__pyx_t_7); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 347, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (__pyx_t_8) {
# 11378 "example1.c"
          __pyx_t_7 = __pyx_v_tmp1; __Pyx_INCREF(__pyx_t_7); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_7)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_3 = PyList_GET_ITEM(__pyx_t_7, __pyx_t_12); __Pyx_INCREF(__pyx_t_3); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 348, __pyx_L1_error)
            #else
            __pyx_t_3 = PySequence_ITEM(__pyx_t_7, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 348, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_3);
            __pyx_t_3 = 0;
# 11397 "example1.c"
            __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Tz); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 349, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __pyx_t_13 = NULL;
            __pyx_t_6 = 0;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
              __pyx_t_13 = PyMethod_GET_SELF(__pyx_t_5);
              if (likely(__pyx_t_13)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
                __Pyx_INCREF(__pyx_t_13);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_5, function);
                __pyx_t_6 = 1;
              }
            }
            #if CYTHON_FAST_PYCALL
            if (PyFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_13, __pyx_v_R, __pyx_v_k};
              __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 349, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
              __Pyx_GOTREF(__pyx_t_3);
            } else
            #endif
            #if CYTHON_FAST_PYCCALL
            if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_13, __pyx_v_R, __pyx_v_k};
              __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 349, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
              __Pyx_GOTREF(__pyx_t_3);
            } else
            #endif
            {
              __pyx_t_1 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 349, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_1);
              if (__pyx_t_13) {
                __Pyx_GIVEREF(__pyx_t_13); PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_13); __pyx_t_13 = NULL;
              }
              __Pyx_INCREF(__pyx_v_R);
              __Pyx_GIVEREF(__pyx_v_R);
              PyTuple_SET_ITEM(__pyx_t_1, 0+__pyx_t_6, __pyx_v_R);
              __Pyx_INCREF(__pyx_v_k);
              __Pyx_GIVEREF(__pyx_v_k);
              PyTuple_SET_ITEM(__pyx_t_1, 1+__pyx_t_6, __pyx_v_k);
              __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_1, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 349, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_3);
              __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
            }
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp3, __pyx_t_3); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 349, __pyx_L1_error)
            __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
# 11454 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 11464 "example1.c"
          __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 350, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_7));
          __pyx_t_7 = 0;
# 11476 "example1.c"
          __pyx_t_7 = __pyx_v_tmp3; __Pyx_INCREF(__pyx_t_7); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_7)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_3 = PyList_GET_ITEM(__pyx_t_7, __pyx_t_12); __Pyx_INCREF(__pyx_t_3); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 351, __pyx_L1_error)
            #else
            __pyx_t_3 = PySequence_ITEM(__pyx_t_7, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 351, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_3);
            __pyx_t_3 = 0;
# 11495 "example1.c"
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 352, __pyx_L1_error)
# 11504 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 11514 "example1.c"
          __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 353, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF_SET(__pyx_v_tmp3, ((PyObject*)__pyx_t_7));
          __pyx_t_7 = 0;
# 11526 "example1.c"
          __pyx_t_7 = __pyx_v_tmp2; __Pyx_INCREF(__pyx_t_7); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_7)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_3 = PyList_GET_ITEM(__pyx_t_7, __pyx_t_12); __Pyx_INCREF(__pyx_t_3); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 354, __pyx_L1_error)
            #else
            __pyx_t_3 = PySequence_ITEM(__pyx_t_7, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 354, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_3);
            __pyx_t_3 = 0;
# 11545 "example1.c"
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_L, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 355, __pyx_L1_error)
# 11554 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 11564 "example1.c"
        }
        __pyx_L15:;
# 11574 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    }
    __pyx_L5:;
# 11586 "example1.c"
    __pyx_t_2 = __Pyx_PyInt_AddObjC(__pyx_v_j, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 357, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF_SET(__pyx_v_j, __pyx_t_2);
    __pyx_t_2 = 0;
  }
# 11599 "example1.c"
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 358, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_Hyperbolic_distance = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;
# 11611 "example1.c"
  __pyx_t_2 = __pyx_v_nodes_in_DT; __Pyx_INCREF(__pyx_t_2); __pyx_t_9 = 0;
  for (;;) {
    if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_2)) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_7 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_7); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 359, __pyx_L1_error)
    #else
    __pyx_t_7 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 359, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    #endif
    __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_7);
    __pyx_t_7 = 0;
# 11630 "example1.c"
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Cartesian_radial_hyperbolic_dist); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 360, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_5 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
      }
    }
    __pyx_t_7 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_5, __pyx_v_k) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_v_k);
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 360, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_Hyperbolic_distance, __pyx_t_7); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 360, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 11657 "example1.c"
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
# 11667 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_Hyperbolic_distance);
  __pyx_r = __pyx_v_Hyperbolic_distance;
  goto __pyx_L0;
# 11681 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_AddTraceback("example1.Hyperbolic_Distance_Gamma0", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_T);
  __Pyx_XDECREF(__pyx_v_R);
  __Pyx_XDECREF(__pyx_v_L);
  __Pyx_XDECREF(__pyx_v_tmp1);
  __Pyx_XDECREF(__pyx_v_tmp2);
  __Pyx_XDECREF(__pyx_v_nodes_in_DT);
  __Pyx_XDECREF(__pyx_v_j);
  __Pyx_XDECREF(__pyx_v_z);
  __Pyx_XDECREF(__pyx_v_i);
  __Pyx_XDECREF(__pyx_v_k);
  __Pyx_XDECREF(__pyx_v_tmp3);
  __Pyx_XDECREF(__pyx_v_Hyperbolic_distance);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 11717 "example1.c"
static PyObject *__pyx_pw_8example1_53Exp_negative_Hyperbolic_Distance_Gamma0(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_53Exp_negative_Hyperbolic_Distance_Gamma0 = {"Exp_negative_Hyperbolic_Distance_Gamma0", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_53Exp_negative_Hyperbolic_Distance_Gamma0, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_53Exp_negative_Hyperbolic_Distance_Gamma0(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_Lambda = 0;
  PyObject *__pyx_v_m = 0;
  PyObject *__pyx_v_N = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Exp_negative_Hyperbolic_Distance_Gamma0 (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_Lambda,&__pyx_n_s_m,&__pyx_n_s_N,0};
    PyObject* values[3] = {0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_Lambda)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_m)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Exp_negative_Hyperbolic_Distance_Gamma0", 1, 3, 3, 1); __PYX_ERR(0, 364, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case 2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_N)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Exp_negative_Hyperbolic_Distance_Gamma0", 1, 3, 3, 2); __PYX_ERR(0, 364, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "Exp_negative_Hyperbolic_Distance_Gamma0") < 0)) __PYX_ERR(0, 364, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_Lambda = values[0];
    __pyx_v_m = values[1];
    __pyx_v_N = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("Exp_negative_Hyperbolic_Distance_Gamma0", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 364, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.Exp_negative_Hyperbolic_Distance_Gamma0", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_52Exp_negative_Hyperbolic_Distance_Gamma0(__pyx_self, __pyx_v_Lambda, __pyx_v_m, __pyx_v_N);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_52Exp_negative_Hyperbolic_Distance_Gamma0(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_Lambda, PyObject *__pyx_v_m, PyObject *__pyx_v_N) {
  PyObject *__pyx_v_T = NULL;
  double __pyx_v_theta;
  PyObject *__pyx_v_R = NULL;
  PyObject *__pyx_v_L = NULL;
  PyObject *__pyx_v_tmp1 = NULL;
  PyObject *__pyx_v_tmp2 = NULL;
  PyObject *__pyx_v_nodes_in_DT = NULL;
  PyObject *__pyx_v_j = NULL;
  PyObject *__pyx_v_z = NULL;
  PyObject *__pyx_v_i = NULL;
  PyObject *__pyx_v_k = NULL;
  PyObject *__pyx_v_tmp3 = NULL;
  PyObject *__pyx_v_Hyperbolic_distance = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  double __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  Py_ssize_t __pyx_t_9;
  PyObject *(*__pyx_t_10)(PyObject *);
  int __pyx_t_11;
  Py_ssize_t __pyx_t_12;
  PyObject *__pyx_t_13 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Exp_negative_Hyperbolic_Distance_Gamma0", 0);
# 11833 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_operator_T); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 365, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_v_Lambda) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_Lambda);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 365, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_T = __pyx_t_1;
  __pyx_t_1 = 0;
# 11860 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_math); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 366, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_pi); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 366, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyNumber_Divide(__pyx_t_2, __pyx_v_m); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 366, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_4 = __Pyx_PyObject_AsDouble(__pyx_t_1); if (unlikely(__pyx_t_4 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 366, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_theta = __pyx_t_4;
# 11879 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_operator_R); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 367, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyFloat_FromDouble(__pyx_v_theta); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 367, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_5, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 367, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_R = __pyx_t_1;
  __pyx_t_1 = 0;
# 11909 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Tz); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 368, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyList_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 368, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_3, 0, __pyx_int_0);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_3, 1, __pyx_int_0);
  __pyx_t_5 = NULL;
  __pyx_t_6 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_6 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_3};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 368, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_3};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 368, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  } else
  #endif
  {
    __pyx_t_7 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 368, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    if (__pyx_t_5) {
      __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_5); __pyx_t_5 = NULL;
    }
    __Pyx_INCREF(__pyx_v_T);
    __Pyx_GIVEREF(__pyx_v_T);
    PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_6, __pyx_v_T);
    __Pyx_GIVEREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_6, __pyx_t_3);
    __pyx_t_3 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_7, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 368, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 368, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __pyx_t_1 = 0;
  __pyx_v_L = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;
# 11981 "example1.c"
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 369, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_tmp1 = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;
# 11993 "example1.c"
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 370, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_tmp2 = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;
# 12005 "example1.c"
  __pyx_t_2 = PyList_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 371, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_int_0);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_int_0);
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 371, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_2);
  __pyx_t_2 = 0;
  __pyx_v_nodes_in_DT = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 12028 "example1.c"
  __Pyx_INCREF(__pyx_int_1);
  __pyx_v_j = __pyx_int_1;
# 12038 "example1.c"
  while (1) {
    __pyx_t_1 = PyObject_RichCompare(__pyx_v_j, __pyx_v_N, Py_LE); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 373, __pyx_L1_error)
    __pyx_t_8 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 373, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (!__pyx_t_8) break;
# 12051 "example1.c"
    __pyx_t_1 = __Pyx_PyInt_EqObjC(__pyx_v_j, __pyx_int_1, 1, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 375, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_8 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 375, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (__pyx_t_8) {
# 12064 "example1.c"
      __pyx_t_1 = __Pyx_GetItemInt_List(__pyx_v_L, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 376, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_XDECREF_SET(__pyx_v_z, __pyx_t_1);
      __pyx_t_1 = 0;
# 12076 "example1.c"
      __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 377, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_1));
      __pyx_t_1 = 0;
# 12088 "example1.c"
      __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 378, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF_SET(__pyx_v_tmp2, ((PyObject*)__pyx_t_1));
      __pyx_t_1 = 0;
# 12100 "example1.c"
      __pyx_t_1 = PyNumber_Multiply(__pyx_int_2, __pyx_v_m); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 379, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_2 = __Pyx_PyInt_SubtractObjC(__pyx_t_1, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 379, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 379, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (likely(PyList_CheckExact(__pyx_t_1)) || PyTuple_CheckExact(__pyx_t_1)) {
        __pyx_t_2 = __pyx_t_1; __Pyx_INCREF(__pyx_t_2); __pyx_t_9 = 0;
        __pyx_t_10 = NULL;
      } else {
        __pyx_t_9 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 379, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_10 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 379, __pyx_L1_error)
      }
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      for (;;) {
        if (likely(!__pyx_t_10)) {
          if (likely(PyList_CheckExact(__pyx_t_2))) {
            if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_1 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_1); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 379, __pyx_L1_error)
            #else
            __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 379, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            #endif
          } else {
            if (__pyx_t_9 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_1 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_1); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 379, __pyx_L1_error)
            #else
            __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 379, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            #endif
          }
        } else {
          __pyx_t_1 = __pyx_t_10(__pyx_t_2);
          if (unlikely(!__pyx_t_1)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 379, __pyx_L1_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_1);
        }
        __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_1);
        __pyx_t_1 = 0;
# 12158 "example1.c"
        __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_Tz); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 380, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_3 = NULL;
        __pyx_t_6 = 0;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_7);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_7, function);
            __pyx_t_6 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_7)) {
          PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_R, __pyx_v_z};
          __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 380, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_GOTREF(__pyx_t_1);
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_7)) {
          PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_R, __pyx_v_z};
          __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 380, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_GOTREF(__pyx_t_1);
        } else
        #endif
        {
          __pyx_t_5 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 380, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_5);
          if (__pyx_t_3) {
            __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3); __pyx_t_3 = NULL;
          }
          __Pyx_INCREF(__pyx_v_R);
          __Pyx_GIVEREF(__pyx_v_R);
          PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_6, __pyx_v_R);
          __Pyx_INCREF(__pyx_v_z);
          __Pyx_GIVEREF(__pyx_v_z);
          PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_6, __pyx_v_z);
          __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 380, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        }
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_DECREF_SET(__pyx_v_z, __pyx_t_1);
        __pyx_t_1 = 0;
# 12215 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 381, __pyx_L1_error)
# 12224 "example1.c"
        __pyx_t_1 = __Pyx_PyInt_SubtractObjC(__pyx_v_m, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 382, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_7 = PyObject_RichCompare(__pyx_v_i, __pyx_t_1, Py_NE); __Pyx_XGOTREF(__pyx_t_7); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 382, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_8 = __Pyx_PyObject_IsTrue(__pyx_t_7); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 382, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (__pyx_t_8) {
# 12239 "example1.c"
          __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp2, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 383, __pyx_L1_error)
# 12248 "example1.c"
          goto __pyx_L8;
        }
# 12258 "example1.c"
                 {
          __pyx_t_7 = __Pyx_GetItemInt_List(__pyx_v_L, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 385, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp2, __pyx_t_7); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 385, __pyx_L1_error)
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        }
        __pyx_L8:;
# 12273 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
# 12283 "example1.c"
      __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 386, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF_SET(__pyx_v_L, ((PyObject*)__pyx_t_2));
      __pyx_t_2 = 0;
# 12295 "example1.c"
      __pyx_t_2 = __pyx_v_tmp2; __Pyx_INCREF(__pyx_t_2); __pyx_t_9 = 0;
      for (;;) {
        if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_7 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_7); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 387, __pyx_L1_error)
        #else
        __pyx_t_7 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 387, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_7);
        #endif
        __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_7);
        __pyx_t_7 = 0;
# 12314 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_L, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 388, __pyx_L1_error)
# 12323 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
# 12333 "example1.c"
      __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_Tz); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 389, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 389, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_INCREF(__pyx_int_0);
      __Pyx_GIVEREF(__pyx_int_0);
      PyList_SET_ITEM(__pyx_t_1, 0, __pyx_int_0);
      __Pyx_INCREF(__pyx_int_0);
      __Pyx_GIVEREF(__pyx_int_0);
      PyList_SET_ITEM(__pyx_t_1, 1, __pyx_int_0);
      __pyx_t_5 = NULL;
      __pyx_t_6 = 0;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
        __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_7);
        if (likely(__pyx_t_5)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
          __Pyx_INCREF(__pyx_t_5);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_7, function);
          __pyx_t_6 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_7)) {
        PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_1};
        __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 389, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_7)) {
        PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_1};
        __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 389, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      } else
      #endif
      {
        __pyx_t_3 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 389, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        if (__pyx_t_5) {
          __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_5); __pyx_t_5 = NULL;
        }
        __Pyx_INCREF(__pyx_v_T);
        __Pyx_GIVEREF(__pyx_v_T);
        PyTuple_SET_ITEM(__pyx_t_3, 0+__pyx_t_6, __pyx_v_T);
        __Pyx_GIVEREF(__pyx_t_1);
        PyTuple_SET_ITEM(__pyx_t_3, 1+__pyx_t_6, __pyx_t_1);
        __pyx_t_1 = 0;
        __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_3, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 389, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      }
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __pyx_t_7 = PyList_New(1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 389, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_GIVEREF(__pyx_t_2);
      PyList_SET_ITEM(__pyx_t_7, 0, __pyx_t_2);
      __pyx_t_2 = 0;
      __Pyx_DECREF_SET(__pyx_v_nodes_in_DT, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 12405 "example1.c"
      goto __pyx_L5;
    }
# 12415 "example1.c"
             {
      __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 393, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF_SET(__pyx_v_nodes_in_DT, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 12428 "example1.c"
      __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 394, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 12440 "example1.c"
      __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 395, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF_SET(__pyx_v_tmp2, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 12452 "example1.c"
      __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 396, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_XDECREF_SET(__pyx_v_tmp3, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 12464 "example1.c"
      __pyx_t_7 = __pyx_v_L; __Pyx_INCREF(__pyx_t_7); __pyx_t_9 = 0;
      for (;;) {
        if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_7)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyList_GET_ITEM(__pyx_t_7, __pyx_t_9); __Pyx_INCREF(__pyx_t_2); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 397, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_7, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 397, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
        __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_2);
        __pyx_t_2 = 0;
# 12483 "example1.c"
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Tz); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 398, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_1 = NULL;
        __pyx_t_6 = 0;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
          __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_3);
          if (likely(__pyx_t_1)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
            __Pyx_INCREF(__pyx_t_1);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_3, function);
            __pyx_t_6 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_3)) {
          PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_T, __pyx_v_k};
          __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 398, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_GOTREF(__pyx_t_2);
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
          PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_T, __pyx_v_k};
          __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 398, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_GOTREF(__pyx_t_2);
        } else
        #endif
        {
          __pyx_t_5 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 398, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_5);
          if (__pyx_t_1) {
            __Pyx_GIVEREF(__pyx_t_1); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_1); __pyx_t_1 = NULL;
          }
          __Pyx_INCREF(__pyx_v_T);
          __Pyx_GIVEREF(__pyx_v_T);
          PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_6, __pyx_v_T);
          __Pyx_INCREF(__pyx_v_k);
          __Pyx_GIVEREF(__pyx_v_k);
          PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_6, __pyx_v_k);
          __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_5, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 398, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        }
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_XDECREF_SET(__pyx_v_z, __pyx_t_2);
        __pyx_t_2 = 0;
# 12540 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_nodes_in_DT, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 399, __pyx_L1_error)
# 12549 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 400, __pyx_L1_error)
# 12558 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp2, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 401, __pyx_L1_error)
# 12567 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 12577 "example1.c"
      __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 402, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF_SET(__pyx_v_L, ((PyObject*)__pyx_t_7));
      __pyx_t_7 = 0;
# 12589 "example1.c"
      __pyx_t_7 = PyNumber_Multiply(__pyx_int_2, __pyx_v_m); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 403, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_2 = __Pyx_PyInt_SubtractObjC(__pyx_t_7, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 403, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __pyx_t_7 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_t_2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 403, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (likely(PyList_CheckExact(__pyx_t_7)) || PyTuple_CheckExact(__pyx_t_7)) {
        __pyx_t_2 = __pyx_t_7; __Pyx_INCREF(__pyx_t_2); __pyx_t_9 = 0;
        __pyx_t_10 = NULL;
      } else {
        __pyx_t_9 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 403, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_10 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 403, __pyx_L1_error)
      }
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      for (;;) {
        if (likely(!__pyx_t_10)) {
          if (likely(PyList_CheckExact(__pyx_t_2))) {
            if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_7 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_7); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 403, __pyx_L1_error)
            #else
            __pyx_t_7 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 403, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_7);
            #endif
          } else {
            if (__pyx_t_9 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_7 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_7); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 403, __pyx_L1_error)
            #else
            __pyx_t_7 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 403, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_7);
            #endif
          }
        } else {
          __pyx_t_7 = __pyx_t_10(__pyx_t_2);
          if (unlikely(!__pyx_t_7)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 403, __pyx_L1_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_7);
        }
        __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_7);
        __pyx_t_7 = 0;
# 12647 "example1.c"
        __pyx_t_7 = __Pyx_PyInt_SubtractObjC(__pyx_v_m, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 404, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_3 = PyObject_RichCompare(__pyx_v_i, __pyx_t_7, Py_NE); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 404, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __pyx_t_8 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 404, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (__pyx_t_8) {
# 12662 "example1.c"
          __pyx_t_3 = __pyx_v_tmp1; __Pyx_INCREF(__pyx_t_3); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_3)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_7 = PyList_GET_ITEM(__pyx_t_3, __pyx_t_12); __Pyx_INCREF(__pyx_t_7); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 405, __pyx_L1_error)
            #else
            __pyx_t_7 = PySequence_ITEM(__pyx_t_3, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 405, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_7);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_7);
            __pyx_t_7 = 0;
# 12681 "example1.c"
            __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Tz); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 406, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __pyx_t_1 = NULL;
            __pyx_t_6 = 0;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
              __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_5);
              if (likely(__pyx_t_1)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
                __Pyx_INCREF(__pyx_t_1);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_5, function);
                __pyx_t_6 = 1;
              }
            }
            #if CYTHON_FAST_PYCALL
            if (PyFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_R, __pyx_v_k};
              __pyx_t_7 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 406, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
              __Pyx_GOTREF(__pyx_t_7);
            } else
            #endif
            #if CYTHON_FAST_PYCCALL
            if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_R, __pyx_v_k};
              __pyx_t_7 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 406, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
              __Pyx_GOTREF(__pyx_t_7);
            } else
            #endif
            {
              __pyx_t_13 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 406, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_13);
              if (__pyx_t_1) {
                __Pyx_GIVEREF(__pyx_t_1); PyTuple_SET_ITEM(__pyx_t_13, 0, __pyx_t_1); __pyx_t_1 = NULL;
              }
              __Pyx_INCREF(__pyx_v_R);
              __Pyx_GIVEREF(__pyx_v_R);
              PyTuple_SET_ITEM(__pyx_t_13, 0+__pyx_t_6, __pyx_v_R);
              __Pyx_INCREF(__pyx_v_k);
              __Pyx_GIVEREF(__pyx_v_k);
              PyTuple_SET_ITEM(__pyx_t_13, 1+__pyx_t_6, __pyx_v_k);
              __pyx_t_7 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_13, NULL); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 406, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_7);
              __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
            }
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp3, __pyx_t_7); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 406, __pyx_L1_error)
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 12738 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
# 12748 "example1.c"
          __pyx_t_3 = PyList_New(0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 407, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_3));
          __pyx_t_3 = 0;
# 12760 "example1.c"
          __pyx_t_3 = __pyx_v_tmp3; __Pyx_INCREF(__pyx_t_3); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_3)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_7 = PyList_GET_ITEM(__pyx_t_3, __pyx_t_12); __Pyx_INCREF(__pyx_t_7); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 408, __pyx_L1_error)
            #else
            __pyx_t_7 = PySequence_ITEM(__pyx_t_3, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 408, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_7);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_7);
            __pyx_t_7 = 0;
# 12779 "example1.c"
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 409, __pyx_L1_error)
# 12788 "example1.c"
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_L, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 410, __pyx_L1_error)
# 12797 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
# 12807 "example1.c"
          __pyx_t_3 = PyList_New(0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 411, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF_SET(__pyx_v_tmp3, ((PyObject*)__pyx_t_3));
          __pyx_t_3 = 0;
# 12819 "example1.c"
          goto __pyx_L15;
        }
# 12829 "example1.c"
        __pyx_t_3 = __Pyx_PyInt_SubtractObjC(__pyx_v_m, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 412, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_7 = PyObject_RichCompare(__pyx_v_i, __pyx_t_3, Py_EQ); __Pyx_XGOTREF(__pyx_t_7); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 412, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_8 = __Pyx_PyObject_IsTrue(__pyx_t_7); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 412, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (__pyx_t_8) {
# 12844 "example1.c"
          __pyx_t_7 = __pyx_v_tmp1; __Pyx_INCREF(__pyx_t_7); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_7)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_3 = PyList_GET_ITEM(__pyx_t_7, __pyx_t_12); __Pyx_INCREF(__pyx_t_3); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 413, __pyx_L1_error)
            #else
            __pyx_t_3 = PySequence_ITEM(__pyx_t_7, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 413, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_3);
            __pyx_t_3 = 0;
# 12863 "example1.c"
            __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Tz); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 414, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __pyx_t_13 = NULL;
            __pyx_t_6 = 0;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
              __pyx_t_13 = PyMethod_GET_SELF(__pyx_t_5);
              if (likely(__pyx_t_13)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
                __Pyx_INCREF(__pyx_t_13);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_5, function);
                __pyx_t_6 = 1;
              }
            }
            #if CYTHON_FAST_PYCALL
            if (PyFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_13, __pyx_v_R, __pyx_v_k};
              __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 414, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
              __Pyx_GOTREF(__pyx_t_3);
            } else
            #endif
            #if CYTHON_FAST_PYCCALL
            if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_13, __pyx_v_R, __pyx_v_k};
              __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 414, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
              __Pyx_GOTREF(__pyx_t_3);
            } else
            #endif
            {
              __pyx_t_1 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 414, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_1);
              if (__pyx_t_13) {
                __Pyx_GIVEREF(__pyx_t_13); PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_13); __pyx_t_13 = NULL;
              }
              __Pyx_INCREF(__pyx_v_R);
              __Pyx_GIVEREF(__pyx_v_R);
              PyTuple_SET_ITEM(__pyx_t_1, 0+__pyx_t_6, __pyx_v_R);
              __Pyx_INCREF(__pyx_v_k);
              __Pyx_GIVEREF(__pyx_v_k);
              PyTuple_SET_ITEM(__pyx_t_1, 1+__pyx_t_6, __pyx_v_k);
              __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_1, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 414, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_3);
              __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
            }
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp3, __pyx_t_3); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 414, __pyx_L1_error)
            __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
# 12920 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 12930 "example1.c"
          __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 415, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_7));
          __pyx_t_7 = 0;
# 12942 "example1.c"
          __pyx_t_7 = __pyx_v_tmp3; __Pyx_INCREF(__pyx_t_7); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_7)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_3 = PyList_GET_ITEM(__pyx_t_7, __pyx_t_12); __Pyx_INCREF(__pyx_t_3); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 416, __pyx_L1_error)
            #else
            __pyx_t_3 = PySequence_ITEM(__pyx_t_7, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 416, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_3);
            __pyx_t_3 = 0;
# 12961 "example1.c"
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 417, __pyx_L1_error)
# 12970 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 12980 "example1.c"
          __pyx_t_7 = PyList_New(0); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 418, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF_SET(__pyx_v_tmp3, ((PyObject*)__pyx_t_7));
          __pyx_t_7 = 0;
# 12992 "example1.c"
          __pyx_t_7 = __pyx_v_tmp2; __Pyx_INCREF(__pyx_t_7); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_7)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_3 = PyList_GET_ITEM(__pyx_t_7, __pyx_t_12); __Pyx_INCREF(__pyx_t_3); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 419, __pyx_L1_error)
            #else
            __pyx_t_3 = PySequence_ITEM(__pyx_t_7, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 419, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_3);
            __pyx_t_3 = 0;
# 13011 "example1.c"
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_L, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 420, __pyx_L1_error)
# 13020 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 13030 "example1.c"
        }
        __pyx_L15:;
# 13040 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    }
    __pyx_L5:;
# 13052 "example1.c"
    __pyx_t_2 = __Pyx_PyInt_AddObjC(__pyx_v_j, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 422, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF_SET(__pyx_v_j, __pyx_t_2);
    __pyx_t_2 = 0;
  }
# 13065 "example1.c"
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 423, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_Hyperbolic_distance = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;
# 13077 "example1.c"
  __pyx_t_2 = __pyx_v_nodes_in_DT; __Pyx_INCREF(__pyx_t_2); __pyx_t_9 = 0;
  for (;;) {
    if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_2)) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_7 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_9); __Pyx_INCREF(__pyx_t_7); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 424, __pyx_L1_error)
    #else
    __pyx_t_7 = PySequence_ITEM(__pyx_t_2, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 424, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    #endif
    __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_7);
    __pyx_t_7 = 0;
# 13096 "example1.c"
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_math); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 425, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_exp); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 425, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Cartesian_radial_hyperbolic_dist); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 425, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_13 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
      __pyx_t_13 = PyMethod_GET_SELF(__pyx_t_1);
      if (likely(__pyx_t_13)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
        __Pyx_INCREF(__pyx_t_13);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_1, function);
      }
    }
    __pyx_t_3 = (__pyx_t_13) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_13, __pyx_v_k) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_v_k);
    __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 425, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyNumber_Negative(__pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 425, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_3)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_3);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_7 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_3, __pyx_t_1) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_1);
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 425, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_Hyperbolic_distance, __pyx_t_7); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 425, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
# 13147 "example1.c"
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
# 13157 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_Hyperbolic_distance);
  __pyx_r = __pyx_v_Hyperbolic_distance;
  goto __pyx_L0;
# 13171 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_AddTraceback("example1.Exp_negative_Hyperbolic_Distance_Gamma0", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_T);
  __Pyx_XDECREF(__pyx_v_R);
  __Pyx_XDECREF(__pyx_v_L);
  __Pyx_XDECREF(__pyx_v_tmp1);
  __Pyx_XDECREF(__pyx_v_tmp2);
  __Pyx_XDECREF(__pyx_v_nodes_in_DT);
  __Pyx_XDECREF(__pyx_v_j);
  __Pyx_XDECREF(__pyx_v_z);
  __Pyx_XDECREF(__pyx_v_i);
  __Pyx_XDECREF(__pyx_v_k);
  __Pyx_XDECREF(__pyx_v_tmp3);
  __Pyx_XDECREF(__pyx_v_Hyperbolic_distance);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 13207 "example1.c"
static PyObject *__pyx_pw_8example1_55Improved_Exp_negative_Hyperbolic_Distance_Gamma0(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_55Improved_Exp_negative_Hyperbolic_Distance_Gamma0 = {"Improved_Exp_negative_Hyperbolic_Distance_Gamma0", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_55Improved_Exp_negative_Hyperbolic_Distance_Gamma0, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_55Improved_Exp_negative_Hyperbolic_Distance_Gamma0(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_Lambda = 0;
  PyObject *__pyx_v_m = 0;
  PyObject *__pyx_v_N = 0;
  PyObject *__pyx_v_L = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("Improved_Exp_negative_Hyperbolic_Distance_Gamma0 (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_Lambda,&__pyx_n_s_m,&__pyx_n_s_N,&__pyx_n_s_L,0};
    PyObject* values[4] = {0,0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case 3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_Lambda)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_m)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Improved_Exp_negative_Hyperbolic_Distance_Gamma0", 1, 4, 4, 1); __PYX_ERR(0, 429, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case 2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_N)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Improved_Exp_negative_Hyperbolic_Distance_Gamma0", 1, 4, 4, 2); __PYX_ERR(0, 429, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case 3:
        if (likely((values[3] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_L)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("Improved_Exp_negative_Hyperbolic_Distance_Gamma0", 1, 4, 4, 3); __PYX_ERR(0, 429, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "Improved_Exp_negative_Hyperbolic_Distance_Gamma0") < 0)) __PYX_ERR(0, 429, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 4) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
      values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
    }
    __pyx_v_Lambda = values[0];
    __pyx_v_m = values[1];
    __pyx_v_N = values[2];
    __pyx_v_L = values[3];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("Improved_Exp_negative_Hyperbolic_Distance_Gamma0", 1, 4, 4, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 429, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.Improved_Exp_negative_Hyperbolic_Distance_Gamma0", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_54Improved_Exp_negative_Hyperbolic_Distance_Gamma0(__pyx_self, __pyx_v_Lambda, __pyx_v_m, __pyx_v_N, __pyx_v_L);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_54Improved_Exp_negative_Hyperbolic_Distance_Gamma0(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_Lambda, PyObject *__pyx_v_m, PyObject *__pyx_v_N, PyObject *__pyx_v_L) {
  PyObject *__pyx_v_T = NULL;
  double __pyx_v_theta;
  PyObject *__pyx_v_R = NULL;
  PyObject *__pyx_v_j = NULL;
  PyObject *__pyx_v_tmp1 = NULL;
  PyObject *__pyx_v_tmp2 = NULL;
  PyObject *__pyx_v_nodes_in_DT = NULL;
  PyObject *__pyx_v_z = NULL;
  PyObject *__pyx_v_i = NULL;
  PyObject *__pyx_v_k = NULL;
  PyObject *__pyx_v_tmp3 = NULL;
  PyObject *__pyx_v_Hyperbolic_distance = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  double __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  Py_ssize_t __pyx_t_6;
  int __pyx_t_7;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  PyObject *(*__pyx_t_10)(PyObject *);
  int __pyx_t_11;
  Py_ssize_t __pyx_t_12;
  PyObject *__pyx_t_13 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("Improved_Exp_negative_Hyperbolic_Distance_Gamma0", 0);
  __Pyx_INCREF(__pyx_v_L);
# 13334 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_operator_T); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 431, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_v_Lambda) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_Lambda);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 431, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_T = __pyx_t_1;
  __pyx_t_1 = 0;
# 13361 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_math); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 432, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_pi); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 432, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyNumber_Divide(__pyx_t_2, __pyx_v_m); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 432, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_4 = __Pyx_PyObject_AsDouble(__pyx_t_1); if (unlikely(__pyx_t_4 == ((double)((double)-1)) && PyErr_Occurred())) __PYX_ERR(0, 432, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_theta = __pyx_t_4;
# 13380 "example1.c"
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_operator_R); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 433, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyFloat_FromDouble(__pyx_v_theta); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 433, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_5, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 433, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_R = __pyx_t_1;
  __pyx_t_1 = 0;
# 13410 "example1.c"
  __pyx_t_6 = PyObject_Length(__pyx_v_L); if (unlikely(__pyx_t_6 == ((Py_ssize_t)-1))) __PYX_ERR(0, 434, __pyx_L1_error)
  __pyx_t_7 = ((__pyx_t_6 == 0) != 0);
  if (__pyx_t_7) {
# 13421 "example1.c"
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Tz); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 435, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_3 = PyList_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 435, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_INCREF(__pyx_int_0);
    __Pyx_GIVEREF(__pyx_int_0);
    PyList_SET_ITEM(__pyx_t_3, 0, __pyx_int_0);
    __Pyx_INCREF(__pyx_int_0);
    __Pyx_GIVEREF(__pyx_int_0);
    PyList_SET_ITEM(__pyx_t_3, 1, __pyx_int_0);
    __pyx_t_5 = NULL;
    __pyx_t_8 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
        __pyx_t_8 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_2)) {
      PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_3};
      __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 435, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
      PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_3};
      __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 435, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    } else
    #endif
    {
      __pyx_t_9 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 435, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      if (__pyx_t_5) {
        __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_5); __pyx_t_5 = NULL;
      }
      __Pyx_INCREF(__pyx_v_T);
      __Pyx_GIVEREF(__pyx_v_T);
      PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_8, __pyx_v_T);
      __Pyx_GIVEREF(__pyx_t_3);
      PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_8, __pyx_t_3);
      __pyx_t_3 = 0;
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_9, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 435, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    }
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 435, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_GIVEREF(__pyx_t_1);
    PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
    __pyx_t_1 = 0;
    __Pyx_DECREF_SET(__pyx_v_L, __pyx_t_2);
    __pyx_t_2 = 0;
# 13493 "example1.c"
    __Pyx_INCREF(__pyx_int_1);
    __pyx_v_j = __pyx_int_1;
# 13503 "example1.c"
    goto __pyx_L3;
  }
# 13513 "example1.c"
           {
    __Pyx_INCREF(__pyx_v_N);
    __pyx_v_j = __pyx_v_N;
  }
  __pyx_L3:;
# 13526 "example1.c"
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 439, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_tmp1 = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;
# 13538 "example1.c"
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 440, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_tmp2 = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;
# 13550 "example1.c"
  __pyx_t_2 = PyList_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 441, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_int_0);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_int_0);
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 441, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_2);
  __pyx_t_2 = 0;
  __pyx_v_nodes_in_DT = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
# 13573 "example1.c"
  while (1) {
    __pyx_t_1 = PyObject_RichCompare(__pyx_v_j, __pyx_v_N, Py_LE); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 443, __pyx_L1_error)
    __pyx_t_7 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 443, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (!__pyx_t_7) break;
# 13586 "example1.c"
    __pyx_t_1 = __Pyx_PyInt_EqObjC(__pyx_v_j, __pyx_int_1, 1, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 445, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_7 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 445, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (__pyx_t_7) {
# 13599 "example1.c"
      __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_L, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 446, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_XDECREF_SET(__pyx_v_z, __pyx_t_1);
      __pyx_t_1 = 0;
# 13611 "example1.c"
      __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 447, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_1));
      __pyx_t_1 = 0;
# 13623 "example1.c"
      __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 448, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF_SET(__pyx_v_tmp2, ((PyObject*)__pyx_t_1));
      __pyx_t_1 = 0;
# 13635 "example1.c"
      __pyx_t_1 = PyNumber_Multiply(__pyx_int_2, __pyx_v_m); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 449, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_2 = __Pyx_PyInt_SubtractObjC(__pyx_t_1, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 449, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 449, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (likely(PyList_CheckExact(__pyx_t_1)) || PyTuple_CheckExact(__pyx_t_1)) {
        __pyx_t_2 = __pyx_t_1; __Pyx_INCREF(__pyx_t_2); __pyx_t_6 = 0;
        __pyx_t_10 = NULL;
      } else {
        __pyx_t_6 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 449, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_10 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 449, __pyx_L1_error)
      }
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      for (;;) {
        if (likely(!__pyx_t_10)) {
          if (likely(PyList_CheckExact(__pyx_t_2))) {
            if (__pyx_t_6 >= PyList_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_1 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_6); __Pyx_INCREF(__pyx_t_1); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 449, __pyx_L1_error)
            #else
            __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 449, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            #endif
          } else {
            if (__pyx_t_6 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_1 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_6); __Pyx_INCREF(__pyx_t_1); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 449, __pyx_L1_error)
            #else
            __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 449, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            #endif
          }
        } else {
          __pyx_t_1 = __pyx_t_10(__pyx_t_2);
          if (unlikely(!__pyx_t_1)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 449, __pyx_L1_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_1);
        }
        __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_1);
        __pyx_t_1 = 0;
# 13693 "example1.c"
        __Pyx_GetModuleGlobalName(__pyx_t_9, __pyx_n_s_Tz); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 450, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_9);
        __pyx_t_3 = NULL;
        __pyx_t_8 = 0;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_9))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_9);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_9);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_9, function);
            __pyx_t_8 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_9)) {
          PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_R, __pyx_v_z};
          __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_9, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 450, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_GOTREF(__pyx_t_1);
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_9)) {
          PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_R, __pyx_v_z};
          __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_9, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 450, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_GOTREF(__pyx_t_1);
        } else
        #endif
        {
          __pyx_t_5 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 450, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_5);
          if (__pyx_t_3) {
            __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3); __pyx_t_3 = NULL;
          }
          __Pyx_INCREF(__pyx_v_R);
          __Pyx_GIVEREF(__pyx_v_R);
          PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_8, __pyx_v_R);
          __Pyx_INCREF(__pyx_v_z);
          __Pyx_GIVEREF(__pyx_v_z);
          PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_8, __pyx_v_z);
          __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_9, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 450, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        }
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
        __Pyx_DECREF_SET(__pyx_v_z, __pyx_t_1);
        __pyx_t_1 = 0;
# 13750 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 451, __pyx_L1_error)
# 13759 "example1.c"
        __pyx_t_1 = __Pyx_PyInt_SubtractObjC(__pyx_v_m, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 452, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_9 = PyObject_RichCompare(__pyx_v_i, __pyx_t_1, Py_NE); __Pyx_XGOTREF(__pyx_t_9); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 452, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_7 = __Pyx_PyObject_IsTrue(__pyx_t_9); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 452, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
        if (__pyx_t_7) {
# 13774 "example1.c"
          __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp2, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 453, __pyx_L1_error)
# 13783 "example1.c"
          goto __pyx_L9;
        }
# 13793 "example1.c"
                 {
          __pyx_t_9 = __Pyx_GetItemInt(__pyx_v_L, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 455, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_9);
          __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp2, __pyx_t_9); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 455, __pyx_L1_error)
          __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
        }
        __pyx_L9:;
# 13808 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
# 13818 "example1.c"
      __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 456, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF_SET(__pyx_v_L, __pyx_t_2);
      __pyx_t_2 = 0;
# 13830 "example1.c"
      __pyx_t_2 = __pyx_v_tmp2; __Pyx_INCREF(__pyx_t_2); __pyx_t_6 = 0;
      for (;;) {
        if (__pyx_t_6 >= PyList_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_9 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_6); __Pyx_INCREF(__pyx_t_9); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 457, __pyx_L1_error)
        #else
        __pyx_t_9 = PySequence_ITEM(__pyx_t_2, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 457, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_9);
        #endif
        __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_9);
        __pyx_t_9 = 0;
# 13849 "example1.c"
        __pyx_t_11 = __Pyx_PyObject_Append(__pyx_v_L, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 458, __pyx_L1_error)
# 13858 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
# 13868 "example1.c"
      __Pyx_GetModuleGlobalName(__pyx_t_9, __pyx_n_s_Tz); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 459, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 459, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_INCREF(__pyx_int_0);
      __Pyx_GIVEREF(__pyx_int_0);
      PyList_SET_ITEM(__pyx_t_1, 0, __pyx_int_0);
      __Pyx_INCREF(__pyx_int_0);
      __Pyx_GIVEREF(__pyx_int_0);
      PyList_SET_ITEM(__pyx_t_1, 1, __pyx_int_0);
      __pyx_t_5 = NULL;
      __pyx_t_8 = 0;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_9))) {
        __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_9);
        if (likely(__pyx_t_5)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_9);
          __Pyx_INCREF(__pyx_t_5);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_9, function);
          __pyx_t_8 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_9)) {
        PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_1};
        __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_9, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 459, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_9)) {
        PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_T, __pyx_t_1};
        __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_9, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 459, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      } else
      #endif
      {
        __pyx_t_3 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 459, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        if (__pyx_t_5) {
          __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_5); __pyx_t_5 = NULL;
        }
        __Pyx_INCREF(__pyx_v_T);
        __Pyx_GIVEREF(__pyx_v_T);
        PyTuple_SET_ITEM(__pyx_t_3, 0+__pyx_t_8, __pyx_v_T);
        __Pyx_GIVEREF(__pyx_t_1);
        PyTuple_SET_ITEM(__pyx_t_3, 1+__pyx_t_8, __pyx_t_1);
        __pyx_t_1 = 0;
        __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_9, __pyx_t_3, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 459, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      }
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = PyList_New(1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 459, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_GIVEREF(__pyx_t_2);
      PyList_SET_ITEM(__pyx_t_9, 0, __pyx_t_2);
      __pyx_t_2 = 0;
      __Pyx_DECREF_SET(__pyx_v_nodes_in_DT, ((PyObject*)__pyx_t_9));
      __pyx_t_9 = 0;
# 13940 "example1.c"
      goto __pyx_L6;
    }
# 13950 "example1.c"
             {
      __pyx_t_9 = PyList_New(0); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 463, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF_SET(__pyx_v_nodes_in_DT, ((PyObject*)__pyx_t_9));
      __pyx_t_9 = 0;
# 13963 "example1.c"
      __pyx_t_9 = PyList_New(0); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 464, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_9));
      __pyx_t_9 = 0;
# 13975 "example1.c"
      __pyx_t_9 = PyList_New(0); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 465, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF_SET(__pyx_v_tmp2, ((PyObject*)__pyx_t_9));
      __pyx_t_9 = 0;
# 13987 "example1.c"
      __pyx_t_9 = PyList_New(0); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 466, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_XDECREF_SET(__pyx_v_tmp3, ((PyObject*)__pyx_t_9));
      __pyx_t_9 = 0;
# 13999 "example1.c"
      if (likely(PyList_CheckExact(__pyx_v_L)) || PyTuple_CheckExact(__pyx_v_L)) {
        __pyx_t_9 = __pyx_v_L; __Pyx_INCREF(__pyx_t_9); __pyx_t_6 = 0;
        __pyx_t_10 = NULL;
      } else {
        __pyx_t_6 = -1; __pyx_t_9 = PyObject_GetIter(__pyx_v_L); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 467, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_9);
        __pyx_t_10 = Py_TYPE(__pyx_t_9)->tp_iternext; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 467, __pyx_L1_error)
      }
      for (;;) {
        if (likely(!__pyx_t_10)) {
          if (likely(PyList_CheckExact(__pyx_t_9))) {
            if (__pyx_t_6 >= PyList_GET_SIZE(__pyx_t_9)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_2 = PyList_GET_ITEM(__pyx_t_9, __pyx_t_6); __Pyx_INCREF(__pyx_t_2); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 467, __pyx_L1_error)
            #else
            __pyx_t_2 = PySequence_ITEM(__pyx_t_9, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 467, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_2);
            #endif
          } else {
            if (__pyx_t_6 >= PyTuple_GET_SIZE(__pyx_t_9)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_9, __pyx_t_6); __Pyx_INCREF(__pyx_t_2); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 467, __pyx_L1_error)
            #else
            __pyx_t_2 = PySequence_ITEM(__pyx_t_9, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 467, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_2);
            #endif
          }
        } else {
          __pyx_t_2 = __pyx_t_10(__pyx_t_9);
          if (unlikely(!__pyx_t_2)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 467, __pyx_L1_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_2);
        }
        __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_2);
        __pyx_t_2 = 0;
# 14048 "example1.c"
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Tz); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 468, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_1 = NULL;
        __pyx_t_8 = 0;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
          __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_3);
          if (likely(__pyx_t_1)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
            __Pyx_INCREF(__pyx_t_1);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_3, function);
            __pyx_t_8 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_3)) {
          PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_T, __pyx_v_k};
          __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 468, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_GOTREF(__pyx_t_2);
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
          PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_T, __pyx_v_k};
          __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 468, __pyx_L1_error)
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_GOTREF(__pyx_t_2);
        } else
        #endif
        {
          __pyx_t_5 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 468, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_5);
          if (__pyx_t_1) {
            __Pyx_GIVEREF(__pyx_t_1); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_1); __pyx_t_1 = NULL;
          }
          __Pyx_INCREF(__pyx_v_T);
          __Pyx_GIVEREF(__pyx_v_T);
          PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_8, __pyx_v_T);
          __Pyx_INCREF(__pyx_v_k);
          __Pyx_GIVEREF(__pyx_v_k);
          PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_8, __pyx_v_k);
          __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_5, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 468, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        }
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_XDECREF_SET(__pyx_v_z, __pyx_t_2);
        __pyx_t_2 = 0;
# 14105 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_nodes_in_DT, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 469, __pyx_L1_error)
# 14114 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 470, __pyx_L1_error)
# 14123 "example1.c"
        __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp2, __pyx_v_z); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 471, __pyx_L1_error)
# 14132 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
# 14142 "example1.c"
      __pyx_t_9 = PyList_New(0); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 472, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF_SET(__pyx_v_L, __pyx_t_9);
      __pyx_t_9 = 0;
# 14154 "example1.c"
      __pyx_t_9 = PyNumber_Multiply(__pyx_int_2, __pyx_v_m); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 473, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __pyx_t_2 = __Pyx_PyInt_SubtractObjC(__pyx_t_9, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 473, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_t_2); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 473, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (likely(PyList_CheckExact(__pyx_t_9)) || PyTuple_CheckExact(__pyx_t_9)) {
        __pyx_t_2 = __pyx_t_9; __Pyx_INCREF(__pyx_t_2); __pyx_t_6 = 0;
        __pyx_t_10 = NULL;
      } else {
        __pyx_t_6 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_9); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 473, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_10 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 473, __pyx_L1_error)
      }
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      for (;;) {
        if (likely(!__pyx_t_10)) {
          if (likely(PyList_CheckExact(__pyx_t_2))) {
            if (__pyx_t_6 >= PyList_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_9 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_6); __Pyx_INCREF(__pyx_t_9); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 473, __pyx_L1_error)
            #else
            __pyx_t_9 = PySequence_ITEM(__pyx_t_2, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 473, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_9);
            #endif
          } else {
            if (__pyx_t_6 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_9 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_6); __Pyx_INCREF(__pyx_t_9); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 473, __pyx_L1_error)
            #else
            __pyx_t_9 = PySequence_ITEM(__pyx_t_2, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 473, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_9);
            #endif
          }
        } else {
          __pyx_t_9 = __pyx_t_10(__pyx_t_2);
          if (unlikely(!__pyx_t_9)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 473, __pyx_L1_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_9);
        }
        __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_9);
        __pyx_t_9 = 0;
# 14212 "example1.c"
        __pyx_t_9 = __Pyx_PyInt_SubtractObjC(__pyx_v_m, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 474, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_9);
        __pyx_t_3 = PyObject_RichCompare(__pyx_v_i, __pyx_t_9, Py_NE); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 474, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
        __pyx_t_7 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 474, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (__pyx_t_7) {
# 14227 "example1.c"
          __pyx_t_3 = __pyx_v_tmp1; __Pyx_INCREF(__pyx_t_3); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_3)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_9 = PyList_GET_ITEM(__pyx_t_3, __pyx_t_12); __Pyx_INCREF(__pyx_t_9); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 475, __pyx_L1_error)
            #else
            __pyx_t_9 = PySequence_ITEM(__pyx_t_3, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 475, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_9);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_9);
            __pyx_t_9 = 0;
# 14246 "example1.c"
            __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Tz); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 476, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __pyx_t_1 = NULL;
            __pyx_t_8 = 0;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
              __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_5);
              if (likely(__pyx_t_1)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
                __Pyx_INCREF(__pyx_t_1);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_5, function);
                __pyx_t_8 = 1;
              }
            }
            #if CYTHON_FAST_PYCALL
            if (PyFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_R, __pyx_v_k};
              __pyx_t_9 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 476, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
              __Pyx_GOTREF(__pyx_t_9);
            } else
            #endif
            #if CYTHON_FAST_PYCCALL
            if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_v_R, __pyx_v_k};
              __pyx_t_9 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 476, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
              __Pyx_GOTREF(__pyx_t_9);
            } else
            #endif
            {
              __pyx_t_13 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 476, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_13);
              if (__pyx_t_1) {
                __Pyx_GIVEREF(__pyx_t_1); PyTuple_SET_ITEM(__pyx_t_13, 0, __pyx_t_1); __pyx_t_1 = NULL;
              }
              __Pyx_INCREF(__pyx_v_R);
              __Pyx_GIVEREF(__pyx_v_R);
              PyTuple_SET_ITEM(__pyx_t_13, 0+__pyx_t_8, __pyx_v_R);
              __Pyx_INCREF(__pyx_v_k);
              __Pyx_GIVEREF(__pyx_v_k);
              PyTuple_SET_ITEM(__pyx_t_13, 1+__pyx_t_8, __pyx_v_k);
              __pyx_t_9 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_13, NULL); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 476, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_9);
              __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
            }
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp3, __pyx_t_9); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 476, __pyx_L1_error)
            __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
# 14303 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
# 14313 "example1.c"
          __pyx_t_3 = PyList_New(0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 477, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_3));
          __pyx_t_3 = 0;
# 14325 "example1.c"
          __pyx_t_3 = __pyx_v_tmp3; __Pyx_INCREF(__pyx_t_3); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_3)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_9 = PyList_GET_ITEM(__pyx_t_3, __pyx_t_12); __Pyx_INCREF(__pyx_t_9); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 478, __pyx_L1_error)
            #else
            __pyx_t_9 = PySequence_ITEM(__pyx_t_3, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 478, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_9);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_9);
            __pyx_t_9 = 0;
# 14344 "example1.c"
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 479, __pyx_L1_error)
# 14353 "example1.c"
            __pyx_t_11 = __Pyx_PyObject_Append(__pyx_v_L, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 480, __pyx_L1_error)
# 14362 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
# 14372 "example1.c"
          __pyx_t_3 = PyList_New(0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 481, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF_SET(__pyx_v_tmp3, ((PyObject*)__pyx_t_3));
          __pyx_t_3 = 0;
# 14384 "example1.c"
          goto __pyx_L16;
        }
# 14394 "example1.c"
        __pyx_t_3 = __Pyx_PyInt_SubtractObjC(__pyx_v_m, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 482, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_9 = PyObject_RichCompare(__pyx_v_i, __pyx_t_3, Py_EQ); __Pyx_XGOTREF(__pyx_t_9); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 482, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_7 = __Pyx_PyObject_IsTrue(__pyx_t_9); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 482, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
        if (__pyx_t_7) {
# 14409 "example1.c"
          __pyx_t_9 = __pyx_v_tmp1; __Pyx_INCREF(__pyx_t_9); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_9)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_3 = PyList_GET_ITEM(__pyx_t_9, __pyx_t_12); __Pyx_INCREF(__pyx_t_3); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 483, __pyx_L1_error)
            #else
            __pyx_t_3 = PySequence_ITEM(__pyx_t_9, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 483, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_3);
            __pyx_t_3 = 0;
# 14428 "example1.c"
            __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Tz); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 484, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __pyx_t_13 = NULL;
            __pyx_t_8 = 0;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
              __pyx_t_13 = PyMethod_GET_SELF(__pyx_t_5);
              if (likely(__pyx_t_13)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
                __Pyx_INCREF(__pyx_t_13);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_5, function);
                __pyx_t_8 = 1;
              }
            }
            #if CYTHON_FAST_PYCALL
            if (PyFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_13, __pyx_v_R, __pyx_v_k};
              __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 484, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
              __Pyx_GOTREF(__pyx_t_3);
            } else
            #endif
            #if CYTHON_FAST_PYCCALL
            if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
              PyObject *__pyx_temp[3] = {__pyx_t_13, __pyx_v_R, __pyx_v_k};
              __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 484, __pyx_L1_error)
              __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
              __Pyx_GOTREF(__pyx_t_3);
            } else
            #endif
            {
              __pyx_t_1 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 484, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_1);
              if (__pyx_t_13) {
                __Pyx_GIVEREF(__pyx_t_13); PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_13); __pyx_t_13 = NULL;
              }
              __Pyx_INCREF(__pyx_v_R);
              __Pyx_GIVEREF(__pyx_v_R);
              PyTuple_SET_ITEM(__pyx_t_1, 0+__pyx_t_8, __pyx_v_R);
              __Pyx_INCREF(__pyx_v_k);
              __Pyx_GIVEREF(__pyx_v_k);
              PyTuple_SET_ITEM(__pyx_t_1, 1+__pyx_t_8, __pyx_v_k);
              __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_1, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 484, __pyx_L1_error)
              __Pyx_GOTREF(__pyx_t_3);
              __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
            }
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp3, __pyx_t_3); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 484, __pyx_L1_error)
            __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
# 14485 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
# 14495 "example1.c"
          __pyx_t_9 = PyList_New(0); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 485, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_9);
          __Pyx_DECREF_SET(__pyx_v_tmp1, ((PyObject*)__pyx_t_9));
          __pyx_t_9 = 0;
# 14507 "example1.c"
          __pyx_t_9 = __pyx_v_tmp3; __Pyx_INCREF(__pyx_t_9); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_9)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_3 = PyList_GET_ITEM(__pyx_t_9, __pyx_t_12); __Pyx_INCREF(__pyx_t_3); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 486, __pyx_L1_error)
            #else
            __pyx_t_3 = PySequence_ITEM(__pyx_t_9, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 486, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_3);
            __pyx_t_3 = 0;
# 14526 "example1.c"
            __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp1, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 487, __pyx_L1_error)
# 14535 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
# 14545 "example1.c"
          __pyx_t_9 = PyList_New(0); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 488, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_9);
          __Pyx_DECREF_SET(__pyx_v_tmp3, ((PyObject*)__pyx_t_9));
          __pyx_t_9 = 0;
# 14557 "example1.c"
          __pyx_t_9 = __pyx_v_tmp2; __Pyx_INCREF(__pyx_t_9); __pyx_t_12 = 0;
          for (;;) {
            if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_9)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_3 = PyList_GET_ITEM(__pyx_t_9, __pyx_t_12); __Pyx_INCREF(__pyx_t_3); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 489, __pyx_L1_error)
            #else
            __pyx_t_3 = PySequence_ITEM(__pyx_t_9, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 489, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            #endif
            __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_3);
            __pyx_t_3 = 0;
# 14576 "example1.c"
            __pyx_t_11 = __Pyx_PyObject_Append(__pyx_v_L, __pyx_v_k); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 490, __pyx_L1_error)
# 14585 "example1.c"
          }
          __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
# 14595 "example1.c"
        }
        __pyx_L16:;
# 14605 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    }
    __pyx_L6:;
# 14617 "example1.c"
    __pyx_t_2 = __Pyx_PyInt_AddObjC(__pyx_v_j, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 492, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF_SET(__pyx_v_j, __pyx_t_2);
    __pyx_t_2 = 0;
  }
# 14630 "example1.c"
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 493, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_Hyperbolic_distance = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;
# 14642 "example1.c"
  __pyx_t_2 = __pyx_v_nodes_in_DT; __Pyx_INCREF(__pyx_t_2); __pyx_t_6 = 0;
  for (;;) {
    if (__pyx_t_6 >= PyList_GET_SIZE(__pyx_t_2)) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_9 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_6); __Pyx_INCREF(__pyx_t_9); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 494, __pyx_L1_error)
    #else
    __pyx_t_9 = PySequence_ITEM(__pyx_t_2, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 494, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    #endif
    __Pyx_XDECREF_SET(__pyx_v_k, __pyx_t_9);
    __pyx_t_9 = 0;
# 14661 "example1.c"
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_math); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 495, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_exp); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 495, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Cartesian_radial_hyperbolic_dist); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 495, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_13 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
      __pyx_t_13 = PyMethod_GET_SELF(__pyx_t_1);
      if (likely(__pyx_t_13)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
        __Pyx_INCREF(__pyx_t_13);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_1, function);
      }
    }
    __pyx_t_3 = (__pyx_t_13) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_13, __pyx_v_k) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_v_k);
    __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 495, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyNumber_Negative(__pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 495, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_3)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_3);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_9 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_3, __pyx_t_1) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_1);
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 495, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_Hyperbolic_distance, __pyx_t_9); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 495, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
# 14712 "example1.c"
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
# 14722 "example1.c"
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_2 = PyList_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 496, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_v_Hyperbolic_distance);
  __Pyx_GIVEREF(__pyx_v_Hyperbolic_distance);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_v_Hyperbolic_distance);
  __Pyx_INCREF(__pyx_v_L);
  __Pyx_GIVEREF(__pyx_v_L);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_v_L);
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;
# 14744 "example1.c"
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_AddTraceback("example1.Improved_Exp_negative_Hyperbolic_Distance_Gamma0", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_T);
  __Pyx_XDECREF(__pyx_v_R);
  __Pyx_XDECREF(__pyx_v_j);
  __Pyx_XDECREF(__pyx_v_tmp1);
  __Pyx_XDECREF(__pyx_v_tmp2);
  __Pyx_XDECREF(__pyx_v_nodes_in_DT);
  __Pyx_XDECREF(__pyx_v_z);
  __Pyx_XDECREF(__pyx_v_i);
  __Pyx_XDECREF(__pyx_v_k);
  __Pyx_XDECREF(__pyx_v_tmp3);
  __Pyx_XDECREF(__pyx_v_Hyperbolic_distance);
  __Pyx_XDECREF(__pyx_v_L);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
# 14780 "example1.c"
static PyObject *__pyx_pw_8example1_57examples_of_10000(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds);
static PyMethodDef __pyx_mdef_8example1_57examples_of_10000 = {"examples_of_10000", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_8example1_57examples_of_10000, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_8example1_57examples_of_10000(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_initial = 0;
  PyObject *__pyx_v_increment = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("examples_of_10000 (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_initial,&__pyx_n_s_increment,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case 2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case 1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case 0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case 0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_initial)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case 1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_increment)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("examples_of_10000", 1, 2, 2, 1); __PYX_ERR(0, 498, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "examples_of_10000") < 0)) __PYX_ERR(0, 498, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_initial = values[0];
    __pyx_v_increment = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("examples_of_10000", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 498, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("example1.examples_of_10000", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_8example1_56examples_of_10000(__pyx_self, __pyx_v_initial, __pyx_v_increment);


  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_8example1_56examples_of_10000(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_initial, PyObject *__pyx_v_increment) {
  PyObject *__pyx_v_counter = NULL;
  PyObject *__pyx_v_useful_example = NULL;
  PyObject *__pyx_v_out = NULL;
  PyObject *__pyx_v_rho = NULL;
  PyObject *__pyx_v_i = NULL;
  CYTHON_UNUSED long __pyx_v_sum1;
  CYTHON_UNUSED long __pyx_v_sum2;
  PyObject *__pyx_v_test = NULL;
  PyObject *__pyx_v_ave_of_all_exp_of_negative_rho_of_this_level = NULL;
  PyObject *__pyx_v_occurence = NULL;
  PyObject *__pyx_v_tmp = NULL;
  PyObject *__pyx_v_node = NULL;
  PyObject *__pyx_v_ave_of_all_short_exp_of_negative_rho_of_this_level = NULL;
  long __pyx_v_flag;
  PyObject *__pyx_v_n = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_t_3;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  long __pyx_t_8;
  Py_ssize_t __pyx_t_9;
  PyObject *(*__pyx_t_10)(PyObject *);
  int __pyx_t_11;
  PyObject *__pyx_t_12 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("examples_of_10000", 0);
# 14886 "example1.c"
  __Pyx_INCREF(__pyx_v_initial);
  __pyx_v_counter = __pyx_v_initial;
# 14896 "example1.c"
  __Pyx_INCREF(__pyx_int_0);
  __pyx_v_useful_example = __pyx_int_0;
# 14906 "example1.c"
  while (1) {
    __pyx_t_1 = PyNumber_Multiply(__pyx_int_10000, __pyx_v_increment); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 501, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = PyNumber_Add(__pyx_v_initial, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 501, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyObject_RichCompare(__pyx_v_counter, __pyx_t_2, Py_LT); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 501, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_3 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 501, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (!__pyx_t_3) break;
# 14925 "example1.c"
    __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_counter); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 502, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = PyNumber_Add(__pyx_kp_s_, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 502, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyNumber_Add(__pyx_t_2, __pyx_kp_s_); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 502, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (__Pyx_PrintOne(0, __pyx_t_1) < 0) __PYX_ERR(0, 502, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 14943 "example1.c"
    __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 503, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_XDECREF_SET(__pyx_v_out, ((PyObject*)__pyx_t_1));
    __pyx_t_1 = 0;
# 14955 "example1.c"
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_check_T_generate_a_Schottky); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 504, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 504, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_Lambda, __pyx_v_counter) < 0) __PYX_ERR(0, 504, __pyx_L1_error)
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_m, __pyx_int_2) < 0) __PYX_ERR(0, 504, __pyx_L1_error)
    __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 504, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_3 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 504, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (__pyx_t_3) {
# 14976 "example1.c"
      {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_ExceptionSave(&__pyx_t_5, &__pyx_t_6, &__pyx_t_7);
        __Pyx_XGOTREF(__pyx_t_5);
        __Pyx_XGOTREF(__pyx_t_6);
        __Pyx_XGOTREF(__pyx_t_7);
                 {
# 14992 "example1.c"
          __pyx_t_4 = PyList_New(0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 506, __pyx_L6_error)
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_XDECREF_SET(__pyx_v_rho, ((PyObject*)__pyx_t_4));
          __pyx_t_4 = 0;
# 15004 "example1.c"
          for (__pyx_t_8 = 0; __pyx_t_8 < 15; __pyx_t_8+=1) {
            __pyx_t_4 = __Pyx_PyInt_From_long(__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 507, __pyx_L6_error)
            __Pyx_GOTREF(__pyx_t_4);
            __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_4);
            __pyx_t_4 = 0;
# 15017 "example1.c"
            __pyx_v_sum1 = 0;
# 15026 "example1.c"
            __pyx_v_sum2 = 0;
# 15035 "example1.c"
            __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Exp_negative_Hyperbolic_Distance); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 510, __pyx_L6_error)
            __Pyx_GOTREF(__pyx_t_4);
            __pyx_t_2 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 510, __pyx_L6_error)
            __Pyx_GOTREF(__pyx_t_2);
            if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_Lambda, __pyx_float_0_3) < 0) __PYX_ERR(0, 510, __pyx_L6_error)
            if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_m, __pyx_int_2) < 0) __PYX_ERR(0, 510, __pyx_L6_error)
            if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_N, __pyx_v_i) < 0) __PYX_ERR(0, 510, __pyx_L6_error)
            __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 510, __pyx_L6_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
            __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
            __Pyx_XDECREF_SET(__pyx_v_test, __pyx_t_1);
            __pyx_t_1 = 0;
# 15056 "example1.c"
            __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_statistics); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 511, __pyx_L6_error)
            __Pyx_GOTREF(__pyx_t_2);
            __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_mean); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 511, __pyx_L6_error)
            __Pyx_GOTREF(__pyx_t_4);
            __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
            __pyx_t_2 = NULL;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
              __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_4);
              if (likely(__pyx_t_2)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
                __Pyx_INCREF(__pyx_t_2);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_4, function);
              }
            }
            __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_2, __pyx_v_test) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_v_test);
            __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
            if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 511, __pyx_L6_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
            __Pyx_XDECREF_SET(__pyx_v_ave_of_all_exp_of_negative_rho_of_this_level, __pyx_t_1);
            __pyx_t_1 = 0;
# 15086 "example1.c"
            __Pyx_INCREF(__pyx_int_0);
            __Pyx_XDECREF_SET(__pyx_v_occurence, __pyx_int_0);
# 15096 "example1.c"
            __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 513, __pyx_L6_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_XDECREF_SET(__pyx_v_tmp, ((PyObject*)__pyx_t_1));
            __pyx_t_1 = 0;
# 15108 "example1.c"
            if (likely(PyList_CheckExact(__pyx_v_test)) || PyTuple_CheckExact(__pyx_v_test)) {
              __pyx_t_1 = __pyx_v_test; __Pyx_INCREF(__pyx_t_1); __pyx_t_9 = 0;
              __pyx_t_10 = NULL;
            } else {
              __pyx_t_9 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_v_test); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 514, __pyx_L6_error)
              __Pyx_GOTREF(__pyx_t_1);
              __pyx_t_10 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 514, __pyx_L6_error)
            }
            for (;;) {
              if (likely(!__pyx_t_10)) {
                if (likely(PyList_CheckExact(__pyx_t_1))) {
                  if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_1)) break;
                  #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                  __pyx_t_4 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_9); __Pyx_INCREF(__pyx_t_4); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 514, __pyx_L6_error)
                  #else
                  __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 514, __pyx_L6_error)
                  __Pyx_GOTREF(__pyx_t_4);
                  #endif
                } else {
                  if (__pyx_t_9 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
                  #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                  __pyx_t_4 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_9); __Pyx_INCREF(__pyx_t_4); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 514, __pyx_L6_error)
                  #else
                  __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 514, __pyx_L6_error)
                  __Pyx_GOTREF(__pyx_t_4);
                  #endif
                }
              } else {
                __pyx_t_4 = __pyx_t_10(__pyx_t_1);
                if (unlikely(!__pyx_t_4)) {
                  PyObject* exc_type = PyErr_Occurred();
                  if (exc_type) {
                    if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
                    else __PYX_ERR(0, 514, __pyx_L6_error)
                  }
                  break;
                }
                __Pyx_GOTREF(__pyx_t_4);
              }
              __Pyx_XDECREF_SET(__pyx_v_node, __pyx_t_4);
              __pyx_t_4 = 0;
# 15157 "example1.c"
              __pyx_t_4 = PyObject_RichCompare(__pyx_v_node, __pyx_v_ave_of_all_exp_of_negative_rho_of_this_level, Py_LT); __Pyx_XGOTREF(__pyx_t_4); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 515, __pyx_L6_error)
              __pyx_t_3 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 515, __pyx_L6_error)
              __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
              if (__pyx_t_3) {
# 15169 "example1.c"
                __pyx_t_4 = __Pyx_PyInt_AddObjC(__pyx_v_occurence, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 516, __pyx_L6_error)
                __Pyx_GOTREF(__pyx_t_4);
                __Pyx_DECREF_SET(__pyx_v_occurence, __pyx_t_4);
                __pyx_t_4 = 0;
# 15181 "example1.c"
                goto __pyx_L18;
              }
# 15191 "example1.c"
                       {
                __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_tmp, __pyx_v_node); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 518, __pyx_L6_error)
              }
              __pyx_L18:;
# 15203 "example1.c"
            }
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 15213 "example1.c"
            __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_i); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 519, __pyx_L6_error)
            __Pyx_GOTREF(__pyx_t_1);
            __pyx_t_4 = PyNumber_Add(__pyx_kp_s_N_2, __pyx_t_1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 519, __pyx_L6_error)
            __Pyx_GOTREF(__pyx_t_4);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
            if (__Pyx_PrintOne(0, __pyx_t_4) < 0) __PYX_ERR(0, 519, __pyx_L6_error)
            __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
# 15228 "example1.c"
            __pyx_t_4 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_occurence); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 520, __pyx_L6_error)
            __Pyx_GOTREF(__pyx_t_4);
            __pyx_t_1 = PyNumber_Add(__pyx_kp_s_occurence, __pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 520, __pyx_L6_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
            if (__Pyx_PrintOne(0, __pyx_t_1) < 0) __PYX_ERR(0, 520, __pyx_L6_error)
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 15243 "example1.c"
            __pyx_t_9 = PyList_GET_SIZE(__pyx_v_tmp); if (unlikely(__pyx_t_9 == ((Py_ssize_t)-1))) __PYX_ERR(0, 521, __pyx_L6_error)
            __pyx_t_3 = ((__pyx_t_9 != 0) != 0);
            if (__pyx_t_3) {
# 15254 "example1.c"
              __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_statistics); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 522, __pyx_L6_error)
              __Pyx_GOTREF(__pyx_t_4);
              __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_mean); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 522, __pyx_L6_error)
              __Pyx_GOTREF(__pyx_t_2);
              __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
              __pyx_t_4 = NULL;
              if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
                __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
                if (likely(__pyx_t_4)) {
                  PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
                  __Pyx_INCREF(__pyx_t_4);
                  __Pyx_INCREF(function);
                  __Pyx_DECREF_SET(__pyx_t_2, function);
                }
              }
              __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_4, __pyx_v_tmp) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_tmp);
              __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
              if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 522, __pyx_L6_error)
              __Pyx_GOTREF(__pyx_t_1);
              __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
              __Pyx_XDECREF_SET(__pyx_v_ave_of_all_short_exp_of_negative_rho_of_this_level, __pyx_t_1);
              __pyx_t_1 = 0;
# 15284 "example1.c"
              __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_rho, __pyx_v_ave_of_all_short_exp_of_negative_rho_of_this_level); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 523, __pyx_L6_error)
# 15293 "example1.c"
              __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_ave_of_all_short_exp_of_negative_rho_of_this_level); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 524, __pyx_L6_error)
              __Pyx_GOTREF(__pyx_t_1);
              __pyx_t_2 = PyNumber_Add(__pyx_kp_s_ave_of_all_short_exp_of_negative, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 524, __pyx_L6_error)
              __Pyx_GOTREF(__pyx_t_2);
              __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
              if (__Pyx_PrintOne(0, __pyx_t_2) < 0) __PYX_ERR(0, 524, __pyx_L6_error)
              __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
# 15308 "example1.c"
              __pyx_t_2 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_ave_of_all_exp_of_negative_rho_of_this_level); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 525, __pyx_L6_error)
              __Pyx_GOTREF(__pyx_t_2);
              __pyx_t_1 = PyNumber_Add(__pyx_kp_s_ave_of_all_exp_of_negative_rho_o, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 525, __pyx_L6_error)
              __Pyx_GOTREF(__pyx_t_1);
              __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
              if (__Pyx_PrintOne(0, __pyx_t_1) < 0) __PYX_ERR(0, 525, __pyx_L6_error)
              __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 15323 "example1.c"
              __pyx_t_1 = __Pyx_PyInt_NeObjC(__pyx_v_ave_of_all_short_exp_of_negative_rho_of_this_level, __pyx_int_0, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 526, __pyx_L6_error)
              __Pyx_GOTREF(__pyx_t_1);
              __pyx_t_3 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 526, __pyx_L6_error)
              __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
              if (__pyx_t_3) {
# 15336 "example1.c"
                __pyx_t_1 = __Pyx_PyNumber_Divide(__pyx_v_ave_of_all_short_exp_of_negative_rho_of_this_level, __pyx_v_ave_of_all_exp_of_negative_rho_of_this_level); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 527, __pyx_L6_error)
                __Pyx_GOTREF(__pyx_t_1);
                __pyx_t_2 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 527, __pyx_L6_error)
                __Pyx_GOTREF(__pyx_t_2);
                __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
                __pyx_t_1 = PyNumber_Add(__pyx_kp_s_ave_of_all_short_exp_of_negative_2, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 527, __pyx_L6_error)
                __Pyx_GOTREF(__pyx_t_1);
                __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
                if (__Pyx_PrintOne(0, __pyx_t_1) < 0) __PYX_ERR(0, 527, __pyx_L6_error)
                __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 15354 "example1.c"
              }
# 15363 "example1.c"
            }
          }
# 15373 "example1.c"
        }
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        goto __pyx_L13_try_end;
        __pyx_L6_error:;
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
# 15390 "example1.c"
                    {
          __Pyx_AddTraceback("example1.examples_of_10000", __pyx_clineno, __pyx_lineno, __pyx_filename);
          if (__Pyx_GetException(&__pyx_t_1, &__pyx_t_2, &__pyx_t_4) < 0) __PYX_ERR(0, 529, __pyx_L8_except_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_GOTREF(__pyx_t_4);
# 15404 "example1.c"
          if (__Pyx_PrintOne(0, __pyx_kp_s__2) < 0) __PYX_ERR(0, 530, __pyx_L8_except_error)
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
          goto __pyx_L7_exception_handled;
        }
        __pyx_L8_except_error:;
# 15419 "example1.c"
        __Pyx_XGIVEREF(__pyx_t_5);
        __Pyx_XGIVEREF(__pyx_t_6);
        __Pyx_XGIVEREF(__pyx_t_7);
        __Pyx_ExceptionReset(__pyx_t_5, __pyx_t_6, __pyx_t_7);
        goto __pyx_L1_error;
        __pyx_L7_exception_handled:;
        __Pyx_XGIVEREF(__pyx_t_5);
        __Pyx_XGIVEREF(__pyx_t_6);
        __Pyx_XGIVEREF(__pyx_t_7);
        __Pyx_ExceptionReset(__pyx_t_5, __pyx_t_6, __pyx_t_7);
        __pyx_L13_try_end:;
      }
# 15439 "example1.c"
    }
# 15448 "example1.c"
    __pyx_t_9 = PyList_GET_SIZE(__pyx_v_out); if (unlikely(__pyx_t_9 == ((Py_ssize_t)-1))) __PYX_ERR(0, 531, __pyx_L1_error)
    __pyx_t_3 = ((__pyx_t_9 > 2) != 0);
    if (__pyx_t_3) {
# 15459 "example1.c"
      __pyx_v_flag = 0;
# 15468 "example1.c"
      __pyx_t_9 = PyList_GET_SIZE(__pyx_v_out); if (unlikely(__pyx_t_9 == ((Py_ssize_t)-1))) __PYX_ERR(0, 534, __pyx_L1_error)
      __pyx_t_4 = PyInt_FromSsize_t(__pyx_t_9); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 534, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 534, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      if (likely(PyList_CheckExact(__pyx_t_2)) || PyTuple_CheckExact(__pyx_t_2)) {
        __pyx_t_4 = __pyx_t_2; __Pyx_INCREF(__pyx_t_4); __pyx_t_9 = 0;
        __pyx_t_10 = NULL;
      } else {
        __pyx_t_9 = -1; __pyx_t_4 = PyObject_GetIter(__pyx_t_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 534, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        __pyx_t_10 = Py_TYPE(__pyx_t_4)->tp_iternext; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 534, __pyx_L1_error)
      }
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      for (;;) {
        if (likely(!__pyx_t_10)) {
          if (likely(PyList_CheckExact(__pyx_t_4))) {
            if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_4)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_2 = PyList_GET_ITEM(__pyx_t_4, __pyx_t_9); __Pyx_INCREF(__pyx_t_2); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 534, __pyx_L1_error)
            #else
            __pyx_t_2 = PySequence_ITEM(__pyx_t_4, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 534, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_2);
            #endif
          } else {
            if (__pyx_t_9 >= PyTuple_GET_SIZE(__pyx_t_4)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_4, __pyx_t_9); __Pyx_INCREF(__pyx_t_2); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 534, __pyx_L1_error)
            #else
            __pyx_t_2 = PySequence_ITEM(__pyx_t_4, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 534, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_2);
            #endif
          }
        } else {
          __pyx_t_2 = __pyx_t_10(__pyx_t_4);
          if (unlikely(!__pyx_t_2)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 534, __pyx_L1_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_2);
        }
        __Pyx_XDECREF_SET(__pyx_v_n, __pyx_t_2);
        __pyx_t_2 = 0;
# 15524 "example1.c"
        __pyx_t_2 = PyObject_RichCompare(__pyx_v_n, __pyx_int_1, Py_GT); __Pyx_XGOTREF(__pyx_t_2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 535, __pyx_L1_error)
        __pyx_t_3 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 535, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        if (__pyx_t_3) {
# 15536 "example1.c"
          __pyx_t_2 = __Pyx_PyObject_GetItem(__pyx_v_out, __pyx_v_n); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 536, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 536, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __pyx_t_2 = __Pyx_PyInt_SubtractObjC(__pyx_v_n, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 536, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __pyx_t_12 = __Pyx_PyObject_GetItem(__pyx_v_out, __pyx_t_2); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 536, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_12, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 536, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = __Pyx_PyNumber_Divide(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 536, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __pyx_t_2 = PyObject_RichCompare(__pyx_t_12, __pyx_int_1, Py_GT); __Pyx_XGOTREF(__pyx_t_2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 536, __pyx_L1_error)
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_3 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 536, __pyx_L1_error)
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          if (__pyx_t_3) {
# 15566 "example1.c"
            __pyx_v_flag = 1;
# 15575 "example1.c"
          }
# 15584 "example1.c"
        }
# 15593 "example1.c"
      }
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
# 15603 "example1.c"
      __pyx_t_3 = ((__pyx_v_flag == 1) != 0);
      if (__pyx_t_3) {
# 15613 "example1.c"
        __pyx_t_4 = __Pyx_PyInt_AddObjC(__pyx_v_useful_example, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 539, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        __Pyx_DECREF_SET(__pyx_v_useful_example, __pyx_t_4);
        __pyx_t_4 = 0;
# 15625 "example1.c"
        if (__Pyx_PrintOne(0, __pyx_v_out) < 0) __PYX_ERR(0, 541, __pyx_L1_error)
# 15634 "example1.c"
      }
# 15643 "example1.c"
    }
# 15652 "example1.c"
    __pyx_t_4 = PyNumber_InPlaceAdd(__pyx_v_counter, __pyx_v_increment); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 543, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF_SET(__pyx_v_counter, __pyx_t_4);
    __pyx_t_4 = 0;
# 15664 "example1.c"
    __pyx_t_4 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_counter); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 544, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_2 = PyNumber_Add(__pyx_kp_s_counter, __pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 544, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (__Pyx_PrintOne(0, __pyx_t_2) < 0) __PYX_ERR(0, 544, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;







    __pyx_t_2 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_useful_example); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 545, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_4 = PyNumber_Add(__pyx_kp_s_useful_example, __pyx_t_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 545, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (__Pyx_PrintOne(0, __pyx_t_4) < 0) __PYX_ERR(0, 545, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  }
# 15696 "example1.c"
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_AddTraceback("example1.examples_of_10000", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_counter);
  __Pyx_XDECREF(__pyx_v_useful_example);
  __Pyx_XDECREF(__pyx_v_out);
  __Pyx_XDECREF(__pyx_v_rho);
  __Pyx_XDECREF(__pyx_v_i);
  __Pyx_XDECREF(__pyx_v_test);
  __Pyx_XDECREF(__pyx_v_ave_of_all_exp_of_negative_rho_of_this_level);
  __Pyx_XDECREF(__pyx_v_occurence);
  __Pyx_XDECREF(__pyx_v_tmp);
  __Pyx_XDECREF(__pyx_v_node);
  __Pyx_XDECREF(__pyx_v_ave_of_all_short_exp_of_negative_rho_of_this_level);
  __Pyx_XDECREF(__pyx_v_n);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

#if PY_MAJOR_VERSION >= 3
#if CYTHON_PEP489_MULTI_PHASE_INIT
static PyObject* __pyx_pymod_create(PyObject *spec, PyModuleDef *def);
static int __pyx_pymod_exec_example1(PyObject* module);
static PyModuleDef_Slot __pyx_moduledef_slots[] = {
  {Py_mod_create, (void*)__pyx_pymod_create},
  {Py_mod_exec, (void*)__pyx_pymod_exec_example1},
  {0, NULL}
};
#endif

static struct PyModuleDef __pyx_moduledef = {
    PyModuleDef_HEAD_INIT,
    "example1",
    0,
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    0,
  #else
    -1,
  #endif
    __pyx_methods ,
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    __pyx_moduledef_slots,
  #else
    NULL,
  #endif
    NULL,
    NULL,
    NULL
};
#endif
#ifndef CYTHON_SMALL_CODE
#if defined(__clang__)
    #define CYTHON_SMALL_CODE
#elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
    #define CYTHON_SMALL_CODE __attribute__((cold))
#else
    #define CYTHON_SMALL_CODE
#endif
#endif

static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_kp_s_, __pyx_k_, sizeof(__pyx_k_), 0, 0, 1, 0},
  {&__pyx_kp_s_1_0_1, __pyx_k_1_0_1, sizeof(__pyx_k_1_0_1), 0, 0, 1, 0},
  {&__pyx_n_s_A, __pyx_k_A, sizeof(__pyx_k_A), 0, 0, 1, 1},
  {&__pyx_n_s_B, __pyx_k_B, sizeof(__pyx_k_B), 0, 0, 1, 1},
  {&__pyx_n_s_C, __pyx_k_C, sizeof(__pyx_k_C), 0, 0, 1, 1},
  {&__pyx_n_s_Cartesian_complex_add, __pyx_k_Cartesian_complex_add, sizeof(__pyx_k_Cartesian_complex_add), 0, 0, 1, 1},
  {&__pyx_n_s_Cartesian_complex_complex_conjug, __pyx_k_Cartesian_complex_complex_conjug, sizeof(__pyx_k_Cartesian_complex_complex_conjug), 0, 0, 1, 1},
  {&__pyx_n_s_Cartesian_complex_complex_to_pol, __pyx_k_Cartesian_complex_complex_to_pol, sizeof(__pyx_k_Cartesian_complex_complex_to_pol), 0, 0, 1, 1},
  {&__pyx_n_s_Cartesian_complex_divide, __pyx_k_Cartesian_complex_divide, sizeof(__pyx_k_Cartesian_complex_divide), 0, 0, 1, 1},
  {&__pyx_n_s_Cartesian_complex_matrix_additio, __pyx_k_Cartesian_complex_matrix_additio, sizeof(__pyx_k_Cartesian_complex_matrix_additio), 0, 0, 1, 1},
  {&__pyx_n_s_Cartesian_complex_matrix_inverse, __pyx_k_Cartesian_complex_matrix_inverse, sizeof(__pyx_k_Cartesian_complex_matrix_inverse), 0, 0, 1, 1},
  {&__pyx_n_s_Cartesian_complex_matrix_multipl, __pyx_k_Cartesian_complex_matrix_multipl, sizeof(__pyx_k_Cartesian_complex_matrix_multipl), 0, 0, 1, 1},
  {&__pyx_n_s_Cartesian_complex_modulus, __pyx_k_Cartesian_complex_modulus, sizeof(__pyx_k_Cartesian_complex_modulus), 0, 0, 1, 1},
  {&__pyx_n_s_Cartesian_complex_mul, __pyx_k_Cartesian_complex_mul, sizeof(__pyx_k_Cartesian_complex_mul), 0, 0, 1, 1},
  {&__pyx_n_s_Cartesian_complex_scalar_mul, __pyx_k_Cartesian_complex_scalar_mul, sizeof(__pyx_k_Cartesian_complex_scalar_mul), 0, 0, 1, 1},
  {&__pyx_n_s_Cartesian_radial_hyperbolic_dist, __pyx_k_Cartesian_radial_hyperbolic_dist, sizeof(__pyx_k_Cartesian_radial_hyperbolic_dist), 0, 0, 1, 1},
  {&__pyx_n_s_D, __pyx_k_D, sizeof(__pyx_k_D), 0, 0, 1, 1},
  {&__pyx_n_s_Exp_negative_Hyperbolic_Distance, __pyx_k_Exp_negative_Hyperbolic_Distance, sizeof(__pyx_k_Exp_negative_Hyperbolic_Distance), 0, 0, 1, 1},
  {&__pyx_n_s_Gamma0, __pyx_k_Gamma0, sizeof(__pyx_k_Gamma0), 0, 0, 1, 1},
  {&__pyx_n_s_Hyperbolic_Distance_Gamma0, __pyx_k_Hyperbolic_Distance_Gamma0, sizeof(__pyx_k_Hyperbolic_Distance_Gamma0), 0, 0, 1, 1},
  {&__pyx_n_s_Hyperbolic_distance, __pyx_k_Hyperbolic_distance, sizeof(__pyx_k_Hyperbolic_distance), 0, 0, 1, 1},
  {&__pyx_n_s_Improved_Exp_negative_Hyperbolic, __pyx_k_Improved_Exp_negative_Hyperbolic, sizeof(__pyx_k_Improved_Exp_negative_Hyperbolic), 0, 0, 1, 1},
  {&__pyx_n_s_K, __pyx_k_K, sizeof(__pyx_k_K), 0, 0, 1, 1},
  {&__pyx_n_s_L, __pyx_k_L, sizeof(__pyx_k_L), 0, 0, 1, 1},
  {&__pyx_n_s_Lambda, __pyx_k_Lambda, sizeof(__pyx_k_Lambda), 0, 0, 1, 1},
  {&__pyx_n_s_N, __pyx_k_N, sizeof(__pyx_k_N), 0, 0, 1, 1},
  {&__pyx_n_s_N1, __pyx_k_N1, sizeof(__pyx_k_N1), 0, 0, 1, 1},
  {&__pyx_n_s_N2, __pyx_k_N2, sizeof(__pyx_k_N2), 0, 0, 1, 1},
  {&__pyx_kp_s_N_2, __pyx_k_N_2, sizeof(__pyx_k_N_2), 0, 0, 1, 0},
  {&__pyx_n_s_Polar_complex_add, __pyx_k_Polar_complex_add, sizeof(__pyx_k_Polar_complex_add), 0, 0, 1, 1},
  {&__pyx_n_s_Polar_complex_complex_to_Cartesi, __pyx_k_Polar_complex_complex_to_Cartesi, sizeof(__pyx_k_Polar_complex_complex_to_Cartesi), 0, 0, 1, 1},
  {&__pyx_n_s_Polar_complex_conjugate, __pyx_k_Polar_complex_conjugate, sizeof(__pyx_k_Polar_complex_conjugate), 0, 0, 1, 1},
  {&__pyx_n_s_Polar_complex_divide, __pyx_k_Polar_complex_divide, sizeof(__pyx_k_Polar_complex_divide), 0, 0, 1, 1},
  {&__pyx_n_s_Polar_complex_mul, __pyx_k_Polar_complex_mul, sizeof(__pyx_k_Polar_complex_mul), 0, 0, 1, 1},
  {&__pyx_n_s_R, __pyx_k_R, sizeof(__pyx_k_R), 0, 0, 1, 1},
  {&__pyx_n_s_T, __pyx_k_T, sizeof(__pyx_k_T), 0, 0, 1, 1},
  {&__pyx_n_s_T0, __pyx_k_T0, sizeof(__pyx_k_T0), 0, 0, 1, 1},
  {&__pyx_n_s_Tz, __pyx_k_Tz, sizeof(__pyx_k_Tz), 0, 0, 1, 1},
  {&__pyx_kp_s_William_Huanshan_Chuang, __pyx_k_William_Huanshan_Chuang, sizeof(__pyx_k_William_Huanshan_Chuang), 0, 0, 1, 0},
  {&__pyx_n_s_X, __pyx_k_X, sizeof(__pyx_k_X), 0, 0, 1, 1},
  {&__pyx_n_s_Y, __pyx_k_Y, sizeof(__pyx_k_Y), 0, 0, 1, 1},
  {&__pyx_kp_s__2, __pyx_k__2, sizeof(__pyx_k__2), 0, 0, 1, 0},
  {&__pyx_n_s_a, __pyx_k_a, sizeof(__pyx_k_a), 0, 0, 1, 1},
  {&__pyx_n_s_a1, __pyx_k_a1, sizeof(__pyx_k_a1), 0, 0, 1, 1},
  {&__pyx_n_s_a2, __pyx_k_a2, sizeof(__pyx_k_a2), 0, 0, 1, 1},
  {&__pyx_n_s_alpha, __pyx_k_alpha, sizeof(__pyx_k_alpha), 0, 0, 1, 1},
  {&__pyx_n_s_append, __pyx_k_append, sizeof(__pyx_k_append), 0, 0, 1, 1},
  {&__pyx_n_s_atan, __pyx_k_atan, sizeof(__pyx_k_atan), 0, 0, 1, 1},
  {&__pyx_n_s_author, __pyx_k_author, sizeof(__pyx_k_author), 0, 0, 1, 1},
  {&__pyx_kp_s_ave_of_all_exp_of_negative_rho_o, __pyx_k_ave_of_all_exp_of_negative_rho_o, sizeof(__pyx_k_ave_of_all_exp_of_negative_rho_o), 0, 0, 1, 0},
  {&__pyx_n_s_ave_of_all_exp_of_negative_rho_o_2, __pyx_k_ave_of_all_exp_of_negative_rho_o_2, sizeof(__pyx_k_ave_of_all_exp_of_negative_rho_o_2), 0, 0, 1, 1},
  {&__pyx_kp_s_ave_of_all_short_exp_of_negative, __pyx_k_ave_of_all_short_exp_of_negative, sizeof(__pyx_k_ave_of_all_short_exp_of_negative), 0, 0, 1, 0},
  {&__pyx_kp_s_ave_of_all_short_exp_of_negative_2, __pyx_k_ave_of_all_short_exp_of_negative_2, sizeof(__pyx_k_ave_of_all_short_exp_of_negative_2), 0, 0, 1, 0},
  {&__pyx_n_s_ave_of_all_short_exp_of_negative_3, __pyx_k_ave_of_all_short_exp_of_negative_3, sizeof(__pyx_k_ave_of_all_short_exp_of_negative_3), 0, 0, 1, 1},
  {&__pyx_n_s_b, __pyx_k_b, sizeof(__pyx_k_b), 0, 0, 1, 1},
  {&__pyx_n_s_b1, __pyx_k_b1, sizeof(__pyx_k_b1), 0, 0, 1, 1},
  {&__pyx_n_s_b2, __pyx_k_b2, sizeof(__pyx_k_b2), 0, 0, 1, 1},
  {&__pyx_n_s_c, __pyx_k_c, sizeof(__pyx_k_c), 0, 0, 1, 1},
  {&__pyx_n_s_c1, __pyx_k_c1, sizeof(__pyx_k_c1), 0, 0, 1, 1},
  {&__pyx_n_s_c2, __pyx_k_c2, sizeof(__pyx_k_c2), 0, 0, 1, 1},
  {&__pyx_n_s_check_T_generate_a_Schottky, __pyx_k_check_T_generate_a_Schottky, sizeof(__pyx_k_check_T_generate_a_Schottky), 0, 0, 1, 1},
  {&__pyx_n_s_classification_point, __pyx_k_classification_point, sizeof(__pyx_k_classification_point), 0, 0, 1, 1},
  {&__pyx_n_s_cline_in_traceback, __pyx_k_cline_in_traceback, sizeof(__pyx_k_cline_in_traceback), 0, 0, 1, 1},
  {&__pyx_n_s_cos, __pyx_k_cos, sizeof(__pyx_k_cos), 0, 0, 1, 1},
  {&__pyx_kp_s_counter, __pyx_k_counter, sizeof(__pyx_k_counter), 0, 0, 1, 0},
  {&__pyx_n_s_counter_2, __pyx_k_counter_2, sizeof(__pyx_k_counter_2), 0, 0, 1, 1},
  {&__pyx_n_s_d, __pyx_k_d, sizeof(__pyx_k_d), 0, 0, 1, 1},
  {&__pyx_n_s_d1, __pyx_k_d1, sizeof(__pyx_k_d1), 0, 0, 1, 1},
  {&__pyx_n_s_d2, __pyx_k_d2, sizeof(__pyx_k_d2), 0, 0, 1, 1},
  {&__pyx_n_s_det, __pyx_k_det, sizeof(__pyx_k_det), 0, 0, 1, 1},
  {&__pyx_n_s_discriminant, __pyx_k_discriminant, sizeof(__pyx_k_discriminant), 0, 0, 1, 1},
  {&__pyx_n_s_email, __pyx_k_email, sizeof(__pyx_k_email), 0, 0, 1, 1},
  {&__pyx_n_s_end, __pyx_k_end, sizeof(__pyx_k_end), 0, 0, 1, 1},
  {&__pyx_n_s_example1, __pyx_k_example1, sizeof(__pyx_k_example1), 0, 0, 1, 1},
  {&__pyx_kp_s_example1_py, __pyx_k_example1_py, sizeof(__pyx_k_example1_py), 0, 0, 1, 0},
  {&__pyx_n_s_examples_of_10000, __pyx_k_examples_of_10000, sizeof(__pyx_k_examples_of_10000), 0, 0, 1, 1},
  {&__pyx_n_s_exp, __pyx_k_exp, sizeof(__pyx_k_exp), 0, 0, 1, 1},
  {&__pyx_n_s_file, __pyx_k_file, sizeof(__pyx_k_file), 0, 0, 1, 1},
  {&__pyx_n_s_flag, __pyx_k_flag, sizeof(__pyx_k_flag), 0, 0, 1, 1},
  {&__pyx_n_s_i, __pyx_k_i, sizeof(__pyx_k_i), 0, 0, 1, 1},
  {&__pyx_n_s_import, __pyx_k_import, sizeof(__pyx_k_import), 0, 0, 1, 1},
  {&__pyx_n_s_increment, __pyx_k_increment, sizeof(__pyx_k_increment), 0, 0, 1, 1},
  {&__pyx_n_s_initial, __pyx_k_initial, sizeof(__pyx_k_initial), 0, 0, 1, 1},
  {&__pyx_n_s_inverse_det, __pyx_k_inverse_det, sizeof(__pyx_k_inverse_det), 0, 0, 1, 1},
  {&__pyx_n_s_j, __pyx_k_j, sizeof(__pyx_k_j), 0, 0, 1, 1},
  {&__pyx_n_s_k, __pyx_k_k, sizeof(__pyx_k_k), 0, 0, 1, 1},
  {&__pyx_n_s_l, __pyx_k_l, sizeof(__pyx_k_l), 0, 0, 1, 1},
  {&__pyx_n_s_l1, __pyx_k_l1, sizeof(__pyx_k_l1), 0, 0, 1, 1},
  {&__pyx_n_s_l2, __pyx_k_l2, sizeof(__pyx_k_l2), 0, 0, 1, 1},
  {&__pyx_n_s_log, __pyx_k_log, sizeof(__pyx_k_log), 0, 0, 1, 1},
  {&__pyx_n_s_m, __pyx_k_m, sizeof(__pyx_k_m), 0, 0, 1, 1},
  {&__pyx_n_s_m1, __pyx_k_m1, sizeof(__pyx_k_m1), 0, 0, 1, 1},
  {&__pyx_n_s_m2, __pyx_k_m2, sizeof(__pyx_k_m2), 0, 0, 1, 1},
  {&__pyx_n_s_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 0, 1, 1},
  {&__pyx_n_s_math, __pyx_k_math, sizeof(__pyx_k_math), 0, 0, 1, 1},
  {&__pyx_n_s_mean, __pyx_k_mean, sizeof(__pyx_k_mean), 0, 0, 1, 1},
  {&__pyx_n_s_n, __pyx_k_n, sizeof(__pyx_k_n), 0, 0, 1, 1},
  {&__pyx_n_s_name, __pyx_k_name, sizeof(__pyx_k_name), 0, 0, 1, 1},
  {&__pyx_n_s_node, __pyx_k_node, sizeof(__pyx_k_node), 0, 0, 1, 1},
  {&__pyx_n_s_nodes_in_DT, __pyx_k_nodes_in_DT, sizeof(__pyx_k_nodes_in_DT), 0, 0, 1, 1},
  {&__pyx_n_s_null, __pyx_k_null, sizeof(__pyx_k_null), 0, 0, 1, 1},
  {&__pyx_n_s_numb, __pyx_k_numb, sizeof(__pyx_k_numb), 0, 0, 1, 1},
  {&__pyx_n_s_numb1, __pyx_k_numb1, sizeof(__pyx_k_numb1), 0, 0, 1, 1},
  {&__pyx_n_s_numb2, __pyx_k_numb2, sizeof(__pyx_k_numb2), 0, 0, 1, 1},
  {&__pyx_n_s_nx, __pyx_k_nx, sizeof(__pyx_k_nx), 0, 0, 1, 1},
  {&__pyx_n_s_ny, __pyx_k_ny, sizeof(__pyx_k_ny), 0, 0, 1, 1},
  {&__pyx_kp_s_occurence, __pyx_k_occurence, sizeof(__pyx_k_occurence), 0, 0, 1, 0},
  {&__pyx_n_s_occurence_2, __pyx_k_occurence_2, sizeof(__pyx_k_occurence_2), 0, 0, 1, 1},
  {&__pyx_n_s_operator_R, __pyx_k_operator_R, sizeof(__pyx_k_operator_R), 0, 0, 1, 1},
  {&__pyx_n_s_operator_T, __pyx_k_operator_T, sizeof(__pyx_k_operator_T), 0, 0, 1, 1},
  {&__pyx_n_s_out, __pyx_k_out, sizeof(__pyx_k_out), 0, 0, 1, 1},
  {&__pyx_n_s_pi, __pyx_k_pi, sizeof(__pyx_k_pi), 0, 0, 1, 1},
  {&__pyx_n_s_print, __pyx_k_print, sizeof(__pyx_k_print), 0, 0, 1, 1},
  {&__pyx_n_s_r, __pyx_k_r, sizeof(__pyx_k_r), 0, 0, 1, 1},
  {&__pyx_n_s_range, __pyx_k_range, sizeof(__pyx_k_range), 0, 0, 1, 1},
  {&__pyx_n_s_real_matrix_addition, __pyx_k_real_matrix_addition, sizeof(__pyx_k_real_matrix_addition), 0, 0, 1, 1},
  {&__pyx_n_s_real_matrix_inverse, __pyx_k_real_matrix_inverse, sizeof(__pyx_k_real_matrix_inverse), 0, 0, 1, 1},
  {&__pyx_n_s_real_matrix_multiplication, __pyx_k_real_matrix_multiplication, sizeof(__pyx_k_real_matrix_multiplication), 0, 0, 1, 1},
  {&__pyx_n_s_rho, __pyx_k_rho, sizeof(__pyx_k_rho), 0, 0, 1, 1},
  {&__pyx_n_s_sin, __pyx_k_sin, sizeof(__pyx_k_sin), 0, 0, 1, 1},
  {&__pyx_n_s_sqrt, __pyx_k_sqrt, sizeof(__pyx_k_sqrt), 0, 0, 1, 1},
  {&__pyx_n_s_statistics, __pyx_k_statistics, sizeof(__pyx_k_statistics), 0, 0, 1, 1},
  {&__pyx_n_s_sum1, __pyx_k_sum1, sizeof(__pyx_k_sum1), 0, 0, 1, 1},
  {&__pyx_n_s_sum2, __pyx_k_sum2, sizeof(__pyx_k_sum2), 0, 0, 1, 1},
  {&__pyx_n_s_t, __pyx_k_t, sizeof(__pyx_k_t), 0, 0, 1, 1},
  {&__pyx_n_s_test, __pyx_k_test, sizeof(__pyx_k_test), 0, 0, 1, 1},
  {&__pyx_n_s_test_2, __pyx_k_test_2, sizeof(__pyx_k_test_2), 0, 0, 1, 1},
  {&__pyx_n_s_theta, __pyx_k_theta, sizeof(__pyx_k_theta), 0, 0, 1, 1},
  {&__pyx_n_s_tmp, __pyx_k_tmp, sizeof(__pyx_k_tmp), 0, 0, 1, 1},
  {&__pyx_n_s_tmp1, __pyx_k_tmp1, sizeof(__pyx_k_tmp1), 0, 0, 1, 1},
  {&__pyx_n_s_tmp2, __pyx_k_tmp2, sizeof(__pyx_k_tmp2), 0, 0, 1, 1},
  {&__pyx_n_s_tmp3, __pyx_k_tmp3, sizeof(__pyx_k_tmp3), 0, 0, 1, 1},
  {&__pyx_n_s_tot, __pyx_k_tot, sizeof(__pyx_k_tot), 0, 0, 1, 1},
  {&__pyx_kp_s_useful_example, __pyx_k_useful_example, sizeof(__pyx_k_useful_example), 0, 0, 1, 0},
  {&__pyx_n_s_useful_example_2, __pyx_k_useful_example_2, sizeof(__pyx_k_useful_example_2), 0, 0, 1, 1},
  {&__pyx_n_s_version, __pyx_k_version, sizeof(__pyx_k_version), 0, 0, 1, 1},
  {&__pyx_kp_s_wchuang2_mail_sfsu_edu, __pyx_k_wchuang2_mail_sfsu_edu, sizeof(__pyx_k_wchuang2_mail_sfsu_edu), 0, 0, 1, 0},
  {&__pyx_n_s_x, __pyx_k_x, sizeof(__pyx_k_x), 0, 0, 1, 1},
  {&__pyx_n_s_y, __pyx_k_y, sizeof(__pyx_k_y), 0, 0, 1, 1},
  {&__pyx_n_s_z, __pyx_k_z, sizeof(__pyx_k_z), 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0}
};
static CYTHON_SMALL_CODE int __Pyx_InitCachedBuiltins(void) {
  __pyx_builtin_range = __Pyx_GetBuiltinName(__pyx_n_s_range); if (!__pyx_builtin_range) __PYX_ERR(0, 253, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitCachedConstants(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_InitCachedConstants", 0);
# 15929 "example1.c"
  __pyx_tuple__3 = PyTuple_Pack(4, __pyx_n_s_numb1, __pyx_n_s_numb2, __pyx_n_s_x, __pyx_n_s_y); if (unlikely(!__pyx_tuple__3)) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__3);
  __Pyx_GIVEREF(__pyx_tuple__3);
  __pyx_codeobj__4 = (PyObject*)__Pyx_PyCode_New(2, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__3, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Cartesian_complex_mul, 8, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__4)) __PYX_ERR(0, 8, __pyx_L1_error)
# 15941 "example1.c"
  __pyx_tuple__5 = PyTuple_Pack(4, __pyx_n_s_alpha, __pyx_n_s_numb1, __pyx_n_s_x, __pyx_n_s_y); if (unlikely(!__pyx_tuple__5)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__5);
  __Pyx_GIVEREF(__pyx_tuple__5);
  __pyx_codeobj__6 = (PyObject*)__Pyx_PyCode_New(2, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__5, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Cartesian_complex_scalar_mul, 14, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__6)) __PYX_ERR(0, 14, __pyx_L1_error)
# 15953 "example1.c"
  __pyx_tuple__7 = PyTuple_Pack(4, __pyx_n_s_numb1, __pyx_n_s_numb2, __pyx_n_s_x, __pyx_n_s_y); if (unlikely(!__pyx_tuple__7)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__7);
  __Pyx_GIVEREF(__pyx_tuple__7);
  __pyx_codeobj__8 = (PyObject*)__Pyx_PyCode_New(2, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__7, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Cartesian_complex_add, 20, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__8)) __PYX_ERR(0, 20, __pyx_L1_error)
# 15965 "example1.c"
  __pyx_tuple__9 = PyTuple_Pack(7, __pyx_n_s_numb1, __pyx_n_s_numb2, __pyx_n_s_d, __pyx_n_s_nx, __pyx_n_s_ny, __pyx_n_s_X, __pyx_n_s_Y); if (unlikely(!__pyx_tuple__9)) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__9);
  __Pyx_GIVEREF(__pyx_tuple__9);
  __pyx_codeobj__10 = (PyObject*)__Pyx_PyCode_New(2, 0, 7, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__9, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Cartesian_complex_divide, 26, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__10)) __PYX_ERR(0, 26, __pyx_L1_error)
# 15977 "example1.c"
  __pyx_tuple__11 = PyTuple_Pack(1, __pyx_n_s_numb); if (unlikely(!__pyx_tuple__11)) __PYX_ERR(0, 35, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__11);
  __Pyx_GIVEREF(__pyx_tuple__11);
  __pyx_codeobj__12 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__11, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Cartesian_complex_modulus, 35, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__12)) __PYX_ERR(0, 35, __pyx_L1_error)
# 15989 "example1.c"
  __pyx_tuple__13 = PyTuple_Pack(1, __pyx_n_s_numb); if (unlikely(!__pyx_tuple__13)) __PYX_ERR(0, 38, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__13);
  __Pyx_GIVEREF(__pyx_tuple__13);
  __pyx_codeobj__14 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__13, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Cartesian_complex_complex_conjug, 38, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__14)) __PYX_ERR(0, 38, __pyx_L1_error)
# 16001 "example1.c"
  __pyx_tuple__15 = PyTuple_Pack(3, __pyx_n_s_numb, __pyx_n_s_r, __pyx_n_s_t); if (unlikely(!__pyx_tuple__15)) __PYX_ERR(0, 41, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__15);
  __Pyx_GIVEREF(__pyx_tuple__15);
  __pyx_codeobj__16 = (PyObject*)__Pyx_PyCode_New(1, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__15, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Cartesian_complex_complex_to_pol, 41, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__16)) __PYX_ERR(0, 41, __pyx_L1_error)
# 16013 "example1.c"
  __pyx_tuple__17 = PyTuple_Pack(1, __pyx_n_s_numb); if (unlikely(!__pyx_tuple__17)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__17);
  __Pyx_GIVEREF(__pyx_tuple__17);
  __pyx_codeobj__18 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__17, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Polar_complex_complex_to_Cartesi, 56, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__18)) __PYX_ERR(0, 56, __pyx_L1_error)
# 16025 "example1.c"
  __pyx_tuple__19 = PyTuple_Pack(1, __pyx_n_s_numb); if (unlikely(!__pyx_tuple__19)) __PYX_ERR(0, 59, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__19);
  __Pyx_GIVEREF(__pyx_tuple__19);
  __pyx_codeobj__20 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__19, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Polar_complex_conjugate, 59, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__20)) __PYX_ERR(0, 59, __pyx_L1_error)
# 16037 "example1.c"
  __pyx_tuple__21 = PyTuple_Pack(4, __pyx_n_s_numb1, __pyx_n_s_numb2, __pyx_n_s_r, __pyx_n_s_t); if (unlikely(!__pyx_tuple__21)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__21);
  __Pyx_GIVEREF(__pyx_tuple__21);
  __pyx_codeobj__22 = (PyObject*)__Pyx_PyCode_New(2, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__21, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Polar_complex_mul, 62, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__22)) __PYX_ERR(0, 62, __pyx_L1_error)
# 16049 "example1.c"
  __pyx_tuple__23 = PyTuple_Pack(4, __pyx_n_s_numb1, __pyx_n_s_numb2, __pyx_n_s_r, __pyx_n_s_t); if (unlikely(!__pyx_tuple__23)) __PYX_ERR(0, 68, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__23);
  __Pyx_GIVEREF(__pyx_tuple__23);
  __pyx_codeobj__24 = (PyObject*)__Pyx_PyCode_New(2, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__23, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Polar_complex_divide, 68, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__24)) __PYX_ERR(0, 68, __pyx_L1_error)
# 16061 "example1.c"
  __pyx_tuple__25 = PyTuple_Pack(5, __pyx_n_s_numb1, __pyx_n_s_numb2, __pyx_n_s_N1, __pyx_n_s_N2, __pyx_n_s_tot); if (unlikely(!__pyx_tuple__25)) __PYX_ERR(0, 74, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__25);
  __Pyx_GIVEREF(__pyx_tuple__25);
  __pyx_codeobj__26 = (PyObject*)__Pyx_PyCode_New(2, 0, 5, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__25, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Polar_complex_add, 74, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__26)) __PYX_ERR(0, 74, __pyx_L1_error)
# 16073 "example1.c"
  __pyx_tuple__27 = PyTuple_Pack(9, __pyx_n_s_m1, __pyx_n_s_m2, __pyx_n_s_a, __pyx_n_s_b, __pyx_n_s_c, __pyx_n_s_d, __pyx_n_s_l1, __pyx_n_s_l2, __pyx_n_s_l); if (unlikely(!__pyx_tuple__27)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__27);
  __Pyx_GIVEREF(__pyx_tuple__27);
  __pyx_codeobj__28 = (PyObject*)__Pyx_PyCode_New(2, 0, 9, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__27, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_real_matrix_addition, 80, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__28)) __PYX_ERR(0, 80, __pyx_L1_error)
# 16085 "example1.c"
  __pyx_tuple__29 = PyTuple_Pack(17, __pyx_n_s_m1, __pyx_n_s_m2, __pyx_n_s_a1, __pyx_n_s_a2, __pyx_n_s_b1, __pyx_n_s_b2, __pyx_n_s_c1, __pyx_n_s_c2, __pyx_n_s_d1, __pyx_n_s_d2, __pyx_n_s_a, __pyx_n_s_b, __pyx_n_s_c, __pyx_n_s_d, __pyx_n_s_l1, __pyx_n_s_l2, __pyx_n_s_l); if (unlikely(!__pyx_tuple__29)) __PYX_ERR(0, 93, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__29);
  __Pyx_GIVEREF(__pyx_tuple__29);
  __pyx_codeobj__30 = (PyObject*)__Pyx_PyCode_New(2, 0, 17, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__29, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Cartesian_complex_matrix_additio, 93, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__30)) __PYX_ERR(0, 93, __pyx_L1_error)
# 16097 "example1.c"
  __pyx_tuple__31 = PyTuple_Pack(9, __pyx_n_s_m1, __pyx_n_s_m2, __pyx_n_s_a, __pyx_n_s_b, __pyx_n_s_c, __pyx_n_s_d, __pyx_n_s_l1, __pyx_n_s_l2, __pyx_n_s_l); if (unlikely(!__pyx_tuple__31)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__31);
  __Pyx_GIVEREF(__pyx_tuple__31);
  __pyx_codeobj__32 = (PyObject*)__Pyx_PyCode_New(2, 0, 9, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__31, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_real_matrix_multiplication, 115, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__32)) __PYX_ERR(0, 115, __pyx_L1_error)
# 16109 "example1.c"
  __pyx_tuple__33 = PyTuple_Pack(9, __pyx_n_s_m1, __pyx_n_s_m2, __pyx_n_s_a, __pyx_n_s_b, __pyx_n_s_c, __pyx_n_s_d, __pyx_n_s_l1, __pyx_n_s_l2, __pyx_n_s_l); if (unlikely(!__pyx_tuple__33)) __PYX_ERR(0, 128, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__33);
  __Pyx_GIVEREF(__pyx_tuple__33);
  __pyx_codeobj__34 = (PyObject*)__Pyx_PyCode_New(2, 0, 9, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__33, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Cartesian_complex_matrix_multipl, 128, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__34)) __PYX_ERR(0, 128, __pyx_L1_error)
# 16121 "example1.c"
  __pyx_tuple__35 = PyTuple_Pack(9, __pyx_n_s_m1, __pyx_n_s_det, __pyx_n_s_a, __pyx_n_s_b, __pyx_n_s_c, __pyx_n_s_d, __pyx_n_s_l1, __pyx_n_s_l2, __pyx_n_s_l); if (unlikely(!__pyx_tuple__35)) __PYX_ERR(0, 142, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__35);
  __Pyx_GIVEREF(__pyx_tuple__35);
  __pyx_codeobj__36 = (PyObject*)__Pyx_PyCode_New(1, 0, 9, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__35, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_real_matrix_inverse, 142, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__36)) __PYX_ERR(0, 142, __pyx_L1_error)
# 16133 "example1.c"
  __pyx_tuple__37 = PyTuple_Pack(10, __pyx_n_s_m1, __pyx_n_s_det, __pyx_n_s_inverse_det, __pyx_n_s_a, __pyx_n_s_b, __pyx_n_s_c, __pyx_n_s_d, __pyx_n_s_l1, __pyx_n_s_l2, __pyx_n_s_l); if (unlikely(!__pyx_tuple__37)) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__37);
  __Pyx_GIVEREF(__pyx_tuple__37);
  __pyx_codeobj__38 = (PyObject*)__Pyx_PyCode_New(1, 0, 10, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__37, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Cartesian_complex_matrix_inverse, 156, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__38)) __PYX_ERR(0, 156, __pyx_L1_error)
# 16145 "example1.c"
  __pyx_tuple__39 = PyTuple_Pack(2, __pyx_n_s_z, __pyx_n_s_r); if (unlikely(!__pyx_tuple__39)) __PYX_ERR(0, 173, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__39);
  __Pyx_GIVEREF(__pyx_tuple__39);
  __pyx_codeobj__40 = (PyObject*)__Pyx_PyCode_New(1, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__39, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Cartesian_radial_hyperbolic_dist, 173, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__40)) __PYX_ERR(0, 173, __pyx_L1_error)
# 16157 "example1.c"
  __pyx_tuple__41 = PyTuple_Pack(13, __pyx_n_s_Lambda, __pyx_n_s_D, __pyx_n_s_a1, __pyx_n_s_a2, __pyx_n_s_b1, __pyx_n_s_b2, __pyx_n_s_c1, __pyx_n_s_c2, __pyx_n_s_d1, __pyx_n_s_d2, __pyx_n_s_l1, __pyx_n_s_l2, __pyx_n_s_l); if (unlikely(!__pyx_tuple__41)) __PYX_ERR(0, 177, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__41);
  __Pyx_GIVEREF(__pyx_tuple__41);
  __pyx_codeobj__42 = (PyObject*)__Pyx_PyCode_New(1, 0, 13, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__41, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_operator_T, 177, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__42)) __PYX_ERR(0, 177, __pyx_L1_error)
# 16169 "example1.c"
  __pyx_tuple__43 = PyTuple_Pack(8, __pyx_n_s_theta, __pyx_n_s_a, __pyx_n_s_b, __pyx_n_s_c, __pyx_n_s_d, __pyx_n_s_l1, __pyx_n_s_l2, __pyx_n_s_l); if (unlikely(!__pyx_tuple__43)) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__43);
  __Pyx_GIVEREF(__pyx_tuple__43);
  __pyx_codeobj__44 = (PyObject*)__Pyx_PyCode_New(1, 0, 8, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__43, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_operator_R, 194, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__44)) __PYX_ERR(0, 194, __pyx_L1_error)
# 16181 "example1.c"
  __pyx_tuple__45 = PyTuple_Pack(1, __pyx_n_s_Lambda); if (unlikely(!__pyx_tuple__45)) __PYX_ERR(0, 206, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__45);
  __Pyx_GIVEREF(__pyx_tuple__45);
  __pyx_codeobj__46 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__45, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_classification_point, 206, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__46)) __PYX_ERR(0, 206, __pyx_L1_error)
# 16193 "example1.c"
  __pyx_tuple__47 = PyTuple_Pack(8, __pyx_n_s_Lambda, __pyx_n_s_m, __pyx_n_s_t, __pyx_n_s_K, __pyx_n_s_B, __pyx_n_s_T, __pyx_n_s_T0, __pyx_n_s_discriminant); if (unlikely(!__pyx_tuple__47)) __PYX_ERR(0, 209, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__47);
  __Pyx_GIVEREF(__pyx_tuple__47);
  __pyx_codeobj__48 = (PyObject*)__Pyx_PyCode_New(2, 0, 8, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__47, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_check_T_generate_a_Schottky, 209, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__48)) __PYX_ERR(0, 209, __pyx_L1_error)
# 16205 "example1.c"
  __pyx_tuple__49 = PyTuple_Pack(12, __pyx_n_s_T, __pyx_n_s_z, __pyx_n_s_a, __pyx_n_s_b, __pyx_n_s_c, __pyx_n_s_d, __pyx_n_s_x, __pyx_n_s_y, __pyx_n_s_A, __pyx_n_s_B, __pyx_n_s_C, __pyx_n_s_D); if (unlikely(!__pyx_tuple__49)) __PYX_ERR(0, 222, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__49);
  __Pyx_GIVEREF(__pyx_tuple__49);
  __pyx_codeobj__50 = (PyObject*)__Pyx_PyCode_New(2, 0, 12, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__49, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Tz, 222, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__50)) __PYX_ERR(0, 222, __pyx_L1_error)
# 16217 "example1.c"
  __pyx_tuple__51 = PyTuple_Pack(15, __pyx_n_s_Lambda, __pyx_n_s_m, __pyx_n_s_N, __pyx_n_s_T, __pyx_n_s_theta, __pyx_n_s_R, __pyx_n_s_L, __pyx_n_s_tmp1, __pyx_n_s_tmp2, __pyx_n_s_nodes_in_DT, __pyx_n_s_j, __pyx_n_s_z, __pyx_n_s_i, __pyx_n_s_k, __pyx_n_s_tmp3); if (unlikely(!__pyx_tuple__51)) __PYX_ERR(0, 238, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__51);
  __Pyx_GIVEREF(__pyx_tuple__51);
  __pyx_codeobj__52 = (PyObject*)__Pyx_PyCode_New(3, 0, 15, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__51, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Gamma0, 238, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__52)) __PYX_ERR(0, 238, __pyx_L1_error)
# 16229 "example1.c"
  __pyx_tuple__53 = PyTuple_Pack(16, __pyx_n_s_Lambda, __pyx_n_s_m, __pyx_n_s_N, __pyx_n_s_T, __pyx_n_s_theta, __pyx_n_s_R, __pyx_n_s_L, __pyx_n_s_tmp1, __pyx_n_s_tmp2, __pyx_n_s_nodes_in_DT, __pyx_n_s_j, __pyx_n_s_z, __pyx_n_s_i, __pyx_n_s_k, __pyx_n_s_tmp3, __pyx_n_s_Hyperbolic_distance); if (unlikely(!__pyx_tuple__53)) __PYX_ERR(0, 299, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__53);
  __Pyx_GIVEREF(__pyx_tuple__53);
  __pyx_codeobj__54 = (PyObject*)__Pyx_PyCode_New(3, 0, 16, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__53, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Hyperbolic_Distance_Gamma0, 299, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__54)) __PYX_ERR(0, 299, __pyx_L1_error)
# 16241 "example1.c"
  __pyx_tuple__55 = PyTuple_Pack(16, __pyx_n_s_Lambda, __pyx_n_s_m, __pyx_n_s_N, __pyx_n_s_T, __pyx_n_s_theta, __pyx_n_s_R, __pyx_n_s_L, __pyx_n_s_tmp1, __pyx_n_s_tmp2, __pyx_n_s_nodes_in_DT, __pyx_n_s_j, __pyx_n_s_z, __pyx_n_s_i, __pyx_n_s_k, __pyx_n_s_tmp3, __pyx_n_s_Hyperbolic_distance); if (unlikely(!__pyx_tuple__55)) __PYX_ERR(0, 364, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__55);
  __Pyx_GIVEREF(__pyx_tuple__55);
  __pyx_codeobj__56 = (PyObject*)__Pyx_PyCode_New(3, 0, 16, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__55, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Exp_negative_Hyperbolic_Distance, 364, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__56)) __PYX_ERR(0, 364, __pyx_L1_error)
# 16253 "example1.c"
  __pyx_tuple__57 = PyTuple_Pack(16, __pyx_n_s_Lambda, __pyx_n_s_m, __pyx_n_s_N, __pyx_n_s_L, __pyx_n_s_T, __pyx_n_s_theta, __pyx_n_s_R, __pyx_n_s_j, __pyx_n_s_tmp1, __pyx_n_s_tmp2, __pyx_n_s_nodes_in_DT, __pyx_n_s_z, __pyx_n_s_i, __pyx_n_s_k, __pyx_n_s_tmp3, __pyx_n_s_Hyperbolic_distance); if (unlikely(!__pyx_tuple__57)) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__57);
  __Pyx_GIVEREF(__pyx_tuple__57);
  __pyx_codeobj__58 = (PyObject*)__Pyx_PyCode_New(4, 0, 16, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__57, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_Improved_Exp_negative_Hyperbolic, 429, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__58)) __PYX_ERR(0, 429, __pyx_L1_error)
# 16265 "example1.c"
  __pyx_tuple__59 = PyTuple_Pack(17, __pyx_n_s_initial, __pyx_n_s_increment, __pyx_n_s_counter_2, __pyx_n_s_useful_example_2, __pyx_n_s_out, __pyx_n_s_rho, __pyx_n_s_i, __pyx_n_s_sum1, __pyx_n_s_sum2, __pyx_n_s_test, __pyx_n_s_ave_of_all_exp_of_negative_rho_o_2, __pyx_n_s_occurence_2, __pyx_n_s_tmp, __pyx_n_s_node, __pyx_n_s_ave_of_all_short_exp_of_negative_3, __pyx_n_s_flag, __pyx_n_s_n); if (unlikely(!__pyx_tuple__59)) __PYX_ERR(0, 498, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__59);
  __Pyx_GIVEREF(__pyx_tuple__59);
  __pyx_codeobj__60 = (PyObject*)__Pyx_PyCode_New(2, 0, 17, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__59, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_example1_py, __pyx_n_s_examples_of_10000, 498, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__60)) __PYX_ERR(0, 498, __pyx_L1_error)
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitGlobals(void) {
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  __pyx_float_0_3 = PyFloat_FromDouble(0.3); if (unlikely(!__pyx_float_0_3)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_float_0_5 = PyFloat_FromDouble(0.5); if (unlikely(!__pyx_float_0_5)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_float_0_000001 = PyFloat_FromDouble(0.000001); if (unlikely(!__pyx_float_0_000001)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_float_neg_0_5 = PyFloat_FromDouble(-0.5); if (unlikely(!__pyx_float_neg_0_5)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_0 = PyInt_FromLong(0); if (unlikely(!__pyx_int_0)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_1 = PyInt_FromLong(1); if (unlikely(!__pyx_int_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_2 = PyInt_FromLong(2); if (unlikely(!__pyx_int_2)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_4 = PyInt_FromLong(4); if (unlikely(!__pyx_int_4)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_10000 = PyInt_FromLong(10000L); if (unlikely(!__pyx_int_10000)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_neg_1 = PyInt_FromLong(-1); if (unlikely(!__pyx_int_neg_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_modinit_global_init_code(void);
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_export_code(void);
static CYTHON_SMALL_CODE int __Pyx_modinit_function_export_code(void);
static CYTHON_SMALL_CODE int __Pyx_modinit_type_init_code(void);
static CYTHON_SMALL_CODE int __Pyx_modinit_type_import_code(void);
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_import_code(void);
static CYTHON_SMALL_CODE int __Pyx_modinit_function_import_code(void);

static int __Pyx_modinit_global_init_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_global_init_code", 0);

  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_export_code", 0);

  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_export_code", 0);

  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_type_init_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_init_code", 0);

  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_type_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_import_code", 0);

  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_import_code", 0);

  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_import_code", 0);

  __Pyx_RefNannyFinishContext();
  return 0;
}


#ifndef CYTHON_NO_PYINIT_EXPORT
#define __Pyx_PyMODINIT_FUNC PyMODINIT_FUNC
#elif PY_MAJOR_VERSION < 3
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" void
#else
#define __Pyx_PyMODINIT_FUNC void
#endif
#else
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" PyObject *
#else
#define __Pyx_PyMODINIT_FUNC PyObject *
#endif
#endif


#if PY_MAJOR_VERSION < 3
__Pyx_PyMODINIT_FUNC initexample1(void) CYTHON_SMALL_CODE;
__Pyx_PyMODINIT_FUNC initexample1(void)
#else
__Pyx_PyMODINIT_FUNC PyInit_example1(void) CYTHON_SMALL_CODE;
__Pyx_PyMODINIT_FUNC PyInit_example1(void)
#if CYTHON_PEP489_MULTI_PHASE_INIT
{
  return PyModuleDef_Init(&__pyx_moduledef);
}
static CYTHON_SMALL_CODE int __Pyx_check_single_interpreter(void) {
    #if PY_VERSION_HEX >= 0x030700A1
    static PY_INT64_T main_interpreter_id = -1;
    PY_INT64_T current_id = PyInterpreterState_GetID(PyThreadState_Get()->interp);
    if (main_interpreter_id == -1) {
        main_interpreter_id = current_id;
        return (unlikely(current_id == -1)) ? -1 : 0;
    } else if (unlikely(main_interpreter_id != current_id))
    #else
    static PyInterpreterState *main_interpreter = NULL;
    PyInterpreterState *current_interpreter = PyThreadState_Get()->interp;
    if (!main_interpreter) {
        main_interpreter = current_interpreter;
    } else if (unlikely(main_interpreter != current_interpreter))
    #endif
    {
        PyErr_SetString(
            PyExc_ImportError,
            "Interpreter change detected - this module can only be loaded into one interpreter per process.");
        return -1;
    }
    return 0;
}
static CYTHON_SMALL_CODE int __Pyx_copy_spec_to_module(PyObject *spec, PyObject *moddict, const char* from_name, const char* to_name, int allow_none) {
    PyObject *value = PyObject_GetAttrString(spec, from_name);
    int result = 0;
    if (likely(value)) {
        if (allow_none || value != Py_None) {
            result = PyDict_SetItemString(moddict, to_name, value);
        }
        Py_DECREF(value);
    } else if (PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Clear();
    } else {
        result = -1;
    }
    return result;
}
static CYTHON_SMALL_CODE PyObject* __pyx_pymod_create(PyObject *spec, CYTHON_UNUSED PyModuleDef *def) {
    PyObject *module = NULL, *moddict, *modname;
    if (__Pyx_check_single_interpreter())
        return NULL;
    if (__pyx_m)
        return __Pyx_NewRef(__pyx_m);
    modname = PyObject_GetAttrString(spec, "name");
    if (unlikely(!modname)) goto bad;
    module = PyModule_NewObject(modname);
    Py_DECREF(modname);
    if (unlikely(!module)) goto bad;
    moddict = PyModule_GetDict(module);
    if (unlikely(!moddict)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "loader", "__loader__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "origin", "__file__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "parent", "__package__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "submodule_search_locations", "__path__", 0) < 0)) goto bad;
    return module;
bad:
    Py_XDECREF(module);
    return NULL;
}


static CYTHON_SMALL_CODE int __pyx_pymod_exec_example1(PyObject *__pyx_pyinit_module)
#endif
#endif
{
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  if (__pyx_m) {
    if (__pyx_m == __pyx_pyinit_module) return 0;
    PyErr_SetString(PyExc_RuntimeError, "Module 'example1' has already been imported. Re-initialisation is not supported.");
    return -1;
  }
  #elif PY_MAJOR_VERSION >= 3
  if (__pyx_m) return __Pyx_NewRef(__pyx_m);
  #endif
  #if CYTHON_REFNANNY
__Pyx_RefNanny = __Pyx_RefNannyImportAPI("refnanny");
if (!__Pyx_RefNanny) {
  PyErr_Clear();
  __Pyx_RefNanny = __Pyx_RefNannyImportAPI("Cython.Runtime.refnanny");
  if (!__Pyx_RefNanny)
      Py_FatalError("failed to import 'refnanny' module");
}
#endif
  __Pyx_RefNannySetupContext("__Pyx_PyMODINIT_FUNC PyInit_example1(void)", 0);
  if (__Pyx_check_binary_version() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pxy_PyFrame_Initialize_Offsets
  __Pxy_PyFrame_Initialize_Offsets();
  #endif
  __pyx_empty_tuple = PyTuple_New(0); if (unlikely(!__pyx_empty_tuple)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_bytes = PyBytes_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_bytes)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_unicode = PyUnicode_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_unicode)) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pyx_CyFunction_USED
  if (__pyx_CyFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_FusedFunction_USED
  if (__pyx_FusedFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Coroutine_USED
  if (__pyx_Coroutine_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Generator_USED
  if (__pyx_Generator_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_AsyncGen_USED
  if (__pyx_AsyncGen_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_StopAsyncIteration_USED
  if (__pyx_StopAsyncIteration_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif


  #if defined(__PYX_FORCE_INIT_THREADS) && __PYX_FORCE_INIT_THREADS
  #ifdef WITH_THREAD
  PyEval_InitThreads();
  #endif
  #endif

  #if CYTHON_PEP489_MULTI_PHASE_INIT
  __pyx_m = __pyx_pyinit_module;
  Py_INCREF(__pyx_m);
  #else
  #if PY_MAJOR_VERSION < 3
  __pyx_m = Py_InitModule4("example1", __pyx_methods, 0, 0, PYTHON_API_VERSION); Py_XINCREF(__pyx_m);
  #else
  __pyx_m = PyModule_Create(&__pyx_moduledef);
  #endif
  if (unlikely(!__pyx_m)) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  __pyx_d = PyModule_GetDict(__pyx_m); if (unlikely(!__pyx_d)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_d);
  __pyx_b = PyImport_AddModule(__Pyx_BUILTIN_MODULE_NAME); if (unlikely(!__pyx_b)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_b);
  __pyx_cython_runtime = PyImport_AddModule((char *) "cython_runtime"); if (unlikely(!__pyx_cython_runtime)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_cython_runtime);
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) __PYX_ERR(0, 1, __pyx_L1_error);

  if (__Pyx_InitGlobals() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #if PY_MAJOR_VERSION < 3 && (__PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT)
  if (__Pyx_init_sys_getdefaultencoding_params() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  if (__pyx_module_is_main_example1) {
    if (PyObject_SetAttr(__pyx_m, __pyx_n_s_name, __pyx_n_s_main) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  }
  #if PY_MAJOR_VERSION >= 3
  {
    PyObject *modules = PyImport_GetModuleDict(); if (unlikely(!modules)) __PYX_ERR(0, 1, __pyx_L1_error)
    if (!PyDict_GetItemString(modules, "example1")) {
      if (unlikely(PyDict_SetItemString(modules, "example1", __pyx_m) < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
    }
  }
  #endif

  if (__Pyx_InitCachedBuiltins() < 0) __PYX_ERR(0, 1, __pyx_L1_error)

  if (__Pyx_InitCachedConstants() < 0) __PYX_ERR(0, 1, __pyx_L1_error)

  (void)__Pyx_modinit_global_init_code();
  (void)__Pyx_modinit_variable_export_code();
  (void)__Pyx_modinit_function_export_code();
  (void)__Pyx_modinit_type_init_code();
  (void)__Pyx_modinit_type_import_code();
  (void)__Pyx_modinit_variable_import_code();
  (void)__Pyx_modinit_function_import_code();

  #if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
  if (__Pyx_patch_abc() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif






  if (PyDict_SetItem(__pyx_d, __pyx_n_s_author, __pyx_kp_s_William_Huanshan_Chuang) < 0) __PYX_ERR(0, 1, __pyx_L1_error)







  if (PyDict_SetItem(__pyx_d, __pyx_n_s_version, __pyx_kp_s_1_0_1) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
# 16583 "example1.c"
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_email, __pyx_kp_s_wchuang2_mail_sfsu_edu) < 0) __PYX_ERR(0, 3, __pyx_L1_error)
# 16592 "example1.c"
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_math, 0, -1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_math, __pyx_t_1) < 0) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16604 "example1.c"
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_statistics, 0, -1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_statistics, __pyx_t_1) < 0) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16616 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_1Cartesian_complex_mul, 0, __pyx_n_s_Cartesian_complex_mul, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__4)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Cartesian_complex_mul, __pyx_t_1) < 0) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16628 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_3Cartesian_complex_scalar_mul, 0, __pyx_n_s_Cartesian_complex_scalar_mul, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__6)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Cartesian_complex_scalar_mul, __pyx_t_1) < 0) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16640 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_5Cartesian_complex_add, 0, __pyx_n_s_Cartesian_complex_add, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__8)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Cartesian_complex_add, __pyx_t_1) < 0) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16652 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_7Cartesian_complex_divide, 0, __pyx_n_s_Cartesian_complex_divide, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__10)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Cartesian_complex_divide, __pyx_t_1) < 0) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16664 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_9Cartesian_complex_modulus, 0, __pyx_n_s_Cartesian_complex_modulus, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__12)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 35, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Cartesian_complex_modulus, __pyx_t_1) < 0) __PYX_ERR(0, 35, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16676 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_11Cartesian_complex_complex_conjugate, 0, __pyx_n_s_Cartesian_complex_complex_conjug, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__14)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 38, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Cartesian_complex_complex_conjug, __pyx_t_1) < 0) __PYX_ERR(0, 38, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16688 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_13Cartesian_complex_complex_to_polar, 0, __pyx_n_s_Cartesian_complex_complex_to_pol, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__16)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 41, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Cartesian_complex_complex_to_pol, __pyx_t_1) < 0) __PYX_ERR(0, 41, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16700 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_15Polar_complex_complex_to_Cartesian, 0, __pyx_n_s_Polar_complex_complex_to_Cartesi, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__18)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Polar_complex_complex_to_Cartesi, __pyx_t_1) < 0) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16712 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_17Polar_complex_conjugate, 0, __pyx_n_s_Polar_complex_conjugate, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__20)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 59, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Polar_complex_conjugate, __pyx_t_1) < 0) __PYX_ERR(0, 59, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16724 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_19Polar_complex_mul, 0, __pyx_n_s_Polar_complex_mul, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__22)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Polar_complex_mul, __pyx_t_1) < 0) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16736 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_21Polar_complex_divide, 0, __pyx_n_s_Polar_complex_divide, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__24)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 68, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Polar_complex_divide, __pyx_t_1) < 0) __PYX_ERR(0, 68, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16748 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_23Polar_complex_add, 0, __pyx_n_s_Polar_complex_add, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__26)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 74, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Polar_complex_add, __pyx_t_1) < 0) __PYX_ERR(0, 74, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16760 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_25real_matrix_addition, 0, __pyx_n_s_real_matrix_addition, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__28)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_real_matrix_addition, __pyx_t_1) < 0) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16772 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_27Cartesian_complex_matrix_addition, 0, __pyx_n_s_Cartesian_complex_matrix_additio, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__30)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 93, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Cartesian_complex_matrix_additio, __pyx_t_1) < 0) __PYX_ERR(0, 93, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16784 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_29real_matrix_multiplication, 0, __pyx_n_s_real_matrix_multiplication, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__32)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_real_matrix_multiplication, __pyx_t_1) < 0) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16796 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_31Cartesian_complex_matrix_multiplication, 0, __pyx_n_s_Cartesian_complex_matrix_multipl, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__34)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 128, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Cartesian_complex_matrix_multipl, __pyx_t_1) < 0) __PYX_ERR(0, 128, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16808 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_33real_matrix_inverse, 0, __pyx_n_s_real_matrix_inverse, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__36)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 142, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_real_matrix_inverse, __pyx_t_1) < 0) __PYX_ERR(0, 142, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16820 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_35Cartesian_complex_matrix_inverse, 0, __pyx_n_s_Cartesian_complex_matrix_inverse, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__38)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Cartesian_complex_matrix_inverse, __pyx_t_1) < 0) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16832 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_37Cartesian_radial_hyperbolic_distance, 0, __pyx_n_s_Cartesian_radial_hyperbolic_dist, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__40)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 173, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Cartesian_radial_hyperbolic_dist, __pyx_t_1) < 0) __PYX_ERR(0, 173, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16844 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_39operator_T, 0, __pyx_n_s_operator_T, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__42)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 177, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_operator_T, __pyx_t_1) < 0) __PYX_ERR(0, 177, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16856 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_41operator_R, 0, __pyx_n_s_operator_R, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__44)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_operator_R, __pyx_t_1) < 0) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16868 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_43classification_point, 0, __pyx_n_s_classification_point, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__46)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 206, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_classification_point, __pyx_t_1) < 0) __PYX_ERR(0, 206, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16880 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_45check_T_generate_a_Schottky, 0, __pyx_n_s_check_T_generate_a_Schottky, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__48)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 209, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_check_T_generate_a_Schottky, __pyx_t_1) < 0) __PYX_ERR(0, 209, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16892 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_47Tz, 0, __pyx_n_s_Tz, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__50)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 222, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Tz, __pyx_t_1) < 0) __PYX_ERR(0, 222, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16904 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_49Gamma0, 0, __pyx_n_s_Gamma0, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__52)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 238, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Gamma0, __pyx_t_1) < 0) __PYX_ERR(0, 238, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16916 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_51Hyperbolic_Distance_Gamma0, 0, __pyx_n_s_Hyperbolic_Distance_Gamma0, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__54)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 299, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Hyperbolic_Distance_Gamma0, __pyx_t_1) < 0) __PYX_ERR(0, 299, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16928 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_53Exp_negative_Hyperbolic_Distance_Gamma0, 0, __pyx_n_s_Exp_negative_Hyperbolic_Distance, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__56)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 364, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Exp_negative_Hyperbolic_Distance, __pyx_t_1) < 0) __PYX_ERR(0, 364, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16940 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_55Improved_Exp_negative_Hyperbolic_Distance_Gamma0, 0, __pyx_n_s_Improved_Exp_negative_Hyperbolic, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__58)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Improved_Exp_negative_Hyperbolic, __pyx_t_1) < 0) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
# 16952 "example1.c"
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_8example1_57examples_of_10000, 0, __pyx_n_s_examples_of_10000, NULL, __pyx_n_s_example1, __pyx_d, ((PyObject *)__pyx_codeobj__60)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 498, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_examples_of_10000, __pyx_t_1) < 0) __PYX_ERR(0, 498, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;






  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_examples_of_10000); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 546, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 546, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_initial, __pyx_float_0_3) < 0) __PYX_ERR(0, 546, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_increment, __pyx_float_0_000001) < 0) __PYX_ERR(0, 546, __pyx_L1_error)
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 546, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;






  __pyx_t_3 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_test_2, __pyx_t_3) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;



  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  if (__pyx_m) {
    if (__pyx_d) {
      __Pyx_AddTraceback("init example1", __pyx_clineno, __pyx_lineno, __pyx_filename);
    }
    Py_CLEAR(__pyx_m);
  } else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_ImportError, "init example1");
  }
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  return (__pyx_m != NULL) ? 0 : -1;
  #elif PY_MAJOR_VERSION >= 3
  return __pyx_m;
  #else
  return;
  #endif
}



#if CYTHON_REFNANNY
static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname) {
    PyObject *m = NULL, *p = NULL;
    void *r = NULL;
    m = PyImport_ImportModule(modname);
    if (!m) goto end;
    p = PyObject_GetAttrString(m, "RefNannyAPI");
    if (!p) goto end;
    r = PyLong_AsVoidPtr(p);
end:
    Py_XDECREF(p);
    Py_XDECREF(m);
    return (__Pyx_RefNannyAPIStruct *)r;
}
#endif


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name) {
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_getattro))
        return tp->tp_getattro(obj, attr_name);
#if PY_MAJOR_VERSION < 3
    if (likely(tp->tp_getattr))
        return tp->tp_getattr(obj, PyString_AS_STRING(attr_name));
#endif
    return PyObject_GetAttr(obj, attr_name);
}
#endif


static PyObject *__Pyx_GetBuiltinName(PyObject *name) {
    PyObject* result = __Pyx_PyObject_GetAttrStr(__pyx_b, name);
    if (unlikely(!result)) {
        PyErr_Format(PyExc_NameError,
#if PY_MAJOR_VERSION >= 3
            "name '%U' is not defined", name);
#else
            "name '%.200s' is not defined", PyString_AS_STRING(name));
#endif
    }
    return result;
}


static void __Pyx_RaiseArgtupleInvalid(
    const char* func_name,
    int exact,
    Py_ssize_t num_min,
    Py_ssize_t num_max,
    Py_ssize_t num_found)
{
    Py_ssize_t num_expected;
    const char *more_or_less;
    if (num_found < num_min) {
        num_expected = num_min;
        more_or_less = "at least";
    } else {
        num_expected = num_max;
        more_or_less = "at most";
    }
    if (exact) {
        more_or_less = "exactly";
    }
    PyErr_Format(PyExc_TypeError,
                 "%.200s() takes %.8s %" CYTHON_FORMAT_SSIZE_T "d positional argument%.1s (%" CYTHON_FORMAT_SSIZE_T "d given)",
                 func_name, more_or_less, num_expected,
                 (num_expected == 1) ? "" : "s", num_found);
}


static void __Pyx_RaiseDoubleKeywordsError(
    const char* func_name,
    PyObject* kw_name)
{
    PyErr_Format(PyExc_TypeError,
        #if PY_MAJOR_VERSION >= 3
        "%s() got multiple values for keyword argument '%U'", func_name, kw_name);
        #else
        "%s() got multiple values for keyword argument '%s'", func_name,
        PyString_AsString(kw_name));
        #endif
}


static int __Pyx_ParseOptionalKeywords(
    PyObject *kwds,
    PyObject **argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    const char* function_name)
{
    PyObject *key = 0, *value = 0;
    Py_ssize_t pos = 0;
    PyObject*** name;
    PyObject*** first_kw_arg = argnames + num_pos_args;
    while (PyDict_Next(kwds, &pos, &key, &value)) {
        name = first_kw_arg;
        while (*name && (**name != key)) name++;
        if (*name) {
            values[name-argnames] = value;
            continue;
        }
        name = first_kw_arg;
        #if PY_MAJOR_VERSION < 3
        if (likely(PyString_Check(key))) {
            while (*name) {
                if ((CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**name) == PyString_GET_SIZE(key))
                        && _PyString_Eq(**name, key)) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    if ((**argname == key) || (
                            (CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**argname) == PyString_GET_SIZE(key))
                             && _PyString_Eq(**argname, key))) {
                        goto arg_passed_twice;
                    }
                    argname++;
                }
            }
        } else
        #endif
        if (likely(PyUnicode_Check(key))) {
            while (*name) {
                int cmp = (**name == key) ? 0 :
                #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                    (__Pyx_PyUnicode_GET_LENGTH(**name) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                #endif
                    PyUnicode_Compare(**name, key);
                if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                if (cmp == 0) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    int cmp = (**argname == key) ? 0 :
                    #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                        (__Pyx_PyUnicode_GET_LENGTH(**argname) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                    #endif
                        PyUnicode_Compare(**argname, key);
                    if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                    if (cmp == 0) goto arg_passed_twice;
                    argname++;
                }
            }
        } else
            goto invalid_keyword_type;
        if (kwds2) {
            if (unlikely(PyDict_SetItem(kwds2, key, value))) goto bad;
        } else {
            goto invalid_keyword;
        }
    }
    return 0;
arg_passed_twice:
    __Pyx_RaiseDoubleKeywordsError(function_name, key);
    goto bad;
invalid_keyword_type:
    PyErr_Format(PyExc_TypeError,
        "%.200s() keywords must be strings", function_name);
    goto bad;
invalid_keyword:
    PyErr_Format(PyExc_TypeError,
    #if PY_MAJOR_VERSION < 3
        "%.200s() got an unexpected keyword argument '%.200s'",
        function_name, PyString_AsString(key));
    #else
        "%s() got an unexpected keyword argument '%U'",
        function_name, key);
    #endif
bad:
    return -1;
}


static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j) {
    PyObject *r;
    if (!j) return NULL;
    r = PyObject_GetItem(o, j);
    Py_DECREF(j);
    return r;
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyList_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyList_GET_SIZE(o)))) {
        PyObject *r = PyList_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyTuple_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyTuple_GET_SIZE(o)))) {
        PyObject *r = PyTuple_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i, int is_list,
                                                     CYTHON_NCP_UNUSED int wraparound,
                                                     CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS && CYTHON_USE_TYPE_SLOTS
    if (is_list || PyList_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyList_GET_SIZE(o);
        if ((!boundscheck) || (likely(__Pyx_is_valid_index(n, PyList_GET_SIZE(o))))) {
            PyObject *r = PyList_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    }
    else if (PyTuple_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyTuple_GET_SIZE(o);
        if ((!boundscheck) || likely(__Pyx_is_valid_index(n, PyTuple_GET_SIZE(o)))) {
            PyObject *r = PyTuple_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    } else {
        PySequenceMethods *m = Py_TYPE(o)->tp_as_sequence;
        if (likely(m && m->sq_item)) {
            if (wraparound && unlikely(i < 0) && likely(m->sq_length)) {
                Py_ssize_t l = m->sq_length(o);
                if (likely(l >= 0)) {
                    i += l;
                } else {
                    if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                        return NULL;
                    PyErr_Clear();
                }
            }
            return m->sq_item(o, i);
        }
    }
#else
    if (is_list || PySequence_Check(o)) {
        return PySequence_GetItem(o, i);
    }
#endif
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
}


static double __Pyx__PyObject_AsDouble(PyObject* obj) {
    PyObject* float_value;
#if !CYTHON_USE_TYPE_SLOTS
    float_value = PyNumber_Float(obj); if ((0)) goto bad;
#else
    PyNumberMethods *nb = Py_TYPE(obj)->tp_as_number;
    if (likely(nb) && likely(nb->nb_float)) {
        float_value = nb->nb_float(obj);
        if (likely(float_value) && unlikely(!PyFloat_Check(float_value))) {
            PyErr_Format(PyExc_TypeError,
                "__float__ returned non-float (type %.200s)",
                Py_TYPE(float_value)->tp_name);
            Py_DECREF(float_value);
            goto bad;
        }
    } else if (PyUnicode_CheckExact(obj) || PyBytes_CheckExact(obj)) {
#if PY_MAJOR_VERSION >= 3
        float_value = PyFloat_FromString(obj);
#else
        float_value = PyFloat_FromString(obj, 0);
#endif
    } else {
        PyObject* args = PyTuple_New(1);
        if (unlikely(!args)) goto bad;
        PyTuple_SET_ITEM(args, 0, obj);
        float_value = PyObject_Call((PyObject*)&PyFloat_Type, args, 0);
        PyTuple_SET_ITEM(args, 0, 0);
        Py_DECREF(args);
    }
#endif
    if (likely(float_value)) {
        double value = PyFloat_AS_DOUBLE(float_value);
        Py_DECREF(float_value);
        return value;
    }
bad:
    return (double)-1;
}


#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    return likely(dict) ? __PYX_GET_DICT_VERSION(dict) : 0;
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj) {
    PyObject **dictptr = NULL;
    Py_ssize_t offset = Py_TYPE(obj)->tp_dictoffset;
    if (offset) {
#if CYTHON_COMPILING_IN_CPYTHON
        dictptr = (likely(offset > 0)) ? (PyObject **) ((char *)obj + offset) : _PyObject_GetDictPtr(obj);
#else
        dictptr = _PyObject_GetDictPtr(obj);
#endif
    }
    return (dictptr && *dictptr) ? __PYX_GET_DICT_VERSION(*dictptr) : 0;
}
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    if (unlikely(!dict) || unlikely(tp_dict_version != __PYX_GET_DICT_VERSION(dict)))
        return 0;
    return obj_dict_version == __Pyx_get_object_dict_version(obj);
}
#endif


#if CYTHON_USE_DICT_VERSIONS
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value)
#else
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name)
#endif
{
    PyObject *result;
#if !CYTHON_AVOID_BORROWED_REFS
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1
    result = _PyDict_GetItem_KnownHash(__pyx_d, name, ((PyASCIIObject *) name)->hash);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    } else if (unlikely(PyErr_Occurred())) {
        return NULL;
    }
#else
    result = PyDict_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
#endif
#else
    result = PyObject_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
    PyErr_Clear();
#endif
    return __Pyx_GetBuiltinName(name);
}


#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject * __Pyx_PyCFunction_FastCall(PyObject *func_obj, PyObject **args, Py_ssize_t nargs) {
    PyCFunctionObject *func = (PyCFunctionObject*)func_obj;
    PyCFunction meth = PyCFunction_GET_FUNCTION(func);
    PyObject *self = PyCFunction_GET_SELF(func);
    int flags = PyCFunction_GET_FLAGS(func);
    assert(PyCFunction_Check(func));
    assert(METH_FASTCALL == (flags & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)));
    assert(nargs >= 0);
    assert(nargs == 0 || args != NULL);



    assert(!PyErr_Occurred());
    if ((PY_VERSION_HEX < 0x030700A0) || unlikely(flags & METH_KEYWORDS)) {
        return (*((__Pyx_PyCFunctionFastWithKeywords)(void*)meth)) (self, args, nargs, NULL);
    } else {
        return (*((__Pyx_PyCFunctionFast)(void*)meth)) (self, args, nargs);
    }
}
#endif


#if CYTHON_FAST_PYCALL
static PyObject* __Pyx_PyFunction_FastCallNoKw(PyCodeObject *co, PyObject **args, Py_ssize_t na,
                                               PyObject *globals) {
    PyFrameObject *f;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject **fastlocals;
    Py_ssize_t i;
    PyObject *result;
    assert(globals != NULL);




    assert(tstate != NULL);
    f = PyFrame_New(tstate, co, globals, NULL);
    if (f == NULL) {
        return NULL;
    }
    fastlocals = __Pyx_PyFrame_GetLocalsplus(f);
    for (i = 0; i < na; i++) {
        Py_INCREF(*args);
        fastlocals[i] = *args++;
    }
    result = PyEval_EvalFrameEx(f,0);
    ++tstate->recursion_depth;
    Py_DECREF(f);
    --tstate->recursion_depth;
    return result;
}
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs) {
    PyCodeObject *co = (PyCodeObject *)PyFunction_GET_CODE(func);
    PyObject *globals = PyFunction_GET_GLOBALS(func);
    PyObject *argdefs = PyFunction_GET_DEFAULTS(func);
    PyObject *closure;
#if PY_MAJOR_VERSION >= 3
    PyObject *kwdefs;
#endif
    PyObject *kwtuple, **k;
    PyObject **d;
    Py_ssize_t nd;
    Py_ssize_t nk;
    PyObject *result;
    assert(kwargs == NULL || PyDict_Check(kwargs));
    nk = kwargs ? PyDict_Size(kwargs) : 0;
    if (Py_EnterRecursiveCall((char*)" while calling a Python object")) {
        return NULL;
    }
    if (
#if PY_MAJOR_VERSION >= 3
            co->co_kwonlyargcount == 0 &&
#endif
            likely(kwargs == NULL || nk == 0) &&
            co->co_flags == (CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE)) {
        if (argdefs == NULL && co->co_argcount == nargs) {
            result = __Pyx_PyFunction_FastCallNoKw(co, args, nargs, globals);
            goto done;
        }
        else if (nargs == 0 && argdefs != NULL
                 && co->co_argcount == Py_SIZE(argdefs)) {


            args = &PyTuple_GET_ITEM(argdefs, 0);
            result =__Pyx_PyFunction_FastCallNoKw(co, args, Py_SIZE(argdefs), globals);
            goto done;
        }
    }
    if (kwargs != NULL) {
        Py_ssize_t pos, i;
        kwtuple = PyTuple_New(2 * nk);
        if (kwtuple == NULL) {
            result = NULL;
            goto done;
        }
        k = &PyTuple_GET_ITEM(kwtuple, 0);
        pos = i = 0;
        while (PyDict_Next(kwargs, &pos, &k[i], &k[i+1])) {
            Py_INCREF(k[i]);
            Py_INCREF(k[i+1]);
            i += 2;
        }
        nk = i / 2;
    }
    else {
        kwtuple = NULL;
        k = NULL;
    }
    closure = PyFunction_GET_CLOSURE(func);
#if PY_MAJOR_VERSION >= 3
    kwdefs = PyFunction_GET_KW_DEFAULTS(func);
#endif
    if (argdefs != NULL) {
        d = &PyTuple_GET_ITEM(argdefs, 0);
        nd = Py_SIZE(argdefs);
    }
    else {
        d = NULL;
        nd = 0;
    }
#if PY_MAJOR_VERSION >= 3
    result = PyEval_EvalCodeEx((PyObject*)co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, kwdefs, closure);
#else
    result = PyEval_EvalCodeEx(co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, closure);
#endif
    Py_XDECREF(kwtuple);
done:
    Py_LeaveRecursiveCall();
    return result;
}
#endif
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    PyObject *result;
    ternaryfunc call = func->ob_type->tp_call;
    if (unlikely(!call))
        return PyObject_Call(func, arg, kw);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = (*call)(func, arg, kw);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif


static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2) {
    PyObject *args, *result = NULL;
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyFunction_FastCall(function, args, 2);
    }
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyCFunction_FastCall(function, args, 2);
    }
    #endif
    args = PyTuple_New(2);
    if (unlikely(!args)) goto done;
    Py_INCREF(arg1);
    PyTuple_SET_ITEM(args, 0, arg1);
    Py_INCREF(arg2);
    PyTuple_SET_ITEM(args, 1, arg2);
    Py_INCREF(function);
    result = __Pyx_PyObject_Call(function, args, NULL);
    Py_DECREF(args);
    Py_DECREF(function);
done:
    return result;
}


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg) {
    PyObject *self, *result;
    PyCFunction cfunc;
    cfunc = PyCFunction_GET_FUNCTION(func);
    self = PyCFunction_GET_SELF(func);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = cfunc(self, arg);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static PyObject* __Pyx__PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_New(1);
    if (unlikely(!args)) return NULL;
    Py_INCREF(arg);
    PyTuple_SET_ITEM(args, 0, arg);
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, &arg, 1);
    }
#endif
    if (likely(PyCFunction_Check(func))) {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_O)) {
            return __Pyx_PyObject_CallMethO(func, arg);
#if CYTHON_FAST_PYCCALL
        } else if (PyCFunction_GET_FLAGS(func) & METH_FASTCALL) {
            return __Pyx_PyCFunction_FastCall(func, &arg, 1);
#endif
        }
    }
    return __Pyx__PyObject_CallOneArg(func, arg);
}
#else
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_Pack(1, arg);
    if (unlikely(!args)) return NULL;
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
#endif


#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_AddObjC(PyObject *op1, PyObject *op2, CYTHON_UNUSED long intval, int inplace, int zerodivision_check) {
    (void)inplace;
    (void)zerodivision_check;
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        const long b = intval;
        long x;
        long a = PyInt_AS_LONG(op1);
            x = (long)((unsigned long)a + b);
            if (likely((x^a) >= 0 || (x^b) >= 0))
                return PyInt_FromLong(x);
            return PyLong_Type.tp_as_number->nb_add(op1, op2);
    }
    #endif
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        const long b = intval;
        long a, x;
#ifdef HAVE_LONG_LONG
        const PY_LONG_LONG llb = intval;
        PY_LONG_LONG lla, llx;
#endif
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        const Py_ssize_t size = Py_SIZE(op1);
        if (likely(__Pyx_sst_abs(size) <= 1)) {
            a = likely(size) ? digits[0] : 0;
            if (size == -1) a = -a;
        } else {
            switch (size) {
                case -2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = (long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = (long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = (long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                default: return PyLong_Type.tp_as_number->nb_add(op1, op2);
            }
        }
                x = a + b;
            return PyLong_FromLong(x);
#ifdef HAVE_LONG_LONG
        long_long:
                llx = lla + llb;
            return PyLong_FromLongLong(llx);
#endif


    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        const long b = intval;
        double a = PyFloat_AS_DOUBLE(op1);
            double result;
            PyFPE_START_PROTECT("add", return NULL)
            result = ((double)a) + (double)b;
            PyFPE_END_PROTECT(result)
            return PyFloat_FromDouble(result);
    }
    return (inplace ? PyNumber_InPlaceAdd : PyNumber_Add)(op1, op2);
}
#endif


#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_SubtractObjC(PyObject *op1, PyObject *op2, CYTHON_UNUSED long intval, int inplace, int zerodivision_check) {
    (void)inplace;
    (void)zerodivision_check;
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        const long b = intval;
        long x;
        long a = PyInt_AS_LONG(op1);
            x = (long)((unsigned long)a - b);
            if (likely((x^a) >= 0 || (x^~b) >= 0))
                return PyInt_FromLong(x);
            return PyLong_Type.tp_as_number->nb_subtract(op1, op2);
    }
    #endif
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        const long b = intval;
        long a, x;
#ifdef HAVE_LONG_LONG
        const PY_LONG_LONG llb = intval;
        PY_LONG_LONG lla, llx;
#endif
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        const Py_ssize_t size = Py_SIZE(op1);
        if (likely(__Pyx_sst_abs(size) <= 1)) {
            a = likely(size) ? digits[0] : 0;
            if (size == -1) a = -a;
        } else {
            switch (size) {
                case -2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = (long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = (long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = (long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                default: return PyLong_Type.tp_as_number->nb_subtract(op1, op2);
            }
        }
                x = a - b;
            return PyLong_FromLong(x);
#ifdef HAVE_LONG_LONG
        long_long:
                llx = lla - llb;
            return PyLong_FromLongLong(llx);
#endif


    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        const long b = intval;
        double a = PyFloat_AS_DOUBLE(op1);
            double result;
            PyFPE_START_PROTECT("subtract", return NULL)
            result = ((double)a) - (double)b;
            PyFPE_END_PROTECT(result)
            return PyFloat_FromDouble(result);
    }
    return (inplace ? PyNumber_InPlaceSubtract : PyNumber_Subtract)(op1, op2);
}
#endif


static CYTHON_INLINE PyObject* __Pyx_PyInt_EqObjC(PyObject *op1, PyObject *op2, CYTHON_UNUSED long intval, CYTHON_UNUSED long inplace) {
    if (op1 == op2) {
        Py_RETURN_TRUE;
    }
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        const long b = intval;
        long a = PyInt_AS_LONG(op1);
        if (a == b) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    #endif
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        int unequal;
        unsigned long uintval;
        Py_ssize_t size = Py_SIZE(op1);
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        if (intval == 0) {
            if (size == 0) Py_RETURN_TRUE; else Py_RETURN_FALSE;
        } else if (intval < 0) {
            if (size >= 0)
                Py_RETURN_FALSE;
            intval = -intval;
            size = -size;
        } else {
            if (size <= 0)
                Py_RETURN_FALSE;
        }
        uintval = (unsigned long) intval;
#if PyLong_SHIFT * 4 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 4)) {
            unequal = (size != 5) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[2] != ((uintval >> (2 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[3] != ((uintval >> (3 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[4] != ((uintval >> (4 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
#if PyLong_SHIFT * 3 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 3)) {
            unequal = (size != 4) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[2] != ((uintval >> (2 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[3] != ((uintval >> (3 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
#if PyLong_SHIFT * 2 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 2)) {
            unequal = (size != 3) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[2] != ((uintval >> (2 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
#if PyLong_SHIFT * 1 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 1)) {
            unequal = (size != 2) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
            unequal = (size != 1) || (((unsigned long) digits[0]) != (uintval & (unsigned long) PyLong_MASK));
        if (unequal == 0) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        const long b = intval;
        double a = PyFloat_AS_DOUBLE(op1);
        if ((double)a == (double)b) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    return (
        PyObject_RichCompare(op1, op2, Py_EQ));
}


static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method) {
    PyObject *attr;
#if CYTHON_UNPACK_METHODS && CYTHON_COMPILING_IN_CPYTHON && CYTHON_USE_PYTYPE_LOOKUP
    PyTypeObject *tp = Py_TYPE(obj);
    PyObject *descr;
    descrgetfunc f = NULL;
    PyObject **dictptr, *dict;
    int meth_found = 0;
    assert (*method == NULL);
    if (unlikely(tp->tp_getattro != PyObject_GenericGetAttr)) {
        attr = __Pyx_PyObject_GetAttrStr(obj, name);
        goto try_unpack;
    }
    if (unlikely(tp->tp_dict == NULL) && unlikely(PyType_Ready(tp) < 0)) {
        return 0;
    }
    descr = _PyType_Lookup(tp, name);
    if (likely(descr != NULL)) {
        Py_INCREF(descr);
#if PY_MAJOR_VERSION >= 3
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type)))
        #endif
#else
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr)))
        #endif
#endif
        {
            meth_found = 1;
        } else {
            f = Py_TYPE(descr)->tp_descr_get;
            if (f != NULL && PyDescr_IsData(descr)) {
                attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
                Py_DECREF(descr);
                goto try_unpack;
            }
        }
    }
    dictptr = _PyObject_GetDictPtr(obj);
    if (dictptr != NULL && (dict = *dictptr) != NULL) {
        Py_INCREF(dict);
        attr = __Pyx_PyDict_GetItemStr(dict, name);
        if (attr != NULL) {
            Py_INCREF(attr);
            Py_DECREF(dict);
            Py_XDECREF(descr);
            goto try_unpack;
        }
        Py_DECREF(dict);
    }
    if (meth_found) {
        *method = descr;
        return 1;
    }
    if (f != NULL) {
        attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
        Py_DECREF(descr);
        goto try_unpack;
    }
    if (descr != NULL) {
        *method = descr;
        return 0;
    }
    PyErr_Format(PyExc_AttributeError,
#if PY_MAJOR_VERSION >= 3
                 "'%.50s' object has no attribute '%U'",
                 tp->tp_name, name);
#else
                 "'%.50s' object has no attribute '%.400s'",
                 tp->tp_name, PyString_AS_STRING(name));
#endif
    return 0;
#else
    attr = __Pyx_PyObject_GetAttrStr(obj, name);
    goto try_unpack;
#endif
try_unpack:
#if CYTHON_UNPACK_METHODS
    if (likely(attr) && PyMethod_Check(attr) && likely(PyMethod_GET_SELF(attr) == obj)) {
        PyObject *function = PyMethod_GET_FUNCTION(attr);
        Py_INCREF(function);
        Py_DECREF(attr);
        *method = function;
        return 1;
    }
#endif
    *method = attr;
    return 0;
}


static PyObject* __Pyx__PyObject_CallMethod1(PyObject* method, PyObject* arg) {
    PyObject *result = __Pyx_PyObject_CallOneArg(method, arg);
    Py_DECREF(method);
    return result;
}
static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg) {
    PyObject *method = NULL, *result;
    int is_method = __Pyx_PyObject_GetMethod(obj, method_name, &method);
    if (likely(is_method)) {
        result = __Pyx_PyObject_Call2Args(method, obj, arg);
        Py_DECREF(method);
        return result;
    }
    if (unlikely(!method)) return NULL;
    return __Pyx__PyObject_CallMethod1(method, arg);
}


static CYTHON_INLINE int __Pyx_PyObject_Append(PyObject* L, PyObject* x) {
    if (likely(PyList_CheckExact(L))) {
        if (unlikely(__Pyx_PyList_Append(L, x) < 0)) return -1;
    } else {
        PyObject* retval = __Pyx_PyObject_CallMethod1(L, __pyx_n_s_append, x);
        if (unlikely(!retval))
            return -1;
        Py_DECREF(retval);
    }
    return 0;
}


static CYTHON_INLINE PyObject* __Pyx_PyInt_NeObjC(PyObject *op1, PyObject *op2, CYTHON_UNUSED long intval, CYTHON_UNUSED long inplace) {
    if (op1 == op2) {
        Py_RETURN_FALSE;
    }
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        const long b = intval;
        long a = PyInt_AS_LONG(op1);
        if (a != b) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    #endif
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        int unequal;
        unsigned long uintval;
        Py_ssize_t size = Py_SIZE(op1);
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        if (intval == 0) {
            if (size != 0) Py_RETURN_TRUE; else Py_RETURN_FALSE;
        } else if (intval < 0) {
            if (size >= 0)
                Py_RETURN_TRUE;
            intval = -intval;
            size = -size;
        } else {
            if (size <= 0)
                Py_RETURN_TRUE;
        }
        uintval = (unsigned long) intval;
#if PyLong_SHIFT * 4 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 4)) {
            unequal = (size != 5) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[2] != ((uintval >> (2 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[3] != ((uintval >> (3 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[4] != ((uintval >> (4 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
#if PyLong_SHIFT * 3 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 3)) {
            unequal = (size != 4) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[2] != ((uintval >> (2 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[3] != ((uintval >> (3 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
#if PyLong_SHIFT * 2 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 2)) {
            unequal = (size != 3) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[2] != ((uintval >> (2 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
#if PyLong_SHIFT * 1 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 1)) {
            unequal = (size != 2) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
            unequal = (size != 1) || (((unsigned long) digits[0]) != (uintval & (unsigned long) PyLong_MASK));
        if (unequal != 0) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        const long b = intval;
        double a = PyFloat_AS_DOUBLE(op1);
        if ((double)a != (double)b) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    return (
        PyObject_RichCompare(op1, op2, Py_NE));
}


#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem *
__Pyx_PyErr_GetTopmostException(PyThreadState *tstate)
{
    _PyErr_StackItem *exc_info = tstate->exc_info;
    while ((exc_info->exc_type == NULL || exc_info->exc_type == Py_None) &&
           exc_info->previous_item != NULL)
    {
        exc_info = exc_info->previous_item;
    }
    return exc_info;
}
#endif


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = __Pyx_PyErr_GetTopmostException(tstate);
    *type = exc_info->exc_type;
    *value = exc_info->exc_value;
    *tb = exc_info->exc_traceback;
    #else
    *type = tstate->exc_type;
    *value = tstate->exc_value;
    *tb = tstate->exc_traceback;
    #endif
    Py_XINCREF(*type);
    Py_XINCREF(*value);
    Py_XINCREF(*tb);
}
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = type;
    exc_info->exc_value = value;
    exc_info->exc_traceback = tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = type;
    tstate->exc_value = value;
    tstate->exc_traceback = tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
#endif


#if CYTHON_FAST_THREAD_STATE
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb)
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb)
#endif
{
    PyObject *local_type, *local_value, *local_tb;
#if CYTHON_FAST_THREAD_STATE
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    local_type = tstate->curexc_type;
    local_value = tstate->curexc_value;
    local_tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
#else
    PyErr_Fetch(&local_type, &local_value, &local_tb);
#endif
    PyErr_NormalizeException(&local_type, &local_value, &local_tb);
#if CYTHON_FAST_THREAD_STATE
    if (unlikely(tstate->curexc_type))
#else
    if (unlikely(PyErr_Occurred()))
#endif
        goto bad;
    #if PY_MAJOR_VERSION >= 3
    if (local_tb) {
        if (unlikely(PyException_SetTraceback(local_value, local_tb) < 0))
            goto bad;
    }
    #endif
    Py_XINCREF(local_tb);
    Py_XINCREF(local_type);
    Py_XINCREF(local_value);
    *type = local_type;
    *value = local_value;
    *tb = local_tb;
#if CYTHON_FAST_THREAD_STATE
    #if CYTHON_USE_EXC_INFO_STACK
    {
        _PyErr_StackItem *exc_info = tstate->exc_info;
        tmp_type = exc_info->exc_type;
        tmp_value = exc_info->exc_value;
        tmp_tb = exc_info->exc_traceback;
        exc_info->exc_type = local_type;
        exc_info->exc_value = local_value;
        exc_info->exc_traceback = local_tb;
    }
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = local_type;
    tstate->exc_value = local_value;
    tstate->exc_traceback = local_tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
#else
    PyErr_SetExcInfo(local_type, local_value, local_tb);
#endif
    return 0;
bad:
    *type = 0;
    *value = 0;
    *tb = 0;
    Py_XDECREF(local_type);
    Py_XDECREF(local_value);
    Py_XDECREF(local_tb);
    return -1;
}


#if CYTHON_USE_TYPE_SLOTS
static PyObject *__Pyx_PyObject_GetIndex(PyObject *obj, PyObject* index) {
    PyObject *runerr;
    Py_ssize_t key_value;
    PySequenceMethods *m = Py_TYPE(obj)->tp_as_sequence;
    if (unlikely(!(m && m->sq_item))) {
        PyErr_Format(PyExc_TypeError, "'%.200s' object is not subscriptable", Py_TYPE(obj)->tp_name);
        return NULL;
    }
    key_value = __Pyx_PyIndex_AsSsize_t(index);
    if (likely(key_value != -1 || !(runerr = PyErr_Occurred()))) {
        return __Pyx_GetItemInt_Fast(obj, key_value, 0, 1, 1);
    }
    if (PyErr_GivenExceptionMatches(runerr, PyExc_OverflowError)) {
        PyErr_Clear();
        PyErr_Format(PyExc_IndexError, "cannot fit '%.200s' into an index-sized integer", Py_TYPE(index)->tp_name);
    }
    return NULL;
}
static PyObject *__Pyx_PyObject_GetItem(PyObject *obj, PyObject* key) {
    PyMappingMethods *m = Py_TYPE(obj)->tp_as_mapping;
    if (likely(m && m->mp_subscript)) {
        return m->mp_subscript(obj, key);
    }
    return __Pyx_PyObject_GetIndex(obj, key);
}
#endif


static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level) {
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    #if PY_MAJOR_VERSION < 3
    PyObject *py_import;
    py_import = __Pyx_PyObject_GetAttrStr(__pyx_b, __pyx_n_s_import);
    if (!py_import)
        goto bad;
    #endif
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    {
        #if PY_MAJOR_VERSION >= 3
        if (level == -1) {
            if ((1) && (strchr(__Pyx_MODULE_NAME, '.'))) {
                module = PyImport_ImportModuleLevelObject(
                    name, global_dict, empty_dict, list, 1);
                if (!module) {
                    if (!PyErr_ExceptionMatches(PyExc_ImportError))
                        goto bad;
                    PyErr_Clear();
                }
            }
            level = 0;
        }
        #endif
        if (!module) {
            #if PY_MAJOR_VERSION < 3
            PyObject *py_level = PyInt_FromLong(level);
            if (!py_level)
                goto bad;
            module = PyObject_CallFunctionObjArgs(py_import,
                name, global_dict, empty_dict, list, py_level, (PyObject *)NULL);
            Py_DECREF(py_level);
            #else
            module = PyImport_ImportModuleLevelObject(
                name, global_dict, empty_dict, list, level);
            #endif
        }
    }
bad:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(py_import);
    #endif
    Py_XDECREF(empty_list);
    Py_XDECREF(empty_dict);
    return module;
}


static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type) {
    PyObject* fake_module;
    PyTypeObject* cached_type = NULL;
    fake_module = PyImport_AddModule((char*) "_cython_" CYTHON_ABI);
    if (!fake_module) return NULL;
    Py_INCREF(fake_module);
    cached_type = (PyTypeObject*) PyObject_GetAttrString(fake_module, type->tp_name);
    if (cached_type) {
        if (!PyType_Check((PyObject*)cached_type)) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s is not a type object",
                type->tp_name);
            goto bad;
        }
        if (cached_type->tp_basicsize != type->tp_basicsize) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s has the wrong size, try recompiling",
                type->tp_name);
            goto bad;
        }
    } else {
        if (!PyErr_ExceptionMatches(PyExc_AttributeError)) goto bad;
        PyErr_Clear();
        if (PyType_Ready(type) < 0) goto bad;
        if (PyObject_SetAttrString(fake_module, type->tp_name, (PyObject*) type) < 0)
            goto bad;
        Py_INCREF(type);
        cached_type = type;
    }
done:
    Py_DECREF(fake_module);
    return cached_type;
bad:
    Py_XDECREF(cached_type);
    cached_type = NULL;
    goto done;
}


#include <structmember.h>
static PyObject *
__Pyx_CyFunction_get_doc(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *closure)
{
    if (unlikely(op->func_doc == NULL)) {
        if (op->func.m_ml->ml_doc) {
#if PY_MAJOR_VERSION >= 3
            op->func_doc = PyUnicode_FromString(op->func.m_ml->ml_doc);
#else
            op->func_doc = PyString_FromString(op->func.m_ml->ml_doc);
#endif
            if (unlikely(op->func_doc == NULL))
                return NULL;
        } else {
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    Py_INCREF(op->func_doc);
    return op->func_doc;
}
static int
__Pyx_CyFunction_set_doc(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp = op->func_doc;
    if (value == NULL) {
        value = Py_None;
    }
    Py_INCREF(value);
    op->func_doc = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_name(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_name == NULL)) {
#if PY_MAJOR_VERSION >= 3
        op->func_name = PyUnicode_InternFromString(op->func.m_ml->ml_name);
#else
        op->func_name = PyString_InternFromString(op->func.m_ml->ml_name);
#endif
        if (unlikely(op->func_name == NULL))
            return NULL;
    }
    Py_INCREF(op->func_name);
    return op->func_name;
}
static int
__Pyx_CyFunction_set_name(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__name__ must be set to a string object");
        return -1;
    }
    tmp = op->func_name;
    Py_INCREF(value);
    op->func_name = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_qualname(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_qualname);
    return op->func_qualname;
}
static int
__Pyx_CyFunction_set_qualname(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__qualname__ must be set to a string object");
        return -1;
    }
    tmp = op->func_qualname;
    Py_INCREF(value);
    op->func_qualname = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_self(__pyx_CyFunctionObject *m, CYTHON_UNUSED void *closure)
{
    PyObject *self;
    self = m->func_closure;
    if (self == NULL)
        self = Py_None;
    Py_INCREF(self);
    return self;
}
static PyObject *
__Pyx_CyFunction_get_dict(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_dict == NULL)) {
        op->func_dict = PyDict_New();
        if (unlikely(op->func_dict == NULL))
            return NULL;
    }
    Py_INCREF(op->func_dict);
    return op->func_dict;
}
static int
__Pyx_CyFunction_set_dict(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
    if (unlikely(value == NULL)) {
        PyErr_SetString(PyExc_TypeError,
               "function's dictionary may not be deleted");
        return -1;
    }
    if (unlikely(!PyDict_Check(value))) {
        PyErr_SetString(PyExc_TypeError,
               "setting function's dictionary to a non-dict");
        return -1;
    }
    tmp = op->func_dict;
    Py_INCREF(value);
    op->func_dict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_globals(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_globals);
    return op->func_globals;
}
static PyObject *
__Pyx_CyFunction_get_closure(CYTHON_UNUSED __pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(Py_None);
    return Py_None;
}
static PyObject *
__Pyx_CyFunction_get_code(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    PyObject* result = (op->func_code) ? op->func_code : Py_None;
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_init_defaults(__pyx_CyFunctionObject *op) {
    int result = 0;
    PyObject *res = op->defaults_getter((PyObject *) op);
    if (unlikely(!res))
        return -1;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    op->defaults_tuple = PyTuple_GET_ITEM(res, 0);
    Py_INCREF(op->defaults_tuple);
    op->defaults_kwdict = PyTuple_GET_ITEM(res, 1);
    Py_INCREF(op->defaults_kwdict);
    #else
    op->defaults_tuple = PySequence_ITEM(res, 0);
    if (unlikely(!op->defaults_tuple)) result = -1;
    else {
        op->defaults_kwdict = PySequence_ITEM(res, 1);
        if (unlikely(!op->defaults_kwdict)) result = -1;
    }
    #endif
    Py_DECREF(res);
    return result;
}
static int
__Pyx_CyFunction_set_defaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyTuple_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__defaults__ must be set to a tuple object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_tuple;
    op->defaults_tuple = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_defaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_tuple;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_tuple;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_kwdefaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__kwdefaults__ must be set to a dict object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_kwdict;
    op->defaults_kwdict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_kwdefaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_kwdict;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_kwdict;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_annotations(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value || value == Py_None) {
        value = NULL;
    } else if (!PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__annotations__ must be set to a dict object");
        return -1;
    }
    Py_XINCREF(value);
    tmp = op->func_annotations;
    op->func_annotations = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_annotations(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->func_annotations;
    if (unlikely(!result)) {
        result = PyDict_New();
        if (unlikely(!result)) return NULL;
        op->func_annotations = result;
    }
    Py_INCREF(result);
    return result;
}
static PyGetSetDef __pyx_CyFunction_getsets[] = {
    {(char *) "func_doc", (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "__doc__", (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "func_name", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__name__", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__qualname__", (getter)__Pyx_CyFunction_get_qualname, (setter)__Pyx_CyFunction_set_qualname, 0, 0},
    {(char *) "__self__", (getter)__Pyx_CyFunction_get_self, 0, 0, 0},
    {(char *) "func_dict", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "__dict__", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "func_globals", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "__globals__", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "func_closure", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "__closure__", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "func_code", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "__code__", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "func_defaults", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__defaults__", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__kwdefaults__", (getter)__Pyx_CyFunction_get_kwdefaults, (setter)__Pyx_CyFunction_set_kwdefaults, 0, 0},
    {(char *) "__annotations__", (getter)__Pyx_CyFunction_get_annotations, (setter)__Pyx_CyFunction_set_annotations, 0, 0},
    {0, 0, 0, 0, 0}
};
static PyMemberDef __pyx_CyFunction_members[] = {
    {(char *) "__module__", T_OBJECT, offsetof(PyCFunctionObject, m_module), PY_WRITE_RESTRICTED, 0},
    {0, 0, 0, 0, 0}
};
static PyObject *
__Pyx_CyFunction_reduce(__pyx_CyFunctionObject *m, CYTHON_UNUSED PyObject *args)
{
#if PY_MAJOR_VERSION >= 3
    return PyUnicode_FromString(m->func.m_ml->ml_name);
#else
    return PyString_FromString(m->func.m_ml->ml_name);
#endif
}
static PyMethodDef __pyx_CyFunction_methods[] = {
    {"__reduce__", (PyCFunction)__Pyx_CyFunction_reduce, METH_VARARGS, 0},
    {0, 0, 0, 0}
};
#if PY_VERSION_HEX < 0x030500A0
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func_weakreflist)
#else
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func.m_weakreflist)
#endif
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject *op, PyMethodDef *ml, int flags, PyObject* qualname,
                                       PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    if (unlikely(op == NULL))
        return NULL;
    op->flags = flags;
    __Pyx_CyFunction_weakreflist(op) = NULL;
    op->func.m_ml = ml;
    op->func.m_self = (PyObject *) op;
    Py_XINCREF(closure);
    op->func_closure = closure;
    Py_XINCREF(module);
    op->func.m_module = module;
    op->func_dict = NULL;
    op->func_name = NULL;
    Py_INCREF(qualname);
    op->func_qualname = qualname;
    op->func_doc = NULL;
    op->func_classobj = NULL;
    op->func_globals = globals;
    Py_INCREF(op->func_globals);
    Py_XINCREF(code);
    op->func_code = code;
    op->defaults_pyobjects = 0;
    op->defaults_size = 0;
    op->defaults = NULL;
    op->defaults_tuple = NULL;
    op->defaults_kwdict = NULL;
    op->defaults_getter = NULL;
    op->func_annotations = NULL;
    return (PyObject *) op;
}
static int
__Pyx_CyFunction_clear(__pyx_CyFunctionObject *m)
{
    Py_CLEAR(m->func_closure);
    Py_CLEAR(m->func.m_module);
    Py_CLEAR(m->func_dict);
    Py_CLEAR(m->func_name);
    Py_CLEAR(m->func_qualname);
    Py_CLEAR(m->func_doc);
    Py_CLEAR(m->func_globals);
    Py_CLEAR(m->func_code);
    Py_CLEAR(m->func_classobj);
    Py_CLEAR(m->defaults_tuple);
    Py_CLEAR(m->defaults_kwdict);
    Py_CLEAR(m->func_annotations);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_XDECREF(pydefaults[i]);
        PyObject_Free(m->defaults);
        m->defaults = NULL;
    }
    return 0;
}
static void __Pyx__CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    if (__Pyx_CyFunction_weakreflist(m) != NULL)
        PyObject_ClearWeakRefs((PyObject *) m);
    __Pyx_CyFunction_clear(m);
    PyObject_GC_Del(m);
}
static void __Pyx_CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    PyObject_GC_UnTrack(m);
    __Pyx__CyFunction_dealloc(m);
}
static int __Pyx_CyFunction_traverse(__pyx_CyFunctionObject *m, visitproc visit, void *arg)
{
    Py_VISIT(m->func_closure);
    Py_VISIT(m->func.m_module);
    Py_VISIT(m->func_dict);
    Py_VISIT(m->func_name);
    Py_VISIT(m->func_qualname);
    Py_VISIT(m->func_doc);
    Py_VISIT(m->func_globals);
    Py_VISIT(m->func_code);
    Py_VISIT(m->func_classobj);
    Py_VISIT(m->defaults_tuple);
    Py_VISIT(m->defaults_kwdict);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_VISIT(pydefaults[i]);
    }
    return 0;
}
static PyObject *__Pyx_CyFunction_descr_get(PyObject *func, PyObject *obj, PyObject *type)
{
#if PY_MAJOR_VERSION < 3
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    if (m->flags & __Pyx_CYFUNCTION_STATICMETHOD) {
        Py_INCREF(func);
        return func;
    }
    if (m->flags & __Pyx_CYFUNCTION_CLASSMETHOD) {
        if (type == NULL)
            type = (PyObject *)(Py_TYPE(obj));
        return __Pyx_PyMethod_New(func, type, (PyObject *)(Py_TYPE(type)));
    }
    if (obj == Py_None)
        obj = NULL;
#endif
    return __Pyx_PyMethod_New(func, obj, type);
}
static PyObject*
__Pyx_CyFunction_repr(__pyx_CyFunctionObject *op)
{
#if PY_MAJOR_VERSION >= 3
    return PyUnicode_FromFormat("<cyfunction %U at %p>",
                                op->func_qualname, (void *)op);
#else
    return PyString_FromFormat("<cyfunction %s at %p>",
                               PyString_AsString(op->func_qualname), (void *)op);
#endif
}
static PyObject * __Pyx_CyFunction_CallMethod(PyObject *func, PyObject *self, PyObject *arg, PyObject *kw) {
    PyCFunctionObject* f = (PyCFunctionObject*)func;
    PyCFunction meth = f->m_ml->ml_meth;
    Py_ssize_t size;
    switch (f->m_ml->ml_flags & (METH_VARARGS | METH_KEYWORDS | METH_NOARGS | METH_O)) {
    case METH_VARARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0))
            return (*meth)(self, arg);
        break;
    case METH_VARARGS | METH_KEYWORDS:
        return (*(PyCFunctionWithKeywords)(void*)meth)(self, arg, kw);
    case METH_NOARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 0))
                return (*meth)(self, NULL);
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes no arguments (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    case METH_O:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 1)) {
                PyObject *result, *arg0;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                arg0 = PyTuple_GET_ITEM(arg, 0);
                #else
                arg0 = PySequence_ITEM(arg, 0); if (unlikely(!arg0)) return NULL;
                #endif
                result = (*meth)(self, arg0);
                #if !(CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS)
                Py_DECREF(arg0);
                #endif
                return result;
            }
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes exactly one argument (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    default:
        PyErr_SetString(PyExc_SystemError, "Bad call flags in "
                        "__Pyx_CyFunction_Call. METH_OLDARGS is no "
                        "longer supported!");
        return NULL;
    }
    PyErr_Format(PyExc_TypeError, "%.200s() takes no keyword arguments",
                 f->m_ml->ml_name);
    return NULL;
}
static CYTHON_INLINE PyObject *__Pyx_CyFunction_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    return __Pyx_CyFunction_CallMethod(func, ((PyCFunctionObject*)func)->m_self, arg, kw);
}
static PyObject *__Pyx_CyFunction_CallAsMethod(PyObject *func, PyObject *args, PyObject *kw) {
    PyObject *result;
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *) func;
    if ((cyfunc->flags & __Pyx_CYFUNCTION_CCLASS) && !(cyfunc->flags & __Pyx_CYFUNCTION_STATICMETHOD)) {
        Py_ssize_t argc;
        PyObject *new_args;
        PyObject *self;
        argc = PyTuple_GET_SIZE(args);
        new_args = PyTuple_GetSlice(args, 1, argc);
        if (unlikely(!new_args))
            return NULL;
        self = PyTuple_GetItem(args, 0);
        if (unlikely(!self)) {
            Py_DECREF(new_args);
            return NULL;
        }
        result = __Pyx_CyFunction_CallMethod(func, self, new_args, kw);
        Py_DECREF(new_args);
    } else {
        result = __Pyx_CyFunction_Call(func, args, kw);
    }
    return result;
}
static PyTypeObject __pyx_CyFunctionType_type = {
    PyVarObject_HEAD_INIT(0, 0)
    "cython_function_or_method",
    sizeof(__pyx_CyFunctionObject),
    0,
    (destructor) __Pyx_CyFunction_dealloc,
    0,
    0,
    0,
#if PY_MAJOR_VERSION < 3
    0,
#else
    0,
#endif
    (reprfunc) __Pyx_CyFunction_repr,
    0,
    0,
    0,
    0,
    __Pyx_CyFunction_CallAsMethod,
    0,
    0,
    0,
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC,
    0,
    (traverseproc) __Pyx_CyFunction_traverse,
    (inquiry) __Pyx_CyFunction_clear,
    0,
#if PY_VERSION_HEX < 0x030500A0
    offsetof(__pyx_CyFunctionObject, func_weakreflist),
#else
    offsetof(PyCFunctionObject, m_weakreflist),
#endif
    0,
    0,
    __pyx_CyFunction_methods,
    __pyx_CyFunction_members,
    __pyx_CyFunction_getsets,
    0,
    0,
    __Pyx_CyFunction_descr_get,
    0,
    offsetof(__pyx_CyFunctionObject, func_dict),
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#if PY_VERSION_HEX >= 0x030400a1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
    0,
#endif
};
static int __pyx_CyFunction_init(void) {
    __pyx_CyFunctionType = __Pyx_FetchCommonType(&__pyx_CyFunctionType_type);
    if (unlikely(__pyx_CyFunctionType == NULL)) {
        return -1;
    }
    return 0;
}
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *func, size_t size, int pyobjects) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults = PyObject_Malloc(size);
    if (unlikely(!m->defaults))
        return PyErr_NoMemory();
    memset(m->defaults, 0, size);
    m->defaults_pyobjects = pyobjects;
    m->defaults_size = size;
    return m->defaults;
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *func, PyObject *tuple) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_tuple = tuple;
    Py_INCREF(tuple);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_kwdict = dict;
    Py_INCREF(dict);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->func_annotations = dict;
    Py_INCREF(dict);
}


static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml, int flags, PyObject* qualname,
                                      PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    PyObject *op = __Pyx_CyFunction_Init(
        PyObject_GC_New(__pyx_CyFunctionObject, __pyx_CyFunctionType),
        ml, flags, qualname, closure, module, globals, code
    );
    if (likely(op)) {
        PyObject_GC_Track(op);
    }
    return op;
}


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    tmp_type = tstate->curexc_type;
    tmp_value = tstate->curexc_value;
    tmp_tb = tstate->curexc_traceback;
    tstate->curexc_type = type;
    tstate->curexc_value = value;
    tstate->curexc_traceback = tb;
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    *type = tstate->curexc_type;
    *value = tstate->curexc_value;
    *tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
}
#endif


#ifndef CYTHON_CLINE_IN_TRACEBACK
static int __Pyx_CLineForTraceback(CYTHON_NCP_UNUSED PyThreadState *tstate, int c_line) {
    PyObject *use_cline;
    PyObject *ptype, *pvalue, *ptraceback;
#if CYTHON_COMPILING_IN_CPYTHON
    PyObject **cython_runtime_dict;
#endif
    if (unlikely(!__pyx_cython_runtime)) {
        return c_line;
    }
    __Pyx_ErrFetchInState(tstate, &ptype, &pvalue, &ptraceback);
#if CYTHON_COMPILING_IN_CPYTHON
    cython_runtime_dict = _PyObject_GetDictPtr(__pyx_cython_runtime);
    if (likely(cython_runtime_dict)) {
        __PYX_PY_DICT_LOOKUP_IF_MODIFIED(
            use_cline, *cython_runtime_dict,
            __Pyx_PyDict_GetItemStr(*cython_runtime_dict, __pyx_n_s_cline_in_traceback))
    } else
#endif
    {
      PyObject *use_cline_obj = __Pyx_PyObject_GetAttrStr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback);
      if (use_cline_obj) {
        use_cline = PyObject_Not(use_cline_obj) ? Py_False : Py_True;
        Py_DECREF(use_cline_obj);
      } else {
        PyErr_Clear();
        use_cline = NULL;
      }
    }
    if (!use_cline) {
        c_line = 0;
        PyObject_SetAttr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback, Py_False);
    }
    else if (use_cline == Py_False || (use_cline != Py_True && PyObject_Not(use_cline) != 0)) {
        c_line = 0;
    }
    __Pyx_ErrRestoreInState(tstate, ptype, pvalue, ptraceback);
    return c_line;
}
#endif


static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line) {
    int start = 0, mid = 0, end = count - 1;
    if (end >= 0 && code_line > entries[end].code_line) {
        return count;
    }
    while (start < end) {
        mid = start + (end - start) / 2;
        if (code_line < entries[mid].code_line) {
            end = mid;
        } else if (code_line > entries[mid].code_line) {
             start = mid + 1;
        } else {
            return mid;
        }
    }
    if (code_line <= entries[mid].code_line) {
        return mid;
    } else {
        return mid + 1;
    }
}
static PyCodeObject *__pyx_find_code_object(int code_line) {
    PyCodeObject* code_object;
    int pos;
    if (unlikely(!code_line) || unlikely(!__pyx_code_cache.entries)) {
        return NULL;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if (unlikely(pos >= __pyx_code_cache.count) || unlikely(__pyx_code_cache.entries[pos].code_line != code_line)) {
        return NULL;
    }
    code_object = __pyx_code_cache.entries[pos].code_object;
    Py_INCREF(code_object);
    return code_object;
}
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object) {
    int pos, i;
    __Pyx_CodeObjectCacheEntry* entries = __pyx_code_cache.entries;
    if (unlikely(!code_line)) {
        return;
    }
    if (unlikely(!entries)) {
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Malloc(64*sizeof(__Pyx_CodeObjectCacheEntry));
        if (likely(entries)) {
            __pyx_code_cache.entries = entries;
            __pyx_code_cache.max_count = 64;
            __pyx_code_cache.count = 1;
            entries[0].code_line = code_line;
            entries[0].code_object = code_object;
            Py_INCREF(code_object);
        }
        return;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if ((pos < __pyx_code_cache.count) && unlikely(__pyx_code_cache.entries[pos].code_line == code_line)) {
        PyCodeObject* tmp = entries[pos].code_object;
        entries[pos].code_object = code_object;
        Py_DECREF(tmp);
        return;
    }
    if (__pyx_code_cache.count == __pyx_code_cache.max_count) {
        int new_max = __pyx_code_cache.max_count + 64;
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Realloc(
            __pyx_code_cache.entries, ((size_t)new_max) * sizeof(__Pyx_CodeObjectCacheEntry));
        if (unlikely(!entries)) {
            return;
        }
        __pyx_code_cache.entries = entries;
        __pyx_code_cache.max_count = new_max;
    }
    for (i=__pyx_code_cache.count; i>pos; i--) {
        entries[i] = entries[i-1];
    }
    entries[pos].code_line = code_line;
    entries[pos].code_object = code_object;
    __pyx_code_cache.count++;
    Py_INCREF(code_object);
}


#include "compile.h"
#include "frameobject.h"
#include "traceback.h"
static PyCodeObject* __Pyx_CreateCodeObjectForTraceback(
            const char *funcname, int c_line,
            int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    #if PY_MAJOR_VERSION < 3
    py_srcfile = PyString_FromString(filename);
    #else
    py_srcfile = PyUnicode_FromString(filename);
    #endif
    if (!py_srcfile) goto bad;
    if (c_line) {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #else
        py_funcname = PyUnicode_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #endif
    }
    else {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromString(funcname);
        #else
        py_funcname = PyUnicode_FromString(funcname);
        #endif
    }
    if (!py_funcname) goto bad;
    py_code = __Pyx_PyCode_New(
        0,
        0,
        0,
        0,
        0,
        __pyx_empty_bytes,
        __pyx_empty_tuple,
        __pyx_empty_tuple,
        __pyx_empty_tuple,
        __pyx_empty_tuple,
        __pyx_empty_tuple,
        py_srcfile,
        py_funcname,
        py_line,
        __pyx_empty_bytes
    );
    Py_DECREF(py_srcfile);
    Py_DECREF(py_funcname);
    return py_code;
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    return NULL;
}
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    if (c_line) {
        c_line = __Pyx_CLineForTraceback(tstate, c_line);
    }
    py_code = __pyx_find_code_object(c_line ? -c_line : py_line);
    if (!py_code) {
        py_code = __Pyx_CreateCodeObjectForTraceback(
            funcname, c_line, py_line, filename);
        if (!py_code) goto bad;
        __pyx_insert_code_object(c_line ? -c_line : py_line, py_code);
    }
    py_frame = PyFrame_New(
        tstate,
        py_code,
        __pyx_d,
        0
    );
    if (!py_frame) goto bad;
    __Pyx_PyFrame_SetLineNumber(py_frame, py_line);
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}


#ifdef __FreeBSD__
#include <floatingpoint.h>
#endif
#if PY_MAJOR_VERSION < 3
int main(int argc, char** argv) {
#elif defined(WIN32) || defined(MS_WINDOWS)
int wmain(int argc, wchar_t **argv) {
#else
static int __Pyx_main(int argc, wchar_t **argv) {
#endif





#ifdef __FreeBSD__
    fp_except_t m;
    m = fpgetmask();
    fpsetmask(m & ~FP_X_OFL);
#endif
    if (argc && argv)
        Py_SetProgramName(argv[0]);
    Py_Initialize();
    if (argc && argv)
        PySys_SetArgv(argc, argv);
    {
      PyObject* m = NULL;
      __pyx_module_is_main_example1 = 1;
      #if PY_MAJOR_VERSION < 3
          initexample1();
      #elif CYTHON_PEP489_MULTI_PHASE_INIT
          m = PyInit_example1();
          if (!PyModule_Check(m)) {
              PyModuleDef *mdef = (PyModuleDef *) m;
              PyObject *modname = PyUnicode_FromString("__main__");
              m = NULL;
              if (modname) {
                  m = PyModule_NewObject(modname);
                  Py_DECREF(modname);
                  if (m) PyModule_ExecDef(m, mdef);
              }
          }
      #else
          m = PyInit_example1();
      #endif
      if (PyErr_Occurred()) {
          PyErr_Print();
          #if PY_MAJOR_VERSION < 3
          if (Py_FlushLine()) PyErr_Clear();
          #endif
          return 1;
      }
      Py_XDECREF(m);
    }
    Py_Finalize();
    return 0;
}
#if PY_MAJOR_VERSION >= 3 && !defined(WIN32) && !defined(MS_WINDOWS)
#include <locale.h>
static wchar_t*
__Pyx_char2wchar(char* arg)
{
    wchar_t *res;
#ifdef HAVE_BROKEN_MBSTOWCS




    size_t argsize = strlen(arg);
#else
    size_t argsize = mbstowcs(NULL, arg, 0);
#endif
    size_t count;
    unsigned char *in;
    wchar_t *out;
#ifdef HAVE_MBRTOWC
    mbstate_t mbs;
#endif
    if (argsize != (size_t)-1) {
        res = (wchar_t *)malloc((argsize+1)*sizeof(wchar_t));
        if (!res)
            goto oom;
        count = mbstowcs(res, arg, argsize+1);
        if (count != (size_t)-1) {
            wchar_t *tmp;


            for (tmp = res; *tmp != 0 &&
                     (*tmp < 0xd800 || *tmp > 0xdfff); tmp++)
                ;
            if (*tmp == 0)
                return res;
        }
        free(res);
    }
#ifdef HAVE_MBRTOWC


    argsize = strlen(arg) + 1;
    res = (wchar_t *)malloc(argsize*sizeof(wchar_t));
    if (!res) goto oom;
    in = (unsigned char*)arg;
    out = res;
    memset(&mbs, 0, sizeof mbs);
    while (argsize) {
        size_t converted = mbrtowc(out, (char*)in, argsize, &mbs);
        if (converted == 0)
            break;
        if (converted == (size_t)-2) {




            fprintf(stderr, "unexpected mbrtowc result -2\\n");
            free(res);
            return NULL;
        }
        if (converted == (size_t)-1) {


            *out++ = 0xdc00 + *in++;
            argsize--;
            memset(&mbs, 0, sizeof mbs);
            continue;
        }
        if (*out >= 0xd800 && *out <= 0xdfff) {


            argsize -= converted;
            while (converted--)
                *out++ = 0xdc00 + *in++;
            continue;
        }
        in += converted;
        argsize -= converted;
        out++;
    }
#else



    res = (wchar_t *)malloc((strlen(arg)+1)*sizeof(wchar_t));
    if (!res) goto oom;
    in = (unsigned char*)arg;
    out = res;
    while(*in)
        if(*in < 128)
            *out++ = *in++;
        else
            *out++ = 0xdc00 + *in++;
    *out = 0;
#endif
    return res;
oom:
    fprintf(stderr, "out of memory\\n");
    return NULL;
}
int
main(int argc, char **argv)
{
    if (!argc) {
        return __Pyx_main(0, NULL);
    }
    else {
        int i, res;
        wchar_t **argv_copy = (wchar_t **)malloc(sizeof(wchar_t*)*argc);
        wchar_t **argv_copy2 = (wchar_t **)malloc(sizeof(wchar_t*)*argc);
        char *oldloc = strdup(setlocale(LC_ALL, NULL));
        if (!argv_copy || !argv_copy2 || !oldloc) {
            fprintf(stderr, "out of memory\\n");
            free(argv_copy);
            free(argv_copy2);
            free(oldloc);
            return 1;
        }
        res = 0;
        setlocale(LC_ALL, "");
        for (i = 0; i < argc; i++) {
            argv_copy2[i] = argv_copy[i] = __Pyx_char2wchar(argv[i]);
            if (!argv_copy[i]) res = 1;
        }
        setlocale(LC_ALL, oldloc);
        free(oldloc);
        if (res == 0)
            res = __Pyx_main(argc, argv_copy);
        for (i = 0; i < argc; i++) {
            free(argv_copy2[i]);
        }
        free(argv_copy);
        free(argv_copy2);
        return res;
    }
}
#endif


    static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value) {
    const long neg_one = (long) ((long) 0 - (long) 1), const_zero = (long) 0;
    const int is_unsigned = neg_one > const_zero;
    if (is_unsigned) {
        if (sizeof(long) < sizeof(long)) {
            return PyInt_FromLong((long) value);
        } else if (sizeof(long) <= sizeof(unsigned long)) {
            return PyLong_FromUnsignedLong((unsigned long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG) value);
#endif
        }
    } else {
        if (sizeof(long) <= sizeof(long)) {
            return PyInt_FromLong((long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
            return PyLong_FromLongLong((PY_LONG_LONG) value);
#endif
        }
    }
    {
        int one = 1; int little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&value;
        return _PyLong_FromByteArray(bytes, sizeof(long),
                                     little, !is_unsigned);
    }
}


    #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION < 3
static PyObject *__Pyx_GetStdout(void) {
    PyObject *f = PySys_GetObject((char *)"stdout");
    if (!f) {
        PyErr_SetString(PyExc_RuntimeError, "lost sys.stdout");
    }
    return f;
}
static int __Pyx_Print(PyObject* f, PyObject *arg_tuple, int newline) {
    int i;
    if (!f) {
        if (!(f = __Pyx_GetStdout()))
            return -1;
    }
    Py_INCREF(f);
    for (i=0; i < PyTuple_GET_SIZE(arg_tuple); i++) {
        PyObject* v;
        if (PyFile_SoftSpace(f, 1)) {
            if (PyFile_WriteString(" ", f) < 0)
                goto error;
        }
        v = PyTuple_GET_ITEM(arg_tuple, i);
        if (PyFile_WriteObject(v, f, Py_PRINT_RAW) < 0)
            goto error;
        if (PyString_Check(v)) {
            char *s = PyString_AsString(v);
            Py_ssize_t len = PyString_Size(v);
            if (len > 0) {
                switch (s[len-1]) {
                    case ' ': break;
                    case '\f': case '\r': case '\n': case '\t': case '\v':
                        PyFile_SoftSpace(f, 0);
                        break;
                    default: break;
                }
            }
        }
    }
    if (newline) {
        if (PyFile_WriteString("\n", f) < 0)
            goto error;
        PyFile_SoftSpace(f, 0);
    }
    Py_DECREF(f);
    return 0;
error:
    Py_DECREF(f);
    return -1;
}
#else
static int __Pyx_Print(PyObject* stream, PyObject *arg_tuple, int newline) {
    PyObject* kwargs = 0;
    PyObject* result = 0;
    PyObject* end_string;
    if (unlikely(!__pyx_print)) {
        __pyx_print = PyObject_GetAttr(__pyx_b, __pyx_n_s_print);
        if (!__pyx_print)
            return -1;
    }
    if (stream) {
        kwargs = PyDict_New();
        if (unlikely(!kwargs))
            return -1;
        if (unlikely(PyDict_SetItem(kwargs, __pyx_n_s_file, stream) < 0))
            goto bad;
        if (!newline) {
            end_string = PyUnicode_FromStringAndSize(" ", 1);
            if (unlikely(!end_string))
                goto bad;
            if (PyDict_SetItem(kwargs, __pyx_n_s_end, end_string) < 0) {
                Py_DECREF(end_string);
                goto bad;
            }
            Py_DECREF(end_string);
        }
    } else if (!newline) {
        if (unlikely(!__pyx_print_kwargs)) {
            __pyx_print_kwargs = PyDict_New();
            if (unlikely(!__pyx_print_kwargs))
                return -1;
            end_string = PyUnicode_FromStringAndSize(" ", 1);
            if (unlikely(!end_string))
                return -1;
            if (PyDict_SetItem(__pyx_print_kwargs, __pyx_n_s_end, end_string) < 0) {
                Py_DECREF(end_string);
                return -1;
            }
            Py_DECREF(end_string);
        }
        kwargs = __pyx_print_kwargs;
    }
    result = PyObject_Call(__pyx_print, arg_tuple, kwargs);
    if (unlikely(kwargs) && (kwargs != __pyx_print_kwargs))
        Py_DECREF(kwargs);
    if (!result)
        return -1;
    Py_DECREF(result);
    return 0;
bad:
    if (kwargs != __pyx_print_kwargs)
        Py_XDECREF(kwargs);
    return -1;
}
#endif


    #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION < 3
static int __Pyx_PrintOne(PyObject* f, PyObject *o) {
    if (!f) {
        if (!(f = __Pyx_GetStdout()))
            return -1;
    }
    Py_INCREF(f);
    if (PyFile_SoftSpace(f, 0)) {
        if (PyFile_WriteString(" ", f) < 0)
            goto error;
    }
    if (PyFile_WriteObject(o, f, Py_PRINT_RAW) < 0)
        goto error;
    if (PyFile_WriteString("\n", f) < 0)
        goto error;
    Py_DECREF(f);
    return 0;
error:
    Py_DECREF(f);
    return -1;


    return __Pyx_Print(f, NULL, 0);
}
#else
static int __Pyx_PrintOne(PyObject* stream, PyObject *o) {
    int res;
    PyObject* arg_tuple = PyTuple_Pack(1, o);
    if (unlikely(!arg_tuple))
        return -1;
    res = __Pyx_Print(stream, arg_tuple, 1);
    Py_DECREF(arg_tuple);
    return res;
}
#endif


    #define __PYX_VERIFY_RETURN_INT(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 0)
#define __PYX_VERIFY_RETURN_INT_EXC(target_type,func_type,func_value) \
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 1)
#define __PYX__VERIFY_RETURN_INT(target_type,func_type,func_value,exc) \
    {\
        func_type value = func_value;\
        if (sizeof(target_type) < sizeof(func_type)) {\
            if (unlikely(value != (func_type) (target_type) value)) {\
                func_type zero = 0;\
                if (exc && unlikely(value == (func_type)-1 && PyErr_Occurred()))\
                    return (target_type) -1;\
                if (is_unsigned && unlikely(value < zero))\
                    goto raise_neg_overflow;\
                else\
                    goto raise_overflow;\
            }\
        }\
        return (target_type) value;\
    }


    static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *x) {
    const long neg_one = (long) ((long) 0 - (long) 1), const_zero = (long) 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(long) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(long, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (long) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case 0: return (long) 0;
                case 1: __PYX_VERIFY_RETURN_INT(long, digit, digits[0])
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 2 * PyLong_SHIFT) {
                            return (long) (((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 3 * PyLong_SHIFT) {
                            return (long) (((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 4 * PyLong_SHIFT) {
                            return (long) (((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (long) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(long) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case 0: return (long) 0;
                case -1: __PYX_VERIFY_RETURN_INT(long, sdigit, (sdigit) (-(sdigit)digits[0]))
                case 1: __PYX_VERIFY_RETURN_INT(long, digit, +digits[0])
                case -2:
                    if (8 * sizeof(long) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) ((((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) ((((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) ((((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(long) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            long val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (long) -1;
        }
    } else {
        long val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (long) -1;
        val = __Pyx_PyInt_As_long(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to long");
    return (long) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to long");
    return (long) -1;
}


    static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *x) {
    const int neg_one = (int) ((int) 0 - (int) 1), const_zero = (int) 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(int) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(int, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (int) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case 0: return (int) 0;
                case 1: __PYX_VERIFY_RETURN_INT(int, digit, digits[0])
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 2 * PyLong_SHIFT) {
                            return (int) (((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 3 * PyLong_SHIFT) {
                            return (int) (((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 4 * PyLong_SHIFT) {
                            return (int) (((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (int) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(int) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case 0: return (int) 0;
                case -1: __PYX_VERIFY_RETURN_INT(int, sdigit, (sdigit) (-(sdigit)digits[0]))
                case 1: __PYX_VERIFY_RETURN_INT(int, digit, +digits[0])
                case -2:
                    if (8 * sizeof(int) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) ((((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) ((((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) ((((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(int) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            int val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (int) -1;
        }
    } else {
        int val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (int) -1;
        val = __Pyx_PyInt_As_int(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to int");
    return (int) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to int");
    return (int) -1;
}


    #if CYTHON_COMPILING_IN_CPYTHON
static int __Pyx_InBases(PyTypeObject *a, PyTypeObject *b) {
    while (a) {
        a = a->tp_base;
        if (a == b)
            return 1;
    }
    return b == &PyBaseObject_Type;
}
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b) {
    PyObject *mro;
    if (a == b) return 1;
    mro = a->tp_mro;
    if (likely(mro)) {
        Py_ssize_t i, n;
        n = PyTuple_GET_SIZE(mro);
        for (i = 0; i < n; i++) {
            if (PyTuple_GET_ITEM(mro, i) == (PyObject *)b)
                return 1;
        }
        return 0;
    }
    return __Pyx_InBases(a, b);
}
#if PY_MAJOR_VERSION == 2
static int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject* exc_type2) {
    PyObject *exception, *value, *tb;
    int res;
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&exception, &value, &tb);
    res = exc_type1 ? PyObject_IsSubclass(err, exc_type1) : 0;
    if (unlikely(res == -1)) {
        PyErr_WriteUnraisable(err);
        res = 0;
    }
    if (!res) {
        res = PyObject_IsSubclass(err, exc_type2);
        if (unlikely(res == -1)) {
            PyErr_WriteUnraisable(err);
            res = 0;
        }
    }
    __Pyx_ErrRestore(exception, value, tb);
    return res;
}
#else
static CYTHON_INLINE int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject *exc_type2) {
    int res = exc_type1 ? __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type1) : 0;
    if (!res) {
        res = __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type2);
    }
    return res;
}
#endif
static int __Pyx_PyErr_GivenExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    assert(PyExceptionClass_Check(exc_type));
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        PyObject *t = PyTuple_GET_ITEM(tuple, i);
        #if PY_MAJOR_VERSION < 3
        if (likely(exc_type == t)) return 1;
        #endif
        if (likely(PyExceptionClass_Check(t))) {
            if (__Pyx_inner_PyErr_GivenExceptionMatches2(exc_type, NULL, t)) return 1;
        } else {
        }
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject* exc_type) {
    if (likely(err == exc_type)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        if (likely(PyExceptionClass_Check(exc_type))) {
            return __Pyx_inner_PyErr_GivenExceptionMatches2(err, NULL, exc_type);
        } else if (likely(PyTuple_Check(exc_type))) {
            return __Pyx_PyErr_GivenExceptionMatchesTuple(err, exc_type);
        } else {
        }
    }
    return PyErr_GivenExceptionMatches(err, exc_type);
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *exc_type1, PyObject *exc_type2) {
    assert(PyExceptionClass_Check(exc_type1));
    assert(PyExceptionClass_Check(exc_type2));
    if (likely(err == exc_type1 || err == exc_type2)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        return __Pyx_inner_PyErr_GivenExceptionMatches2(err, exc_type1, exc_type2);
    }
    return (PyErr_GivenExceptionMatches(err, exc_type1) || PyErr_GivenExceptionMatches(err, exc_type2));
}
#endif


    static int __Pyx_check_binary_version(void) {
    char ctversion[4], rtversion[4];
    PyOS_snprintf(ctversion, 4, "%d.%d", PY_MAJOR_VERSION, PY_MINOR_VERSION);
    PyOS_snprintf(rtversion, 4, "%s", Py_GetVersion());
    if (ctversion[0] != rtversion[0] || ctversion[2] != rtversion[2]) {
        char message[200];
        PyOS_snprintf(message, sizeof(message),
                      "compiletime version %s of module '%.100s' "
                      "does not match runtime version %s",
                      ctversion, __Pyx_MODULE_NAME, rtversion);
        return PyErr_WarnEx(NULL, message, 1);
    }
    return 0;
}


    static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        #if PY_MAJOR_VERSION < 3
        if (t->is_unicode) {
            *t->p = PyUnicode_DecodeUTF8(t->s, t->n - 1, NULL);
        } else if (t->intern) {
            *t->p = PyString_InternFromString(t->s);
        } else {
            *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        }
        #else
        if (t->is_unicode | t->is_str) {
            if (t->intern) {
                *t->p = PyUnicode_InternFromString(t->s);
            } else if (t->encoding) {
                *t->p = PyUnicode_Decode(t->s, t->n - 1, t->encoding, NULL);
            } else {
                *t->p = PyUnicode_FromStringAndSize(t->s, t->n - 1);
            }
        } else {
            *t->p = PyBytes_FromStringAndSize(t->s, t->n - 1);
        }
        #endif
        if (!*t->p)
            return -1;
        if (PyObject_Hash(*t->p) == -1)
            return -1;
        ++t;
    }
    return 0;
}

static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char* c_str) {
    return __Pyx_PyUnicode_FromStringAndSize(c_str, (Py_ssize_t)strlen(c_str));
}
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject* o) {
    Py_ssize_t ignore;
    return __Pyx_PyObject_AsStringAndSize(o, &ignore);
}
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
#if !CYTHON_PEP393_ENABLED
static const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    char* defenc_c;
    PyObject* defenc = _PyUnicode_AsDefaultEncodedString(o, NULL);
    if (!defenc) return NULL;
    defenc_c = PyBytes_AS_STRING(defenc);
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    {
        char* end = defenc_c + PyBytes_GET_SIZE(defenc);
        char* c;
        for (c = defenc_c; c < end; c++) {
            if ((unsigned char) (*c) >= 128) {
                PyUnicode_AsASCIIString(o);
                return NULL;
            }
        }
    }
#endif
    *length = PyBytes_GET_SIZE(defenc);
    return defenc_c;
}
#else
static CYTHON_INLINE const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    if (unlikely(__Pyx_PyUnicode_READY(o) == -1)) return NULL;
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    if (likely(PyUnicode_IS_ASCII(o))) {
        *length = PyUnicode_GET_LENGTH(o);
        return PyUnicode_AsUTF8(o);
    } else {
        PyUnicode_AsASCIIString(o);
        return NULL;
    }
#else
    return PyUnicode_AsUTF8AndSize(o, length);
#endif
}
#endif
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
    if (
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
            __Pyx_sys_getdefaultencoding_not_ascii &&
#endif
            PyUnicode_Check(o)) {
        return __Pyx_PyUnicode_AsStringAndSize(o, length);
    } else
#endif
#if (!CYTHON_COMPILING_IN_PYPY) || (defined(PyByteArray_AS_STRING) && defined(PyByteArray_GET_SIZE))
    if (PyByteArray_Check(o)) {
        *length = PyByteArray_GET_SIZE(o);
        return PyByteArray_AS_STRING(o);
    } else
#endif
    {
        char* result;
        int r = PyBytes_AsStringAndSize(o, &result, length);
        if (unlikely(r < 0)) {
            return NULL;
        } else {
            return result;
        }
    }
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject* x) {
   int is_true = x == Py_True;
   if (is_true | (x == Py_False) | (x == Py_None)) return is_true;
   else return PyObject_IsTrue(x);
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject* x) {
    int retval;
    if (unlikely(!x)) return -1;
    retval = __Pyx_PyObject_IsTrue(x);
    Py_DECREF(x);
    return retval;
}
static PyObject* __Pyx_PyNumber_IntOrLongWrongResultType(PyObject* result, const char* type_name) {
#if PY_MAJOR_VERSION >= 3
    if (PyLong_Check(result)) {
        if (PyErr_WarnFormat(PyExc_DeprecationWarning, 1,
                "__int__ returned non-int (type %.200s).  "
                "The ability to return an instance of a strict subclass of int "
                "is deprecated, and may be removed in a future version of Python.",
                Py_TYPE(result)->tp_name)) {
            Py_DECREF(result);
            return NULL;
        }
        return result;
    }
#endif
    PyErr_Format(PyExc_TypeError,
                 "__%.4s__ returned non-%.4s (type %.200s)",
                 type_name, type_name, Py_TYPE(result)->tp_name);
    Py_DECREF(result);
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x) {
#if CYTHON_USE_TYPE_SLOTS
  PyNumberMethods *m;
#endif
  const char *name = NULL;
  PyObject *res = NULL;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_Check(x) || PyLong_Check(x)))
#else
  if (likely(PyLong_Check(x)))
#endif
    return __Pyx_NewRef(x);
#if CYTHON_USE_TYPE_SLOTS
  m = Py_TYPE(x)->tp_as_number;
  #if PY_MAJOR_VERSION < 3
  if (m && m->nb_int) {
    name = "int";
    res = m->nb_int(x);
  }
  else if (m && m->nb_long) {
    name = "long";
    res = m->nb_long(x);
  }
  #else
  if (likely(m && m->nb_int)) {
    name = "int";
    res = m->nb_int(x);
  }
  #endif
#else
  if (!PyBytes_CheckExact(x) && !PyUnicode_CheckExact(x)) {
    res = PyNumber_Int(x);
  }
#endif
  if (likely(res)) {
#if PY_MAJOR_VERSION < 3
    if (unlikely(!PyInt_Check(res) && !PyLong_Check(res))) {
#else
    if (unlikely(!PyLong_CheckExact(res))) {
#endif
        return __Pyx_PyNumber_IntOrLongWrongResultType(res, name);
    }
  }
  else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_TypeError,
                    "an integer is required");
  }
  return res;
}
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject* b) {
  Py_ssize_t ival;
  PyObject *x;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_CheckExact(b))) {
    if (sizeof(Py_ssize_t) >= sizeof(long))
        return PyInt_AS_LONG(b);
    else
        return PyInt_AsSsize_t(b);
  }
#endif
  if (likely(PyLong_CheckExact(b))) {
    #if CYTHON_USE_PYLONG_INTERNALS
    const digit* digits = ((PyLongObject*)b)->ob_digit;
    const Py_ssize_t size = Py_SIZE(b);
    if (likely(__Pyx_sst_abs(size) <= 1)) {
        ival = likely(size) ? digits[0] : 0;
        if (size == -1) ival = -ival;
        return ival;
    } else {
      switch (size) {
         case 2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
      }
    }
    #endif
    return PyLong_AsSsize_t(b);
  }
  x = PyNumber_Index(b);
  if (!x) return -1;
  ival = PyInt_AsSsize_t(x);
  Py_DECREF(x);
  return ival;
}
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b) {
  return b ? __Pyx_NewRef(Py_True) : __Pyx_NewRef(Py_False);
}
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t ival) {
    return PyInt_FromSize_t(ival);
}


#endif
