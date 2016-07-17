/* $Id: option.c,v 1.1 1996/11/07 08:03:54 ryo freeze $
 *
 *	�\�[�X�R�[�h�W�F�l���[�^
 *	Option analyze , etc
 *	Copyright (C) 1989,1990 K.Abe, 1994 R.ShimiZu
 *	All rights reserved.
 *	Copyright (C) 1997-2010 Tachibana
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef __LIBC__
#include <sys/xglob.h>
#else
#define _toslash(p) (p)
#endif

#include "analyze.h"		/* Arg_after_call */
#include "disasm.h"
#include "estruct.h"
#include "etc.h"		/* strupr */
#include "fpconv.h"		/* Inreal_flag */
#include "generate.h"
#include "getopt.h"
#include "global.h"
#include "hex.h"
#include "include.h"		/* xxx_mac */
#include "option.h"
#include "output.h"		/* Output_AddressCommentLine, Output_SplitByte */
#include "symbol.h"		/* Output_Symbol */


boolean option_a, option_c, option_d, option_e, option_g, option_h,
	option_i, option_k, option_l, option_p, option_q, option_r,
	option_v, option_x, option_y, option_z, option_B,
	option_D, option_E, option_I, option_M, option_N, /* option_Q, */
	option_S, option_T, option_U, option_Y, option_Z;

boolean option_overwrite;


/* main.c */
extern void	print_title (void);

extern short	Emulate_mode;	/* bit0=1:fpsp bit1=1:isp emulation���߂�F������ */
extern int	String_length_min;
extern char	CommentChar;
extern address	Base, Exec;
extern int	Verbose;
extern int	Quiet_mode;
#ifndef	OSKDIS
extern char	FileType;
#endif

extern char*	Filename_in;
extern char*	Filename_out;
extern char*	Labelfilename_in;
extern char*	Labelfilename_out;
extern char*	Tablefilename;


/* static �֐��v���g�^�C�v */
private void	option_switch (int, char**);



/*

  �I�v�V��������͂���

*/
extern void
analyze_args (int argc, char* argv[])
{
    int fileind;
    char* envptr;

    static const char optionlist[] =
	"a::b:cde::fg::hijklm:n:o:pq::rs::u::vw:xyz:"
	"ABC::DEFGIK:L:MNP:QR:S::T::UV:W:XYZ::#:-:";

#ifdef	READ_FEFUNC_H
    fefunc_mac = "fefunc.h";
#endif

    /* process environment variable `dis_opt' */
    if (/* option_Q == FALSE && */ (envptr = getenv (DIS_ENVNAME))) {
	int c;
	int count, cnt;
	char *envs, *envp;	/* envs=�Œ�, envp=��Ɨp */
	char **args, **argp;	/* args=�Œ�, argp=��Ɨp */

	/* �������X�y�[�X�ŕ������� */
	while (*envptr == ' ')
	    envptr++;
	envp = envs = Malloc (strlen (envptr) + 1);
	for (count = 1; *envptr; count++) {
	    while (*envptr && (*envptr != ' '))
		*envp++ = *envptr++;
	    *envp++ = '\0';
	    while (*envptr == ' ')
		envptr++;
	}

	/* �e�����ւ̃|�C���^�z������ */
	argp = args = Malloc ((count + 1) * sizeof (char*));
	envp = envs;
	*argp++ = argv[0];		/* my name */
	for (cnt = count; --cnt;) {
	    *argp++ = envp;
	    while (*envp++)
		;
	}
	*argp = NULL;

	/* �I�v�V������� */
	/* optind = -1; */
	while ((c = dis_getopt (count, args, optionlist)) != EOF)
	    option_switch (c, args);

	/* �Y�ꂸ�ɉ�� */
	Mfree (args);
	Mfree (envs);
    }

    /* process commandline variable */
    {
	int c;
	optind = -1;
	while ((c = dis_getopt (argc, argv, optionlist)) != EOF)
	    option_switch (c, argv);
	fileind = optind;
    }


    while (fileind < argc) {
	if (Filename_in == NULL)
	    Filename_in = argv[fileind++];
	else if (Filename_out == NULL)
	    Filename_out = argv[fileind++];
	else
	    err ("�t�@�C�������������܂�.\n");
    }
    if ((Filename_in  == NULL) || (*Filename_in  == (char)'\0'))
	usage (1);
    if ((Filename_out == NULL) || (*Filename_out == (char)'\0'))
	Filename_out = "-";


    if ((MMU_type & MMU851) && !(MPU_types & M020))
	err ("-m68851 �� -m68020 �Ƃ������p�ł��܂���.\n");

    if ((FPCP_type & F88x) && !(MPU_types & (M020|M030)))
	err ("-m6888x �� -m68020/68030 �Ƃ������p�ł��܂���.\n");

    if ((Emulate_mode & 2) && (MPU_types & M060))
	MPU_types |= MISP;

    if (Emulate_mode & 1) {
	short tmp = FPCP_type;
	if (tmp & F040) tmp |= F4SP;
	if (tmp & F060) tmp |= F6SP;
	FPCP_type = tmp;
    }


    /* if invoked with -T , labelfile must be read */
    if (option_T)
	option_g = TRUE;


    /* ���x���t�@�C��/�e�[�u���t�@�C�������쐬���� */
    {
	char* file = strcmp ("-", Filename_out) ? Filename_out : "aout";
	char* buf = Malloc (strlen (file) + 1);
	size_t len;

	_toslash (strcpy (buf, file));

	{
	    char* p = strrchr (buf, '/');
	    p = p ? (p + 1) : buf;
	    p = strrchr ((*p == (char)'.') ? (p + 1) : p, '.');
	    if (p)
		*p = '\0';		/* �g���q���폜���� */
	}
	len = strlen (buf) + 4 + 1;

	if (option_g && Labelfilename_in == NULL) {
	    Labelfilename_in = Malloc (len);
	    strcat (strcpy (Labelfilename_in, buf), ".lab");
	}
	if (option_e && Labelfilename_out == NULL) {
	    Labelfilename_out = Malloc (len);
	    strcat (strcpy (Labelfilename_out, buf), ".lab");
	}
	if (option_T && Tablefilename == NULL) {
	    Tablefilename = Malloc (len);
	    strcat (strcpy (Tablefilename, buf), ".tab");
	}

	Mfree (buf);
    }
}


private int
ck_atoi (char* str)
{
    unsigned char c;
    unsigned char* ptr = (unsigned char*) str;

    while ((c = *ptr++) != '\0') {
	if ((c < '0') || ('9' < c))
	    err ("���l�̎w�肪�ُ�ł�.\n");
    }

    return atoi (str);
}


private void
init_fpuid_table (void)
{
    memset (FPUID_table, 0, sizeof FPUID_table);
}


private const char**
include_option (char* p)
{
    char eq;

    if (strncmp (p, "exclude-", 8) != 0 &&
	strncmp (p, "include-", 8) != 0)
	return NULL;

    eq = (*p == (char)'e') ? '\0' : '=';
    p += 8;

    if (strncmp (p, "doscall-mac", 11) == 0 && p[11] == eq)
	return &doscall_mac;
    if (strncmp (p,"iocscall-mac", 12) == 0 && p[12] == eq)
	return &iocscall_mac;
    if (strncmp (p,  "fefunc-mac", 10) == 0 && p[10] == eq)
	return &fefunc_mac;

    return NULL;
}

private const char*
include_filename (char* p)
{
    size_t len;

    if (*p == (char)'e')
	return NULL;

    while (*p++ != '=')
	;

    len = strlen (p);
    return len ? _toslash (strcpy (Malloc (len + 1), p))
	       : NULL;
}

private void
option_switch (int opt, char** argv)
{
    switch (opt) {
    case 'a':
	option_a = TRUE;
	Output_AddressCommentLine = (optarg ? ck_atoi (optarg) : 5);
	break;
    case 'b':
	Generate_SizeMode = ck_atoi (optarg);
	break;
    case 'c':
	option_c = TRUE;
	break;
    case 'd':
	option_d = TRUE;
	break;
    case 'e':
	option_e = TRUE;
	if (optarg)
	    Labelfilename_out = optarg;
	break;
    case 'f':
	Disasm_Exact = FALSE;
	break;
    case 'g':
	option_g = TRUE;
	if (optarg)
	    Labelfilename_in = optarg;
	break;
    case 'h':
	option_h = TRUE;
	break;
    case 'i':
	option_i = TRUE;
	break;
    case 'j':
	Disasm_AddressErrorUndefined = FALSE;
	break;
    case 'k':
	option_k = TRUE;
	break;
    case 'l':
	option_l = TRUE;
	break;
    case 'm':
	{
	    int init = 0;
	    char* next;
#ifndef	__LIBC__
	    char* new_optarg = (char*) Malloc (strlen (optarg) + 1);
	    optarg = strcpy (new_optarg, optarg);
#endif
	    do {
		int m;

		next = strchr (optarg, ',');
		if (next)
		    *next++ = '\0';

#ifdef	COLDFIRE
		if (strcasecmp (optarg, "cf") == 0
		 || strcasecmp (optarg, "coldfire") == 0) {
		    Disasm_ColdFire = TRUE;
		    continue;
		}
#endif
		if (strcasecmp (optarg, "cpu32") == 0) {
		    Disasm_CPU32 = TRUE;
		    continue;
		}
		if (strcasecmp (optarg, "680x0") == 0)
		    m = -1;
		else {
		    m = ck_atoi (optarg);
		    if (m == 68851) {
			MMU_type |= MMU851;
			continue;
		    } else if (m == 68881 || m == 68882) {
			int id = next ? ck_atoi (next) : 1;

			FPCP_type |= (m == 68882) ? F882 : F881;
			if (id & ~7)
			    err ("FPU ID�̒l���ُ�ł�(-m).\n");
			FPUID_table[id*2] = 1;
			break;
		    }
		}

		/* 680x0, 68000, 68010, ... */
		if (init == 0) {
		    init = 1;
		    MPU_types = 0;
		    FPCP_type = MMU_type = 0;
		    init_fpuid_table ();
		}
		switch (m) {
		case 68000:
		case 68008:
		    MPU_types |= M000;
		    break;
		case 68010:
		    MPU_types |= M010;
		    break;
		case 68020:
		    MPU_types |= M020;
		    break;
		case 68030:
		    MPU_types |= M030;
		    MMU_type |= MMU030;
		    break;
		case 68040:
		    MPU_types |= M040;
		    FPCP_type |= F040;
		    MMU_type |= MMU040;
		    FPUID_table[1*2] = 1;
		    break;
		case 68060:
		    MPU_types |= M060;
		    FPCP_type |= F060;
		    MMU_type |= MMU060;
		    FPUID_table[1*2] = 1;
		    break;
		case -1:	/* -m680x0 */
		    MPU_types |= (M000|M010|M020|M030|M040|M060);
		    FPCP_type |= (F040|F060);
		    MMU_type |= (MMU030|MMU040|MMU060);
		    FPUID_table[1*2] = 1;
		    break;
		default:
		    err ("�w��� MPU, FPU �̓T�|�[�g���Ă��܂���(-m).\n");
		    /* NOT REACHED */
		}
	    } while ((optarg = next) != NULL);
#ifndef	__LIBC__
	    Mfree (new_optarg);
#endif
	}
	break;
    case 'n':
	String_length_min = ck_atoi (optarg);
	break;
    case 'o':
	String_width = ck_atoi (optarg);
	if( String_width < 1 || 80 < String_width )
	    err ("�l�������Ȕ͈͂ł�(-o).\n");
	break;
    case 'p':
	option_p = TRUE;
	break;
    case 'q':
	option_q = TRUE;
	if( optarg ) Quiet_mode = ck_atoi (optarg);
	if( Quiet_mode < 0 || 1 < Quiet_mode )
	    err ("�l�������Ȕ͈͂ł�(-q).\n");
	break;
    case 'r':
	option_r = TRUE;
	break;
    case 's':
	Output_Symbol = optarg ? ck_atoi (optarg) : 0;
	if ((unsigned short)Output_Symbol > 2)
	    err ("�l�������Ȕ͈͂ł�(-s).\n");
	break;
    case 'u':
	Disasm_UnusedTrapUndefined = FALSE;
	if (optarg && (ck_atoi (optarg) == 1))
	    Disasm_SX_Window = TRUE;
	break;
    case 'v':
	option_v = TRUE;
	break;
    case 'w':
	Data_width = ck_atoi (optarg);
	if( Data_width < 1 || 32 < Data_width )
	    err ("�l�������Ȕ͈͂ł�(-w).\n");
	break;
    case 'x':
	option_x = TRUE;
	break;
    case 'y':
	option_y = TRUE;
	break;
    case 'z':
	option_z = TRUE;
	Absolute = ABSOLUTE_ZOPT;
	FileType = 'r';
	{
	    char* p;
#ifndef	__LIBC__
	    char* new_optarg = (char*) Malloc (strlen (optarg) + 1);
	    optarg = strcpy (new_optarg, optarg);
#endif
	    p = strchr (optarg, ',');
	    if (p) {
		*p++ = '\0';
		Base = (address) atox (optarg);
		Exec = (address) atox (p);
	    } else
		Exec = Base = (address) atox (optarg);
#ifndef	__LIBC__
	    Mfree (new_optarg);
#endif
	}
	if (Base > Exec) {
	    err ("�l�������Ȕ͈͂ł�(-z).\n");
	}
	break;

    case 'A':
	Disasm_MnemonicAbbreviation = TRUE;
	break;
    case 'B':
	option_B = TRUE;
	break;
    case 'C':
	SymbolColonNum = optarg ? ck_atoi (optarg) : 0;
	if( SymbolColonNum < 0 || 3 < SymbolColonNum )
	    err ("�l�������Ȕ͈͂ł�(-C).\n");
	break;
    case 'D':
	option_D = TRUE;
	break;
    case 'E':
	option_E = TRUE;
	break;
    case 'F':
	Disasm_Dbra = FALSE;
	break;
    case 'G':
	Arg_after_call = TRUE;
	break;
    case 'I':
	option_I = TRUE;
	break;
    case 'K':
	if (!optarg[0] || optarg[1])
	    err ("�R�����g�L�����N�^�͈ꕶ�������w��o���܂���(-K).\n");
	CommentChar = *optarg;
	break;
    case 'L':
	if (!optarg[0] || optarg[1])
	    err ("���x���̐擪�����͈ꕶ�������w��o���܂���(-L).\n");
	if ((char)'0' <= *optarg && *optarg <= (char)'9')
	    err ("���x���̐擪�����ɐ����͎g���܂���(-L).\n");
	Label_first_char = *optarg;
	break;
    case 'M':
	option_M = TRUE;
	break;
    case 'N':
	option_N = TRUE;
	break;
    case 'P':
	Emulate_mode = ck_atoi (optarg);
	if (Emulate_mode & ~0x03)
	    err ("�l�������Ȕ͈͂ł�(-P).\n");
	break;
    case 'Q':
    /*  option_Q = TRUE;  */
	break;
    case 'R':
	UndefRegLevel = ck_atoi (optarg);
	if (UndefRegLevel & ~0x0f)
	    err ("�l�������Ȕ͈͂ł�(-R).\n");
	break;
    case 'S':
	option_S = TRUE;
	Output_SplitByte = ( optarg ? ck_atoi (optarg) : 64 ) * 1024;
	break;
    case 'T':
	option_T = TRUE;
	if (optarg)
	    Tablefilename = optarg;
	break;
    case 'U':
	option_U = TRUE;
	strupr (opsize);
	/* fall through */
    case 'X':
	strupr (Hex);
	break;
    case 'V':
	Verbose = ck_atoi (optarg);
	if( Verbose < 0 || 2 < Verbose )
	    err ("�l�������Ȕ͈͂ł�(-V).\n");
	break;
    case 'W':
	Compress_len = ck_atoi (optarg);
	break;
    case 'Y':
	option_Y = TRUE;
	break;
    case 'Z':
	option_Z = TRUE;
	Zerosupress_mode = optarg ? ck_atoi(optarg) : 0;
	if( Zerosupress_mode < 0 || 1 < Zerosupress_mode )
	    err ("�l�������Ȕ͈͂ł�(-Z).\n");
	break;
    case '#':
	Debug = ck_atoi (optarg);
	break;
    case '-':
	{
#ifndef	OSKDIS
	    const char** p;
	    char c = optarg[0];
	    if (!optarg[1] && (c == (char)'x' || c == (char)'r' || c == (char)'z')) {
		FileType = c;
		break;
	    }
#endif

#define isLONGOPT(str) (strcmp (optarg, str) == 0)
	         if (isLONGOPT (   "fpsp"))	Emulate_mode |=  1;
	    else if (isLONGOPT ("no-fpsp"))	Emulate_mode &= ~1;
	    else if (isLONGOPT (   "isp"))	Emulate_mode |=  2;
	    else if (isLONGOPT ("no-isp"))	Emulate_mode &= ~2;
	    else if (isLONGOPT ("no-fpu"))	{ FPCP_type = 0; init_fpuid_table (); }
	    else if (isLONGOPT ("no-mmu"))	MMU_type = 0;

	    else if (isLONGOPT ("sp"))		sp_a7_flag = TRUE;
	    else if (isLONGOPT ("a7"))		sp_a7_flag = FALSE;
	    else if (isLONGOPT ("old-syntax"))	Old_syntax = TRUE;
	    else if (isLONGOPT ("new-syntax"))	Old_syntax = FALSE;
	    else if (isLONGOPT ("inreal"))	Inreal_flag = TRUE;
	    else if (isLONGOPT ("real"))	Inreal_flag = FALSE;

	    else if (isLONGOPT ("overwrite"))	option_overwrite = TRUE;
	    else if (isLONGOPT ("help"))	usage (0);
	    else if (isLONGOPT ("version"))	{ printf ("dis version %s\n", Version);
						  exit (0); }
#ifndef	OSKDIS
	    else if (strncmp (optarg, "header=", 7) == 0)
		Header_filename = optarg + 7;
	    else if ((p = include_option (optarg)) != NULL)
		*p = include_filename (optarg);
#endif
	    else
		err ("%s: unrecognized option '--%s'\n", argv[0], optarg);
	}
	break;
/*  case '?':  */
    default:
	exit (EXIT_FAILURE);
	break;
    }
    return;
}


extern void
usage (int exitcode)
{
    static const char message[] =
	"usage: dis [option] ���s�t�@�C���� [�o�̓t�@�C����]\n"
	"option:\n"

	/* �������I�v�V���� */
	"	-a[num]		num �s���ƂɃA�h���X���R�����g�œ����(num ���ȗ������ 5 �s����)\n"
	"	-b num		���Ε��򖽗߂̃T�C�Y�̏o��(0:���� 1:��ɏȗ� 2:��ɕt����)\n"
	"	-c		���x���`�F�b�N���s��Ȃ�\n"
	"	-d		�f�o�C�X�h���C�o�̎��Ɏw��\n"
	"	-e[file]	���x���t�@�C���̏o��\n"
	"	-f		�o�C�g���얽�߂̕s��o�C�g�̃`�F�b�N($00 or $ff ?)�����Ȃ�\n"
	"	-g[file]	���x���t�@�C����ǂݍ���\n"
	"	-h		�f�[�^�̈撆�� $4e75(rts)�̎��̃A�h���X�ɒ��ڂ���\n"
	"	-i		�����Ŗ���`���߂������Ă��f�[�^�̈�ƌ��Ȃ��Ȃ�\n"
	"	-j		�A�h���X�G���[���N����ł��낤���߂𖢒�`���߂ƌ��Ȃ��Ȃ�\n"
	"	-k		���߂̒����w�����x���͂Ȃ����̂ƌ��Ȃ�\n"
	"	-l		�v���O�����̈悪������Ȃ��Ȃ�܂ŉ��x���{�����Ƃ����Ȃ�\n"
	"	-m 680x0[,...]	�t�A�Z���u���Ώۂ� MPU ���w��(68000-68060,680x0)\n"
	"	-m 68851	68851 ���߂�L���ɂ���(-m68020 �w�莞�̂ݗL��)\n"
	"	-m 6888x[,ID]	�L���� FPCP �Ƃ��� ID ���w��(68881/68882 ID=0-7,�ȗ���1)\n"
	"	-n num		������Ƃ��Ĕ��肷��ŏ��̒���. 0 �Ȃ画�肵�Ȃ�(�����l=3)\n"
	"	-o num		������̈�̌���(1��num��80 �����l=60)\n"
	"	-p		�f�[�^�̈撆�̃v���O�����̈�𔻕ʂ��Ȃ�\n"
	"	-q[num]		���b�Z�[�W���o�͂��Ȃ�([0]:�ʏ� 1:�e�[�u���Ɋւ�������o�͂��Ȃ�)\n"
	"	-r		������� 16 �i���̃R�����g��t����\n"
	"	-s[num]		�V���{���e�[�u���̏o��([0]:���Ȃ� 1:[�ʏ�] 2:�S��)\n"
/* -t */
	"	-u[num]		���g�p�� A,F line trap �𖢒�`���߂ƌ��Ȃ��Ȃ�(num=1 SX-Window�Ή�)\n"
	"	-v		�P�Ȃ�t�A�Z���u�����X�g�̏o��\n"
	"	-w num		�f�[�^�̈�̉��o�C�g��(1��num��32 �����l=8)\n"
	"	-x		���ۂ̃I�y�R�[�h�� 16 �i���̃R�����g�ŕt����\n"
	"	-y		�S�Ẵf�[�^�̈���v���O�����̈�łȂ����m���߂邱�Ƃ����Ȃ�\n"
	"	-z base,exec	���s�t�@�C���� base ����̃o�C�i���t�@�C���Ƃ݂Ȃ��Aexec �����͂���\n"

	/* �啶���I�v�V���� */
	"\n"
	"	-A		cmpi, movea ���� cmp, move ���ɂ���\n"
	"	-B		bra �̌�ł����s����\n"
	"	-C[num]		���x���̌�̃R����(0:�t���Ȃ� 1:�S�Ă�1�� [2]:�ʏ� 3:�S�Ă�2��)\n"
	"	-D		�f�[�^�Z�N�V�������ɂ��v���O������F�߂�\n"
	"	-E		�o�C�g���얽�߂̕s��o�C�g�̏��������`�F�b�N�����Ȃ�\n"
	"	-F		dbra,fdbra �� dbf,fdbf �Ƃ��ďo�͂���\n"
	"	-G		�T�u���[�`���R�[���̒���Ɉ�����u���v���O��������͂���\n"
/* -H */
	"	-I		���߂̒����������x���̃A�h���X��\\������\n"
/* -J */
	"	-K char		char ���R�����g�L�����N�^�Ƃ��ėp����\n"
	"	-L char		char �����x�����̐擪�����Ƃ��ėp����\n"
	"	-M		cmpi, move, addi.b, subi.b #imm ����� pack, unpk �ɃR�����g������\n"
	"	-N		�T�C�Y���f�t�H���g�Ȃ�t���Ȃ�\n"
/* -O */
	"	-P num		�\\�t�g�E�F�A�G�~�����[�V�������߂�L���ɂ���(�r�b�g�w��, �����l=3)\n"
	"		+1	���������������_���߂�L���ɂ���\n"
	"		+2	�������������߂�L���ɂ���\n"
/*	"	-Q		���ϐ� dis_opt ���Q�Ƃ��Ȃ�\n"	*/
	"	-R num		���g�p�t�B�[���h�̃`�F�b�N���ڂ̎w��(�r�b�g�w��, �����l=15)\n"
	"		+1	mulu.l, muls.l, ftst.x �ɂ����関�g�p���W�X�^�t�B�[���h�̃`�F�b�N\n"
	"		+2	�g���A�h���b�V���O�ł̃T�v���X���ꂽ���W�X�^�t�B�[���h�̃`�F�b�N\n"
	"		+4	�T�v���X���ꂽ�C���f�b�N�X���W�X�^�ɑ΂���X�P�[�����O�̃`�F�b�N\n"
	"		+8	�T�v���X���ꂽ�C���f�b�N�X���W�X�^�ɑ΂���T�C�Y�w��(.l)�̃`�F�b�N\n"
	"	-S[num]		�o�̓t�@�C���� num KB ���Ƃɕ�������(num ���ȗ������ 64KB)\n"
	"	-T[file]	�e�[�u���L�q�t�@�C����ǂݍ���\n"
	"	-U		�j�[���j�b�N��啶���ŏo�͂���\n"
	"	-V num		�o�b�N�g���b�N�̌����̕\\��(0:���Ȃ� [1]:�v���O�����̈� 2:�S�Ă̗̈�)\n"
	"	-W num		����f�[�^�� .dcb �ŏo�͂���ŏ��o�C�g��. 0�Ȃ爳�k���Ȃ�(�����l=64)\n"
	"	-X		16 �i����啶���ŏo�͂���\n"
	"	-Y		�J�����g�f�B���N�g������� include �t�@�C������������\n"
	"	-Z[num]		16 �i�����[���T�v���X����([0]:�ʏ� 1:�ȗ��\\��'$'���ȗ�)\n"

	/* �P�ꖼ�I�v�V���� */
	"\n"

#ifndef	OSKDIS
	"	--include-XXX-mac=file	include �t�@�C���̎w��(XXX = doscall,iocscall,fefunc)\n"
	"	--exclude-XXX-mac	include �t�@�C����ǂݍ��܂Ȃ�\n"
#endif
	"	--header=file	�w�b�_�t�@�C���̎w��(���ϐ� dis_header ���D��)\n"
	"	--(no-)fpsp	���������������_���߂�[�L��](����)�ɂ���\n"
	"	--(no-)isp	�������������߂�[�L��](����)�ɂ���\n" 
	"	--no-fpu	���� FPU ���߂𖳌��ɂ���(-m68040�`68060 �̌�Ɏw��)\n" 
	"	--no-mmu	���� MMU ���߂𖳌��ɂ���(-m68030�`68060 �̌�Ɏw��)\n" 
	"	--sp		a7 ���W�X�^��'sp'�ƕ\\�L����(�W���ł� --a7)\n"
	"	--old-syntax	�A�h���b�V���O�����\\�L�ŏo�͂���(�W���ł� --new-syntax)\n"
	"	--(in)real	���������_��[�����\\�L](�����\\��)�ŏo�͂���\n"
	"	--overwrite	�t�@�C���𖳏����ŏ㏑������\n"
	"	--version	�o�[�W������\\������\n"
	"	--help		�g�p�@��\\������\n"

#if 0	/* �B���I�v�V���� */
	"\n"
#ifndef	OSKDIS
	"	--x|r|z		���s�t�@�C���� X|R|Z �`���ƌ��Ȃ�\n"
#endif
	"	-# num		�f�o�b�O���[�h\n"
#endif
	; /* end of message */

    print_title ();
    printf (message);
    exit (exitcode);
}

/* EOF */
