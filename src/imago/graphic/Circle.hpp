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
///   File: Circle.hpp
///
/// Author: $author$
///   Date: 10/10/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_CIRCLE_HPP
#define _IMAGO_GRAPHIC_CIRCLE_HPP

#include "imago/base/Base.hpp"

namespace imago {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef unsigned int CircleOctant;
enum {
    CIRCLE_OCTANT_NONE = 0,

    CIRCLE_OCTANT_1 = (1 << 0),
    CIRCLE_OCTANT_2 = (1 << 1),
    CIRCLE_OCTANT_3 = (1 << 2),
    CIRCLE_OCTANT_4 = (1 << 3),
    CIRCLE_OCTANT_5 = (1 << 4),
    CIRCLE_OCTANT_6 = (1 << 5),
    CIRCLE_OCTANT_7 = (1 << 6),
    CIRCLE_OCTANT_8 = (1 << 7),

    CIRCLE_OCTANT_NEXT = (CIRCLE_OCTANT_8 << 1),
    CIRCLE_OCTANT_ALL  = (CIRCLE_OCTANT_NEXT-1)
};
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef CircleOctant CircleQuadrant;
enum {
    CIRCLE_QUADRANT_NONE = CIRCLE_OCTANT_NONE,

    CIRCLE_QUADRANT_1 = (CIRCLE_OCTANT_1|CIRCLE_OCTANT_2),
    CIRCLE_QUADRANT_2 = (CIRCLE_OCTANT_3|CIRCLE_OCTANT_4),
    CIRCLE_QUADRANT_3 = (CIRCLE_OCTANT_5|CIRCLE_OCTANT_6),
    CIRCLE_QUADRANT_4 = (CIRCLE_OCTANT_7|CIRCLE_OCTANT_8),

    CIRCLE_QUADRANT_ALL = CIRCLE_OCTANT_ALL,
};

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_CIRCLE_HPP 
