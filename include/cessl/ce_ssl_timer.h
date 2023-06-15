#ifndef CESSL_CE_SSL_TIMER_H
#define CESSL_CE_SSL_TIMER_H


#include <stdint.h>

#define CE_SSL_CYCLE 0
#define CE_SSL_NANO 1
#define CE_SSL_MILLISECOND  2
#define CE_SSL_SECOND 3

typedef struct ce_ssl_timer_t ce_ssl_timer_t;
typedef ce_ssl_timer_t * ce_ssl_timer_tp;
/**
 * @author      杨元元
 * @name        ce_ssl_timer_init
 * @description timer 初始化函数 默认类型为 CE_SSL_CYCLE
 * @calls
 * @input       [Cce_ssl_timer_tp] timer ce_ssl_timer_t 结构指针，可以为NULL
 * @output      [ce_ssl_timer_t] timer 返回初始化好的值
 * @return      NULL for fail, not NULL for success
 * @status      @DEV
 * @calledBy:
 */
ce_ssl_timer_t ce_ssl_timer_init(ce_ssl_timer_tp timer, const char * name);
/**
 * @author      杨元元
 * @name        ce_ssl_timer_start
 * @description timer 计时开始
 * @calls
 * @input       [ce_ssl_timer_tp] timer ce_ssl_timer_t 结构指针，不可以为NULL
 * @output      /
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
void ce_ssl_timer_start(ce_ssl_timer_tp timer);
/**
 * @author      杨元元
 * @name        ce_ssl_timer_end
 * @description timer 计时停止
 * @calls
 * @input       [ce_ssl_timer_tp] timer ce_ssl_timer_t 结构指针，不可以为NULL
 * @output      /
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
void ce_ssl_timer_end(ce_ssl_timer_tp timer);
/**
 * @author      杨元元
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
char * ce_ssl_timer_report(ce_ssl_timer_tp timer, char * buf);
/**
 * @author      杨元元
 * @name        ce_ssl_timer_init
 * @description timer 初始化函数 类型为 CE_SSL_NANO
 * @calls
 * @input       [Cce_ssl_timer_tp] timer ce_ssl_timer_t 结构指针，可以为NULL
 *              [const char *] name timer 名称
 * @output      [ce_ssl_timer_t] timer 返回初始化好的值
 * @return      NULL for fail, not NULL for success
 * @status      @DEV
 * @calledBy:
 */
ce_ssl_timer_t ce_ssl_timer_init_nano(ce_ssl_timer_tp timer, const char * name);
/**
 * @author      杨元元
 * @name        ce_ssl_timer_init
 * @description timer 初始化函数 类型为 CE_SSL_MILLISECOND
 * @calls
 * @input       [Cce_ssl_timer_tp] timer ce_ssl_timer_t 结构指针，可以为NULL
 *              [const char *] name timer 名称
 * @output      [ce_ssl_timer_t] timer 返回初始化好的值
 * @return      NULL for fail, not NULL for success
 * @status      @DEV
 * @calledBy:
 */
ce_ssl_timer_t ce_ssl_timer_init_ms(ce_ssl_timer_tp timer, const char * name);
/**
 * @author      杨元元
 * @name        ce_ssl_timer_init
 * @description timer 初始化函数 类型为 CE_SSL_SECOND
 * @calls
 * @input       [Cce_ssl_timer_tp] timer ce_ssl_timer_t 结构指针，可以为NULL
 *              [const char *] name timer 名称
 * @output      [ce_ssl_timer_t] timer 返回初始化好的值
 * @return      NULL for fail, not NULL for success
 * @status      @DEV
 * @calledBy:
 */
ce_ssl_timer_t ce_ssl_timer_init_s(ce_ssl_timer_tp timer, const char * name);




#endif //CESSL_CE_SSL_TIMER_H
