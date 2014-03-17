#!/usr/bin/env python
# coding: utf-8
from distutils.core import setup
from distutils.extension import Extension

path_to_boost = 'c:\\home\\third_party\\boost_1_55_0\\boost_1_55_0'

setup( name="PackageName",
    ext_modules=[
        Extension("hello_ext", [  # с таким именем будем ипортировать в питон
            "logger.cc",
            ],
            library_dirs = [path_to_boost+'\\builded_lib\\msvc-9.0\\lib'],
            libraries = [
                "boost_python-vc90-mt-1_55", 
                ],
            include_dirs = [
                #"../",
                #"../no-standart-dependenses/",
                #"../third_party/gmock-1.6.0/fused-src",
                path_to_boost,
                "d:/Python27/include",
                "D:/Program Files/Microsoft SDKs/Windows/v6.1/Include"],
        )
    ])
    
# move module