/*
README file for a 2D Hangman Game
*/
// Isaac Powrie
// 2018-11-20
// ReadMe.txt


"A triumph of modern graphical rendering... breathtaking."
-The New York Times

"Boundless dynamism in a massively imaginative environment, a real pleasure
  to play."
-Theo, age: 3

"Five stars."
-Hangman Quarterly

PURPOSE
  So seriously, this is a simple 2D hangman game I created using C. I am trying to implement modular code, so there are several different sections to this program. I tried to include any game specific functionality in "funcs.c" while more general functionality is housed in "helpers.c". The main function is just an initializer for the real program and the header functions correspond to the source files!
  
THE GAME
  If you are trying it out, the gameplay is pretty straightforward. There is a computer generated option as well as a user entered choice. You select a letter and the program determines if you have revealed more of the solution, or more of the unfortunate 2D man whose life is in your hands. The game remembers your choices and does not allow repeated guesses.
  
POSSIBLE IMPROVEMENTS
  Currently the computer generated options exist in an array that is only initialized if the corresponding option is selected from the main menu. This is an acceptable implementation, but what if we wanted to add a new puzzle after the code had been compiled? We would have to recompile new source code, and although this game is not ever going to be widely distributed, this set up is not ideal if there are a large number of places the original executable exists. One possible improvement therefore is changing that initialization function to read the puzzles into memory from a text file that ships with the program.
  Another Improvement would be a level selection, which could control how many steps of hangperson rendering are advanced through for each wrong answer.
  Lastly, the input for letter guessing currently accepts non letters. This is a pretty easy fix if it is deemed necessary!
