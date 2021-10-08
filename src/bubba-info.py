#! /usr/bin/python2.6

__version__ = "1.0"

import ctypes, ctypes.util
lib = ctypes.CDLL(ctypes.util.find_library('bubba-info'))

def getHWType():
	return lib.getHWType(None)

def isB1():
	return lib.isB1(None) > 0

def isB2():
	return lib.isB2(None) > 0

def isB3():
	return lib.isB3(None) > 0

# For testing only
if __name__ == '__main__':
    print getHWType();
    print isB1();
    print isB2();
    print isB3();
