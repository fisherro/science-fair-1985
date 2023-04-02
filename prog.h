#include <stdio.h>

struct pob {    /* planet prop */
    double m;   /* mass */
    double r;   /* radius */
    double xp;  /* x position */
    double yp;  /* y position */
    double xv;  /* x velocity */
    double yv;  /* y velocity */
    char name[];
};
struct pop {    /* primary prop */
    double m;
    double r;
    char name[];
};
struct pos {        /* ship prop */
    double m;       /* grams */
    double r;       /* metres */
    double xp;      /* ditto */
    double yp;
    double xv;      /* metres/second */
    double yv;
    double zr;      /* rotation along z axis */
    double zrv;     /* z axis rotational velocity */
    double izr;     /* direction of inertia along z axis */
    double fuel;    /* fuel left */
    double eff;     /* fuel effeciency/fuel:thrust ratio */
    double mthrst;  /* max thrust m/s/s */
    char name[];
};
struct pop primary;
struct pob planet[];
struct pos ship;
int nop;
int i;
int scale;
double dx;
double dy;
double fx;
double fy;
double dxv;
double dyv;

sign(arg) /* return sign of "arg" */
double arg;
{   if (arg < 0) return(-1);
    if (arg > 0) return(1);
    if (arg = 0) return(0);
}

sq(arg) /* square value "arg" */
double arg;
{   return(arg * arg);
}
