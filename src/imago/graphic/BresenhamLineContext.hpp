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
///   File: BresenhamLineContext.hpp
///
/// Author: $author$
///   Date: 10/16/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_BRESENHAMLINECONTEXT_HPP
#define _IMAGO_GRAPHIC_BRESENHAMLINECONTEXT_HPP

#include "imago/graphic/ImageBase.hpp"

namespace imago {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: BresenhamLineContextT
///////////////////////////////////////////////////////////////////////
template
<class TBase = Base,
 class TExtends = TBase>

class _EXPORT_CLASS BresenhamLineContextT: public TExtends {
public:
    typedef TExtends Extends;

    typedef BresenhamLineContextT Derives;
    typedef bool (Derives::*MFinish)(tInt& x, tInt& y);
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BresenhamLineContextT(): m_finish(0) {
    }
    virtual ~BresenhamLineContextT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Start
    (tInt& x,tInt& y,tInt p_x1,tInt p_y1, tInt p_x2,tInt p_y2) {
        bool isTrue = false;

        x = (x1 = p_x1);
        y = (y1 = p_y1);
        x2 = p_x2;
        y2 = p_y2;

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

            if (y1 > y2) {
                if (x2 < x1) {
                    m_finish = &Derives::FinishMinusYminusX;
                } else {
                    m_finish = &Derives::FinishMinusYplusX;
                }
            } else {
                if (x2 < x1) {
                    m_finish = &Derives::FinishYminusX;
                } else {
                    m_finish = &Derives::FinishYplusX;
                }
            }
            isTrue = true;
        } else {
            d = 2*dy-dx;
            i1 = 2*dy;
            i2 = 2*(dy - dx);

            if (x1 > x2) {
                if (y2 < y1) {
                    m_finish = &Derives::FinishMinusXminusY;
                } else {
                    m_finish = &Derives::FinishMinusXplusY;
                }
            } else {
                if (y2 < y1) {
                    m_finish = &Derives::FinishXminusY;
                } else {
                    m_finish = &Derives::FinishXplusY;
                }
            }
            isTrue = true;
        }
        return isTrue;
    }
    virtual bool Finish(tInt& x, tInt& y) {
        bool isTrue = false;
        if (m_finish) {
            isTrue = (this->*m_finish)(x,y);
        }
        return isTrue;
    }
    virtual bool FinishYminusX(tInt& x, tInt& y) {
        bool isTrue = false;
        if ((isTrue = ((++y) <= y2))) {
            if (d < 0) {
                d += i1;
            } else {
                d += i2;
                --x;
            }
        }
        return isTrue;
    }
    virtual bool FinishYplusX(tInt& x, tInt& y) {
        bool isTrue = false;
        if ((isTrue = ((++y) <= y2))) {
            if (d < 0) {
                d += i1;
            } else {
                d += i2;
                x++;
            }
        }
        return isTrue;
    }
    virtual bool FinishXminusY(tInt& x, tInt& y) {
        bool isTrue = false;
        if ((isTrue = ((++x) <= x2))) {
            if (d < 0) {
                d += i1;
            } else {
                d += i2;
                --y;
            }
        }
        return isTrue;
    }
    virtual bool FinishXplusY(tInt& x, tInt& y) {
        bool isTrue = false;
        if ((isTrue = ((++x) <= x2))) {
            if (d < 0) {
                d += i1;
            } else {
                d += i2;
                y++;
            }
        }
        return isTrue;
    }
    virtual bool FinishMinusYminusX(tInt& x, tInt& y) {
        bool isTrue = false;
        if ((isTrue = ((--y) >= y2))) {
            if (d < 0) {
                d += i1;
            } else {
                d += i2;
                --x;
            }
        }
        return isTrue;
    }
    virtual bool FinishMinusYplusX(tInt& x, tInt& y) {
        bool isTrue = false;
        if ((isTrue = ((--y) >= y2))) {
            if (d < 0) {
                d += i1;
            } else {
                d += i2;
                x++;
            }
        }
        return isTrue;
    }
    virtual bool FinishMinusXminusY(tInt& x, tInt& y) {
        bool isTrue = false;
        if ((isTrue = ((--x) >= x2))) {
            if (d < 0) {
                d += i1;
            } else {
                d += i2;
                --y;
            }
        }
        return isTrue;
    }
    virtual bool FinishMinusXplusY(tInt& x, tInt& y) {
        bool isTrue = false;
        if ((isTrue = ((--x) >= x2))) {
            if (d < 0) {
                d += i1;
            } else {
                d += i2;
                y++;
            }
        }
        return isTrue;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    MFinish m_finish;
    tInt x1,y1,x2,y2,dx,dy,i1,i2,d;
};
typedef BresenhamLineContextT<> BresenhamLineContext;

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_BRESENHAMLINECONTEXT_HPP 
