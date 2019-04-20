# readme file for createCurve C Program
# Isaac Powrie
# 2018-11-19

createCurve

THE PROJECT

  The idea behind this project was to create a simple C program for outputing a variety of "curves",
as represented by an SVG file graph. The ouput files record approxiamtely ten thousand ordinal pairs, wo that the resulting images can be zoomed into without becoming pixelated. Users determine the destination of the output file, and a user may create as many SVG files in one execution of the program as they would like.

CURRENT SCOPE

There are currently four patterns which the user can select from:

1.) Linear: y = m(x + c) + b
2.) Quadratic: y = m(x + c)^2 + b
3.) Sine: y = m * cos(x + c) + b
4.) Cosine: y = m * cos(x + c) + b

Any of the constants m, b, and c can be adjusted by the user before output to a file. Currently, 
all constants are stored as integer datatype, and they will accept any integer value, positive
or negative.

LIMITATIONS

Because the constants are stored as integer datatype, there is not any way to represent factions.
This is a simple limitation to overcome by small adjustments to the code, but currently exists as
a limitation of use.

POSSIBLE ADDITIONS

The simplest way to add to the program is to add another function pattern. Really there is no 
limit to the number of patterns this program could hold, and with some further addition to the 
Function struct, multivariable functions could also be included.

The addition that I would first make though is to add functionality to check if the file which
the user has decided to write to already exists. If the file exists, the user should be warned 
that it will be overwritten if the program continues, and possibly even be given some options 
about how to open the file.
