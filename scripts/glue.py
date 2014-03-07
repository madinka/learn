# coding: utf-8


def work(planet, talker):
    """
        Решает поставленную задачу, используя передынные ей объеты
    """
    planet.set('howdy')
    print planet.greet()
    print talker.say()


def run_pure_py():
    # Build
    import hello_ext
    string_di = 'yes'
    hello = hello_ext.Hello(string_di)  # Оборачиваем в python
    talker = hello_ext.Talker(hello)
    planet = hello_ext.World(string_di)

    # Work
    work(planet, talker)




