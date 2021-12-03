/**
*** INTEL CONFIDENTIAL
*** 
*** Copyright (March 2011) (March 2011) Intel Corporation All Rights Reserved. 
*** The source code contained or described herein and all documents related to the
*** source code ("Material") are owned by Intel Corporation or its suppliers or 
*** licensors. Title to the Material remains with Intel Corporation or its 
*** suppliers and licensors. The Material contains trade secrets and proprietary 
*** and confidential information of Intel or its suppliers and licensors. 
*** The Material is protected by worldwide copyright and trade secret laws 
*** and treaty provisions. No part of the Material may be used, copied, 
*** reproduced, modified, published, uploaded, posted, transmitted, distributed,
*** or disclosed in any way without Intel's prior express written permission.
***
*** No license under any patent, copyright, trade secret or other intellectual
*** property right is granted to or conferred upon you by disclosure or delivery
*** of the Materials, either expressly, by implication, inducement, estoppel or
*** otherwise. Any license under such intellectual property rights must be 
*** express and approved by Intel in writing.
**/

#ifndef __INCLUDE_PURE_EVENT_DRIVEN_INCREMENTING_INPUT__
#define __INCLUDE_PURE_EVENT_DRIVEN_INCREMENTING_INPUT__

//-----------------------------------------------------------------------------
// Headers inclusions.
//-----------------------------------------------------------------------------
#include <windows.h>
#include "pub_intel_modeler.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
/*--------------------------------------------------------------------------*/

//-----------------------------------------------------------------------------
// Child Windows Struct & Callback Function
//-----------------------------------------------------------------------------
typedef struct {
	DWORD ownerpid;
	DWORD childpid;
} windowinfo;

BOOL CALLBACK EnumChildWindowsCallback(HWND hWnd, LPARAM lp) {
	windowinfo* info = (windowinfo*)lp;
	DWORD pid = 0;
	GetWindowThreadProcessId(hWnd, &pid);
	if (pid != info->ownerpid) info->childpid = pid;
	return TRUE;
}

//-----------------------------------------------------------------------------
// Global variables.
//-----------------------------------------------------------------------------
// string pattern to split by
const wchar_t s[3] = L"\\";

//-----------------------------------------------------------------------------
// Defines.
//-----------------------------------------------------------------------------
#define STRING_BUFFERS_SIZE 1024
#define MAX_MPLEX_LOGGER_CHECKS 10
#define WAIT_FOR_MULTIPLEX_LOGGER_TIME_IN_MS 1000
#define INPUT_PAUSE_IN_MS 1000 // does not accept floating point
#define INPUT_COUNT 20
	#define INPUT_EXECUTABLE 0
	#define INPUT_WINDOW_TITLE 1
	#define INPUT_NEXT_WINDOW 2
	#define INPUT_PREV_WINDOW 3
	#define INPUT_PARENT_WINDOW 4
	#define INPUT_SHELL_WINDOW 5
	#define INPUT_DESKTOP_WINDOW 6
	#define INPUT_FOREGROUND_WINDOW 7
	#define INPUT_IS_HUNG 8
	#define INPUT_IS_ZOOMED 9
	#define INPUT_IS_VISIBLE 10
	#define INPUT_IS_MINIMIZED 11
	#define INPUT_IS_WINDOW_UNICODE 12
	#define INPUT_WINDOW_RECT 13
	#define INPUT_CLIENT_WINDOW_RECT 14
	#define INPUT_WINDOW_STYLE 15
	#define INPUT_WINDOW_STYLE_EX 16
	#define INPUT_WINDOW_PLACEMENT 17
	#define INPUT_WINDOW_MONITOR 18
	#define INPUT_MONITOR_INFO 19

#define INPUT_NAME_STRING "DESKTOP-MAPPER"

#define INPUT_DESCRIPTION_STRINGS \
	"Executable Name", \
	"Window Title", \
	"Next Window", \
	"Previous Window", \
	"Parent Window", \
	"Shell Window", \
	"Desktop Window", \
	"Foreground Window", \
	"Window is Hung", \
	"Window is Zoomed", \
	"Window is Visible", \
	"Window is Minimized", \
	"Window is Unicode", \
	"Window Rectangle", \
	"Client Window Rectangle", \
	"Window Style", \
	"Window Style Ex", \
	"Window Placement", \
	"Window Monitor", \
	"Window Monitor Info", \

#define INPUT_TYPES \
	STRING_COUNTER, \
	STRING_COUNTER, \
	STRING_COUNTER, \
	STRING_COUNTER, \
	STRING_COUNTER, \
	STRING_COUNTER, \
	STRING_COUNTER, \
	STRING_COUNTER, \
	ULL_COUNTER, \
	ULL_COUNTER, \
	ULL_COUNTER, \
	ULL_COUNTER, \
	ULL_COUNTER, \
	ULL_COUNTER, \
	ULL_COUNTER, \
	ULL_COUNTER, \
	ULL_COUNTER, \
	ULL_COUNTER, \
	ULL_COUNTER, \
	ULL_COUNTER

#define WAIT_EVENTS_COUNT (2)
	#define STOP_EVENT_INDEX (0)
	#define FOREGROUND_WINDOW_CHANGE_INDEX (1)

//-----------------------------------------------------------------------------
// Function prototypes.
//-----------------------------------------------------------------------------
ESRV_API ESRV_STATUS modeler_init_inputs(
	unsigned int *, 
	int *, 
	int *, 
	char *,
	size_t
);
ESRV_API ESRV_STATUS modeler_open_inputs(PINTEL_MODELER_INPUT_TABLE);
ESRV_API ESRV_STATUS modeler_close_inputs(PINTEL_MODELER_INPUT_TABLE);
ESRV_STATUS modeler_read_inputs(PINTEL_MODELER_INPUT_TABLE);
ESRV_STATUS modeler_listen_inputs(PINTEL_MODELER_INPUT_TABLE);
ESRV_STATUS modeler_process_dctl(PINTEL_MODELER_INPUT_TABLE);
ESRV_STATUS modeler_process_lctl(PINTEL_MODELER_INPUT_TABLE);
//-----------------------------------------------------------------------------
ESRV_API unsigned int __stdcall custom_desktop_thread(void*);
ESRV_API unsigned int __stdcall custom_logger_thread(void*);
ESRV_API unsigned int __stdcall map_desktop(PINTEL_MODELER_INPUT_TABLE);
ESRV_API unsigned int __stdcall get_window_info(WINDOWS_STRUCTURE*);
ESRV_API unsigned int __stdcall multiplex_logging(PINTEL_MODELER_INPUT_TABLE);
TCHAR get_process_image_name(HWND);

/*--------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __INCLUDE_PURE_EVENT_DRIVEN_INCREMENTING_INPUT__
