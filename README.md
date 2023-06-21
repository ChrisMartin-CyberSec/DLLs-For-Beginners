# DLLs-For-Beginners

## Simple DLL linking using C++ executable

This repository contains two files: `main.cpp` and `dlltest.cpp`

The `main.cpp` will be compiled as the **executable** .

The `dlltest.cpp` will be compiled as the **dll**.


## Viewing DLL Exports Using 'dumpbin'

Open the **Visual Studio Native Tools Command Prompt**

`c:\Users\%user%\Documents\DLL_Test> **dumpbin /exports dlltest.dll**`

`Microsoft (R) COFF/PE Dumper Version 14.36.32532.0
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

          1    0 0000131B **dll_hijack**
          2    1 000012ED **testfunc**

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
        1000 .tls`
