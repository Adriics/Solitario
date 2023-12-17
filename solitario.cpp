#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct carta
{
    int num;
    char pal;
};

int main()
{
    srand((unsigned)time(NULL));
    carta barajaVacia[4][6];
    carta baraja[4][6];
    carta cartesEliminatories[4] = {0, 0, 0, 0};
    carta perJugar[4] = {};
    char pals[] = {'A', 'B', 'C', 'D'};
    carta cartaAux;
    char t;
    int i1, i2, j1, j2;
    char colocar;
    carta auxiliar;
    int contEliminatories = 0;
    char tornarJugar;
    int perdut = 0, partidesJugades = 0;

    /* for (int filas = 0; filas < 4; filas++)
    {
        for (int columnas = 0; columnas < 6; columnas++)
        {
            barajaVacia[filas][columnas].num = 0;
            cout << "[" << barajaVacia[filas][columnas].num << barajaVacia[filas][columnas].pal << "] ";
        }
        cout << endl;
    } */

    do
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cout << endl;
                barajaVacia[i][j].num = 0;
                barajaVacia[i][j].pal = 'X';
            }
            cartesEliminatories[i].num = 0;
            cartesEliminatories[i].pal = 'x';
        }
        contEliminatories = 0;
        for (int filas = 0; filas < 4; filas++)
        {
            for (int columnas = 0; columnas < 6; columnas++)
            {
                if (filas == 0)
                {
                    for (int i = 0; i < 6; i++)
                    {
                        baraja[filas][columnas].num = columnas + 1;
                        baraja[filas][columnas].pal = 'A';
                    }
                }
                if (filas == 1)
                {
                    for (int i = 0; i < 6; i++)
                    {
                        baraja[filas][columnas].num = columnas + 1;
                        baraja[filas][columnas].pal = 'B';
                    }
                }
                if (filas == 2)
                {
                    for (int i = 0; i < 6; i++)
                    {
                        baraja[filas][columnas].num = columnas + 1;
                        baraja[filas][columnas].pal = 'C';
                    }
                }
                if (filas == 3)
                {
                    for (int i = 0; i < 6; i++)
                    {
                        baraja[filas][columnas].num = columnas + 1;
                        baraja[filas][columnas].pal = 'D';
                    }
                }
            }
            cout << endl;
        }

        for (int filas = 0; filas < 2500; filas++)
        {
            i1 = rand() % 4;
            i2 = rand() % 4;
            j1 = rand() % 6;
            j2 = rand() % 6;
            cartaAux = baraja[i1][j1];
            baraja[i1][j1] = baraja[i2][j2];
            baraja[i2][j2] = cartaAux;
        }

        /* for (int filas = 0; filas < 4; filas++)
         {
             for (int columnas = 0; columnas < 5; columnas++)
             {
                 baraja[filas][columnas].num == baraja[i2][j2].num;
                 baraja[filas][columnas].pal == baraja[i2][j2].pal;
                 cout << "[" << baraja[filas][columnas].num << baraja[filas][columnas].pal << "] ";
             }
             cout << endl;
         }*/

        // SELECCIONAR LA MÀ DE CARTES
        for (int filas = 0; filas < 4; filas++)
        {
            for (int columnas = 0; columnas < 6; columnas++)
            {
                if (columnas == 5)
                {
                    perJugar[filas] = baraja[filas][5];
                }
            }
        }
        // COLOCAR CARTES

        colocar = 's';
        while (colocar == 's' || colocar == 'S')
        {
            system("cls");
            cout << "BARAJA JUGANT:" << endl;
            for (int filas = 0; filas < 4; filas++)
            {
                for (int columnas = 0; columnas < 5; columnas++)
                {
                    cout << "[" << barajaVacia[filas][columnas].num << barajaVacia[filas][columnas].pal << "] ";
                }
                cout << endl;
            }
            cout << endl;
            cout << "MA DE CARTES:" << endl;

            for (int i = 0; i < 4; i++)
            {
                if (i == contEliminatories)
                {
                    cout << "[" << perJugar[i].num << perJugar[i].pal << "]";
                }
                else
                {
                    cout << "[X]";
                }
            }

            cout << endl;
            cout << "CARTES ELIMINATORIES:" << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << "[" << cartesEliminatories[i].num << cartesEliminatories[i].pal << "] ";
            }
            cout << endl;
            cout << "Vols colocar la carta? s/S)Si n/N)No" << endl;
            cin >> colocar;
            system("cls");
            if (colocar == 's' || colocar == 'S')
            {
                cout << "MA DE CARTES:" << endl;
                for (int i = 0; i < 4; i++)
                {
                    if (perJugar[i - 1].num == 0 || perJugar[0].num == 0)
                    {
                        cout << "[" << perJugar[i].num << perJugar[i].pal << "]";
                    }
                }

                switch (perJugar[contEliminatories].pal)
                {
                case 'A':
                    if (perJugar[contEliminatories].num == 6)
                    {
                        cartesEliminatories[contEliminatories] = perJugar[contEliminatories];
                        perJugar[contEliminatories].num = 0;
                        perJugar[contEliminatories].pal = 'x';
                        contEliminatories++;
                    }
                    else
                    {
                        barajaVacia[0][perJugar[contEliminatories].num - 1] = perJugar[contEliminatories];
                        auxiliar = baraja[0][perJugar[contEliminatories].num - 1];
                        baraja[0][perJugar[contEliminatories].num - 1] = perJugar[contEliminatories];
                        perJugar[contEliminatories] = auxiliar;
                    }
                    break;
                case 'B':
                    if (perJugar[contEliminatories].num == 6)
                    {
                        cartesEliminatories[contEliminatories] = perJugar[contEliminatories];
                        perJugar[contEliminatories].num = 0;
                        perJugar[contEliminatories].pal = 'x';
                        contEliminatories++;
                    }
                    else
                    {
                        barajaVacia[1][perJugar[contEliminatories].num - 1] = perJugar[contEliminatories];
                        auxiliar = baraja[1][perJugar[contEliminatories].num - 1];
                        baraja[1][perJugar[contEliminatories].num - 1] = perJugar[contEliminatories];
                        perJugar[contEliminatories] = auxiliar;
                    }
                    break;
                case 'C':
                    if (perJugar[contEliminatories].num == 6)
                    {
                        cartesEliminatories[contEliminatories] = perJugar[contEliminatories];
                        perJugar[contEliminatories].num = 0;
                        perJugar[contEliminatories].pal = 'x';
                        contEliminatories++;
                    }
                    else
                    {
                        barajaVacia[2][perJugar[contEliminatories].num - 1] = perJugar[contEliminatories];
                        auxiliar = baraja[2][perJugar[contEliminatories].num - 1];
                        baraja[2][perJugar[contEliminatories].num - 1] = perJugar[contEliminatories];
                        perJugar[contEliminatories] = auxiliar;
                    }
                    break;
                case 'D':

                    if (perJugar[contEliminatories].num == 6)
                    {
                        cartesEliminatories[contEliminatories] = perJugar[contEliminatories];
                        perJugar[contEliminatories].num = 0;
                        perJugar[contEliminatories].pal = 'x';
                        contEliminatories++;
                    }
                    else
                    {
                        barajaVacia[3][perJugar[contEliminatories].num - 1] = perJugar[contEliminatories];
                        auxiliar = baraja[3][perJugar[contEliminatories].num - 1];
                        baraja[3][perJugar[contEliminatories].num - 1] = perJugar[contEliminatories];
                        perJugar[contEliminatories] = auxiliar;
                    }
                    break;
                default:
                    break;
                }

                /* cout << "OBJECTIU:" << endl;
                for (int filas = 0; filas < 4; filas++)
                {
                    for (int columnas = 0; columnas < 5; columnas++)
                    {
                        cout << "[" << baraja[filas][columnas].num << baraja[filas][columnas].pal << "] ";
                    }
                    cout << endl;
                } */

                cout << "BARAJA JUGANT:" << endl;
                for (int filas = 0; filas < 4; filas++)
                {
                    for (int columnas = 0; columnas < 5; columnas++)
                    {
                        cout << "[" << barajaVacia[filas][columnas].num << barajaVacia[filas][columnas].pal << "] ";
                    }
                    cout << endl;
                }
                cout << endl;
                cout << "MA DE CARTES:" << endl;

                for (int i = 0; i < 4; i++)
                {
                    cout << "[" << perJugar[i].num << perJugar[i].pal << "] ";
                }

                cout << endl;
                cout << "CARTES ELIMINATORIES:" << endl;
                for (int i = 0; i < 4; i++)
                {
                    cout << "[" << cartesEliminatories[i].num << cartesEliminatories[i].pal << "] ";
                }
            }

            if (contEliminatories == 4)
            {
                for (int filas = 0; filas < 4; filas++)
                {
                    for (int columnas = 0; columnas < 5; columnas++)
                    {
                        // DARLE LA VUELTA A LA BARAJA OBJETUVO PARA COMPROVAR SI HE GANADO O NO
                        if (baraja[filas][columnas].num != 0)
                        {
                            barajaVacia[filas][columnas].num = baraja[filas][columnas].num;
                            barajaVacia[filas][columnas].pal = baraja[filas][columnas].pal;
                            baraja[filas][columnas].pal = 'x';
                            baraja[filas][columnas].num = 0;
                        }
                    }
                    cout << endl;
                }
                system("cls");
                cout << "BARAJA JUGANT:" << endl;
                for (int filas = 0; filas < 4; filas++)
                {
                    for (int columnas = 0; columnas < 5; columnas++)
                    {
                        cout << "[" << barajaVacia[filas][columnas].num << barajaVacia[filas][columnas].pal << "] ";
                    }
                    cout << endl;
                }
                cout << endl;
                cout << "MA DE CARTES:" << endl;

                for (int i = 0; i < 4; i++)
                {
                    cout << "[" << perJugar[i].num << perJugar[i].pal << "] ";
                }

                cout << endl;
                cout << "CARTES ELIMINATORIES:" << endl;
                for (int i = 0; i < 4; i++)
                {
                    cout << "[" << cartesEliminatories[i].num << cartesEliminatories[i].pal << "] ";
                }
                i1 = 1;
                perdut = 0;

                for (int filas = 0; filas < 4; filas++)
                {
                    for (int columnas = 0; columnas < 5; columnas++)
                    {
                        if (filas == 0)
                        {
                            if (barajaVacia[filas][columnas].num != i1 || barajaVacia[filas][columnas].pal != 'A')
                            {

                                perdut = 1;
                            }
                        }
                        if (filas == 1)
                        {
                            if (barajaVacia[filas][columnas].num != i1 || barajaVacia[filas][columnas].pal != 'B')
                            {

                                perdut = 1;
                            }
                        }
                        if (filas == 2)
                        {
                            if (barajaVacia[filas][columnas].num != i1 || barajaVacia[filas][columnas].pal != 'C')
                            {

                                perdut = 1;
                            }
                        }
                        if (filas == 3)
                        {
                            if (barajaVacia[filas][columnas].num != i1 || barajaVacia[filas][columnas].pal != 'D')
                            {

                                perdut = 1;
                            }
                        }
                        i1++;
                    }
                    i1 = 1;
                }
                if (perdut == 1)
                {
                    cout << endl;
                    colocar = 'n';
                    cout << "HAS PERDUT!" << endl;
                    cout << "Vols tornar a jugar?" << endl;
                    cin >> tornarJugar;
                    partidesJugades++;
                }
                if (perdut != 1)
                {
                    cout << endl;
                    colocar = 'n';
                    cout << "ENHORABONA, HAS GUANYAT" << endl;
                    cout << "Vols tornar a jugar?" << endl;
                    cin >> tornarJugar;
                    partidesJugades++;
                }
            }
        }
    } while (tornarJugar == 's' || tornarJugar == 'S');
}