# Mixed vcpkg Static and Dynamic Libraries in Classic Mode

This project demonstrates how to use vcpkg installed static and dynamic libraries in classic mode.

## Install Packages Using vcpkg

### Dynamic Packages

To install dynamic packages, use the following command. It will install both *release* and *debug*
libraries.

`vcpkg packgename:x64-windows --clean-after-build`


### Static Packages

To install static packages, use the following command. It will install both *release* and *debug*
libraries.

`vcpkg packgename:x64-windows-static --clean-after-build`


## CMakePresets.json

vcpkg CMake toolchain needs to be defined for finding installed packages. By default, vcpkg looks
for dynamic packages. To find static packages, **CMAKE_PREFIX_PATH** can be defined after dynamic
package findings in *CMakeLists.txt* for static package search paths. For vcpkg, the path is:
`$env{VCPKG_ROOT}/installed/x64-windows-static`. Other non-vcpkg static paths can be appended too.

**CMAKE_MSVC_RUNTIME_LIBRARY** should be set as *MultiThreaded* for *release* build and
*MultiThreadedDebug* for *debug* build.
