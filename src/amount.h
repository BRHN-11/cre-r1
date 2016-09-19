// Copyright (c) 2016 cybercode technologies
// Copyright (c) 2016 The Cowrie developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COWRIE_AMOUNT_H
#define COWRIE_AMOUNT_H

#include "serialize.h"

#include <stdlib.h>
#include <string>

typedef int64_t CAmount;

static const CAmount COIN = 100000000;
static const CAmount CENT = 1000000;

/** No amount larger than this (in shell) is valid */
static const CAmount MAX_MONEY = 84000000 * COIN;
inline bool MoneyRange(const CAmount& nValue) { return (nValue >= 0 && nValue <= MAX_MONEY); }

/** Type-safe wrapper class to for fee rates
 * (how much to pay based on transaction size)
 */
class CFeeRate
{
private:
    CAmount nshellsPerK; // unit is shells-per-1,000-bytes
public:
    CFeeRate() : nshellsPerK(0) { }
    explicit CFeeRate(const CAmount& _nshellsPerK): nshellsPerK(_nshellsPerK) { }
    CFeeRate(const CAmount& nFeePaid, size_t nSize);
    CFeeRate(const CFeeRate& other) { nshellsPerK = other.nshellsPerK; }

    CAmount GetFee(size_t size) const; // unit returned is shells
    CAmount GetFeePerK() const { return GetFee(1000); } // shells-per-1000-bytes

    friend bool operator<(const CFeeRate& a, const CFeeRate& b) { return a.nshellsPerK < b.nshellsPerK; }
    friend bool operator>(const CFeeRate& a, const CFeeRate& b) { return a.nshellsPerK > b.nshellsPerK; }
    friend bool operator==(const CFeeRate& a, const CFeeRate& b) { return a.nshellsPerK == b.nshellsPerK; }
    friend bool operator<=(const CFeeRate& a, const CFeeRate& b) { return a.nshellsPerK <= b.nshellsPerK; }
    friend bool operator>=(const CFeeRate& a, const CFeeRate& b) { return a.nshellsPerK >= b.nshellsPerK; }
    std::string ToString() const;

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action, int nType, int nVersion) {
        READWRITE(nshellsPerK);
    }
};

#endif //  COWRIE_AMOUNT_H
