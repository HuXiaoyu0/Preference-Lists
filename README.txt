# Preference-Lists
data structure, homework 4

In this assignment you will write a program to manage the preferences and rankings between schools and
applicants who wish to enroll at those schools. Your program will handle several different operations: adding
a school and the ranking of students that the school is interested in admitting to their program, adding
a student and the ranking of schools that applicant is interested in attending, editing (adding/removing)
preferences, and printing the current state of these lists.

The input for the program will come from a file and the output will also go to a file. These file names are
specified by command-line arguments. Here’s an example of how the program will be called:
preferences.exe requests.txt results.txt

Then the program uses Gale-Shapley algorithm to perform the matching.

The output will be a .txt file indicating the preference list of all the schools and students. It looks like this:
dartmouth preference list:
  1. mary_kramer
  2. harold_chen
  3. daniel_myers
  4. bob_evans
  5. paul_weston
  6. sally_jones
  7. ryan_roberts
...
larry_roberts preference list:
  1. university_of_washington
  2. georgia_tech
  3. university_of_pennsylvania
...
