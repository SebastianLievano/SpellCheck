# SpellCheck
Spell Checking program designed to quickly check long documents (1000+ words) in less than a second. Dictionary file used is attached.

Usage instructions: All code is contained in spellcheck.cpp file. A sample Dictionary.txt file is provided
Attach a text document named input.txt and run the compiled program to spellcheck. 
A sample input.txt (An excerpt from Arthur Conan Doyles Sherlock Holmes) is also attached.

The program takes 12-14 ms to spellcheck the 13000 word document, averaging around 0.001 ms per word. 

Program also calculates its own duration and checks accuracy of document

Current development state:
- First version out
  - Need to add parsing for integer values and better punctuation support. 
  - More detailed location information on error, maybe a line value.

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
