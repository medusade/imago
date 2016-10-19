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
///   File: ImagePoint.hpp
///
/// Author: $author$
///   Date: 10/16/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_IMAGEPOINT_HPP
#define _IMAGO_GRAPHIC_IMAGEPOINT_HPP

#include "imago/graphic/ImageBase.hpp"
#include "xos/base/array.hpp"

namespace imago {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: ImagePointT
///////////////////////////////////////////////////////////////////////
template
<class TBase = Base,
 class TExtends = TBase>

class _EXPORT_CLASS ImagePointT: public TExtends {
public:
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ImagePointT(tInt x, tInt y)
    : m_x(x), m_y(y) {
    }
    ImagePointT(const ImagePointT& copy)
    : m_x(copy.m_x), m_y(copy.m_y) {
    }
    ImagePointT()
    : m_x(0), m_y(0) {
    }
    virtual ~ImagePointT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare(const ImagePointT& toPoint) const  {
        int unequal = 0;
        if (m_y > toPoint.m_y)
            unequal = 1;
        else
        if (m_y < toPoint.m_y)
            unequal = -1;
        else
        if (m_x > toPoint.m_x)
            unequal = 1;
        else
        if (m_x < toPoint.m_x)
            unequal = -1;
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
public:
    tInt m_x, m_y;
};
typedef ImagePointT<> ImagePoint;

///////////////////////////////////////////////////////////////////////
///  Class: ImagePointArrayT
///////////////////////////////////////////////////////////////////////
template
<class TWhat = ImagePoint,
 tSize VSize = XOS_ARRAY_DEFAULT_SIZE,
 class TArray = xos::base::arrayt<TWhat, tSize, VSize>,
 class TExtends = TArray>

class _EXPORT_CLASS ImagePointArrayT: public TExtends {
public:
    typedef TExtends Extends;

    typedef TWhat tWhat;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tLength QSort() {
        tLength count = this->length();
        if (0 < (count))
            this->QSort(0, count-1);
        return count;
    }
    virtual void QSort(tSize iFirst, tSize iLast) {
        tSize iNext, iPrev;
        if (iFirst < iLast) {
            if (iLast-iFirst>1) {
                for (iNext=iFirst, iPrev=iLast-1; iNext<iPrev;) {
                    for (;iNext<=iPrev; iNext++) {
                        if (Compare(iNext, iLast)>0)
                            break;
                    }
                    for (;iPrev>iNext; iPrev--) {
                        if (Compare(iPrev,iLast)<0) {
                            Swap(iNext++, iPrev--);
                            break;
                        }
                    }
                }
                if (iNext<iLast) {
                    Swap(iNext, iLast);
                    QSort(iNext+1, iLast);
                }
                if (iNext > iFirst)
                    QSort(iFirst, iNext-1);
            } else {
                if (Compare(iFirst, iLast)>0)
                    Swap(iFirst, iLast);
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Compare(tSize iFirst, tSize iLast) const {
        int unequal = 0;
        if ((iFirst >= 0) && (iLast < this->length_))
            unequal = this->elements_[iFirst].Compare(this->elements_[iLast]);
        return unequal;
    }
    virtual void Swap(tSize iFirst, tSize iLast) {
        tWhat temp = this->elements_[iFirst];
        this->elements_[iFirst] = this->elements_[iLast];
        this->elements_[iLast] = temp;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tWhat* Points(tLength& pointsSize, tLength& pointsLength) const {
        tWhat* points = this->elements();
        pointsSize = this->size();
        pointsLength = this->length();
        return points;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ImagePointArrayT<> ImagePointArray;

///////////////////////////////////////////////////////////////////////
///  Class: ImagePointTriangleT
///////////////////////////////////////////////////////////////////////
template
<class TWhat = ImagePoint,
 class TArray = ImagePointArrayT<TWhat, 3>,
 class TExtends = TArray>

class _EXPORT_CLASS ImagePointTriangleT: public TExtends {
public:
    typedef TExtends Extends;

    typedef TWhat tWhat;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ImagePointTriangleT(tInt x1,tInt y1, tInt x2,tInt y2, tInt x3,tInt y3) {
        this->elements_[0].m_x = x1;
        this->elements_[0].m_y = y1;
        this->elements_[1].m_x = x2;
        this->elements_[1].m_y = y2;
        this->elements_[2].m_x = x3;
        this->elements_[2].m_y = y3;
        this->size_ = (this->length_ = 3);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ImagePointTriangleT<> ImagePointTriangle;

///////////////////////////////////////////////////////////////////////
///  Class: SortedImagePointTriangleT
///////////////////////////////////////////////////////////////////////
template
<class TWhat = ImagePoint,
 class TArray = ImagePointTriangleT<TWhat>,
 class TExtends = TArray>

class _EXPORT_CLASS SortedImagePointTriangleT: public TExtends {
public:
    typedef TExtends Extends;

    typedef TWhat tWhat;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    SortedImagePointTriangleT
    (tInt x1,tInt y1, tInt x2,tInt y2, tInt x3,tInt y3)
    : Extends(x1,y1, x2,y2, x3,y3) {
        this->QSort();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef SortedImagePointTriangleT<> SortedImagePointTriangle;

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_IMAGEPOINT_HPP 

