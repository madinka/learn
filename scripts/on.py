# coding: utf-8

"""
detector.upOutPower()

for i in range(8):
    detector.upRefPower()
"""


class MyStateClock(object):
    def __init__(self, minutes):
        self.min_ = minutes

    def reset(self):
        print self.min_


def main():
    clock = MyStateClock(9)

    clock.reset()
    print 0


if __name__ == '__main__':
    main()


