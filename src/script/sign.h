// Copyright (c) 2016 cybercode technologies
// Copyright (c) 2016 The Cowrie developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COWRIE_SCRIPT_SIGN_H
#define COWRIE_SCRIPT_SIGN_H

#include "script/interpreter.h"

class CKeyStore;
class CScript;
class CTransaction;

struct CMutableTransaction;

bool SignSignature(const CKeyStore& keystore, const CScript& fromPubKey, CMutableTransaction& txTo, unsigned int nIn, int nHashType=SIGHASH_ALL);
bool SignSignature(const CKeyStore& keystore, const CTransaction& txFrom, CMutableTransaction& txTo, unsigned int nIn, int nHashType=SIGHASH_ALL);

/**
 * Given two sets of signatures for scriptPubKey, possibly with OP_0 placeholders,
 * combine them intelligently and return the result.
 */
CScript CombineSignatures(const CScript& scriptPubKey, const CTransaction& txTo, unsigned int nIn, const CScript& scriptSig1, const CScript& scriptSig2);

#endif // COWRIE_SCRIPT_SIGN_H
