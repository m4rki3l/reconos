/*
 * Copyright 1992 by Jutta Degener and Carsten Bormann, Technische
 * Universitaet Berlin.  See the accompanying file "COPYRIGHT" for
 * details.  THERE IS ABSOLUTELY NO WARRANTY FOR THIS SOFTWARE.
 */

/*$Header: /home/mguthaus/.cvsroot/mibench/telecomm/gsm/inc/proto.h,v 1.1.1.1 2000/11/06 19:54:25 mguthaus Exp $*/

#ifndef	PROTO_H
#define	PROTO_H

#if __cplusplus
#	define	NeedFunctionPrototypes	1
#endif

#if __STDC__
#	define	NeedFunctionPrototypes	1
#endif

#ifdef	_NO_PROTO
#	undef	NeedFunctionPrototypes
#endif

#undef	P	/* gnu stdio.h actually defines this... 	*/
#undef	P0
#undef	P1
#undef	P2
#undef	P3
#undef	P4
#undef	P5
#undef	P6
#undef	P7
#undef	P8
#undef	P9	/*added by Alexander Sprenger Universitaet Paderborn 2013*/
#undef	P10	/*added by Alexander Sprenger Universitaet Paderborn 2013*/

#if NeedFunctionPrototypes

#	define	P( protos )	protos

#	define	P0()				(void)
#	define	P1(x, a)			(a)
#	define	P2(x, a, b)			(a, b)
#	define	P3(x, a, b, c)			(a, b, c)
#	define	P4(x, a, b, c, d)		(a, b, c, d)	
#	define	P5(x, a, b, c, d, e)		(a, b, c, d, e)
#	define	P6(x, a, b, c, d, e, f)		(a, b, c, d, e, f)
#	define	P7(x, a, b, c, d, e, f, g)	(a, b, c, d, e, f, g)
#	define	P8(x, a, b, c, d, e, f, g, h)	(a, b, c, d, e, f, g, h)
#	define	P9(x, a, b, c, d, e, f, g, h, i)	(a, b, c, d, e, f, g, h, i)
#	define	P10(x, a, b, c, d, e, f, g, h, i, j)	(a, b, c, d, e, f, g, h, i, j)


#else /* !NeedFunctionPrototypes */

#	define	P( protos )	( /* protos */ )

#	define	P0()				()
#	define	P1(x, a)			x a;
#	define	P2(x, a, b)			x a; b;
#	define	P3(x, a, b, c)			x a; b; c;
#	define	P4(x, a, b, c, d)		x a; b; c; d;
#	define	P5(x, a, b, c, d, e)		x a; b; c; d; e;
#	define	P6(x, a, b, c, d, e, f)		x a; b; c; d; e; f;
#	define	P7(x, a, b, c, d, e, f, g)	x a; b; c; d; e; f; g;
#	define	P8(x, a, b, c, d, e, f, g, h)	x a; b; c; d; e; f; g; h;
#	define	P9(x, a, b, c, d, e, f, g, h, i)	x a; b; c; d; e; f; g; h; i;
#	define	P10(x, a, b, c, d, e, f, g, h, i, j)	x a; b; c; d; e; f; g; h; i; j;

#endif  /* !NeedFunctionPrototypes */

#endif	/* PROTO_H */
