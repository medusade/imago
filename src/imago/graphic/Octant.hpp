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
///   File: Octant.hpp
///
/// Author: $author$
///   Date: 10/10/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_OCTANT_HPP
#define _IMAGO_GRAPHIC_OCTANT_HPP

#include "imago/base/Base.hpp"

namespace imago {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef unsigned int Octant;
enum {
    OCTANT_NONE = 0,

    OCTANT_1 = (1 << 0),
    OCTANT_2 = (1 << 1),

    OCTANT_3 = (1 << 2),
    OCTANT_4 = (1 << 3),

    OCTANT_5 = (1 << 4),
    OCTANT_6 = (1 << 5),

    OCTANT_7 = (1 << 6),
    OCTANT_8 = (1 << 7),

    OCTANT_FIRST = (OCTANT_1),
    OCTANT_LAST = (OCTANT_8),
    OCTANT_NEXT = (OCTANT_LAST << 1),
    OCTANT_ALL  = (OCTANT_NEXT - 1),
    OCTANT_BITS = 1
};

} // namespace graphic
} // namespace imago 

#endif // _IMAGO_GRAPHIC_OCTANT_HPP 

