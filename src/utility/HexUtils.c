//
// Copyright (c) 2019 Takpit. All rights reserved.
//

#include "proto_nmea/utility/HexUtils.h"

//region Hex Table

#if defined(__GNUC__)
static const uint8_t hextable[] = {
        [0 ... 255] = -1, // bit aligned access into this table is considerably
        ['0'] = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, // faster for most modern processors,
        ['A'] = 10, 11, 12, 13, 14, 15,       // for the space conscious, reduce to
        ['a'] = 10, 11, 12, 13, 14, 15        // signed char.
};
#else
static const uint8_t hextable[] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1, -1, 10, 11, 12, 13, 14, 15, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};
#endif

//endregion

uint32_t stringToHex(unsigned const char *hexString)
{
    uint32_t ret = 0;
    while (*hexString && ret >= 0)
    {
        ret = (ret << 4u) | hextable[*hexString++];
    }
    return ret;
}

bool isHex(unsigned char c)
{
    if (c < '0' || c > '9')
    {
        if (c < 'a' || c > 'f')
        {
            if (c < 'A' || c > 'F')
                return false;
        }
    }
    return true;
}
