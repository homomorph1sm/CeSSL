
#ifndef CESSL_CE_CRYPTO_HANDLER_H
#define CESSL_CE_CRYPTO_HANDLER_H

#include "ce_ssl_core.h"
#include "ce_ssl_defines.h"

/***
 * @author: 任雄鹏
 * @name: struct CeSSLCryptoHandler
 * @alias:
 *      @see CeSSLCryptoHandler
 *      @see CeSSLCryptoHandlerPointer
 * @param version           当前的版本号 @see CE_SSL_VERSION_CPT_HANDLER_*宏
 * @param name              算法名称，最大长度 @see CE_SSL_HANDLER_NAME_MAX
 * @param types             算法内部编号 @see  CeSSLCryptoTypes
 * @param reallyHandler     通常情况下是NULL， 但存在一种情况，即@param class == FunctionAlias时，其余成员均为NULL，
 *                              此时该值会指向对应的别名代指的Handler地址
 * @param destructor        算法Handler的析构方法，默认为NULL
 * @param class             标识一个算法会属于哪一类算法 @see CeSSLCryptoClassify
 * @param handler           算法可执行的函数指针，默认排序为[加密（哈希）、解密、签名、验签]
 * @param status            当前算法的状态，@see AU_AC_CRYPTO_TYPE_HANDLER_STATUS_* 宏
 * @param memoryType        可以预估的内存类型，默认get的handler为@see StackMemory, 否则应该为@see HeapMemory
 */


struct CeSSLCryptoHandler {
    int version;
    char name[CE_SSL_HANDLER_NAME_MAX];
    CeSSLCryptoTypes types;
    struct CeSSLCryptoHandler * reallyHandler;
    CeSSLCryptoHandlerPointerDestructor destructor;
    CeSSLCryptoClassify class;
    CeSSLCryptoHandlerHandlerMethod handler[4];
    int status;
    CeSSLCryptoMemoryType memoryType;
};
/**
 * @author      任雄鹏
 * @name        ce_ssl_crypto_handler_constructor
 * @description CeSSLCryptoHandler 初始化函数
 * @calls
 * @input       [CeSSLCryptoHandler *] handler CeSSLCryptoHandler 结构指针，可以为NULL
 * @output      [CeSSLCryptoHandler *] handler 若传入的handler不为空，则返回初始化好的值
 * @return      NULL for fail, not NULL for success
 * @status      @DEV
 * @calledBy:
 */

CeSSLCryptoHandlerPointer ce_ssl_crypto_handler_constructor(CeSSLCryptoHandler * handler);


#endif //CESSL_CE_CRYPTO_HANDLER_H
