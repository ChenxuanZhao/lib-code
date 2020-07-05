/**
 ******************************************************************************
 * @file main.h
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

#ifndef __MAIN_H
#define __MAIN_H

#include <STC89C5xRC.H>

sbit LED_Pin = P1 ^ 0;

#ifdef __cplusplus
extern "C" {
#endif

extern void Test_TSC_Utf8ToUcs2String(void);
extern void Test_TSC_Ucs2ToUtf8String(void);
extern void LED_Blink(void);
extern void Delay500ms(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
