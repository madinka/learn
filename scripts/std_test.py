import mymodulea_foo = Nonedef setup(a_foo_from_cxx):  print 'setup called with', a_foo_from_cxx  global a_foo  a_foo = a_foo_from_cxx    print "Assigned"def run():  print len(a_foo.myFuncGet())  result = a_foo.myFuncGet()    real = mymodule.MyListClass()  real.append(8)  print real[0]  a_foo.myFuncSet(real)  passprint 'main module loaded'