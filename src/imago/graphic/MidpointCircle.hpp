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
///   File: MidpointCircle.hpp
///
/// Author: $author$
///   Date: 10/17/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_MIDPOINTCIRCLE_HPP
#define _IMAGO_GRAPHIC_MIDPOINTCIRCLE_HPP

#include "imago/graphic/ImageBase.hpp"
#include "imago/graphic/Circle.hpp"

namespace imago {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Function: DrawMidpointCircleT
///////////////////////////////////////////////////////////////////////
template
<class TImage, class TPixel, class TInt>

void DrawMidpointCircleT
(TImage &image, TPixel &pixel,
 TInt cx, TInt cy, TInt r, CircleOctant o = CIRCLE_OCTANT_ALL) {
    TInt x, y, d;
    if (1 == r) {
        image.CirclePlot(pixel, r, cx,cy, o);
    } else if (0 < (y = --r)) {
        d = 1-r;
        for (x = 0; x < y; x++) {
            image.CirclePlot(pixel, r, cx,cy, x,y, o);
            if (d<0) {
                d += 2*x+3;
            } else {
                d += 2*(x-y)+5;
                --y;
            }
        }
        image.CirclePlot(pixel, r, cx,cy, x,y, o);
    }
}

///////////////////////////////////////////////////////////////////////
///  Class: MidpointCircleT
///////////////////////////////////////////////////////////////////////
template
<class TImageBase = ImageBase,
 class TImageImplementBase = ImageImplementBase,
 class TImage = TImageImplementBase,
 class TPixel = TImageImplementBase,
 class TExtends = TImageBase>

class _EXPORT_CLASS MidpointCircleT: public TExtends {
public:
    typedef TExtends Extends;
    typedef MidpointCircleT Derives;

    typedef TImageImplementBase tImageImplementBase;
    typedef TImageBase tImageBase;
    typedef TImage tImage;
    typedef TPixel tPixel;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MidpointCircleT(tImageImplementBase& image): Extends(image) {
    }
    virtual ~MidpointCircleT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void CirclePlot
    (TPixel &pixel, tInt r,
     tInt cx,tInt cy, CircleOctant o = CIRCLE_OCTANT_ALL) {
        this->Plot(pixel, cx, cy);
    }
    virtual void CirclePlot
    (TPixel &pixel, tInt r, tInt cx,tInt cy,
     tInt x,tInt y, CircleOctant o = CIRCLE_OCTANT_ALL) {
        if (o != CIRCLE_OCTANT_ALL) {
            if (o & CIRCLE_OCTANT_8) this->Plot(pixel, cx-x, cy-y);
            if (o & CIRCLE_OCTANT_1) this->Plot(pixel, cx+x, cy-y);

            if (o & CIRCLE_OCTANT_7) this->Plot(pixel, cx-y, cy-x);
            if (o & CIRCLE_OCTANT_2) this->Plot(pixel, cx+y, cy-x);

            if (o & CIRCLE_OCTANT_6) this->Plot(pixel, cx-y, cy+x);
            if (o & CIRCLE_OCTANT_3) this->Plot(pixel, cx+y, cy+x);

            if (o & CIRCLE_OCTANT_5) this->Plot(pixel, cx-x, cy+y);
            if (o & CIRCLE_OCTANT_4) this->Plot(pixel, cx+x, cy+y);
        } else {
            this->Plot(pixel, cx-x, cy-y);
            this->Plot(pixel, cx+x, cy-y);

            this->Plot(pixel, cx-y, cy-x);
            this->Plot(pixel, cx+y, cy-x);

            this->Plot(pixel, cx-y, cy+x);
            this->Plot(pixel, cx+y, cy+x);

            this->Plot(pixel, cx-x, cy+y);
            this->Plot(pixel, cx+x, cy+y);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PlotCircle
    (tPixel &pixel, tInt cx,tInt cy,
     tInt r, CircleOctant o = CIRCLE_OCTANT_ALL) {
        DrawMidpointCircleT<Derives, tPixel, tInt>
        (*this, pixel, cx,cy,r, o);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MidpointCircleT<> MidpointCircle;

///////////////////////////////////////////////////////////////////////
///  Class: FilledMidpointCircleT
///////////////////////////////////////////////////////////////////////
template
<class TImageBase = ImageBase,
 class TImageImplementBase = ImageImplementBase,
 class TImage = TImageImplementBase,
 class TPixel = TImageImplementBase,
 class TExtends = TImageBase>

class _EXPORT_CLASS FilledMidpointCircleT: public TExtends {
public:
    typedef TExtends Extends;
    typedef FilledMidpointCircleT Derives;

    typedef TImageImplementBase tImageImplementBase;
    typedef TImageBase tImageBase;
    typedef TImage tImage;
    typedef TPixel tPixel;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    FilledMidpointCircleT(tImageImplementBase& image): Extends(image) {
    }
    virtual ~FilledMidpointCircleT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void CirclePlot
    (TPixel &pixel, tInt r,
     tInt cx,tInt cy, CircleOctant o = CIRCLE_OCTANT_ALL) {
        this->Plot(pixel, cx, cy);
    }
    virtual void CirclePlot
    (TPixel &pixel, tInt r, tInt cx,tInt cy,
     tInt x,tInt y, CircleOctant o = CIRCLE_OCTANT_ALL) {
        if (o != CIRCLE_OCTANT_ALL) {
            if ((o & CIRCLE_QUADRANT_4) == CIRCLE_QUADRANT_4) {
                this->Fill(pixel, cx-x, cy-y, x+1, 1);
                this->Fill(pixel, cx-y, cy-x, y+1, 1);
            }
            if ((o & CIRCLE_QUADRANT_1) == CIRCLE_QUADRANT_1) {
                this->Fill(pixel, cx, cy-y, x+1, 1);
                this->Fill(pixel, cx, cy-x, y+1, 1);
            }
            if ((o & CIRCLE_QUADRANT_3) == CIRCLE_QUADRANT_3) {
                this->Fill(pixel, cx-y, cy+x, y+1, 1);
                this->Fill(pixel, cx-x, cy+y, x+1, 1);
            }
            if ((o & CIRCLE_QUADRANT_2) == CIRCLE_QUADRANT_2) {
                this->Fill(pixel, cx, cy+x, y+1, 1);
                this->Fill(pixel, cx, cy+y, x+1, 1);
            }
        } else {
            if (1 > x) {
                this->Plot(pixel, cx, cy-y);
            } else {
                this->Fill(pixel, cx-x, cy-y, x+x+1, 1);
            }

            if (1 > y) {
                this->Plot(pixel, cx, cy-x);
            } else {
                this->Fill(pixel, cx-y, cy-x, y+y+1, 1);
            }

            if (1 > y) {
                this->Plot(pixel, cx, cy+x);
            } else {
                this->Fill(pixel, cx-y, cy+x, y+y+1, 1);
            }

            if (1 > x) {
                this->Plot(pixel, cx, cy+y);
            } else {
                this->Fill(pixel, cx-x, cy+y, x+x+1, 1);
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void PlotCircle
    (tPixel &pixel, tInt cx,tInt cy,
     tInt r, CircleOctant o = CIRCLE_OCTANT_ALL) {
        DrawMidpointCircleT<Derives, tPixel, tInt>
        (*this, pixel, cx,cy,r, o);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef FilledMidpointCircleT<> FilledMidpointCircle;

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_MIDPOINTCIRCLE_HPP 
