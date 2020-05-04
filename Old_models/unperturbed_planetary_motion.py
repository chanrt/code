import numpy as np
from matplotlib import pyplot 

def calc_next(plnt_init, prec, cnst):

    plnt_final = {}
    deno = plnt_init['r']**3

    plnt_final['vx'] = plnt_init['vx'] - (cnst * plnt_init['x'] / deno)
    plnt_final['vy'] = plnt_init['vy'] - (cnst * plnt_init['y'] / deno)
    plnt_final['x'] = plnt_init['x'] + (prec * plnt_final['vx'])
    plnt_final['y'] = plnt_init['y'] + (prec * plnt_final['vy'])
    plnt_final['r'] = np.sqrt(plnt_init['x']**2 + plnt_init['y']**2)

    return plnt_final

def unperturbed_planetry_motion(plnt_init, prec, star_mass, time):

    runtime = 0.0
    plnt_final = {}
    cnst = prec * star_mass
    x_pos, y_pos, x_vel, y_vel, r_pos, t_pos = [], [], [], [], [], []

    while runtime <= time:

        x_pos.append(plnt_init['x'])
        y_pos.append(plnt_init['y'])
        x_vel.append(plnt_init['vx'])
        y_vel.append(plnt_init['vy'])
        r_pos.append(plnt_init['r'])
        t_pos.append(runtime)
        print("Time: %.4f\tX: %.4f\tY: %.4f\tVx: %.4f\tVy: %.4f\tR: %.4f" % (runtime, plnt_init['x'], plnt_init['y'], plnt_init['vx'], plnt_init['vy'], plnt_init['r']))

        if abs(plnt_init['x']) <= prec*10 and abs(plnt_init['y']) <= prec*10:
            print("Planet swirled into star")
            break

        plnt_final = calc_next(plnt_init, prec, cnst)
        plnt_init = plnt_final
        runtime = runtime + prec

    x_array = np.array(x_pos)
    y_array = np.array(y_pos)
    r_array = np.array(r_pos)
    t_array = np.array(t_pos)

    pyplot.plot(x_array, y_array)
    pyplot.scatter(0,0)
    pyplot.show()

    #f, (ax1, ax2, ax3) = pyplot.subplots(nrows = 3, sharex = True)

    #ax1.plot(x_array, y_array)
    #ax2.plot(r_array, t_array)
    #pyplot.show()


def input_unperturbed_planetry_motion():

    plnt_init = {}
    print("\n\n---> Unperturbed planetary motion <---")
    print("Method of computation: Numerical")
    print("Suggested digression: 0.01")
    print("Suggested mass of star (for stable orbits): 100")

    try:
        predef = input("\nDo you want the pre-defined state?\n1: Planet capture\n2: Planet orbit\n0: No\nType 'exit' for quitting the model\nYour choice: ")
    except RuntimeError:
        return
    else:

        if predef == 'exit':
            return
        
        else:
            predef = int(predef)

        if predef == 0:
            plnt_init['x'] = float(input("Enter initial X co-ordinate of planet: "))
            plnt_init['y'] = float(input("Enter initial Y co-ordinate of planet: "))
            plnt_init['vx'] = float(input("Enter initial horizontal velocity of planet: "))
            plnt_init['vy'] = float(input("Enter initial vertical velocity of planet: "))

            star_mass = float(input("Enter mass of the star: "))
            prec = float(input("Enter digression tolerable: "))
            time = int(input("Enter time of simulation: "))
            plnt_init['r'] = np.sqrt(plnt_init['x']**2 + plnt_init['y']**2)

            unperturbed_planetry_motion(plnt_init, prec, star_mass, time)


    # planet capture 1

        elif predef == 1:
            plnt_init['x'] = 0
            plnt_init['y'] = 5
            plnt_init['vx'] = 1
            plnt_init['vy'] = 0
            plnt_init['r'] = np.sqrt(plnt_init['x']**2 + plnt_init['y']**2)
            unperturbed_planetry_motion(plnt_init, 0.01, 100, 10)

    # planet orbit 1

        elif predef == 2:
            plnt_init['x'] = 5
            plnt_init['y'] = 5
            plnt_init['vx'] = 3
            plnt_init['vy'] = -3
            plnt_init['r'] = np.sqrt(plnt_init['x']**2 + plnt_init['y']**2)
            unperturbed_planetry_motion(plnt_init, 0.01, 100, 20)

    # planet capture 2

        elif predef == 3:
            plnt_init['x'] = 3
            plnt_init['y'] = 3
            plnt_init['vx'] = 1
            plnt_init['vy'] = -1
            plnt_init['r'] = np.sqrt(plnt_init['x']**2 + plnt_init['y']**2)
            unperturbed_planetry_motion(plnt_init, 0.01, 100, 20)

    # planet orbit 2

        elif predef == 4:
            plnt_init['x'] = 0
            plnt_init['y'] = 5
            plnt_init['vx'] = 4
            plnt_init['vy'] = 0
            plnt_init['r'] = np.sqrt(plnt_init['x']**2 + plnt_init['y']**2)
            unperturbed_planetry_motion(plnt_init, 0.01, 100, 20)

    # extremely stable orbit

        elif predef == 5:
            plnt_init['x'] = 0
            plnt_init['y'] = 5
            plnt_init['vx'] = 4.5
            plnt_init['vy'] = 0
            plnt_init['r'] = np.sqrt(plnt_init['x']**2 + plnt_init['y']**2)
            unperturbed_planetry_motion(plnt_init, 0.01, 100, 20)

