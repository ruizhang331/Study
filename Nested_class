class mother(object):
    def __init__(self):
        self.var1 = 1
    class child(object):
        def __init__(self):
            self.var2 = mother().var1 +1

if __name__ == "__main__":
    a = mother()
    b = mother().child()

    print a.var1
    print b.var2


######Or we can have
class mother(object):
    var1 = 1
    def __init__(self):
        pass
    class child(object):
        def __init__(self,mother):
            self.var2 = mother.var1 +1


if __name__ == "__main__":
    a = mother()
    b = mother().child(mother)
