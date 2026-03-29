void quick_sort(int imu[], int e_sx, int e_dx)
{
    int q;
    if(e_sx < e_dx)
    {
        q = partiziona(imu, e_sx, e_dx);
        quick_sort(imu, e_sx, q - 1);
        quick_sort(imu, q + 1, e_dx);
    }
}

int partiziona(int imu[], int sx, int dx)
{
    int pivot;
    int ipivot;
    ipivot = sx;
    pivot = imu[ipivot];

    while(sx < dx)
    {
        while((imu[sx] <= pivot) && (sx < dx))
        {
            sx++;
        }
        while(imu[dx] > pivot)
        {
            dx--;
        }
        if(sx < dx)
        {
            scambia(imu, sx, dx);
        }
    }
    scambia(imu, ipivot, dx);
    return dx;
}

void scambia(int imu[], int sx, int dx)
{
    int b;
    b = imu[sx];
    imu[sx] = imu[dx];
    imu[dx] = b;
}
