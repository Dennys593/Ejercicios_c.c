#include <stdio.h>

int main (int argc, char *argv[]) {

    float cal[5][3][3] = {0};
    char nombres[5][20];
    char asignaturas[3][20] = {"Fisica",
                               "Quimica",
                               "Calculo"};
    int opc = 0, opc2= 0;
    int contaE = 0; 
    int selE = 0;
    float prom[5][3] = {0};
    
    do
    {
        printf("    Seleccione una opcion    \n");
        printf("1. Registro de estudiantes\n");
        printf("2. Registrar calificaciones\n");
        printf("3. Promedio por estudinte\n");
        printf("4. Promedio por asignatura\n");
        printf("5. Calificacion mas alta y baja por estudinte\n");
        printf("6. Calificacion mas alta y baja por asignatura\n");
        printf("7. Estudiantes aprobados y reprobados por asignatura\n");
        printf(">> ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:

            if (contaE < 5)
            {
                printf("registre el nombre del estuadintes %d: ", contaE+1);
                getchar();
                fgets(nombres[contaE],20,stdin);
                contaE++;
            }
            else
            {
                printf("Ya se registraron los 5 estudiantes\n");
            }
            break;

        case 2:
            
            if (contaE == 0)
            {
                printf("Primero registre estudiantes\n");
                break;
            }

            printf("Seleccione el estudiante al que desea registrar las calificaciones:\n");
            
            for (int i = 0; i < contaE; i++)
            {
                printf("%d. %s", i, nombres[i]);
            }

            scanf("%d", &selE);

            if (selE < 0 || selE >= contaE)
            {
                printf("Estudiante no valido\n");
                break;
            }

            printf("Ingrese las calificaciones del estudinte %s", nombres[selE]);

            for (int i = 0; i < 3; i++)
            {
                prom[selE][i] = 0;
                printf("%s\n", asignaturas[i]);

                for (int j = 0; j < 3; j++)
                {
                    do
                    {
                        printf("Nota %d: ", j+1);
                        scanf("%f", &cal[selE][i][j]);

                        if (cal[selE][i][j] < 0 || cal[selE][i][j] > 10)
                        {
                            printf("Numero incorrecto. Debe ser de 0 a 10\n");
                        }

                    } while (cal[selE][i][j] < 0 || cal[selE][i][j] > 10);

                    prom[selE][i] += cal[selE][i][j];
                }

                prom[selE][i] /= 3;
            }
            
            break;

        case 3:
        {
            float auxProm = 0;
            printf("Promedios por alumno\n");
            printf("%s\t\t%s\t\t%s\t\tpromedio\t\tNombre\n",asignaturas[0],
                                                            asignaturas[1],
                                                            asignaturas[2]);

            for (int i = 0; i < contaE; i++)
            {
                auxProm = (prom[i][0] + prom[i][1] + prom[i][2])/3;
                printf("%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%s\n",prom[i][0],
                                                           prom[i][1],
                                                           prom[i][2],
                                                           auxProm,
                                                           nombres[i]);
            }

            break;
        }

        case 4:
        {
            float auxAsig = 0;
            printf("Promedio por asignatura\n");

            for (int i = 0; i < 3; i++)
            {
                auxAsig = 0;

                for (int j = 0; j < contaE; j++)
                {
                    auxAsig += prom[j][i];
                }

                if (contaE > 0)
                {
                    auxAsig /= contaE;
                }

                printf("%s: %.2f\n", asignaturas[i], auxAsig);
            }

            break;
        }

        case 5:
        {
            float mayor = 0, menor = 0;

            printf("Calificacion mas alta y baja por estudinte\n");

            for (int i = 0; i < contaE; i++)
            {
                mayor = prom[i][0];
                menor = prom[i][0];

                for (int j = 1; j < 3; j++)
                {
                    if (prom[i][j] > mayor)
                    {
                        mayor = prom[i][j];
                    }

                    if (prom[i][j] < menor)
                    {
                        menor = prom[i][j];
                    }
                }

                printf("%sMayor: %.2f | Menor: %.2f\n", nombres[i], mayor, menor);
            }

            break;
        }

        case 6:
        {
            float mayor = 0, menor = 0;

            printf("Calificacion mas alta y baja por asignatura\n");

            for (int i = 0; i < 3; i++)
            {
                if (contaE > 0)
                {
                    mayor = prom[0][i];
                    menor = prom[0][i];

                    for (int j = 1; j < contaE; j++)
                    {
                        if (prom[j][i] > mayor)
                        {
                            mayor = prom[j][i];
                        }

                        if (prom[j][i] < menor)
                        {
                            menor = prom[j][i];
                        }
                    }

                    printf("%s  Mayor: %.2f | Menor: %.2f\n", asignaturas[i], mayor, menor);
                }
            }

            break;
        }

        case 7:
        {
            int aprobados = 0, reprobados = 0;

            printf("Estudiantes aprobados y reprobados por asignatura\n");

            for (int i = 0; i < 3; i++)
            {
                aprobados = 0;
                reprobados = 0;

                for (int j = 0; j < contaE; j++)
                {
                    if (prom[j][i] >= 6)
                    {
                        aprobados++;
                    }
                    else
                    {
                        reprobados++;
                    }
                }

                printf("%s  Aprobados: %d | Reprobados: %d\n", asignaturas[i], aprobados, reprobados);
            }

            break;
        }

        default:
            printf("Opcion no valida\n");
            break;
        }

        printf("Deseas continuar con el programa? 1.Si 2.No\n>> ");
        scanf("%d", &opc2);

    } while (opc2 == 1);
        
    return 0;
}