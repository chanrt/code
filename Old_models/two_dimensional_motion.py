import numpy as np
from matplotlib import pyplot

def calc_list(object_init, accn, prec):

    object_final = {}
    object_final['vx'] = object_init['vx']
    object_final['vy'] = object_init['vy'] + prec*accn
    object_final['x'] = object_init['x'] + prec*object_final['vx']
    object_final['y'] = object_init['y'] + prec*object_final['vy']

    return object_final

def two_dimensional_motion(object_init, accn, prec, time):

    onGround = 0
    runtime = 0.0
    x_pos, y_pos, vel_x, vel_y, t_pos = [], [], [], [], []

    while runtime <= time:

        object_final = {}
        x_pos.append(object_init['x'])
        y_pos.append(object_init['y'])
        t_pos.append(runtime)

        if onGround:
            accn = 0
            object_init['vx'] = 0
            object_init['vy'] = 0
        
        vel_x.append(object_init['vx'])
        vel_y.append(object_init['vy'])

        object_final = calc_list(object_init, accn, prec)
        object_init = object_final

        if object_init['y'] <= 0.0:
            onGround = 1

        runtime = runtime + prec

    x_array = np.array(x_pos)
    y_array = np.array(y_pos)
    t_array = np.array(t_pos)

    pyplot.plot(x_array, y_array)
    pyplot.show()

def input_two_dimensional_motion():

    object_init = {}

    object_init['x'] = float(input("Enter initial X co-ordinate: "))
    object_init['y'] = float(input("Enter initial Y co-ordinate: "))
    velocity = float(input("Enter initial velocity of the body: "))

    inDegrees = int(input("Is your angle in 1: Degrees or 2: Radians ? : "))

    if inDegrees == 1:
        angle_proj = float(input("Enter the angle of projection (in degrees): "))
        angle_proj = (np.pi / 180) * angle_proj

    else:
        angle_proj = float(input("Enter the angle of projection (in radians): "))
        
    object_init['vx'] = velocity*np.cos(angle_proj)
    object_init['vy'] = velocity*np.sin(angle_proj)

    accn = float(input("Enter acceleration at that place (negative for downwards): "))
    prec = float(input("Enter digression tolerable: "))
    time = float(input("Enter time of simulation: "))

    two_dimensional_motion(object_init, accn, prec, time)


input_two_dimensional_motion()