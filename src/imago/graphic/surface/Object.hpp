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
///   File: Object.hpp
///
/// Author: $author$
///   Date: 10/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_SURFACE_OBJECT_HPP
#define _IMAGO_GRAPHIC_SURFACE_OBJECT_HPP

#include "imago/graphic/surface/Image.hpp"
#include "imago/graphic/ImageObject.hpp"
#include "imago/graphic/Image.hpp"

namespace imago {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: ObjectT
///////////////////////////////////////////////////////////////////////
template
<class TImageObject = ImageObject,
 class TImageImplement = ImageImplement,
 class TImageImplementBase = ImageImplementBase,
 class TSelectedImage = SelectedImage,
 class TColorSample = ColorSample,
 class TExtends = TImageObject>

class _EXPORT_CLASS ObjectT: public TExtends {
public:
    typedef TExtends Extends;

    typedef TImageObject tImageObject;
    typedef TImageImplement tImageImplement;
    typedef TImageImplementBase tImageImplementBase;
    typedef TSelectedImage tSelectedImage;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ObjectT(tImageImplement &surfaceImage, tSize width = 0, tSize height = 0)
    : Extends(surfaceImage, width, height), m_surfaceImage(surfaceImage) {
    }
    virtual ~ObjectT() {
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tSelectedImage* SurfaceSelectImage(tSelectedImage* image) {
        return m_surfaceImage.SelectImage(image);
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tImageImplement &m_surfaceImage;
};
typedef ObjectT<> Object;

} // namespace surface 
} // namespace graphic 
} // namespace imago 

#endif // _IMAGO_GRAPHIC_SURFACE_OBJECT_HPP 
