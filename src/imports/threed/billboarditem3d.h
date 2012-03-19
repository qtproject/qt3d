/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef BILLBOARDITEM3D_H
#define BILLBOARDITEM3D_H

#include "qquickitem3d.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

class BillboardItem3D : public QQuickItem3D
{
    Q_OBJECT
    Q_PROPERTY(bool preserveUpVector READ preserveUpVector WRITE setPreserveUpVector)
public:
    BillboardItem3D(QObject *parent = 0);

    bool preserveUpVector() const;
    void setPreserveUpVector(bool value);

    void draw(QGLPainter *painter);

private:
    bool m_preserveUpVector;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(BillboardItem3D)

QT_END_HEADER

#endif // BILLBOARDITEM3D_H
