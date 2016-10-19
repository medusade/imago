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
///   File: Ellipse.hpp
///
/// Author: $author$
///   Date: 10/10/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_ELLIPSE_HPP
#define _IMAGO_GRAPHIC_ELLIPSE_HPP

#include "imago/graphic/Circle.hpp"

namespace imago {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef unsigned int EllipseQuadrant;
enum {
    ELLIPSE_QUADRANT_NONE = CIRCLE_QUADRANT_NONE,

    ELLIPSE_QUADRANT_1 = CIRCLE_QUADRANT_1,
    ELLIPSE_QUADRANT_2 = CIRCLE_QUADRANT_2,
    ELLIPSE_QUADRANT_3 = CIRCLE_QUADRANT_3,
    ELLIPSE_QUADRANT_4 = CIRCLE_QUADRANT_4,

    ELLIPSE_QUADRANT_ALL = CIRCLE_QUADRANT_ALL,
};

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_ELLIPSE_HPP 
