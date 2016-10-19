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
///   Date: 10/10/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_IMAGE_HPP
#define _IMAGO_GRAPHIC_IMAGE_HPP

#include "imago/graphic/BresenhamLineImage.hpp"
#include "imago/graphic/BresenhamTriangleImage.hpp"
#include "imago/graphic/MidpointCircleImage.hpp"
#include "imago/graphic/MidpointEllipseImage.hpp"

namespace imago {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: ImageT
///////////////////////////////////////////////////////////////////////
template
<class TImageImplement = ImageImplement,
 class TBase = Base,
 class TImplements = TImageImplement, class TExtends = TBase>

class _EXPORT_CLASS ImageT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TImageImplement tImageImplement;
    typedef TBase tBase;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ImageT(tImageImplement* image = 0): m_image(image) {
    }
    virtual ~ImageT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot(tImageImplement& image, tOffset x, tOffset y) {
        image.Plot(x,y);
    }
    virtual void Fill
    (tImageImplement& image, tOffset x, tOffset y, tSize w, tSize h) {
        image.Fill(x,y, w,h);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot(tOffset x, tOffset y) {
        tImageImplement* image;
        if ((image = Image())) {
            image->Plot(x, y);
        }
    }
    virtual void Fill(tOffset x, tOffset y, tSize w, tSize h) {
        tImageImplement* image;
        if ((image = Image())) {
            image->Fill(x,y, w,h);
        }
    }
    virtual void Draw(tOffset x, tOffset y, tOffset x2, tOffset y2) {
        tImageImplement* image;
        if ((image = Image())) {
            BresenhamLineImage line(*image);
            line.DrawLine(*image, x,y, x2,y2);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void DrawTriangle
    (tOffset x1, tOffset y1, tOffset x2, tOffset y2, tOffset x3, tOffset y3) {
        tImageImplement* image;
        if ((image = Image())) {
            BresenhamTriangleImage triangle(*image);
            triangle.DrawTriangle(*image, x1,y1, x2,y2, x3,y3);
        }
    }
    virtual void FillTriangle
    (tOffset x1, tOffset y1, tOffset x2, tOffset y2, tOffset x3, tOffset y3) {
        tImageImplement* image;
        if ((image = Image())) {
            FilledBresenhamTriangleImage triangle(*image);
            triangle.DrawTriangle(*image, x1,y1, x2,y2, x3,y3);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void DrawCircle
    (tOffset x, tOffset y, tSize r, Octant o = OCTANT_ALL) {
        tImageImplement* image;
        if ((image = Image())) {
            MidpointCircleImage circle(*image);
            circle.PlotCircle(*image, x,y, r, o);
        }
    }
    virtual void FillCircle
    (tOffset x, tOffset y, tSize r, Octant o = OCTANT_ALL) {
        tImageImplement* image;
        if ((image = Image())) {
            FilledMidpointCircleImage circle(*image);
            circle.PlotCircle(*image, x,y, r, o);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void DrawEllipse
    (tOffset x, tOffset y, tSize w, tSize h, Quadrant q = QUADRANT_ALL) {
        tImageImplement* image;
        if ((image = Image())) {
            MidpointEllipseImage ellipse(*image);
            ellipse.PlotEllipse(*image, x,y, w,h, q);
        }
    }
    virtual void FillEllipse
    (tOffset x, tOffset y, tSize w, tSize h, Quadrant q = QUADRANT_ALL) {
        tImageImplement* image;
        if ((image = Image())) {
            FilledMidpointEllipseImage ellipse(*image);
            ellipse.PlotEllipse(*image, x,y, w,h, q);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageImplement* SetImage(tImageImplement* image) {
        tImageImplement* prevImage = m_image;
        m_image = image;
        return prevImage;
    }
    virtual tImageImplement* Image() const {
        tImageImplement* image = m_image;
        return image;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tImageImplement* m_image;
};
typedef ImageT<> Image;

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_IMAGE_HPP 
