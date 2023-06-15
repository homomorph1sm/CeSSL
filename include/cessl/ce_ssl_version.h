#ifndef CESSL_CE_SSL_VERSION_H
#define CESSL_CE_SSL_VERSION_H
/**
 * @author: gorio
 * @name CE_SSL_VERSION_STEP_DEV
 * @value 0
 * @usage 标明当前版本为开发版本
 */
#define CE_SSL_VERSION_STEP_DEV          0
/**
 * @author: gorio
 * @name CE_SSL_VERSION_STEP_BETA
 * @value 1
 * @usage 标明当前版本为测试版本
 */
#define CE_SSL_VERSION_STEP_BETA         1
/**
 * @author: gorio
 * @name CE_SSL_VERSION_STEP_RELEASE
 * @value 2
 * @usage 标明当前版本为发布版本
 */
#define CE_SSL_VERSION_STEP_RELEASE      2

/**
 * git push=git merge
 *   |      |
 *  dev<==>beta==>release==>更新==>dev
 *          |       |
 *      小版本号+1  大版本号+1
 *          |
 *        测试通过==>
 *          |
 *     <==测试失败
 */


/**
 * @author gorio
 * @name CE_SSL_VERSION_CODE
 * @param versionTotal      当前大版本号
 * @param versionSub        小版本号，从1开始累加，大版本号迭代后回退为0
 * @param versionStep       阶段号，表示当前版本是处于何种阶段 @see CE_SSL_VERSION_STEP_* 宏
 */
#define CE_SSL_VERSION_CODE(versionTotal, versionSub, versionStep)  (((versionTotal) << 6) + ((versionSub) << 4) + (versionStep))

/**
 * @author gorio
 * @name CE_SSL_VERSION_STRING
 * @param versionTotal      当前大版本号
 * @param versionSub        小版本号，从1开始累加，大版本号迭代后回退为0
 * @param versionStep       阶段号，表示当前版本是处于何种阶段 @see CE_SSL_VERSION_STEP_* 宏
 */
#define CE_SSL_VERSION_STRING(versionTotal, versionSub, versionStep) (#versionTotal "." #versionSub "." #versionStep)

#define CE_SSL_VERSION_CORE_CODE CE_SSL_VERSION_CODE( 0, 7, CE_SSL_VERSION_STEP_RELEASE)
#define CE_SSL_VERSION_CORE_STRING CE_SSL_VERSION_STRING( 0, 7, CE_SSL_VERSION_STEP_RELEASE)

#define CE_SSL_VERSION_CPT_HANDLER_CODE CE_SSL_VERSION_CODE( 0, 7, CE_SSL_VERSION_STEP_RELEASE)
#define CE_SSL_VERSION_CPT_HANDLER_STRING CE_SSL_VERSION_STRING( 0, 7, CE_SSL_VERSION_STEP_RELEASE)

#define CE_SSL_VERSION_KEY_HANDLER_CODE CE_SSL_VERSION_CODE( 0, 7, CE_SSL_VERSION_STEP_RELEASE)
#define CE_SSL_VERSION_KEY_HANDLER_STRING CE_SSL_VERSION_STRING( 0, 7, CE_SSL_VERSION_STEP_RELEASE)

#define CE_SSL_VERSION_RES_HANDLER_CODE CE_SSL_VERSION_CODE( 0, 7, CE_SSL_VERSION_STEP_RELEASE)
#define CE_SSL_VERSION_RES_HANDLER_STRING CE_SSL_VERSION_STRING( 0, 7, CE_SSL_VERSION_STEP_RELEASE)

#define CE_SSL_VERSION_CTX_HANDLER_CODE CE_SSL_VERSION_CODE( 0, 7, CE_SSL_VERSION_STEP_RELEASE)
#define CE_SSL_VERSION_CTX_HANDLER_STRING CE_SSL_VERSION_STRING( 0, 7, CE_SSL_VERSION_STEP_RELEASE)



#endif //CESSL_CE_SSL_VERSION_H
