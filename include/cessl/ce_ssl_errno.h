
#ifndef CESSL_CE_SSL_ERRNO_H
#define CESSL_CE_SSL_ERRNO_H
#include "ce_ssl_errno_defines.h"

typedef int ce_ssl_errno_t;

/**
 * @author      gorio
 * @name        ce_ssl_set_pthread_errno
 * @description 为特定线程添加一个errno
 * @calls
 * @input       [ce_ssl_errno_t]              errno     错误码
 * @output      /
 * @return      [ce_ssl_errno_t] CE_SSL_SUCCESS for success, other values for fail
 * @status      @UnderChecking
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_set_pthread_errno(ce_ssl_errno_t errno);

/**
 * @author      gorio
 * @name        ce_ssl_get_errno_readable_message
 * @description 获取特定的errono对应的可读的信息
 * @calls
 * @input       [ce_ssl_errno_t]              errno     错误码
 * @output      /
 * @return      [char *] 一个栈上的内存空间，不需要手动释放
 * @status      @UnderChecking
 * @calledBy:
 */
char * ce_ssl_get_errno_readable_message(ce_ssl_errno_t errno);


#endif //CESSL_CE_SSL_ERRNO_H
