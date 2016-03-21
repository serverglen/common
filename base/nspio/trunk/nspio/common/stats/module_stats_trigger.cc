// copyright:
//            (C) SINA Inc.
//
//           file: nspio/common/stats/module_stats_trigger.cc
//           desc: 
//  signed-off-by: Dong Fang <yp.fangdong@gmail.com>
//           date: 2014-02-14


#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <nspio/errno.h>
#include "os/memalloc.h"
#include "module_stats.h"


NSPIO_DECLARATION_START

module_stat_trigger::module_stat_trigger(int range) :
    key_range(range)
{
    uint32_t chunksize = sizeof(int64_t) * range;
    char *last = NULL;

    while ((last = (char *)mem_zalloc(chunksize * 4)) == NULL) {
    }
    last_s = (int64_t *)(last + chunksize * 0);
    last_m = (int64_t *)(last + chunksize * 1);
    last_h = (int64_t *)(last + chunksize * 2);
    last_d = (int64_t *)(last + chunksize * 3);
}

module_stat_trigger::~module_stat_trigger() {
    uint32_t chunksize = sizeof(int64_t) * key_range;
    mem_free(last_s, chunksize * 4);
}


int64_t module_stat_trigger::getlast_s(int key) {
    return last_s[key - 1];
}


int64_t module_stat_trigger::getlast_m(int key) {
    return last_m[key - 1];
}


int64_t module_stat_trigger::getlast_h(int key) {
    return last_h[key - 1];
}


int64_t module_stat_trigger::getlast_d(int key) {
    return last_d[key - 1];
}










}