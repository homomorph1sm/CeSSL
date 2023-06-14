//
// Created by 83672 on 2023/6/14.
//

#ifndef CESSL_CE_SSL_CORE_H
#define CESSL_CE_SSL_CORE_H
#include "ce_ssl_errno.h"
#include "ce_ssl_stdint.h"
#include "ce_ssl_defines.h"



typedef struct CeSSLCryptoCore       CeSSLCryptoCore;
typedef struct CeSSLCryptoHandler    CeSSLCryptoHandler;
typedef struct CeSSLCryptoHandler  * CeSSLCryptoHandlerPointer;
typedef struct CeSSLKeyHandler       CeSSLKeyHandler;
typedef struct CeSSLKeyHandler     * CeSSLKeyHandlerPointer;
typedef struct CeSSLResultHandler    CeSSLCryptoResultHandler;
typedef struct CeSSLResultHandler  * CeSSLCryptoResultHandlerPointer;
typedef struct CeSSLContextHandler   CeSSLContextHandler;
typedef struct CeSSLContextHandler * CeSSLContextHandlerPointer;
typedef struct CeSSLKeyEnvelope      CeSSLKeyEnvelope;
typedef struct CeSSLKeyEnvelope    * CeSSLKeyEnvelopePointer;

typedef CeSSLCryptoHandlerPointer (*CeSSLCryptoHandlerPointerConstructor)(void * args);
typedef ce_ssl_errno_t (*CeSSLCryptoHandlerPointerDestructor)(CeSSLCryptoHandlerPointer handler);
typedef ce_ssl_errno_t (*CeSSLCryptoHandlerHandlerMethod)(CeSSLCryptoHandlerPointer handler,
                                                    CeSSLKeyHandlerPointer key,
                                                    CeSSLContextHandlerPointer context,
                                                    CeSSLCryptoResultHandlerPointer* result);




/**
 * @author      gorio
 * @name        ce_ssl_crypto_core_init
 * @description crypto库初始化函数
 * @calls
 * @input       /
 * @output      /
 * @return      [ce_ssl_errno_t] AC_AU_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 *              @see int main(void)
 */
ce_ssl_errno_t ce_ssl_crypto_core_init();

/**
 * @author      gorio
 * @name        ce_ssl_crypto_core_init_by_config_file
 * @description crypto库通过配置文件初始化函数
 * @calls
 * @input       [char *] filePath 文件路径
 * @output      /
 * @return      [ce_ssl_errno_t] AC_AU_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_crypto_core_init_by_config_file(char * filePath);
/**
 * @author      gorio
 * @name        ce_ssl_crypto_get_handler
 * @description 获取一个算法的handler
 * @calls
 * @input       [CeSSLCryptoTypes] cryptoTypes  算法编号
 * @output      /
 * @return      [CeSSLCryptoHandlerPointer] not NULL for success, NULL for fail
 * @status      @TODO
 * @calledBy:
 */
CeSSLCryptoHandlerPointer ce_ssl_crypto_get_handler(CeSSLCryptoTypes cryptoTypes);
/**
 * @author      gorio
 * @name        ce_ssl_crypto_get_handler_by_name
 * @description 获取一个算法的handler
 * @calls
 * @input       [char *] name  算法名
 * @output      /
 * @return      [ce_ssl_errno_t] AC_AU_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 */
CeSSLCryptoHandlerPointer ce_ssl_crypto_get_handler_by_name(char * name);
/**
 * @author      gorio
 * @note        此函数无法在运行时进行禁用，必须在调用第一个handler之前调用
 * @name        ce_ssl_crypto_core_disable_handler
 * @description 禁用一种算法
 * @calls
 * @input       [CeSSLCryptoTypes] cryptoTypes  算法编号
 * @output      /
 * @return      [ce_ssl_errno_t] AC_AU_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_crypto_core_disable_handler(CeSSLCryptoTypes cryptoTypes);
/**
 * @author      gorio
 * @note        此函数无法在运行时进行禁用，必须在调用第一个handler之前调用
 * @name        ce_ssl_crypto_core_disable_handler
 * @description 禁用一种算法
 * @calls
 * @input       [char *] name  算法名
 * @output      /
 * @return      [ce_ssl_errno_t] AC_AU_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_crypto_core_disable_handler_by_name(char * name);
/**
 * @author      gorio
 * @note        此函数无法在运行时进行禁用，必须在调用第一个handler之前调用
 * @name        ce_ssl_crypto_core_enable_handler
 * @description 启用一种算法
 * @calls
 * @input       [CeSSLCryptoTypes] cryptoTypes 算法编号
 * @output      /
 * @return      [ce_ssl_errno_t] AC_AU_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_crypto_core_enable_handler(CeSSLCryptoTypes cryptoTypes);
/**
 * @author      gorio
 * @note        此函数无法在运行时进行禁用，必须在调用第一个handler之前调用
 * @name        ce_ssl_crypto_core_enable_handler_by_name
 * @description 启用一种算法
 * @calls
 * @input       [char *] name  算法名
 * @output      /
 * @return      [ce_ssl_errno_t] AC_AU_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_crypto_core_enable_handler_by_name(char * name);
/**
 * @author      gorio
 * @note        此函数无法在运行时进行禁用，必须在调用第一个handler之前调用
 * @name        ce_ssl_crypto_add_handler
 * @description 添加一种算法
 * @calls
 * @input       [CeSSLCryptoTypes]                       cryptoTypes 算法名
 *              [CeSSLCryptoHandlerPointerConstructor]   constructor 构造器
 *              [CeSSLCryptoHandlerPointerDestructor]    destructor  析构器
 *              [CeSSLCryptoHandlerHandlerMethod]        method      承载方法
 *              [bool]                                  saveForever 是否永久保存
 * @output      /
 * @return      [ce_ssl_errno_t] AC_AU_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_crypto_add_handler(CeSSLCryptoTypes cryptoTypes,
                                  CeSSLCryptoHandlerPointerConstructor constructor,
                                  CeSSLCryptoHandlerPointerDestructor destructor,
                                  CeSSLCryptoHandlerHandlerMethod method,
                                  bool saveForever);
/**
 * @author      gorio
 * @note        此函数无法在运行时进行禁用，必须在调用第一个handler之前调用，且不会持久化，本次运行有效
 * @name        ce_ssl_crypto_add_static_handler
 * @description 添加一种算法
 * @calls
 * @input       [CeSSLCryptoTypes]                       cryptoTypes 算法名
 *              [char *]                                libPath     库的路径必须是.so文件
 *              [char *]                                methodName  对应的方法名
 *              [saveForever]                           method      承载方法
 *              [bool]                                  saveForever 是否永久保存
 * @output      /
 * @return      [ce_ssl_errno_t] AC_AU_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_crypto_add_static_handler(CeSSLCryptoTypes cryptoTypes,
                                         char * libPath,
                                         char * methodName,
                                         bool saveForever);
/**
 * @author      gorio
 * @name        ce_ssl_crypto_do
 * @description 运行发此方法会将core的状态从inited --> running
 * @calls
 * @input       [CeSSLCryptoHandlerPointer]              handler     算法句柄
 *              [CeSSLKeyHandlerPointer]                 key         密钥句柄
 *              [CeSSLContextHandlerPointer]             context     上下文句柄
 *              [CeSSLCryptoResultHandlerPointer *]      result      算法结果
 * @output      /
 * @return      [ce_ssl_errno_t] AC_AU_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_crypto_do(CeSSLCryptoHandlerPointer handler,
                         CeSSLKeyHandlerPointer key,
                         CeSSLContextHandlerPointer context,
                         CeSSLCryptoResultHandlerPointer *result);
/**
 * @author      gorio
 * @name        ce_ssl_crypto_get_better_performance
 * @description 对比多个相同类型算法，获得最佳的效率
 * @calls
 * @input       [CeSSLKeyHandler*]              handler     算法句柄
 *              [CeSSLKeyHandlerPointer]        keyHandler  密钥句柄
 *              [CeSSLKeyHandler*]  * n         context     上下文句柄
 * @output      /
 * @return      [CeSSLKeyHandler*]  返回效率最高的一个handler（单纯指时间）
 * @status      @TODO
 * @calledBy:
 */
CeSSLKeyHandler* ce_ssl_crypto_get_better_performance(CeSSLKeyHandler * handler1, CeSSLContextHandler context,
                                                   CeSSLKeyHandler keyHandler, ...);


/**
 * @author      gorio
 * @name        ce_ssl_crypto_handler_default_destructor
 * @description void 析构函数
 * @calls
 * @input       [CeSSLCryptoHandler *] handler CeSSLCryptoHandler 结构指针，可以为NULL
 * @output      /
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
void ce_ssl_crypto_handler_default_destructor(CeSSLCryptoHandler * handler);


/************************CONTEXT_HANDLER_METHOD_HERE******************************/
/**
 * @author      gorio
 * @name        ce_ssl_context_handler_constructor
 * @description CeSSLContextHandler 初始化函数
 * @calls
 * @input       [char *]            plainTextLen    明文数据
 *              [int]               plainTextLen    明文数据的长度
 *              [char *]            cipherText      密文数据
 *              [int]               cipherTextLen   密文数据的长度
 *              [CeSSLContextType]   type            上下文的类型
 * @output      /
 * @return      [CeSSLContextHandlerPointer] not NULL for success, NULL for fail
 * @status      @DEV
 * @calledBy:
 *              @see ce_ssl_context_handler_plain_constructor
 *              @see ce_ssl_context_handler_cipher_constructor
 */
CeSSLContextHandlerPointer ce_ssl_context_handler_constructor(char * plainText, int plainTextLen, char * cipherText,
                                                           int cipherTextLen, CeSSLContextType type);
/**
 * @author      gorio
 * @name        ce_ssl_context_handler_append
 * @description CeSSLContextHandler 向handler中添加数据，深拷贝
 * @calls
 * @input       [CeSSLContextHandlerPointer]            handler    上下文句柄
 *              [char *]            plainText      明文数据
 *              [int]               plainTextLen  明文数据长度
 *              [CeSSLContextType]   type            上下文的类型
 * @output      /
 * @return      [CeSSLContextHandlerPointer] not NULL for success, NULL for fail
 * @status      @DEV
 * @calledBy:
 *              @see ce_ssl_context_handler_plain_constructor
 *              @see ce_ssl_context_handler_cipher_constructor
 */
ce_ssl_errno_t ce_ssl_context_handler_append(CeSSLContextHandlerPointer handler, char * plainText, int plainTextLen);
/**
 * @author      gorio
 * @name        ce_ssl_context_handler_crypto_constructor
 * @description CeSSLContextHandler 加密快捷初始化函数
 * @calls       @see ce_ssl_context_handler_constructor
 * @input       [char *]            data       数据指针
 *              [int]               dataLen    数据长度
 * @output      /
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
CeSSLContextHandlerPointer ce_ssl_context_handler_crypto_constructor(char * data, int dataLen) ;
/**
 * @author      gorio
 * @name        ce_ssl_context_handler_crypto_constructor
 * @description CeSSLContextHandler 哈希快捷初始化函数
 * @calls       @see ce_ssl_context_handler_constructor
 * @input       [char *]            data       数据指针
 *              [int]               dataLen    数据长度
 * @output      /
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
CeSSLContextHandlerPointer ce_ssl_context_handler_hash_constructor(char * data, int dataLen) ;
/**
 * @author      gorio
 * @name        ce_ssl_context_handler_decrypt_constructor
 * @description CeSSLContextHandler 解密快捷初始化函数
 * @calls       @see ce_ssl_context_handler_constructor
 * @input       [char *]            data       数据指针
 *              [int]               dataLen    数据长度
 * @output      /
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
CeSSLContextHandlerPointer ce_ssl_context_handler_decrypt_constructor(char * data, int dataLen);
/**
 * @author      gorio
 * @name        ce_ssl_context_handler_sign_constructor
 * @description CeSSLContextHandler 签名快捷初始化函数
 * @calls       @see ce_ssl_context_handler_constructor
 * @input       [char *]            data       数据指针
 *              [int]               dataLen    数据长度
 * @output      /
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
CeSSLContextHandlerPointer ce_ssl_context_handler_sign_constructor(char * data, int dataLen);
/**
 * @author      gorio
 * @name        ce_ssl_context_handler_verify_constructor
 * @description CeSSLContextHandler 验签快捷初始化函数
 * @calls       @see ce_ssl_context_handler_constructor
 * @input       [char *]            plainTextLen    明文数据
 *              [int]               plainTextLen    明文数据的长度
 *              [char *]            cipherText      密文数据
 *              [int]               cipherTextLen   密文数据的长度
 * @output      /
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
CeSSLContextHandlerPointer ce_ssl_context_handler_verify_constructor(char * plainText, int plainTextLen, char * cipherText,
                                                                  int cipherTextLen);

/**
 * @author      gorio
 * @name        ce_ssl_context_handler_destructor
 * @note        对于浅拷贝的指针，在这里不会被释放，因此需要额外注意内存泄露的问题
 * @description void 析构函数
 * @calls
 * @input       [CeSSLContextHandlerPointer] ptr 要被析构的结构体
 * @output      /
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
void ce_ssl_context_handler_destructor(CeSSLContextHandlerPointer ptr);

/**
 * @author      gorio
 * @name        ce_ssl_context_handler_change_output_type
 * @description void 更改context_handler输出样式
 * @calls
 * @input       [CeSSLContextHandlerPointer] ptr
 *              [CeSSLCryptoOutputType]      outputType  输出的结果样式
 * @output      /
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
void ce_ssl_context_handler_change_output_type(CeSSLContextHandlerPointer ptr, CeSSLCryptoOutputType outputType);
/**
 * @author      gorio
 * @name        ce_ssl_context_handler_get_output_type
 * @description [CeSSLCryptoOutputType] 获取结果样式
 * @calls
 * @input       [CeSSLContextHandlerPointer] ptr
 * @output      /
 * @return      [CeSSLCryptoOutputType]  输出的结果样式
 * @status      @DEV
 * @calledBy:
 */
CeSSLCryptoOutputType ce_ssl_context_handler_get_output_type(CeSSLContextHandlerPointer ptr);

/************************KEY_HANDLER_METHOD_HERE******************************/
/**
 * @author      gorio
 * @name        ce_ssl_key_handler_constructor
 * @note        key为浅拷贝
 * @description CeSSLKeyHandler 初始化函数
 * @calls
 * @input       [char *]            key         密钥
 *              [int]               keyLen      密钥长度
 *              [CeSSLKeyType]       type        密钥类型
 * @output      /
 * @return      [CeSSLKeyHandlerPointer]  not NULL for success, NULL for fail
 * @status      @DEV
 * @calledBy:
 */
CeSSLKeyHandlerPointer ce_ssl_key_handler_constructor(char * key, int keyLen, CeSSLKeyType type);
/**
 * @author      gorio
 * @name        ce_ssl_key_handler_add_iv
 * @note        iv为浅拷贝
 * @description 向一个非空的keyHandler添加IV
 * @calls
 * @input       [CeSSLKeyHandlerPointer]            ptr         CeSSLKeyHandler结构，非空
 *              [char *]                           iv          初始向量
 *              [CeSSLKeyType]                      ivLen       初始向量长度
 * @output      [CeSSLKeyHandlerPointer]            ptr         CeSSLKeyHandler结构，非空
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
void ce_ssl_key_handler_add_iv(CeSSLKeyHandlerPointer ptr, char * iv, int ivLen);
/**
 * @author      gorio
 * @name        ce_ssl_key_handler_key_path
 * @note        keyPath
 * @description CeSSLKeyHandler 初始化函数
 * @calls
 * @input       [char *]            keyPath     密钥或证书路径
 *              [int]               keyLen      密钥长度
 *              [CeSSLKeyType]       type        密钥类型
 * @output      /
 * @return      [CeSSLKeyHandlerPointer]  not NULL for success, NULL for fail
 * @status      @DEV
 * @calledBy:
 */
CeSSLKeyHandlerPointer ce_ssl_key_handler_key_path(char * keyPath, int pathLen);
/**
 * @author      gorio
 * @note        对于浅拷贝的指针，在这里不会被释放，因此需要额外注意内存泄露的问题
 * @name        ce_ssl_key_handler_destructor
 * @description void 析构函数
 * @calls
 * @input       [CeSSLKeyHandlerPointer] ptr 要被析构的结构体
 * @output      /
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
void ce_ssl_key_handler_destructor(CeSSLKeyHandlerPointer ptr);

/************************RESULT_HANDLER_METHOD_HERE******************************/

/**
 * @author      gorio
 * @name        ce_ssl_result_handler_destructor
 * @description void 析构函数
 * @calls
 * @input       [CeSSLCryptoResultHandlerPointer] ptr 要被析构的结构体
 * @output      /
 * @return      /
 * @status      @DEV
 * @calledBy:
 */
void ce_ssl_result_handler_destructor(CeSSLCryptoResultHandlerPointer ptr);
/**
 * @author      gorio
 * @name        ce_ssl_result_handler_get_result
 * @note        对于bufLen 必须是非空的，且必须严格等于buf的实际长度,当bufLen ==0时，bufLen返回需要的长度
 * @description 数据获取函数
 * @calls
 * @input       [CeSSLCryptoResultHandlerPointer] ptr             提取数据的指针
 * @output      [void *]                         buff            用户态缓存区
 *              [int *]                          bufLen          写入buff的长度
 * @return      [ce_ssl_errno_t] AC_AU_SUCCESS for success, other values for fail
 * @status      @DEV
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_result_handler_get_result(CeSSLCryptoResultHandlerPointer ptr, void * buf, int * bufLen);

/**
 * @author      李泽健
 * @name        ce_ssl_result_handler_get_results
 * @note        对于bufLen 必须是非空的，且必须严格等于buf的实际长度,当bufLen ==0时，bufLen返回需要的长度
 * @description 从结果数组中批量获取数据
 * @calls
 * @input       [CeSSLCryptoResultHandlerPointer] ptr          提取数据的指针
 * @output      [void *]                         buff         用户态缓存区
 *              [int *]                          bufLen       写入buff的长度
 *              [int]                            start        起始位置角标
 *              [int]                            sum          读取数量
 * @return      [ce_ssl_errno_t] AC_AU_SUCCESS for success, other values for fail
 * @status      @DEV
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_result_handler_get_results(CeSSLCryptoResultHandlerPointer ptr, int start, int sum, ...);
/**
 * @author      李泽健
 * @name        ce_ssl_result_handler_get_specific_result
 * @note        对于bufLen 必须是非空的，且必须严格等于buf的实际长度,当bufLen ==0时，bufLen返回需要的长度
 * @description 从结果数组中获取单一结果
 * @calls
 * @input       [CeSSLCryptoResultHandlerPointer] ptr          提取数据的指针
 * @output      [void *]                         buff         用户态缓存区
 *              [int *]                          bufLen       写入buff的长度
 *              [int]                            pos          读取单个位置角标
 * @return      [ce_ssl_errno_t] AC_AU_SUCCESS for success, other values for fail
 * @status      @DEV
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_result_handler_get_specific_result(CeSSLCryptoResultHandlerPointer ptr, int pos, void * buf, int * bufLen);

/**
 * @author          李泽健
 * @name            ce_sslcrypto_core_set_5g_fn_sz
 * @description     设置5g_fn中相关字段的大小
 * @param keyType   字段类型
 * @param value     字段大小，使用宏定义赋值
 * @param ...       @TODO 使用可变参数实现同时设置多个字段大小
 * @return
 */
ce_ssl_errno_t ce_sslcrypto_core_set_5g_fn_sz(CeSSLTuakFnType keyType, uint8 value, ...);

/**
 * @author                  李泽健
 * @name                    ce_sslcrypto_core_set_5g_fn_hashmethod
 * @description             设置5g_fn使用的哈希方法及轮数
 * @param hashmethod        5g_fn中使用的哈希方法名称，枚举类型
 * @param hashRounds        哈希轮数，默认1次
 * @return
 */
ce_ssl_errno_t ce_sslcrypto_core_set_5g_fn_hashmethod(CeSSLTuakFnHash hashmethod,int hashRounds);

/**
 * @author              李泽健
 * @name                ce_sslcrypto_core_set_5g_fn_top
 * @description         设置5g_fn中的TOP字段，深拷贝
 * @param top           TOP字段参数
 */
void ce_sslcrypto_core_set_5g_fn_top(uint8 *top);
#ifdef AC_AU_DEBUG_MODE
void ce_ssl_crypto_handler_print(CeSSLCryptoHandlerPointer pointer);
#endif





#endif //CESSL_CE_SSL_CORE_H
