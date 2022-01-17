# ivef-sdk
_Convert ivef.xsd to C++, JAVA and PHP code to easily read or write IVEF_

Makes a parser for IVEF XML in a few steps.
* Step 1: Make a schema to code executable. 
        Needs Qt library version 5 (or maybe even version 4, but definitely not version 6 as there are some breaking changes from the preceding version. 
* Step 2: The executable will generate classes for C++, JAVA or PHP based on a xsd.
        ivef.xsd is used per default, but the schema-to-code can be used for any xsd file.
* Step 3: Build the parser library, which is located at [./ivef-sdk/build/targets/qt/lib](https://github.com/ncs-niva/ivef-sdk/tree/master/ivef-sdk/build/targets/qt/lib)

Examples for how the library can be used to generate XML or read XML are available in the example directory.

## To build
Use Qt's `qmake` and then `make`. Simply run the following commands sequentialy:
1. If the `qmake` path is set correctly as a system-wide environment variable:
```shell
$ qmake
```

2. The long way to go about the setting of `make` is to do the following so there will be no conflict with existing alternative `make` installations on the same PC:
```shell
$ C:\Qt\Qt5.12.12\Tools\mingw730_64\bin\mingw32-make.exe
```

Results (schema to code executable, libraries and examples) are then generated in the build. 

The build will then be located at the [./ivef-sdk/ivef-sdk/build/](https://github.com/ncs-niva/ivef-sdk/tree/master/ivef-sdk/build) directory once the compilation is complete. Pleaes make sure to install version 5 of Qt before attempting to build from scratch as from https://github.com/openivef/ivef-sdk. 

If you are using a Windows OS, please take care to use the `qmake` executable at something similar to `C:\Qt\Qt5.12.12\5.12.12\mingw73_64\bin\qmake.exe`, beware to use the version with 64 for 64-bit and 32 for 32-bit depending on the CPU. On the other hand, for the `make` executable, please use the one comes with Qt 5 with a path similar to `C:\Qt\Qt5.12.12\Tools\mingw730_64\bin\mingw32-make.exe`. Please also make sure you have Java installed and the `jar` path properly set. 

## Compatiable Qt version
Tested as of January 2022 with Qt version 5.12.12. Additionally with `java` and `jar` 17. 
