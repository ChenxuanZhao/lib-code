/**
 ******************************************************************************
 * @file tsc_ucs2toutf8string.c
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

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "lib_code.h"

void TSC_Ucs2ToUtf8String(const char *str, char *pData, int16_t Size) {
  if (str == NULL || pData == NULL || Size <= 0) {
    return;
  }

  Size -= strlen(pData);
  while (isalnum((int)*str) && Size - 5 >= 0) {
    uint32_t utf8_word = 0;
    size_t ucs2_word = 0;
    char buff[5] = {0};
    uint8_t i = 0;

    strncpy(buff, str, 4);
    sscanf(buff, "%X", &ucs2_word);
    utf8_word = TSC_Ucs2ToUtf8((uint16_t)ucs2_word);
    while (!(utf8_word & 0xFF000000)) {
      utf8_word <<= 8;
    }
    memset(buff, 0, sizeof(buff));
    for (i = 0; i < 4; i++) {
      buff[i] = (utf8_word >> 8 * (3 - i)) & 0xFF;
    }
    strcat(pData, buff);
    str += 4;
    Size -= strlen(buff);
  }
}
