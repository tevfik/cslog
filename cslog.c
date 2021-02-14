/* Copyright (c)[Tevfik KADIOGLU](mailto:tevfik.kadioglu@gmail.com), 
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the author may not be used to endorse or promote
   products derived from this software without specific prior
   written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

#include "cslog.h"

#if CSLOG_VT100 > 0

const char *log_level_strings[] = {
    "ALL ",                         // 0
    TERM_GRAY"DEBG"TERM_NONE,       // 1
    TERM_CYAN"INFO"TERM_NONE,       // 2
    TERM_GREEN"NOTI"TERM_NONE,      // 3
    TERM_BLUE"WARN"TERM_NONE,       // 4
    TERM_L_YELLOW"ERR-"TERM_NONE,   // 5
    TERM_PURPLE"CRIT"TERM_NONE,     // 6
    TERM_L_PURPLE"ALRT"TERM_NONE,   // 7
    TERM_RED"EMER"TERM_NONE,        // 8
    "NONE",                         // 9
};

#else

const char *log_level_strings[] = {
    "ALL ",                         // 0    
    "DEBG",                         // 1
    "INFO",                         // 2
    "NOTI",                         // 3
    "WARN",                         // 4
    "ERR-",                         // 5
    "CRIT",                         // 6
    "ALRT",                         // 7
    "EMER",                         // 8
    "NONE",                         // 9    
};

#endif // CSLOG_VT100 > 0
