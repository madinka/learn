#!/usr/bin/env python
from distutils.core import setup
from distutils.extension import Extension

setup( name="PackageName",
    ext_modules=[
        Extension("protocols_module", [
            "../no-standart-dependenses/protocols/protocols_py.cc",
            "../no-standart-dependenses/protocols/protocols.cc",
            "../no-standart-dependenses/transports/rs485.cc",
            "../no-standart-dependenses/tools/debug_tools.cc",
            "../no-standart-dependenses/uni_convertors/simple_type_processors.cc",
            ],
            library_dirs = ['D:\\home\\third_party\\cc\\boost_1_55_0\\builded_lib\\msvc-9.0\\lib'],
            libraries = [
                "boost_python-vc90-mt-1_55", 
                #"libboost_system-vc90-mt-1_55"
                ],
            include_dirs = [
                "../",
                "../no-standart-dependenses/",
                "../third_party/gmock-1.6.0/fused-src",
                "D:/home/third_party/cc/boost_1_55_0",
                "d:/Python27/include",
                "D:/Program Files/Microsoft SDKs/Windows/v6.1/Include"],
        )
    ])