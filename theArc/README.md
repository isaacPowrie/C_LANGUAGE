The Arc

FUNCTIONALITY

This is a program which determines and outputs coordinate points which a projectile of a given mass intersects when launched with a given force at a given angle. I imagine that this output is the sort of thing which could be stored and dsiplayed to a user like the ouput of a graphing calculator

MODIFIABILITY

The program is designed so that you or I as the coder determine how detailed the output will be. By modifying the ERROR macro in the functions.h header file, a more detailed and accurate calculation is made for each point. By modifying the TIMESCALE macro in the functions.h header file, more points will be produced for the same trajectory. Another possible adjustment would be to change the inputs from integers to one of the floating point types in order to increase the range of acceptable inputs as well as the specificity of the calculation.

WHY I MADE THIS

I am new to C! I created this program for fun and thought it would be a good first thing to share up here. If you have taken the time to check it out and youre an experienced C coder I'd love to hear your advice or suggestions about the content, form or style! If you are seeing this and you are also a C beginner, feel free to collaborate however you see fit and we can get to know this stuff together.

Thanks all!

PS LIMITATIONS

The program does use a conversion to a long long in the sine and cosine calculations (which by the way are based off of the Taylor series, any input on a different method would be cool to hear). The conversion is used for rounding which is important so that the series always makes correct calculations for basic trig like cos(0). The downside is that the level of specificity for ERROR is constrained by the size of a long long, which is obviously still a lot of space but anyway, the limitation is there!
