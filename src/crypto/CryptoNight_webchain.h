/* XMRig
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2017-2018 XMR-Stak    <https://github.com/fireice-uk>, <https://github.com/psychocrypt>
 * Copyright 2018      Lee Clagett <https://github.com/vtnerd>
 * Copyright 2016-2018 XMRig       <https://github.com/xmrig>, <support@xmrig.com>
 * Copyright 2018      Webchain project
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

#ifndef __CRYPTONIGHT_MONERO_H__
#define __CRYPTONIGHT_MONERO_H__

// VARIANT ALTERATIONS
#define VARIANT1_INIT(part) {}

#define VARIANT1_1(p) \
    if (VARIANT > 0) { \
        const uint8_t tmp1 = ((const uint8_t*)(p))[11]; \
        static const uint32_t table1 = 0x86420; \
        const uint8_t index1 = (((tmp1 >> 3) & 6) | (tmp1 & 1)) << 1; \
        ((uint8_t*)(p))[11] = tmp1 ^ ((table1 >> index1) & 0x30); \
    }

#define VARIANT1_2(p, part) \
    if (VARIANT > 0) { \
        const uint8_t tmp2 = ((uint8_t*)(&p))[1]; \
        static const uint32_t table2 = 0x75310; \
        const uint8_t index2 = (((tmp2 >> 3) & 6) | (tmp2 & 1)) << 1; \
        ((uint8_t*)(&p))[1] = tmp2 ^ ((table2 >> index2) & 0x33); \
    }

#endif /* __CRYPTONIGHT_MONERO_H__ */
