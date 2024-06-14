#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
 //MAQUINA DISPENSADORA DE ARTICULOS DEPORTIVOS
int ren=4;
int col=3;

void llenar_precios(int precio[ren][col]){ //Procedimiento para llenar el precio de cada uno de los productos dela maquina
    precio[0][0]=15; //Posicion del producto dentro de lamatriz y el precio desigando a esa locacion
    precio[0][1]=10; //Posicion del producto dentro de lamatriz y el precio desigando a esa locacion
    precio[0][2]=30; //Posicion del producto dentro de lamatriz y el precio desigando a esa locacion
    precio[1][0]=10; //Posicion del producto dentro de lamatriz y el precio desigando a esa locacion
    precio[1][1]=20; //Posicion del producto dentro de lamatriz y el precio desigando a esa locacion
    precio[1][2]=40; //Posicion del producto dentro de lamatriz y el precio desigando a esa locacion
    precio[2][0]=30; //Posicion del producto dentro de lamatriz y el precio desigando a esa locacion
    precio[2][1]=20; //Posicion del producto dentro de lamatriz y el precio desigando a esa locacion
    precio[2][2]=40; //Posicion del producto dentro de lamatriz y el precio desigando a esa locacion
    precio[3][0]=50; //Posicion del producto dentro de lamatriz y el precio desigando a esa locacion
    precio[3][1]=50; //Posicion del producto dentro de lamatriz y el precio desigando a esa locacion
    precio[3][2]=30; //Posicion del producto dentro de lamatriz y el precio desigando a esa locacion
}

void llenar_cantidad(int cantidad[ren][col]){ //Procedimiento para asignar valor a cada localidad de la matriz cvon la cantidad de productos
    int i,j; //Variables para mover la localidad de la matriz
    for(i=0;i<ren;i++){ //Ciclo para mover los renglones de la matriz
        for(j=0;j<col;j++){ //Ciclo para mover las columnas de la matriz
            cantidad[i][j]=rand()%9+2; //Asignacion de un numero aleatoria para la cantidad de cada producto.
        }
    }
}

void imprimir_maquina(int precios[ren][col],int cantidad[ren][col]){ //Procedimiento para imprimir numero de producto, precio y cantidad
    int i,j,k=1;  //Variables para mover la localidad de la matriz
    printf("    Producto Cantidad Precio\n"); //Titulo
    for(i=0;i<ren;i++){ //Ciclo para mover los renglones de la matriz
        for(j=0;j<col;j++){ //Ciclo para mover las columnas de la matriz
            printf("\t%i",k); //Impresion del numero de producto
            printf("\t%i",cantidad[i][j]); //Impresion de la cantidad de articulos que hay
            printf("\t$ %i\n",precios[i][j]); //Impresion del precio de cada producto
            k++;
        }
    }
}

int cambios(int precios[ren][col],int dinero,int i,int j){ //Funcion pára regresar cambio al momento de ingresar el dinero en la maquina
    int cambio, precio; //Variables
    precio=precios[i][j]; //Asignar valor a una de las variables, este valor depende del producto se que haya escogido
    cambio=dinero-precio; //Calculo para sacar cambio o en dado caso verificar que se pueda comprar el producto con el dinero metido a la maquina
    return cambio; //regresar cambio
}

void menu(){ //Menu principal
    printf("\n\t\t MENU\n");
    printf("\t 1. Maquina Dispensadora para Deportistas\n");
    printf("\t 2. Archivo Final del Dia\n");
    printf("\t 3. Siguiente Dia\n");
    printf("\t 4. Ganancias totales\n");
    printf("\t 0. SALIR(y rellenar maquina)\n\n\t");
}

void productos(){ //Menu de los productos de la maquina dispensadora
    printf("\n\t\t Escoja Producto: \n");
    printf("\t\t 1. Botella de Suero\n");
    printf("\t\t 2. Toalla\n");
    printf("\t\t 3. Rodilleras\n");
    printf("\t\t 4. Cinta\n");
    printf("\t\t 5. Guantes\n");
    printf("\t\t 6. Gorra\n");
    printf("\t\t 7. Bloqueador\n");
    printf("\t\t 8. Ligas\n");
    printf("\t\t 9. Cronometro\n");
    printf("\t\t 10. Pulsera de ritmo cardiaco\n");
    printf("\t\t 11. Lentes obscuros\n");
    printf("\t\t 12. Banditas\n");
    printf("\t\t 0. SALIR\n\t");
}

void main(){ //pROCEDIMIENTO PRINCIPAL (MENU PRINCIPAL)
    int opcion,producto,cambio,decision,dinero,GANANCIAS=0,GANANCIAS_TOTALES=0; //Variables para regresar valores o guardar valores
    int precios[ren][col],cantidad[ren][col],i,j,k=1,l=1; //Variables de las matrices y contadores para mover la localidad de la matriz
    llenar_cantidad(cantidad); //Llenar las cantidades de los productos
    llenar_precios(precios); //Asignar precios establecidos a los productos
    srand(time(NULL)); //Condicion para sacar numeros aleatorios
    char documentacion[10000]; //Cadena de caracteres para el archivo
    FILE*apuntador; //Inicializar apuntador para crear el archivo
    apuntador=fopen("documentacion.txt","w"); //Crear archivo nuevo para escribir
    if(apuntador!=NULL){ //Condicion, si le archivo se puede abrir entonces que ejecute todo lo de adentro
            fputs(" REGISTRO DE VENTAS Y GANANCIAS (INICIO Y FINAL DEL DIA)\n",apuntador); //Registrar en el archivo creado todos los productos de la maquina
            fputs("\t Productos a vender:\n",apuntador);
            fputs("  1. Botella de Suero",apuntador);
            fputs("\t 2. Toalla\n",apuntador);
            fputs("  3. Rodilleras",apuntador);
            fputs("\t\t 4. Cinta\n",apuntador);
            fputs("  5. Guantes",apuntador);
            fputs("\t\t 6. Gorra\n",apuntador);
            fputs("  7. Bloqueador",apuntador);
            fputs("\t\t 8. Ligas\n",apuntador);
            fputs("  9. Cronometro",apuntador);
            fputs("\t\t 10. Pulsera de ritmo cardiaco\n",apuntador);
            fputs("  11. Lentes obscuros",apuntador);
            fputs("\t 12. Banditas\n\n",apuntador);
            fprintf(apuntador,"\t\t INICIO DEL DIA %i\n",l); //Registro de los prodcutos del inicio del dia
            fputs("   Producto    Precio  Cantidad inicial\n",apuntador);
            for(i=0;i<ren;i++){ //Ciclo para mover los renglones de la matriz
                for(j=0;j<col;j++){ //Ciclo para mover las clumnas de la matriz
                    fprintf(apuntador,"\t%i",k); //Registrar numero de articulo, precio y la cantidad que hay
                    fprintf(apuntador,"\t$ %i",precios[i][j]);
                    fprintf(apuntador,"\t  %i",cantidad[i][j]);
                    fputc('\n',apuntador);
                    k++;
                }
            }
        fclose(apuntador); //Cerrar arcchivo
    }
    else printf("\t Error en el archivo"); //sino marcar error
    do{ //Condicion mientas no sea salir,seguir enseñando menu
        menu(); //Enseñar menu principal
        scanf("%i%*c",&opcion); //Escaneo de opcion
        switch(opcion){
        case 1: //OPCION DE MAQUINA DISPENSADORA
            do{ //Condicion para hacerlo mientas la opcion no sea SALIR
                productos(); //Menu de productos de la maquina
                imprimir_maquina(precios,cantidad); //Imprimir producto, precio y cantidad inicial
                scanf("%i%*c",&producto);
                switch(producto){ //Seleccion de producto
                case 1: //Producto, precio, opcion para comprar el producto, devolucion de cambio y en dado caso mensaje de saldo insuficiente, contador para saber si todavia hay producto
                    if(cantidad[0][0]>0){ //Si hay producto entonces se puede comprar sino, escoja otro producto
                        printf("\t Articulo: Botella de suero");
                        printf("\t Precio: %i",precios[0][0]);
                        printf("\t Cancelar = 0 OK = 1\n\t");
                        scanf("%i%*c",&decision);
                        if(decision==1){
                            printf("\t Ingrese dinero: ");
                            scanf("%i%*c",&dinero);
                            cambio=cambios(precios,dinero,0,0);
                        }
                        if(cambio<0){
                            printf("\n\t Saldo insuficiente\n");
                        } else printf("\t Tu cambio: %i\n",cambio);
                        GANANCIAS=GANANCIAS+precios[0][0];
                        cantidad[0][0]=cantidad[0][0]-1;
                    }else printf("\t Ya no hay articulo, intente otro\n");
                    break;
                case 2: //Producto, precio, opcion para comprar el producto, devolucion de cambio y en dado caso mensaje de saldo insuficiente, contador para saber si todavia hay producto
                    if(cantidad[0][1]>0){ //Si hay producto entonces se puede comprar sino, escoja otro producto
                        printf("\t Articulo: Toalla");
                        printf("\t Precio: %i",precios[0][1]);
                        printf("\t Cancelar = 0 OK = 1\n\t");
                        scanf("%i%*c",&decision);
                        if(decision==1){
                            printf("\t Ingrese dinero: ");
                            scanf("%i%*c",&dinero);
                            cambio=cambios(precios,dinero,0,1);
                        }
                        if(cambio<0){
                            printf("\n\t Saldo insuficiente\n");
                        } else printf("\t Tu cambio: %i\n",cambio);
                        GANANCIAS=GANANCIAS+precios[0][1];
                        cantidad[0][1]=cantidad[0][1]-1;
                    }else printf("\t Ya no hay articulo, intente otro\n");
                    break;
                case 3: //Producto, precio, opcion para comprar el producto, devolucion de cambio y en dado caso mensaje de saldo insuficiente, contador para saber si todavia hay producto
                    if(cantidad[0][2]>0){ //Si hay producto entonces se puede comprar sino, escoja otro producto
                        printf("\t Articulo: Rodilleras");
                        printf("\t Precio: %i",precios[0][2]);
                        printf("\t Cancelar = 0 OK = 1\n\t");
                        scanf("%i%*c",&decision);
                        if(decision==1){
                            printf("\t Ingrese dinero: ");
                            scanf("%i%*c",&dinero);
                            cambio=cambios(precios,dinero,0,2);
                        }
                        if(cambio<0){
                            printf("\n\t Saldo insuficiente\n");
                        } else printf("\t Tu cambio: %i\n",cambio);
                        GANANCIAS=GANANCIAS+precios[0][2];
                        cantidad[0][2]=cantidad[0][2]-1;
                    }else printf("\t Ya no hay articulo, intente otro\n");
                    break;
                case 4: //Producto, precio, opcion para comprar el producto, devolucion de cambio y en dado caso mensaje de saldo insuficiente, contador para saber si todavia hay producto
                    if(cantidad[1][0]>0){ //Si hay producto entonces se puede comprar sino, escoja otro producto
                        printf("\t Articulo: Cinta");
                        printf("\t Precio: %i",precios[1][0]);
                        printf("\t Cancelar = 0 OK = 1\n\t");
                        scanf("%i%*c",&decision);
                        if(decision==1){
                            printf("\t Ingrese dinero: ");
                            scanf("%i%*c",&dinero);
                            cambio=cambios(precios,dinero,1,0);
                        }
                        if(cambio<0){
                            printf("\n\t Saldo insuficiente\n");
                        } else printf("\t Tu cambio: %i\n",cambio);
                        GANANCIAS=GANANCIAS+precios[1][0];
                        cantidad[1][0]=cantidad[1][0]-1;
                    }else printf("\t Ya no hay articulo, intente otro\n");
                    break;
                case 5: //Producto, precio, opcion para comprar el producto, devolucion de cambio y en dado caso mensaje de saldo insuficiente, contador para saber si todavia hay producto
                    if(cantidad[1][1]>0){ //Si hay producto entonces se puede comprar sino, escoja otro producto
                        printf("\t Articulo: Guantes");
                        printf("\t Precio: %i",precios[1][1]);
                        printf("\t Cancelar = 0 OK = 1\n\t");
                        scanf("%i%*c",&decision);
                        if(decision==1){
                            printf("\t Ingrese dinero: ");
                            scanf("%i%*c",&dinero);
                            cambio=cambios(precios,dinero,1,1);
                        }
                        if(cambio<0){
                            printf("\n\t Saldo insuficiente\n");
                        } else printf("\t Tu cambio: %i\n",cambio);
                        GANANCIAS=GANANCIAS+precios[1][1];
                        cantidad[1][1]=cantidad[1][1]-1;
                    }else printf("\t Ya no hay articulo, intente otro\n");
                    break;
                case 6: //Producto, precio, opcion para comprar el producto, devolucion de cambio y en dado caso mensaje de saldo insuficiente, contador para saber si todavia hay producto
                    if(cantidad[1][2]>0){ //Si hay producto entonces se puede comprar sino, escoja otro producto
                        printf("\t Articulo: Gorras");
                        printf("\t Precio: %i",precios[1][2]);
                        printf("\t Cancelar = 0 OK = 1\n\t");
                        scanf("%i%*c",&decision);
                        if(decision==1){
                            printf("\t Ingrese dinero: ");
                            scanf("%i%*c",&dinero);
                            cambio=cambios(precios,dinero,1,2);
                        }
                        if(cambio<0){
                            printf("\n\t Saldo insuficiente\n");
                        } else printf("\t Tu cambio: %i\n",cambio);
                        GANANCIAS=GANANCIAS+precios[1][2];
                        cantidad[1][2]=cantidad[1][2]-1;
                    }else printf("\t Ya no hay articulo, intente otro\n");
                    break;
                case 7: //Producto, precio, opcion para comprar el producto, devolucion de cambio y en dado caso mensaje de saldo insuficiente, contador para saber si todavia hay producto
                    if(cantidad[2][0]>0){ //Si hay producto entonces se puede comprar sino, escoja otro producto
                        printf("\t Articulo: Botella de bloqueador");
                        printf("\t Precio: %i",precios[2][0]);
                        printf("\t Cancelar = 0 OK = 1\n\t");
                        scanf("%i%*c",&decision);
                        if(decision==1){
                            printf("\t Ingrese dinero: ");
                            scanf("%i%*c",&dinero);
                            cambio=cambios(precios,dinero,2,0);
                        }
                        if(cambio<0){
                            printf("\n\t Saldo insuficiente\n");
                        } else printf("\t Tu cambio: %i\n",cambio);
                        GANANCIAS=GANANCIAS+precios[2][0];
                        cantidad[2][0]=cantidad[2][0]-1;
                    }else printf("\t Ya no hay articulo, intente otro\n");
                    break;
                case 8: //Producto, precio, opcion para comprar el producto, devolucion de cambio y en dado caso mensaje de saldo insuficiente, contador para saber si todavia hay producto
                    if(cantidad[2][1]>0){ //Si hay producto entonces se puede comprar sino, escoja otro producto
                        printf("\t Articulo: Ligas");
                        printf("\t Precio: %i",precios[2][1]);
                        printf("\t Cancelar = 0 OK = 1\n\t");
                        scanf("%i%*c",&decision);
                        if(decision==1){
                            printf("\t Ingrese dinero: ");
                            scanf("%i%*c",&dinero);
                            cambio=cambios(precios,dinero,2,1);
                        }
                        if(cambio<0){
                            printf("\n\t Saldo insuficiente\n");
                        } else printf("\t Tu cambio: %i\n",cambio);
                        GANANCIAS=GANANCIAS+precios[2][1];
                        cantidad[2][1]=cantidad[2][1]-1;
                    }else printf("\t Ya no hay articulo, intente otro\n");
                    break;
                case 9: //Producto, precio, opcion para comprar el producto, devolucion de cambio y en dado caso mensaje de saldo insuficiente, contador para saber si todavia hay producto
                    if(cantidad[2][2]>0){ //Si hay producto entonces se puede comprar sino, escoja otro producto
                        printf("\t Articulo: Cronometro");
                        printf("\t Precio: %i",precios[2][2]);
                        printf("\t Cancelar = 0 OK = 1\n\t");
                        scanf("%i%*c",&decision);
                        if(decision==1){
                            printf("\t Ingrese dinero: ");
                            scanf("%i%*c",&dinero);
                            cambio=cambios(precios,dinero,2,2);
                        }
                        if(cambio<0){
                            printf("\n\t Saldo insuficiente\n");
                        } else printf("\t Tu cambio: %i\n",cambio);
                        GANANCIAS=GANANCIAS+precios[2][2];
                        cantidad[2][2]=cantidad[2][2]-1;
                    }else printf("\t Ya no hay articulo, intente otro\n");
                    break;
                case 10: //Producto, precio, opcion para comprar el producto, devolucion de cambio y en dado caso mensaje de saldo insuficiente, contador para saber si todavia hay producto
                    if(cantidad[3][0]>0){ //Si hay producto entonces se puede comprar sino, escoja otro producto
                        printf("\t Articulo: Pulsera de ritmo cardiaco");
                        printf("\t Precio: %i",precios[3][0]);
                        printf("\t Cancelar = 0 OK = 1\n\t");
                        scanf("%i%*c",&decision);
                        if(decision==1){
                            printf("\t Ingrese dinero: ");
                            scanf("%i%*c",&dinero);
                            cambio=cambios(precios,dinero,3,0);
                        }
                        if(cambio<0){
                            printf("\n\t Saldo insuficiente\n");
                        } else printf("\t Tu cambio: %i\n",cambio);
                        GANANCIAS=GANANCIAS+precios[3][0];
                        cantidad[3][0]=cantidad[3][0]-1;
                    }else printf("\t Ya no hay articulo, intente otro\n");
                    break;
                case 11: //Producto, precio, opcion para comprar el producto, devolucion de cambio y en dado caso mensaje de saldo insuficiente, contador para saber si todavia hay producto
                    if(cantidad[3][1]>0){ //Si hay producto entonces se puede comprar sino, escoja otro producto
                        printf("\t Articulo: Lentes obscuros");
                        printf("\t Precio: %i",precios[3][1]);
                        printf("\t Cancelar = 0 OK = 1\n\t");
                        scanf("%i%*c",&decision);
                        if(decision==1){
                            printf("\t Ingrese dinero: ");
                            scanf("%i%*c",&dinero);
                            cambio=cambios(precios,dinero,3,1);
                        }
                        if(cambio<0){
                            printf("\n\t Saldo insuficiente\n");
                        } else printf("\t Tu cambio: %i\n",cambio);
                        GANANCIAS=GANANCIAS+precios[3][1];
                        cantidad[3][1]=cantidad[3][1]-1;
                    }else printf("\t Ya no hay articulo, intente otro\n");
                    break;
                case 12: //Producto, precio, opcion para comprar el producto, devolucion de cambio y en dado caso mensaje de saldo insuficiente, contador para saber si todavia hay producto
                    if(cantidad[3][2]>0){ //Si hay producto entonces se puede comprar sino, escoja otro producto
                        printf("\t Articulo: Banditas");
                        printf("\t Precio: %i",precios[3][2]);
                        printf("\t Cancelar = 0 OK = 1\n\t");
                        scanf("%i%*c",&decision);
                        if(decision==1){
                            printf("\t Ingrese dinero: ");
                            scanf("%i%*c",&dinero);
                            cambio=cambios(precios,dinero,3,2);
                        }
                        if(cambio<0){
                            printf("\n\t Saldo insuficiente\n");
                        } else printf("\t Tu cambio: %i\n",cambio);
                        GANANCIAS=GANANCIAS+precios[3][2];
                        cantidad[3][2]=cantidad[3][2]-1;
                    }else printf("\t Ya no hay articulo, intente otro\n");
                    break;
                case 0: //Salir de la maquina
                    printf("\t Salir de la maquina");
                    break;
                default: //Opcion no existente
                    printf("\t Opcion NO existente, intente otra opcion");
                }
            }while(producto!=0);
            break;
        case 2:
            k=1;
            apuntador=fopen("documentacion.txt","a"); //Abrir archivo para reescribir en el
            if(apuntador!=NULL){
                fputs("\n\t\t FINAL DEL DIA\n",apuntador); //Registro del final del dia
                fputs("   Producto    Precio  Cantidad inicial\n",apuntador);
                for(i=0;i<ren;i++){
                    for(j=0;j<col;j++){
                        fprintf(apuntador,"\t%i",k);
                        fprintf(apuntador,"\t$ %i",precios[i][j]);
                        fprintf(apuntador,"\t  %i",cantidad[i][j]);
                        fputc('\n',apuntador);
                        k++;
                    }
                }
            fprintf(apuntador,"\t GANANCIAS DEL DIA: %i",GANANCIAS);
            GANANCIAS_TOTALES=GANANCIAS_TOTALES+GANANCIAS;
            GANANCIAS=0;
            fclose(apuntador);
            }
            else printf("\t Error en el archivo");
            break;
        case 3:
            printf("\n\t Registro de siguiente dia guardado\n"); //Registro inicial del dia siguiente
            k=1;
            l++;
            apuntador=fopen("documentacion.txt","a"); //Abrir archivo para reescribir en el
            if(apuntador!=NULL){
                fprintf(apuntador,"\n\t\t INICIO DEL DIA %i\n",l);
                fputs("   Producto    Precio  Cantidad inicial\n",apuntador);
                for(i=0;i<ren;i++){
                    for(j=0;j<col;j++){
                        fprintf(apuntador,"\t%i",k);
                        fprintf(apuntador,"\t$ %i",precios[i][j]);
                        fprintf(apuntador,"\t  %i",cantidad[i][j]);
                        fputc('\n',apuntador);
                        k++;
                    }
                }
            }else printf("\t Error en el archivo");
            break;
        case 4:
            printf("\t GANANCIAS TOTALES: %i",GANANCIAS_TOTALES); //REgistro de ganancias totales
            apuntador=fopen("documentacion.txt","a");
            if(apuntador!=NULL){ //REgistardas en el archivo
                fputs("\t GANANCIAS TOTALES:",apuntador);
                fprintf(apuntador,"\t$ %i",GANANCIAS_TOTALES);
            }else printf("\t Error en el archivo");
            break;
        case 0: //Opcion de salir del programa
            printf("\t SALIR del programa");
            break;
        default:
            printf("\t Opcion NO existente"); //Opcion no existente
        }
    }while(opcion!=0);
}

