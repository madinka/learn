set VER=msvc-9.0
rem bjam ^
rem   -j2 ^
rem   --toolset=%VER% ^
rem   release debug ^
rem   --with-python ^
rem   -sPYTHON_VERSION=2.7 -sPYTHON_ROOT=d:/Python27 ^
rem   threading=multi link=static link=shared runtime-link=shared ^
rem   stage --stagedir="builded_lib/%VER%"
rem   pause
  
bjam --toolset=%VER% --user-config=user-config.jam --with-python threading=multi link=static link=shared runtime-link=shared stage --stagedir="builded_lib/%VER%"
pause