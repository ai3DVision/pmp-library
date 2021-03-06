//=============================================================================
// Copyright (C) 2011-2017 The pmp-library developers
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
#pragma once
//=============================================================================

#include <pmp/gl/PointSetGL.h>
#include <pmp/gl/TrackballViewer.h>

//=============================================================================

namespace pmp {

//=============================================================================

//! \addtogroup gl gl
//! @{

//! Simple viewer for a PointSet
class PointSetViewer : public TrackballViewer
{
public:
    //! constructor
    PointSetViewer(const char* title, int width, int height);

    //! destructor
    virtual ~PointSetViewer();

    //! load a mesh from file \c filename
    virtual bool loadPointSet(const char* filename);

    //! update all buffers for OpenGL rendering.  call this function whenever
    //! you change either the vertex positions of the point set.
    virtual void updatePointSet();

    //! draw the scene in different draw modes
    virtual void draw(const std::string& _draw_mode);

    //! this function handles keyboard events
    void keyboard(int key, int scancode, int action, int mod);

protected:
    PointSetGL  m_pointSet; //!< the point set
    std::string m_filename; //!< the current file
};

//=============================================================================
//! @}
//=============================================================================
} // namespace pmp
//=============================================================================
