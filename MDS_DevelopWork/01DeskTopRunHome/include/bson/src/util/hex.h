// util/hex.h

/*    Copyright 2009 10gen Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once

#include "../bsonassert.h"
#include "builder.h"
#include "export.h"

namespace bson {

    //can't use hex namespace because it conflicts with hex iostream function
    inline int fromHex( char c ) {
        if ( '0' <= c && c <= '9' )
            return c - '0';
        if ( 'a' <= c && c <= 'f' )
            return c - 'a' + 10;
        if ( 'A' <= c && c <= 'F' )
            return c - 'A' + 10;
        assert( false );
        return 0xff;
    }
    inline char fromHex( const char *c ) {
        return (char)(( fromHex( c[ 0 ] ) << 4 ) | fromHex( c[ 1 ] ));
    }

    inline string toHex(const void* inRaw, int len) {
        static const char hexchars[] = "0123456789ABCDEF";

        StringBuilder out;
        const char* in = reinterpret_cast<const char*>(inRaw);
        for (int i=0; i<len; ++i) {
            char c = in[i];
            char hi = hexchars[(c & 0xF0) >> 4];
            char lo = hexchars[(c & 0x0F)];

            out << hi << lo;
        }

        return out.str();
    }

    inline int to_big(const char* data)
    {
        unsigned char * t = new unsigned char[4];
        //std::cout << toHex(data,4) << std::endl;
        t[0] = data[3];
        t[1] = data[2];
        t[2] = data[1];
        t[3] = data[0];
        int tt = *(int*)(t);
        delete []t;
        //std::cout << toHex(&tt,4) << std::endl;
        return tt;
    }

    inline string toHexLower(const void* inRaw, int len) {
        static const char hexchars[] = "0123456789abcdef";

        StringBuilder out;
        const char* in = reinterpret_cast<const char*>(inRaw);
        for (int i=0; i<len; ++i) {
            char c = in[i];
            char hi = hexchars[(c & 0xF0) >> 4];
            char lo = hexchars[(c & 0x0F)];

            out << hi << lo;
        }

        return out.str();
    }
}
