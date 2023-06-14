//
// Created by 83672 on 2023/6/14.
//

#ifndef CESSL_CE_SSL_DEFINES_H
#define CESSL_CE_SSL_DEFINES_H

#ifdef __GNUC__
#define CE_SSL_THREAD __thread
#else
// @FIXME
#define CE_SSL_THREAD
#endif
/***
 * @author: gorio
 * @name: enum CeSSLCryptoTypes
 * @alias:
 *      @see CeSSLCryptoTypes
 * @description: 算法标识定义
 */
typedef enum CeSSLCryptoTypes{
    AES_128_CBC                         = 0,
    AES_128_CBC_HMAC_SHA1               = 1,
    AES_128_CBC_HMAC_SHA256             = 2,
    id_aes128_CCM                       = 3,
    AES_128_CFB                         = 4,
    AES_128_CFB1                        = 5,
    AES_128_CFB8                        = 6,
    AES_128_CTR                         = 7,
    AES_128_ECB                         = 8,
    id_aes128_GCM                       = 9,
    AES_128_OCB                         = 10,
    AES_128_OFB                         = 11,
    AES_128_XTS                         = 12,
    AES_192_CBC                         = 13,
    id_aes192_CCM                       = 14,
    AES_192_CFB                         = 15,
    AES_192_CFB1                        = 16,
    AES_192_CFB8                        = 17,
    AES_192_CTR                         = 18,
    AES_192_ECB                         = 19,
    id_aes192_GCM                       = 20,
    AES_192_OCB                         = 21,
    AES_192_OFB                         = 22,
    AES_256_CBC                         = 23,
    AES_256_CBC_HMAC_SHA1               = 24,
    AES_256_CBC_HMAC_SHA256             = 25,
    id_aes256_CCM                       = 26,
    AES_256_CFB                         = 27,
    AES_256_CFB1                        = 28,
    AES_256_CFB8                        = 29,
    AES_256_CTR                         = 30,
    AES_256_ECB                         = 31,
    id_aes256_GCM                       = 32,
    AES_256_OCB                         = 33,
    AES_256_OFB                         = 34,
    AES_256_XTS                         = 35,
    aes128                              = 36,// => AES_128_CBC,
    aes128_wrap                         = 37,// => id_aes128_wrap = 1,
    aes192                              = 38,// => AES_192_CBC = 1,
    aes192_wrap                         = 39,// => id_aes192_wrap = 1,
    aes256                              = 40,// => AES_256_CBC = 1,
    aes256_wrap                         = 41,// => id_aes256_wrap = 1,
    ARIA_128_CBC                        = 42,
    ARIA_128_CCM                        = 43,
    ARIA_128_CFB                        = 44,
    ARIA_128_CFB1                       = 45,
    ARIA_128_CFB8                       = 46,
    ARIA_128_CTR                        = 47,
    ARIA_128_ECB                        = 48,
    ARIA_128_GCM                        = 49,
    ARIA_128_OFB                        = 50,
    ARIA_192_CBC                        = 51,
    ARIA_192_CCM                        = 52,
    ARIA_192_CFB                        = 53,
    ARIA_192_CFB1                       = 54,
    ARIA_192_CFB8                       = 55,
    ARIA_192_CTR                        = 56,
    ARIA_192_ECB                        = 57,
    ARIA_192_GCM                        = 58,
    ARIA_192_OFB                        = 59,
    ARIA_256_CBC                        = 60,
    ARIA_256_CCM                        = 61,
    ARIA_256_CFB                        = 62,
    ARIA_256_CFB1                       = 63,
    ARIA_256_CFB8                       = 64,
    ARIA_256_CTR                        = 65,
    ARIA_256_ECB                        = 66,
    ARIA_256_GCM                        = 67,
    ARIA_256_OFB                        = 68,
    aria128                             = 69,// => ARIA_128_CBC = 1,
    aria192                             = 70,// => ARIA_192_CBC = 1,
    aria256                             = 71,// => ARIA_256_CBC = 1,
    bf                                  = 72,// => BF_CBC = 1,
    BF_CBC                              = 73,
    BF_CFB                              = 74,
    BF_ECB                              = 75,
    BF_OFB                              = 76,
    blowfish                            = 77,// => BF_CBC = 1,
    CAMELLIA_128_CBC                    = 78,
    CAMELLIA_128_CFB                    = 79,
    CAMELLIA_128_CFB1                   = 80,
    CAMELLIA_128_CFB8                   = 81,
    CAMELLIA_128_CTR                    = 82,
    CAMELLIA_128_ECB                    = 83,
    CAMELLIA_128_OFB                    = 84,
    CAMELLIA_192_CBC                    = 85,
    CAMELLIA_192_CFB                    = 86,
    CAMELLIA_192_CFB1                   = 87,
    CAMELLIA_192_CFB8                   = 88,
    CAMELLIA_192_CTR                    = 89,
    CAMELLIA_192_ECB                    = 90,
    CAMELLIA_192_OFB                    = 91,
    CAMELLIA_256_CBC                    = 92,
    CAMELLIA_256_CFB                    = 93,
    CAMELLIA_256_CFB1                   = 94,
    CAMELLIA_256_CFB8                   = 95,
    CAMELLIA_256_CTR                    = 96,
    CAMELLIA_256_ECB                    = 97,
    CAMELLIA_256_OFB                    = 98,
    camellia128                         = 99,// => CAMELLIA_128_CBC = 1,
    camellia192                         = 100,// => CAMELLIA_192_CBC = 1,
    camellia256                         = 101,// => CAMELLIA_256_CBC = 1,
    cast                                = 102,// => CAST5_CBC = 1,
    cast_cbc                            = 103,// => CAST5_CBC = 1,
    CAST5_CBC                           = 104,
    CAST5_CFB                           = 105,
    CAST5_ECB                           = 106,
    CAST5_OFB                           = 107,
    ChaCha20                            = 108,
    ChaCha20_Poly1305                   = 109,
    des                                 = 110,// => DES_CBC = 1,
    DES_CBC                             = 111,
    DES_CFB                             = 112,
    DES_CFB1                            = 113,
    DES_CFB8                            = 114,
    DES_ECB                             = 115,
    DES_EDE                             = 116,
    DES_EDE_CBC                         = 117,
    DES_EDE_CFB                         = 118,
    des_ede_ecb                         = 119,// => DES_EDE = 1,
    DES_EDE_OFB                         = 120,
    DES_EDE3                            = 121,
    DES_EDE3_CBC                        = 122,
    DES_EDE3_CFB                        = 123,
    DES_EDE3_CFB1                       = 124,
    DES_EDE3_CFB8                       = 125,
    des_ede3_ecb                        = 126,// => DES_EDE3 = 1,
    DES_EDE3_OFB                        = 127,
    DES_OFB                             = 128,
    des3                                = 129,// => DES_EDE3_CBC = 1,
    des3_wrap                           = 130,// => id_smime_alg_CMS3DESwrap = 1,
    desx                                = 131,// => DESX_CBC = 1,
    DESX_CBC                            = 132,
    id_aes128_wrap                      = 133,
    id_aes128_wrap_pad                  = 134,
    id_aes192_wrap                      = 135,
    id_aes192_wrap_pad                  = 136,
    id_aes256_wrap                      = 137,
    id_aes256_wrap_pad                  = 138,
    id_smime_alg_CMS3DESwrap            = 139,
    rc2                                 = 140,//  => RC2_CBC = 1,
    rc2_128                             = 141,//  => RC2_CBC = 1,
    rc2_40                              = 142,//  => RC2_40_CBC = 1,
    RC2_40_CBC                          = 143,
    rc2_64                              = 144,//  => RC2_64_CBC = 1,
    RC2_64_CBC                          = 145,
    RC2_CBC                             = 146,
    RC2_CFB                             = 147,
    RC2_ECB                             = 148,
    RC2_OFB                             = 149,
    RC4                                 = 150,
    RC4_40                              = 151,
    RC4_HMAC_MD5                        = 152,
    seed                                = 153,//  => SEED_CBC = 1,
    SEED_CBC                            = 154,
    SEED_CFB                            = 155,
    SEED_ECB                            = 156,
    SEED_OFB                            = 157,
    sm4                                 = 158,//  => SM4_CBC = 1,
    SM4_CBC                             = 159,
    SM4_CFB                             = 160,
    SM4_CTR                             = 161,
    SM4_ECB                             = 162,
    SM4_OFB                             = 163,
    /*********digest algorithms*************/
    RSA_MD4                             = 164,//  => MD4 = 1,
    RSA_MD5                             = 165,//  => MD5 = 1,
    RSA_RIPEMD160                       = 166,//  => RIPEMD160 = 1,
    RSA_SHA1                            = 167,//  => SHA1 = 1,
    RSA_SHA1_2                          = 168,//  => RSA_SHA1 = 1,
    RSA_SHA224                          = 169,//  => SHA224 = 1,
    RSA_SHA256                          = 170,// => SHA256 = 1,
    RSA_SHA3_224                        = 171,//  => SHA3_224 = 1,
    RSA_SHA3_256                        = 172,//  => SHA3_256 = 1,
    RSA_SHA3_384                        = 173,//  => SHA3_384 = 1,
    RSA_SHA3_512                        = 174,//  => SHA3_512 = 1,
    RSA_SHA384                          = 175,//  => SHA384 = 1,
    RSA_SHA512                          = 176,//  => SHA512 = 1,
    RSA_SHA512_224                      = 177,//  => SHA512_224 = 1,
    RSA_SHA512_256                      = 178,//  => SHA512_256 = 1,
    RSA_SM3                             = 179,//  => SM3 = 1,
    BLAKE2b512                          = 180,
    BLAKE2s256                          = 181,
    id_rsassa_pkcs1_v1_5_with_sha3_224  = 182,//  => SHA3_224 = 1,
    id_rsassa_pkcs1_v1_5_with_sha3_256  = 183,//  => SHA3_256 = 1,
    id_rsassa_pkcs1_v1_5_with_sha3_384  = 184,//  => SHA3_384 = 1,
    id_rsassa_pkcs1_v1_5_with_sha3_512  = 185,//  => SHA3_512 = 1,
    MD4                                 = 186,
    md4WithRSAEncryption                = 187,//  => MD4 = 1,
    MD5                                 = 188,
    MD5_SHA1                            = 189,
    md5WithRSAEncryption                = 190,//  => MD5 = 1,
    ripemd                              = 191,//  => RIPEMD160 = 1,
    RIPEMD160                           = 192,
    ripemd160WithRSA                    = 193,//  => RIPEMD160 = 1,
    rmd160                              = 194,//  => RIPEMD160 = 1,
    SHA1                                = 195,
    sha1WithRSAEncryption               = 196,// => SHA1 = 1,
    SHA224                              = 197,
    sha224WithRSAEncryption             = 198,//  => SHA224 = 1,
    SHA256                              = 199,
    sha256WithRSAEncryption             = 200,//  => SHA256 = 1,
    SHA3_224                            = 201,
    SHA3_256                            = 202,
    SHA3_384                            = 203,
    SHA3_512                            = 204,
    SHA384                              = 205,
    sha384WithRSAEncryption             = 206,// => SHA384 = 1,
    SHA512                              = 207,
    SHA512_224                          = 208,
    sha512_224WithRSAEncryption         = 209,//  => SHA512_224 = 1,
    SHA512_256                          = 210,
    sha512_256WithRSAEncryption         = 211,//  => SHA512_256 = 1,
    sha512WithRSAEncryption             = 212,//  => SHA512 = 1,
    SHAKE128                            = 213,
    SHAKE256                            = 214,
    SM3                                 = 215,
    sm3WithRSAEncryption                = 216,//  => SM3 = 1,
    ssl3_md5                            = 217,//  => MD5 = 1,
    ssl3_sha1                           = 218,//  => SHA1 = 1,
    whirlpool                           = 219,
    /*********public ket algorithms*************/
    rsaEncryption                       = 220,
    dhKeyAgreement                      = 221,
    dsaEncryption                       = 222,
    id_ecPublicKey                      = 223,
    hmac                                = 224,
    cmac                                = 225,
    rsassaPss                           = 226,
    X9_42_DH                            = 227,
    scrypt                              = 228,
    tls1_prf                            = 229,
    X25519                              = 230,
    X448                                = 231,
    hkdf                                = 232,
    poly1305                            = 233,
    siphash                             = 234,
    ED25519                             = 235,
    ED448                               = 236,
    sm2                                 = 237,
    sm9                                 = 238
} CeSSLCryptoTypes;
/***
 * @author: gorio
 * @name: enum CeSSLCryptoOutputType
 * @alias:
 *      @see CeSSLCryptoOutputType
 * @description: 算法输出标识
 */
typedef enum CeSSLCryptoOutputType{
    raw = 0,
    base16,
    base32,
    base64,
    base128,
    binary,
    hexadecimal
}CeSSLCryptoOutputType;
/***
 * @author: gorio
 * @name: enum CeSSLContextType
 * @alias:
 *      @see CeSSLContextType
 * @description: 算法上下文类型
 */
typedef enum CeSSLContextType{
    Crypto = 0,
    Decrypt,
    Sign,
    Verify,
    Hash
}CeSSLContextType;
/***
 * @author: gorio
 * @name: enum CeSSLCryptoClassify
 * @alias:
 *      @see CeSSLCryptoClassify
 * @description: 算法分类
 */
typedef enum CeSSLCryptoClassify{
    SymmetricEncryption = 0,
    AsymmetricEncryption,
    HashFunction,
    KeyGeneration,
    FunctionAlias

}CeSSLCryptoClassify;
/***
 * @author: gorio
 * @name: enum CeSSLKeyType
 * @alias:
 *      @see CeSSLKeyType
 * @description: 密钥分类
 */
typedef enum CeSSLKeyType{
    SymmetricKey = 0, // 对称
    PublicKey,
    PrivateKey,
    PublicKeyCertificationPath,
    PrivateKeyCertificatePath,
    CertificatePath // 比如pfx证书
}CeSSLKeyType;
/***
 * @author: gorio
 * @name: enum CeSSLResultType
 * @alias:
 *      @see CeSSLResultType
 * @description: 结果类型
 */
typedef enum CeSSLResultType{
    StringResult = 0,
    IntResult
}CeSSLResultType;
/***
 * @author: gorio
 * @name: enum CeSSLCryptoMemoryType
 * @alias:
 *      @see CeSSLCryptoMemoryType
 * @description: 内存类型
 */
typedef enum CeSSLCryptoMemoryType{
    StackMemory = 0,
    HeapMemory,
    OuterSpace
}CeSSLCryptoMemoryType;
/***
 * @author nana
 * @name enum CeSSLKeyPairType
 * @description: 公私钥对类型
 */
typedef enum CeSSLKeyPairType{
    RSA = 0,
    SM2,
}CeSSLKeyPairType;
/***
* @author: 李晟
* @name: struct CeSSLKeyHandler
* @alias:
* @see CeSSLKeyHandler
* @see CeSSLKeyHandlerPointer
* @param version 当前的版本号 @see CE_SSL_VERSION_KEY_HANDLER_* 宏
* @param key 存放密钥的地址指针，并不一定是密钥本身，具体使用方式需要 @see CeSSLKeyType
* @param keyLen key的长度
* @param type key类型的定义
* @param memoryType 可以预估的内存类型，默认get的handler为@see StackMemory, 否则应该为@see HeapMemory
* @param iv 部分函数可以自定义IV
* @param ivLen 自定义IV的长度
*/
struct CeSSLKeyHandler {
    int version;
    unsigned char * key;
    char * iv;
    int ivLen;
    int keyLen;
    CeSSLKeyType type;
    CeSSLCryptoMemoryType memoryType;
};


#define TUAK_KEY_16   16
#define TUAK_KEY_32   32
#define TUAK_RES_4     4
#define TUAK_RES_8     8
#define TUAK_RES_16   16
#define TUAK_RES_32   32
#define TUAK_CK_16    16
#define TUAK_CK_32    32
#define TUAK_IK_16    16
#define TUAK_IK_32    32
#define TUAK_MAC_8     8
#define TUAK_MAC_16   16
#define TUAK_MAC_32   32

#define TUAK_TOP_SZ   32
#define TUAK_TOPC_SZ  32
#define TUAK_RAND_SZ  16
#define TUAK_AMF_SZ    2
#define TUAK_SQN_SZ    6
#define TUAK_AK_SZ     6

/***
 * @author: 李泽健
 * @name: enum CeSSLTuakFnType
 * @alias:
 *      @see CeSSLTuakFnType
 * @description: 5GFn系列函数枚举类型
 */
typedef enum CeSSLTuakFnType{
    TuakRes = 0,
    TuakCk = 1,
    TuakIk = 2,
    TuakAk = 3,
    TuakMac,
    TuakKey
}CeSSLTuakFnType;

typedef enum CeSSLTuakFnHash{
    TuakHashByKeccak,
    TuakHashBySm3
}CeSSLTuakFnHash;


#endif //CESSL_CE_SSL_DEFINES_H
