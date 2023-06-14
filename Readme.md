# CeSSL密码算法库
## 一、密码库组成
CeSSL主要由以下几部分组成：

| 名称  | 是否完成| 施工人员 | 备注 |
|---|---|---|---|
| 摘要算法 | 正在施工 | - | |
| 对称加密 | 正在施工 | - | |
| 非对称加密 | 正在施工 | - | |
| 密钥生成 | 否 | - | |
| 密钥封装 | 否 | - | |
| 密钥派生 | 否 | - | |
| 安全多方计算 | 否 | - | |
| 同态加密 | 否 | - | |
| 模糊提取 | 否 | - | |
| 格式解析 | 否 | - | |
| SSL | 否 | - | |
| 安全分享 | 否 | - | |
| CA | 否 | - | |
| PKI | 否 | - | |
| PGC | 否 | - | |

## 二、密码库使用

对于大多数情况，密码库的使用方式如下
```c
#include <ce_ssl_crypto_core.h>

int main(int argc, char * argv){
    if(ce_ssl_crypto_core_init() != CeSSL_SUCCESS){
        printf("lib init error\n");
        exit(0);
    }
    CeSSLCryptoHandlerPointer handler = ce_ssl_crypto_get_handler(sm4);
    CeSSLKeyHandlerPointer key = ce_ssl_key_handler_constructor("1234567890123456", 16, SymmetricKey);
    CeSSLContextHandlerPointer context = ce_ssl_context_handler_crypto_constructor("abc", 3);
    ce_ssl_context_handler_append(context, "def", 3);
    CeSSLCryptoResultHandlerPointer result;   
    ce_ssl_crypto_do(handler, key, context, &result);
    int dataLen = 0;
    ce_ssl_result_handler_get_result(result, NULL, &dataLen);
    char trueResult[dataLen] = {0};
    ce_ssl_result_handler_get_result(result, trueResult, &dataLen);
    for(int i = 0; i < dataLen; i++){
        printf("%02x", trueResult[i]); 
    }
    printf("\n");  
   
    
    
    ce_ssl_context_handler_destructor(context);
    ce_ssl_key_handler_destructor(key);
    ce_ssl_crypto_handler_default_destructor(handler);
}

```
## 三、标准符合性测评参考文件
### 3.1 对称加密
### 3.2 非对称加密
### 3.3 摘要算法
### 3.4 密钥生成算法
### 3.5 密钥封装算法
### 3.5 密钥派生算法
### 3.6 随机数生成算法
## 四、各类算法详细施工情况
### 4.1 对称加密
### 4.2 非对称加密
### 4.3 摘要算法
### 4.4 密钥生成算法
### 4.5 密钥封装算法
### 4.5 密钥派生算法
### 4.6 随机数生成算法