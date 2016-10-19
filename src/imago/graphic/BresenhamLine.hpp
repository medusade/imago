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
///   File: BresenhamLine.hpp
///
/// Author: $author$
///   Date: 10/13/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_BRESENHAMLINE_HPP
#define _IMAGO_GRAPHIC_BRESENHAMLINE_HPP

#include "imago/graphic/ImageBase.hpp"

namespace imago {
namespace graphic {

///////////////////////////////////////////////////////////////////////
/// Function: DrawBresenhamLineT
///////////////////////////////////////////////////////////////////////
template <class TImage, class TPixel, class TInt>

void DrawBresenhamLineT
(TImage &image, TPixel &pixel, TInt x1, TInt y1, TInt x2, TInt y2) {
    TInt dx,dy,i1,i2,d,x,y;

    x = x1;
    y = y1;

    if (0 > (dx = x2-x1)) {
        dx = -dx;
    }
    if (0 > (dy = y2-y1)) {
        dy = -dy;
    }

    if (dx < dy) {
        d = 2*dx-dy;
        i1 = 2*dx;
        i2 = 2*(dx - dy);

        image.Plot(pixel, x, y);

        if (y1 > y2) {
            if (x1 > x2) {
                while ((((--y) >= y2))) {
                    if (d < 0) {
                        d += i1;
                    } else {
                        d += i2;
                        --x;
                    }
                    image.Plot(pixel, x, y);
                }
            } else {
                while ((((--y) >= y2))) {
                    if (d < 0) {
                        d += i1;
                    } else {
                        d += i2;
                        x++;
                    }
                    image.Plot(pixel, x, y);
                }
            }
        } else {
            if (x1 > x2) {
                while ((((++y) <= y2))) {
                    if (d < 0) {
                        d += i1;
                    } else {
                        d += i2;
                        --x;
                    }
                    image.Plot(pixel, x, y);
                }
            } else {
                while ((((++y) <= y2))) {
                    if (d < 0) {
                        d += i1;
                    } else {
                        d += i2;
                        x++;
                    }
                    image.Plot(pixel, x, y);
                }
            }
        }
    } else {
        d = 2*dy-dx;
        i1 = 2*dy;
        i2 = 2*(dy - dx);

        image.Plot(pixel, x, y);

        if (x1 > x2) {
            if (y1 > y2) {
                while ((((--x) >= x2))) {
                    if (d < 0) {
                        d += i1;
                    } else {
                        d += i2;
                        --y;
                    }
                    image.Plot(pixel, x, y);
                }
            } else {
                while ((((--x) >= x2))) {
                    if (d < 0) {
                        d += i1;
                    } else {
                        d += i2;
                        y++;
                    }
                    image.Plot(pixel, x, y);
                }
            }
        } else {
            if (y1 > y2) {
                while ((((++x) <= x2))) {
                    if (d < 0) {
                        d += i1;
                    } else {
                        d += i2;
                        --y;
                    }
                    image.Plot(pixel, x, y);
                }
            } else {
                while ((((++x) <= x2))) {
                    if (d < 0) {
                        d += i1;
                    } else {
                        d += i2;
                        y++;
                    }
                    image.Plot(pixel, x, y);
                }
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////
///  Class: BresenhamLineT
///////////////////////////////////////////////////////////////////////
template
<class TImageBase = ImageBase,
 class TImageImplementBase = ImageImplementBase,
 class TImage = TImageImplementBase,
 class TPixel = TImageImplementBase,
 class TExtends = TImageBase>

class _EXPORT_CLASS BresenhamLineT: public TExtends {
public:
    typedef TExtends Extends;

    typedef TImageImplementBase tImageImplementBase;
    typedef TImageBase tImageBase;
    typedef TImage tImage;
    typedef TPixel tPixel;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BresenhamLineT(tImageImplementBase& image): Extends(image) {
    }
    virtual ~BresenhamLineT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void DrawLine(tPixel &pixel, tInt x1,tInt y1, tInt x2,tInt y2) {
        DrawBresenhamLineT<Extends, tPixel, tInt>
        (*this, pixel, x1,y1, x2,y2);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef BresenhamLineT<> BresenhamLine;

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_BRESENHAMLINE_HPP 
