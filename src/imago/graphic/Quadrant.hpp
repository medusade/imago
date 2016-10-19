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
///   File: Quadrant.hpp
///
/// Author: $author$
///   Date: 10/10/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_QUADRANT_HPP
#define _IMAGO_GRAPHIC_QUADRANT_HPP

#include "imago/graphic/Octant.hpp"

namespace imago {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef unsigned int Quadrant;
enum {
    QUADRANT_ALL = OCTANT_ALL,

    QUADRANT_1 = (OCTANT_1 | OCTANT_2),
    QUADRANT_2 = (OCTANT_3 | OCTANT_4),
    QUADRANT_3 = (OCTANT_5 | OCTANT_6),
    QUADRANT_4 = (OCTANT_7 | OCTANT_8),

    QUADRANT_TOP_RIGHT    = (QUADRANT_1),
    QUADRANT_BOTTOM_RIGHT = (QUADRANT_2),
    QUADRANT_BOTTOM_LEFT  = (QUADRANT_3),
    QUADRANT_TOP_LEFT     = (QUADRANT_4),

    QUADRANT_FIRST = QUADRANT_1,
    QUADRANT_LAST = QUADRANT_4,
    QUADRANT_BITS = 2
};

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_QUADRANT_HPP 
