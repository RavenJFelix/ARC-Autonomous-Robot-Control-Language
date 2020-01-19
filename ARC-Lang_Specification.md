Autonomous Robot Control Language
=================================
# Introduction
ARC is a specification language that is designed to be used for a
variety of robots in a understandable manner. The language itself
is not "definite" because each robot has it's own commands and whatnot.
What the specification goes over is basic syntax, commonly used commands,
and extension tips.
(We are nearing an era where we will need a RELEASE LeDrones command in a few years)

# ARC Syntax Levels Modules Overview
## Instruction Modules
There are two parts to the ARC language, the Core module and the Extended module.  
__Core:__ pertains to operations and commands use universally by any robot regardless of
hardware. Examples are storing variables, waiting, and outputting to the screen.

__Extended:__ Deals with syntax that is added by the programming team. Commonly used
Extended commands(or since ARC is just starting, likely) such as moving and rotating will
be discussed in the specification.

## Syntax Levels
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

# Basic Syntax Level, Core Instructions, and Basic General Extended Instructions
The most commonly used approach in writing an autonomous robot program is to
simply write out exactly what a robot will do. Most programmers will
know that this involves highly technical function calls to multiple
motors at the same time each time you merely want to move a foot forward.
This is less true for more advanced teams although since the instructions
are hard-coded, now the program has to be recompiled each time a small
change is desired in trial and error.

## Instruction Syntax
Here is an example of moving a robot a couple of feet forward.
```
MOVE 5 ft
```
Simple, isn't it?

The first part of the instruction is the _Command_, in this case MOVE is the command.

#### IMPORTANT NOTE ON CASES
The ARC specification __does not__ require for the commands to be in all capital,
in terms of style, it is recommended; however, in the heat of programming,
or use of alternative styles, flexibility is key.  Although there is no
ethical justification fOr uSIng mIXeD cAPs sInCe ThAt iS haRD to REaD anD tYPE
aLThOugH You STIll cAN. It is easier to implement one or the other. Or, as in
programming or.

Anything that follows are called _Command Parameters_, these are values which
the command uses for more detail.

5 is the parameter for how much feet to move, and feet is specifying what unit the movement is.
More details on the MOVE command will be supplied.

## Instruction Notation
Instruction shorthand is a quick way of
saying, "here's how to write this command" and whatnot. It may seem cryptic as first,
but for quick reference, it is highly useful. Here is the notation that will be used
in this specification manual.
```
MOVE $number \[$unit\]
```
Anything that comes with a $ sign is a variable, for example $number could be a 4, 5, or 
10 million.

```
MOVE 4
MOVE 5
MOVE 10000000000 ; To a Galaxy Far Far Away...
```
Anything in brackets is optional and can be ommited. The shorthand notation
will not give the default value. The default values will be specified for the Core
instructions although the Core Commands can be adapted none-theless. The default values
for the _Extended Commands_ will be simply guidelines as various environments need
various configurations.

### Command Abbreviations
In the rage of development it may be tedious to those who do not use vim
or suck at typing to type out the commands even in mere lowercase.

Instead of having to type MOVE, one could simply say M, the abbreviation(if any)
will be given at end of the command's shorthand.

MOVE (insert command stuff here) Abreviation: M
### Variables
All variables will be defined by STORE(more in the Core Commands section) and then
called with a $ sign.
```
STORE yeets 10
MOVE $yeets ft
```
### Comments
Single line commands will be delimited with a semicolon(;), anything else after the
semicolon in the line will be ignored.
```
MOVE 10 ft ; yeqpwepoiuqwpoeiurqer
```

Multiline comments will start with /* and end with */. Everything in between will be
ignored.

```
MOVE 5 ft
/* ree ree ree
MOVE 109234870128374 ft
STORE 10239487

### Units
Units refer to physical measurements.
Standard units for easy parsing are
Distance: Milimeters
Time:  Miliseconds
Rotation: Degrees
(This is to avoid having to parse for a decimal.)

Better units:  
Distance: Meters  
Time: Miliseconds  
Rotation: Degress(Can be converted to radians in functions since they are
more elegant with math formulae)

#### Units of rotation
Degrees will be denoted as $numberd i.e. 180d
Radians will be denoted as $numberr i.e. 3.14r

### Command Delimiter
For ease of interpreting, the new-line character will determine
the end of a command.

### Error Detection
To prevent bad things from happening, always have the program
check for bad calls. Always...

## Core Commands and Examples

### STORE
STORE $datatype $any-value-to-your-heart's-desire Abbreviation: S

The command tells the program to remember a value for later retrieval. The Level 0 syntax
has __no__ concept of cope. All variables can be seen throughout the rest of the program


### WAIT
WAIT $duration \[$time_unit\] Abbreviation: W

```
WAIT 1000 ms ;Pauses for 1000 milliseconds
```
### PRINT
PRINT $message Abbreviation: P
Writes message to output screen

```
PRINT "Yee Yee" ;used if there are spaces
PRINT WOOF; shorter form
PRINT "Bot says, \"Hi\"" ;escape characters(not required) to output delimiters
```
### LOG
LOG $message Abbreviation: L
Writes message to log file

## Commonly used Extended Commands
These commands are not part of the spec, these are merely guidelines, although to be honest,
every spec is a guideline although it's not like the ARC code you write will be used
on a vastly different robot.

### MOVE
MOVE $distance \[$unit\] \[speed\] Abbreviation: M
MOVE $direction $distance \[$unit\] Abbreviation: M
Positive values move the Robot forward and
Negative values move the Robot backward unless a direction is included
How the direction is interpred is up to the programmer.
In this case, the direction is degrees from north. It could easily
have been degrees from current position.

The default unit will be milimeters(this is an example lmao)

A default speed needs to be set as well.

```
MOVE 10
MOVE 100 mm
MOVE 123d 100 mm ;move 100 millimeters 123 degrees
counter-clockwise from north. This syntax would be useful
with robots that do not have to rotate to move i.e. leDronez.
```
### ROTATE
ROTATE $amount abbreviation: ROT, R

Rotates the robot amount of degrees clockwise from it's current position

## Simultaenous Execution
In general, the computer will not move on into the next command
until the previous command has been finished. Multiple commands
can be executed at the same time by appending a &.
```
MOVE 100 mm &
ROT 120d 

## FORcing time
when the FOR statement is appended to a command, a duration can be
set if needed.
```
MOVE 10 ft FOR 10 s
MOVE 1000 ft FOR 1 s ; this will likely be rejected by the program
; or "clamped" to a safe value by the programmer or robot api. 
; if not, prepare for explosions and the speed of sound being broken.
```

## AT statements
I forgot what at statements were supposed to do, I head the idea just a few
hours ago oof. It was similar to FOR statements


