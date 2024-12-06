#include "globrig.h"
#include "define.h"
#include "defpage.h"
#include "nef2.h"
#include "cim.h"
#include "usemod.h"

Void usepas(n, pl, rez)
long n;
ptr_ *pl;
long *rez;
{
  /* number of option */
  /* pointer to argument list */
  /* result */
  a pp1, pp2;

  pp1 = pl->cel;
  next(pl);
  pp2 = pl->cel;
  next(pl);
  switch (n) {

  /*    n:   use_x(pp1,pp2,pl.cel,rez) */
  case 1:
    use_1(pp1, pp2, pl->cel, rez);
    break;

  case 2:
    use_2(pp1, pp2, pl->cel, rez);
    break;

  case 3:
    use_3(pp1, pp2, pl->cel, rez);
    break;

  case 4:
    use_4(pp1, pp2, pl->cel, rez);
    break;

  case 5:
    use_5(pp1, pp2, pl->cel, rez);
    break;

  case 6:
    use_6(pp1, pp2, pl->cel, rez);
    break;

  case 7:
    use_7(pp1, pp2, pl->cel, rez);
    break;

  case 8:
    use_8(pp1, pp2, pl->cel, rez);
    break;

  case 9:
    use_9(pp1, pp2, pl->cel, rez);
    break;

  case 10:
    use_10(pp1, pp2, pl->cel, rez);
    break;

  case 11:
    use_11(pp1, pp2, pl->cel, rez);
    break;

  case 12:
    use_12(pp1, pp2, pl->cel, rez);
    break;

  case 13:
    use_13(pp1, pp2, pl->cel, rez);
    break;

  case 14:
    use_14(pp1, pp2, pl->cel, rez);
    break;

  case 15:
    use_15(pp1, pp2, pl->cel, rez);
    break;

  case 16:
    use_16(pp1, pp2, pl->cel, rez);
    break;

  case 17:
    use_17(pp1, pp2, pl->cel, rez);
    break;

  case 18:
    use_18(pp1, pp2, pl->cel, rez);
    break;

  case 19:
    use_19(pp1, pp2, pl->cel, rez);
    break;

  case 20:
    use_20(pp1, pp2, pl->cel, rez);
    break;

  case 21:
    use_21(pp1, pp2, pl->cel, rez);
    break;

  case 22:
    use_22(pp1, pp2, pl->cel, rez);
    break;

  case 23:
    use_23(pp1, pp2, pl->cel, rez);
    break;

  case 24:
    use_24(pp1, pp2, pl->cel, rez);
    break;

  case 25:
    use_25(pp1, pp2, pl->cel, rez);
    break;

  case 26:
    use_26(pp1, pp2, pl->cel, rez);
    break;

  case 27:
    use_27(pp1, pp2, pl->cel, rez);
    break;

  case 28:
    use_28(pp1, pp2, pl->cel, rez);
    break;

  case 29:
    use_29(pp1, pp2, pl->cel, rez);
    break;

  case 30:
    use_30(pp1, pp2, pl->cel, rez);
    break;

  case 31:
    use_31(pp1, pp2, pl->cel, rez);
    break;

  case 32:
    use_32(pp1, pp2, pl->cel, rez);
    break;

  case 33:
    use_33(pp1, pp2, pl->cel, rez);
    break;

  case 34:
    use_34(pp1, pp2, pl->cel, rez);
    break;

  case 35:
    use_35(pp1, pp2, pl->cel, rez);
    break;

  case 36:
    use_36(pp1, pp2, pl->cel, rez);
    break;

  case 37:
    use_37(pp1, pp2, pl->cel, rez);
    break;

  case 38:
    use_38(pp1, pp2, pl->cel, rez);
    break;

  case 39:
    use_39(pp1, pp2, pl->cel, rez);
    break;

  case 40:
    use_40(pp1, pp2, pl->cel, rez);
    break;

  case 41:
    use_41(pp1, pp2, pl->cel, rez);
    break;

  case 42:
    use_42(pp1, pp2, pl->cel, rez);
    break;

  case 43:
    use_43(pp1, pp2, pl->cel, rez);
    break;

  case 44:
    use_44(pp1, pp2, pl->cel, rez);
    break;

  /* 45 & 46 are passed*/

  case 47:
    use_47(pp1, pp2, pl->cel, rez);
    break;

  case 48:
    use_48(pp1, pp2, pl->cel, rez);
    break;

  case 49:
    use_49(pp1, pp2, pl->cel, rez);
    break;

  case 50:
    use_50(pp1, pp2, pl->cel, rez);
    break;

  case 51:
    use_51(pp1, pp2, pl->cel, rez);
    break;

  case 52:
    use_52(pp1, pp2, pl->cel, rez);
    break;

  case 53:
    use_53(pp1, pp2, pl->cel, rez);
    break;

  case 54:
    use_54(pp1, pp2, pl->cel, rez);
    break;

  case 55:
    use_55(pp1, pp2, pl->cel, rez);
    break;

  case 56:
    use_56(pp1, pp2, pl->cel, rez);
    break;

  case 57:
    use_57(pp1, pp2, pl->cel, rez);
    break;

  case 58:
    use_58(pp1, pp2, pl->cel, rez);
    break;

  case 59:
    use_59(pp1, pp2, pl->cel, rez);
    break;

  case 60:
    use_60(pp1, pp2, pl->cel, rez);
    break;

  case 61:
    use_61(pp1, pp2, pl->cel, rez);
    break;

  case 62:
    use_62(pp1, pp2, pl->cel, rez);
    break;

  case 63:
    use_63(pp1, pp2, pl->cel, rez);
    break;

  case 64:
    use_64(pp1, pp2, pl->cel, rez);
    break;

  case 65:
    use_65(pp1, pp2, pl->cel, rez);
    break;

  case 66:
    use_66(pp1, pp2, pl->cel, rez);
    break;

  case 67:
    use_67(pp1, pp2, pl->cel, rez);
    break;

  case 68:
    use_68(pp1, pp2, pl->cel, rez);
    break;

  case 69:
    use_69(pp1, pp2, pl->cel, rez);
    break;

  case 70:
    use_70(pp1, pp2, pl->cel, rez);
    break;

  case 71:
    use_71(pp1, pp2, pl->cel, rez);
    break;

  case 72:
    use_72(pp1, pp2, pl->cel, rez);
    break;

  case 73:
    use_73(pp1, pp2, pl->cel, rez);
    break;

  case 74:
    use_74(pp1, pp2, pl->cel, rez);
    break;

  case 75:
    use_75(pp1, pp2, pl->cel, rez);
    break;

  case 76:
    use_76(pp1, pp2, pl->cel, rez);
    break;

  case 77:
    use_77(pp1, pp2, pl->cel, rez);
    break;

  case 78:
    use_78(pp1, pp2, pl->cel, rez);
    break;

  case 79:
    use_79(pp1, pp2, pl->cel, rez);
    break;

  case 80:
    use_80(pp1, pp2, pl->cel, rez);
    break;

  case 81:
    use_81(pp1, pp2, pl->cel, rez);
    break;

  case 82:
    use_82(pp1, pp2, pl->cel, rez);
    break;

  case 83:
    use_83(pp1, pp2, pl->cel, rez);
    break;

  case 84:
    use_84(pp1, pp2, pl->cel, rez);
    break;

  case 85:
    use_85(pp1, pp2, pl->cel, rez);
    break;

  case 86:
    use_86(pp1, pp2, pl->cel, rez);
    break;

  case 87:
    use_87(pp1, pp2, pl->cel, rez);
    break;

  case 88:
    use_88(pp1, pp2, pl->cel, rez);
    break;

  case 89:
    use_89(pp1, pp2, pl->cel, rez);
    break;

  case 90:
    use_90(pp1, pp2, pl->cel, rez);
    break;

  case 91:
    use_91(pp1, pp2, pl->cel, rez);
    break;

  case 92:
    use_92(pp1, pp2, pl->cel, rez);
    break;

  case 93:
    use_93(pp1, pp2, pl->cel, rez);
    break;

  case 94:
    use_94(pp1, pp2, pl->cel, rez);
    break;

  case 95:
    use_95(pp1, pp2, pl->cel, rez);
    break;

  case 96:
    use_96(pp1, pp2, pl->cel, rez);
    break;

  case 97:
    use_97(pp1, pp2, pl->cel, rez);
    break;

  case 98:
    use_98(pp1, pp2, pl->cel, rez);
    break;

  case 99:
    use_99(pp1, pp2, pl->cel, rez);
    break;

  case 100:
    use_100(pp1, pp2, pl->cel, rez);
    break;

  case 101:
    use_101(pp1, pp2, pl->cel, rez);
    break;

  case 102:
    use_102(pp1, pp2, pl->cel, rez);
    break;

  case 103:
    use_103(pp1, pp2, pl->cel, rez);
    break;

  case 104:
    use_104(pp1, pp2, pl->cel, rez);
    break;

  case 105:
    use_105(pp1, pp2, pl->cel, rez);
    break;

  case 106:
    use_106(pp1, pp2, pl->cel, rez);
    break;

  case 107:
    use_107(pp1, pp2, pl->cel, rez);
    break;

  case 108:
    use_108(pp1, pp2, pl->cel, rez);
    break;

  case 109:
    use_109(pp1, pp2, pl->cel, rez);
    break;

  case 110:
    use_110(pp1, pp2, pl->cel, rez);
    break;

  case 111:
    use_111(pp1, pp2, pl->cel, rez);
    break;

  case 112:
    use_112(pp1, pp2, pl->cel, rez);
    break;

  case 113:
    use_113(pp1, pp2, pl->cel, rez);
    break;

  case 114:
    use_114(pp1, pp2, pl->cel, rez);
    break;

  case 115:
    use_115(pp1, pp2, pl->cel, rez);
    break;

  case 116:
    use_116(pp1, pp2, pl->cel, rez);
    break;

  case 117:
    use_117(pp1, pp2, pl->cel, rez);
    break;

  case 118:
    use_118(pp1, pp2, pl->cel, rez);
    break;

  case 119:
    use_119(pp1, pp2, pl->cel, rez);
    break;

  case 120:
    use_120(pp1, pp2, pl->cel, rez);
    break;

  case 121:
    use_121(pp1, pp2, pl->cel, rez);
    break;

  case 122:
    use_122(pp1, pp2, pl->cel, rez);
    break;

  case 123:
    use_123(pp1, pp2, pl->cel, rez);
    break;

  case 124:
    use_124(pp1, pp2, pl->cel, rez);
    break;

  case 125:
    use_125(pp1, pp2, pl->cel, rez);
    break;

  case 126:
    use_126(pp1, pp2, pl->cel, rez);
    break;

  case 127:
    use_127(pp1, pp2, pl->cel, rez);
    break;

  case 128:
    use_128(pp1, pp2, pl->cel, rez);
    break;

  case 129:
    use_129(pp1, pp2, pl->cel, rez);
    break;

  case 130:
    use_130(pp1, pp2, pl->cel, rez);
    break;

  case 131:
    use_131(pp1, pp2, pl->cel, rez);
    break;

  case 132:
    use_132(pp1, pp2, pl->cel, rez);
    break;

  case 133:
    use_133(pp1, pp2, pl->cel, rez);
    break;

  case 134:
    use_134(pp1, pp2, pl->cel, rez);
    break;

  case 135:
    use_135(pp1, pp2, pl->cel, rez);
    break;

  case 136:
    use_136(pp1, pp2, pl->cel, rez);
    break;

  case 137:
    use_137(pp1, pp2, pl->cel, rez);
    break;

  case 138:
    use_138(pp1, pp2, pl->cel, rez);
    break;

  case 139:
    use_139(pp1, pp2, pl->cel, rez);
    break;

  case 140:
    use_140(pp1, pp2, pl->cel, rez);
    break;

  case 141:
    use_141(pp1, pp2, pl->cel, rez);
    break;

  case 142:
    use_142(pp1, pp2, pl->cel, rez);
    break;

  case 143:
    use_143(pp1, pp2, pl->cel, rez);
    break;

  case 144:
    use_144(pp1, pp2, pl->cel, rez);
    break;

  case 145:
    use_145(pp1, pp2, pl->cel, rez);
    break;

  case 146:
    use_146(pp1, pp2, pl->cel, rez);
    break;

  case 147:
    use_147(pp1, pp2, pl->cel, rez);
    break;

  case 148:
    use_148(pp1, pp2, pl->cel, rez);
    break;

  case 149:
    use_149(pp1, pp2, pl->cel, rez);
    break;

  case 150:
    use_150(pp1, pp2, pl->cel, rez);
    break;

  default:
    *rez = pp1;
    break;
  }
}




Void add(d, r)
long *d, *r;
{
  /*==============*/
  /*  d+:= r      */
  /*==============*/
  mpd x, y;
  numberdescriptor *WITH;

  /* deleted sign processing 2-oct-89 */
  if (*d == null_) {
    if (*r == null_)
      return;
    pointr(*r, &y.sa);
    if (y.snd->dtype == number) {
      /* instead of d:=r; changed 22-oct-90 */
      gets1(d, &x.sa);
      *x.snd = *y.snd;
    }
    return;
  }
  points(*d, &x.sa);
  if (x.snd->dtype != number) {
    *d = null_;
    err(9L);
    return;
  }
  if (*r == null_)
    return;
  pointr(*r, &y.sa);
  if (y.snd->dtype == number) {
    WITH = x.snd;
    WITH->val += y.snd->val;
  } else {  /* not number */
    *d = null_;
    err(10L);
  }

  /* a */
  /* a */
}  /* add */


Void arithm(op)
long op;
{
  /* kod operacii */
  /*======================================*/
  /* operacii + - * div mod               */
  /*      > < >= <=                       */
  /* whod:    v[base -2]  v[base -1]      */
  /*              a1        a2            */
  /* wyhod:   v[base -2]   oswob.         */
  /*           a1 op a2                   */
  /*======================================*/
  /* wyhod */

  mpd x;
  longint n[2];   /* changed 17-nov-90 */
  a rez;
  aa a_adr[2];
  char dts[2];

  longint k;
  long j;

  rez = null_;
  for (k = 2; k >= 1; k--) {
    getval(&v[base - k - 1]);
    if (v[base - k - 1] == null_) {
      n[2 - k] = 0;
      dts[2 - k] = dummy;
      /* a_adr - not used ! */
    } else {
      pointr(v[base - k - 1], &x.sa);

      dts[2 - k] = x.snd->dtype;
      if (dts[2 - k] == number)
	n[2 - k] = x.snd->val;
      else
	n[2 - k] = 0;
      a_adr[2 - k] = x.sad->name;
    }
  }





  if (dts[0] == dummy && dts[1] == dummy || dts[0] == number ||
      dts[1] == number) {
    if (op == cgt && n[0] > n[1] || op == clt && n[0] < n[1] ||
	op == cge && n[0] >= n[1] || op == cle && n[0] <= n[1])
      rez = atomt;
    else {  /* arifmetika */
      if (op >= cmult && op <= cminus) {  /* sozdatx atom rezulxtata */
	gets1(&rez, &x.sa);
	if (op == cadd)
	  k = n[0] + n[1];
	else if (op == cminus)
	  k = n[0] - n[1];
	else if (op == cmult)
	  k = n[0] * n[1];
	else if (op == cdiv)
	  k = n[0] / n[1];
	else if (op == cmod) {
	  k = n[0] % n[1];
/* p2c: erm.z, line 1070:
 * Note: Using % for possibly-negative arguments [317] */
	}
	x.snd->dtype = number;
	x.snd->val = k;
      }
    }

  } else {
    if (op >= cmult && op <= cminus) {
      gets1(&rez, &x.sa);
      x.snd->dtype = number;
      x.snd->val = 0;
    } else {  /* operations cgt,cge,clt.cle only */

      if (((1L << ((long)dts[0])) &
	   ((1L << ((long)atom)) | (1L << ((long)idatom)) |
	    (1L << ((long)keyword)) | (1L << ((long)tatom)))) != 0) {
	if (((1L << ((long)dts[1])) &
	     ((1L << ((long)atom)) | (1L << ((long)idatom)) |
	      (1L << ((long)keyword)) | (1L << ((long)tatom)))) != 0) {
	  switch (op) {

	  case clt:
	    j = 1;
	    break;

	  case cle:
	    j = 2;
	    break;

	  case cgt:
	    j = 3;
	    break;

	  case cge:
	    j = 4;
	    break;
	  }

	  if (compatom(j, a_adr[0], a_adr[1]))
	    rez = atomt;
	} else {
	  if (dts[1] == dummy) {
	    if (op == cgt || op == cge)
	      rez = atomt;
	  }
	}


      } else {
	if (dts[0] == dummy) {
	  if (((1L << ((long)dts[1])) &
	       ((1L << ((long)atom)) | (1L << ((long)idatom)) |
		(1L << ((long)keyword)) | (1L << ((long)tatom)))) != 0) {
	    if (op == clt || op == cle)
	      rez = atomt;
	  }
	}
      }
    }

  }

_L33:
  base--;
  v[base - 2] = rez;



}















Void unmins()
{
  mpd x, y;
  a rez;

  getval(&v[base - 2]);
  if (v[base - 2] == null_)
    goto _L99;
  pointr(v[base - 2], &y.sa);
  if (y.snd->dtype != number) {
    v[base - 2] = null_;
    goto _L99;
  }
  gets1(&rez, &x.sa);
  *x.snd = *y.snd;
  x.snd->val = -y.snd->val;   /* del sign change 3-oct-89 */
  v[base - 2] = rez;
_L99: ;
}  /* unmins*/


/* Local variables for bltin: */
struct LOC_bltin {
  long l;
} ;

Local long alen(k, LINK)
long k;
struct LOC_bltin *LINK;
{
  bl80 m;
  a t;


  t = k;
  pointa(t, m, &LINK->l);   /* [1] ibm/pc */
  return LINK->l;
}  /* alen */


Void bltin(rez, success, pl, n)
long *rez;
boolean *success;
ptr_ *pl;
long n;
{
  /* 1-j argument */
  /* nomer wstr.prawila */
  /*===========================*/
  /* wyzow wstroennogo prawila */
  /*===========================*/
  struct LOC_bltin V;
  /* wyhod */

  char rulenum;
  a k, s;
  mpd x, y;
  long t;
  longint li_;   /* 12- mar -91 */
  bl80 mm;
  numberdescriptor *WITH;
  atomdescriptor *WITH1;
  specdescriptor *WITH2;
  long FORLIM;


  rulenum = n;
  k = pl->cel;
  if ((k & 511) != 0 || k >= 65535L || k < 0)
    pointr(k, &x.sa);
  *success = true;
  *rez = k;
  switch (rulenum) {

  case 1:   /* #implode */
    implode(pl, rez);
    break;

  case 2:   /* #explode */
    if (k == null_)
      goto _L99;
    if (((1L << ((long)x.sad->dtype)) &
	 ((1L << ((long)fatom + 1)) - (1L << ((long)atom)))) != 0)
      explode(k, rez);
    else
      *success = false;
    break;

  case 3:   /* #atom */
    if (k == null_)
      goto _L99;
    *success = (((1L << ((long)x.sad->dtype)) &
		 ((1L << ((long)fatom + 1)) - (1L << ((long)atom)))) != 0);
    break;

  case 4:   /* #number */
    if (k == null_)
      *success = false;
    else
      *success = (x.sad->dtype == number);
    break;

  case 5:   /* #ident */
    if (k == null_)
      *success = false;
    else
      *success = (x.sad->dtype == idatom);
    break;

  case 6:   /* #list */
    if (k == null_)
      goto _L99;
    *success = (x.sad->dtype == listmain);
    break;

  case 7:   /* #tree */
    if (k == null_)
      goto _L99;
    *success = (x.sad->dtype == treemain);
    break;

  case 8:   /* #tatom */
    if (k == null_)
      *success = false;
    else
      *success = (x.sad->dtype == tatom);
    break;

  case 9:   /* #fatom */
    if (k == null_)
      *success = false;
    else
      *success = (x.sad->dtype == fatom);
    break;

  case 10:   /* #_keyword */
    if (k == null_)
      *success = false;
    else
      *success = (x.sad->dtype == keyword);
    break;

  case 11:   /* #_specdesc */
    if (k == null_)
      *success = false;
    else
      *success = (x.sad->dtype == spec);
    break;

  case 12:   /* #len */
    if (k == null_)
      *rez = 0;
    else {
      switch (x.sad->dtype) {

      case atom:
      case idatom:
      case keyword:
      case tatom:
      case fatom:
	*rez = alen(x.sad->name, &V);
	break;

      case number:
	/* pods~itatx ~islo zna~.cifr */
	li_ = x.snd->val;
	t = 0;
	while (li_ != 0) {
	  li_ /= 10;
	  t++;
	}
	if (t == 0)
	  t = 1;
	if (x.snd->val < 0)
	  t++;
	*rez = t;
	break;
	/* number */

      case listmain:
	*rez = x.smld->totalelnum;
	break;

      case treemain:
	*rez = x.smtd->totalarcnum;
	break;



      default:
	*rez = 0;
	break;
      }/* case */
    }
    gets1(&k, &x.sa);
    WITH = x.snd;
    WITH->dtype = number;
    WITH->val = *rez;
    *rez = k;
    break;
    /* #len */

  case 13:   /* #_specatom */
    if ((k & 511) != 0 || k >= 65535L || k < 0)
      *success = false;
    break;

  case 14:   /* #_rulename */
    if (k == null_)
      *success = false;
    else
      *success = (x.sad->dtype == rulename);
    break;

  case 15:   /* #_varname */
    if (k == null_)
      *success = false;
    else {
      *success = (((1L << ((long)x.sad->dtype)) &
	    ((1L << ((long)fvariable + 1)) - (1L << ((long)variable)))) != 0);
      points(k, &x.sa);
      x.svd->guard = true;
    }
    break;

  case 16:
  case 17:   /* #_ruletoatom, #_varntoatm */
    if (k == null_)
      *success = false;
    else {
      if (x.srd->dtype == rulename && rulenum == 16 ||
	  (((1L << ((long)x.svd->dtype)) &
	    ((1L << ((long)fvariable + 1)) - (1L << ((long)variable)))) != 0 &&
	   rulenum == 17)) {
	gets1(&s, &y.sa);
	WITH1 = y.sad;
	WITH1->dtype = idatom;
	if (rulenum == 16)   /* !!! vax !!! */
	  WITH1->name = x.srd->name;
	else
	  WITH1->name = x.svd->name;
	*rez = s;
      } else
	*success = false;
    }
    break;

  case 18:   /* #_vardesloc */
    if (((1L << ((long)x.svd->dtype)) &
	 ((1L << ((long)fvariable + 1)) - (1L << ((long)variable)))) != 0) {
      next(pl);
      s = pl->cel;
      pointr(s, &y.sa);
      points(k, &x.sa);
      x.svd->location = y.snd->val;
    } else
      *success = false;
    break;

  case 19:   /* #debug */
    if (eqatoms(pl->cel, atomrules)) {
      /*
           rules */
      debugrule = true;
    } else if (eqatoms(pl->cel, atomnorules)) {
      /* norules */
      debugrule = false;
    }
    break;

  case 20:   /* #_spectodsc */
    gets1(&s, &y.sa);
    if ((k & 511) == 0 && k < 65535L && k >= 0) {
      WITH2 = y.sspec;
      WITH2->dtype = spec;
      WITH2->val = k;
    } else
      *y.sspec = *x.sspec;
    *rez = s;
    break;

  case 21:   /* _content2 */
    if ((k & 511) == 0 && k < 65535L && k >= 0)
      *success = false;
    else {
      s = x.snd->val;
      gets1(&k, &x.sa);
      WITH = x.snd;
      WITH->dtype = number;
      WITH->val = s;

      *rez = k;
    }
    break;
    /* _content2 */

  case 22:   /* #chr */
    if ((k & 511) == 0 && k < 65535L && k >= 0) {
      *rez = null_;
      *success = false;
    } else if (x.snd->dtype != number || x.snd->val > 255 || x.snd->val < 0) {
      *rez = null_;
      *success = false;
    } else {
      t = x.snd->val;
      mm[0] = (Char)t;
      V.l = 1;
      putatm(mm, V.l, &s);
      gets1(&k, &x.sa);
      WITH1 = x.sad;
      if (is_rig_letter((int)t))
	WITH1->dtype = idatom;
      else
	WITH1->dtype = atom;
      WITH1->name = s;
      *rez = k;
    }
    break;
    /* chr */

  case 23:   /* parameter */
    *rez = null_;
    FORLIM = run_param_cnt;
    for (V.l = 1; V.l <= FORLIM; V.l++) {  /* see glovar.pas */
      printf(" %s", run_param_array[V.l - 1]);
      lconc(rez, str_to_atom(run_param_array[V.l - 1]));
    }
    putchar('\n');
    break;

  case 24:   /* #_totatom */
    if (k == null_)
      *success = false;
    else {
      gets1(&s, &y.sa);
      WITH1 = y.sad;
      WITH1->dtype = tatom;
      WITH1->name = x.sad->name;
      WITH1->flags = 0;
      *rez = s;
    }
    break;

  case 25:   /* #ord */
    if ((k & 511) == 0 && k < 65535L && k >= 0)
      goto _L99;
    if (((1L << ((long)x.sad->dtype)) &
	 (((1L << ((long)keyword + 1)) - (1L << ((long)atom))) |
	  (1L << ((long)tatom)))) != 0) {
      s = x.sad->name;
      pointa(s, mm, &V.l);
      gets1(&k, &y.sa);
      WITH = y.snd;
      WITH->dtype = number;
      WITH->val = mm[0];
      *rez = k;
    } else
      *success = false;
    break;
    /* ord */

  case 26:   /* call_pas */
    if ((k & 511) == 0 && k < 65535L && k >= 0) {
      *rez = null_;
      goto _L99;
    }
    if (x.snd->dtype != number) {
      *rez = null_;
      goto _L99;
    }
    next(pl);
    if (debugrule) {
      if (out_screen)
	printf("(%12ld)", x.snd->val);
      else
	fprintf(out, "(%12ld)", x.snd->val);
    }
    usepas(x.snd->val, pl, rez);
    break;



  }/* case */
_L99:
  if (*success) {
    if (pl->ptrtype != ptrtree)
      next(pl);
  } else
    *rez = null_;
}


boolean compnames(p, ld)
long p, ld;
{
  /* adres w sr-prostr. (<>0) deskr.atoma */
  /*    ili peremennoj w {ablone    */
  /* adres w st-prostr. (<>0) glawnogo */
  /* fragmenta deskr.spiska */
  /*=======================================*/
  /* esli r -atom, prowerqet rawen  li on  */
  /* imeni spiska(derewa) ld, da -true     */
  /*                         net -false    */
  /* esli r-peremennaq, to priswaiwaet ej  */
  /* imq  ili null, esli imeni             */
  /* net, wozwr. true.                     */
  /*=======================================*/
  boolean Result;
  mpd x, y;
  a w;


  pointr(p, &x.sa);
  /* polu~itx dostup k deskr. atoma ili peremennoj */
  Result = false;
  if (ld == null_)
    return Result;
  pointr(ld, &y.sa);
  /* polu~itx dostup k deskr.spiska */
  if (((1L << ((long)x.sad->dtype)) &
       ((1L << ((long)fatom + 1)) - (1L << ((long)atom)))) != 0)
  {  /* atom */
    w = y.smld->name;
    if ((w & 511) == 0 && w < 65536L && w >= 0) {
      /* u spiska net imeni */
      return false;
    }
    /* posmotretx deskr. imeni (atom ili spisok) */
    pointr(w, &y.sa);
    if (((1L << ((long)y.sad->dtype)) &
	 ((1L << ((long)fatom + 1)) - (1L << ((long)atom)))) != 0)
      return (eqatoms(p, w));
    return Result;
  }  /* atom */
  if (x.sad->dtype != spec) {
    v[mybase + x.svd->location - 1] = y.smld->name;
    /* peremennoj priswoitx spisok imen iz y.smld^.name */
    return true;
  }  /* specadres */

  /* specadres */
  w = y.smld->name;
  if ((w & 511) == 0 && w < 65536L && w >= 0)
    return (w == x.sspec->val);
  return Result;

  /* w {ablone - peremennaq */
}


Void concop(a1, a2)
long *a1, a2;
{
  /*======================================*/
  /* operaciq  a1 !! a2                   */
  /*       ( a1 !! a2 ) -> a1             */
  /*======================================*/
  /* wyhod */

  mpd x;
  ptr_ p1;
  a l;


  l = *a1;
  if (a2 == null_) {
    if (l == null_)
      goto _L99;
    else {
      pointr(l, &x.sa);
      if (x.smld->dtype == listmain)
	goto _L99;
      else {
	l = null_;
	goto _L99;
      }
    }
  }
  pointr(a2, &x.sa);
  if (x.smld->dtype != listmain) {
    l = null_;
    goto _L99;
  }
  if (l != null_) {
    pointr(l, &x.sa);
    if (x.smld->dtype != listmain) {
      l = null_;
      goto _L99;
    }
  }
  first(a2, &p1);
  while (p1.nel != 0) {
    lconc(&l, p1.cel);
    next(&p1);
  }
_L99:
  *a1 = l;
}  /* concop */


Void copyop()
{
  /*======================*/
  /*      v[base -1]      */
  /*whod:         a       */
  /*wyhod:  copy( a )     */
  /*======================*/
  /* wyhod */

  long k;
  mpd x, y, z;
  a r1, r2, r3;


  getval(&v[base - 2]);
  if (v[base - 2] == null_)
    goto _L99;
  pointr(v[base - 2], &x.sa);
  switch (x.sad->dtype) {

  case atom:
  case idatom:
  case keyword:
  case number:
  case tatom:
  case fatom:
  case variable:
  case idvariable:
  case nvariable:
  case fvariable:
  case spec:   /* coord removed */
    gets1(&r1, &y.sa);
    *y.sad = *x.sad;
    v[base - 2] = r1;
    break;

  case rulename:
  case object_d:
    gets2(&r1, &y.sa);
    *y.srd = *x.srd;
    v[base - 2] = r1;
    break;

  case listmain:
  case treemain:
    gets5(&r1, &y.sa);
    /* skopirowatx glawnyj deskriptor */
    *y.smld = *x.smld;
    v[base - 2] = r1;
    r2 = x.smld->next;
    while (r2 != null_) {
      pointr(r2, &x.sa);
      gets5(&r3, &z.sa);
      *z.smld = *x.smld;
      points(r1, &y.sa);
      y.smld->next = r3;
      r1 = r3;
      r2 = z.smld->next;
    }  /* while */
    break;

  }/* case */
_L99: ;   /* wyhod */
}  /* copyop */


Void epilog()
{
  long iii;
  longint dr, dw, dp;


  for (iii = 0; iii < filenum; iii++) {
    if (filetab[iii].isopen) {
      if (filetab[iii].screen)
	putchar('\n');
      else {
	putc('\n', files[iii]);
	if (files[iii] != NULL)
	  fclose(files[iii]);
	files[iii] = NULL;
      }



    }
  }
  printf("\n========== End of execution ==========\n");
  vola(&dr, &dw, &dp);
  if (dr + dw + dp > 0)
    printf("A-Space:%12ld/%12ld/%12ld pages \n", dr, dw, dp);
  vols(&dr, &dw, &dp);
  if (dr + dw + dp > 0)
    printf("S-Space :%12ld reads %12ld writes %12ld pages \n", dr, dw, dp);
  if (out_open) {
    if (out != NULL)
      fclose(out);
    out = NULL;
  }

  closea();
  closes();
}  /* epilog */



Void eqop(o)
long o;
{
  /* cequ(=), cnequ(<>) */
  /*====================================*/
  /*   rawenstwo/ nerawenstwo obxektow  */
  /* whod: v[base -2]     v[base -1]    */
  /*       a1             a2            */
  /* wyhod:  t / null     oswob.        */
  /*====================================*/
  boolean rez;


  getval(&v[base - 3]);
  getval(&v[base - 2]);
  eqop1(o, v[base - 3], v[base - 2], &rez);
  if (rez && o == cequ || !rez && o == cnequ)
    v[base - 3] = atomt;
  else
    v[base - 3] = null_;
  base--;
}  /* eqop */


Void eqop1(o, a1, a2, rez1)
long o, a1, a2;
boolean *rez1;
{
  /* cequ(=), cnequ(<>) */
  /*====================================*/
  /*   rawenstwo/ nerawenstwo obxektow  */
  /* whod: a1             a2            */
  /* wyhod:  true / false w rez1        */
  /*====================================*/
  /*wyhod */

  mpd x, y;
  boolean rez;
  ptr_ px, py;



  rez = true;
  if (a2 == null_) {
    if (a1 == null_)
      goto _L1;
    else {
      pointr(a1, &x.sa);
      rez = (((1L << ((long)x.smld->dtype)) &
	      ((1L << ((long)listmain)) | (1L << ((long)treemain)))) != 0 &&
	     x.smld->totalelnum == 0);
      goto _L1;
    }
  }  /* a2 =null */
  /* oba ne null */

  pointr(a2, &x.sa);
  if (a1 == null_) {
    rez = (((1L << ((long)x.smld->dtype)) &
	    ((1L << ((long)listmain)) | (1L << ((long)treemain)))) != 0 &&
	   x.smld->totalelnum == 0);
    goto _L1;
  }
  pointr(a1, &y.sa);
  switch (x.smld->dtype) {

  case variable:
  case idvariable:
  case nvariable:
  case fvariable:
  case spec:
  case rulename:   /* coord removed */
    rez = (memcmp(x.sc8, y.sc8, sizeof(atomdescriptor)) == 0);
    break;

  case number:
    /* added 20-jul-1989 in pc/at, changed 3-oct sign */
    rez = (y.snd->dtype == number && x.snd->val == y.snd->val);
    break;



  case atom:
  case idatom:
  case keyword:
  case tatom:
    rez = (((1L << ((long)y.sad->dtype)) & (((1L << ((long)keyword + 1)) -
		(1L << ((long)atom))) | (1L << ((long)tatom)))) != 0 &&
	   x.sad->name == y.sad->name);
    break;

  case fatom:
    rez = (y.sad->dtype == fatom && x.sad->name == y.sad->name);
    break;

  case listmain:
    rez = (x.smld->totalelnum == y.smld->totalelnum &&
	   y.smld->dtype == listmain);
    if (rez) {
      first(a1, &px);
      first(a2, &py);
      while (rez && px.nel != 0) {
	eqop1(o, px.cel, py.cel, &rez);
	next(&px);
	next(&py);
      }  /* while */
    }
    break;

  case treemain:
    rez = (x.smtd->totalarcnum == y.smtd->totalarcnum &&
	   y.smtd->dtype == treemain);
    if (rez) {
      first(a1, &px);
      while (rez && px.nel != 0) {
	first(a2, &py);
	while (py.nel != 0 && px.UU.U1.arc != py.UU.U1.arc)
	  next(&py);
	if (py.nel == 0)
	  rez = false;
	else
	  eqop1(o, px.cel, py.cel, &rez);
	next(&px);
      }  /* while */
    }
    break;
  }/* case */
_L1:

  *rez1 = rez;

  /* a2 <>null */
}  /* eqop */


Void explode(kk, rez)
long kk, *rez;
{
  /*=====================================*/
  /* sozdaet spisok odnobukwennyh atomow */
  /*=====================================*/
  a s, k;
  mpd x;
  longint l;   /* changed fron integer 17-nov-90 */
  string80 str_val;
  Char STR1[256];
  long FORLIM;

  *rez = null_;
  if (kk == null_)
    goto _L99;

  pointr(kk, &x.sa);
  switch (x.sad->dtype) {

  case fatom:   /* added 17-feb-92 */
    real_to_string(str_val, take_fatom(x.sad->name));
    break;

  case number:
    long_to_str(str_val, x.snd->val);
    break;

  case 5:
  case 6:
  case 7:
  case tatom:
    aa_str(str_val, x.sad->name);
    break;



  default:
    goto _L99;
    break;
  }/* case */
  /* w m sformirowan massiw simwolow */
  s = null_;   /* rez.spisok */
  FORLIM = strlen(str_val);
  for (l = 0; l < FORLIM; l++) {
    sprintf(STR1, "%c", str_val[l]);
    k = str_to_textatom(STR1);
    lconc(&s, k);
  }  /* for */
  *rez = s;
_L99: ;
}  /* explode */


#define max_digit       10   /* maximum for longint type */


/* Local variables for implode: */
struct LOC_implode {
  bl80 m, m1;
  mpd x;
  a k;
  long p1;   /* posledn.zanqtyj |l-t w m1 */
  string80 str_val;
} ;

Local Void pass(pl, LINK)
ptr_ *pl;
struct LOC_implode *LINK;
{
  ptr_ pl1;
  long t, l;

  while (pl->nel != 0) {
    LINK->k = pl->cel;
    if (LINK->k != null_) {
      pointr(LINK->k, &LINK->x.sa);
      if (LINK->x.smld->dtype == listmain) {
	first(LINK->k, &pl1);   /*, st */
	pass(&pl1, LINK);
      } else {  /* not list */
	if (((1L << ((long)LINK->x.sad->dtype)) &
	     ((1L << ((long)fatom + 1)) - (1L << ((long)atom)))) == 0)
	  goto _L99;

	if (LINK->x.sad->dtype == fatom) {   /* added 17-feb-92 */
	  real_to_string(LINK->str_val, take_fatom(LINK->x.sad->name));
	  l = strlen(LINK->str_val);
	  if (LINK->p1 + l > 80) {
	    err(25L);
	    goto _L99;
	  }
	  for (t = 0; t < l; t++)
	    LINK->m1[LINK->p1 + t] = LINK->str_val[t];
	  LINK->p1 += l;
	} else {
	  if (((1L << ((long)LINK->x.sad->dtype)) &
	       (((1L << ((long)keyword + 1)) - (1L << ((long)atom))) |
		(1L << ((long)tatom)))) != 0) {
	    /* wzqtx atom iz a-prostranstwa w m */
	    LINK->k = LINK->x.sad->name;
	    pointa(LINK->k, LINK->m, &l);   /* [1] ibm/pc */
	    if (LINK->p1 + l > 80) {
	      err(25L);
	      goto _L99;
	    }
	    for (t = 0; t < l; t++)
	      LINK->m1[LINK->p1 + t] = LINK->m[t];
	    LINK->p1 += l;
	  } else {  /* number */
	    /*==============================*/
	    /* perewesti ~islo w simwoly i  */
	    /* pomestitx w m [1..max_digit]         */
	    /*==============================*/
	    LINK->k = LINK->x.snd->val;
	    if (LINK->k < 0)   /* changed from abs call */
	      LINK->k = -LINK->k;
	    for (t = max_digit - 1; t >= 0; t--) {
	      l = LINK->k % 10;
/* p2c: erm.z, line 1925:
 * Note: Using % for possibly-negative arguments [317] */
	      LINK->k /= 10;
	      LINK->m[t] = (Char)(l + '0');
	    }
	    t = 1;
	    while (t < max_digit && LINK->m[t - 1] == '0')
	      t++;
	    if (LINK->x.snd->val < 0) {
	      if (LINK->p1 == 80) {
		err(25L);
		goto _L99;
	      }
	      LINK->p1++;
	      LINK->m1[LINK->p1 - 1] = '-';
	    }
	    if (LINK->p1 + max_digit - t > 79) {
	      err(25L);
	      goto _L99;
	    }
	    for (l = t - 1; l < max_digit; l++) {
	      LINK->p1++;
	      LINK->m1[LINK->p1 - 1] = LINK->m[l];
	    }
	  }  /* number */
	}
      }  /* not list */
    }  /* k<> null */
    next(pl);
  }  /* while */
_L99: ;


}  /* pass */


Void implode(pl, rez)
ptr_ *pl;
long *rez;
{
  /* 1-j argument */
  /*======================================*/
  /* skleiwanie  atomow a1 a2 ... an  do  */
  /* perwogo, otli~nogo ot atoma ili null */
  /*======================================*/
  struct LOC_implode V;
  longint l;
  /* rab. */
  /* change from integer 17-nov-90*/
  boolean id;
  long FORLIM;
  atomdescriptor *WITH;


  V.p1 = 0;
  pass(pl, &V);
  if (V.p1 == 0) {
    *rez = null_;
    return;
  }
  putatm(V.m1, V.p1, &V.k);
  id = is_rig_letter(V.m1[0]);
  FORLIM = V.p1;
  for (l = 0; l < FORLIM; l++)
    id &= is_rig_symbol(V.m1[l]);
  l = 1;
  gets1(rez, &V.x.sa);
  WITH = V.x.sad;
  if (id)
    WITH->dtype = idatom;
  else
    WITH->dtype = atom;
  WITH->name = V.k;

  /* zapisatx nowyj atom w a-prostr. */

}

#undef max_digit


Void indxop()
{
  /*==============================================*/
  /* whod:        v[base-2]       v[base-1]       */
  /*              l               x               */
  /* wyhod:       l[ x ]          oswoboditx      */
  /*                                              */
  /*   esli l -object, to i rezulxtat - object    */
  /*  l[ -1 ]  - poslednij |l-t spiska            */
  /*  l[ -2 ]  - predposlednij |l-t spiska  ...   */
  /*==============================================*/
  /* wyhod */

  mpd x, y, z;
  long k, n;
  a r, t;
  boolean wasobject, mainlist;
  objdescriptor *WITH;


  getval(&v[base - 2]);
  if (v[base - 2] == null_) {
    err(5L);
    v[base - 3] = null_;
    goto _L1;
  }
  /* proweritx, ~to x -~islo */
  pointr(v[base - 2], &x.sa);
  if (x.snd->dtype != number) {
    err(3L);
    v[base - 3] = null_;
    goto _L1;
  }
  n = x.snd->val;
  /* delete sign proc.*/
  wasobject = false;
  getval(&v[base - 3]);
  if (v[base - 3] == null_)   /* rezulxtat= null */
    goto _L1;
  /* opredelitx tip l */
  pointr(v[base - 3], &z.sa);
  if (z.smld->dtype == listmain)
    y = z;
  else {
    if (z.smld->dtype != object_d) {
      err(4L);
      v[base - 3] = null_;
      goto _L1;
    }
    wasobject = true;
    if (z.sobj->variable_)
      t = v[z.sobj->fragmorvar - 1];
    else {
      t = z.sobj->fragmorvar;
      pointr(t, &x.sa);
      switch (x.smld->dtype) {

      case listmain:
      case listfragm:
	t = x.sfld->elt[z.sobj->nel - 1];
	break;

      /* ****** very strange ******* */
      case treemain:
	t = x.smtd->arc[z.sobj->nel - 1].elt;
	break;

      case treefragm:
	t = x.sftd->arc[z.sobj->nel - 1].elt;
	break;
      }/* case */
    }
    /* t ukazywaet na glawn. deskriptor spiska */
    if (t == null_) {
      v[base - 3] = null_;
      goto _L1;
    }
    pointr(t, &y.sa);
    if (y.smld->dtype != listmain) {
      err(4L);
      v[base - 3] = null_;
      goto _L1;
    }
  }  /* object */
  /*============================================*/
  /* y ukazywaet na deskriptor glawnogo spiska  */
  /* z - na object, esli takoj byl              */
  /*============================================*/
  /* wy~islenie l[x] */
  k = y.smld->totalelnum;
  if (n < 0)
    n += k + 1;
  if (n < 1 || n > k) {
    err(5L);
    /*  indeks wne spiska */
    v[base - 3] = null_;
    goto _L1;
  }
  /*================================*/
  /* poisk |l-ta spiska             */
  /*================================*/
  if (n <= y.smld->elnum) {
    mainlist = true;
    r = y.smld->elt[n - 1];
  } else {
    mainlist = false;
    n -= y.smld->elnum;
    t = y.smld->next;
    pointr(t, &y.sa);
    while (n > y.sfld->elnum) {
      n -= y.sfld->elnum;
      t = y.sfld->next;
      pointr(t, &y.sa);
    }
    r = y.sfld->elt[n - 1];
  }
  /* w r rezulxtat = l [ x ]  */
  if (wasobject) {
    points(v[base - 3], &z.sa);
    WITH = z.sobj;
    WITH->variable_ = false;
    if (mainlist)
      WITH->nel = n + 2;
    else
      WITH->nel = n;
    WITH->fragmorvar = t;   /* with */
  }  /* wasobject */
  else
    v[base - 3] = r;
_L1:
  base--;

  /* o{ibka */
}  /* indxop */


Void nameop()
{
  /*================================================*/
  /* operaciq  a :: l                               */
  /* whod:      v[base-2]       v[base-1]           */
  /*              a               l ili t           */
  /* wyhod:       a::l            oswoboditx        */
  /*                                                */
  /*================================================*/
  /* wyhod */

  mpd x, y;


  getval(&v[base - 2]);
  if (v[base - 2] == null_) {
    v[base - 3] = null_;
    goto _L1;
  }
  getval(&v[base - 3]);
  /* if v[base - 2] = null then
     goto 1; */
  /* deleted 23-1-1992 for null::<.a:b.> <> null */
  if ((v[base - 3] & 511) != 0 || v[base - 3] >= 65536L || v[base - 3] < 0) {
    pointr(v[base - 3], &y.sa);
    /*   dostup k atomu  */
    if (((1L << ((long)y.sad->dtype)) &
	 (((1L << ((long)fatom + 1)) - (1L << ((long)atom))) |
	  (1L << ((long)spec)))) == 0) {
      err(7L);
      v[base - 3] = null_;
      goto _L1;
    }
  }
  points(v[base - 2], &x.sa);
  /*  polu~itx deskriptor spiska (derewa) */
  if (((1L << ((long)x.smld->dtype)) &
       ((1L << ((long)listmain)) | (1L << ((long)treemain)))) == 0) {
    err(6L);
    v[base - 3] = null_;
    goto _L1;
  }
  x.smld->name = v[base - 3];
  v[base - 3] = v[base - 2];
_L1:
  base--;
}


Void prolog(y, debug, code)
ptr_ *y;
boolean debug;
long code;
{
  /*===============*/
  /* inicializaciq */
  /*===============*/
  long k, k1;
  mpd x;
  long iii;
  Char m[10];
  a rez, s;
  atomdescriptor *WITH;

  k = 1;
  vs[0] = code;
  debugrule = debug;
  base = 1;
  sbase = 1;
  /* w na~ale wse fajly zakryty */
  for (iii = 0; iii < filenum; iii++)
    filetab[iii].isopen = false;
  /* sozdatx atom t */
  m[0] = 'T';
  k1 = 1;
  putatm(m, k1, &s);
  gets1(&atomt, &x.sa);
  WITH = x.sad;
  WITH->dtype = idatom;
  WITH->name = s;
  v[base - 1] = atomt;
  base++;
  /* ~toby ne propal pri sborke musora */
  m[0] = 'R';
  m[1] = 'U';
  m[2] = 'L';
  m[3] = 'E';
  m[4] = 'S';
  k1 = 5;
  putatm(m, k1, &s);
  gets1(&atomrules, &x.sa);
  WITH = x.sad;
  WITH->dtype = idatom;
  WITH->name = s;
  v[base - 1] = atomrules;
  base++;

  m[0] = 'N';
  m[1] = 'O';
  m[2] = 'R';
  m[3] = 'U';
  m[4] = 'L';
  m[5] = 'E';
  m[6] = 'S';
  k1 = 7;
  putatm(m, k1, &s);
  gets1(&atomnorules, &x.sa);
  WITH = x.sad;
  WITH->dtype = idatom;
  WITH->name = s;
  v[base - 1] = atomnorules;
  base++;

  /* wojti w s-kod rigal */
  first(vs[0], y);
  next(y);   /* mybase */
  rez = y->cel;
  points(rez, &x.sa);
  mybase = base - 1;
  x.snd->val = mybase;
  next(y);   /* ~islo lok.peremennyh */
  rez = y->cel;
  pointr(rez, &x.sa);
  base += x.snd->val + 1;
  /* inicializaciq lok.per. glawn.progr. */
  for (iii = mybase; iii < varnum; iii++)
    v[iii] = null_;
  next(y);
  fail = false;
  break_ = false;
  continue_ = true;
  teklexem = null_;

  printf("=========Start  of execution ==========\n");

}  /* prolog */










Void selctr()
{
  /*==============================================*/
  /* whod:        v[ base -2 ]    v[ base -1 ]    */
  /*                      t               x       */
  /* wyhod:       v[ base -2]                     */
  /*                t.x           oswoboditx      */
  /*      esli t- object, to i rezulxtat -object  */
  /*==============================================*/
  /* wyhod */

  mpd x, y, z;
  a n;   /* imq selektora */
  a t, glavnder;   /* s-adr.glawn.derewa */
  long ai, i;
  boolean wasobject;
  maintreedescriptor *WITH;
  long FORLIM;
  fragmtreedescriptor *WITH1;
  objdescriptor *WITH2;


  getval(&v[base - 2]);
  if (v[base - 2] == null_) {
    err(21L);
    v[base - 3] = null_;
    goto _L1;
  }
  /* prowerim, ~to x -ne~islowoj atom */
  pointr(v[base - 2], &x.sa);
  if (x.sad->dtype != idatom) {
    err(22L);
    v[base - 3] = null_;
    goto _L1;
  }
  n = x.sad->name;
  wasobject = false;
  getval(&v[base - 3]);
  if (v[base - 3] == null_)
    goto _L1;
  /* rezulxtat =null */

  /* opredelitx tip t */
  pointr(v[base - 3], &z.sa);
  if (z.smtd->dtype == treemain)
    y = z;
  else {
    if (z.smtd->dtype != object_d) {
      err(23L);
      v[base - 3] = null_;
      goto _L1;
    }

    wasobject = true;
    if (z.sobj->variable_)
      t = v[z.sobj->fragmorvar - 1];
    else {
      t = z.sobj->fragmorvar;
      pointr(t, &x.sa);
      switch (x.smld->dtype) {

      case listmain:
      case listfragm:
	t = x.sfld->elt[z.sobj->nel - 1];
	break;

      case treemain:
	t = x.smtd->arc[z.sobj->nel - 1].elt;
	break;

      case treefragm:
	t = x.sftd->arc[z.sobj->nel - 1].elt;
	break;
      }/* case */
    }
    if (t == null_) {
      v[base - 3] = null_;
      goto _L1;
    }
    /* added 20-jul-1989 in pc/at from 10-jul-89 on vax */

    pointr(t, &y.sa);
    if (y.smtd->dtype != treemain) {
      err(23L);
      v[base - 3] = null_;
      goto _L1;
    }
  }

  /*=====================================*/
  /*  y ukazywaet na glawn.deskr. derewa */
  /*  z  na object, esli takoj byl       */
  /*  t  na deskr.glawn. derewa          */
  /*=====================================*/
  glavnder = t;   /* sna~ala w glawnom derewe */
  /* wy~islenie y.x               */
  /* poisk selektora n w derewe y */

  WITH = y.smtd;   /* with */
  FORLIM = WITH->arcnum;
  for (i = 1; i <= FORLIM; i++) {
    if (WITH->arc[i - 1].arcname == n) {   /* na{li */
      ai = i;
      n = WITH->arc[i - 1].elt;
      goto _L2;
    }
  }
  t = WITH->next;
  /* prodolvaem poisk w fragmentah */
  while (t != null_) {
    pointr(t, &y.sa);
    WITH1 = y.sftd;
    FORLIM = WITH1->arcnum;
    for (i = 1; i <= FORLIM; i++) {
      if (WITH1->arc[i - 1].arcname == n) {   /* na{li */
	ai = i;
	n = WITH1->arc[i - 1].elt;
	goto _L2;
      }
    }
    t = WITH1->next;   /* with */
  }  /* while */

  /* ne na{li !  */
  v[base - 3] = null_;
  goto _L1;
_L2:   /* na{li */
  /*==============================*/
  /* w n -rezulxtat t.x           */
  /* w ai -nomer w arc[...]       */
  /* w t  -s-ssylka na fragment   */
  /*==============================*/
  if (wasobject) {
    points(v[base - 3], &z.sa);
    WITH2 = z.sobj;
    WITH2->variable_ = false;
    WITH2->nel = ai;
    WITH2->fragmorvar = t;
    WITH2->glavn = glavnder;
    /* with */
  }  /* wasobject */
  else
    v[base - 3] = n;
_L1:
  base--;

  /* t ukazywaet na glawn.deskriptor derewa */
  /* o{ibka */
}  /* selctr */


Void int11(debug, code)
boolean debug;
long code;
{
  ptr_ y;
  boolean success;
  a rez;

  /* inicializaciq */
  prolog(&y, debug, code);
  /* osnownoj cikl */

  success = true;
  while (y.cel != null_ && continue_) {
    statement(y.cel, &success, &rez);
    next(&y);
  }
  epilog();
}


Void push()
{
  /*========================================*/
  /* zanqtx w steke peremennu`, nomer       */
  /* per. (base - 1)                        */
  /*========================================*/
  base++;
  if (base > varnum)
     {err(1L); epilog();exit(1); } /* VADIM CHANGED 8/6/95 */
}


Void pratom(aa_)
long aa_;
{
  /* pe~atx atoma */
  bl80 m;
  long s, l;
  a k;

  k = aa_;
  pointa(k, m, &l);   /* ibm/pc [1] */
  for (s = 0; s < l; s++) {
    if (out_screen)
      putchar(m[s]);
    else
      putc(m[s], out);
  }
}  /* pratom */


Void prblt(nn)
long nn;
{
  /* adres nom.wstr.prawila */
  mpd x;
  long bn;
  string80 rn;

  pointr(nn, &x.sa);
  bn = x.snd->val;
  switch (bn) {

  case 1:
    strcpy(rn, "#IMPLODE");
    break;

  case 2:
    strcpy(rn, "#EXPLODE");
    break;

  case 3:
    strcpy(rn, "#ATOM");
    break;

  case 4:
    strcpy(rn, "#NUMBER");
    break;

  case 5:
    strcpy(rn, "#IDENT");
    break;

  case 6:
    strcpy(rn, "#LIST");
    break;

  case 7:
    strcpy(rn, "#TREE");
    break;

  case 8:
    strcpy(rn, "#TATOM");
    break;

  case 9:
    strcpy(rn, "#FATOM");
    break;

  case 10:
    strcpy(rn, "#_KEYWORD");
    break;

  case 11:
    strcpy(rn, "#_SPECDESC");
    break;

  case 12:
    strcpy(rn, "#LEN");
    break;

  case 13:
    strcpy(rn, "#_SPECATOM");
    break;

  case 14:
    strcpy(rn, "#_RULENAME");
    break;

  case 15:
    strcpy(rn, "#_VARNAME");
    break;

  case 16:
    strcpy(rn, "#_RULETOATOM");
    break;

  case 17:
    strcpy(rn, "#_VARNTOATOM");
    break;

  case 18:
    strcpy(rn, "#_VARDESLOC");
    break;

  case 19:
    strcpy(rn, "#DEBUG");
    break;

  case 20:
    strcpy(rn, "#_SPECTODSC");
    break;

  case 21:
    strcpy(rn, "#_CONTENT2");
    break;

  case 22:
    strcpy(rn, "#CHR");
    break;

  case 23:
    strcpy(rn, "#PARM");
    break;

  case 24:
    strcpy(rn, "#_TOTATOM");
    break;

  case 25:
    strcpy(rn, "#ORD");
    break;

  case 26:
    strcpy(rn, "#CALL_PAS");
    break;
  }/* case */
  if (out_screen)
    fputs(rn, stdout);
  else
    fputs(rn, out);
}  /* prblt */


Void srchrule(rd, pp)
long rd;
ptr_ *pp;
{
  /*=================*/
  /* rd w st-prostr. */
  /*=================*/
  /*(rd: a; (* adres deskriptora #l * )
          (* w st-prostranstwe

  var
    pp: ptr (* ukaz. na sled. posle #l |l-t w spiske
             programmy * ) ); */
  /*====================================*/
  /* poisk w spiske programmy |l-ta,    */
  /* sled. za #l.                       */
  /* esli w deskriptore #l net ssylki   */
  /* na |tot |l-t, to wstawitx ee w     */
  /*  deskriptor #l                     */
  /*====================================*/
  mpd x, z;
  ptr_ y;
  a v1, v, name;
  ruledescriptor *WITH;


  pointr(rd, &x.sa);
  /* polu~itx deskriptor #l */
  if (x.srd->fragmadr == 0) {
    /* nuven poisk w spiske programmy */
    name = x.srd->name;
    v1 = x.srd->nomintab;
    /* s-adres #l w sr-prostranstwe */
    first(vs[0], &y);
    /* y na na~alo spiska
                          programmy */
    v = y.cel;
    pointr(v, &z.sa);
    while (z.srd->name != name) {
      while (y.cel != 0)
	next(&y);
      next(&y);
      v = y.cel;
      pointr(v, &z.sa);
    }  /* #l najden */
    next(&y);
    /* y na "base  prawila #l"    */
    /* zapisatx informaci` w deskriptor #l */
    points(v1, &x.sa);
    x.srd->fragmadr = y.UU.U1.curfragment;
    x.srd->nomintab = y.nel;
  }  /* poisk */
  else {
    /* w deskriptore #l estx ssylka na spisok
           programmy*/
    v = x.srd->fragmadr;
    pointr(v, &z.sa);
    WITH = x.srd;
    if (z.smld->dtype == listmain)
      y.cel = z.smld->elt[WITH->nomintab - 1];
    else
      y.cel = z.sfld->elt[WITH->nomintab - 1];
    y.ptrtype = ptrlist;
    y.nel = WITH->nomintab;
    y.UU.U1.curfragment = WITH->fragmadr;
  }
  *pp = y;
}  /* srchrule */


Void srchrule1(rd, pp)
long rd;
ptr_ *pp;
{
  /*=================*/
  /* rd w sr-prostr. */
  /*=================*/
  /*(rd: a; (* adres deskriptora #l * )
            (* w sr-prostranstwe * )
     var pp: ptr (* ukaz. na sled.
                  posle #l |l-t w spiske
                  programmy * ) );
  */
  /*====================================*/
  /* poisk w spiske programmy |l-ta,    */
  /* sled. za #l.                       */
  /* esli w deskriptore #l net ssylki   */
  /* na |tot |l-t, to wstawitx ee w     */
  /*  deskriptor #l                     */
  /*====================================*/
  mpd x, z;
  ptr_ y;
  a v, name;
  ruledescriptor *WITH;


  pointr(rd, &x.sa);
  /* polu~itx deskriptor #l */
  if (x.srd->fragmadr == 0) {
    /* nuven poisk w spiske programmy */
    name = x.srd->name;
    first(vs[0], &y);
    /* y na na~alo spiska
                          programmy */
    v = y.cel;
    pointr(v, &z.sa);
    while (z.srd->name != name) {
      while (y.cel != 0)
	next(&y);
      next(&y);
      v = y.cel;
      pointr(v, &z.sa);
    }  /* #l najden */
    next(&y);
    /* y na "base  prawila #l"    */
    /* zapisatx informaci` w deskriptor #l */
    points(rd, &x.sa);
    x.srd->fragmadr = y.UU.U1.curfragment;
    x.srd->nomintab = y.nel;
  }  /* poisk */
  else {
    /* w deskriptore #l estx ssylka na spisok
           programmy*/
    v = x.srd->fragmadr;
    pointr(v, &z.sa);
    WITH = x.srd;
    if (z.smld->dtype == listmain)
      y.cel = z.smld->elt[WITH->nomintab - 1];
    else
      y.cel = z.sfld->elt[WITH->nomintab - 1];
    y.ptrtype = ptrlist;
    y.nel = WITH->nomintab;
    y.UU.U1.curfragment = WITH->fragmadr;
  }
  *pp = y;
}  /* srchrule */


Void lastop()
{
  /*================================================*/
  /*  whod:     v[base -2]        v[base -1]        */
  /*              #l               $e               */
  /* wyhod:       zna~enie         oswoboditx       */
  /*            perem. $e                           */
  /*                                                */
  /*================================================*/
  ptr_ p;
  mpd x;
  a k;


  srchrule(v[base - 3], &p);
  /*   p ukaz. na sled.posle #l |l-t w tabl.prawil*/
  k = p.cel;
  pointr(k, &x.sa);
  /*  polu~itx dostup k base poslednego wyzowa #l */
  k = x.snd->val;
  if (k >= 0) {   /* change from x.snd^.sign=true 3-oct-89 */
    pointr(v[base - 2], &x.sa);
    /* polu~itx dostup k deskr.$e  */
    v[base - 3] = v[k + x.svd->location - 1];
  } else
    v[base - 3] = null_;
  base--;   /* osw.stek */
}  /* lastop */




Static Void errstrmes(n, m)
long n;
Char *m;
{
  Char STR2[130];

  switch (n) {

  case 1:
    sprintf(m, "Interpreter stack size overflow (stack size = %d);",
	    varnum);
    break;

  case 2:
    strcpy(m, "Assignment left side is not list or tree");
    break;

  case 3:
    strcpy(m, "List index is not number");
    break;

  case 4:
    strcpy(m, "Using [..] not for list");
    break;

  case 5:
    strcpy(m, "Index value exceeds list bounds");
    break;

  case 6:
    strcpy(m, "Not list or tree after \"::\"");
    break;

  case 7:
    strcpy(m, "Not atomic name before \"::\"");
    break;

  case 8:
    strcpy(m, "NULL in left side of assignment");
    break;

  case 9:
    strcpy(m, "Not numerical value in left side of \"+:=\" statement");
    break;

  case 10:
    strcpy(m, "Not numerical value in right side of \"+:=\" statement");
    break;

  case 11:
    strcpy(m, "File specification is not atom");
    break;

  case 12:
    strcpy(m, "Too long file specification");
    break;

  case 13:
    strcpy(m, "Too much open text files");
    break;

  case 14:
    strcpy(m, "File not open for output");
    break;

  case 15:
    strcpy(m, "Wrong file name in SAVE statement ");
    break;

  case 16:
    strcpy(m, "File was not closed before new opening");
    break;

  case 17:
    strcpy(m, "Atom length exceeds file record length");
    break;

  case 18:
    strcpy(m, "Not exist file in LOAD statement ");
    break;

  case 19:
    strcpy(m, "Wrong file name in OPEN statement ");
    break;

  case 21:
    strcpy(m, "Selector after \".\" is not identifier ");
    break;

  case 22:
    strcpy(m, "Selector in tree constructor is not identifier ");
    break;

  case 23:
    strcpy(m, "Not tree before \".\" operation ");
    break;

  case 24:
    strcpy(m, "Not tree or list as base of FORALL-IN statement ");
    break;

  case 25:
    strcpy(m, "Atom length more than 80 bytes in #IMPLODE ");
    break;

  case 26:
    strcpy(m, "\"BRANCHES\" option cannot be used for lists ");
    break;



  default:
    strcpy(m, "Unknown error");
    break;
  }
}


Void err(n)
long n;
{
  /* kod o{ibki */
  string80 m, STR1;
  Char STR2[174];

  errstrmes(n, m);
  sprintf(m, "*** ERROR %s %s", long_to_str(STR1, n), strcpy(STR2, m));
  if (out_open)
    fprintf(out, "%s\n", m);
  puts(m);
}  /* err */


Void errstr(n, s)
long n;
Char *s;
{
  /* kod o{ibki */
  string80 m, STR1;
  Char STR3[254];

  errstrmes(n, m);
  sprintf(m, "*** ERROR %s %s%s", long_to_str(STR1, n), strcpy(STR3, m), s);
  if (out_open)
    fprintf(out, "%s\n", m);
  puts(m);
}  /* err */


Void getval(m)
long *m;
{
  /* ssylka na perem.ili obxekt   */

  /*========================================*/
  /* esli m -peremennaq, to w m pomestitx   */
  /* ssylku na ee zna~enie                  */
  /*                                        */
  /*========================================*/
  mpd x;


  if (((*m) & 511) == 0 && *m < 65535L && *m >= 0)
    return;
  pointr(*m, &x.sa);
  if (((1L << ((long)x.svd->dtype)) &
       ((1L << ((long)fvariable + 1)) - (1L << ((long)variable)))) != 0 &&
      !x.svd->guard)
    *m = v[mybase + x.svd->location - 1];
}



/* End. */
