from Models import spring_motion as sm
from Models import unperturbed_planetary_motion as upm
from Models import planetary_system as ps

def startSpringMotion(main_menu_window, toBeShown): 
    sm.spring_motion_layout(main_menu_window, toBeShown)

def startUnperturbedPlanetaryMotion():
    upm.input_unperturbed_planetry_motion()

def startPlanetarySystem():
    ps.input_planetary_system()


