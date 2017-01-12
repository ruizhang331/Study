class Abc:
    def __init__(self):
        self.name="abc name"
    def jsonable(self):
        return self.name

class Doc:
    def __init__(self):
        self.abc=Abc()
    def jsonable(self):
        return self.__dict__

def ComplexHandler(Obj):
    if hasattr(Obj, 'jsonable'):
        return Obj.jsonable()
    else:
        raise TypeError, 'Object of type %s with value of %s is not JSON serializable' % (type(Obj), repr(Obj))

doc=Doc()
print json.dumps(doc, default=ComplexHandler)
