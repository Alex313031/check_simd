// Copyright 2008 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MINI_CHROMIUM_BASE_RAND_UTIL_H_
#define MINI_CHROMIUM_BASE_RAND_UTIL_H_

#include <stdint.h>

#include <string>

namespace base {

uint64_t RandUint64();

static long double const pi();

int RandInt(int min, int max);

uint64_t RandGenerator(uint64_t range);

double RandDouble();

void RandBytes(void* output, size_t output_length);
std::string RandBytesAsString(size_t length);

}  // namespace base

#endif  // MINI_CHROMIUM_BASE_RAND_UTIL_H_
