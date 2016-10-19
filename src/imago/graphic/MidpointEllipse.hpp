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
///   File: MidpointEllipse.hpp
///
/// Author: $author$
///   Date: 10/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_MIDPOINTELLIPSE_HPP
#define _IMAGO_GRAPHIC_MIDPOINTELLIPSE_HPP

#include "imago/graphic/ImageBase.hpp"
#include "imago/graphic/Ellipse.hpp"

namespace imago {
namespace graphic {

///////////////////////////////////////////////////////////////////////
/// Function: DrawMidpointEllipseT
///////////////////////////////////////////////////////////////////////
template <class TImage, class TPixel, class TInt>

void DrawMidpointEllipseT
(TImage &image, TPixel &pixel,
 TInt cx, TInt cy, TInt a, TInt b,
 EllipseQuadrant q = ELLIPSE_QUADRANT_ALL) {
    TInt x, y, a2, b2, S, T;

    if ((1 == a) && (1 == b)) {
        image.Plot(pixel, cx,cy);
    }
    else if ((1 == a) && (1 < b)) {
            image.Fill(pixel, cx,cy-b+1, 1,b+b-1);
    }
    else if ((1 < a) && (1 == b)) {
            image.Fill(pixel, cx-a+1,cy, a+a-1,1);
    }
    else if ((0 < --a) && (0 < --b)) {
        a2 = a*a;
        b2 = b*b;
        x = 0;
        y = b;
        S = a2*(1-2*b) + 2*b2;
        T = b2 - 2*a2*(2*b-1);

        image.EllipsePlot(pixel, a,b, cx,cy, x,y, q);

        do {
            if (S<0) {
                S += 2*b2*(2*x+3);
                T += 4*b2*(x+1);
                x++;
            }
            else if (T<0) {
                S += 2*b2*(2*x+3) - 4*a2*(y-1);
                T += 4*b2*(x+1) - 2*a2*(2*y-3);
                x++;
                y--;
            }
            else {
                S -= 4*a2*(y-1);
                T -= 2*a2*(2*y-3);
                y--;
            }

            image.EllipsePlot(pixel, a,b, cx,cy, x,y, q);
        } while (y>0);
    }
}

///////////////////////////////////////////////////////////////////////
///  Class: MidpointEllipseT
///////////////////////////////////////////////////////////////////////
template
<class TImageBase = ImageBase,
 class TImageImplementBase = ImageImplementBase,
 class TImage = TImageImplementBase,
 class TPixel = TImageImplementBase,
 class TExtends = TImageBase>

class _EXPORT_CLASS MidpointEllipseT: public TExtends {
public:
    typedef TExtends Extends;
    typedef MidpointEllipseT Derives;

    typedef TImageBase tImageBase;
    typedef TImageImplementBase tImageImplementBase;
    typedef TImage tImage;
    typedef TPixel tPixel;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MidpointEllipseT(tImage& image): Extends(image) {
    }
    virtual ~MidpointEllipseT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void EllipsePlot
    (tPixel &pixel, tInt a,tInt b, tInt cx,tInt cy, tInt x,tInt y,
     EllipseQuadrant q = ELLIPSE_QUADRANT_ALL) {
        if (q != ELLIPSE_QUADRANT_ALL) {
            if (q & ELLIPSE_QUADRANT_1) {
                this->Plot(pixel, cx + x, cy - y);
            }
            if (q & ELLIPSE_QUADRANT_2) {
                this->Plot(pixel, cx + x, cy + y);
            }
            if (q & ELLIPSE_QUADRANT_3) {
                this->Plot(pixel, cx - x, cy + y);
            }
            if (q & ELLIPSE_QUADRANT_4) {
                this->Plot(pixel, cx - x, cy - y);
            }
        }
        else {
            this->Plot(pixel, cx + x, cy + y);
            this->Plot(pixel, cx - x, cy - y);
            this->Plot(pixel, cx + x, cy - y);
            this->Plot(pixel, cx - x, cy + y);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PlotEllipse
    (tPixel &pixel, tInt cx,tInt cy, tInt a,tInt b,
     EllipseQuadrant q = ELLIPSE_QUADRANT_ALL) {
        DrawMidpointEllipseT<Derives, tPixel, tInt>
        (*this, pixel, cx,cy, a,b, q);
    }
    virtual void PlotCircle
    (tPixel &pixel, tInt cx,tInt cy, tInt r,
     EllipseQuadrant q = ELLIPSE_QUADRANT_ALL) {
        DrawMidpointEllipseT<Derives, tPixel, tInt>
        (*this, pixel, cx,cy, r,r, q);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MidpointEllipseT<> MidpointEllipse;

///////////////////////////////////////////////////////////////////////
///  Class: FilledMidpointEllipseT
///////////////////////////////////////////////////////////////////////
template
<class TImageBase = ImageBase,
 class TImageImplementBase = ImageImplementBase,
 class TImage = TImageImplementBase,
 class TPixel = TImageImplementBase,
 class TExtends = TImageBase>

class _EXPORT_CLASS FilledMidpointEllipseT: public TExtends {
public:
    typedef TExtends Extends;
    typedef FilledMidpointEllipseT Derives;

    typedef TImageBase tImageBase;
    typedef TImageImplementBase tImageImplementBase;
    typedef TImage tImage;
    typedef TPixel tPixel;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    FilledMidpointEllipseT(tImage& image): Extends(image) {
    }
    virtual ~FilledMidpointEllipseT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void EllipsePlot
    (tPixel &pixel, tInt a,tInt b, tInt cx,tInt cy, tInt x,tInt y,
     EllipseQuadrant q = ELLIPSE_QUADRANT_ALL) {
        if (q != ELLIPSE_QUADRANT_ALL) {
            if (q & ELLIPSE_QUADRANT_1) {
                this->Fill(pixel, cx, cy - y, x+1, 1);
            }
            if (q & ELLIPSE_QUADRANT_2) {
                this->Fill(pixel, cx, cy + y, x+1, 1);
            }
            if (q & ELLIPSE_QUADRANT_3) {
                this->Fill(pixel, cx - x, cy + y, x+1, 1);
            }
            if (q & ELLIPSE_QUADRANT_4) {
                this->Fill(pixel, cx - x, cy - y, x+1, 1);
            }
        } else {
            this->Fill(pixel, cx - x, cy + y, x+x+1, 1);
            this->Fill(pixel, cx - x, cy - y, x+x+1, 1);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PlotEllipse
    (tPixel &pixel, tInt cx,tInt cy, tInt a,tInt b,
     EllipseQuadrant q = ELLIPSE_QUADRANT_ALL) {
        DrawMidpointEllipseT<Derives, tPixel, tInt>
        (*this, pixel, cx,cy, a,b, q);
    }
    virtual void PlotCircle
    (tPixel &pixel, tInt cx,tInt cy, tInt r,
     EllipseQuadrant q = ELLIPSE_QUADRANT_ALL) {
        DrawMidpointEllipseT<Derives, tPixel, tInt>
        (*this, pixel, cx,cy, r,r, q);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef FilledMidpointEllipseT<> FilledMidpointEllipse;

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_MIDPOINTELLIPSE_HPP 
