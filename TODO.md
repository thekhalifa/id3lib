
# id3lib TODO

- Migrate to C++ 2011, but not until there is a stable cleaned up version
- Add unit tests and sample files

### Maybes

- Extract Tutorial from src/tag.cpp into docs/ markdown file
- Review tickets on sf.net to see if they're relevant
- Move id3info type switch into the API, it should report the type directly

## Done

- Remove Debug directives for libcwd as it's not in distros
- Replace license header with SPDX identifier
- Reformat files
- Add pkgconf file, 2024
- Cleanup example code
    - Remove non-working examples
    - Distinguish between tools and tests, write tests separately
    - Mind where they write their files
- Add strip post build to reduce binary sizes as libtool is not there anymore
    - Skipped, enough to use MinSizeRelease config

# Historical TODOs

- id3lib still requires the following work:
    * testing testing testing
    * The interface for file access is muddled.  It has been separated out from the
      next unstable release (3.9.x), but perhaps it can be cleaned up for 3.7.x
    * id3lib needs a C interface.  Badly.
    * Some of the limitations present in 3.05a have been fixed, but many still
      exist.  See below for the original list and what has been updated.
- Version 3.05a of ID3Lib has some known limitations...
    * Firstly, contrary to good programming ideas and contrary to the 'ID3v2
      Programming Guidelines', ID3Lib will explode in a ball of brilliant blue
      flame if asked to parse an invalid ID3v2 tag.  This will change.
        + Update for 3.7.0: this has been improved, but still requires more testing.
    * Incorrect handling of unknown frames.  This means that when ID3Lib encounters
      an unknown frame, it is currently ignored.  It is neither re-written to the
      tag when re-rendered nor are the file or tag alter frame flags observed.
        + 3.7.0 adds nominal support for all remaining known frames (as defined in
          the spec for id3v2.2.0 and id3v2.3.0 at www.id3.org).  Unknown frames are
          now parsed and re-rendered, but the file and tag alter frame flags are not
          yet observed
    * No support for the read-only frame flag.  It is currently ignored---such 
      frames can be altered at will.
    * No support as yet for the verification of frames before rendering.
    * Does not yet render 3.0 extended headers.  Although the functionality for
      selecting this is present, the setting is ignored for now.
    * Does not yet parse 3.0 extended headers.  They are quite adequately ignored
      and the rest of the tag is parsed correctly.
    * ID3Lib currently has no direct support for things like the language and
      currency fields.  It is up to the application to generate the data for these
      fields manually.  Soon, ID3Lib will have these things assigned to IDs so that
      the applications programmer will not have to remember the ISO tables for the 
      actual strings.
