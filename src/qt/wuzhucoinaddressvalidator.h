// Copyright (c) 2011-2014 The Wuzhucoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WUZHUCOIN_QT_WUZHUCOINADDRESSVALIDATOR_H
#define WUZHUCOIN_QT_WUZHUCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class WuzhucoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit WuzhucoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Wuzhucoin address widget validator, checks for a valid wuzhucoin address.
 */
class WuzhucoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit WuzhucoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // WUZHUCOIN_QT_WUZHUCOINADDRESSVALIDATOR_H
