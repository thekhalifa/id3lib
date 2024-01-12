/*
  File autogenerated by gengetopt version 2.3
  generated with the following command:
  gengetopt --file-name=demo_info_options --unamed-opts --input=demo_info_options.ggo 

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
/* Check for configure's getopt check result.  */
#ifndef HAVE_GETOPT_LONG
#include "getopt.h"
#else
#include <getopt.h>
#endif

#include "demo_info_options.h"


void cmdline_parser_print_version (void)
{
    printf ("%s %s\n", PACKAGE, VERSION);
}

void cmdline_parser_print_help (void)
{
    cmdline_parser_print_version ();
    printf ("\n"
            "Usage: %s [OPTIONS]... [FILES]...\n\
   -h  --help      Print help and exit\n\
   -V  --version   Print version and exit\n\
   -a  --assign    Test the assignment operator (default=off)\n\
   -w  --warning   Turn on warnings (for debugging) (default=off)\n\
   -n  --notice    Turn on notices (for debugging) (default=off)\n\
", PACKAGE);
}


static char *gengetopt_strdup (char *s)
{
    char *n, * pn, * ps = s;

    while (*ps) {
        ps++;
    }

    n = (char *) malloc (1 + ps - s);

    if (n != NULL) {
        for (ps = s, pn = n; *ps; ps++, pn++) {
            *pn = *ps;
        }

        *pn = 0;
    }

    return n;
}


int cmdline_parser (int argc, char *const *argv, struct gengetopt_args_info *args_info)
{
    int c;    /* Character of the parsed option.  */
    int missing_required_options = 0;

    args_info->help_given = 0 ;
    args_info->version_given = 0 ;
    args_info->assign_given = 0 ;
    args_info->warning_given = 0 ;
    args_info->notice_given = 0 ;
#define clear_args() { \
        args_info->assign_flag = 0;\
        args_info->warning_flag = 0;\
        args_info->notice_flag = 0;\
    }

    clear_args();

    args_info->inputs = NULL;
    args_info->inputs_num = 0;

    while (1) {
        int option_index = 0;
        static struct option long_options[] = {
            { "help",   0, NULL, 'h' },
            { "version",    0, NULL, 'V' },
            { "assign", 0, NULL, 'a' },
            { "warning",    0, NULL, 'w' },
            { "notice", 0, NULL, 'n' },
            { NULL, 0, NULL, 0 }
        };

        c = getopt_long (argc, argv, "hVawn", long_options, &option_index);

        if (c == -1) {
            break;    /* Exit from `while (1)' loop.  */
        }

        switch (c) {
        case 'h':   /* Print help and exit.  */
            clear_args ();
            cmdline_parser_print_help ();
            exit (0);

        case 'V':   /* Print version and exit.  */
            clear_args ();
            cmdline_parser_print_version ();
            exit (0);

        case 'a':   /* Test the assignment operator.  */
            args_info->assign_flag = ! (args_info->assign_flag);
            break;

        case 'w':   /* Turn on warnings (for debugging).  */
            args_info->warning_flag = ! (args_info->warning_flag);
            break;

        case 'n':   /* Turn on notices (for debugging).  */
            args_info->notice_flag = ! (args_info->notice_flag);
            break;

        case 0: /* Long option with no short option */

        case '?':   /* Invalid option.  */
            /* `getopt_long' already printed an error message.  */
            exit (1);

        default:    /* bug: option not considered.  */
            fprintf (stderr, "%s: option unknown: %c\n", PACKAGE, c);
            abort ();
        } /* switch */
    } /* while */

    if (missing_required_options) {
        exit (1);
    }

    if (optind < argc) {
        int i = 0 ;

        args_info->inputs_num = argc - optind ;
        args_info->inputs =
            (char **) (malloc ( (args_info->inputs_num) * sizeof (char *))) ;

        while (optind < argc) {
            args_info->inputs[ i++ ] = gengetopt_strdup (argv[optind++]) ;
        }
    }

    return 0;
}
