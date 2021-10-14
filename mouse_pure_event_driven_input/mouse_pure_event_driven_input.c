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

//-----------------------------------------------------------------------------
// Headers inclusions.
//-----------------------------------------------------------------------------
#include <assert.h>
#include <windows.h>
#include <process.h> // for _beginthreadex
#include "static_pure_event_driven_input.h"

//-----------------------------------------------------------------------------
// Custom event-listener thread data.
//-----------------------------------------------------------------------------
DWORD thread_id = 0;
HANDLE h_thread = NULL;
HANDLE h_1 = NULL, h_2 = NULL, h_3 = NULL, h_4 = NULL, h_5 = NULL, h_6 = NULL, 
h_7 = NULL, h_8 = NULL, h_9 = NULL, h_10 = NULL, h_11 = NULL, h_12 = NULL, 
h_13 = NULL, h_14 = NULL, h_15 = NULL, h_16;
CURSORINFO c = { 0 };

//-----------------------------------------------------------------------------
// Global variables.
//-----------------------------------------------------------------------------
unsigned long long int icon;

/*-----------------------------------------------------------------------------
Function: modeler_init_inputs
Purpose : return the inputs count.
In      : pointer to an unsigned integer.
Out     : modified unsigned integer.
Return  : status.
-----------------------------------------------------------------------------*/
ESRV_API ESRV_STATUS modeler_init_inputs(
	unsigned int *p, 
	int *pfd,
	int *pfe,
	char *po,
	size_t so
) {

	//-------------------------------------------------------------------------

	//-------------------------------------------------------------------------
	// Exception handling section begin.
	//-------------------------------------------------------------------------
	INPUT_BEGIN_EXCEPTIONS_HANDLING

	assert(p != NULL);
	assert(pfd != NULL);
	assert(pfe != NULL);

	SIGNAL_PURE_EVENT_DRIVEN_MODE;
	SET_INPUTS_COUNT(INPUTS_COUNT);

	return(ESRV_SUCCESS);

	//-------------------------------------------------------------------------
	// Exception handling section end.
	//-------------------------------------------------------------------------
	INPUT_END_EXCEPTIONS_HANDLING(NULL)

}

/*-----------------------------------------------------------------------------
Function: modeler_open_inputs
Purpose : open inputs.
In      : pointer to PINTEL_MODELER_INPUT_TABLE data structure.
Out     : modified PINTEL_MODELER_INPUT_TABLE data structure.
Return  : status.
-----------------------------------------------------------------------------*/
ESRV_API ESRV_STATUS modeler_open_inputs(PINTEL_MODELER_INPUT_TABLE p) {

	//-------------------------------------------------------------------------
	// Generic variables.
	//-------------------------------------------------------------------------
	unsigned int i = 0;

	//-------------------------------------------------------------------------
	// Input descriptions.
	//-------------------------------------------------------------------------
	static char *descriptions[INPUTS_COUNT] = { 
		INPUT_DESCRIPTION_STRINGS 
	};
	static INTEL_MODELER_INPUT_TYPES types[INPUTS_COUNT] = {
		INPUT_TYPES
	};

	//-------------------------------------------------------------------------

	//-------------------------------------------------------------------------
	// Exception handling section begin.
	//-------------------------------------------------------------------------
	INPUT_BEGIN_EXCEPTIONS_HANDLING

	assert(p != NULL);

	//-------------------------------------------------------------------------
	// Start the pure event-driven thread.
	//-------------------------------------------------------------------------
	h_thread = (HANDLE)_beginthreadex(
		NULL,
		0,
		custom_event_listner_thread,
		(void *)p,
		0,
		(unsigned int *)&thread_id 
	);
	if(h_thread == NULL) {
		goto modeler_open_inputs_error;
	}

	//-------------------------------------------------------------------------
	// Set input information.
	//-------------------------------------------------------------------------
	SET_INPUTS_NAME(INPUT_NAME_STRING);
	for( i = 0; i < INPUTS_COUNT; i++) {
		SET_INPUT_DESCRIPTION(
			i,
			descriptions[i]
		);
		SET_INPUT_TYPE(
			i,
			types[i]
		);
	} // for i (each input)

	return(ESRV_SUCCESS);

	//-------------------------------------------------------------------------
	// Exception handling section end.
	//-------------------------------------------------------------------------
	INPUT_END_EXCEPTIONS_HANDLING(p)

modeler_open_inputs_error:

	return(ESRV_FAILURE);

}

/*-----------------------------------------------------------------------------
Function: modeler_close_inputs
Purpose : close inputs.
In      : pointer to PINTEL_MODELER_INPUT_TABLE data structure.
Out     : modified PINTEL_MODELER_INPUT_TABLE data structure.
Return  : status.
-----------------------------------------------------------------------------*/
ESRV_API ESRV_STATUS modeler_close_inputs(PINTEL_MODELER_INPUT_TABLE p) {

	//-------------------------------------------------------------------------
	// Exception handling section begin.
	//-------------------------------------------------------------------------
	INPUT_BEGIN_EXCEPTIONS_HANDLING

	assert(p != NULL);

//# check if thread is still running
//# do not need stop event
//# create global event in open
//# when you exit the thread, you set that event
//# wait on that event  in close (say 5 seconds)
//# check state of thread knowing the handle (this is better than)
//# can also wait on the handle of the thread, already have it
//# if thread is still running, use a macro which terminates the thread
//# read MS documentation -- do not terminate thread because of leak
//# good practice to have it in case of unexpected cases

	/* local variable definition */
	int a = 0;

	/* do loop execution */
	// in do loop:
	//	GetExitCodeThread() -- to check which state a thread is in
	//	limit number of checks, give it some time

	do {
		a = a + 1;
	} while (GetExitCodeThread(h_thread, 0) != 0 && a < 5);

	return(ESRV_SUCCESS);

	//-------------------------------------------------------------------------
	// Exception handling section end.
	//-------------------------------------------------------------------------
	INPUT_END_EXCEPTIONS_HANDLING(p)

//modeler_close_inputs_error:
//	return(ESRV_FAILURE);
}

/*-----------------------------------------------------------------------------
Function: modeler_read_inputs
Purpose : collect all inputs.
In      : pointer to PINTEL_MODELER_INPUT_TABLE data structure.
Out     : modified PINTEL_MODELER_INPUT_TABLE data structure.
Return  : status.
-----------------------------------------------------------------------------*/
ESRV_STATUS modeler_read_inputs(PINTEL_MODELER_INPUT_TABLE p) {

	//-------------------------------------------------------------------------

	//-------------------------------------------------------------------------
	// Exception handling section begin.
	//-------------------------------------------------------------------------
	INPUT_BEGIN_EXCEPTIONS_HANDLING

	assert(p != NULL);

	return(ESRV_SUCCESS);

	//-------------------------------------------------------------------------
	// Exception handling section end.
	//-------------------------------------------------------------------------
	INPUT_END_EXCEPTIONS_HANDLING(p)

}

/*-----------------------------------------------------------------------------
Function: modeler_listen_inputs
Purpose : listen for all inputs.
In      : pointer to PINTEL_MODELER_INPUT_TABLE data structure.
Out     : modified PINTEL_MODELER_INPUT_TABLE data structure.
Return  : status.
-----------------------------------------------------------------------------*/
ESRV_STATUS modeler_listen_inputs(PINTEL_MODELER_INPUT_TABLE p) {

	//-------------------------------------------------------------------------

	//-------------------------------------------------------------------------
	// Exception handling section begin.
	//-------------------------------------------------------------------------
	INPUT_BEGIN_EXCEPTIONS_HANDLING

	assert(p != NULL);

	return(ESRV_SUCCESS);

	//-------------------------------------------------------------------------
	// Exception handling section end.
	//-------------------------------------------------------------------------
	INPUT_END_EXCEPTIONS_HANDLING(p)

}

/*-----------------------------------------------------------------------------
Function: modeler_process_dctl
Purpose : process DCTL commands on DCTL interrupt notification.
In      : pointer to PINTEL_MODELER_INPUT_TABLE data structure.
Out     : modified PINTEL_MODELER_INPUT_TABLE data structure.
Return  : status.
-----------------------------------------------------------------------------*/
ESRV_STATUS modeler_process_dctl(PINTEL_MODELER_INPUT_TABLE p) {

	//-------------------------------------------------------------------------

	//-------------------------------------------------------------------------
	// Exception handling section begin.
	//-------------------------------------------------------------------------
	INPUT_BEGIN_EXCEPTIONS_HANDLING

	assert(p != NULL);

	return(ESRV_SUCCESS);

	//-------------------------------------------------------------------------
	// Exception handling section end.
	//-------------------------------------------------------------------------
	INPUT_END_EXCEPTIONS_HANDLING(p)

}

/*-----------------------------------------------------------------------------
Function: modeler_process_lctl
Purpose : process LCTL commands on LCTL interrupt notification.
In      : pointer to PINTEL_MODELER_INPUT_TABLE data structure.
Out     : modified PINTEL_MODELER_INPUT_TABLE data structure.
Return  : status.
-----------------------------------------------------------------------------*/
ESRV_STATUS modeler_process_lctl(PINTEL_MODELER_INPUT_TABLE p) {

	//-------------------------------------------------------------------------

	//-------------------------------------------------------------------------
	// Exception handling section begin.
	//-------------------------------------------------------------------------
	INPUT_BEGIN_EXCEPTIONS_HANDLING

	assert(p != NULL);

	return(ESRV_SUCCESS);

	//-------------------------------------------------------------------------
	// Exception handling section end.
	//-------------------------------------------------------------------------
	INPUT_END_EXCEPTIONS_HANDLING(p)

}

//-----------------------------------------------------------------------------

/*-----------------------------------------------------------------------------
Function: custom_event_listner_thread
Purpose : implement the pure event listener thread.
In      : pointers to the input table (passed as void *).
Out     : modified input variables and time events list data.
Return  : status.
-----------------------------------------------------------------------------*/
ESRV_API unsigned int __stdcall custom_event_listner_thread(void *px) {

	//-------------------------------------------------------------------------
	// Generic variables.
	//-------------------------------------------------------------------------
	DWORD dwret = 0;

	//-------------------------------------------------------------------------
	// Watchdog variables.
	//-------------------------------------------------------------------------
	WATCHDOG_VARIABLES

	//-------------------------------------------------------------------------
	// Access helper variables.
	//-------------------------------------------------------------------------
	PINTEL_MODELER_INPUT_TABLE p = NULL;

	//-------------------------------------------------------------------------

	//-------------------------------------------------------------------------
	// Exception handling section begin.
	//-------------------------------------------------------------------------
	INPUT_BEGIN_EXCEPTIONS_HANDLING

	assert(px != NULL);
	p = (PINTEL_MODELER_INPUT_TABLE)px;

	//-------------------------------------------------------------------------
	// Name this thread (for debug mode only).
	//-------------------------------------------------------------------------
	INPUT_DIAGNOSTIC_NAME_THIS_THREAD(
		p,
		"custom_event_listner_thread"
	);

	//-------------------------------------------------------------------------
	// Register this thread with watchdog.
	//-------------------------------------------------------------------------
	INPUT_REGISTER_EVENT_LOCKED_THREAD_WITH_WATCHDOG(
		p,
		"custom_event_listner_thread",
		h_thread,
		thread_id,
		STOP_SIGNAL,
		custom_event_listner_thread_exit
	);

	h_1 = LoadCursorA(NULL, IDC_APPSTARTING);
	h_2 = LoadCursorA(NULL, IDC_ARROW);
	h_3 = LoadCursorA(NULL, IDC_CROSS);
	h_4 = LoadCursorA(NULL, IDC_HAND);
	h_5 = LoadCursorA(NULL, IDC_HELP);
	h_6 = LoadCursorA(NULL, IDC_IBEAM);
	h_7 = LoadCursorA(NULL, IDC_ICON);
	h_8 = LoadCursorA(NULL, IDC_NO);
	h_9 = LoadCursorA(NULL, IDC_SIZE);
	h_10 = LoadCursorA(NULL, IDC_SIZEALL);
	h_11 = LoadCursorA(NULL, IDC_SIZENESW);
	h_12 = LoadCursorA(NULL, IDC_SIZENS);
	h_13 = LoadCursorA(NULL, IDC_SIZENWSE);
	h_14 = LoadCursorA(NULL, IDC_SIZEWE);
	h_15 = LoadCursorA(NULL, IDC_UPARROW);
	h_16 = LoadCursorA(NULL, IDC_WAIT);

	while(STOP_REQUEST == 0) {
		//---------------------------------------------------------------------
			// Pause to simulate event triggering.
			// Note:
			//    Rather than using a sleep, which would lock the event listener 
			//    thread, we recommend using the method shown below. In general
			//    developers of event-driven input libraries should add into the
			//    end condition the event / semaphore via the STOP_SIGNAL macro 
			//    (also - but not instead - use the STOP_REQUEST macro).
			//---------------------------------------------------------------------
		dwret = WaitForSingleObject(
			STOP_SIGNAL,
			INPUT_PAUSE_IN_MS //# 100ms
		);
		switch (dwret) {
		case WAIT_OBJECT_0:
			goto custom_event_listner_thread_exit; // time to leave!
			break;
		case WAIT_TIMEOUT:

//# think about the private data: which cursor have we seen?
//# macros to set private data
//# monitoring 3 different mouse inputs OR only one input and use private data

//example: count of how many times we see appstart cursor
//example: which window was in the foreground?
//we want a single signal in the time series, could be a binary flag
//can log a binary flag -- which cursor? 0 is app start, 1 is waiting, 2 is hand, etc.
//what is the minimum data I may need for this waiting issue
//example: mark when state of icon changes
//example: can mark cursor change only when loading for more than x seconds
//could bring some of that computation inside the input library 
			
			c.cbSize = sizeof(c);
			GetCursorInfo(&c);

			if (c.hCursor == h_1) {
				icon = 0;
			} 
			else if (c.hCursor == h_2) {
				icon = 1;
			}
			else if (c.hCursor == h_3) {
				icon = 2;
			}
			else if (c.hCursor == h_4) {
				icon = 3;
			}
			else if (c.hCursor == h_5) {
				icon = 4;
			}
			else if (c.hCursor == h_6) {
				icon = 5;
			}
			else if (c.hCursor == h_7) {
				icon = 6;
			}
			else if (c.hCursor == h_8) {
				icon = 7;
			}
			else if (c.hCursor == h_9) {
				icon = 8;
			}
			else if (c.hCursor == h_10) {
				icon = 9;
			}
			else if (c.hCursor == h_11) {
				icon = 10;
			}
			else if (c.hCursor == h_12) {
				icon = 11;
			}
			else if (c.hCursor == h_13) {
				icon = 12;
			}
			else if (c.hCursor == h_14) {
				icon = 13;
			}
			else if (c.hCursor == h_15) {
				icon = 14;
			}
			else if (c.hCursor == h_16) {
				icon = 15;
			}

			break; // all good, time to make a measurement
		default:
			goto custom_event_listner_thread_exit; // error condition
		} // switch

		//---------------------------------------------------------------------
		// Trigger logging.
		//---------------------------------------------------------------------
		LOG_INPUT_VALUES;

		//---------------------------------------------------------------------
		// Set input values.
		//---------------------------------------------------------------------

		SET_INPUT_ULL_VALUE(
			INPUT_CURSOR_ICON,
			icon
		);
	} // while

custom_event_listner_thread_exit:
	return(ESRV_FAILURE);

	//-------------------------------------------------------------------------
	// Un-register this thread with watchdog.
	//-------------------------------------------------------------------------
	INPUT_UNREGISTER_THREAD_WITH_WATCHDOG(
		p,
		h_thread,
		thread_id
	);

	return(ESRV_SUCCESS);

	//-------------------------------------------------------------------------
	// Exception handling section end.
	//-------------------------------------------------------------------------
	INPUT_END_EXCEPTIONS_HANDLING(p)

}
