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
///   File: BaseImage.hpp
///
/// Author: $author$
///   Date: 10/13/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_BASEIMAGE_HPP
#define _IMAGO_GRAPHIC_BASEIMAGE_HPP

#include "imago/graphic/ImageBase.hpp"
#include "imago/graphic/ColorSample.hpp"
#include "imago/graphic/Rectangle.hpp"
#include "imago/graphic/Circle.hpp"
#include "imago/graphic/Ellipse.hpp"

namespace imago {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: ImageImplementT
///////////////////////////////////////////////////////////////////////
template
<class TImageImplementBase = ImageImplementBase,
 class TColorSample = ColorSample,
 class TImplements = TImageImplementBase>

class _EXPORT_CLASS ImageImplementT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef ImageImplementT tImageImplement;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageImplement* CreateColor
    (tColorSample r, tColorSample g, tColorSample b, tColorSample a, tSize w = 1, tSize h = 1) {
        tImageImplement* image = 0;
        return image;
    }
    virtual tImageImplement* CreateColor
    (tColorSample r, tColorSample g, tColorSample b, tSize w = 1, tSize h = 1) {
        tImageImplement* image = 0;
        return image;
    }
    virtual bool Destroy(tImageImplement& image) {
        bool success = false;
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot(tImageImplement& image, tOffset x, tOffset y) {
        tImageImplement* prevImage = SelectImage(&image);
        Plot(x,y);
        SelectAsImage(prevImage);
    }
    virtual void Fill
    (tImageImplement& image, tOffset x, tOffset y, tSize w, tSize h) {
        tImageImplement* prevImage = SelectImage(&image);
        Fill(x,y, w,h);
        SelectAsImage(prevImage);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Plot(tOffset x, tOffset y) {
    }
    virtual void Fill(tOffset x, tOffset y, tSize w, tSize h) {
    }
    virtual void Draw(tOffset x, tOffset y, tOffset x2, tOffset y2) {
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void DrawCircle
    (tOffset x, tOffset y, tSize r, Octant o = OCTANT_ALL) {
    }
    virtual void FillCircle
    (tOffset x, tOffset y, tSize r, Octant o = OCTANT_ALL) {
    }
    virtual void HollowCircle
    (tOffset x, tOffset y, tSize r, Octant o = OCTANT_ALL) {
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void DrawEllipse
    (tOffset x, tOffset y, tSize w, tSize h, Quadrant q = QUADRANT_ALL) {
    }
    virtual void FillEllipse
    (tOffset x, tOffset y, tSize w, tSize h, Quadrant q = QUADRANT_ALL) {
    }
    virtual void HollowEllipse
    (tOffset x, tOffset y, tSize w, tSize h, Quadrant q = QUADRANT_ALL) {
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void DrawTriangle
    (tOffset x1, tOffset y1, tOffset x2, tOffset y2, tOffset x3, tOffset y3) {
        Draw(x1,y1, x2,y2);
        Draw(x2,y2, x3,y3);
        Draw(x3,y3, x1,y1);
    }
    virtual void FillTriangle
    (tOffset x1, tOffset y1, tOffset x2, tOffset y2, tOffset x3, tOffset y3) {
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void DrawRectangle
    (tOffset x, tOffset y, tSize w, tSize h) {
        Fill(x,y, w-1,1);
        Fill(x+w-1,y, 1,h-1);
        Fill(x+1,y+h-1, w-1,1);
        Fill(x,y+1, 1,h-1);
    }
    virtual void FillRectangle
    (tOffset x, tOffset y, tSize w, tSize h) {
        Fill(x,y, w,h);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void DrawRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize r) {
        DrawCircle(x,y, r, CIRCLE_QUADRANT_4);
        DrawCircle(x+w-1,y, r, CIRCLE_QUADRANT_1);
        DrawCircle(x+w-1,y+h-1, r, CIRCLE_QUADRANT_2);
        DrawCircle(x,y+h-1, r, CIRCLE_QUADRANT_3);
        if (2 < w) {
            Fill(x+1,y-r+1, w-2,1);
            Fill(x+1,y+h+r-1, w-2,1);
        }
        if (2 < h) {
            Fill(x-r+1,y, 1,h-2);
            Fill(x+w+r-1,y, 1,h-2);
        }
    }
    virtual void FillRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize r) {
        FillCircle(x,y, r, CIRCLE_QUADRANT_4);
        FillCircle(x+w-1,y, r, CIRCLE_QUADRANT_1);
        FillCircle(x+w-1,y+h-1, r, CIRCLE_QUADRANT_2);
        FillCircle(x,y+h-1, r, CIRCLE_QUADRANT_3);
        if (2 < w) {
            Fill(x+1,y-r+1, w-2,r);
            Fill(x+1,y+h-1, w-2,r);
        }
        if (2 < h) {
            Fill(x-r+1,y, w+r+r-2,h-2);
        }
    }
    virtual void HollowRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize r) {
        HollowCircle(x,y, r, CIRCLE_QUADRANT_4);
        HollowCircle(x+w-1,y, r, CIRCLE_QUADRANT_1);
        HollowCircle(x+w-1,y+h-1, r, CIRCLE_QUADRANT_2);
        HollowCircle(x,y+h-1, r, CIRCLE_QUADRANT_3);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void DrawEllipticalRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize rx, tSize ry) {
        DrawEllipse(x,y, rx,ry, CIRCLE_QUADRANT_4);
        DrawEllipse(x+w-1,y, rx,ry, CIRCLE_QUADRANT_1);
        DrawEllipse(x+w-1,y+h-1, rx,ry, CIRCLE_QUADRANT_2);
        DrawEllipse(x,y+h-1, rx,ry, CIRCLE_QUADRANT_3);
        if (2 < w) {
            Fill(x+1,y-ry+1, w-2,1);
            Fill(x+1,y+h+ry-1, w-2,1);
        }
        if (2 < h) {
            Fill(x-rx+1,y, 1,h-2);
            Fill(x+w+rx-1,y, 1,h-2);
        }
    }
    virtual void FillEllipticalRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize rx, tSize ry) {
        FillEllipse(x,y, rx,ry, CIRCLE_QUADRANT_4);
        FillEllipse(x+w-1,y, rx,ry, CIRCLE_QUADRANT_1);
        FillEllipse(x+w-1,y+h-1, rx,ry, CIRCLE_QUADRANT_2);
        FillEllipse(x,y+h-1, rx,ry, CIRCLE_QUADRANT_3);
        if (2 < w) {
            Fill(x+1,y-ry+1, w-2,ry);
            Fill(x+1,y+h-1, w-2,ry);
        }
        if (2 < h) {
            Fill(x-rx+1,y, w+rx+rx-2,h-2);
        }
    }
    virtual void HollowEllipticalRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize rx, tSize ry) {
        HollowEllipse(x,y, rx,ry, CIRCLE_QUADRANT_4);
        HollowEllipse(x+w-1,y, rx,ry, CIRCLE_QUADRANT_1);
        HollowEllipse(x+w-1,y+h-1, rx,ry, CIRCLE_QUADRANT_2);
        HollowEllipse(x,y+h-1, rx,ry, CIRCLE_QUADRANT_3);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void DrawRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize r,
     tSize thickness, RectangleCorner corner, RectangleSide side) {
        if ((RECTANGLE_CORNER_TOP_LEFT & corner))     DrawCircle(x,y, r, CIRCLE_QUADRANT_4);
        if ((RECTANGLE_CORNER_TOP_RIGHT & corner))    DrawCircle(x+w-1,y, r, CIRCLE_QUADRANT_1);
        if ((RECTANGLE_CORNER_BOTTOM_RIGHT & corner)) DrawCircle(x+w-1,y+h-1, r, CIRCLE_QUADRANT_2);
        if ((RECTANGLE_CORNER_BOTTOM_LEFT & corner))  DrawCircle(x,y+h-1, r, CIRCLE_QUADRANT_3);
        if ((RECTANGLE_SIDE_LEFT & side)) Fill(x-r+1,y, 1,h);
        if ((RECTANGLE_SIDE_TOP & side)) Fill(x,y-r+1, w,1);
        if ((RECTANGLE_SIDE_RIGHT & side)) Fill(x+w-1,y, 1,h);
        if ((RECTANGLE_SIDE_BOTTOM & side)) Fill(x,y+h-1, w,1);
    }
    virtual void FillRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize r,
     tSize thickness, RectangleCorner corner, RectangleSide side) {
        if ((RECTANGLE_CORNER_TOP_LEFT & corner))     FillCircle(x,y, r, CIRCLE_QUADRANT_4);
        if ((RECTANGLE_CORNER_TOP_RIGHT & corner))    FillCircle(x+w-1,y, r, CIRCLE_QUADRANT_1);
        if ((RECTANGLE_CORNER_BOTTOM_RIGHT & corner)) FillCircle(x+w-1,y+h-1, r, CIRCLE_QUADRANT_2);
        if ((RECTANGLE_CORNER_BOTTOM_LEFT & corner))  FillCircle(x,y+h-1, r, CIRCLE_QUADRANT_3);
        if ((RECTANGLE_SIDE_LEFT & side)) Fill(x-r+1,y, r,h);
        if ((RECTANGLE_SIDE_TOP & side)) Fill(x,y-r+1, w,r);
        if ((RECTANGLE_SIDE_RIGHT & side)) Fill(x+w-1,y, r,h);
        if ((RECTANGLE_SIDE_BOTTOM & side)) Fill(x,y+r+h-1, w,r);
    }
    virtual void HollowRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize r,
     tSize thickness, RectangleCorner corner, RectangleSide side) {
        if ((RECTANGLE_CORNER_TOP_LEFT & corner))     HollowCircle(x,y, r, CIRCLE_QUADRANT_4);
        if ((RECTANGLE_CORNER_TOP_RIGHT & corner))    HollowCircle(x+w-1,y, r, CIRCLE_QUADRANT_1);
        if ((RECTANGLE_CORNER_BOTTOM_RIGHT & corner)) HollowCircle(x+w-1,y+h-1, r, CIRCLE_QUADRANT_2);
        if ((RECTANGLE_CORNER_BOTTOM_LEFT & corner))  HollowCircle(x,y+h-1, r, CIRCLE_QUADRANT_3);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void DrawEllipticalRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize rx, tSize ry,
     tSize thickness, RectangleCorner corner, RectangleSide side) {
        if ((RECTANGLE_CORNER_TOP_LEFT & corner))     DrawEllipse(x,y, rx,ry, CIRCLE_QUADRANT_4);
        if ((RECTANGLE_CORNER_TOP_RIGHT & corner))    DrawEllipse(x+w-1,y, rx,ry, CIRCLE_QUADRANT_1);
        if ((RECTANGLE_CORNER_BOTTOM_RIGHT & corner)) DrawEllipse(x+w-1,y+h-1, rx,ry, CIRCLE_QUADRANT_2);
        if ((RECTANGLE_CORNER_BOTTOM_LEFT & corner))  DrawEllipse(x,y+h-1, rx,ry, CIRCLE_QUADRANT_3);
        if ((RECTANGLE_SIDE_LEFT & side)) Fill(x-rx+1,y, 1,h);
        if ((RECTANGLE_SIDE_TOP & side)) Fill(x,y-ry+1, w,1);
        if ((RECTANGLE_SIDE_RIGHT & side)) Fill(x+w-1,y, 1,h);
        if ((RECTANGLE_SIDE_BOTTOM & side)) Fill(x,y+ry+h-1, w,1);
    }
    virtual void FillEllipticalRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize rx, tSize ry,
     tSize thickness, RectangleCorner corner, RectangleSide side) {
        if ((RECTANGLE_CORNER_TOP_LEFT & corner))     FillEllipse(x,y, rx,ry, CIRCLE_QUADRANT_4);
        if ((RECTANGLE_CORNER_TOP_RIGHT & corner))    FillEllipse(x+w-1,y, rx,ry, CIRCLE_QUADRANT_1);
        if ((RECTANGLE_CORNER_BOTTOM_RIGHT & corner)) FillEllipse(x+w-1,y+h-1, rx,ry, CIRCLE_QUADRANT_2);
        if ((RECTANGLE_CORNER_BOTTOM_LEFT & corner))  FillEllipse(x,y+h-1, rx,ry, CIRCLE_QUADRANT_3);
        if ((RECTANGLE_SIDE_LEFT & side)) Fill(x-rx+1,y, rx,h);
        if ((RECTANGLE_SIDE_TOP & side)) Fill(x,y-ry+1, w,ry);
        if ((RECTANGLE_SIDE_RIGHT & side)) Fill(x+w-1,y, rx,h);
        if ((RECTANGLE_SIDE_BOTTOM & side)) Fill(x,y+h-1, w,ry);
    }
    virtual void HollowEllipticalRoundedRectangle
    (tOffset x, tOffset y, tSize w, tSize h, tSize rx, tSize ry,
     tSize thickness, RectangleCorner corner, RectangleSide side) {
        if ((RECTANGLE_CORNER_TOP_LEFT & corner))     HollowEllipse(x,y, rx,ry, CIRCLE_QUADRANT_4);
        if ((RECTANGLE_CORNER_TOP_RIGHT & corner))    HollowEllipse(x+w-1,y, rx,ry, CIRCLE_QUADRANT_1);
        if ((RECTANGLE_CORNER_BOTTOM_RIGHT & corner)) HollowEllipse(x+w-1,y+h-1, rx,ry, CIRCLE_QUADRANT_2);
        if ((RECTANGLE_CORNER_BOTTOM_LEFT & corner))  HollowEllipse(x,y+h-1, rx,ry, CIRCLE_QUADRANT_3);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageImplement* SelectAsImage(tImageImplement* image) {
        tImageImplement* prevImage = 0;
        if (image) {
            prevImage = image->SelectAsImage();
        } else {
            prevImage = SetImage(image);
        }
        return prevImage;
    }
    virtual tImageImplement* SelectAsImage() {
        tImageImplement* prevImage = Image();
        return prevImage;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageImplement* SetAsImage(tImageImplement* image) {
        tImageImplement* prevImage = 0;
        if (image) {
            prevImage = image->SetAsImage();
        } else {
            prevImage = Image();
        }
        return prevImage;
    }
    virtual tImageImplement* SetAsImage() {
        tImageImplement* prevImage = Image();
        return prevImage;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageImplement* SelectImage(tImageImplement* image) {
        tImageImplement* prevImage = Image();
        SetImage(image);
        return prevImage;
    }
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
};
typedef ImageImplementT<> ImageImplement;

///////////////////////////////////////////////////////////////////////
///  Class: BaseImageT
///////////////////////////////////////////////////////////////////////
template
<class TImageImplement = ImageImplement,
 class TBase = Base,
 class TExtends = TBase>

class _EXPORT_CLASS BaseImageT: public TExtends {
public:
    typedef TExtends Extends;

    typedef TImageImplement tImageImplement;
    typedef TBase tBase;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BaseImageT(tImageImplement& image): m_image(image) {
    }
    virtual ~BaseImageT() {
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
        m_image.Plot(x,y);
    }
    virtual void Fill(tOffset x, tOffset y, tSize w, tSize h) {
        m_image.Fill(x,y, w,h);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tImageImplement& m_image;
};
typedef BaseImageT<> BaseImage;

typedef ImageImplement SelectedImage;

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_BASEIMAGE_HPP 
