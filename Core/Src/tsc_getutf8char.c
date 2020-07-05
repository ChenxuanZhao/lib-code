/**
 ******************************************************************************
 * @file tsc_getutf8char.c
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

#include "lib_code.h"

#define RANGE(min, val, max) (min <= val && val <= max)

struct _utf8_index {
  uint32_t begin;
  uint32_t end;
};

#if defined __C51__
static code struct _utf8_index utf8_index[] = {{0x00000000, 0x0000007F},
                                               {0x0000C080, 0x0000DFBF},
                                               {0x00E08080, 0x00EFBFBF},
                                               {0xF0808080, 0xF7BFBFBF}};
#else
static const struct _utf8_index utf8_index[] = {{0x00000000, 0x0000007F},
                                                {0x0000C080, 0x0000DFBF},
                                                {0x00E08080, 0x00EFBFBF},
                                                {0xF0808080, 0xF7BFBFBF}};
#endif

uint8_t TSC_GetUtf8Char(const char *str, uint32_t *pData) {
  uint8_t i = 0;
  uint32_t utf8_word = 0;

  if (str == NULL) {
    return 0;
  }

  for (i = 0; i < 4; i++) {
    utf8_word <<= 8;
    utf8_word |= (uint8_t)str[i];
    if (RANGE(utf8_index[i].begin, utf8_word, utf8_index[i].end)) {
      if (pData != NULL) {
        *pData = utf8_word;
      }

      return i + 1;
    }
  }

  return 0;
}
