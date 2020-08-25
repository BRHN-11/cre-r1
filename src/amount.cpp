// Copyright (c) 2016 cybercode technologies
// Copyright (c) 2016 The Cowrie developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "amount.h"

#include "tinyformat.h"

CFeeRate::CFeeRate(const CAmount& nFeePaid, size_t nSize)
{
    if (nSize > 0)
        nshellsPerK = nFeePaid*1000/nSize;
    else
        nshellsPerK = 0;
}

CAmount CFeeRate::GetFee(size_t nSize) const
{
    // Round up nSize to the nearest 1000
    CAmount mod = nSize % 1000;
    if (mod > 0)
        nSize = nSize - mod + 1000;
    CAmount nFee = nshellsPerK*nSize / 1000;

    if (nFee == 0 && nshellsPerK > 0)
        nFee = nshellsPerK;

    return nFee;
}

std::string CFeeRate::ToString() const
{
    return strprintf("%d.%08d COR/kB", nshellsPerK / COIN, nshellsPerK % COIN);
}
