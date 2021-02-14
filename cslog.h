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
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef CSLOG_H_
#define CSLOG_H_


#ifdef PROJECT_CONF_H
#include PROJECT_CONF_H
#endif /* PROJECT_CONF_H */

#define LOG_LVL_ALL                             0
#define LOG_LVL_DEBUG                           1
#define LOG_LVL_INFO                            2
#define LOG_LVL_NOTICE                          3
#define LOG_LVL_WARNING                         4
#define LOG_LVL_ERROR                           5
#define LOG_LVL_CRITICAL                        6
#define LOG_LVL_ALERT                           7
#define LOG_LVL_EMERGENCY                       8
#define LOG_LVL_NONE                            9

#define CSLOG_BUILD_LEVEL                       LOG_LVL_INFO
#define CSLOG_VT100                             1
#define CSLOG_TIMESTAMP                         1

#ifndef CSLOG_VT100
	#define CSLOG_VT100							0
#endif

#ifndef CSLOG_TIMESTAMP
	#define CSLOG_TIMESTAMP						0
#endif

#ifndef ADDITIONAL_DESC
    // #define ADDITIONAL_DESC						""
    #define ADDITIONAL_DESC						__FUNCTION__
	// #define ADDITIONAL_DESC							__FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
	// #define ADDITIONAL_DESC							__FILE__#__LINE__
	// #define ADDITIONAL_DESC							__LINE__
#endif

#ifndef CSLOG_BUILD_LEVEL
	#define CSLOG_BUILD_LEVEL 					LOG_LVL_DEBUG
#endif

#ifndef CSLOG_STREAM
	#define CSLOG_STREAM						xprintf
#endif

#if CSLOG_VT100 > 0
// #warning "vt100 option not implemented yet"
	// colors
	#define TERM_NONE                 			"\e[0m"
	#define TERM_BLACK                			"\e[0;30m"
	#define TERM_L_BLACK             			"\e[1;30m"
	#define TERM_RED         			        "\e[0;31m"
	#define TERM_L_RED                			"\e[1;31m"
	#define TERM_GREEN       			        "\e[0;32m"
	#define TERM_L_GREEN              			"\e[1;32m"
	#define TERM_YELLOW                			"\e[0;33m"
	#define TERM_L_YELLOW               		"\e[1;33m"
	#define TERM_BLUE                 			"\e[0;34m"
	#define TERM_L_BLUE               			"\e[1;34m"
	#define TERM_PURPLE               			"\e[0;35m"
	#define TERM_L_PURPLE             			"\e[1;35m"
	#define TERM_CYAN                 			"\e[0;36m"
	#define TERM_L_CYAN               			"\e[1;36m"
	#define TERM_GRAY                 			"\e[0;37m"
	#define TERM_WHITE                			"\e[1;37m"

	#define TERM_BOLD                 			"\e[1m"
	#define TERM_UNDERLINE            			"\e[4m"
	#define TERM_BLINK                			"\e[5m"
	#define TERM_REVERSE              			"\e[7m"
	#define TERM_HIDE                 			"\e[8m"
	#define TERM_CLEAR                			"\e[2J"
	#define TERM_CLRLINE         			    "\r\e[K" //or "\e[1K\r"
	
	#define VT100_COL_BLACK   					"\033[0;30;37m" //BLACK_FG WHITE_BG
	#define VT100_COL_RED     					"\033[0;31;30m"	//RED_FG BLACK_FG
	#define VT100_COL_GREEN   					"\033[0;32;30m"	//GREEN_FG BLACK_FG
	#define VT100_COL_YELLOW  					"\033[0;33;30m"	//YELLOW_FG BLACK_FG
	#define VT100_COL_BLUE    					"\033[0;34;30m"	//BLUE_FG BLACK_FG
	#define VT100_COL_MAGENTA 					"\033[0;35;30m"	//MAGENTA_FG BLACK_FG
	#define VT100_COL_CYAN    					"\033[0;36;30m"	//CYAN_FG BLACK_FG
	#define VT100_COL_WHITE   					"\033[0;37;30m"	//WHITE_FG BLACK_FG
	#define VT100_CLR_RESET						"\033[0m"

#else

#endif

extern const char * log_level_strings[];

#if CSLOG_TIMESTAMP > 0
    #include <stdint.h>
    extern volatile unsigned long msTick;
	#define __TIME_STAMP_TO_LOG					CSLOG_STREAM("[%10ld]",msTick);
#else
	#define __TIME_STAMP_TO_LOG					do{}while(0);
#endif

#define SHOULD_I_LOG( level ) 					(level > (CSLOG_BUILD_LEVEL-1))
    
#define LOG(level, ... )    /* if ( SHOULD_I_LOG(level) ) */ { \
		__TIME_STAMP_TO_LOG\
		CSLOG_STREAM("[%s]{%s}:", log_level_strings[level], ADDITIONAL_DESC); \
		CSLOG_STREAM( __VA_ARGS__ ); \
        CSLOG_STREAM("\n"); \
	}
	
#if SHOULD_I_LOG(LOG_LVL_DEBUG)
#define CSLOG_DEBUG( ... )  					LOG( LOG_LVL_DEBUG,  __VA_ARGS__ )
#else
#define CSLOG_DEBUG( ... )
#endif

#if SHOULD_I_LOG(LOG_LVL_INFO)
#define CSLOG_INFO( ... ) 						LOG( LOG_LVL_INFO, __VA_ARGS__ )
#else
#define CSLOG_INFO( ... )
#endif

#if SHOULD_I_LOG(LOG_LVL_NOTICE)
#define CSLOG_NOTICE( ... ) 					LOG( LOG_LVL_NOTICE, __VA_ARGS__ )
#else
#define CSLOG_NOTICE( ... )
#endif

#if SHOULD_I_LOG(LOG_LVL_WARNING)
#define CSLOG_WARNING(  ... ) 					LOG( LOG_LVL_WARNING,__VA_ARGS__ )
#else
#define CSLOG_WARNING( ... )
#endif

#if SHOULD_I_LOG(LOG_LVL_ERROR)
#define CSLOG_ERROR( ... ) 						LOG( LOG_LVL_ERROR, __VA_ARGS__ )
#else
#define CSLOG_ERROR( ... )
#endif

#if SHOULD_I_LOG(LOG_LVL_CRITICAL)
#define CSLOG_CRITICAL(  ... ) 					LOG( LOG_LVL_CRITICAL, __VA_ARGS__ )
#else
#define CSLOG_CRITICAL( ... )
#endif

#if SHOULD_I_LOG(LOG_LVL_ALERT)
#define CSLOG_ALERT(  ... ) 					LOG( LOG_LVL_ALERT, __VA_ARGS__ )
#else
#define CSLOG_ALERT( ... )
#endif

#if SHOULD_I_LOG(LOG_LVL_EMERGENCY)
#define CSLOG_EMERG(  ... ) 					LOG( LOG_LVL_EMERGENCY, __VA_ARGS__ )
#else
#define CSLOG_EMERG( ... )
#endif

#endif /* CSLOG_H_ */
