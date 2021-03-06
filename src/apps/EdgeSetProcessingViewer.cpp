//=============================================================================
// Copyright (C) 2011-2018 The pmp-library developers
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//=============================================================================

#include "EdgeSetProcessingViewer.h"

#include <pmp/algorithms/EdgeSetSmoothing.h>
#include <pmp/algorithms/EdgeSetSubdivision.h>

//=============================================================================

using namespace pmp;

//=============================================================================

void EdgeSetProcessingViewer::keyboard(int key, int code, int action, int mods)
{
    if (action!=GLFW_PRESS && action!=GLFW_REPEAT)
        return;

    switch (key)
    {
        case GLFW_KEY_S:
        {
            EdgeSetSmoothing ess(m_edgeSet);
            ess.smooth(1);
            updateEdgeSet();
            break;
        }
        case GLFW_KEY_U:
        {
            EdgeSetSubdivision esub(m_edgeSet);
            esub.subdivide();
            updateEdgeSet();
            break;
        }
        case GLFW_KEY_O:
        {
            m_edgeSet.write("output.knt");
            std::cout << "wrote EdgeSet to output.knt" << std::endl;
            break;
        }
        default:
        {
            EdgeSetViewer::keyboard(key, code, action, mods);
            break;
        }
    }
}

//=============================================================================
