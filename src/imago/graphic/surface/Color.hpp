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
///   File: Color.hpp
///
/// Author: $author$
///   Date: 10/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_SURFACE_COLOR_HPP
#define _IMAGO_GRAPHIC_SURFACE_COLOR_HPP

#include "imago/graphic/surface/Object.hpp"

namespace imago {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: ColorT
///////////////////////////////////////////////////////////////////////
template
<class TObject = Object,
 class TImageImplement = ImageImplement,
 class TPixelImplement = PixelImplement,
 class TPixel = Pixel,
 class TImageImplementBase = ImageImplementBase,
 class TColorSample = ColorSample,
 class TImplements = TPixelImplement, class TExtends = TObject>

class _EXPORT_CLASS ColorT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TObject tObject;
    typedef TImageImplement tImageImplement;
    typedef TImageImplementBase tImageImplementBase;
    typedef TPixelImplement tPixelImplement;
    typedef TPixel tPixel;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ColorT
    (tImageImplement& surfaceImage,
     tColorSample r, tColorSample g, tColorSample b,
     tSize width = 1, tSize height = 1)
    : Extends(surfaceImage),
      m_r(r), m_g(g), m_b(b),
      m_width(width), m_height(height),
      m_color(r,g,b) {
    }
    ColorT(const ColorT& copy, tSize width = 1, tSize height = 1)
    : Extends(copy.m_surfaceImage),
      m_r(copy.m_r), m_g(copy.m_g), m_b(copy.m_b),
      m_width(width), m_height(height),
      m_color(copy.m_color) {
    }
    ColorT(const ColorT& copy)
    : Extends(copy.m_surfaceImage),
      m_r(copy.m_r), m_g(copy.m_g), m_b(copy.m_b),
      m_width(copy.m_width), m_height(copy.m_height),
      m_color(copy.m_color) {
    }
    virtual ~ColorT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot
    (tImageImplementBase& pixel, tOffset x,tOffset y) {
        tImageImplementBase& thisImage = this->m_surfaceImage;
        if (!(&pixel != &thisImage)) {
            this->Fill(x,y, 1,1);
        }
    }
    virtual void Fill
    (tImageImplementBase& pixel, tOffset x,tOffset y, tSize w,tSize h) {
        tImageImplementBase& thisImage = this->m_surfaceImage;
        if (!(&pixel != &thisImage)) {
            this->Fill(x,y, w,h);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot(tOffset x, tOffset y) {
        Fill(x,y, 1,1);
    }
    virtual void Fill(tOffset x, tOffset y, tSize w, tSize h) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tColorSample Red() const { return m_r; }
    virtual tColorSample Green() const { return m_g; }
    virtual tColorSample Blue() const { return m_b; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tSize Width() const { return m_width; }
    virtual tSize Height() const { return m_height; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tPixelImplement& Color() const {
        return (tPixelImplement&)m_color;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tColorSample m_r, m_g, m_b;
    tSize m_width, m_height;
    tPixel m_color;
};
typedef ColorT<> Color;

} // namespace surface
} // namespace graphic 
} // namespace imago 

#endif // _IMAGO_GRAPHIC_SURFACE_COLOR_HPP 
