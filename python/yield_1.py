import time
from collections import deque

def foo():
    for n in xrange(5):
        print("I am foo %d" %n)
        yield 3

def bar():
    for n in xrange(7):
        print("I am bar %d" %n)
        yield 4


def spam():
    for n in xrange(10):
        print("I am spam %d" %n)
        yield 5

if __name__ == "__main__":
    task_queue = deque()
    task_queue.append(foo())
    task_queue.append(bar())
    task_queue.append(spam())

    while(task_queue):
        task = task_queue.pop()
        try:
            returned = next(task)
            print returned
            task_queue.appendleft(task)
        except StopIteration:
            pass
