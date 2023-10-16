#include <stdio.h>
#include <string.h>

struct Produto{
    int codigo;
    int numero;
    char nome[25];
    float preco;
};

struct Cliente{
    int id;
    char nome;
    char senha;
};

void visualizarProdutos(struct Produto produtos[]);
void cadastrarProtudos(struct Produto produtos[]);
void removerProdutos(struct Produto produtos[]);
void inicializarProdutos(struct Produto produtos[]);
void inicializarClientes(struct Cliente clientes[]);
void cadastrarClientes(struct Cliente clientes[]);
void removerClientes(struct Cliente clientes[]);
void menuAdmin(struct Cliente clientes[], struct Produto produtos[]);
void menuUser(struct Cliente clientes[], struct Produto produtos[]);
void comprarProduto(struct Produto produtos[], struct Cliente clientes[]);

int main(){
    struct Produto produtos[51];
    struct Cliente clientes[51];
    char nome[20], senha[20];
    int modo;

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("=            E-COMMERCE             =\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("-=-=-=-=-=-=Efetuar Login-=-=-=-=-=-=-\n");
    printf("Nome: ");
    gets(nome);

    printf("Senha: ");
    gets(senha);

    printf("Bem vindo %s!\n \n", nome);

    printf("MODO ADMIN: PRESSIONE [1]\n");
    printf("MODO USER: PRESSIONE [2]\n");
    printf("Modo: ");
    scanf("%d", &modo);
    while(modo != 1 && modo != 2){
        printf("Opção inválida!\n");
        printf("MODO ADMIN: PRESSIONE [1]\n");
        printf("MODO USER: PRESSIONE [2]\n");
        printf("Modo: ");
        scanf("%d", &modo);
    }

    if(modo == 1){
        menuAdmin(produtos, clientes);
    }else{
        menuUser(produtos, clientes);
    }

    return 0;
}

void visualizarProdutos(struct Produto produtos[]){
    printf("=-=-=-=-= PRODUTOS =-=-=-=-=\n");

    for(int i = 1; i <= 50; i++){
        if(produtos[i].numero == i){
            printf("=-=-=-=-=-=-=-=-=\n");
            printf("Produto %d!\n", i);
            printf("Código: %d\n", produtos[i].codigo);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Preço: %.2f\n", produtos[i].preco);
            printf("=-=-=-=-=-=-=-=-=\n");
        }
    }
}

void cadastrarProtudos(struct Produto produtos[]){
    int numero;

    printf("=-=-=-=-=-=-=-=-=\n");
    printf("Cadastrando produto...\n");
    printf("=-=-=-=-=-=-=-=-=\n");

    printf("Número: ");
    scanf("%d", &numero);
    produtos[numero].numero = numero;
    while(numero < 1 || numero > 50){
        printf("Número inválido! insira um número com o valor de 1 a 50!\n");
        printf("Número: ");
        scanf("%d", &numero);
        produtos[numero].numero = numero;
    }

    getchar();

    printf("Código: ");
    scanf("%d", &produtos[numero].codigo);
    while(produtos[numero].codigo < 0){
        printf("O código do produto deve ser maior que 0!\n");
        printf("Código: ");
        scanf("%d", &produtos[numero].codigo);
    }

    getchar();

    printf("Nome: ");
    gets(produtos[numero].nome);

    printf("Valor: ");
    scanf("%f", &produtos[numero].preco);
    while(produtos[numero].preco < 0){
        printf("O valor deve ser maior que 0!");
        printf("Valor: ");
        scanf("%f", &produtos[numero].preco);
    }
}

void removerProdutos(struct Produto produtos[]){
    int numero;

    printf("=-=-=-=-=-=-=-=-=\n");
    printf("Removendo produto...\n");
    printf("=-=-=-=-=-=-=-=-=\n");


    printf("Número do produto: ");
    scanf("%d", &numero);

    produtos[numero].numero = 0;
    produtos[numero].codigo = 0;
    produtos[numero].preco = 0.0;
    strcpy(produtos[numero].nome, "Indefinido");
}

void inicializarProdutos(struct Produto produtos[]){
    for(int i = 0; i <= 50; i++){
        produtos[i].numero = 0;
        produtos[i].codigo = 0;
        produtos[i].preco = 0.0;
        strcpy(produtos[i].nome, "Indefinido");
    }
}

void inicializarClientes(struct Cliente clientes[]){
    for(int i = 0; i <= 50; i++){
        clientes[i].id = 0;
        strcpy(clientes[i].nome, "Indefinido");
        strcpy(clientes[i].senha, "Indefinido");
    }
}

void cadastrarClientes(struct Cliente clientes[]){
    int numero;

    printf("=-=-=-=-=-=-=-=-=\n");
    printf("Cadastrando cliente...\n");
    printf("=-=-=-=-=-=-=-=-=\n");

    printf("Número do cliente: ");
    scanf("%d", &numero);
    while(numero < 1 || numero > 50){
        printf("Número inválido! insira um número com o valor de 1 a 50!\n");
        printf("Número do cliente: ");
        scanf("%d", &numero);
    }

    getchar();

    printf("Nome: ");
    scanf("%s", &clientes[numero].nome);

    printf("Id: ");
    scanf("%d", &clientes[numero].id);
    while(clientes[numero].id < 0){
        printf("O valor deve ser maior que 0!");
        printf("Id: ");
        scanf("%d", &clientes[numero].id);
    }

    getchar();

    printf("Senha: ");
    scanf("%s", &clientes[numero].senha);
}

void removerClientes(struct Cliente clientes[]){
    int numero;

    printf("=-=-=-=-=-=-=-=-=\n");
    printf("Removendo produto...\n");
    printf("=-=-=-=-=-=-=-=-=\n");


    printf("Número do produto: ");
    scanf("%d", &numero);

    clientes[numero].id = 0;
    strcpy(clientes[numero].nome, "Indefinido");
    strcpy(clientes[numero].senha, "Indefinido");
}

void menuAdmin(struct Cliente clientes[], struct Produto produtos[]){
    int resposta, funcionalidade;
    
    while(resposta != 0){
        printf("=-=-=-MENU ADMIN=-=-=-=\n");

        printf("[1] -> Visualizar Produto\n");
        printf("[2] -> Cadastrar Produto\n");
        printf("[3] -> Remover Produto\n");
        printf("[4] -> Comprar Produto\n");
        printf("[5] -> Verificar Pedidos\n");
        printf("[6] -> Cadastrar Cliente\n");
        printf("[7] -> Remover Cliente\n");

        printf("Funcionalidade: ");
        scanf("%d", &funcionalidade);
        switch (funcionalidade)
        {
        case 1:
            visualizarProdutos(produtos);
            break;
        case 2:
            cadastrarProtudos(produtos);
            break;
        case 3:
            removerProdutos(produtos);
            break;
        case 4:
            comprarProduto(produtos, clientes);
            break;
        case 5:
            break;
        case 6:
            cadastrarClientes(clientes);
            break;
        case 7:
            removerClientes(clientes);
            break;    
        default:
            break;
        }

        printf("Deseja sair? pressione [0]: ");
        scanf("%d", &resposta);
    }
}

void menuUser(struct Cliente clientes[], struct Produto produtos[]){
    int resposta, funcionalidade;
    
    while(resposta != 0){
        printf("=-=-=-MENU USER=-=-=-=\n");

        printf("[1] -> Visualizar Produto\n");
        printf("[2] -> Cadastrar Cliente\n");
        printf("[3] -> Remover Cliente\n");
        printf("[4] -> Comprar Produto\n");
        printf("[5] -> Verificar Pedidos\n");

        printf("Funcionalidade: ");
        scanf("%d", &funcionalidade);
        switch (funcionalidade)
        {
        case 1:
            visualizarProdutos(produtos);
            break;
        case 2:
            cadastrarClientes(clientes);
            break;
        case 3:
            removerClientes(clientes);
            break;
        case 4:
            comprarProduto(produtos, clientes);
            break; 
        default:
            break;
        }

        printf("Deseja sair? pressione [0]: ");
        scanf("%d", &resposta);
    }
}

void comprarProduto(struct Produto produtos[], struct Cliente clientes[]){
    int numero;

    printf("=-=-=-=-=-=-=-=-=\n");
    printf("=Comprar Produto=\n");
    printf("=-=-=-=-=-=-=-=-=\n");

    printf("Número do produto: ");
    scanf("%d", &numero);

    printf("=-=-=-=-=-=-=-=-=\n");
    printf("Produto %d!", numero);
    printf("Código: %d\n", produtos[numero].codigo);
    printf("Nome: %s\n", produtos[numero].nome);
    printf("Preço: %.2f\n", produtos[numero].preco);
    printf("=-=-=-=-=-=-=-=-=\n");

    printf("Compra efetuada!\n");
}