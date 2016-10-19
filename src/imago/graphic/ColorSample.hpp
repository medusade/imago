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
///   File: ColorSample.hpp
///
/// Author: $author$
///   Date: 10/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _IMAGO_GRAPHIC_COLORSAMPLE_HPP
#define _IMAGO_GRAPHIC_COLORSAMPLE_HPP

#include "imago/base/Base.hpp"

#define IMAGO_GRAPHIC_COLORSAMPLE_LEVELS_DEFAULT 256

namespace imago {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: ColorSampleT
///////////////////////////////////////////////////////////////////////
template
<typename TLevel = size_t,
 TLevel VLevelsDefault = IMAGO_GRAPHIC_COLORSAMPLE_LEVELS_DEFAULT,
 class TImplements = ImplementBase, class TExtends = Base>
class _EXPORT_CLASS ColorSampleT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TLevel level_t;
    static const level_t LevelsDefault = VLevelsDefault;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ColorSampleT(level_t level = 0, level_t levels = LevelsDefault)
    : m_level(level), m_levels(levels) {
    }
    ColorSampleT(const ColorSampleT& copy)
    : m_level(copy.m_level), m_levels(copy.m_levels) {
    }
    virtual ~ColorSampleT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual level_t SetLevel(level_t to) {
        m_level = to;
        return m_level;
    }
    virtual level_t Level() const {
        return m_level;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual level_t SetLevels(level_t to) {
        m_levels = to;
        return m_levels;
    }
    virtual level_t Levels() const {
        return m_levels;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual operator float () const {
        float level = 0.0;
        if (1 < (m_levels)) {
            level = ((float)m_level) / ((float)(m_levels-1));
        }
        return level;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    level_t m_level, m_levels;
};
typedef ColorSampleT<> ColorSample;

} // namespace graphic 
} // namespace imago 

#endif // _IMAGO_GRAPHIC_COLORSAMPLE_HPP 
