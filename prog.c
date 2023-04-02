#include <prog.h>

main()
{
    setship(); /* set up ship */
    runsys();
}

runsys()
{   while (1)
    {   input();
        mplanet();
        mship();
        output();
    }
}

setsys(fspec)
char fspec[];
{   FILE *fopen(), *fp;

    fp = fopen(fspec, "r");
    fscanf("%s %lf %lf", primary->name[], primary->m, primary->r);
    fscanf("%d", &nop);
    i = 0;
    while (i <= nop)
        fscanf( "%s %c %lf %lf %lf %lf %lf %lf",
                planet[i]->name,
                planet[i]->sysf,
                planet[i]->m,
                planet[i]->r,
                planet[i]->xp,
                planet[i]->yp,
                planet[i]->xv,
                planet[i]->yv
              );
}

setship();
{   char fspec[];
    FILE *fopen(), *fp;
    char sys;

    printf("Enter the file spec. of the ship data file.\n>");
    scanf("%s", fspec);
    fp = fopen(fspec, "r");

    fscanf("%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
            ship->name,
            ship->sysf, // Penciled in note to delete this
            ship->m,
            ship->r,
            ship->xp,
            ship->yp,
            ship->xv,
            ship->yv,
            ship->zr,
            ship->zrv,
            ship->izr,
            ship->fuel,
            // Penciled in note to insert ship->eff here
            ship->mthrst
          );
    fscanf("%s", sys);
    setsys(sys);
}

mplanet()
{
    i = 0;
    while (i <= nop)
    {   dx = planet[i]->xp;
        dy = planet[i]->yp;
        fx = GC * ((planet[i]->m * primary->m) / sq(dx));
        fy = GC * ((planet[i]->m * primary->m) / sq(dy));
        dxv = sign(dx) * (fx / planet[i]->m);
        dyv = sign(dy) * (fy / planet[i]->m);
        planet[i]->xv = planet[i]->xv + dxv;
        planet[i]->yv = planet[i]->yv + dyv;
        planet[i]->xp = planet[i]->xp + planet[i]->xv;
        planet[i]->yp = planet[i]->yp + planet[i]->yv;
        i++;
    }
}

mship()
{   dx = ship->xp;
    dy = ship->yp;
    fx = GC * ((ship->m * primary->m) / sq(dx));
    fy = GC * ((ship->m * primary->m) / sq(dy));
    dxv = sign(dx) * (fx / ship->m);
    dyv = sign(dy) * (fy / ship->m);
    ship->xv = ship->xv + dxv;
    ship->yv = ship->yv + dyv;

    i = 0;
    while (i <= nop)
    {   dx = ship->xp - planet[i]->xp;
        dy = ship->yp - planet[i]->yp;
        fx = GC * ((ship->m * planet[i]->m) / sq(dx));
        fy = GC * ((ship->m * planet[i]->m) / sq(dy));
        dxv = sign(dx) * (fx / ship->m);
        dyv = sign(dy) * (fy / ship->m);
        ship->xv = ship->xv + dxv;
        ship->yv = ship->yv + dyv;
        i++;
    }

    ship->xp = ship->xp + ship->xv;
    ship->yp = ship->yp + ship->yv;
    ship->zr = ship->zr + ship->zrv;

    i = 0;
    while (i <= nop)
    {   d = dsqrt(sq(ship->xp - plane[i]->xp)
                + sq(ship->yp - planet[i]->yp));
        if (sign(d - dabs(ship->r - plane[i]->r)) == -1)
            if (planet[i]->sysf == 's') enter();
            else crash();
    }
}

output()
/* for VT52 */
{
    char pre[2];
    int con;
    char cx;
    char cy;

    pre[0] = 27;
    pre[1] = 89;
    con = 32;

    cx = 40 + con;
    cy = 10 + con;
    printf("%s%c%c%c", pre[], cy, cx, '+');

    ddx = ((0 - ship->xp) * scale);
    ddy = ((0 - ship->yp) * scale);
    if (abs(ddx) <= 40 || abs(ddy) <= 10)
    {   cx = ddx + 40 + con;
        cy = ddy + (-10) + con;
        printf("%s%c%c%c", pre[], -cy, cx, '*');
    }

    i = 0;
    while (i <= nop)
    {   ddx = ((planet[i]->xp - ship->xp) * scale);
        ddy = ((platet[i]->yp - ship->yp) * scale);
        if (abs(ddx) <= 40 || abs(ddy) <= 10)
        {   cx = ddx + 40 + con;
            cy = ddy + (-1) + con;
            printf("%s%c%c%c", pre[], -cy cs, '0');
        }
    }

    head = datan2(ship->yv, ship->xv);
    vel = ship->yv * dsin(head);
    printf("%s%c%c%c", pre[], 21 + con, 0 + con);
    printf("heading:%3.2d degrees      linear velocity:%9.3d m/sec.\n",
            head, vel);
    printf("    yaw:%3.2d degrees  rotational velocity:%4.2d degrees/sec.",
            ship->zr, ship->zrv);
}

input();
{   char c;

    if ((c = kbinr()) == -1) return();
    if (c == 'a') ship->zrv = ship->zrv - thrust;
    if (c == 's') ship->zrv = ship->zrv + thrust;
    if (c == 't')
    {   fx = dcos(ship->zr) * thrust;
        fy = dsin(ship->zr) * thrust;
        dxv = fx / ship->m;
        dyv = fy / ship->m;
        ship->xv = ship->xv + dxv;
        ship->yv = ship->yv + dyv;
    }
}
