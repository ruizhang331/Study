import time


def func_a(value):
    num = yield do_something(value)
    time.sleep(3)
    num2 = yield do_something_more(num)
    print num2+1



def do_something(value):
    print value
    return value*2



def do_something_more(num):
    print num*2
    return num*2



if __name__ == "__main__":
    m = func_a(1)
    print m
    m.send(m.next())
