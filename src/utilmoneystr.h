// Copyright (c) 2016 cybercode technologies
// Copyright (c) 2016 The Wuzhucoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

/**
 * Money parsing/formatting utilities.
 */
#ifndef WUZHUCOIN_UTILMONEYSTR_H
#define WUZHUCOIN_UTILMONEYSTR_H

#include <stdint.h>
#include <string>

#include "amount.h"

std::string FormatMoney(const CAmount& n, bool fPlus=false);
bool ParseMoney(const std::string& str, CAmount& nRet);
bool ParseMoney(const char* pszIn, CAmount& nRet);

#endif // WUZHUCOIN_UTILMONEYSTR_H
