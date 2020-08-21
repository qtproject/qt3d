/****************************************************************************
**
** Copyright (C) 2016 Klaralvdalens Datakonsult AB (KDAB).
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QT3DRENDER_RENDER_OPENGL_RENDERVIEWBUILDER_H
#define QT3DRENDER_RENDER_OPENGL_RENDERVIEWBUILDER_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of other Qt classes.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <functional>
#include <Qt3DCore/qaspectjob.h>
#include <Qt3DRender/private/filterlayerentityjob_p.h>
#include <Qt3DRender/private/genericlambdajob_p.h>
#include <Qt3DRender/private/nodemanagers_p.h>
#include <Qt3DRender/private/frustumcullingjob_p.h>
#include <Qt3DRender/private/filterproximitydistancejob_p.h>
#include <Qt3DRender/private/materialparametergathererjob_p.h>
#include <Qt3DRender/private/renderviewcommandbuilderjob_p.h>
#include <Qt3DRender/private/renderviewcommandupdaterjob_p.h>
#include <renderview_p.h>

QT_BEGIN_NAMESPACE

namespace Qt3DRender {

namespace Render {

namespace OpenGL {

class Renderer;

using SynchronizerJobPtr = GenericLambdaJobPtr<std::function<void()>>;
#define CreateSynchronizerJobPtr(lambda, type, instance) \
    SynchronizerJobPtr::create(lambda, type, #type, instance)

using RenderViewCommandBuilderJobPtr = Render::RenderViewCommandBuilderJobPtr<RenderView, RenderCommand>;
using RenderViewCommandUpdaterJobPtr = Render::RenderViewCommandUpdaterJobPtr<RenderView, RenderCommand>;
using RenderViewInitializerJobPtr = Render::RenderViewInitializerJobPtr<RenderView, Renderer>;

class Q_AUTOTEST_EXPORT RenderViewBuilder
{
public:
    explicit RenderViewBuilder(Render::FrameGraphNode *leafNode, int renderViewIndex, Renderer *renderer);

    RenderViewInitializerJobPtr renderViewJob() const;
    FilterLayerEntityJobPtr filterEntityByLayerJob() const;
    FrustumCullingJobPtr frustumCullingJob() const;
    const std::vector<RenderViewCommandBuilderJobPtr> &renderViewCommandBuilderJobs() const;
    const std::vector<RenderViewCommandUpdaterJobPtr> &renderViewCommandUpdaterJobs() const;
    const std::vector<MaterialParameterGathererJobPtr> &materialGathererJobs() const;
    SynchronizerJobPtr syncRenderViewPostInitializationJob() const;
    SynchronizerJobPtr syncPreFrustumCullingJob() const;
    SynchronizerJobPtr syncRenderViewPreCommandBuildingJob() const;
    SynchronizerJobPtr syncRenderViewPreCommandUpdateJob() const;
    SynchronizerJobPtr syncRenderViewPostCommandUpdateJob() const;
    SynchronizerJobPtr setClearDrawBufferIndexJob() const;
    SynchronizerJobPtr syncFilterEntityByLayerJob() const;
    FilterProximityDistanceJobPtr filterProximityJob() const;
    SynchronizerJobPtr syncMaterialGathererJob() const;

    void prepareJobs();
    std::vector<Qt3DCore::QAspectJobPtr> buildJobHierachy() const;

    Renderer *renderer() const;
    int renderViewIndex() const;

    void setLayerCacheNeedsToBeRebuilt(bool needsToBeRebuilt);
    bool layerCacheNeedsToBeRebuilt() const;
    void setMaterialGathererCacheNeedsToBeRebuilt(bool needsToBeRebuilt);
    bool materialGathererCacheNeedsToBeRebuilt() const;
    void setRenderCommandCacheNeedsToBeRebuilt(bool needsToBeRebuilt);
    bool renderCommandCacheNeedsToBeRebuilt() const;
    void setLightCacheNeedsToBeRebuilt(bool needsToBeRebuilt);
    bool lightCacheNeedsToBeRebuilt() const;

    static int defaultJobCount();
    int optimalJobCount() const;
    void setOptimalJobCount(int v);

    static std::vector<Entity *> entitiesInSubset(const std::vector<Entity *> &entities,
                                                  const std::vector<Entity *> &subset);

private:
    Render::FrameGraphNode *m_leafNode;
    const int m_renderViewIndex;
    Renderer *m_renderer;
    RebuildFlagSet m_rebuildFlags;

    RenderViewInitializerJobPtr m_renderViewJob;
    FilterLayerEntityJobPtr m_filterEntityByLayerJob;
    FrustumCullingJobPtr m_frustumCullingJob;
    std::vector<RenderViewCommandBuilderJobPtr> m_renderViewCommandBuilderJobs;
    std::vector<RenderViewCommandUpdaterJobPtr> m_renderViewCommandUpdaterJobs;
    std::vector<MaterialParameterGathererJobPtr> m_materialGathererJobs;

    SynchronizerJobPtr m_syncRenderViewPostInitializationJob;
    SynchronizerJobPtr m_syncPreFrustumCullingJob;
    SynchronizerJobPtr m_syncRenderViewPreCommandBuildingJob;
    SynchronizerJobPtr m_syncRenderViewPreCommandUpdateJob;
    SynchronizerJobPtr m_syncRenderViewPostCommandUpdateJob;
    SynchronizerJobPtr m_setClearDrawBufferIndexJob;
    SynchronizerJobPtr m_syncFilterEntityByLayerJob;
    SynchronizerJobPtr m_syncMaterialGathererJob;
    FilterProximityDistanceJobPtr m_filterProximityJob;

    int m_optimalParallelJobCount;
};

} // OpenGL

} // Render

} // Qt3DRender

QT_END_NAMESPACE

#endif // QT3DRENDER_RENDER_OPENGL_RENDERVIEWBUILDER_H
