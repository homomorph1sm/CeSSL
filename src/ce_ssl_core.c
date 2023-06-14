#include "ce_ssl_core.h"
#include <stdio.h>
#include "ce_ssl_version.h"
/***
 * @author: gorio
 * @name: struct CeSSLCryptoCore
 * @alias:
 *      @see CeSSLCryptoCore
 * @param version           当前的版本号 @see CE_SSL_VERSION_CORE_* 宏
 * @param handlers          指向栈空间上的结构体数组，目前不可扩展
 * @param extraHandlers     额外的扩展数组（堆上），用户自添加的，用户自定义的，通过chains导出的
 * @param maxOfHandlers     当前支持的算法总数，即len(this.handlers) + len(this.extraHandlers)
 * @param configPath        当前配置文件的路径，最大长度为255字节
 * @param initStatus        当前初始化状态,@see CE_SSL_CRYPTO_CORE_STATUS_* 宏
 */
struct CeSSLCryptoCore {
    int version;
    CeSSLCryptoHandlerPointer handlers;
    CeSSLCryptoHandlerPointer extraHandlers;
    int maxOfHandlers;
    char configPath[CE_SSL_FILE_PATH_MAX];
    int initStatus;
};

/**
 * @author gorio
 * @name g_ch_array
 * @type struct CeSSLCryptoHandler[]
 * @usage g_cc_core->handlers = g_ch_array;
 */
struct CeSSLCryptoHandler g_ch_array[] = {
        {.name = "AES_128_CBC", .types = AES_128_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_128_CBC_HMAC_SHA1", .types = AES_128_CBC_HMAC_SHA1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_128_CBC_HMAC_SHA256", .types = AES_128_CBC_HMAC_SHA256, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "id_aes128_CCM", .types = id_aes128_CCM, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_128_CFB", .types = AES_128_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_128_CFB1", .types = AES_128_CFB1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_128_CFB8", .types = AES_128_CFB8, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_128_CTR", .types = AES_128_CTR, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_128_ECB", .types = AES_128_ECB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "id_aes128_GCM", .types = id_aes128_GCM, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_128_OCB", .types = AES_128_OCB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_128_OFB", .types = AES_128_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_128_XTS", .types = AES_128_XTS, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_192_CBC", .types = AES_192_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "id_aes192_CCM", .types = id_aes192_CCM, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_192_CFB", .types = AES_192_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_192_CFB1", .types = AES_192_CFB1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_192_CFB8", .types = AES_192_CFB8, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_192_CTR", .types = AES_192_CTR, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_192_ECB", .types = AES_192_ECB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "id_aes192_GCM", .types = id_aes192_GCM, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_192_OCB", .types = AES_192_OCB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_192_OFB", .types = AES_192_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_256_CBC", .types = AES_256_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_256_CBC_HMAC_SHA1", .types = AES_256_CBC_HMAC_SHA1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_256_CBC_HMAC_SHA256", .types = AES_256_CBC_HMAC_SHA256, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "id_aes256_CCM", .types = id_aes256_CCM, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_256_CFB", .types = AES_256_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_256_CFB1", .types = AES_256_CFB1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_256_CFB8", .types = AES_256_CFB8, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_256_CTR", .types = AES_256_CTR, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_256_ECB", .types = AES_256_ECB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "id_aes256_GCM", .types = id_aes256_GCM, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_256_OCB", .types = AES_256_OCB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_256_OFB", .types = AES_256_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "AES_256_XTS", .types = AES_256_XTS, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "aes128", .types = aes128, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => AES_128_CBC,
        {.name = "aes128_wrap", .types = aes128_wrap, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => id_aes128_wrap
        {.name = "aes192", .types = aes192, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => AES_192_CBC
        {.name = "aes192_wrap", .types = aes192_wrap, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => id_aes192_wrap
        {.name = "aes256", .types = aes256, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => AES_256_CBC
        {.name = "aes256_wrap", .types = aes256_wrap, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => id_aes256_wrap
        {.name = "ARIA_128_CBC", .types = ARIA_128_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_128_CCM", .types = ARIA_128_CCM, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_128_CFB", .types = ARIA_128_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_128_CFB1", .types = ARIA_128_CFB1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_128_CFB8", .types = ARIA_128_CFB8, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_128_CTR", .types = ARIA_128_CTR, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_128_ECB", .types = ARIA_128_ECB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_128_GCM", .types = ARIA_128_GCM, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_128_OFB", .types = ARIA_128_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_192_CBC", .types = ARIA_192_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_192_CCM", .types = ARIA_192_CCM, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_192_CFB", .types = ARIA_192_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_192_CFB1", .types = ARIA_192_CFB1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_192_CFB8", .types = ARIA_192_CFB8, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_192_CTR", .types = ARIA_192_CTR, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_192_ECB", .types = ARIA_192_ECB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_192_GCM", .types = ARIA_192_GCM, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_192_OFB", .types = ARIA_192_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_256_CBC", .types = ARIA_256_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_256_CCM", .types = ARIA_256_CCM, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_256_CFB", .types = ARIA_256_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_256_CFB1", .types = ARIA_256_CFB1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_256_CFB8", .types = ARIA_256_CFB8, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_256_CTR", .types = ARIA_256_CTR, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_256_ECB", .types = ARIA_256_ECB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_256_GCM", .types = ARIA_256_GCM, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ARIA_256_OFB", .types = ARIA_256_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "aria128", .types = aria128, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => ARIA_128_CBC
        {.name = "aria192", .types = aria192, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => ARIA_192_CBC
        {.name = "aria256", .types = aria256, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => ARIA_256_CBC
        {.name = "bf", .types = bf, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => BF_CBC
        {.name = "BF_CBC", .types = BF_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "BF_CFB", .types = BF_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "BF_ECB", .types = BF_ECB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "BF_OFB", .types = BF_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "blowfish", .types = blowfish, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => BF_CBC
        {.name = "CAMELLIA_128_CBC", .types = CAMELLIA_128_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_128_CFB", .types = CAMELLIA_128_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_128_CFB1", .types = CAMELLIA_128_CFB1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_128_CFB8", .types = CAMELLIA_128_CFB8, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_128_CTR", .types = CAMELLIA_128_CTR, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_128_ECB", .types = CAMELLIA_128_ECB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_128_OFB", .types = CAMELLIA_128_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_192_CBC", .types = CAMELLIA_192_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_192_CFB", .types = CAMELLIA_192_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_192_CFB1", .types = CAMELLIA_192_CFB1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_192_CFB8", .types = CAMELLIA_192_CFB8, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_192_CTR", .types = CAMELLIA_192_CTR, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_192_ECB", .types = CAMELLIA_192_ECB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_192_OFB", .types = CAMELLIA_192_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_256_CBC", .types = CAMELLIA_256_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_256_CFB", .types = CAMELLIA_256_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_256_CFB1", .types = CAMELLIA_256_CFB1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_256_CFB8", .types = CAMELLIA_256_CFB8, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_256_CTR", .types = CAMELLIA_256_CTR, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_256_ECB", .types = CAMELLIA_256_ECB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "CAMELLIA_256_OFB", .types = CAMELLIA_256_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "camellia128", .types = camellia128, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => CAMELLIA_128_CBC
        {.name = "camellia192", .types = camellia192, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => CAMELLIA_192_CBC
        {.name = "camellia256", .types = camellia256, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => CAMELLIA_256_CBC
        {.name = "cast", .types = cast, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => CAST5_CBC
        {.name = "cast_cbc", .types = cast_cbc, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_DISABLE},// => CAST5_CBC
        {.name = "CAST5_CBC", .types = CAST5_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_DISABLE},
        {.name = "CAST5_CFB", .types = CAST5_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_DISABLE},
        {.name = "CAST5_ECB", .types = CAST5_ECB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_DISABLE},
        {.name = "CAST5_OFB", .types = CAST5_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_DISABLE},
        {.name = "ChaCha20", .types = ChaCha20, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_DISABLE},
        {.name = "ChaCha20_Poly1305", .types = ChaCha20_Poly1305, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_DISABLE},
        {.name = "des", .types = des, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_DISABLE},// => DES_CBC
        {.name = "DES_CBC", .types = DES_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_DISABLE},
        {.name = "DES_CFB", .types = DES_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_DISABLE},
        {.name = "DES_CFB1", .types = DES_CFB1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "DES_CFB8", .types = DES_CFB8, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "DES_ECB", .types = DES_ECB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "DES_EDE", .types = DES_EDE, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "DES_EDE_CBC", .types = DES_EDE_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "DES_EDE_CFB", .types = DES_EDE_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "des_ede_ecb", .types = des_ede_ecb, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => DES_EDE
        {.name = "DES_EDE_OFB", .types = DES_EDE_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "DES_EDE3", .types = DES_EDE3, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "DES_EDE3_CBC", .types = DES_EDE3_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "DES_EDE3_CFB", .types = DES_EDE3_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "DES_EDE3_CFB1", .types = DES_EDE3_CFB1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "DES_EDE3_CFB8", .types = DES_EDE3_CFB8, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "des_ede3_ecb", .types = des_ede3_ecb, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => DES_EDE3
        {.name = "DES_EDE3_OFB", .types = DES_EDE3_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "DES_OFB", .types = DES_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "des3", .types = des3, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => DES_EDE3_CBC
        {.name = "des3_wrap", .types = des3_wrap, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => id_smime_alg_CMS3DESwrap
        {.name = "desx", .types = desx, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => DESX_CBC
        {.name = "DESX_CBC", .types = DESX_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "id_aes128_wrap", .types = id_aes128_wrap, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "id_aes128_wrap_pad", .types = id_aes128_wrap_pad, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "id_aes192_wrap", .types = id_aes192_wrap, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "id_aes192_wrap_pad", .types = id_aes192_wrap_pad, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "id_aes256_wrap", .types = id_aes256_wrap, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "id_aes256_wrap_pad", .types = id_aes256_wrap_pad, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "id_smime_alg_CMS3DESwrap", .types = id_smime_alg_CMS3DESwrap, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "rc2", .types = rc2, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => RC2_CBC
        {.name = "rc2_128", .types = rc2_128, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => RC2_CBC
        {.name = "rc2_40", .types = rc2_40, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => RC2_40_CBC
        {.name = "RC2_40_CBC", .types = RC2_40_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "rc2_64", .types = rc2_64, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => RC2_64_CBC
        {.name = "RC2_64_CBC", .types = RC2_64_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "RC2_CBC", .types = RC2_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "RC2_CFB", .types = RC2_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "RC2_ECB", .types = RC2_ECB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "RC2_OFB", .types = RC2_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "RC4", .types = RC4, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "RC4_40", .types = RC4_40, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "RC4_HMAC_MD5", .types = RC4_HMAC_MD5, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "seed", .types = seed, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SEED_CBC
        {.name = "SEED_CBC", .types = SEED_CBC, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "SEED_CFB", .types = SEED_CFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "SEED_ECB", .types = SEED_ECB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "SEED_OFB", .types = SEED_OFB, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "sm4", .types = sm4, .destructor = NULL, .handler = {do_sm4_ecb_crypto, do_sm4_ecb_decrypto, NULL,NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SM4_CBC
        {.name = "SM4_CBC", .types = SM4_CBC, .destructor = NULL, .handler = {do_sm4_cbc_crypto, do_sm4_cbc_decrypto, NULL,NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "SM4_CFB", .types = SM4_CFB, .destructor = NULL, .handler = {do_sm4_cfb_crypto, do_sm4_cfb_decrypto, NULL,NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "SM4_CTR", .types = SM4_CTR, .destructor = NULL, .handler = {do_sm4_ctr_crypto, do_sm4_ctr_decrypto, NULL,NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "SM4_ECB", .types = SM4_ECB, .destructor = NULL, .handler = {do_sm4_ecb_crypto, do_sm4_ecb_decrypto, NULL,NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "SM4_OFB", .types = SM4_OFB, .destructor = NULL, .handler =  {do_sm4_ofb_crypto, do_sm4_ofb_decrypto, NULL,NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},

        {.name = "RSA_MD4", .types = RSA_MD4, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => MD4
        {.name = "RSA_MD5", .types = RSA_MD5, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => MD5
        {.name = "RSA_RIPEMD160", .types = RSA_RIPEMD160, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => RIPEMD160
        {.name = "RSA_SHA1", .types = RSA_SHA1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA1
        {.name = "RSA_SHA1_2", .types = RSA_SHA1_2, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => RSA_SHA1
        {.name = "RSA_SHA224", .types = RSA_SHA224, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA224
        {.name = "RSA_SHA256", .types = RSA_SHA256, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA256
        {.name = "RSA_SHA3_224", .types = RSA_SHA3_224, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA3_224
        {.name = "RSA_SHA3_256", .types = RSA_SHA3_256, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA3_256
        {.name = "RSA_SHA3_384", .types = RSA_SHA3_384, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA3_384
        {.name = "RSA_SHA3_512", .types = RSA_SHA3_512, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA3_512
        {.name = "RSA_SHA384", .types = RSA_SHA384, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA384
        {.name = "RSA_SHA512", .types = RSA_SHA512, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA512
        {.name = "RSA_SHA512_224", .types = RSA_SHA512_224, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA512_224
        {.name = "RSA_SHA512_256", .types = RSA_SHA512_256, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA512_256
        {.name = "RSA_SM3", .types = RSA_SM3, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SM3
        {.name = "BLAKE2b512", .types = BLAKE2b512, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "BLAKE2s256", .types = BLAKE2s256, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "id_rsassa_pkcs1_v1_5_with_sha3_224", .types = id_rsassa_pkcs1_v1_5_with_sha3_224, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA3_224
        {.name = "id_rsassa_pkcs1_v1_5_with_sha3_256", .types = id_rsassa_pkcs1_v1_5_with_sha3_256, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA3_256
        {.name = "id_rsassa_pkcs1_v1_5_with_sha3_384", .types = id_rsassa_pkcs1_v1_5_with_sha3_384, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA3_384
        {.name = "id_rsassa_pkcs1_v1_5_with_sha3_512", .types = id_rsassa_pkcs1_v1_5_with_sha3_512, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA3_512
        {.name = "MD4", .types = MD4, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "md4WithRSAEncryption", .types = md4WithRSAEncryption, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => MD4
        {.name = "MD5", .types = MD5, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "MD5_SHA1", .types = MD5_SHA1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "md5WithRSAEncryption", .types = md5WithRSAEncryption, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => MD5
        {.name = "ripemd", .types = ripemd, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => RIPEMD160
        {.name = "RIPEMD160", .types = RIPEMD160, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ripemd160WithRSA", .types = ripemd160WithRSA, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => RIPEMD160
        {.name = "rmd160", .types = rmd160, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => RIPEMD160
        {.name = "SHA1", .types = SHA1, .destructor = NULL, .handler = {do_sha1_hash,NULL,NULL,NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "sha1WithRSAEncryption", .types = sha1WithRSAEncryption, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => SHA1
        {.name = "SHA224", .types = SHA224, .destructor = NULL, .handler = {do_sha224_hash,NULL,NULL,NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "sha224WithRSAEncryption", .types = sha224WithRSAEncryption, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => SHA224
        {.name = "SHA256", .types = SHA256, .destructor = NULL, .handler = {do_sha256_hash,NULL,NULL,NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "sha256WithRSAEncryption", .types = sha256WithRSAEncryption, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},// => SHA256
        {.name = "SHA3_224", .types = SHA3_224, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "SHA3_256", .types = SHA3_256, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "SHA3_384", .types = SHA3_384, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "SHA3_512", .types = SHA3_512, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "SHA384", .types = SHA384, .destructor = NULL, .handler = {do_sha384_hash,NULL,NULL,NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "sha384WithRSAEncryption", .types = sha384WithRSAEncryption, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE}, // => SHA384
        {.name = "SHA512", .types = SHA512, .destructor = NULL, .handler = {do_sha512_hash,NULL,NULL,NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "SHA512_224", .types = SHA512_224, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "sha512_224WithRSAEncryption", .types = sha512_224WithRSAEncryption, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA512_224
        {.name = "SHA512_256", .types = SHA512_256, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "sha512_256WithRSAEncryption", .types = sha512_256WithRSAEncryption, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA512_256
        {.name = "sha512WithRSAEncryption", .types = sha512WithRSAEncryption, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA512
        {.name = "SHAKE128", .types = SHAKE128, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "SHAKE256", .types = SHAKE256, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "SM3", .types = SM3, .destructor = NULL, .handler = {do_sm3_hash,NULL,NULL,NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "sm3WithRSAEncryption", .types = sm3WithRSAEncryption, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SM3
        {.name = "ssl3_md5", .types = ssl3_md5, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => MD5
        {.name = "ssl3_sha1", .types = ssl3_sha1, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},//  => SHA1
        {.name = "whirlpool", .types = whirlpool, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},

        {.name = "rsaEncryption", .types = rsaEncryption, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "dhKeyAgreement", .types = dhKeyAgreement, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "dsaEncryption", .types = dsaEncryption, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "id_ecPublicKey", .types = id_ecPublicKey, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "hmac", .types = hmac, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "cmac", .types = cmac, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "rsassaPss", .types = rsassaPss, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "X9_42_DH", .types = X9_42_DH, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "scrypt", .types = scrypt, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "tls1_prf", .types = tls1_prf, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "X25519", .types = X25519, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "X448", .types = X448, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "hkdf", .types = hkdf, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "poly1305", .types = poly1305, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "siphash", .types = siphash, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ED25519", .types = ED25519, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "ED448", .types = ED448, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "sm2", .types = sm2, .destructor = NULL, .handler = {do_sm2_encrypt, do_sm2_decrypt,do_sm2_sign,do_sm2_verify}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "sm9", .types = sm9, .destructor = NULL, .handler = {do_sm9_crypto, do_sm9_decrypto, NULL,NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "f0_5g", .types = f0_5g, .destructor = NULL, .handler = NULL, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_DISABLE},
        {.name = "f1_5g", .types = f1_5g, .destructor = NULL, .handler = {do_5g_f1, NULL, NULL, NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "f1x_5g", .types = f1x_5g, .destructor = NULL, .handler = {do_5g_f1x, NULL, NULL, NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "f2_5g", .types = f2_5g, .destructor = NULL, .handler = {do_5g_f2, NULL, NULL, NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "f3_5g", .types = f3_5g, .destructor = NULL, .handler = {do_5g_f3, NULL, NULL, NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "f4_5g", .types = f4_5g, .destructor = NULL, .handler = {do_5g_f4, NULL, NULL, NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "f5_5g", .types = f5_5g, .destructor = NULL, .handler = {do_5g_f5, NULL, NULL, NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "f5x_5g", .types = f5x_5g, .destructor = NULL, .handler = {do_5g_f5x, NULL, NULL, NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
        {.name = "f2345_5g", .types = f2345_5g, .destructor = NULL, .handler = {do_5g_f2345, NULL, NULL, NULL}, .status = CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE},
};
/**
 * @author      gorio
 * @name        g_cc_core
 * @type        CeSSLCryptoCore
 * @scope       全生命周期
 * @note        crypto库关键的核心控件，在运行期为只读，所有的handler应均从此处派生而出
 */
CeSSLCryptoCore g_cc_core = {
        .version = CE_SSL_VERSION_CORE_CODE,
        .extraHandlers = NULL,
        .handlers = g_ch_array,
        .configPath = "ce_ssl_crypto_config.json",
        .maxOfHandlers = sizeof(g_ch_array) / sizeof (g_ch_array[0]),
        .initStatus = CE_SSL_CRYPTO_CORE_STATUS_UNINITIALIZED,
};
/**
 * @author      gorio
 * @name        ce_ssl_crypto_core_init
 * @description crypto库初始化函数
 * @calls
 * @input       /
 * @output      /
 * @return      [ce_ssl_errno_t] CE_SSL_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 *              @see int main(void)
 */
ce_ssl_errno_t ce_ssl_crypto_core_init() {
    //1.load config.json

    //2.读取被禁用的方法
    //3.修改.handlers里面对应方法的状态
    //4.返回状态
    g_cc_core.initStatus = CE_SSL_CRYPTO_CORE_STATUS_INITIALIZED;
    return CE_SSL_SUCCESS;
}

/**
 * @author      gorio
 * @name        ce_ssl_crypto_core_init_by_config_file
 * @description crypto库通过配置文件初始化函数
 * @calls
 * @input       [char *] filePath 文件路径
 * @output      /
 * @return      [ce_ssl_errno_t] CE_SSL_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_crypto_core_init_by_config_file(char *filePath){
    return CE_SSL_SUCCESS;
}
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
CeSSLCryptoHandlerPointer ce_ssl_crypto_get_handler(CeSSLCryptoTypes cryptoTypes) {
    //@TODO check g_cc_core.initStatus
    if (cryptoTypes < 0 || cryptoTypes >= g_cc_core.maxOfHandlers) {
        ce_ssl_set_pthread_errno(CE_SSL_OUT_OF_ARRAY);
        return NULL;
    }
    return g_cc_core.handlers[cryptoTypes].status == CE_SSL_CRYPTO_TYPE_HANDLER_STATUS_ENABLE
           ? &(g_cc_core.handlers[cryptoTypes]) : NULL;
}



/**
 * @author      gorio
 * @note        此函数无法在运行时进行禁用，必须在调用第一个handler之前调用
 * @name        ce_ssl_crypto_core_disable_handler
 * @description 禁用一种算法
 * @calls
 * @input       [CeSSLCryptoTypes] cryptoTypes  算法编号
 * @output      /
 * @return      [ce_ssl_errno_t] CE_SSL_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_crypto_core_disable_handler(CeSSLCryptoTypes cryptoTypes){
    return CE_SSL_SUCCESS;
}


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
 * @return      [ce_ssl_errno_t] CE_SSL_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_crypto_add_handler(CeSSLCryptoTypes cryptoTypes,
                                  CeSSLCryptoHandlerPointerConstructor constructor,
                                  CeSSLCryptoHandlerPointerDestructor destructor,
                                  CeSSLCryptoHandlerHandlerMethod method,
                                  bool saveForever){
    return CE_SSL_SUCCESS;
}

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
 * @return      [ce_ssl_errno_t] CE_SSL_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_crypto_add_static_handler(CeSSLCryptoTypes cryptoTypes,
                                         char * libPath,
                                         char * methodName,
                                         bool saveForever){
    return CE_SSL_SUCCESS;
}

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
 * @return      [ce_ssl_errno_t] CE_SSL_SUCCESS for success, other values for fail
 * @status      @TODO
 * @calledBy:
 */
ce_ssl_errno_t ce_ssl_crypto_do(CeSSLCryptoHandlerPointer handler,
                         CeSSLKeyHandlerPointer key,
                         CeSSLContextHandlerPointer context,
                         CeSSLCryptoResultHandlerPointer *result){
    if (handler == NULL || context == NULL){
        return -1;
    }
    if (handler->handler[0] == NULL){
        return -2;
    }
    switch (context->type) {
        case Crypto:
        case Hash:
            return handler->handler[0](handler, key, context, result);
            break;
        case Decrypt:
            return handler->handler[1](handler, key, context, result);
            break;
        case Sign:
            return handler->handler[2](handler, key, context, result);
            break;
        case Verify:
            return handler->handler[3](handler, key, context, result);
            break;
        default:
            return -3;
    }
    return -4;
}