#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream f("lfa.in");
ofstream g("lfa.out");

char alfa, cuv[1001], alf[101];
char stiva[1001];
int n, m, tranz, qf[101], nr, q0, x, var, finall[101], y, mat[101][101][101];
int gasit;

void landaAfn(int start, char cuv[], int k)
{
    char x = cuv[0];
    if (strlen(cuv) == 0 && finall[start] == 1)
    {
        gasit = 1;
        g<<"CUVANT ACCEPTAT";
        return;
    }

    if (strlen(cuv) != 0 && gasit == 0)
    {
        for (int i = 0; i<n; i++)
            if (mat[start][i][40] == 1)
            {
                landaAfn(i,cuv,k);
            }
            else if (mat[start][i][x - 'a'] == 1)
            {
                stiva[k] = x;
                strcpy (cuv, cuv+1);
                landaAfn(i, cuv, k+1);
                for (int j = strlen(cuv); j>0; j--)
                    cuv[j] = cuv[j - 1];
                cuv[0] = stiva[k];

            }
    }
}

int main()
{
    f>>n;
    f>>m;
    for (int i=0; i<m; i++)
        f>>alf[i];
    f>>q0;
    f>>nr;
    for (int i=0; i<nr; i++)
    {
        f>>x;
        finall[x] = 1;
    }
    f>>tranz;
    for (int i=0; i<tranz; i++)
    {
        f>>x>>alfa>>y;
        if (alfa != '$')
            var = alfa - 'a';
        else
            var = 40;
        mat[x][y][var] = 1;
    }
    f>>cuv;
    landaAfn(q0, cuv, 0);
    if (gasit == 0)
        g<<"CUVANTUL NU POATE SA FIE ACCEPTAT";
    return 0;
}
