/**
 ******************************************************************************
 * @file lib_code.h
 * @author 赵晨瑄 (chenxuan.zhao@icloud.com)
 * @brief 字符转换程序
 * @version 1.0
 * @date 2020-06-01
 ******************************************************************************
 * Copyright [2020] [Chenxuan]
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************
 */

#ifndef __LIB_CODE_H
#define __LIB_CODE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief utf8 编码
 *
 * @param str [in] utf8 字符串
 * @param pData [out] 字符编码
 * @return uint8_t uft8 字符长度
 */
extern uint8_t TSC_GetUtf8Char(const char *, uint32_t *);

/**
 * @brief utf8 编码 转成 ucs2 编码
 *
 * @param utf8_word [in] utf8 字符编码
 * @return uint16_t ucs2 字符编码
 */
extern uint16_t TSC_Utf8ToUcs2(uint32_t);

/**
 * @brief ucs2 编码 转成 utf8 编码
 *
 * @param ucs2_word [in] ucs2 编码
 * @return uint32_t utf8 编码
 */
extern uint32_t TSC_Ucs2ToUtf8(uint16_t);

/**
 * @brief utf8 字符串 转成 ucs2 编码字符串
 *
 * @param str [in] utf8 字符串
 * @param pData [out] ucs2 编码字符串
 * @param Size [in] 放置 ucs2 编码字符串的内存大小
 * @return None
 */
extern void TSC_Utf8ToUcs2String(const char *, char *, int16_t);

/**
 * @brief ucs2 编码字符串 转成 utf8 字符串
 *
 * @param str [in] ucs2 编码字符串
 * @param pData [out] utf8 编码字符串
 * @param Size [in] 放置 utf8 编码字符串的内存大小
 *
 * @return None
 */
extern void TSC_Ucs2ToUtf8String(const char *, char *, int16_t);

#ifdef __cplusplus
}
#endif

#endif /* __LIB_CODE_H */
