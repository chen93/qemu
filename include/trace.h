#ifndef TRACE_H
#define TRACE_H

#include "trace/generated-tracers.h"
#define DEBUG_TRANS  1
#ifdef DEBUG_TRANS
#define TB_FROM_REQ 1
#define TB_FROM_PRE 2
extern int pre_tbs;
extern int req_tbs;
extern int pre_hit;
extern int req_hit;
#endif

#endif /* TRACE_H */
