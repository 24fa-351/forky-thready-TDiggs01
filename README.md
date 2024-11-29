# 351-five: Do the Forky-Thready thing in Assignment 5

Write a program that takes three arguments: 
- the number of “things” (between 1 and 256) 
- a “pattern number” (1, 2, 3).


Create as many subprocesses (“things”) as the number. 

Implement the forking pattern as below. Arrows represent which process creates the next process.

forky-thready patterns.png

(Pattern 3 is optional)

Each process should output (say) “Process 3 beginning”, then sleep for a random number of seconds (say, 1-8). If it created processes, it should output a message "Process 3 creating Process 4", then wait for them to complete, then output “Process 3 exiting”. It is optional (but desired) that you include the PID in this output ("Process 2 (5232) started Process 3 (5237)").

In pattern 1, it is desired that you fork ALL processes before you start waiting for them. In other words, multiple processes will be executed at "the same" time. However, you can start with "fork one, wait one" as a first version. 

Capture several runs of terminal output and CHECK IT IN as "results.txt".

Extra Credit: 50 points for implementing Pattern 3.


- Create processes

- Wait for them

- Output messages to a text file.

   - Commit the text file here as "results.txt"

- Professional!

  
