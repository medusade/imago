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
///   File: Pixel.hpp
///
/// Author: $author$
///   Date: 10/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_SURFACE_PIXEL_HPP
#define _IMAGO_GRAPHIC_SURFACE_PIXEL_HPP

#include "imago/graphic/ColorSample.hpp"

namespace imago {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: PixelImplementT
///////////////////////////////////////////////////////////////////////
template
<class TImplementBase = ImplementBase,
 class TColorSample = ColorSample,
 class TImplements = TImplementBase>
class _EXPORT_CLASS PixelImplementT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef PixelImplementT<> PixelImplement;

///////////////////////////////////////////////////////////////////////
///  Class: PixelT
///////////////////////////////////////////////////////////////////////
template
<class TImplementBase = PixelImplement,
 class TBase = Base,
 class TColorSample = ColorSample,
 class TImplements = TImplementBase, class TExtends = TBase>
class _EXPORT_CLASS PixelT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    PixelT(tColorSample r, tColorSample g, tColorSample b, tColorSample a) {
    }
    PixelT(tColorSample r, tColorSample g, tColorSample b) {
    }
    virtual ~PixelT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef PixelT<> Pixel;

} // namespace surface 
} // namespace graphic 
} // namespace imago 

#endif // _IMAGO_GRAPHIC_SURFACE_PIXEL_HPP 
