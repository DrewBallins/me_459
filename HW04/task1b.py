# ME 459 HW04: task1b.py
# Author: Andrew Wild
# This program writes my name on one line to a file called output.txt

"First we must create the file called output.txt"
f = open("output.txt","w")

"Next, I write my first and last name to the first line of the text file"
f.write("Andrew Wild")

"Finally I close the text file"
f.close

