# readme file for Canal project
// author: Isaac Powrie
// date: 2019-01-12
// file: readme.txt

CANAL

The Canal program is designed as statistical analysis tool. It's intention is
to connect 1-4 files, each of which may have 15000 datapoints, and perform
meaningful statistical processing on the loaded files. The intro and load menu
are written in C, but they are written in a modular way that is compatible with
C++. The output options are meant to be plugins, which will be designed later
in either C or C++.

CURRENT FUNCTIONALITY

Currently the program loads CSV file data from the file system and holds up to
four such files in memory. The program creates a basic statistical summary that
may be viewed via the start menu. When all files have been loaded the user can
proceed to the output menu.

INTENDED EXPANSION

The output menu should connect to real output functionality. A few examples:

- Print Summary
- Trendline
- Hypothesis Test
- Create Buckets/ Histogram
- Analysis of Variance

LIMITATIONS

The major limitation right now is the way that files are uploaded. The program
can only recognize data from a specifically formatted CSV, and there is no 
way to handle categorical data or titles.
