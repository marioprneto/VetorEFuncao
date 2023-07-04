#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int ids;
    char nomeCompleto[100];
    char email[75];
    char sexo[15];
    char endereco[60];
    double altura;
    int vacina;
} Usuario;

Usuario* usuarios = NULL;
int totalUsuarios = 0;

int main(){
    usuarios = malloc(1000 * sizeof(Usuario));
    menu(0);
    free(usuarios);
    return 0;
}

void menu(int quantidade){
    setlocale(LC_ALL, "Portuguese");
    char opcao;
    char recuperarEmail[75];
    int valorEmail;

    printf("\nBem vindo ao sistema CRUD! Acesse alguma das seguintes opções para prosseguir: \n--------------------------------------------------------------------------------\n");
    printf("(1) - Incluir usuários; Máximo permitido: 1000. \n(2) - Editar um usuário.\n(3) - Excluir um usuário.\n(4) - Buscar um usuário pelo e-mail.\n(5) - Imprimir todos os usuários cadastrados.\n(6) - Finalizar.\n--------------------------------------------------------------------------------");
    printf("\nO que vai ser hoje? ");
    
    if(quantidade < 1000){
        scanf(" %c",&opcao);
        switch (opcao)
        {
            case '1':
                getchar();
                printf("\n");
                incluirusuarios(quantidade);
                break;

            case '2':
                printf("\n");
                editarusuarios();
                break;
        
            case '3':
                getchar();
                printf("\n");
                printf("Qual o e-mail do usuário que você deseja excluir? ");
                fgets(recuperarEmail, sizeof(usuarios[0].email), stdin);

                while(strchr(recuperarEmail,'@') == NULL){
                    printf("Digitação inválida! Digite um e-mail válido: ");
                    fgets(recuperarEmail, sizeof(usuarios[0].email), stdin);
                    recuperarEmail[strcspn(recuperarEmail, "\n")] = '\0';
                }

                recuperarEmail[strcspn(recuperarEmail, "\n")] = '\0';

                valorEmail = recuperaDadosPeloEmail(recuperarEmail);

                if(valorEmail >= 0){
                    excluirusuarios(valorEmail);
                }
                        
                break;

            case '4':
                getchar();
                printf("\n");
                printf("Digite o email que deseja recuperar: ");
                fgets(recuperarEmail, sizeof(usuarios[0].email), stdin);

                while(strchr(recuperarEmail,'@') == NULL){
                    printf("Digitação inválida! Digite um e-mail válido: ");
                    fgets(recuperarEmail, sizeof(usuarios[0].email), stdin);
                    recuperarEmail[strcspn(recuperarEmail, "\n")] = '\0';
                }

                recuperarEmail[strcspn(recuperarEmail, "\n")] = '\0';

                valorEmail = recuperaDadosPeloEmail(recuperarEmail);

                if(valorEmail >= 0){
                    retornaDadosPessoaPeloEmail(valorEmail);
                }
                
                break;

            case '5':
                printf("\n");
                imprimirusuarioss();
                break;

            default:
                break;
        }
        } else{
            opcao = '1';
            while(opcao == '1'){
                scanf(" %c",&opcao);
                switch (opcao)
                {
                    case '1':
                        printf("Quantidade máxima de usuários atingida! Tente novamente outra opção.\n");
                        printf("(1) - Incluir usuários; Máximo permitido: 1000. \n(2) - Editar um usuário.\n(3) - Excluir um usuário.\n(4) - Buscar um usuário pelo e-mail.\n(5) - Imprimir todos os usuários cadastrados.\n(6) - Finalizar.--------------------------------------------------------------------------------");
                        printf("\nO que vai ser hoje? ");
                        break;

                    case '2':
                        editarusuarios();
                        break;
                
                    case '3':
                        getchar();
                        printf("\n");
                        printf("Qual o e-mail do usuário que você deseja editar? ");
                        fgets(recuperarEmail, sizeof(usuarios[0].email), stdin);

                        recuperarEmail[strcspn(recuperarEmail, "\n")] = '\0';

                        valorEmail = recuperaDadosPeloEmail(recuperarEmail);

                        if(valorEmail >= 0){
                            excluirusuarios(valorEmail);
                        }
                        
                        break;

                    case '4':
                        getchar();
                        printf("\n");
                        printf("Digite o email que deseja recuperar: ");
                        fgets(recuperarEmail, sizeof(usuarios[0].email), stdin);

                        while(strchr(recuperarEmail,'@') == NULL){
                            printf("Digitação inválida! Digite um e-mail válido: ");
                            fgets(recuperarEmail, sizeof(usuarios[0].email), stdin);
                            recuperarEmail[strcspn(recuperarEmail, "\n")] = '\0';
                        }

                        recuperarEmail[strcspn(recuperarEmail, "\n")] = '\0';

                        valorEmail = recuperaDadosPeloEmail(recuperarEmail);

                        if(valorEmail >= 0){
                            retornaDadosPessoaPeloEmail(valorEmail);
                        }
                        
                        break;

                    case '5':
                        printf("\n");
                        imprimirusuarioss();
                        break;

                    default:
                        printf("Valor inválido. Digite um valor válido: ");
                        break;

                }
            }
    }
    
    free(usuarios);
}

void incluirusuarios(int quantidadeusuarioss) {
    int i = quantidadeusuarioss, valorVacina, contadorPergunta = 0;
    char encerrarAlgoritmo;
    float valorAltura;

    while (i < quantidadeusuarioss + 1000) {

        totalUsuarios++;
        usuarios[i].ids = geraID(i);

        printf("Digite o nome do usuário %d: ", i);
        fgets(usuarios[i].nomeCompleto, sizeof(usuarios[i].nomeCompleto), stdin);

        usuarios[i].nomeCompleto[strcspn(usuarios[i].nomeCompleto, "\n")] = '\0';

        printf("Digite o e-mail do usuário %d: ", i);
        fgets(usuarios[i].email, sizeof(usuarios[i].email), stdin);

        while (strchr(usuarios[i].email, '@') == NULL) {
            printf("Digitação inválida! Digite um e-mail válido: ");
            fgets(usuarios[i].email, sizeof(usuarios[i].email), stdin);
            usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';
        }

        usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';

        printf("Digite o sexo do usuário (Feminino, Masculino e Indiferente) %d: ", i);
        fgets(usuarios[i].sexo, sizeof(usuarios[i].sexo), stdin);
        usuarios[i].sexo[strcspn(usuarios[i].sexo, "\n")] = '\0';

        while (strcmp(usuarios[i].sexo, "Feminino") != 0 && strcmp(usuarios[i].sexo, "Masculino") != 0 && strcmp(usuarios[i].sexo, "Indiferente") != 0) {
            printf("Digitação inválida! Digite conforme está emntre parenteses. (Feminino, Masculino e Indiferente): ", i);
            fgets(usuarios[i].sexo, sizeof(usuarios[i].sexo), stdin);
            usuarios[i].sexo[strcspn(usuarios[i].sexo, "\n")] = '\0';
        }

        printf("Digite o endereço do usuário %d: ", i);
        fgets(usuarios[i].endereco, sizeof(usuarios[i].endereco), stdin);

        usuarios[i].endereco[strcspn(usuarios[i].endereco, "\n")] = '\0';

        printf("Digite a altura do usuário %d: ", i);
        scanf("%f", &valorAltura);

        while (valorAltura < 1 || valorAltura > 2) {
            printf("Altura inválida! Digite um valor válido entre 1 e 2 metros: ");
            scanf("%f", &valorAltura);
        }

        usuarios[i].altura = valorAltura;

        printf("Digite (1) para se o usuário tomou vacina ou (0) se o usuário não tomou vacina: ");
        scanf("%i", &valorVacina);

        while (valorVacina != 0 && valorVacina != 1) {
            printf("Digite (1) para se o usuário tomou vacina ou (0) se o usuário não tomou vacina: ");
            scanf("%i", &valorVacina);
        }

        usuarios[i].vacina = valorVacina;

        if (contadorPergunta == 0) {
            getchar();
            printf("\nDeseja parar de incluir usuários agora? (S) para sim. ");
            scanf(" %c", &encerrarAlgoritmo);

            if (encerrarAlgoritmo == 'S') {
                printf("Encerrando a inclusão de novos usuários!\n");
                break;
            } else {
                printf("Deseja incluir quantos funcionários no mínimo até que eu faça essa pergunta novamente? ");
                scanf("%i", &contadorPergunta);
                while (contadorPergunta <= 0) {
                    printf("Valor digitado inválido! Deseja incluir quantos funcionários no mínimo até que eu faça essa pergunta novamente? ");
                    scanf("%i", &contadorPergunta);
                }
            }
        }

        contadorPergunta--;
        i++;

        getchar();
    }

    menu(totalUsuarios);
}


void editarusuarios(){
    char emailValor[sizeof(usuarios[0].email)];
    int valorVacina;
    float valorAltura;
    getchar();

    printf("Qual o e-mail do usuário que você deseja editar? ");
    fgets(emailValor, sizeof(emailValor), stdin);

    while(strchr(emailValor,'@') == NULL){
        printf("Digitação inválida! Digite um e-mail válido: ");
        fgets(emailValor, sizeof(emailValor), stdin);
        emailValor[strcspn(emailValor, "\n")] = '\0';
    }

    int i = recuperaDadosPeloEmail(emailValor); 
    
    if(i!=-1){

        printf("Digite o nome do usuário %d: ",i);
        fgets(usuarios[i].nomeCompleto, sizeof(usuarios[i].nomeCompleto), stdin);

        usuarios[i].nomeCompleto[strcspn(usuarios[i].nomeCompleto, "\n")] = '\0';

        printf("Digite o e-mail do usuário %d: ",i);
        fgets(usuarios[i].email, sizeof(usuarios[i].email), stdin);

        while(strchr(usuarios[i].email,'@') == NULL){
            printf("Digitação inválida! Digite um e-mail válido: ");
            fgets(usuarios[i].email, sizeof(usuarios[i].email), stdin);
            usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';
        }

        usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';

        printf("Digite o sexo do usuário (Feminino, Masculino e Indiferente) %d: ",i);
        fgets(usuarios[i].sexo, sizeof(usuarios[i].sexo), stdin);
        usuarios[i].sexo[strcspn(usuarios[i].sexo, "\n")] = '\0';

        while(strcmp(usuarios[i].sexo,"Feminino")!=0 && strcmp(usuarios[i].sexo,"Masculino")!=0 && strcmp(usuarios[i].sexo,"Indiferente")!=0){
            printf("Digitação inválida! Digite conforme está entre parenteses. (Feminino, Masculino e Indiferente): ",i);
            fgets(usuarios[i].sexo, sizeof(usuarios[i].sexo), stdin);
            usuarios[i].sexo[strcspn(usuarios[i].sexo, "\n")] = '\0';
        }

        printf("Digite o endereço do usuário %d: ",i);
        fgets(usuarios[i].endereco, sizeof(usuarios[i].endereco), stdin);

        usuarios[i].endereco[strcspn(usuarios[i].endereco, "\n")] = '\0';

        printf("Digite a altura do usuário %d: ",i);
        scanf("%f",&valorAltura);

        while(valorAltura < 1 || valorAltura > 2){
            printf("Altura inválida! Digite um valor válido entre 1 e 2 metros: ");
            scanf("%f",&valorAltura);
        }

        usuarios[i].altura = valorAltura;

        printf("Digite (1) se o usuário tomou vacina ou (0) se o usuário não tomou vacina: ");
        scanf("%i",&valorVacina);

        while (valorVacina != 0 && valorVacina != 1)
        {
            printf("Digite (1) se o usuário tomou vacina ou (0) se o usuário não tomou vacina: ");
            scanf("%i",&valorVacina);
        }

        usuarios[i].vacina = valorVacina;

        getchar();
    }
    else{
        printf("Nenhum usuário encontrado!");
    }

    menu(totalUsuarios);
}

void excluirusuarios(int posicao) {
    
    for (int i = posicao; i < totalUsuarios - 1; i++) {
        usuarios[i] = usuarios[i + 1];
    }
    
    totalUsuarios--;
    usuarios = realloc(usuarios, totalUsuarios * sizeof(Usuario));

    menu(totalUsuarios);
}

void retornaDadosPessoaPeloEmail(int posicao){
    printf("Id: %d\nNome: %s\nEmail: %s\nSexo: %s\nEndereço: %s\nAltura: %.2f\nVacina: %d", usuarios[posicao].ids, usuarios[posicao].nomeCompleto, usuarios[posicao].email, usuarios[posicao].sexo, usuarios[posicao].endereco, usuarios[posicao].altura, usuarios[posicao].vacina);
    menu(totalUsuarios);
}

void imprimirusuarioss(){
    for(int x=0;x<totalUsuarios; x++){
        printf("Id: %d\nNome: %s\nEmail: %s\nSexo: %s\nEndereço: %s\nAltura: %.2f\nVacina: %d\n", usuarios[x].ids, usuarios[x].nomeCompleto, usuarios[x].email, usuarios[x].sexo, usuarios[x].endereco, usuarios[x].altura, usuarios[x].vacina);
        printf("\n");
    }
    menu(totalUsuarios);
}

int recuperaDadosPeloEmail(char emailParaRecuperar[75]){
    emailParaRecuperar[strcspn(emailParaRecuperar, "\n")] = '\0';
    for(int k = 0; k<totalUsuarios ;k++){
        if(strcmp(emailParaRecuperar, usuarios[k].email) == 0){
            return k;
        }
    }
    return -1;
}

int geraID(i){
    int numeroGerado;
    numeroGerado = rand();
    while(verificaNumero(i,numeroGerado) == 1){
        numeroGerado = rand();
    }
    return numeroGerado;
}

int verificaNumero(int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        if (usuarios[i].ids == numero) {
            return 1;
        }
    }
    return 0;
}
