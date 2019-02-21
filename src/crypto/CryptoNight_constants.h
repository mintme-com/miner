/* XMRig
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2017-2018 XMR-Stak    <https://github.com/fireice-uk>, <https://github.com/psychocrypt>
 * Copyright 2018      Lee Clagett <https://github.com/vtnerd>
 * Copyright 2016-2018 XMRig       <https://github.com/xmrig>, <support@xmrig.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __CRYPTONIGHT_CONSTANTS_H__
#define __CRYPTONIGHT_CONSTANTS_H__


#include <stdint.h>


#include "common/xmrig.h"


namespace xmrig
{

constexpr const size_t   CRYPTONIGHT_MEMORY       = 2 * 1024 * 1024;
constexpr const uint32_t CRYPTONIGHT_MASK         = 0x1FFFF0;
constexpr const uint32_t CRYPTONIGHT_ITER         = 0x80000;

template<Algo ALGO> inline constexpr size_t cn_select_memory()           { return 0; }
template<> inline constexpr size_t cn_select_memory<CRYPTONIGHT>()       { return CRYPTONIGHT_MEMORY; }


inline size_t cn_select_memory(Algo algorithm)
{
    switch(algorithm)
    {
    case CRYPTONIGHT:
        return CRYPTONIGHT_MEMORY;

    default:
        break;
    }

    return 0;
}


template<Algo ALGO> inline constexpr uint32_t cn_select_mask()           { return 0; }
template<> inline constexpr uint32_t cn_select_mask<CRYPTONIGHT>()       { return CRYPTONIGHT_MASK; }


inline uint32_t cn_select_mask(Algo algorithm)
{
    switch(algorithm)
    {
    case CRYPTONIGHT:
        return CRYPTONIGHT_MASK;

    default:
        break;
    }

    return 0;
}


template<Algo ALGO> inline constexpr uint32_t cn_select_iter()           { return 0; }
template<> inline constexpr uint32_t cn_select_iter<CRYPTONIGHT>()       { return CRYPTONIGHT_ITER; }


inline uint32_t cn_select_iter(Algo algorithm)
{
    switch(algorithm)
    {
    case CRYPTONIGHT:
        return CRYPTONIGHT_ITER;

    default:
        break;
    }

    return 0;
}


} /* namespace xmrig */


#endif /* __CRYPTONIGHT_CONSTANTS_H__ */
