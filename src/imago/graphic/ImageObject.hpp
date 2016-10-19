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
///   File: ImageObject.hpp
///
/// Author: $author$
///   Date: 10/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_IMAGEOBJECT_HPP
#define _IMAGO_GRAPHIC_IMAGEOBJECT_HPP

#include "imago/graphic/Image.hpp"

namespace imago {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: ImageObjectImplementT
///////////////////////////////////////////////////////////////////////
template
<class TImageImplement = ImageImplement,
 class TColorSample = ColorSample,
 class TImplements = TImageImplement>

class _EXPORT_CLASS ImageObjectImplementT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TImageImplement tImageImplement;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageImplement* SelectAsImage() {
        tImageImplement* prevImage = 0;
        return prevImage;
    }
    virtual tImageImplement* SetAsImage() {
        tImageImplement* prevImage = 0;
        return prevImage;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageImplement* SetImage(tImageImplement* image) {
        tImageImplement* prevImage = 0;
        return prevImage;
    }
    virtual tImageImplement* Image() const {
        tImageImplement* image = 0;
        return image;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void SetSize(tSize width, tSize height) {
    }
    virtual void OnSetSize
    (tSize width, tSize height, tSize prevWidth, tSize prevHeight) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tSize Width() const {
        return 0;
    }
    virtual tSize Height() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ImageObjectImplementT<> ImageObjectImplement;

///////////////////////////////////////////////////////////////////////
///  Class: ImageObjectT
///////////////////////////////////////////////////////////////////////
template
<class TImageImplement = ImageImplement,
 class TImageObjectImplement = ImageObjectImplement,
 class TImageObjectExtend = Base,
 class TColorSample = ColorSample,
 class TImplements = TImageObjectImplement, class TExtends = TImageObjectExtend>

class _EXPORT_CLASS ImageObjectT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TImageImplement tImageImplement;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ImageObjectT
    (tImageImplement &image,
     tSize width = 0, tSize height = 0,
     tImageImplement *selectedImage = 0)
     : m_image(image), m_selectedImage(selectedImage),
       m_width(width), m_height(height) {
    }
    virtual ~ImageObjectT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageImplement* SelectAsImage() {
        tImageImplement* prevImage = m_image.SelectImage(this);
        return prevImage;
    }
    virtual tImageImplement* SetAsImage() {
        tImageImplement* prevImage = m_image.SetImage(this);
        return prevImage;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageImplement* SetImage(tImageImplement* image) {
        tImageImplement* prevImage = Image();
        m_selectedImage = image;
        return prevImage;
    }
    virtual tImageImplement* Image() const {
        tImageImplement* image = m_selectedImage;
        return image;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void SetSize(tSize width, tSize height) {
        tSize prevWidth = m_width, prevHeight = m_height;
        m_width = width; m_height = height;
        OnSetSize(width,height, prevWidth,prevHeight);
    }
    virtual void OnSetSize
    (tSize width, tSize height, tSize prevWidth, tSize prevHeight) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tSize Width() const {
        return m_width;
    }
    virtual tSize Height() const {
        return m_height;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tImageImplement &m_image, *m_selectedImage;
    tSize m_width, m_height;
};
typedef ImageObjectT<> ImageObject;

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_IMAGEOBJECT_HPP 
