## Author : Girish Bathala, UCSDs
## Title : Transformation between strings ( C++ )

# Description
Transformation of a string from source to destination using only 4 possible operations. Add a charactrer, Delete a character, Replace a character, Replace with anagram. The cost of each operation is given as an input.

Input : Associated cost with each of the above operations :
Say : n1 n2 n3 n4 or 1 3 4 5
The source and destination strings

Output : The cost of transforming one word to another or "-1" if it's not possible

Assumptions : ( According to the sample test cases given in the challenge )
1] Minimum length of each interim word is 3
2] Each word consists of only "CAPITAL" letter (26 in number), 
   if incorperating other ASCII characters the code can be changed accordingly
3] The weight of each edge is positive ( no negative egde weights or cycles ).
   This is required to apply dijkstra's algorithm

*************************************************************************************
# Directory Structure :
headers - Dictionary.h, Graph.h	( Class definitions )
sources	- main.cpp,Dictionary.cpp, Graph.cpp ( Main program and class implementations )
README.txt - read this file for usage before execution
out	- Executable file
*************************************************************************************
# Usage:
1] :$command_prompt: make
If out is up-to-date use :
$command_prompt: ./out

2] Enter the cost of each of the four operations in order: 
( Separate them by spaces )
Add a letter
Delete a letter
Change a letter
Take an anagram of existing word
Ex: 1 3 4 5

3] Enter the source word
HEALTH
4] Enter the destination word
HANDS

5] Output is displayed. Two cases:
a) Shortest cost path from source to destination
b) '-1' if there is no existing path
*************************************************************************************
