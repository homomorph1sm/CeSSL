#include "ce_ssl_timer.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include "ce_ssl_defines.h"
#include "ce_ssl_stdint.h"
struct ce_ssl_timer_t{
    uint8 name[CE_SSL_FILE_PATH_MAX];
    uint64 start;
    uint64 end;
    int type;
};

/**
 * @author      gorio
 * @name        ce_ssl_timer_init
 * @description timer 初始化函数 默认类型为 CE_SSL_CYCLE
 * @calls
 * @input       [Cce_ssl_timer_tp] timer ce_ssl_timer_t 结构指针，不可以为NULL
 * @output      [ce_ssl_timer_t] timer 返回初始化好的值
 * @return      NULL for fail, not NULL for success
 * @status      @DEV
 * @calledBy:
 */
ce_ssl_timer_t ce_ssl_timer_init(ce_ssl_timer_tp timer, const char * name){
    if(timer){
        timer->start = timer->end = 0;
        timer->type = CE_SSL_CYCLE;
        strcpy(timer->name, name);
    }
    return *timer;
}
/**
 * @author      gorio
 * @name        ce_ssl_timer_start
 * @description timer 计时开始
 * @calls
 * @input       [ce_ssl_timer_tp] timer ce_ssl_timer_t 结构指针，不可以为NULL
 * @output      /
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
void ce_ssl_timer_start(ce_ssl_timer_tp timer){
    if (timer && timer->type == CE_SSL_CYCLE)
    {
//        timer->start = cpucycles();
        return;
    }
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    if (timer && timer->type == CE_SSL_NANO){
        timer->start = (uint64_t)ts.tv_sec * 1000000000LL + ts.tv_nsec;
    } else if (timer && timer->type == CE_SSL_MILLISECOND){
        timer->start = (uint64_t)ts.tv_sec * 1000LL + ts.tv_nsec / 1000000LL;
    }
    else if(timer && timer->type == CE_SSL_SECOND){
        timer->start = ts.tv_sec;
    }
}
/**
 * @author      gorio
 * @name        ce_ssl_timer_end
 * @description timer 计时停止
 * @calls
 * @input       [ce_ssl_timer_tp] timer ce_ssl_timer_t 结构指针，不可以为NULL
 * @output      /
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
void ce_ssl_timer_end(ce_ssl_timer_tp timer){
    if (timer && timer->type == CE_SSL_CYCLE)
    {
//        timer->end = cpucycles();
        return;
    }
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    if (timer && timer->type == CE_SSL_NANO){
        timer->end = (uint64_t)ts.tv_sec * 1000000000LL + ts.tv_nsec;
    } else if (timer && timer->type == CE_SSL_MILLISECOND){
        timer->end = (uint64_t)ts.tv_sec * 1000LL + ts.tv_nsec / 1000000LL;
    }
    else if(timer && timer->type == CE_SSL_SECOND){
        timer->end = ts.tv_sec;
    }
}
/**
 * @author      gorio
 * @description internal_buf 计时信息上报缓冲区
 */
CE_SSL_THREAD char internal_buf[1024];
char * ce_ssl_timer_type_str[] = {"CE_SSL_CYCLE", "CE_SSL_NANO", "CE_SSL_MILLISECOND", "CE_SSL_SECOND"};
/**
 * @author      gorio
 * @name        ce_ssl_timer_report
 * @description timer 计时信息上报函数
 * @calls
 * @input       [ce_ssl_timer_tp] timer ce_ssl_timer_t 结构指针，不可以为NULL
 *              [char *] buf 输出缓冲区，可以为NULL
 * @output      /
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
char * ce_ssl_timer_report(ce_ssl_timer_tp timer, char * buf){
    char *unit = ce_ssl_timer_type_str[timer->type];
    if (buf == NULL){
        buf = internal_buf;
    }
    sprintf(buf,"Timer:%s,start at %zu %s, end at %zu %s, cost at %zu %s \n",
            timer->name, timer->start, unit, timer->end,unit, timer->end - timer->start, unit);

    return buf;
}
/**
 * @author      gorio
 * @name        ce_ssl_timer_init
 * @description timer 初始化函数 类型为 CE_SSL_NANO
 * @calls
 * @input       [Cce_ssl_timer_tp] timer ce_ssl_timer_t 结构指针，不可以为NULL
 *              [const char *] name timer 名称
 * @output      [ce_ssl_timer_t] timer 返回初始化好的值
 * @return      NULL for fail, not NULL for success
 * @status      @DEV
 * @calledBy:
 */
ce_ssl_timer_t ce_ssl_timer_init_nano(ce_ssl_timer_tp timer, const char * name){
    if(timer){
        timer->start = timer->end = 0;
        timer->type = CE_SSL_NANO;
        strcpy(timer->name, name);
    }
    return *timer;
}
/**
 * @author      gorio
 * @name        ce_ssl_timer_init
 * @description timer 初始化函数 类型为 CE_SSL_MILLISECOND
 * @calls
 * @input       [Cce_ssl_timer_tp] timer ce_ssl_timer_t 结构指针，不可以为NULL
 *              [const char *] name timer 名称
 * @output      [ce_ssl_timer_t] timer 返回初始化好的值
 * @return      NULL for fail, not NULL for success
 * @status      @DEV
 * @calledBy:
 */
ce_ssl_timer_t ce_ssl_timer_init_ms(ce_ssl_timer_tp timer, const char * name){
    if(timer){
        timer->start = timer->end = 0;
        timer->type = CE_SSL_MILLISECOND;
        strcpy(timer->name, name);
    }
    return *timer;
}
/**
 * @author      gorio
 * @name        ce_ssl_timer_init
 * @description timer 初始化函数 类型为 CE_SSL_SECOND
 * @calls
 * @input       [Cce_ssl_timer_tp] timer ce_ssl_timer_t 结构指针，不可以为NULL
 *              [const char *] name timer 名称
 * @output      [ce_ssl_timer_t] timer 返回初始化好的值
 * @return      NULL for fail, not NULL for success
 * @status      @DEV
 * @calledBy:
 */
ce_ssl_timer_t ce_ssl_timer_init_s(ce_ssl_timer_tp timer, const char * name){
    if(timer){
        timer->start = timer->end = 0;
        timer->type = CE_SSL_SECOND;
        strcpy(timer->name, name);
    }
    return *timer;
}