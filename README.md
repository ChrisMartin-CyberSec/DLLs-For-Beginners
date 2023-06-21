# DLLs-For-Beginners

## Simple DLL linking using C++ executable


This repository contains two files: `main.cpp` and `dlltest.cpp`


The `main.cpp` will be compiled as the **executable** .


The `dlltest.cpp` will be compiled as the **dll**.

Make sure to check out the following Microsoft Documentations: 
- [DllMain Entry Point](https://learn.microsoft.com/en-us/windows/win32/dlls/dllmain)
- [Exporting from a DLL Using __declspec(dllexport)](https://learn.microsoft.com/en-us/cpp/build/exporting-from-a-dll-using-declspec-dllexport?view=msvc-170)
- [GetProcAddress Function](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress)



## Viewing DLL Exports Using **'dumpbin'**

Open the **Visual Studio Native Tools Command Prompt**

### **Without** `extern "C"` the DLL function exports become name mangled

```
c:\Users\cmart\OneDrive\Documents\Scripts\CPP\DLL_Fun>dumpbin /exports dlltest.dll
Microsoft (R) COFF/PE Dumper Version 14.36.32532.0
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file dlltest.dll

File Type: DLL

  Section contains the following exports for dlltest.dll

    00000000 characteristics
    6492F429 time date stamp Wed Jun 21 08:59:21 2023
        0.00 version
           1 ordinal base
           2 number of functions
           2 number of names

    ordinal hint RVA      name

          1    0 00001332 _Z10dll_hijackv
          2    1 00001304 _Z8testfuncv

  Summary

        1000 .CRT
        1000 .bss
        1000 .data
        1000 .debug_abbrev
        1000 .debug_aranges
        2000 .debug_info
        1000 .debug_line
        1000 .edata
        1000 .eh_frame
        1000 .idata
        1000 .rdata
        1000 .reloc
        1000 .text
        1000 .tls
```

### **With** `extern "C"` the DLL functions are exported with the correct names

This allows for easier calling from `main.cpp`

```
c:\Users\%user%\Documents\DLL_Test> dumpbin /exports dlltest.dll

Microsoft (R) COFF/PE Dumper Version 14.36.32532.0
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file dlltest.dll

File Type: DLL

  Section contains the following exports for dlltest.dll

    00000000 characteristics
    6490B78D time date stamp Mon Jun 19 16:16:13 2023
        0.00 version
           1 ordinal base
           2 number of functions
           2 number of names

    ordinal hint RVA      name

          1    0 0000131B dll_hijack
          2    1 000012ED testfunc

  Summary

        1000 .CRT
        1000 .bss
        1000 .data
        1000 .debug_abbrev
        1000 .debug_aranges
        2000 .debug_info
        1000 .debug_line
        1000 .edata
        1000 .eh_frame
        1000 .idata
        1000 .rdata
        1000 .reloc
        1000 .text
        1000 .tls
```
