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
///   File: Rectangle.hpp
///
/// Author: $author$
///   Date: 10/10/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_RECTANGLE_HPP
#define _IMAGO_GRAPHIC_RECTANGLE_HPP

#include "imago/base/Base.hpp"

namespace imago {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef int RectangleCorner;
enum {
    RECTANGLE_CORNER_NONE         = 0,

    RECTANGLE_CORNER_TOP_LEFT     = (1 << 0),
    RECTANGLE_CORNER_TOP_RIGHT    = (1 << 1),
    RECTANGLE_CORNER_BOTTOM_LEFT  = (1 << 2),
    RECTANGLE_CORNER_BOTTOM_RIGHT = (1 << 3),

    RECTANGLE_CORNER_ALL          = ((1 << 4)-1)
};
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef int RectangleSide;
enum {
    RECTANGLE_SIDE_NONE   = 0,

    RECTANGLE_SIDE_LEFT   = (1 << 0),
    RECTANGLE_SIDE_TOP    = (1 << 1),
    RECTANGLE_SIDE_RIGHT  = (1 << 2),
    RECTANGLE_SIDE_BOTTOM = (1 << 3),

    RECTANGLE_SIDE_ALL    = (1 << 4)-1
};

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_RECTANGLE_HPP 
