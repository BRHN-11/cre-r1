// Copyright (c) 2014 The Cowrie developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COWRIE_QT_WINSHUTDOWNMONITOR_H
#define COWRIE_QT_WINSHUTDOWNMONITOR_H

#ifdef WIN32
#include <QByteArray>
#include <QString>

#if QT_VERSION >= 0x050000
#include <windef.h> // for HWND

#include <QAbstractNativeEventFilter>

class WinShutdownMonitor : public QAbstractNativeEventFilter
{
public:
    /** Implements QAbstractNativeEventFilter interface for processing Windows messages */
    bool nativeEventFilter(const QByteArray &eventType, void *pMessage, long *pnResult);

    /** Register the reason for blocking shutdown on Windows to allow clean client exit */
    static void registerShutdownBlockReason(const QString& strReason, const HWND& mainWinId);
};
#endif
#endif

#endif // COWRIE_QT_WINSHUTDOWNMONITOR_H
