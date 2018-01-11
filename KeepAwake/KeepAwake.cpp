// KeepAwake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void BlockSleep()
{
    EXECUTION_STATE result = NULL;

    result = SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED);

    if (result == NULL)
    {
        RaiseFailFastException(nullptr, nullptr, 0);
    }
}

void DontExit()
{
    // Just wait on an event that'll never get set to efficiently wait
    HANDLE neverEndingEvent = NULL;

    neverEndingEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);

    if (neverEndingEvent == NULL)
    {
        RaiseFailFastException(nullptr, nullptr, 0);
    }

    DWORD waitResult = 0;

    waitResult = WaitForSingleObject(neverEndingEvent, INFINITE);
    RaiseFailFastException(nullptr, nullptr, 0);
}


int wmain()
{
    BlockSleep();
    wprintf(L"While this program is running, this computer won't sleep due to inactivity\n");
    wprintf(L"Press Ctrl+C to end\n");
    DontExit();
    return 0;
}

