Autonomous Robot Control Language
=================================
#Introduction
ARC is a specification language that is designed to be used for a
variety of robots in a understandable manner. The language itself
is not "definite" because each robot has it's own commands and whatnot.
What the specification goes over is basic syntax, commonly used commands,
and extension tips.
(We are nearing an era where we will need a RELEASE LeDrones command in a few years)

# ARC Syntax Levels Modules Overview
## Modules
There are two parts to the ARC language, the Core module and the Extended module.  
__Core:__ pertains to operations and commands use universally by any robot regardless of
hardware. Examples are storing variables, waiting, and outputting to the screen.

__Extended:__ Deals with syntax that is added by the programming team. Commonly used
Extended commands(or since ARC is just starting, likely) such as moving and rotating will
be discussed in the specification.

## Levels
The syntax of ARC comes with multiple "levels"
Each level adds more functionality(and complexity) upon the previous one.
Never fear though, complex movements can still be programmed accessibly
with the Basic syntax. (And implemented easier as well)

__Level 0: Basic:__ Code is simply read from top to bottom. There are no functions
and no conditional statements. Purely Static since the robot cannot think for itself.
It is a mere slave to predestinated acts by it's programmer overlords.

__Level 1: Logic:__ Includes all functionality of Level 1 but has support for if statements
and loops.

__Level 2: Functions__ Enables the user to group code into functions
which may be called upon by other functions and whatnot.

__Level 3: Modules__ Code can be split into multiple files which are linked together.
Must be writted a certain way in order for the interpreter to understand although looser
requirements for the compiler can be implemented.

# 
