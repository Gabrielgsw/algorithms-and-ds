#include <stdio.h>
#include <stdlib.h>

// Discente: Gabriel Germano dos Santos Wanderley

// Definindo as estruturas

typedef struct No {
    int peso;
} No;

typedef struct Grafo {
    int vertices;
    int *grau;
    int **pesos;
    int **arestas;
    No **matrizConect;
} Grafo;

// Método para encontrar a menor distância entre 2 vértices
int procuraMenorDistancia(int *dist, int *visitado, int NV) {
    int i, menor = -1, primeiro = 1;
    for (i = 0; i < NV; i++) {
        if (dist[i] >= 0 && visitado[i] == 0) {
            if (primeiro) {
                menor = i;
                primeiro = 0;
            } else {
                if (dist[menor] > dist[i])
                    menor = i;
            }
        }
    }
    return menor;
}

// implementação do algoritmo
void dijkstra(Grafo *grafo, int *ant, int *dist) {
    //Supondo que o vértice de índicie 0 será o inicial
    int inicial = 0;
    int i, cont, NV, ind, *visitado, vert;
    NV = grafo->vertices;
    cont = NV;
    visitado = (int *)malloc(NV * sizeof(int));
    for (i = 0; i < NV; i++) {
        ant[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }
    dist[inicial] = 0;
    while (cont > 0) {
        vert = procuraMenorDistancia(dist, visitado, NV);
        if (vert == -1)
            break;

        visitado[vert] = 1;
        cont--;
        for (i = 0; i < grafo->grau[vert]; i++) {
            ind = grafo->arestas[vert][i];
            if (dist[ind] < 0) {
                dist[ind] = dist[vert] + grafo->pesos[vert][i];
                ant[ind] = vert;
            } else {
                if (dist[ind] > dist[vert] + grafo->pesos[vert][i]) {
                    dist[ind] = dist[vert] + grafo->pesos[vert][i];
                    ant[ind] = vert;
                }
            }
        }
    }

    free(visitado);
}

int criarAresta(Grafo *grafo, int orig, int dest, int peso) {
    if (grafo == NULL)
        return 0;
    if (orig < 0 || orig >= grafo->vertices)
        return 0;
    if (dest < 0 || dest >= grafo->vertices)
        return 0;

    grafo->arestas[orig][grafo->grau[orig]] = dest;
    grafo->pesos[orig][grafo->grau[orig]] = peso;
    grafo->grau[orig]++;

    return 1;
}

int main() {
      // Alocando memória
    Grafo *grafo = malloc(sizeof(Grafo));
    grafo->matrizConect = malloc(6 * sizeof(No *));
    grafo->arestas = malloc(6 * sizeof(int *));
    grafo->grau = malloc(6 * sizeof(int));
    grafo->pesos = malloc(6 * sizeof(int *));

    for (int i = 0; i < 6; i++) {
        grafo->arestas[i] = malloc(6 * sizeof(int));
        grafo->matrizConect[i] = malloc(6 * sizeof(No));
        grafo->pesos[i] = malloc(6 * sizeof(int));
        grafo->grau[i] = 0;
    }

    // Definindo a quantidade de vértices passada no txt
    grafo->vertices = 6;


    FILE *arquivo;
    arquivo = fopen("L5Q2_in.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    // Leitura dos dados do arquivo e preenchimento da matriz de conexões
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            fscanf(arquivo, "%d", &grafo->matrizConect[i][j].peso);
            printf("%d ", grafo->matrizConect[i][j].peso);
        }
        printf("\n");
    }
    // Preenchendo arestas de acordo com a matriz de conectividades de entrada
    criarAresta(grafo, 0, 1,grafo->matrizConect[0][1].peso );
    criarAresta(grafo, 0, 2, grafo->matrizConect[0][2].peso);
    criarAresta(grafo, 1, 4, grafo->matrizConect[1][4].peso);
    criarAresta(grafo, 2, 3, grafo->matrizConect[2][3].peso);
    criarAresta(grafo, 3, 5, grafo->matrizConect[3][5].peso);
    criarAresta(grafo, 4, 5, grafo->matrizConect[4][5].peso);

    int anterior[grafo->vertices];
    int peso[grafo->vertices];
    dijkstra(grafo, anterior, peso);

    for (int i = 0; i < grafo->vertices; i++) {
        printf("Iteração: %d: Vértice anterior: %d -> Peso: %d\n", i, anterior[i], peso[i]);
    }

    // Libere a memória alocada
    for (int i = 0; i < 6; i++) {
        free(grafo->arestas[i]);
        free(grafo->matrizConect[i]);
        free(grafo->pesos[i]);
    }
    free(grafo->arestas);
    free(grafo->matrizConect);
    free(grafo->pesos);
    free(grafo->grau);
    free(grafo);

    return 0;
}
