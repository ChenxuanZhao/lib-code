/**
 ******************************************************************************
 * @file tsc_utf8toucs2.c
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

#include "lib_code.h"

uint16_t TSC_Utf8ToUcs2(uint32_t utf8_word) {
  uint8_t word[4] = {0};
  uint16_t ucs2_word = 0;

  word[0] = (utf8_word >> 24) & 0xFF;
  word[1] = (utf8_word >> 16) & 0xFF;
  word[2] = (utf8_word >> 8) & 0xFF;
  word[3] = (utf8_word >> 0) & 0xFF;

  if (word[0] == 0 && word[1] == 0 && word[2] == 0) {
    ucs2_word = word[3];
  } else if (word[0] == 0 && word[1] == 0) {
    ucs2_word = (uint16_t)((word[2] >> 2 & 0x07) << 8);
    ucs2_word |= (word[2] << 6) + (word[3] & 0x3F) & 0xFF;
  } else if (word[0] == 0) {
    ucs2_word = (uint16_t)(((word[1] << 4) + ((word[2] >> 2) & 0x0F)) << 8);
    ucs2_word |= (word[2] << 6) + (word[3] & 0x3F) & 0xFF;
  }

  return ucs2_word;
}
