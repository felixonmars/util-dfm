// SPDX-FileCopyrightText: 2020 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef DGIOHELPER_H
#define DGIOHELPER_H

#include "dfmio_global.h"
#include "core/dfileinfo.h"

#include <gio/gio.h>

#include <QSharedPointer>

BEGIN_IO_NAMESPACE

template<class C, typename Ret, typename... Ts>
std::function<Ret(Ts...)> bind_field(C *c, Ret (C::*m)(Ts...))
{
    return [=](auto &&... args) { return (c->*m)(std::forward<decltype(args)>(args)...); };
}

template<class C, typename Ret, typename... Ts>
std::function<Ret(Ts...)> bind_field(const C *c, Ret (C::*m)(Ts...) const)
{
    return [=](auto &&... args) { return (c->*m)(std::forward<decltype(args)>(args)...); };
}

template<typename Ret, typename... Ts>
std::function<Ret(Ts...)> bind_field(Ret (*m)(Ts...))
{
    return [=](auto &&... args) { return (*m)(std::forward<decltype(args)>(args)...); };
}

class DLocalHelper
{
public:
    static QSharedPointer<DFileInfo> createFileInfoByUri(const QUrl &uri, const char *attributes = "*",
                                                         const DFMIO::DFileInfo::FileQueryInfoFlags flag = DFMIO::DFileInfo::FileQueryInfoFlags::kTypeNone);
    static QSharedPointer<DFileInfo> createFileInfoByUri(const QUrl &uri, GFileInfo *gfileInfo, const char *attributes = "*",
                                                         const DFMIO::DFileInfo::FileQueryInfoFlags flag = DFMIO::DFileInfo::FileQueryInfoFlags::kTypeNone);

    static QVariant attributeFromGFileInfo(GFileInfo *gfileinfo, DFileInfo::AttributeID id, DFMIOErrorCode &errorcode);
    static QVariant customAttributeFromPath(const QString &path, DFileInfo::AttributeID id);
    static QVariant customAttributeFromPathAndInfo(const QString &path, GFileInfo *fileInfo, DFileInfo::AttributeID id);
    static bool setAttributeByGFile(GFile *gfile, DFileInfo::AttributeID id, const QVariant &value, GError **error);
    static bool setAttributeByGFileInfo(GFileInfo *gfileinfo, DFileInfo::AttributeID id, const QVariant &value);
    static std::string attributeStringById(DFileInfo::AttributeID id);
    static QSet<QString> hideListFromUrl(const QUrl &url);
    static bool fileIsHidden(const QSharedPointer<DFileInfo> &dfileinfo, const QSet<QString> &hideList);

    // tools
    static bool checkGFileType(GFile *file, GFileType type);
};

END_IO_NAMESPACE

#endif   // DGIOHELPER_H
