#if 0
SL cs_add
SL cs_cholsol
SL cs_compress
SL cs_dupl
SL cs_entry
SL cs_gaxpy
SL cs_load
SL cs_lusol
SL cs_multiply
SL cs_norm
SL cs_print
SL cs_qrsol
SL cs_transpose
SL cs_calloc
SL cs_free
SL cs_realloc
SL cs_spalloc
SL cs_spfree
SL cs_sprealloc
SL cs_malloc
SL cs_symbolic
SL cs_sparse
SL cs_numeric
SL cs_dmperm_results
SL cs_amd
SL cs_chol
SL cs_dmperm
SL cs_droptol
SL cs_dropzeros
SL cs_happly
SL cs_ipvec
SL cs_lsolve
SL cs_ltsolve
SL cs_lu
SL cs_permute
SL cs_pinv
SL cs_pvec
SL cs_qr
SL cs_schol
SL cs_sqr
SL cs_symperm
SL cs_updown
SL cs_usolve
SL cs_utsolve
SL cs_sfree
SL cs_nfree
SL cs_dfree
SL cs_counts
SL cs_cumsum
SL cs_dfs
SL cs_ereach
SL cs_etree
SL cs_fkeep
SL cs_house
SL cs_leaf
SL cs_maxtrans
SL cs_post
SL cs_randperm
SL cs_reach
SL cs_scatter
SL cs_scc
SL cs_spsolve
SL cs_tdfs
SL cs_dalloc
SL cs_ddone
SL cs_done
SL cs_idone
SL cs_ndone
SL cs
SL css
SL csn
SL csd
SL cs_wclear
SL cs_diag
SL init_ata
SL cs_bfs
SL cs_unmatched
SL cs_rprune
SL cs_tol
SL cs_nonzero
SL cs_augment
SL cs_vcount
#endif

#ifndef _CS_H
#define _CS_H
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stddef.h>
#include "c_obfuscation.h"
#ifdef MATLAB_MEX_FILE
#include "mex.h"
#endif
//#define CS_VER 3                    /* CSparse Version */
//#define CS_SUBVER 1
//#define CS_SUBSUB 0
//#define CS_DATE "Jun 1, 2012"       /* CSparse release date */
//#define CS_COPYRIGHT "Copyright (c) Timothy A. Davis, 2006-2012"

#include "cs_api.h"

#ifdef __cplusplus
extern "C" {
#endif

// rk: We define csi to be int to be backward compatible with older CSparse releases.
//     At some point we might adapt the internal structures of slgo to use the same type
//     as the one given is this header file.
#define csi int

/* -------------------------------------------------------------------------- */
/* In version 3.0.0 of CSparse, "int" is no longer used.  32-bit MATLAB is
   becoming more rare, as are 32-bit computers.  CSparse now uses "csi" as its
   basic integer, which is ptrdiff_t by default (the same as mwSignedIndex in a
   MATLAB mexFunction).  That makes the basic integer 32-bit on 32-bit
   computers and 64-bit on 64-bit computers.  It is #define'd below, in case
   you wish to change it to something else (back to "int" for example).  You
   can also compile with -Dcsi=int (or whatever) to change csi without editting
   this file. */
#ifdef MATLAB_MEX_FILE
#undef csi
#define csi mwSignedIndex
#endif
#ifndef csi
#define csi ptrdiff_t
#endif
/* -------------------------------------------------------------------------- */

/* --- primary CSparse routines and data structures ------------------------- */
typedef struct cs_sparse    /* matrix in compressed-column or triplet form */
{
    csi nzmax ;     /* maximum number of entries */
    csi m ;         /* number of rows */
    csi n ;         /* number of columns */
    csi *p ;        /* column pointers (size n+1) or col indices (size nzmax) */
    csi *i ;        /* row indices, size nzmax */
    double *x ;     /* numerical values, size nzmax */
    csi nz ;        /* # of entries in triplet matrix, -1 for compressed-col */
} cs ;

SLGO_CSPARSE_API cs *cs_add (const cs *A, const cs *B, double alpha, double beta) ;
SLGO_CSPARSE_API csi cs_cholsol (csi order, const cs *A, double *b) ;
SLGO_CSPARSE_API cs *cs_compress (const cs *T) ;
SLGO_CSPARSE_API csi cs_dupl (cs *A) ;
SLGO_CSPARSE_API csi cs_entry (cs *T, csi i, csi j, double x) ;
SLGO_CSPARSE_API csi cs_gaxpy (const cs *A, const double *x, double *y) ;
SLGO_CSPARSE_API cs *cs_load (FILE *f) ;
SLGO_CSPARSE_API csi cs_lusol (csi order, const cs *A, double *b, double tol) ;
SLGO_CSPARSE_API cs *cs_multiply (const cs *A, const cs *B) ;
SLGO_CSPARSE_API double cs_norm (const cs *A) ;
SLGO_CSPARSE_API csi cs_print (const cs *A, csi brief) ;
SLGO_CSPARSE_API csi cs_qrsol (csi order, const cs *A, double *b) ;
SLGO_CSPARSE_API cs *cs_transpose (const cs *A, csi values) ;
/* utilities */
SLGO_CSPARSE_API void *cs_calloc (csi n, size_t size) ;
SLGO_CSPARSE_API void *cs_free (void *p) ;
SLGO_CSPARSE_API void *cs_realloc (void *p, csi n, size_t size, csi *ok) ;
SLGO_CSPARSE_API cs *cs_spalloc (csi m, csi n, csi nzmax, csi values, csi triplet) ;
SLGO_CSPARSE_API cs *cs_spfree (cs *A) ;
SLGO_CSPARSE_API csi cs_sprealloc (cs *A, csi nzmax) ;
SLGO_CSPARSE_API void *cs_malloc (csi n, size_t size) ;

/* --- secondary CSparse routines and data structures ----------------------- */
typedef struct cs_symbolic  /* symbolic Cholesky, LU, or QR analysis */
{
    csi *pinv ;     /* inverse row perm. for QR, fill red. perm for Chol */
    csi *q ;        /* fill-reducing column permutation for LU and QR */
    csi *parent ;   /* elimination tree for Cholesky and QR */
    csi *cp ;       /* column pointers for Cholesky, row counts for QR */
    csi *leftmost ; /* leftmost[i] = min(find(A(i,:))), for QR */
    csi m2 ;        /* # of rows for QR, after adding fictitious rows */
    double lnz ;    /* # entries in L for LU or Cholesky; in V for QR */
    double unz ;    /* # entries in U for LU; in R for QR */
} css ;

typedef struct cs_numeric   /* numeric Cholesky, LU, or QR factorization */
{
    cs *L ;         /* L for LU and Cholesky, V for QR */
    cs *U ;         /* U for LU, R for QR, not used for Cholesky */
    csi *pinv ;     /* partial pivoting for LU */
    double *B ;     /* beta [0..n-1] for QR */
} csn ;

typedef struct cs_dmperm_results    /* cs_dmperm or cs_scc output */
{
    csi *p ;        /* size m, row permutation */
    csi *q ;        /* size n, column permutation */
    csi *r ;        /* size nb+1, block k is rows r[k] to r[k+1]-1 in A(p,q) */
    csi *s ;        /* size nb+1, block k is cols s[k] to s[k+1]-1 in A(p,q) */
    csi nb ;        /* # of blocks in fine dmperm decomposition */
    csi rr [5] ;    /* coarse row decomposition */
    csi cc [5] ;    /* coarse column decomposition */
} csd ;

SLGO_CSPARSE_API csi *cs_amd (csi order, const cs *A) ;
SLGO_CSPARSE_API csn *cs_chol (const cs *A, const css *S) ;
SLGO_CSPARSE_API csd *cs_dmperm (const cs *A, csi seed) ;
SLGO_CSPARSE_API csi cs_droptol (cs *A, double tol) ;
SLGO_CSPARSE_API csi cs_dropzeros (cs *A) ;
SLGO_CSPARSE_API csi cs_happly (const cs *V, csi i, double beta, double *x) ;
SLGO_CSPARSE_API csi cs_ipvec (const csi *p, const double *b, double *x, csi n) ;
SLGO_CSPARSE_API csi cs_lsolve (const cs *L, double *x) ;
SLGO_CSPARSE_API csi cs_ltsolve (const cs *L, double *x) ;
SLGO_CSPARSE_API csn *cs_lu (const cs *A, const css *S, double tol) ;
SLGO_CSPARSE_API cs *cs_permute (const cs *A, const csi *pinv, const csi *q, csi values) ;
SLGO_CSPARSE_API csi *cs_pinv (const csi *p, csi n) ;
SLGO_CSPARSE_API csi cs_pvec (const csi *p, const double *b, double *x, csi n) ;
SLGO_CSPARSE_API csn *cs_qr (const cs *A, const css *S) ;
SLGO_CSPARSE_API css *cs_schol (csi order, const cs *A) ;
SLGO_CSPARSE_API css *cs_sqr (csi order, const cs *A, csi qr) ;
SLGO_CSPARSE_API cs *cs_symperm (const cs *A, const csi *pinv, csi values) ;
SLGO_CSPARSE_API csi cs_updown (cs *L, csi sigma, const cs *C, const csi *parent) ;
SLGO_CSPARSE_API csi cs_usolve (const cs *U, double *x) ;
SLGO_CSPARSE_API csi cs_utsolve (const cs *U, double *x) ;
/* utilities */
SLGO_CSPARSE_API css *cs_sfree (css *S) ;
SLGO_CSPARSE_API csn *cs_nfree (csn *N) ;
SLGO_CSPARSE_API csd *cs_dfree (csd *D) ;

/* --- tertiary CSparse routines -------------------------------------------- */
SLGO_CSPARSE_API csi *cs_counts (const cs *A, const csi *parent, const csi *post, csi ata) ;
SLGO_CSPARSE_API double cs_cumsum (csi *p, csi *c, csi n) ;
SLGO_CSPARSE_API csi cs_dfs (csi j, cs *G, csi top, csi *xi, csi *pstack, const csi *pinv) ;
SLGO_CSPARSE_API csi cs_ereach (const cs *A, csi k, const csi *parent, csi *s, csi *w) ;
SLGO_CSPARSE_API csi *cs_etree (const cs *A, csi ata) ;
SLGO_CSPARSE_API csi cs_fkeep (cs *A, csi (*fkeep) (csi, csi, double, void *), void *other) ;
SLGO_CSPARSE_API double cs_house (double *x, double *beta, csi n) ;
SLGO_CSPARSE_API csi cs_leaf (csi i, csi j, const csi *first, csi *maxfirst, csi *prevleaf,
    csi *ancestor, csi *jleaf) ;
SLGO_CSPARSE_API csi *cs_maxtrans (const cs *A, csi seed) ;
SLGO_CSPARSE_API csi *cs_post (const csi *parent, csi n) ;
SLGO_CSPARSE_API csi *cs_randperm (csi n, csi seed) ;
SLGO_CSPARSE_API csi cs_reach (cs *G, const cs *B, csi k, csi *xi, const csi *pinv) ;
SLGO_CSPARSE_API csi cs_scatter (const cs *A, csi j, double beta, csi *w, double *x, csi mark,
    cs *C, csi nz) ;
SLGO_CSPARSE_API csd *cs_scc (cs *A) ;
SLGO_CSPARSE_API csi cs_spsolve (cs *G, const cs *B, csi k, csi *xi, double *x,
    const csi *pinv, csi lo) ;
SLGO_CSPARSE_API csi cs_tdfs (csi j, csi k, csi *head, const csi *next, csi *post,
    csi *stack) ;
/* utilities */
SLGO_CSPARSE_API csd *cs_dalloc (csi m, csi n) ;
SLGO_CSPARSE_API csd *cs_ddone (csd *D, cs *C, void *w, csi ok) ;
SLGO_CSPARSE_API cs *cs_done (cs *C, void *w, void *x, csi ok) ;
SLGO_CSPARSE_API csi *cs_idone (csi *p, cs *C, void *w, csi ok) ;
SLGO_CSPARSE_API csn *cs_ndone (csn *N, cs *C, void *w, void *x, csi ok) ;

#define CS_MAX(a,b) (((a) > (b)) ? (a) : (b))
#define CS_MIN(a,b) (((a) < (b)) ? (a) : (b))
#define CS_FLIP(i) (-(i)-2)
#define CS_UNFLIP(i) (((i) < 0) ? CS_FLIP(i) : (i))
#define CS_MARKED(w,j) (w [j] < 0)
#define CS_MARK(w,j) { w [j] = CS_FLIP (w [j]) ; }
#define CS_CSC(A) (A && (A->nz == -1))
#define CS_TRIPLET(A) (A && (A->nz >= 0))
#endif

#ifdef __cplusplus
}
#endif

