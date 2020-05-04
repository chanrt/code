import numpy as np
from matplotlib import pyplot
import scipy

def calc_dist(planet1, planet2):

    x_dist = planet2['x'] - planet1['x']
    y_dist = planet2['y'] - planet1['y']

    distance = np.sqrt(x_dist**2 + y_dist**2)

    return distance

def calc_next(plnt_init, planets, prec, cnst):

    plnt_final = {}
    x_retard, y_retard = 0.0, 0.0

    for planet in planets:
        deno = (calc_dist(plnt_init, planet))**3
        
        x_retard = x_retard + (prec * planet['m'] * (plnt_init['x'] - planet['x']) / deno)
        y_retard = y_retard + (prec * planet['m'] * (plnt_init['y'] - planet['y']) / deno)

    deno = plnt_init['r']**3
    plnt_final['vx'] = plnt_init['vx'] - x_retard - (cnst * plnt_init['x'] / deno)
    plnt_final['vy'] = plnt_init['vy'] - y_retard - (cnst * plnt_init['y'] / deno)

    plnt_final['x'] = plnt_init['x'] + (prec * plnt_final['vx'])
    plnt_final['y'] = plnt_init['y'] + (prec * plnt_final['vy'])

    plnt_final['r'] = np.sqrt(plnt_final['x']**2 + plnt_final['y']**2)
    plnt_final['m'] = plnt_init['m']
    plnt_final['i'] = plnt_init['i']

    return plnt_final

def planetary_system(planets, prec, star_mass, time, num):

    runtime = 0.0
    plnt_final = {}
    cnst = prec * star_mass
    x_pos, y_pos, x_vel, y_vel, r_pos, t_pos, siz = [], [], [], [], [], [], []
    
    while runtime <= time:

        for times in range(1, num + 1):
            planet = planets.pop(0)
            print("Planet: %d\tX: %.4f\tY: %.4f\tVx: %.4f\tVy: %.4f\tTime: %.4f" % (planet['i'], planet['x'], planet['y'], planet['vx'], planet['vy'], runtime))

            x_pos.append(planet['x'])
            y_pos.append(planet['y'])
            x_vel.append(planet['vx'])
            y_vel.append(planet['vy'])
            r_pos.append(planet['r'])
            t_pos.append(runtime)
            siz.append(1)

            plnt_final = calc_next(planet, planets, prec, cnst)

            planets.append(plnt_final)
            runtime = runtime + prec

    x_array = np.array(x_pos)
    y_array = np.array(y_pos)

    pyplot.scatter(x_array, y_array, s = siz)
    pyplot.scatter(0,0)
    pyplot.show()

def input_planetary_system():

    print("\n\n---> Planetary system model <---")
    print("Method of computation: numerical\nSuggested digression value: 0.5\nSuggested mass of star (for stable orbits): 100")

    planets = []
    plnt, plnt2 = {}, {}

    try:
        predef = input("\nDo you want the pre-defined state?\n1: Planet ejection\n2: Precession of orbit\n0: No\nType 'exit' for quitting the model\nYour choice: ")
    except RuntimeError:
        return
    else:

        if predef == 'exit':
            return

        else:
            predef = int(predef)

        if predef == 1:

            num = 2

            plnt['i'] = 1
            plnt['x'] = -5
            plnt['y'] = -5
            plnt['vx'] = -3
            plnt['vy'] = 3
            plnt['m'] = 1
            plnt['r'] = np.sqrt(plnt['x']**2 + plnt['y']**2)
            planets.append(plnt)

            plnt2['i'] = 2
            plnt2['x'] = 0
            plnt2['y'] = 5
            plnt2['vx'] = 4.5
            plnt2['vy'] = 0
            plnt2['m'] = 1
            plnt2['r'] = np.sqrt(plnt2['x']**2 + plnt2['y']**2)
            planets.append(plnt2)

            prec = 0.01
            time = 41.5
            star_mass = 100

            planetary_system(planets, prec, star_mass, time, num)

        if predef == 2:

            num = 1

            plnt2['i'] = 1
            plnt2['x'] = 3
            plnt2['y'] = 3
            plnt2['vx'] = 1
            plnt2['vy'] = -1
            plnt2['m'] = 1
            plnt2['r'] = np.sqrt(plnt2['x']**2 + plnt2['y']**2)
            planets.append(plnt2)

            prec = 0.01
            time = 40
            star_mass = 100

            planetary_system(planets, prec, star_mass, time, num)

        if predef == 3:

            num = 2

            plnt['i'] = 1
            plnt['x'] = 5
            plnt['y'] = 0
            plnt['vx'] = 20
            plnt['vy'] = 0
            plnt['m'] = 100
            plnt['r'] = np.sqrt(plnt['x']**2 + plnt['y']**2)
            planets.append(plnt)

            plnt2['i'] = 2
            plnt2['x'] = 2.5
            plnt2['y'] = 2.5
            plnt2['vx'] = 0
            plnt2['vy'] = 0
            plnt2['m'] = 1
            plnt2['r'] = np.sqrt(plnt2['x']**2 + plnt2['y']**2)
            planets.append(plnt2)

            prec = 0.01
            time = 4
            star_mass = 100

            planetary_system(planets, prec, star_mass, time, num)


        else:

            num = int(input("How many planets are there in your system? :"))

            count = 1
            while count <= num:
                print("\n--- Planet %d ---" % (count))
            
                plnt['i'] = count
                plnt['x'] = float(input("Enter initial X co-ordinate of planet: "))
                plnt['y'] = float(input("Enter initial Y co-ordinate of planet: "))
                plnt['vx'] = float(input("Enter initial horizontal velocity of planet: "))
                plnt['vy'] = float(input("Enter initial vertical velocity of planet: "))
                plnt['m'] = float(input("Enter mass of the planet: "))
                plnt['r'] = np.sqrt(plnt['x']**2 + plnt['y']**2)

                planets.append(plnt)
                count = count + 1

            print("\n--- Other details ---")
            star_mass = float(input("What's the mass of the star? : "))
            time = int(input("Enter time of simulation: "))
            prec = float(input("Enter digression tolerable: "))

            planetary_system(planets, prec, star_mass, time, num)

