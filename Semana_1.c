#include <stdio.h>
#include <string.h>

int main() {
    int id, stock = 0, opcion;
    char nombre[50];
    float precio = 0, ganancias = 0, descuento, prefinal;
    int cantidad, len;

    do {
        printf("\n       MENU      \n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer stock\n");
        printf("4. Mostrar informacion\n");
        printf("5. Mostrar ganancias\n");
        printf("6. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {

            case 1:

                do {
                    printf("ID del producto: ");
                    scanf("%d", &id);

                    if(id <= 0) {
                        printf("ID invalido\n");
                    }
                } while(id <= 0);

                printf("Nombre del producto: ");
                getchar();
                fgets(nombre, 20, stdin);
                len = strlen(nombre) - 1;
                nombre[len] = '\0';

                do {
                    printf("Stock del producto: ");
                    scanf("%d", &stock);

                    if(stock < 0) {
                        printf("Stock invalido\n");
                    }
                } while(stock < 0);

                do {
                    printf("Precio del producto: ");
                    scanf("%f", &precio);

                    if(precio <= 0) {
                        printf("Precio invalido\n");
                    }
                } while(precio <= 0);

                printf("Producto registrado correctamente\n");
                break;

            case 2:

                do {
                    printf("Cantidad a vender: ");
                    scanf("%d", &cantidad);

                    if(cantidad <= 0) {
                        printf("Cantidad invalida\n");
                    } else if(cantidad > stock) {
                        printf("No hay suficiente stock\n");
                    }

                } while(cantidad <= 0 || cantidad > stock);

                do {
                    printf("Ingrese un descuento (0 a 100): ");
                    scanf("%f", &descuento);

                    if (descuento < 0 || descuento > 100){
                        printf("Descuento Invalido\n");
                    }
                }while (descuento < 0 || descuento > 100);

                prefinal = precio - (precio * descuento/100);

                stock = stock - cantidad;
                ganancias += cantidad * prefinal;
                printf("Venta realizada\n");
                printf("Precio con descuento: %.2f\n", prefinal);
                break;

            case 3:

                do {
                    printf("Cantidad a agregar: ");
                    scanf("%d", &cantidad);

                    if(cantidad <= 0) {
                        printf("Cantidad invalida\n");
                    }

                } while(cantidad <= 0);

                stock = stock + cantidad;
                printf("Stock actualizado\n");
                break;

            case 4:

                printf("\n    PRODUCTO    \n");
                printf("ID: %d\n", id);
                printf("Nombre: %s\n", nombre);
                printf("Stock: %d\n", stock);
                printf("Precio: %.2f\n", precio);
                break;

            case 5:

                printf("Ganancias: %.2f\n", ganancias);
                break;

            case 6:

                printf("Salio correctamente\n");
                break;

            default:
                printf("Opcion invalida\n");
        }

    } while(opcion != 6);

    return 0;
}