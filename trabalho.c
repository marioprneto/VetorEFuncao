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

void incluirUsuarios(){
    int i = 0, valorVacina, contadorPergunta = 0;
    char *encerrarAlgoritmo;
    float valorAltura;

    getchar();

    while(i<2){
        
        while(verificaNumero(ids,i,geraID(ids,i)) == 1){
            geraID(ids,i);
        }

        ids[i] = geraID(ids,i);

        printf("Digite o nome do usuário %d: ",i);
        fgets(nomeCompleto[i], 100, stdin);

        nomeCompleto[i][strcspn(nomeCompleto[i], "\n")] = '\0';

        printf("Digite o e-mail do usuário %d: ",i);
        fgets(email[i], 100, stdin);

        while(strchr(email[i],'@') == NULL){
            printf("Digitação inválida! Digite um e-mail válido: ");
            fgets(email[i], 100, stdin);
            email[i][strcspn(email[i], "\n")] = '\0';
        }

        email[i][strcspn(email[i], "\n")] = '\0';

        printf("Digite o sexo do usuário (Feminino, Masculino e Indiferente) %d: ",i);
        fgets(sexo[i], 100, stdin);
        sexo[i][strcspn(sexo[i], "\n")] = '\0';

        while(strcmp(sexo[i],"Feminino")!=0 && strcmp(sexo[i],"Masculino")!=0 && strcmp(sexo[i],"Indiferente")!=0){
            printf("Digitação inválida! Digite conforme está emntre parenteses. (Feminino, Masculino e Indiferente): ",i);
            fgets(sexo[i], 100, stdin);
            sexo[i][strcspn(sexo[i], "\n")] = '\0';
        }

        printf("Digite o endereço do usuário %d: ",i);
        fgets(endereco[i], 100, stdin);

        endereco[i][strcspn(endereco[i], "\n")] = '\0';

        printf("Digite a altura do usuário %d: ",i);
        scanf("%f",&valorAltura);

        while(valorAltura < 1 || valorAltura > 2){
            printf("Altura inválida! Digite um valor válido entre 1 e 2 metros: ");
            scanf("%f",&valorAltura);
        }

        altura[i] = valorAltura;

        printf("Digite (1) para se o usuário tomou vacina ou (0) se o usuário não tomou vacina: ");
        scanf("%i",&valorVacina);

        while (valorVacina != 0 && valorVacina != 1)
        {
            printf("Digite (1) para se o usuário tomou vacina ou (0) se o usuário não tomou vacina: ");
            scanf("%i",&valorVacina);
        }

        vacina[i] = valorVacina;

        getchar();

        /*if(contadorPergunta == 0){
            printf("\nDeseja parar de incluir usuários agora? (Sim) para sim, (Nao) para não. ");
            scanf("%s",&encerrarAlgoritmo);       
            encerrarAlgoritmo[strcspn(encerrarAlgoritmo, "\n")] = '\0';

            if(strcmp(encerrarAlgoritmo,"Sim")==0){
                break;
                i = 1000;
            } else{
                printf("Deseja incluir quantos funcionários no mínimo até que eu faça essa pergunta novamente? ");
                scanf("%i",&contadorPergunta);
                while (contadorPergunta <= 0)
                {
                    printf("Valor digitado inválido! Deseja incluir quantos funcionários no mínimo até que eu faça essa pergunta novamente? ");
                    scanf("%i",&contadorPergunta);
                }
            }
        }*/
        
        contadorPergunta--;
        i++;

        getchar();
    }
    
    menu(i);
    return 0;
}

void editarUsuario(){
    char emailValor[2][TAMANHO_MAXIMO];
    int valorVacina;
    float valorAltura;
    getchar();

    printf("Qual o e-mail do usuário que você deseja editar? ");
    fgets(emailValor[0], 100, stdin);

    while(strchr(emailValor,'@') == NULL){
        printf("Digitação inválida! Digite um e-mail válido: ");
        fgets(emailValor, 100, stdin);
        emailValor[0][strcspn(emailValor[0], "\n")] = '\0';
    }

    int i = recuperaDadosPeloEmail(emailValor[0]); 
    
    if(i!=-1){

        printf("Digite o nome do usuário %d: ",i);
        fgets(nomeCompleto[i], 100, stdin);

        nomeCompleto[i][strcspn(nomeCompleto[i], "\n")] = '\0';

        printf("Digite o e-mail do usuário %d: ",i);
        fgets(email[i], 100, stdin);

        while(strchr(email[i],'@') == NULL){
            printf("Digitação inválida! Digite um e-mail válido: ");
            fgets(email[i], 100, stdin);
            email[i][strcspn(email[i], "\n")] = '\0';
        }

        email[i][strcspn(email[i], "\n")] = '\0';

        printf("Digite o sexo do usuário (Feminino, Masculino e Indiferente) %d: ",i);
        fgets(sexo[i], 100, stdin);
        sexo[i][strcspn(sexo[i], "\n")] = '\0';

        while(strcmp(sexo[i],"Feminino")!=0 && strcmp(sexo[i],"Masculino")!=0 && strcmp(sexo[i],"Indiferente")!=0){
            printf("Digitação inválida! Digite conforme está emntre parenteses. (Feminino, Masculino e Indiferente): ",i);
            fgets(sexo[i], 100, stdin);
            sexo[i][strcspn(sexo[i], "\n")] = '\0';
        }

        printf("Digite o endereço do usuário %d: ",i);
        fgets(endereco[i], 100, stdin);

        endereco[i][strcspn(endereco[i], "\n")] = '\0';

        printf("Digite a altura do usuário %d: ",i);
        scanf("%f",&valorAltura);

        while(valorAltura < 1 || valorAltura > 2){
            printf("Altura inválida! Digite um valor válido entre 1 e 2 metros: ");
            scanf("%f",&valorAltura);
        }

        altura[i] = valorAltura;

        printf("Digite (1) para se o usuário tomou vacina ou (0) se o usuário não tomou vacina: ");
        scanf("%i",&valorVacina);

        while (valorVacina != 0 && valorVacina != 1)
        {
            printf("Digite (1) para se o usuário tomou vacina ou (0) se o usuário não tomou vacina: ");
            scanf("%i",&valorVacina);
        }

        vacina[i] = valorVacina;

        getchar();
    }
    else{
        printf("Nenhum usuário encontrado!");
    }

    int tamanho = retornaTamanhoVetor();
    menu(tamanho);
}

void imprimirUsuarios(){
    int tamanho = retornaTamanhoVetor();
    for(int x=0;x<tamanho; x++){
        printf("Id: %d\nNome: %s\nEmail: %s\nSexo: %s\nEndereço: %s\nAltura: %.2f\nVacina: %d", ids[x], nomeCompleto[x], email[x], sexo[x], endereco[x], altura[x], vacina[x]);
        printf("\n");
    }
    menu(tamanho);
}

int geraID(ids, i){
    int numeroGerado;
    numeroGerado = rand();
    while(verificaNumero(ids,i,numeroGerado) == 1){
        numeroGerado = rand();
    }
    return numeroGerado;
}

int verificaNumero(int vetor[], int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == numero) {
            return 1;
        }
    }
    return 0;
}

int retornaTamanhoVetor(){
    int contador = 0;
    for(int j=0;j<1000;j++){
        if(altura[j]>=1){
            contador++;
        } else{
            return contador;
        }
    }
}