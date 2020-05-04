import numpy as np
from matplotlib import pyplot
import tkinter as tk

def calc_next(spring_init, cnst, prec, time, damp_cnst, runtime):

    spring_final = {}

    spring_final['a'] = - (cnst * spring_init['x']) - (damp_cnst * spring_init['v'])
    spring_final['v'] = spring_init['v'] + (spring_final['a'] * prec)
    spring_final['x'] = spring_init['x'] + (spring_final['v'] * prec)

    return spring_final

def spring_motion(spring_init, cnst, prec, time, damp_cnst):
    
    spring_final = {}
    runtime = 0.0
    pos_array, velocity_array, accn_array, time_array = [], [], [], []

    while runtime <= time:

        if toBeShown.get():
            print("Time: %.4f \tPos: %.4f \tVel: %.4f \tAccn: %.4f"% (runtime,spring_init['x'],spring_init['v'],spring_init['a']))

        pos_array.append(spring_init['x'])
        velocity_array.append(spring_init['v'])
        accn_array.append(spring_init['a'])
        time_array.append(runtime)

        spring_final = calc_next(spring_init, cnst, prec, time, damp_cnst, runtime)
        spring_init = spring_final
        runtime = runtime + prec

    f, (ax1, ax2, ax3) = pyplot.subplots(nrows = 3, sharex = True)

    p_array = np.array(pos_array)
    v_array = np.array(velocity_array)
    a_array = np.array(accn_array)
    t_array = np.array(time_array)

    ax1.plot(t_array, p_array, color = 'red')
    ax1.set_title("Position vs Time")

 #   ax1 = pyplot.gca() 
 #   ax1.spines['right'].set_color('none')
 #  ax1.spines['top'].set_color('none')
 #   ax1.xaxis.set_ticks_position('bottom')
 #   ax1.spines['bottom'].set_position(('data',0))
 #   ax1.yaxis.set_ticks_position('left')
 #   ax1.spines['left'].set_position(('data',0))

    ax2.plot(t_array, v_array, color = 'blue')
    ax2.set_title("Velocity vs Time")

    ax3.plot(t_array, a_array, color = 'orange')
    ax3.set_title("Acceleration vs Time")

    pyplot.show()

def spring_motion_input():
    spring_init = {}

    try:
        spring_init['x'] = input("Initial position of the spring (with sign): ")
    except RuntimeError:
        return 
    else:

        if spring_init['x'] == 'exit':
            return
        else:
            spring_init['x'] = float(spring_init['x'])

        spring_init['v'] = float(input("Initial velocity of the spring (with sign): "))

        spring_constant = float(input("Enter spring constant: "))
        block_mass = float(input("Enter block mass: "))
        damp_cnst = float(input("Enter damping constant of the medium (Enter 0 if no damping): "))

        cnst = spring_constant / block_mass
        damp_cnst = damp_cnst / block_mass
        spring_init['a'] = cnst*spring_init['x'] - damp_cnst*spring_init['v']
            
        prec = float(input("Enter digression tolerable: "))
        time = int(input("Enter time of simulation: "))

        spring_motion(spring_init, cnst, prec, time, damp_cnst)

def predef(case):

    spring_init = {}

    if case == 1:

        spring_init['x'] = 5
        spring_init['v'] = 0
        spring_constant = 9
        block_mass = 2
        damp_cnst = 0
        prec = 0.01
        time = 10

        cnst = spring_constant / block_mass
        damp_cnst = damp_cnst/(block_mass)
        spring_init['a'] = spring_constant*spring_init['x'] - damp_cnst*spring_init['v']

    elif case == 2:

        spring_init['x'] = 5
        spring_init['v'] = 0
        spring_constant = 100
        block_mass = 1
        damp_cnst = 1
        prec = 0.01
        time = 10

        cnst = spring_constant / block_mass
        damp_cnst = damp_cnst/(block_mass)
        spring_init['a'] = spring_constant*spring_init['x'] - damp_cnst*spring_init['v']

    spring_motion(spring_init, cnst, prec, time, damp_cnst)

def spring_motion_layout(main_menu_window, toShow):

    global toBeShown
    toBeShown = toShow
    back_window = tk.Tk()
    
    back_window.title("Spring Motion")

    back_button = tk.Button(back_window, text = "Return", padx = 30, command = (lambda: goBack(main_menu_window, back_window)), bg = 'light blue')
    back_button.pack(side = 'top')

    labels_frame = tk.Frame(back_window)
    labels_frame.pack(side = 'top')

    left_predef_label = tk.Label(labels_frame, padx = 10, text = "\nPredefined case 1:\nUndamped motion\n\nInitial position of block: 5\nInitial velocity: 0\nSpring constant: 9\nBlock mass: 2\nDamping constant: 0\nDigression tolerable: 0.01\nTime of simulation: 10\n")
    left_predef_label.pack(side = 'left')

    right_predef_label = tk.Label(labels_frame, padx = 10, text = "\nPredefined case 2:\nDamped motion\n\nInitial position of block: 5\nInitial velocity: 0\nSpring constant: 100\nBlock mass: 1\nDamping constant: 1\nDigression tolerable: 0.01\nTime of simulation: 10\n")
    right_predef_label.pack(side = 'right')

    use_predef_button_1 = tk.Button(back_window, text = "Use predefined case 1", command = (lambda: predef(1)), bg = 'light blue')
    use_predef_button_1.pack(side = 'top')

    use_predef_button_2 = tk.Button(back_window, text = "Use predefined case 2", command = (lambda: predef(2)), bg = 'light blue')
    use_predef_button_2.pack(side = 'top')

    manual_input_button = tk.Button(back_window, text = "User Input", command = (lambda: spring_motion_input()), bg = 'light blue')
    manual_input_button.pack(side = 'top')

    back_window.mainloop()

def goBack(main_menu_window, back_window):

    back_window.destroy()
    main_menu_window.deiconify()
    return