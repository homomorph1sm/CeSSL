#include "ce_ssl_output.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * @author      gorio,ev
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
size_t ce_ssl_hex_print(char * msg, char * str, size_t strLen){
    return ce_ssl_hex_file_print(stdout, msg, str, strLen);

}
/**
 * @author      gorio,ev
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
size_t ce_ssl_hex_fprint(int fd ,char * msg, char * str, size_t strLen){
    size_t i;
    size_t msgLen = strlen(msg);
    size_t outputLength = 0;

    // Write the message to fd
    write(fd, msg, msgLen);
    outputLength += msgLen;

    // Write the hex representation of str to fd
    for (i = 0; i < strLen; ++i) {
        char hex[3];
        snprintf(hex, sizeof(hex), "%02x", (unsigned char)str[i]);
        write(fd, hex, 2);
        outputLength += 2;
    }

    // Write a newline character to fd
    write(fd, "\n", 1);
    outputLength += 1;

    return outputLength;
}
/**
 * @author      gorio,ev
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
size_t ce_ssl_hex_file_print(FILE * file ,char * msg, char * str, size_t strLen){
    size_t i;
    size_t outputLength = 0;

    // Print the message to file
    fprintf(file, "%s", msg);
    outputLength += strlen(msg);

    // Print the hex representation of str to file
    for (i = 0; i < strLen; ++i) {
        fprintf(file, "%02x", (unsigned char)str[i]);
        outputLength += 2; // Each hex character is 2 characters long
    }

    // Print a newline character to file
    fprintf(file, "\n");
    outputLength += 1;

    return outputLength;
}