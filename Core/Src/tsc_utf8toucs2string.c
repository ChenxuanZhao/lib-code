/**
 ******************************************************************************
 * @file tsc_utf8toucs2string.c
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
 ******************************************************************************
 */

#include <stdio.h>
#include <string.h>

#include "lib_code.h"

void TSC_Utf8ToUcs2String(const char *str, char *pData, int16_t Size) {
  if (str == NULL || pData == NULL || Size <= 0) {
    return;
  }

  Size -= strlen(pData);
  while (*str != '\0' && Size - 5 >= 0) {
    uint32_t utf8_word = 0;
    uint16_t ucs2_word = 0;
    char buff[5] = {0};
    uint8_t word_size = 0;

    word_size = TSC_GetUtf8Char(str, &utf8_word);
    ucs2_word = TSC_Utf8ToUcs2(utf8_word);
    sprintf(buff, "%04X", (size_t)ucs2_word);
    strcat(pData, buff);
    str += word_size;
    Size -= 4;
  }
}
