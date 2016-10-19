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
///   File: ImageBase.hpp
///
/// Author: $author$
///   Date: 10/10/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_IMAGEBASE_HPP
#define _IMAGO_GRAPHIC_IMAGEBASE_HPP

#include "imago/graphic/Quadrant.hpp"

namespace imago {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: ImageImplementBaseT
///////////////////////////////////////////////////////////////////////
template
<class TImplementBase = ImplementBase,
 class TImplements = TImplementBase>

class _EXPORT_CLASS ImageImplementBaseT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef ImageImplementBaseT tImageImplementBase;
    typedef TImplementBase tImplementBase;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot
    (tImageImplementBase& pixel, tOffset x,tOffset y) {
    }
    virtual void Fill
    (tImageImplementBase& pixel, tOffset x,tOffset y, tSize w,tSize h) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void FillEllipse
    (tImageImplementBase& pixel, tOffset x,tOffset y,
     tSize w,tSize h, Quadrant quadrant = QUADRANT_ALL) {
    }
    virtual void FillEllipseRectangle
    (tImageImplementBase& pixel, tOffset x,tOffset y,
     tSize w,tSize h, Quadrant quadrant = QUADRANT_ALL) {
    }
    virtual void HollowEllipse
    (tImageImplementBase& pixel, tOffset x,tOffset y,
     tSize w,tSize h, Quadrant quadrant = QUADRANT_ALL) {
    }
    virtual void HollowEllipseRectangle
    (tImageImplementBase& pixel, tOffset x,tOffset y,
     tSize w,tSize h, Quadrant quadrant = QUADRANT_ALL) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void FillCircle
    (tImageImplementBase& pixel, tOffset x,tOffset y,
     tSize r, Quadrant quadrant = QUADRANT_ALL) {
    }
    virtual void HollowCircle
    (tImageImplementBase& pixel, tOffset x,tOffset y,
     tSize r, Quadrant quadrant = QUADRANT_ALL) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void FillTriangle
    (tImageImplementBase& pixel,
     tOffset x1, tOffset y1, tOffset x2, tOffset y2, tOffset x3, tOffset y3) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ImageImplementBaseT<> ImageImplementBase;

///////////////////////////////////////////////////////////////////////
///  Class: ImageBaseT
///////////////////////////////////////////////////////////////////////
template
<class TImageImplementBase = ImageImplementBase,
 class TBase = Base,
 class TImplements = TImageImplementBase, class TExtends = TBase>

class _EXPORT_CLASS ImageBaseT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TImageImplementBase tImageImplementBase;
    typedef TBase tBase;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ImageBaseT(tImageImplementBase& image): m_image(image) {
    }
    virtual ~ImageBaseT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot
    (tImageImplementBase& pixel, tOffset x,tOffset y) {
        pixel.Plot(m_image, x,y);
    }
    virtual void Fill
    (tImageImplementBase& pixel, tOffset x,tOffset y, tSize w,tSize h) {
        pixel.Fill(m_image, x,y, w,h);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tImageImplementBase& m_image;
};
typedef ImageBaseT<> ImageBase;

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_IMAGEBASE_HPP 
