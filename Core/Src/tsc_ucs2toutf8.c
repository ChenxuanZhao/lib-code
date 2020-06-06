/**
 ******************************************************************************
 * @file tsc_ucs2toutf8.c
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

#define RANGE(min, val, max) (min <= val && val <= max)

uint32_t TSC_Ucs2ToUtf8(uint16_t ucs2_word) {
  uint32_t utf8_word = 0;
  uint32_t word = ucs2_word;

  if (word <= 0x7F) {
    utf8_word = word & 0x7F;
  } else if (RANGE(0x80, word, 0x7FF)) {
    utf8_word = (word >> 6 & 0x1F | 0xC0) << 8;
    utf8_word |= word & 0x3F | 0x80;
  } else if (RANGE(0x800, word, 0xFFFF)) {
    utf8_word = (word >> 12 & 0x0F | 0xE0) << 16;
    utf8_word |= (word >> 6 & 0x3F | 0x80) << 8;
    utf8_word |= word & 0x3F | 0x80;
  } else if (RANGE(0x10000, word, 0x1FFFFF)) {
    utf8_word = (word >> 18 & 0x07 | 0xF0) << 24;
    utf8_word |= (word >> 12 & 0x3F | 0x80) << 16;
    utf8_word |= (word >> 6 & 0x3F | 0x80) << 8;
    utf8_word |= word & 0x3F | 0x80;
  }

  return utf8_word;
}
