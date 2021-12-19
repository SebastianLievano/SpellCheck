# SpellCheck
Spell Checking program designed to quickly check long documents (1000+ words) in less than a second. Dictionary file used is attached.

Usage instructions: All code is contained in spellcheck.cpp file. A sample Dictionary.txt file is provided
Attach a text document named input.txt and run the compiled program to spellcheck. 
A sample input.txt (An excerpt from Arthur Conan Doyles Sherlock Holmes) is also attached.

The program takes 12-14 ms to spellcheck the 13000 word document, averaging around 0.001 ms per word. 

Program also calculates its own duration and checks accuracy of document

Current development status:
- First version out
  - Most punctuation cases are dealt with
  - Added support for selection of file by user
  - Supports large (1'000'000+ word documents) txt files in short times (less than 5 seconds)

Output using the inputlong.txt file attached (source: http://norvig.com/big.txt)


Output for input.txt:  
 

SAMPLE output:
(Detailed error reports above ex:)
Word #13081: spaulding not found in dictionary.
Word found here: this Vincent Spaulding?"
This is error #184 found after 35.992ms


FINAL REPORT: found 185 errors in 13175 words. This document had 98.5958 percent accuracy
PERFORMANCE REPORT
  Spellcheck: 36.171ms
  Average time per word was 0.00274543ms
  Dictionary loaded in 124.445ms
  File "input.txt" loaded in 0.255ms
  Total Run time: 160.998ms
  
output for inputlong.txt

FINAL REPORT: found 35383 errors in 1094861 words. This document had 96.7683 percent accuracy
PERFORMANCE REPORT
  Spellcheck: 1491.28ms
  Average time per word was 0.00136207ms
  Dictionary loaded in 129.679ms
  File "inputlong.txt" loaded in 0.175ms
  Total Run time: 1621.24ms

**Credit for dictionary: **
custom wordlist generated from http://app.aspell.net/create using scowl
with parameters:
  diacritic: both
  max_size: 60
  max_variant: 2
  special: <none>
  spelling: us ca

using git commit from: mon dec 7 20:14:35 2020 -0500 [5ef55f9]

copyright 2000-2019 by kevin atkinson

  permission to use, copy, modify, distribute and sell these word
  lists, the associated scripts, the output created from the scripts,
  and its documentation for any purpose is hereby granted without fee,
  provided that the above copyright notice appears in all copies and
  that both that copyright notice and this permission notice appear in
  supporting documentation. kevin atkinson makes no representations
  about the suitability of this array for any purpose. it is provided
  "as is" without express or implied warranty.

copyright (c) j ross beresford 1993-1999. all rights reserved.

  the following restriction is placed on the use of this publication:
  if the uk advanced cryptics dictionary is used in a software package
  or redistributed in any form, the copyright notice must be
  prominently displayed and the text of this document must be included
  verbatim.

  there are no other restrictions: i would like to see the list
  distributed as widely as possible.

special credit also goes to alan beale <biljir@pobox.com> as he has
given me an incredible amount of feedback and created a number of
special lists (those found in the supplement) in order to help improve
the overall quality of scowl.

many sources were used in the creation of scowl, most of them were in
the public domain or used indirectly.  for a full list please see the
scowl readme.

http://wordlist.aspell.net/
