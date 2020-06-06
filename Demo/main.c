/**
 ******************************************************************************
 * @file main.c
 * @author 赵晨瑄 (chenxuan.zhao@icloud.com)
 * @brief 字符转换演示程序
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

#include "main.h"

#include <intrins.h>
#include <stdlib.h>
#include <string.h>

#include "lib_code.h"

static const char ucs2_string[] = "4F60597D4E16754C";
static const char utf8_string[] = "你好世界";

static char mempool[100] = {0};

int main(void) {
  // 内存池初始化
  init_mempool(mempool, sizeof(mempool));

  // 测试 TSC_Utf8ToUcs2String
  Test_TSC_Utf8ToUcs2String();
  // 测试 TSC_Ucs2ToUtf8String
  Test_TSC_Ucs2ToUtf8String();
  for (;;) {
  }
}

/**
 * @brief TSC_Utf8ToUcs2String 单元测试
 */
void Test_TSC_Utf8ToUcs2String(void) {
  char _MALLOC_MEM_ *ret = (char *)calloc(sizeof(char), 17);

  if (ret != NULL) {
    // utf8 转换成 ucs2
    TSC_Utf8ToUcs2String(utf8_string, ret, 17);
    // 对比字符串
    if (strcmp(ucs2_string, ret) == 0) {
      LED_Blink();
    }
    free(ret);
  }
}

/**
 * @brief TSC_Ucs2ToUtf8String 单元测试
 */
void Test_TSC_Ucs2ToUtf8String(void) {
  char _MALLOC_MEM_ *ret = (char *)calloc(sizeof(char), 17);

  if (ret != NULL) {
    // ucs2 转换成 utf8
    TSC_Ucs2ToUtf8String(ucs2_string, ret, 17);
    // 对比字符串
    if (strcmp(utf8_string, ret) == 0) {
      LED_Blink();
    }
    free(ret);
  }
}

/**
 * @brief LED 小灯开启 500 毫秒
 */
void LED_Blink(void) {
  LED_Pin = 0;
  Delay500ms();
  LED_Pin = 1;
}

/**
 * @brief 延时 500 毫秒
 */
void Delay500ms(void) {  //@11.0592MHz
  uint8_t i = 4;
  uint8_t j = 129;
  uint8_t k = 119;

  _nop_();
  do {
    do {
      while (--k) {
        ;
      }
    } while (--j);
  } while (--i);
}
