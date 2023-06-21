#include <iostream>
#include <windows.h>

// Create a macro for exporting functions
#define DllExport __declspec(dllexport)

/*
// LEGITIMATE DLL EXPORT FUNCTIONS TABLE (extern "C" to avoid the C++ name-mashing):
    extern "C" DllExport void legitimate_dll_func1(void){return;}
    extern "C" DllExport void legitimate_dll_func2(void){return;}
    extern "C" DllExport void legitimate_dll_func3(void){return;}
*/

// Declare export functions (extern "C" to avoid the CPP name mashing)
extern "C" DllExport void testfunc();
extern "C" DllExport void dll_hijack();

/*
    BOOL is a typedef of int
    WINAPI is a typedef of __stdcall (can also use APIENTRY)
    BOOL WINAPI translates to int __stdcall
*/

BOOL WINAPI DllMain(HINSTANCE hDll, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
        {
            dll_hijack();
            break;
        }
    }
    return TRUE;
}



// Functions List

extern "C" DllExport void testfunc()
{
    std::cout << "[+] EXPLICIT EXPORT TEST SUCCESSFUL" << std::endl;
}

extern "C" DllExport void dll_hijack()
{
    if(!system(NULL))               // System should initialize as NULL 
    {
        std::cerr << "[-] SYSTEM CALL FAILED..." << std::endl;
        exit(1);
    }

    MessageBoxW(NULL, (LPCWSTR)L"DLL Loaded Successfully!", (LPCWSTR)L"DLL Loading", MB_ICONEXCLAMATION | MB_OK);
}