## Transformation between strings ( C++ )

# Description
Transformation of a string from source to destination using only 4 possible operations. Add a charactrer, Delete a character, Replace a character, Replace with anagram. The cost of each operation is given as an input.

Input : Associated cost with each of the above operations :
Say : n1 n2 n3 n4 or 1 3 4 5
The source and destination strings

Output : The cost of transforming one word to another or "-1" if it's not possible<br />

Assumptions : ( According to the sample test cases given in the challenge )<br />
1] Minimum length of each interim word is 3 <br />
2] Each word consists of only "CAPITAL" letter (26 in number), 
   if incorperating other ASCII characters the code can be changed accordingly<br />
3] The weight of each edge is positive ( no negative egde weights or cycles ).
   This is required to apply dijkstra's algorithm<br />


# Directory Structure :
headers - Dictionary.h, Graph.h	( Class definitions )<br />
sources	- main.cpp,Dictionary.cpp, Graph.cpp ( Main program and class implementations )<br />
README.txt - read this file for usage before execution<br />
out	- Executable file<br />

# Usage:
1] :$command_prompt: make<br />
If out is up-to-date use :<br />
$command_prompt: ./out<br />

2] Enter the cost of each of the four operations in order: <br />
( Separate them by spaces )<br />
Add a letter<br />
Delete a letter<br />
Change a letter<br />
Take an anagram of existing word<br />
Ex: 1 3 4 5<br />

3] Enter the source word<br />
HEALTH<br />
4] Enter the destination word<br />
HANDS<br />

5] Output is displayed. Two cases:<br />
a) Shortest cost path from source to destination<br />
b) '-1' if there is no existing path<br />

