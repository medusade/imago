///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: MidpointCircleImage.hpp
///
/// Author: $author$
///   Date: 10/17/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_MIDPOINTCIRCLEIMAGE_HPP
#define _IMAGO_GRAPHIC_MIDPOINTCIRCLEIMAGE_HPP

#include "imago/graphic/BaseImage.hpp"
#include "imago/graphic/MidpointCircle.hpp"

namespace imago {
namespace graphic {

typedef MidpointCircleT
<BaseImage, ImageImplement> MidpointCircleImageExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MidpointCircleImage
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MidpointCircleImage: public MidpointCircleImageExtends {
public:
    typedef MidpointCircleImageExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MidpointCircleImage(tImageImplement& image): Extends(image) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef FilledMidpointCircleT
<BaseImage, ImageImplement> FilledMidpointCircleImageExtends;
///////////////////////////////////////////////////////////////////////
///  Class: FilledMidpointCircleImage
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS FilledMidpointCircleImage: public FilledMidpointCircleImageExtends {
public:
    typedef FilledMidpointCircleImageExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    FilledMidpointCircleImage(tImageImplement& image): Extends(image) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_MIDPOINTCIRCLEIMAGE_HPP 
