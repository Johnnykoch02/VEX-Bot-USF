
def get_dTheta(ti, tf):
    positiveDTheta = ((tf+360)-ti)%360
    negativeDTheta = -360 + positiveDTheta
    
    return positiveDTheta if abs(positiveDTheta) <= abs(negativeDTheta) else  negativeDTheta


print(get_dTheta(90, -93))


import gzip
import os
import numpy as np
from pixy2.build.python_demos.ObjDetector import ObjDetector


def format_obj(obj):
    return ('{:.2f} {:.2f} {:.2f} {:.2f} {:.2f}'.format(obj.m_signature, obj.m_x, obj.m_y, obj.m_width, obj.m_height))


ObjDetector = ObjDetector()
ds = []

while input('Continue?\n') != 'n':
    set_frame = input('Press Enter when you are Ready to Take a Frame...')
    objs = ObjDetector.get_objs()
    for p, obj in enumerate(objs):
	    if (obj.m_signature == 2):
		    print(format_obj(obj))
		    if input('Set this Object?\n') == 'y':
			    xycoords = [float(i) for i in input().split(' ')]
			    ds.append([obj.m_signature, obj.m_x, obj.m_y, obj.m_width, obj.m_height, xycoords[0], xycoords[1]])

# yelow: 2, blue: 7, red: 1
		