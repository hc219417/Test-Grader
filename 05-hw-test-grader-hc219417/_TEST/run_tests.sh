#!/bin/bash
echo '\033[0;33m'"###################################################################" '\033[m'
echo '\033[0;33m'"The following should produce errors" '\033[m'
echo '\033[0;33m'"###################################################################" '\033[m'
_TEST/a.out
echo
_TEST/a.out quizzes.txt
echo
_TEST/a.out a b 
echo
echo
_TEST/a.out a b c
echo
echo '\033[0;33m'"###################################################################" '\033[m'
echo '\033[0;33m'"The following command should produce the correct report in output.txt" '\033[m'
echo '\033[0;33m'"###################################################################" '\033[m'
echo _TEST/a.out _TEST/tests.txt output.txt
_TEST/a.out _TEST/tests.txt output.txt
echo
echo '\033[0;33m'"###################################################################" '\033[m'
echo '\033[0;33m'"Below is the content of output.txt" '\033[m'
echo '\033[0;33m'"###################################################################" '\033[m'
cat output.txt
echo
