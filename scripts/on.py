# coding: utf-8

"""
detector.upOutPower()

for i in range(8):
    detector.upRefPower()

Прочитать про:
























   , tuple, (dict), for in, как запускается, import
"""


class MyClock(object):
    def __init__(self, h=0, m=0, s=0):
        self.min_ = m
        self.hour_ = h
        self.sec_ = s

    def reset(self):
        pass

    def sw_(self):
        return " "

    def tick(self):
        if self.sec_ == 59:
            self.sec_ = 0
            self.min_ += 1
        else:
            self.sec_ += 1

        if self.min_ == 60:
            self.min_ = 0
            self.hour_ += 1

    def display(self):
        self.sw_()
        print self.hour_, ':',  self.sw_(), self.min_, ':', self.sw_(), self.sec_, '\r'


def main():
    clock = MyClock()#h=9, m=1, s=50)
    #clock.initialize()  # BAD!
    clock.reset()

    clock.display()


#if __name__ == '__main__':
main()


