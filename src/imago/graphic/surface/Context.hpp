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
///   File: Context.hpp
///
/// Author: $author$
///   Date: 10/13/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_SURFACE_CONTEXT_HPP
#define _IMAGO_GRAPHIC_SURFACE_CONTEXT_HPP

#include "imago/graphic/surface/Pixel.hpp"

namespace imago {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: ContextImplementT
///////////////////////////////////////////////////////////////////////
template
<class TPixelImplement = PixelImplement,
 class TImplementBase = ImplementBase,
 class TColorSample = ColorSample,
 class TImplements = TImplementBase>
class _EXPORT_CLASS ContextImplementT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TPixelImplement tPixelImplement;
    typedef TImplementBase tImplementBase;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void FillRectangle
    (tOffset x, tOffset y, tSize width, tSize height) {
        const tPixelImplement *foregroundColor = Foreground();
        if ((foregroundColor)) {
            FillRectangle(x,y, width,height, *foregroundColor);
        }
    }
    virtual void FillRectangle
    (tOffset x, tOffset y, tSize width, tSize height, const tPixelImplement& color) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void SetForeground
    (const tPixelImplement*& oldColor, const tPixelImplement& toColor) {
    }
    virtual const tPixelImplement* Foreground() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void SetBackground
    (const tPixelImplement*& oldColor, const tPixelImplement& toColor) {
    }
    virtual const tPixelImplement* Background() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tPixelImplement* AllocateColor
    (tColorSample r, tColorSample g, tColorSample b, tColorSample a) {
        return 0;
    }
    virtual tPixelImplement* AllocateColor
    (tColorSample r, tColorSample g, tColorSample b) {
        return 0;
    }
    virtual bool FreeColor(tPixelImplement* color) {
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ContextImplementT<> ContextImplement;

///////////////////////////////////////////////////////////////////////
///  Class: ContextT
///////////////////////////////////////////////////////////////////////
template
<class TPixelImplement = PixelImplement,
 class TImplementBase = ContextImplement,
 class TBase = Base,
 class TColorSample = ColorSample,
 class TImplements = TImplementBase, class TExtends = TBase>
class _EXPORT_CLASS ContextT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TPixelImplement tPixelImplement;
    typedef TImplementBase tImplementBase;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ContextT(): m_foregroundColor(0), m_backgroundColor(0) {
    }
    virtual ~ContextT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void SetForeground
    (const tPixelImplement*& oldColor, const tPixelImplement& toColor) {
        oldColor = m_foregroundColor;
        m_foregroundColor = &toColor;
    }
    virtual const tPixelImplement* Foreground() const {
        return m_foregroundColor;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void SetBackground
    (const tPixelImplement*& oldColor, const tPixelImplement& toColor) {
        oldColor = m_backgroundColor;
        m_backgroundColor = &toColor;
    }
    virtual const tPixelImplement* Background() const {
        return m_backgroundColor;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const tPixelImplement *m_foregroundColor, *m_backgroundColor;
};
typedef ContextT<> Context;

} // namespace surface
} // namespace graphic 
} // namespace imago 

#endif // _IMAGO_GRAPHIC_SURFACE_CONTEXT_HPP 
