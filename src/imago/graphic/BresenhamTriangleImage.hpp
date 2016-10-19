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
///   File: BresenhamTriangleImage.hpp
///
/// Author: $author$
///   Date: 10/17/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_BRESENHAMTRIANGLEIMAGE_HPP
#define _IMAGO_GRAPHIC_BRESENHAMTRIANGLEIMAGE_HPP

#include "imago/graphic/BresenhamTriangle.hpp"
#include "imago/graphic/BaseImage.hpp"

namespace imago {
namespace graphic {

typedef BresenhamTriangleT
<BaseImage, ImageImplement> BresenhamTriangleImageExtends;
///////////////////////////////////////////////////////////////////////
///  Class: BresenhamTriangleImage
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS BresenhamTriangleImage: public BresenhamTriangleImageExtends {
public:
    typedef BresenhamTriangleImageExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BresenhamTriangleImage(tImageImplementBase& image): Extends(image) {
    }
    virtual ~BresenhamTriangleImage() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef FilledBresenhamTriangleT
<BaseImage, ImageImplement> FilledBresenhamTriangleImageExtends;
///////////////////////////////////////////////////////////////////////
///  Class: FilledBresenhamTriangleImage
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS FilledBresenhamTriangleImage: public FilledBresenhamTriangleImageExtends {
public:
    typedef FilledBresenhamTriangleImageExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    FilledBresenhamTriangleImage(tImageImplementBase& image): Extends(image) {
    }
    virtual ~FilledBresenhamTriangleImage() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_BRESENHAMTRIANGLEIMAGE_HPP 
