#include <stdio.h>
#include <graphics.h>
// #include <dos.h>

int main()
{
    int gd = DETECT, gm;
    int i, x, y, flag = 0;
    initgraph(&gd, &gm, "");

    /* get mid positions in x and y-axis */
    x = getmaxx() / 2;
    y = 30;

    while (!kbhit())
    {
        if (y >= getmaxy() - 30 || y <= 30)
            flag = !flag;
        /* draws the gray board */
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        circle(x, y, 30);
        floodfill(x, y, RED);

        /* delay for 10 milli seconds */
        delay(10);

        /* clears screen */
        cleardevice();
        if (flag)
        {
            y = y + 5;
        }
        else
        {
            y = y - 5;
        }
    }

    closegraph();
    return 0;
}
