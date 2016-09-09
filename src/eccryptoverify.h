// Copyright (c) 2016 cybercode technologies
// Copyright (c) 2016 The Wuzhucoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WUZHUCOIN_ECCRYPTOVERIFY_H
#define WUZHUCOIN_ECCRYPTOVERIFY_H

#include <vector>
#include <cstdlib>

class uint256;

namespace eccrypto {

bool Check(const unsigned char *vch);
bool CheckSignatureElement(const unsigned char *vch, int len, bool half);

} // eccrypto namespace

#endif // WUZHUCOIN_ECCRYPTOVERIFY_H
