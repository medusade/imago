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
///   File: Image.hpp
///
/// Author: $author$
///   Date: 10/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_SURFACE_IMAGE_HPP
#define _IMAGO_GRAPHIC_SURFACE_IMAGE_HPP

#include "imago/graphic/surface/Context.hpp"
#include "imago/graphic/Image.hpp"

namespace imago {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: ImageImplementT
///////////////////////////////////////////////////////////////////////
template
<class TImageImplement = graphic::ImageImplement,
 class TContextImplement = ContextImplement,
 class TColorSample = ColorSample,
 class TImplements = TImageImplement>

class _EXPORT_CLASS ImageImplementT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TContextImplement tContextImplement;
    typedef TColorSample tColorSample;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tContextImplement& ContextImplement() const = 0;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ImageImplementT<> ImageImplement;

///////////////////////////////////////////////////////////////////////
///  Class: ImageT
///////////////////////////////////////////////////////////////////////
template
<class TImageImplement = ImageImplement,
 class TImage = graphic::Image,
 class TContextImplement = ContextImplement,
 class TColorSample = ColorSample,
 class TImplements = TImageImplement, class TExtends = TImage>

class _EXPORT_CLASS ImageT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TImageImplement tImageImplement;
    typedef TImage tImage;
    typedef TContextImplement tContextImplement;
    typedef TColorSample tColorSample;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ImageT(tContextImplement& context, tImageImplement* image = 0)
    : Extends(image), m_context(context) {
    }
    virtual ~ImageT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tContextImplement& ContextImplement() const {
        return (tContextImplement&)m_context;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tContextImplement& m_context;
};
typedef ImageT<> Image;

} // namespace surface
} // namespace graphic 
} // namespace imago 

#endif // _IMAGO_GRAPHIC_SURFACE_IMAGE_HPP 
