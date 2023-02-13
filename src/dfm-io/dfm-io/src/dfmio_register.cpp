// SPDX-FileCopyrightText: 2020 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "dfmio_register.h"

#include <mutex>

#include "factory/dlocaliofactory.h"
#include "factory/dtrashiofactory.h"
#include "factory/dftpiofactory.h"
#include "factory/dmtpiofactory.h"
#include "factory/dafciofactory.h"
#include "factory/dafpiofactory.h"
#include "factory/ddaviofactory.h"
#include "factory/dddaviofactory.h"
#include "factory/dnfsiofactory.h"
#include "factory/dsmbiofactory.h"
#include "factory/dburniofactory.h"
#include "factory/dsftpiofactory.h"
#include "factory/dafpbrowseiofactory.h"
#include "factory/darchiveiofactory.h"
#include "factory/dcddaiofactory.h"
#include "factory/dcomputeriofactory.h"
#include "factory/ddnssdiofactory.h"
#include "factory/dgphoto2iofactory.h"
#include "factory/dhttpiofactory.h"
#include "factory/dnetworkiofactory.h"
#include "factory/drecentiofactory.h"
#include "factory/dsmbbrowseiofactory.h"
#include "factory/dgoogleiofactory.h"

USING_IO_NAMESPACE

bool dfmio::dfmio_init()
{
    static std::once_flag flag;

    std::call_once(flag, [](){
        REGISTER_FACTORY1(DLocalIOFactory, "file", QUrl);
        REGISTER_FACTORY1(DTrashIOFactory, "trash", QUrl);
        REGISTER_FACTORY1(DFtpIOFactory, "ftp", QUrl);
        REGISTER_FACTORY1(DMtpIOFactory, "mtp", QUrl);
        REGISTER_FACTORY1(DAfcIOFactory, "afc", QUrl);

        REGISTER_FACTORY1(DAfpIOFactory, "afp", QUrl);
        REGISTER_FACTORY1(DDavIOFactory, "dav", QUrl);
        REGISTER_FACTORY1(DDdavIOFactory, "ddav", QUrl);
        REGISTER_FACTORY1(DNfsIOFactory, "nfs", QUrl);
        REGISTER_FACTORY1(DSmbIOFactory, "smb", QUrl);

        REGISTER_FACTORY1(DBurnIOFactory, "burn", QUrl);
        REGISTER_FACTORY1(DSftpIOFactory, "sftp", QUrl);
        REGISTER_FACTORY1(DAfpbrowseIOFactory, "afpbrowse", QUrl);
        REGISTER_FACTORY1(DArchiveIOFactory, "archive", QUrl);
        REGISTER_FACTORY1(DCddaIOFactory, "cdda", QUrl);

        REGISTER_FACTORY1(DComputerIOFactory, "computer", QUrl);
        REGISTER_FACTORY1(DDnssdIOFactory, "dnssd", QUrl);
        REGISTER_FACTORY1(DGphoto2IOFactory, "gphoto2", QUrl);
        REGISTER_FACTORY1(DHttpIOFactory, "http", QUrl);
        REGISTER_FACTORY1(DNetworkIOFactory, "network", QUrl);

        REGISTER_FACTORY1(DRecentIOFactory, "recent", QUrl);
        REGISTER_FACTORY1(DSmbbrowseIOFactory, "smbbrowse", QUrl);
        REGISTER_FACTORY1(DGoogleIOFactory, "google", QUrl);
    });

    return true;
}

QSet<QString> dfmio::schemesInited()
{
    QSet<QString> set;
    set.insert("file");
    set.insert("trash");
    set.insert("ftp");
    set.insert("mtp");
    set.insert("afc");

    set.insert("afp");
    set.insert("dav");
    set.insert("ddav");
    set.insert("nfs");
    set.insert("smb");

    set.insert("burn");
    set.insert("sftp");
    set.insert("afpbrowse");
    set.insert("archive");
    set.insert("cdda");

    set.insert("computer");
    set.insert("dnssd");
    set.insert("gphoto2");
    set.insert("http");
    set.insert("network");

    set.insert("recent");
    set.insert("smbbrowse");
    set.insert("google");

    return set;
}
