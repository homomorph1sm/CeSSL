#ifndef CESSL_CE_SSL_OUTPUT_H
#define CESSL_CE_SSL_OUTPUT_H
#include <stdio.h>
/**
 * @author      gorio
 * @note        将一个缓冲区以十六进制输出
 * @name        ce_ssl_hex_print
 * @description 将一个缓冲区以十六进制输出
 * @calls
 * @input
 *              [char *] msg 消息
 *              [char *] str 字符串
 *              [size_t] strLen 字符串长度
 * @output
 * @return      [size_t] 输出的长度
 * @status      @TODO
 * @calledBy:
 */
size_t ce_ssl_hex_print(char * msg, char * str, size_t strLen);
/**
 * @author      gorio
 * @note        将一个缓冲区向fd写入十六进制
 * @name        ce_ssl_hex_fprint
 * @description 将一个缓冲区向fd写入十六进制
 * @calls
 * @input
 *              [int] fd 文件描述符
 *              [char *] msg 消息
 *              [char *] str 字符串
 *              [size_t] strLen 字符串长度
 * @output
 * @return      [size_t] 输出的长度
 * @status      @TODO
 * @calledBy:
 */
size_t ce_ssl_hex_fprint(int fd ,char * msg, char * str, size_t strLen);
/**
 * @author      gorio
 * @note        将一个缓冲区向file以十六进制输出
 * @name        ce_ssl_hex_file_print
 * @description 将一个缓冲区向file以十六进制输出
 * @calls
 * @input
 *              [FILE *] file 文件
 *              [char *] msg 消息
 *              [char *] str 字符串
 *              [size_t] strLen 字符串长度
 * @output
 * @return      [size_t] 输出的长度
 * @status      @TODO
 * @calledBy:
 */
size_t ce_ssl_hex_file_print(FILE * file ,char * msg, char * str, size_t strLen);





#endif //CESSL_CE_SSL_OUTPUT_H
