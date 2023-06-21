#include <iostream>
#include <windows.h>

// Create a macro for exporting functions
#define DllExport __declspec(dllexport)


// Declare export functions (extern "C" to avoid the C++ name mashing)
extern "C" DllExport void testfunc();
extern "C" DllExport void dll_hijack();

/*
    BOOL WINAPI DLLMain() 
    This is where you set your parameters for function calls based on process attachment/detachment or thread attachment/detachment
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
        
        case DLL_THREAD_ATTACH:
         // Do thread-specific initialization.
            break;

        case DLL_THREAD_DETACH:
         // Do thread-specific cleanup.
            break;

        case DLL_PROCESS_DETACH:
        
            if (lpvReserved != nullptr)
            {
                break; // do not do cleanup if process termination scenario
            }
            
         // Perform any necessary cleanup.
            break;
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
