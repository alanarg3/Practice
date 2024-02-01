# File: Benford.py
# Student: Alana Gaughan
# UT EID: arg5345
# Course Name: CS303E
#
# Date: 3/31/23
# Description of Program: This program analyzes census data of to determine if town populations across the
# U.S. follow Benford's law.

# Accept a filename from the user .
import os.path

filename = input("Enter a filename: ").strip()
# Check that the file exists .
if not os.path.isfile(filename):
    print("File does not exist.")
    quit()
population_values = set()
leading_digits = {'1': 0, '2': 0, '3': 0, '4': 0, '5': 0, '6': 0, '7': 0, '8': 0, '9': 0}
infile = open(filename,"r")
line = infile.readline()
while line:
    line = infile.readline()
    items = line.split()
    if not items:
        break
    population = items[-1]
    population_values.add(population)
    first_digit = population[0]
    leading_digits[first_digit] += 1
infile.close()
print("Output written to benford.txt")
benford = open('benford.txt', 'w')
total = sum(leading_digits.values())
table = ''
for i in leading_digits:
    digit = i
    count = leading_digits[i]
    percentage = (count / total)* 100
    table += f'{digit}\t\t{count}\t\t{round(percentage, 1)}\n'
benford.write(f"Total number of cities: {total}\n"
              f"Unique population counts: {len(population_values)}\n"
              "First digit frequency distributions:\n"
              "Digit	Count	Percentage\n"
              f"{table}")
benford.close()
