/*
  File autogenerated by gengetopt version 2.1  
  generated with the following command:
  gengetopt --file-name=demo_convert_options --unamed-opts --input=demo_convert_options.ggo 

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

/* Check for configure's getopt check result.  */
#ifndef HAVE_GETOPT_LONG
#include "getopt.h"
#else
#include <getopt.h>
#endif

#include "demo_convert_options.h"

/* Don't define PACKAGE and VERSION if we use automake.  */
#define GGO_PACKAGE "id3convert"
#ifndef VERSION
#  define GGO_VERSION ""
#else
/* ******* WRITE THE VERSION OF YOUR PROGRAM HERE ******* */
#  define GGO_VERSION ""
#endif


void
print_version (void)
{
  printf ("%s %s\n", GGO_PACKAGE, GGO_VERSION);
}

void
print_help (void)
{
  print_version ();
  printf ("Usage: %s [OPTIONS]... [FILES]...\n\
   -h  --help      Print help and exit\n\
   -V  --version   Print version and exit\n\
   -1  --v1tag     Render only the id3v1 tag (default=off)\n\
   -2  --v2tag     Render only the id3v2 tag (default=off)\n\
   -s  --strip     Strip the tags instead of rendering (default=off)\n\
   -p  --padding   Use padding in the tag (default=off)\n\
   -w  --warning   Turn on warnings (for debugging) (default=off)\n\
   -n  --notice    Turn on notices (for debugging) (default=off)\n\
", GGO_PACKAGE);
}


int
cmdline_parser (int argc, char * const *argv, struct gengetopt_args_info *args_info)
{
  int c;	/* Character of the parsed option.  */
  int missing_required_options = 0;	

  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->v1tag_given = 0 ;
  args_info->v2tag_given = 0 ;
  args_info->strip_given = 0 ;
  args_info->padding_given = 0 ;
  args_info->warning_given = 0 ;
  args_info->notice_given = 0 ;

#define clear_args()
{ \
  args_info->v1tag_flag = 0;\
  args_info->v2tag_flag = 0;\
  args_info->strip_flag = 0;\
  args_info->padding_flag = 0;\
  args_info->warning_flag = 0;\
  args_info->notice_flag = 0;\
}

  clear_args();

  args_info->inputs = NULL;
  args_info->inputs_num = 0;

  while (1)
    {
      int option_index = 0;
      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "v1tag",	0, NULL, '1' },
        { "v2tag",	0, NULL, '2' },
        { "strip",	0, NULL, 's' },
        { "padding",	0, NULL, 'p' },
        { "warning",	0, NULL, 'w' },
        { "notice",	0, NULL, 'n' },
        { NULL,	0, NULL, 0 }
      };

      c = getopt_long (argc, argv, "hV12spwn", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          clear_args ();
          print_help ();
          exit (0);

        case 'V':	/* Print version and exit.  */
          clear_args ();
          print_version ();
          exit (0);

        case '1':	/* Render only the id3v1 tag.  */
          args_info->v1tag_flag = !(args_info->v1tag_flag);
          break;

        case '2':	/* Render only the id3v2 tag.  */
          args_info->v2tag_flag = !(args_info->v2tag_flag);
          break;

        case 's':	/* Strip the tags instead of rendering.  */
          args_info->strip_flag = !(args_info->strip_flag);
          break;

        case 'p':	/* Use padding in the tag.  */
          args_info->padding_flag = !(args_info->padding_flag);
          break;

        case 'w':	/* Turn on warnings (for debugging).  */
          args_info->warning_flag = !(args_info->warning_flag);
          break;

        case 'n':	/* Turn on notices (for debugging).  */
          args_info->notice_flag = !(args_info->notice_flag);
          break;

        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          exit (1);

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c\n", GGO_PACKAGE, c);
          abort ();
        } /* switch */
    } /* while */

  if ( missing_required_options )
    exit (1);

  if (optind < argc)
    {
      int i = 0 ;

      args_info->inputs_num = argc - optind ;
      args_info->inputs = 
        (char **)(malloc ((args_info->inputs_num)*sizeof(char *))) ;
      while (optind < argc)
        args_info->inputs[ i++ ] = strdup (argv[optind++]) ; 
    }

  return 0;
}
