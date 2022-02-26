
def get_dTheta(ti, tf):
    positiveDTheta = ((tf+360)-ti)%360
    negativeDTheta = -360 + positiveDTheta
    
    return positiveDTheta if abs(positiveDTheta) <= abs(negativeDTheta) else  negativeDTheta


print(get_dTheta(90, -93))


