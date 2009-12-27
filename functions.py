# import libraries
from agros2d import *
from agros2file import *
from math import *
import sys

# user functions
def addsemicircle(x0, y0, radius, marker = "none"):
	addedge(x0, y0-radius, x0, y0+radius, 180, marker)
	addedge(x0, y0+radius, x0, y0-radius, 0, marker)
	return

def addcircle(x0, y0, radius, marker = "none"):
	addedge(x0, y0-radius, x0, y0+radius, 180, marker)
	addedge(x0, y0+radius, x0, y0-radius, 180, marker)
	return

def addrect(x0, y0, width, height, marker = "none"):
	addedge(x0, y0, x0+width, y0, 0, marker)
	addedge(x0+width, y0, x0+width, y0+height, 0, marker)
	addedge(x0+width, y0+height, x0, y0+height, 0, marker)
	addedge(x0, y0+height, x0, y0, 0, marker)
	return

def agroslistvariables():
	import types
	agrosType = [types.IntType, types.StringType, types.TupleType, types.FloatType, types.BooleanType, types.ListType, types.LongType, types.UnicodeType]

	return filter(lambda x: type(x) in [types.IntType, types.DictType], globals().values())

# redirect script output
class StdoutCatcher:
	def write(self, str):
		capturestdout(str)

sys.stdout = StdoutCatcher()
