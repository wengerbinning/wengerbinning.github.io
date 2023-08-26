#!/usr/bin/env python2

class CompileException(Exception):
    def __init__(self, path, output):
        err = 'module:'+path+'\n'
        if isinstance(output, list):
           for line in output:
              err+=(line+'\n')
        else:
            err+=(output+'\n')
        Exception.__init__(self,err)



if __name__ == "__main__":
    print("Run in __main__")
    try:
        raise CompileException("./", "something")
    except CompileException as err:
        print(err)
