#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i, j;

int nose(int arr_length, int array[], int comparing) {
  int count = 0;
  for ( i = 0; i < arr_length; i++) {
    if(comparing != array[i]) count++;
    if(count == arr_length) {
    return 1;
  }
}
return 0;
}




int main() {
  int codigo_medicamento[10] = {160, 130, 180, 110, 150, 140 ,100, 170, 120, 190};
  float precio_por_envase[10] = {49.99, 62.90, 58.90, 36.00, 67.95, 59.21, 76.20, 101.35, 20.36, 45.60};
  int asignados[7][10][1];

  for (i = 0; i < 10; i++) {
    for ( j = 0; j < 10; j++) {
      if(codigo_medicamento[i] > codigo_medicamento[i++]) {
        int temp = codigo_medicamento[i];
        codigo_medicamento[i] = codigo_medicamento[i++];
        codigo_medicamento[i++] = temp;
      }
    }
  }

  printf("Numero de farmacia:\n");
  printf("Farmacia Casa nova: 0\n");
  printf("farmacia independiente: 1\n");
  printf("farmacia gui: 2\n");
  printf("farmacia popo: 3\n");
  printf("farmacia benedetto: 4\n");
  printf("farmacia corpus: 5\n");
  printf("farmacia aguinaldo: 6\n");

  printf("\n");

  while(1) {
    int cod_temp, cant_temp, farm_temp;
    error:
    printf("Ingrese el codigo del medicamento, la cantidad de envases del mismo y el numero de la farmacia a la que se asigna. Si no desea ingresar nada mas, ingrese un 0.\n");
    scanf("%d %d %d", &cod_temp, &cant_temp, &farm_temp);
    if(cod_temp == 0) break;

    if(nose(10, codigo_medicamento, cod_temp)) {
      printf("medicamento inexistente.\n");
      goto error;
    }

    if(farm_temp > 7) {
      printf("farmacia inexistente.\n");
      goto error;
    }

    asignados[farm_temp][cod_temp][0] += cant_temp;


  }
  int cantidadtotal[10] = {0,0,0,0,0,0,0,0,0,0};

  for (  i = 0; i < 10; i++) {
    for ( j = 0; j < 10; j++) {
      if(asignados[i][j] == codigo_medicamento[j]) cantidadtotal[j] += asignados[i][j][0];
    }
  }
  for (  i = 0; i < 10; i++) {
    printf("%d ", cantidadtotal[i]);
  }


  return 0;
}
