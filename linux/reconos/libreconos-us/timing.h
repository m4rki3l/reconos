///
/// \file timing.h
/// Timing functions.
///
/// \author     Enno Luebbers   <luebbers@reconos.de>
/// \date       28.09.2007
//
// This file is part of the ReconOS project <http://www.reconos.de>.
// University of Paderborn, Computer Engineering Group.
//
// (C) Copyright University of Paderborn 2007.
//

#ifndef __TIMING_H__
#define __TIMING_H__

// NOTE: We can only time up to 42.9 seconds (32 bits @ 100 MHz) on eCos!
#undef USE_DCR_TIMEBASE
#define USE_GETTIMEOFDAY

#ifdef USE_ECOS
typedef unsigned int timing_t;
typedef unsigned int ms_t;
#elif defined USE_GETTIMEOFDAY
#include <sys/time.h>
typedef struct timeval timing_t;
typedef unsigned long ms_t;
#else
typedef unsigned long timing_t;
typedef unsigned long ms_t;
#endif

#define INIT_THE_CLOCK() \
	timing_t t_start = { };\
	timing_t t_stop = { };\

#define STOP_THE_CLOCK( time, action ) \
	timing_t time;\
	t_start = gettime(); \
	do{action}while(0);\
	t_stop = gettime(); \
	timerdiff(&t_stop, &t_start, &time);\

timing_t gettime();
void timerdiff(timing_t * a, timing_t * b, timing_t * diff);
int timer2string(char* s, int s_len, timing_t * t);
long int timer2s(timing_t * t);
long int timer2ms(timing_t * t);
long int timer2us(timing_t * t);

/* Deprecated */
ms_t calc_timediff_ms( timing_t start, timing_t stop );


#ifdef USE_DCR_TIMEBASE
int init_timebase();
void close_timebase();
#endif

#endif                          // __TIMING_H__
