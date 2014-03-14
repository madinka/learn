# coding: utf-8
#import hello


def work(ptr_cc_object):
    """
        Решает поставленную задачу, используя передынные ей объеты
    """
    ptr_cc_object.set('howdy')
    #print ptr_cc_object.()
    print ptr_cc_object.greet()

def run_pure_py():
    #import hello_ext
    #ptr_cc_object = hello_ext.World(string_di)

    # Build
    import hello_ext
    string_di = 'yes'
    ptr_cc_object = hello_ext.World(string_di)  # Оборачиваем в python

    # Work
    work(ptr_cc_object)
