# How to build the executable

- Open “x64 Native Tools Command Prompt for VS 2022”
- Navigate to project root
- Run:
``` bash
cmake --preset debug
cmake --build --preset debug
```
- opengl_renderer.exe will be in build/debug folder.