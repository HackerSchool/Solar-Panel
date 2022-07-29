/**
 * @file SPlane.h
 * @author filipe-varela
 * @brief
 * A class in which generates a plane from a series of LDRs' readings. The readings are
 * converted suffers a signal conditioning, in which goes from `[0..1043]` -> `[0..100]`,
 * with `0` being converted to `100` and `1043` to `0`.
 * @version 0.1
 * @date 2022-07-28
 *
 * @copyright
 * Copyright 2022 Filipe Varela
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SPlane_h
#define SPlane_h

#include <Arduino.h>

class SPlane
{
public:
    SPlane(int ldr_pins[]);
    void read();
    // passar uma referência da array em vez da array toda para poupar espaço e ser mais rápido
    void generatePlane(float &s);
    float s_vector[3];

private:
    int _ldr_pins[];
};

#endif