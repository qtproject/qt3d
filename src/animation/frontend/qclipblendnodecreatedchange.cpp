/****************************************************************************
**
** Copyright (C) 2017 Klaralvdalens Datakonsult AB (KDAB).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qclipblendnodecreatedchange.h"
#include "qclipblendnodecreatedchange_p.h"
#include <Qt3DAnimation/qabstractclipblendnode.h>
#include <Qt3DAnimation/qabstractanimationclip.h>

QT_BEGIN_NAMESPACE

namespace Qt3DAnimation {

QClipBlendNodeCreatedChangeBasePrivate::QClipBlendNodeCreatedChangeBasePrivate(const QAbstractClipBlendNode *node)
    : Qt3DCore::QNodeCreatedChangeBasePrivate(node)
{
}

/*!
   \class Qt3DAnimation::QClipBlendNodeCreatedChangeBase
   \inherits Qt3DCore::QNodeCreatedChangeBase
   \inmodule Qt3DAnimation
   \brief Base class for changes in QClipBlendNode
*/
QClipBlendNodeCreatedChangeBase::QClipBlendNodeCreatedChangeBase(const QAbstractClipBlendNode *node)
    : Qt3DCore::QNodeCreatedChangeBase(*new QClipBlendNodeCreatedChangeBasePrivate(node), node)
{
}

QClipBlendNodeCreatedChangeBase::~QClipBlendNodeCreatedChangeBase()
{
}
/*!
    \typedef Qt3DAnimation::QClipBlendNodeCreatedChangeBasePtr

    A shared pointer for QClipBlendNodeCreatedChangeBase.
*/

} // Qt3DAnimation

QT_END_NAMESPACE
