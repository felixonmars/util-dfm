// SPDX-FileCopyrightText: 2020 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "dfmio_global.h"
#include "dfmio_register.h"

#include "core/dfile.h"
#include "core/diofactory.h"
#include "core/diofactory_p.h"

#include <stdio.h>

USING_IO_NAMESPACE

static void err_msg(const char *msg)
{
    fprintf(stderr, "dfm-move: %s\n", msg);
}

static void usage()
{
    err_msg("usage: dfm-move uri new-path.");
}

static bool move_file(const QUrl &url_src, const QUrl &url_dst)
{
    QSharedPointer<DIOFactory> factory = produceQSharedIOFactory(url_src.scheme(), static_cast<QUrl>(url_src));
    if (!factory) {
        err_msg("create factory failed.");
        return false;
    }

    QSharedPointer<DOperator> op = factory->createOperator();
    if (!op) {
        err_msg("operator create failed.");
        return false;
    }

    bool success = op->moveFile(url_dst, DFile::CopyFlag::kNone);
    if (!success) {
        err_msg("move file failed.");
        return false;
    }

    return true;
}

// move uri to new-path.
int main(int argc, char *argv[])
{
    if (argc != 3) {
        usage();
        return 1;
    }

    const char *uri_src = argv[1];
    const char *uri_dst = argv[2];

    QUrl url_src(QString::fromLocal8Bit(uri_src));
    QUrl url_dst(QString::fromLocal8Bit(uri_dst));

    if (!url_src.isValid() || !url_dst.isValid())
        return 1;

    /*const QString &scheme_src = url_src.scheme();
    const QString &scheme_dst = url_dst.scheme();

    if (scheme_src != scheme_dst)
        return 1;*/

    dfmio_init();
    //REGISTER_FACTORY1(DLocalIOFactory, scheme_src, QUrl);

    if (!move_file(url_src, url_dst)) {
        return 1;
    }

    return 0;
}
