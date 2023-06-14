#include "ce_ssl_errno.h"
#include "ce_ssl_errno_defines.h"
#include "ce_ssl_defines.h"

static char * ERRNO_MESSAGES[] = {
        CE_SSL_ERRNO_STR_0,
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        CE_SSL_ERRNO_STR_43,
        CE_SSL_ERRNO_STR_44,
        CE_SSL_ERRNO_STR_45,
        CE_SSL_ERRNO_STR_46,
        CE_SSL_ERRNO_STR_47};

#define CE_SSL_MAX_ERRORS sizeof(ERRNO_MESSAGES)/sizeof(char *)


CE_SSL_THREAD ce_ssl_errno_t _errno;

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
ce_ssl_errno_t ce_ssl_set_pthread_errno(ce_ssl_errno_t errno) {
    _errno = errno;
    return _errno;
}

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
char * ce_ssl_get_errno_readable_message(ce_ssl_errno_t errno){
    if (errno <CE_SSL_MAX_ERRORS) {
        return ERRNO_MESSAGES[errno];
    }
    return CE_SSL_ERRNO_STR_43;
}




















