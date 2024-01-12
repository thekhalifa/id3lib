
# History, Authors, News and Thanks

This file collects the historical files detailing the progress
and contributions of different people to this library.

The contents cover what was previously four separate files:

- Authors
- Thanks
- News
- History

Most of which took place in the years netween 1998-2002.

--

# AUTHORS

    t1mpy: Thijmen Klok <thijmen@id3lib.org>
    /*
    * Only for questions if Thijmen seems to be dead: 
    * shadrack: Cedric Tefft <cedric@earthling.net>
    */

# THANKS

    $Id: THANKS,v 1.20 2003/03/02 16:38:17 t1mpy Exp $

id3lib THANKS file

See the AUTHORS file for a list of past and current project maintainers.

Since version 3.05a, several individuals have helped further the development of
id3lib.  They are listed below, in no particular order.  Please inform the
current project maintainer if anyone has been missed.

* Paul-Henri (paul-henri.ferme@noos.fr) and Christopher John Shaker <(cjshaker@shaker-net.com)
  for pointing out where the code could have been more robust in tag_find.cpp.
* Bradley J. Marker for pointing out that checking for NULL in Set() can
  prevent crashes.
* Todd Wilson for making a better field.cpp.
* Baz (thebaz@pluizig.com) for creating a patch to get vbr info. 
* Tobias Hoppe (choppe@cs.uni-magdeburg.de) for providing a better way to
  get the framesize.
* Philipp Thomas (pthomas@suse.de) for help with compiling id3lib for gcc 3.2,
  and make it better compliant with libstdc++
* John George (johngeorge_k@asianetindia.com) for donating a number of routines
  in misc_support.cpp.
* Frog Prince (thefrogprince@hotmail.com) for helping with compatibility issues
  for VB and Delphi
* Simon Ferrett (simon@musicmatch.com) made the id3lib.org domain point to our
  project page. He also kindly created an email alias.
* Kamran (kamran@musicmatch.com) fixed several bugs in MusicMatch's internal 
  version of ID3Lib which were merged into the current public version of 
  id3lib.
* Alexander Voronin (av@oskarsb.ru) has submitted several patches to fix a 
  variety of bugs.
* John Adcock (johnadcock@hotmail.com) provided the COM wrapper and lib 
  projects for id3lib, the VB test app for id3com.dll, as well as several
  bugfixes and improvements.
* Myers W. Carpenter (myers@fil.org) has submitted a patch for improving the
  interface and functionality of the library.
* Justin Rogers (justin@mlstoday.com) has provided much valuable conversation
  as to the design and implementation of id3lib.
* Mark B. Elrod (elrod@liquidmetal.com) has provided several patches for better
  win32 functionality.
* Scott Moser (smoser@brickies.net) provided the php translation of the 
  original ID3Lib manual
* Robert Moon (rob@emusic.com) provided tremendous help getting the C interface
  up to speed, as well as providing bugfixes for the Windows projects.
* Lothar Egger (lothar.egger@chello.at) also assisted in fixing the Windows
  projects, as well as providing assistance for testing the dlls under Windows
* Severino Delaurenti (id3lib@castlems.com) added functionality for parsing
  Lyrics3 v1.0 and v2.0 tags, as well as improving synchronized lyric frame 
  (SYLT) dramatically.
* Michael Little (mike@netlinear.com) provided the delphi code for use with 
  id3com.
* Peter Luijer (videoripper@hotmail.com) provided much useful documentation
  on the MusicMatch tagging format.
* Steven Frank (stevenf@users.sourceforge.net) provided invaluable help in 
  tracking down runtime bugs for the Macintosh port.
* The following individuals have assisted by providing bug reports and (often)
  suggestions for fixes:
  - Ben Noblet (Ben.Noblet@xt3.com.au)
  - Benedikt Roth (Benedikt.Roth@gmx.net)
  - Christian Becker (chris@craze.de)
  - Daryl Pawluk (dpawluk@home.com)
  - John Firebaugh (jfirebaugh@mac.com)
  - John Southerland (jbsouthe@home.com)
  - Luca Leonardo Scorcia (scrlln@tin.it)
  - Peter Thorstenson (swede@openlink.com.br)
  - Sasa Ðolic (sasad@moderngroove.com)
  - Steven Frank (stevenf@users.sourceforge.net)
  - Tim Newsome (nuisance@cmu.edu)

Dirk Mahoney included the following at the end of his documentation on ID3Lib
3.05a.  It is included in verbatim here.

  Special Thanks and Credits

  I would like to extend my many thanks to the people who have contributed to
  the ID3Lib project.  The show of support has been tremendous.  I consider
  ID3Lib to be a very 'international' product, as contributions have come from
  almost literally every corner of the globe.  If I have missed you, please
  forgive my lapse of memory.

  * Jean-loup Gailly and Mark Adler - for their great zlib compression library
    and for making it free.
  * Tord Jansson - for much help with teaching me how to make and use DLLs.
  * Slava Karpenko for creating the MacOS static link libraries for the PowerPC
    and CodeWarrior.
  * Bob Kohn - for his advice, input, and generally creating the ID3Lib license
    agreement.
  * Eng-Keong Lee - for finding a few bugs and for extensively testing ID3Lib
    2.xx.
  * James Lin - for his 'ID3v2 Programming Guidelines', and many helpful
    suggestions
  * Michael Mutschler - for prompting me to write the Unicode support and for
    his input on the ID3Lib calling convention.
  * Martin Nilsson - for ID3v2, his support of the ID3Lib web page, for many,
    many suggestions, debates, pointers, URLs, documents, and brightly coloured
    fish.
  * Chris Nunn - for the 3D animated ID3v2 logos which appear in the ID3Lib web
    page and in the distribution.
  * Lachlan Pitts - for general implementation ideas and his brief but helpful
    work on the up-coming genre tree.
  * Jukka Poikolainen - for prompting to implement error handling via the C++
    exception handling mechanism instead of the old 2.xx-style of using an 
    error handling function.
  * Carson Puchol - for his help with some minor Linux compilation hassles.
  * Andreas Sigfridsson - for his initial code for the unsync/resync support
    and for his very valuable input in long brainstorming sessions.
  * Michael Robertson - for helping support ID3Lib by posting announcements on
    MP3.com.
  * Ilana Rudnik - for bug finding and suggestions.
  * Chuck Zenkus - for his support of ID3v2 and ID3Lib by providing us with a
    mirror in the United States and for his bug finding and suggestions.
  * And last but by no means least, all the others who support ID3Lib by 
    subscribing to the mailing list and to the contributors to the discussions
    and debates in the ID3v2 discussion group.

  Without the help of all these people, ID3Lib would not be as good as it is, 
  and I dare say might not even exist if they all weren't around to provide
  motivation to continue to write the thing!
  
  - Dirk Mahoney
  22 November 1998
  Brisbane, Australia


# NEWS

    $Id: NEWS,v 1.27 2002/07/23 13:57:45 t1mpy Exp $

this file will not be updated anymore. Please go to 
http://sourceforge.net/news/?group_id=979 for the latest news

Old News:

2001-09-08 Version 3.8.0pre2
* ID3Lib maintainer has disappeared.  Project maintenance taken over by existing
  developers
* Many bug fixes -- mostly compilation problems -- more detailed info will be
  provided in a later release.

2000-11-20 Version 3.8.0pre1

* First prerelease of 3.8.0 stable.
* Clean separation of interface and implementation to help ensure interface and
  binary compatibility of future releases
* Completely revamped implementation of tag reading and writing
* Better debugging output in debug mode
* New documentation (much more still needed)
* Command-line options processing now more cross-platform
* Removed all exception handling
* Minor changes to public interface
* Use of std::string and other STL classes in implementation
* id3com source code removed from source distribution.  It has moved to its own
  project at http://sourceforge.net/projects/id3com
* Many more changes than can be mentioned here:  see ChangeLog file

2000-09-07 Version 3.7.13

* id3com is broken; maintainer has disappeared; anyone care to fix it?
* Complete reimplementation of ID3_Field: cleaner, safer, faster, clearer, more
  efficient
* Much more robust MusicMatch parsing
* Improved conversion from ID3v2 to ID3v1
* Cleaner implementation of file processing
* Examples now use popt for command-line processing
* Improved portability for Macintosh
* Improved build process for platforms without popt or zlib
* New documentation about the MusicMatch tagging format
* Minor updates to ID3_Field interface
* New interface behavior: 
    // copies entire string (same for unicode_t*)
    size_t ID3_Field::Get(const uchar*, size_t) 
    // for lists, copies a specific item in string (0-based)
    size_t ID3_Field::Get(const uchar*, size_t, index_t);
    // returns the size in characters for strings, in bytes for all else
    size_t ID3_Field::Size() cosnt;
    // returns the rendered size of the field
    size_t ID3_Field::BinSize() cosnt;

2000-07-07 Version 3.7.12

* Removed debugging output left over from 3.7.11
* Update() now updates all tag types by default, not just ID3v2
* Added a second, optional parameter to ID3_GetComment to find a comment with
  a specific description
* Converting an ID3v1 comment to an ID3v2 COMM frame now has the description
  "ID3v1 Comment"
* An ID3v2 COMM frame will only be converted to an ID3v1 comment if it has a
  description of "ID3v1 Comment"

2000-07-05 Version 3.7.11

* Now parses and converts files with MusicMatch tags (beta - needs testing!)
* New tag type enums: ID3TT_LYRICS3, ID3TT_LYRICS3V2, ID3TT_MUSICMATCH, 
  ID3TT_PREPENDED, ID3TT_APPENDED.  Deprecated ID3TT_LYRICS
* Improved file processing routines; cleaned up interface w.r.t. files
* Stripping one type of appended tag strips them all
* New C function: ID3Tag_HasTagType
* New methods for ID3_Tag: GetPrependedBytes(), GetAppendedBytes(), 
  GetFileSize(), and GetFileName()
* New function for calculating size of non-tag data in file: ID3_GetDataSize()
* Render now parameterized on ID3_TagType
* Bug fixes

2000-06-23 Version 3.7.10

* New and updated example tags
* Corrected unicode parsing and rendering
* Improved parsing/conversion of Lyrics3 v2.00 tags
* Fixed errors with exception handling (thanks to Luca Leonardo Scorcia for the
  bug reports)
* Fixed bugs/memory leaks with removing frames and updating tag (thanks to Luca
  Leonardo Scorcia for the bug reports)
* Fixed finding of frames with empty text fields (thanks to Luca Leonardo 
  Scorcia for the bug reports)
* Improved documentation/implementation for uint28
* Added GetTextID() method for ID3_Frame objects
* Tag doesn't render if there aren't any frames; frame doesn't render if there
  aren't any fields
* Reordered ID3_AddSyncLyrics() parameters for better consistency with other
  helper functions
* ID3_GetSyncLyricsInfo() parameters updated to be more specific
* Several other minor bug fixes

2000-05-28 Version 3.7.9

* Added new test programs in examples/ for creating example tag files
* Further improvements to compile on (Unix) systems that don't have zlib
* Fixed a bug when parsing compressed frames (thanks to Christian Becker for 
  the bug report and example file)
* Fixed several bugs when writing to files (thanks to Lothar Egger and Peter 
  Thorstenson for the bug reports)
* New delphi example code for use with id3com (thanks Michael Little)
* Bugfixes for id3com (thanks John Adcock)
* Changed behavior of Link() and Clear() in ID3_Tag: Clear() doesn't remove
  file reference, and Link'ing to an already-linked tag just changes the file
  reference
* Cleaned up the class interfaces to use size_t, flags_t, and index_t rather
  than luint, so as to be more descriptive
* ID3_Tag::RemoveFrame() now returns the pointer to the frame removed (NULL if
  not present), thus releasing the tag from its repsonsibility of managing that
  frame's memory
* Cleaned up C interface so that appropriate function parameters are const
* Cleaned up implementation of ID3_Tag::Clear() to fix inconsistencies
* Deprecated ID3_Tag's HasV2Tag(), HasV1Tag(), and HasLyrics() methods in 
  favor of ID3_Tag::HasTagType() method
* All Render() methods now const
* Added GetUnsync() method to ID3_Tag
* Cleaned up internal class definitions (thereby destroying binary 
  compatibility)
* ID3v2 tag now won't render (and its reported size is 0) if there aren't any
  frames (per the spec)
* Fixed a bug when copying frames that prevented rendering compressed frames in
  certain situations
* Fixed a bug with resyncing that caused it to improperly handle the last byte
* Fixed a bug with recognizing certain sync signals
* Lots of other minor changes

2000-05-11 Version 3.7.8

* Major bug fix that caused all string frames to be written out as unicode, yet
  with the wrong encoding information given
* Bug fix for stripping id3v2 tags that wouldn't remove enough data
* Bug fix for writing id3v1 tags that might add extraneous data to the tag

2000-05-10 Version 3.7.7

* As part of the major rewrite of underlying codebase started with previous
  release, this release features near-complete reimplementation of most of the 
  ID3v2 parsing code - smaller, faster, and better organized
* Much imporved Lyrics3 v2 tag support, along with much improved synchronized
  lyrics (SYLT) support (thanks Severino Delaurenti)
* Updated id3com to reflect changes to compression strategy introduced in last
  release (thanks John Adcock)
* Cleaned up the parameters to several functions/methods with regards to 
  constness
* Several new methods to several classes
* A variety of bugfixes

2000-05-03 Version 3.7.6

* Beginning of major rewrite of underlying codebase to improve efficiency,
  expandability; the interface will need minor updates through this endeavor
  (sorry!)
* Major bugfix in ID3_Tag::Strip which was deleting too much info from a file
  in certain circumstances
* Add descriptions to frames; can access either through a ID3_Frame method for
  a frame object, or via the static method on the class (w/ ID3_FrameID param)
  (thanks John Adcock for descriptions, Daryl Pawluk for spotting misorder)
* Frame compression is determined frame by frame, so deprecated 
  ID3_Tag::SetCompression() for ID3_Frame::SetCompression().  
  ID3_Tag::SetCompression() is now a no-op (updated C interface accordingly)
* New method ID3_Frame::Contains(ID3_FieldID) for determining if a frame
  contains a particular field
* New static method ID3_Tag::IsV2Tag() deprecates ID3_IsTagHeader()
* Other minor bugfixes

2000-04-28 Version 3.7.5

* Fixed nasty bug with rewriting tags to windows files (thanks John Adcock)
* More fixes, improvements to id3com files (thanks John Adcock)
* Added parsing of Lyrics3 v1.00 tags (thanks Severino Delaurenti)
* Updated documentation, but still in flux
* Other minor bugfixes

2000-04-26 Version 3.7.4

* Fixed windows project files so that they all work correctly with new release
  (thanks John Adcock, Robert Moon, and Lothar Egger)
* Added a simple VB app to test id3lib using id3com.dll (thanks John Adcock)
* Added better implementation of PRIV (Private) frame (thanks John Adcock)
* Fixed padding logic (thanks John Adcock)
* New "Spec Versioning" system under the hood produces minor interface change
  - Defined new enum: ID3_V2Spec (ID3V2_2_0, ID3V2_2_1, ID3V2_3_0, etc.)
  - {Get,Set}Spec now used in favor of deprected {Get,Set}Version, GetRevision
  - Field definitions updated accordingly; now smaller and more exact

2000-04-24 Version 3.7.3

* C/C++ interface changes:
  - Moved V1_LEN* constants into an enumeration so that they can be used as 
    array size initializers in C.  Renamed the constants for consistency
    (LEN_V1 -> ID3_V1_LEN, LEN_V1_TITLE -> ID3_V1_LEN_TITLE, etc.)
  - Renamed ID3_TagType's enums to be more consistent with rest of library's
    enums (V1_TAG -> ID3TT_ID3V1, V2_TAG -> ID3TT_ID3V2, etc.)
  - ID3_Err enumeration now defines ID3E_NoError
* C++ interface changes:
  - ID3_Frame now has a copy constructor
  - ID3_Tag::AddNewFrame deprecated for AttachFrame (no other difference in 
    behavior)
  - ID3_Tag::Link(char *, bool, bool) deprecated for 
    ID3_Tag::Link(char *, luint). Now accepts ID3_TagTypes to determine which
    tags to parse. i.e, mytag.Link("myfile.mp3", ID3TT_ID3V2 | ID3TT_LYRICS);
  - ID3_Tag::operator<<, ID3_Tag::AddFrame: relevant parameters now const
* C interface changes:
  - ID3Tag_Parse, ID3Tag_Update, ID3Tag_Strip now return an ID3_Err
  - Added functions ID3Tag_UpdateByTagType, ID3Frame_New, ID3Frame_NewID,
    ID3Frame_Delete
* Implementation changes:
  - AddFrame, AddFrames now add copies of the frames passed in.  
  - AttachFrame adds the actual frame passed to it.
  - The tag takes responsibility for managing its frames' memory in all cases.
* Miscellaneous changes:
  - Moved most enum and struct declarations to include/id3/globals.h so they
    are accessible to C interface
  - id3com.dsp file is 'fixed', but the project still doesn't compile w/o 
    errors
  - Most doxygen comments moved from tag.h to respective files
  - Fixed a bug in id3lib.spec which caused rpm binaries to be compiled without
    exception handling
  - examples, include/id3/* header files no longer include config.h
  - Other minor bugfixes

2000-04-21 Version 3.7.2

* Implementation of C interface for all platforms (in src/c_wrapper.cpp, which
  replaces dll_wrapper.cpp)
* Added examples/demo_simple.c which demonstrates basic use of C interface
* Auto-generated documentation no longer shipped with main tarball distribution
* mp3 example files no longer included (still available via CVS)
* Updated Windows project files so that they'll (hopefully) compile cleanly
  again

2000-04-19 Version 3.7.1

* Interface changed: functions in version.{h,cpp} replaced with constants 
  defined in globals.h
* Added a spec file for creating rpm's
* C interface now defined in include/id3.h, replaces include/src/dll.h; 
* Lots of file movement.  src/id3/* to src/; src/examples to examples;
* Examples now compiled as installable binaries, rather than 'checks'
* Removed unnecessary files: externals.h, types.h, version.{h,cpp}, dll.h

2000-04-15 Version 3.7.0

* New project management: MusicMatch handed reigns over to Scott Thomas Haug
* New project licensing: LGPL (http://www.gnu.org/copyleft/lesser.html)
* New versioning: 3.7.x is unstable series leading up to 3.8.x stable
* Many bug fixes
* Better windows compatibility, with new windows project files
* Improved documentation, using the Doxygen documentation system 
  (http://www.stack.nl/~dimitri/doxygen/)
* Extended API, improved implementation
* More supported frames
* Now parses and rerenders unrecognized frame types
* Better version handling in configuration files, similar to the glib library
  (http://www.gtk.org) 

1999-12-02 Version 3.6.2

* Improved portability: another minor portability fixes, along with the
  inclusion of zlib sources and project files for windows compilation.

1999-12-01 Version 3.6.1

* Code movement: moved the header files from src/id3 to include/id3 to allow
  for easier windows compilation.
* Improved portability: made changes in several files to improve compilation
  on windows.  (thanks to elrod for the fixes)
* Random cleanup: some spelling errors fixed, some minor file administration, 
  etc.

1999-11-30 Version 3.6.0

* Code overhaul: more descriptive variable naming, streamlined implementation
  logic, cleaner interface specification, generalization of magic numbers and
  strings.
* Better documentation: transcribed the the "Documentation for ID3Lib 3.05"
  document (written by Dirk Mahoney, 22 Nov 1998) into the actual source, using
  javadoc-like tags so as to create documentation with the application doc++. 
  Using this program (and ones like it) allows for creating the documentation
  in many different formats, including html, texinfo, man, latex, and the like.
* Added functionality: Added additional functions for simplified access to
  common tags, such as artist, title, and album.
* More robust error checking: Improved upon the exception handling already in
  place to better handle error conditions, such as invalid tags, unrecognized
  frames, and the like.  Work is still needed to ensure the library can handle
  error situations gracefully.
* Improved portability: restructured the code into a GNU-like directory.
  hierarchy.  By making use of the GNU tools automake and autoconf, a wide
  variety of platforms can be easily supported.  This allows for a standard
  "./configure; make; make install" installation process, as well as an
  equally trivial method for uninstallation: "make uninstall".  Likewise,
  "make check" builds the example applications (see below).
* Enhanced examples: the src/examples/ subdirectory has both new and improved
  examples demonstrating how to make use of id3lib.  The original "id3convert"
  example now can convert both ways between id3v1 and id3v2 tags, as well as
  strip both types of tags off of files via command-line switches.
  Additionally, an "id3info" app has been added for displaying id3v1/v2 tag
  information about a file.
* Bug fixing: Fixes, fixes, and more fixes.  A continual process.
* The zlib library files were removed from the project.  The need for zlib
  was instead made a requirement through the configuration process via autoconf
  and automake.
* All of the id3lib library files were renamed by removing the "id3_" prefix.
  Instead, the library files were placed in an id3 subdirectory in the src
  directory.  Likewise, when the library is installed on a system, an "id3"
  subdirectory is created in the indicated include directory, and the header
  files are placed there.  Pragmatically, this means that code that makes use
  of id3lib needs to "#include <id3/tag.h>" rather than "#include <id3_tag.h>".
  This was done to create more structure and to avoid clutter in the include
  directory.
* The versioning strategy has been updated to be more in line with the 
  "libtool" way.  However, in order to be more compatible with how versions
  progressed previously, I've taken the approach that many other libraries have
  taken: I've "massaged" the version:revision:age numbers so that the resulting
  compiled library shows up as id3lib.so.3.6.0 (or whatever the current release
  is).  This is /strongly/ advised against in the libtool documentation, so I'm
  considering going to a more "traditional" libtool versioning approach (see
  the libtool info page for more information).

There is yet much to do!  Please see the TODO file for known bugs and lacking
features...



# HISTORY

    $Id: HISTORY,v 1.3 2000/04/17 05:05:01 eldamitri Exp $

ID3Lib History

The following is a history of id3lib up to version 3.05a.  Please see the
NEWS file for changes since then.

23 Nov 1998     3.05a   - Released 3.05a in which the only change was the 
                          inclusion of a C header file for using the DLL
                          (how forgetful I am!).

22 Nov 1998     3.05    - Released 3.05 and the DLL.

 8 Nov 1998     3.05    - Finished the first revision of the DLL.  Interesting
                          stuff.  Contains both C++ class and C functions (the
                          C++ classes that are exported to the DLL are Tag,
                          Frame, Field and Error).
                        - Took out the SetVersion function from the ID3_Tag 
                          class.  This is because I no longer wish ID3Lib to be
                          able to create the old ID3v2-2.0 tags.  ID3Lib will
                          always create the latest version tags it is capable
                          of creating.

 1 Nov 1998     3.05    - Removed the encryption and grouping stuff.  I have a
                          lot to do before I finish that section and I might 
                          end up implementing it differently, so I thought it
                          best to remove it before people started using it 
                          (no-one should since it wasn't fully functional
                          anyway).

13 Oct 1998     3.05    - Work has begun on the Windows DLL.

 9 Oct 1998     3.04    - Added the text list handling functions from 2.16, but
                          they are slightly different under 3.xx.
                        - Also added a Size() function for fields which
                          applications can use to allocate buffers and so on.
                        - Work has progressed on the encryption and grouping
                          side of things, but nothing usable by an application
                          just yet.

 5 Oct 1998     3.04    - Changed the ID3_AddHandler() function to include a
                          parameter which specifies the factor by which the 
                          size of the frame may increase as a result of
                          encryption or encoding.  This is used for buffer and
                          size estimates.

 3 Oct 1998     3.03a   - Fixed a small Unicode BOM bug.

 2 Oct 1998     3.03    - Added very minimal and not-totally-functional support
                          for the automatic handling of encryption and
                          grouping.
                        - Added a function to ID3_Tag which makes attaching
                          arrays of ID3_Frame objects easy.

 1 Oct 1998     3.03    - Yesterday, ID3v2-3.0 became an informal standard.  
                          Due to this, ID3Lib now does not create ID3v2-3.0
                          tags with the EXPERIMENTAL bit set.

30 Sep 1998     3.02    - Expanded the error handling class to include
                          functions which return the ID3Lib source file and
                          line number of the exception. This is useful for
                          debugging and generating bug reports (hint, hint).

28 Sep 1998     3.02    - Added the grouping registration and encryption
                          registration frames.  Also added support for parsing
                          and rendering frames with the grouping and encryption
                          symbols, although currently this data is ignored.  I
                          plan to implement call backs to handle the encryption
                          and decryption of data.  Also, there is currently no
                          checking at render-time that all frames which have
                          these symbols also have a corresponding rego frame.

26 Sep 1998     3.02    - Changed the 'tag changed' stuff so that calls to
                          ID3_Tag::SetVersion(), ID3_Tag::SetCompression() etc
                          now constitute a change in the tag.  This is because
                          of the relaxed restrictions on the calls to these
                          functions before rendering/updating.  - Fixed a bug
                          in the ID3_Tag::Link() command.

25 Sep 1998     3.01    - Added the ID3_Tag::RemoveFrame() function.
                        - Added the ID3_Tag::SetExtendedHeader() function, even
                          though this setting is currently ignored.
                        - Added luint return type to the Field::Get() functions
                          for ASCII and Unicode strings.  These functions now
                          return how many characters (not bytes necessarily) of
                          the supplied buffer were used, not including the
                          NULL-termination.
                        - Added the 'unique file identifier' frame which I
                          omitted from 3.00 but was present in 2.xx.
                        - Added code that allows ID3Lib and applications to
                          track whether a tag has been altered since the last
                          parse or render.
                        - Slightly altered the padding strategy when a tag 
                          shrinks in size.
                        - No more requirements on when ID3_Tag::SetVersion()
                          etc must be called, except that they should be called
                          prior to an update or render if you plan to use
                          different settings than the defaults.

21 Sep 1998     3.00    - Released 3.00

15 Sep 1998     3.00    - Added support for parsing and converting ID3v1/1.1
                          and Lyrics3 v2.0 tags and CDM frames from 2.01
                          experimental tags.  Also parses Unicode now.

 9 Sep 1998     3.00    - Work almost done on 3.00.  A little bit to fix up in
                          the parsing department (doesn't parse Unicode yet, or
                          CDMs from the old 2.01 draft).  Then just add
                          validity checking and support for most of the frames.

 2 Sep 1998     2.16    - Small Unicode string parsing bug fixed.

25 Aug 1998     2.15    - Small bug fixes in the tag parsing routines.
                        - Completely removed support for creating extended
                          headers, and ID3Lib will now ignore tags which have
                          the EXTENDEDHEADER bit set (as under 2.00, this bit
                          isn't defined).

24 Aug 1998     2.14    - Small bug fixes in the example file 'convert.cpp'.
                        - ID3Lib now sets the EXPERIMENTAL bit in the tag
                          header.

13 Aug 1998     2.13    - As of 2.13, ID3Lib now comes in two flavours.  The
                          first is the normal distribution as we have come to
                          know and love.  The second is a machine-specific
                          archive which contains the static link libraries.
                          Currently, you can get Win32 link libraries.

12 Aug 1998     2.12    - As of 2.12, the ID3Lib distribution will contain
                          precompiled static libraries for Visual C++ and
                          eventually for Linux i386.  The MSVC static libs are
                          be compiled for the multi-threaded run-time library
                          and there will be one for debugging and one normal
                          one for release-quality applications.

                        - Fixed a small exclusion in the 'id3_support.h' file.
                          It now contains a #include for the 'wchar.h' header
                          file.  The absence of this line resulted in some
                          applications producing compilation errors if they
                          didn't already include it or 'stdio.h'.

11 Aug 1998     2.12    - I created a small problem in 2.11 where the name of
                          the URL field in the 'ID3FID_WWWUSER' frame ('WXX')
                          was changed from ID3FN_URL to ID3FN_TEXT.  This has
                          been fixed (is back to ID3FN_URL).
                        - When reading a binary tag, previous versions of
                          ID3Lib ignored the fact that some of the frames in
                          the tag may have been compressed, so when writing the
                          tag back out, those old frames were written without
                          compression.  This is fixed so that all old frames
                          are written back out as they were read in, unless of
                          course you explicitly change the compression status
                          before rendering the new tag.
                        - Added the ID3C_SetSongSize and ID3C_GetSongSize
                          commands to the ID3_Tag class.  These allow you to
                          tell ID3Lib how big (in bytes) the song file is to
                          which you intend attaching the tag.  ID3Lib can then
                          work out how much padding the tag requires to
                          correctly make the entire resulting file fill an even
                          multiple of 2Kb.
                        - If the tag we are manipulating was read in as a
                          binary tag before we started playing with it, then
                          ID3Lib will record the size of tag before we started
                          fooling around with it.  This way, the padding system
                          can pad the new tag out to the old size if the new
                          tag will still fit inside the old one.  This makes
                          file manipulation much easier when writing tags to
                          existing song files.  If it won't fit, then the new
                          tag will receive padding as per the 2K cluster
                          method.  All this talk of padding only applies if the
                          tag's padding property is set to ID3PD_AUTOMATIC,
                          which it is by default.

10 Aug 1998     2.11    - Replaced ID3C_SetID and GetID with proper field
                          names, and the same with ID3C_SetComp and GetComp.
                          This requires a change in source code for the
                          application.  Without quotes, do a search and
                          replace...

                     "ID3C_SetID,"   replace with "ID3C_Set, ID3FN_ID,"
                     "ID3C_GetID,"   replace with "ID3C_Get, ID3FN_ID,"
                     "ID3C_SetComp," replace with "ID3C_Set, ID3FN_COMPRESSED,"
                     "ID3C_GetComp," replace with "ID3C_Get, ID3FN_COMPRESSED,"

                        - Thanks to a suggestion by Ilana Rudnik, I added a
                          generic frame type called 'ID3FID_UNSUPPORTED' which
                          is only to be used by applications as a
                          'place-holder' in lists and arrays while waiting for
                          ID3Lib to support all the frames.

 6 Aug 1998     2.11    - Created the ID3C_Locate and ID3C_GetNumFrames
                          commands.
                        - Made the documentation an HTML file instead of boring
                          text.

 5 Aug 1998     2.11    - Thanks to Eng-Keong Lee, I have located and fixed a
                          bug which most-of-the-time caused a crash when
                          performing an ID3C_SetID on a frame for the first
                          time.

 3 Aug 1998     2.10    - Fixed a few things to make ID3Lib compile completely
                          cleanly under Linux - thanks to Carlos Puchol for
                          finding the remaining hassles.
                        - Added two commands to adjust the unsync facility -
                          ID3C_SetUnsync and ID3C_GetUnsync.  The default is
                          ID3SY_AUTOMATIC.
                        - Add support for the 2.01 extended tag header.  By
                          default, ID3Lib will NOT write an extended header to
                          tags it creates.  This can be adjusted by the
                          ID3C_SetExtHeader command.
                        - Changed the directory structure so that the required
                          zlib source is now in the same directory as the
                          ID3Lib source.

 2 Aug 1998     2.10    - Fixed a small memory leak which occurred when
                          clearing a tag of frames which were read in from an
                          external binary tag.
                        - Added a 'bugreport.txt' file to the documentation to
                          improve effectiveness of bug reporting.

 1 Aug 1998     2.10    - Adding support for tag padding.  This results in two
                          new commands which operate on ID3_Tag objects:
                          ID3C_SetPadding and ID3C_GetPadding.

 1 Aug 1998     2.09    - Fixed some bugs in the ID3C_ToFile and ID3C_FromFile
                          commands.
                        - Fixed a bug which prevented empty strings which were
                          supposed to be NULL-terminated from doing so.

31 Jul 1998     2.09    - Changed the functionality of the error handling
                          mechanism.  The function interface to the error
                          handler has changed - see the example source file
                          'main.cpp' for details.
                        - Improved frame verification somewhat.

28 July 1998    2.08    - Added ID3C_ToFile command to binary fields.
                        - Changed the format of the ID3C_Size command when
                          applied to frames.  There is now a required second
                          parameter which specifies which field you require the
                          size of.  If you request ID3FN_ALL, you will get the
                          size of the frame itself.
                        - The above change for ID3C_Size now also applies to
                          the ID3C_Clear command (again, only when applied to
                          frames).
                        - Enhanced the ID3C_Find command so as to allow
                          searches based on the ID3FN_LANGUAGE field and the
                          ID3FN_DESCRIPTION field.

27 July 1998    2.07    - Fixed a bug which had the WXX and TXX frames
                          including a language field which they shouldn't.
                        - Fixed a bug in the string's ID3C_Get command which
                          wrongly interpreted the presence of a '/' symbol in 
                          the string as meaning that the string was a textlist.

21 July 1998    2.06    - Added support for frame compression via zlib.  This 
                          means that all frames have an extra attribute which
                          specifies whether the frame should be compressed.
                        - Changed some typedefs and macro names so as not to
                          clash with some of Windows' pre-defined
                          datatypes/names.  Thanks to Chuck Zenkus for finding
                          this.

14 July 1998    2.05    - Finished up Unicode support.  All internal string
                          handling is done with Unicode strings.  Strings are
                          converted as needed during rendering of the tag.

 6 July 1998    2.05    - BINARY fields now support an 'ID3C_FromFile' command
                          which fills the field with data from the specified
                          file.  The file is read and the contents placed in
                          the field immediately on the field encountering this
                          command.

 2 July 1998    2.04    - Improved support for frame validation.
                        - Repaired a cool bug in the error handling which
                          prevented an application from finding further
                          information about the error.  This fix resulted in a
                          new format for the application error handler
                          function.

                2.03    - Added support for the ID3C_Add, ID3C_Remove,
                          ID3C_GetElement, ID3C_GetNumElements commands in the
                          STRING field type.  This allows easy use of the text
                          lists as used in the 'TP1' frame.

                        - Improved error handling once more.
                        - Added support for the ID3C_Increment command in the
                          INT field type.
                        - Added support for the CNT, POP, GEO, TCO, TCR and UFI
                          frames.
                        - Added preliminary validation checking for frames to
                          ensure they meet the ID3v2 standard requirements.
                          Not fully implemented.

                2.02    - Adjusted the '::Do()' function slightly - you can now
                          chain commands together.  The last parameter to this
                          call must now always be 'ID3C_DONE'.
                
 1 July 1998    2.01    - Added the 'ID3_IsTagHeader()' function and an
                          appropriately adjusted ID3C_Parse command.

30 June 1998    2.00    - First preliminary release of ID3Lib v2.00.  Supports
                          lots of frames (even PIC).  Lots of work still
                          needed.

25 June 1998    2.00    - Abandoned the v1.xx framework in favour of a more
                          versatile and expandable one.  This required a major
                          re-write of most of the internals of the library as
                          well as changes to any applications using the
                          previous framework.  The new framework is part of all
                          ID3Libs which are 2.xx.

23 June 1998    1.01    - Released v1.01 which added support for four new
                          frames.  TXX, WXX, COM, ULT

21 June 1998    1.00    - Initial Release (v1.0)
