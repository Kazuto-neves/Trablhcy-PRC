#ifndef _Brinquedo_H_
#define _Brinquedo_H_

typedef struct{
    int codigo,qtd;
    char nome[30],cat[20];
    double preco;
}Brinquedo;

typedef struct{
    Brinquedo vet[100];
    int q;
}Brinquedos;

void lerBrinquedo(Brinquedo *d);
void mostrarBriquedo(Brinquedo d);

void inicializar(Brinquedos *h);
void inserir(Brinquedos *h, Brinquedo d);
int existe(Brinquedos h, int codigo);
void remover(Brinquedos *h,int codigo);
void alterar(Brinquedos *h, int codigo, Brinquedo d);
void acrecentar(Brinquedos *h, int codigo, Brinquedo d);
void listar(Brinquedos h);
void mostrar(Brinquedos h);

#endif // DEBUG