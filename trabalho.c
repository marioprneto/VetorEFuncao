#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define TAMANHO_MAXIMO 100
int ids[1000], vacina[1000];
char nomeCompleto[1000][TAMANHO_MAXIMO], email[1000][TAMANHO_MAXIMO], sexo[1000][TAMANHO_MAXIMO], endereco[1000][TAMANHO_MAXIMO];
double altura[1000];

int main(){
    menu(0);
    return 0;
}

int menu(int quantidade){
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    char recuperarEmail[100];

    printf("\nBem vindo ao sistema CRUD! Acesse alguma das seguintes opções para prosseguir: \n--------------------------------------------------------------------------------\n");
    printf("(1) - Incluir usuários; Máximo permitido: 1000. \n(2) - Editar um usuário.\n(3) - Excluir um usuário.\n(4) - Buscar um usuário pelo e-mail.\n(5) - Imprimir todos os usuários cadastrados.\n(6) - Fazer um backup de todos os usuários cadastrados.\n(7) - Fazer a restauração dos dados.\n--------------------------------------------------------------------------------");
    printf("\nO que vai ser hoje? ");
    
    if(quantidade < 1000){
        scanf("%i",&opcao);
        switch (opcao)
        {
            case 1:
                printf("\n");
                incluirUsuarios();
                break;

            case 2:
                printf("\n");
                editarUsuario();
                break;
        
            case 3:
                printf("\n");
                excluirUsuario();
                break;

            case 4:
                getchar();
                printf("\n");
                printf("Digite o email que deseja recuperar: ");
                fgets(recuperarEmail, 100, stdin);

                while(strchr(recuperarEmail,'@') == NULL){
                    printf("Digitação inválida! Digite um e-mail válido: ");
                    fgets(recuperarEmail, 100, stdin);
                    recuperarEmail[strcspn(recuperarEmail, "\n")] = '\0';
                }

                recuperarEmail[strcspn(recuperarEmail, "\n")] = '\0';

                int valorEmail = recuperaDadosPeloEmail(recuperarEmail);

                if(valorEmail >= 0){
                    retornaDadosPessoaPeloEmail(valorEmail);
                }
                
                break;

            case 5:
                printf("\n");
                imprimirUsuarios();
                break;
        
            case 6:
                printf("\n");
                fazerBackupUsuarios();
                break;

            case 7:
                printf("\n");
                restaurarUsuarios();
                break;

            default:
                break;
        }
        } else{
            opcao = 1;
            while(opcao == 1){
                scanf("%i",&opcao);
                switch (opcao)
                {
                    case 1:
                        printf("Quantidade máxima de usuários atingida! Tente novamente outra opção.\n");
                        printf("(1) - Incluir usuários; Máximo permitido: 1000. \n(2) - Editar um usuário.\n(3) - Excluir um usuário.\n(4) - Buscar um usuário pelo e-mail.\n(5) - Imprimir todos os usuários cadastrados.\n(6) - Fazer um backup de todos os usuários cadastrados.\n(7) - Fazer a restauração dos dados.\n--------------------------------------------------------------------------------");
                        printf("\nO que vai ser hoje? ");
                        break;

                    case 2:
                        editarUsuario();
                        break;
                
                    case 3:
                        printf("\n");
                        excluirUsuario();
                        break;

                    case 4:
                        printf("\n");
                        recuperaDadosPeloEmail("");
                        break;

                    case 5:
                        printf("\n");
                        imprimirUsuarios();
                        break;
                
                    case 6:
                        printf("\n");
                        fazerBackupUsuarios();
                        break;

                    case 7:
                        printf("\n");
                        restaurarUsuarios();
                        break;

                    default:
                        printf("Valor inválido. Digite um valor válido: ");
                        break;

                }
            }
    }
}

