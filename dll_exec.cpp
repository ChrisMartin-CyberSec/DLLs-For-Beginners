#include <iostream>
#include <windows.h>

int main()
{
    HMODULE hDll = LoadLibrary(TEXT("dlltest.dll"));        // Attempts to load DLL (returns NULL if unsuccessful)

    if (!hDll || hDll == INVALID_HANDLE_VALUE)              
    {
        std::cerr << "[-] Unable to load DLL..." << std::endl;

        return EXIT_FAILURE;
    }

    std::cout << "[+] DLL LOADED AT: " << std::hex << hDll << std::endl;

    /*
        Use typedef to create a type definition for a pointer function that will be utilized for importing an EXPLICITLY exported function from our test dll
        Set BOOL as the type for use later in the error handling logic (line 32)
        Because we used extern "C" __declspec(dllexport), the function is not name-mangled and exports as "testfunc"
        Use the 'dumpbin' tool in the Native Tools Command Prompt for Visual Studio to see the export functions of the dll
    */
    typedef BOOL (*MyFunc)();

    /*
        Set Func to the address of the "testfunc" function in the DLL
        You can use the "testfunc" function name or the ordinal displayed from the dumpbin (in this case it is 2)
    */
    MyFunc Func = (MyFunc)GetProcAddress(hDll, (LPCSTR) "testfunc");

    // Handle error if GetProcAddress fails
    if (!Func())
    {
        std::cerr << "[-] FAILED TO IMPORT FUNCTION" << std::endl;
    }

    // Free the library when done
    FreeLibrary(hDll);

    return EXIT_SUCCESS;
}   