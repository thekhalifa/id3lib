# id3lib



This is an attempt at reviving this 20-year old bit of code whilst
keeping it functional whereever it is already being used.

This repository is based on the original sf repo with version 3.8.3 with
several Debian patches applied and then a cmake build system added to
replace autoconf/libtool and countless scripts.

The original README contents are shown below as-is, but most
links and mailing lists are no longer there.

------------------------------------------------------------------------


id3lib is a software library for manipulating ID3v1/v1.1 and ID3v2 tags.
id3lib 3.0.x conforms to all ID3v2 standards up to and including the ID3v2.3.0
informal standard.

The id3lib project makes use of the resources available through
SourceForge.net.  Using SourceForge, the id3lib project is able to provide
several tools for developers, including a project homepage, a mailing list, a
patch manager, bug tracking, and cvs access, among other things.

The id3lib project page, which includes links to all of the above, is:
  http://sourceforge.net/project/?group_id=979

The official id3lib homepage is:
  http://id3lib.sourceforge.net

The id3lib developers' mailing list's address is:
  id3lib-devel@lists.sourceforge.net

You can subscribe, unsubscribe, and view mailing list archives at:
  http://lists.sourceforge.net/mailman/listinfo/id3lib-devel

Information about ID3v2 and related standards can be found at: 
   http://www.id3.org


# Installation

See the file 'INSTALL'


# Requirements

In order to successfully compile and use id3lib, the following programs and
libraries are needed:

Compiling:
----------
g++ 2.8/egcs 1.0.3 (or compatible)
GNU make
autoconf 2.13
automake 1.4
zlib
doxygen (optional, for creating documentation)

Using:
----------
zlib


# How to report bugs


To report a bug, submit it to the bug tracker, linked to from the id3lib
project page, or send mail to the id3lib-devel mailing list.

If you send it to the mailing list, please include the following:

* The version of id3lib

* Information about your system. For instance:

   - What operating system and version
   - For Linux, what version of the C library

  And anything else you think is relevant.

* How to reproduce the bug. 

  Please include either a short test program that exhibits the 
  behavior or an example tag that isn't correctly parsed/rendered by
  the library.  As a last resort, you can also provide a pointer to
  a larger piece of software or tagged file that can be downloaded.

* If the bug was a crash, the exact text that was printed out
  when the crash occured.

* Further information such as stack traces may be useful, but
  is not necessary.

# Patches

Patches can be submitted to the patch manager at the id3lib project page, as
mentioned above.  Please follow the instructions there.  So as not to annoy
uniterested parties with large email messages, it is preferable that you not
send such patches to the mailing list.

# For Further Reading

id3lib is free software. Please see the COPYING file for details.
For documentation, please see the files in the doc subdirectory.
See the HISTORY file for information about development up to version 3.05a.
See the NEWS file for information about development since 3.05a.
See the ChangeLog file for an account of changes made to files in the library.
See the AUTHORS and THANKS files to see who has contributed to id3lib.
