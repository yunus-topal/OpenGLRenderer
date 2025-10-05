# How to build the executable

To run the engine as is, you need to install 
- [vcpkg](https://vcpkg.io/en/) and add root folder of vcpkg to your environment variables as VCPKG_ROOT.
- install [cmake](https://cmake.org/download/)

Then open the project with CLion or Visual Studio and load CMake presets. Then you can execute debug or release configurations through IDEs.

If you want to build it manually (and you have Visual Studio installed)
- Open “x64 Native Tools Command Prompt for VS 2022”
- Navigate to project root
- Run debug or release preset:
``` bash
cmake --preset debug
cmake --build --preset debug
```
- sandbox.exe will be in build/debug(release) folder.

If you don't have Visual Studio installed, you might get an error about missing C++ compiler paths. 
In that case, you can download a C++ compiler and add it to your path or add it to the cached variables of the CMakePresets.json file.
