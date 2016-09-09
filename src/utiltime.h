// Copyright (c) 2016 cybercode technologies
// Copyright (c) 2016 The Wuzhucoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WUZHUCOIN_UTILTIME_H
#define WUZHUCOIN_UTILTIME_H

#include <stdint.h>
#include <string>

int64_t GetTime();
int64_t GetTimeMillis();
int64_t GetTimeMicros();
void SetMockTime(int64_t nMockTimeIn);
void MilliSleep(int64_t n);

std::string DateTimeStrFormat(const char* pszFormat, int64_t nTime);

#endif // WUZHUCOIN_UTILTIME_H
