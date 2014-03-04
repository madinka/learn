# coding: utf-8

import hello_ext

print hello_ext.greet()


string_di = 'yes'
planet = hello_ext.World(string_di)
planet.set('howdy')
print planet.greet()

hello = hello_ext.Hello(string_di)
talker = hello_ext.Talker(hello)
print talker.say()


