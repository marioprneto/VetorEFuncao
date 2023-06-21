#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define TAMANHO_MAXIMO 100
typedef struct {
    int ids;
    char nomeCompleto[TAMANHO_MAXIMO];
    char email[TAMANHO_MAXIMO];
    char sexo[TAMANHO_MAXIMO];
    char endereco[TAMANHO_MAXIMO];
    double altura;
    int vacina;
} Usuario;

Usuario usuarios[TAMANHO_MAXIMO];
Usuario usuariosBackup[TAMANHO_MAXIMO];

int main(){
    menu(0);
    return 0;
}

void menu(int quantidade){
    setlocale(LC_ALL, "Portuguese");
    char opcao;
    char recuperarEmail[100];
    int valorEmail;

    printf("\nBem vindo ao sistema CRUD! Acesse alguma das seguintes opções para prosseguir: \n--------------------------------------------------------------------------------\n");
    printf("(1) - Incluir usuários; Máximo permitido: 1000. \n(2) - Editar um usuário.\n(3) - Excluir um usuário.\n(4) - Buscar um usuário pelo e-mail.\n(5) - Imprimir todos os usuários cadastrados.\n(6) - Fazer um backup de todos os usuários cadastrados.\n(7) - Fazer a restauração dos dados.\n--------------------------------------------------------------------------------");
    printf("\nO que vai ser hoje? ");
    
    if(quantidade < 1000){
        scanf(" %c",&opcao);
        switch (opcao)
        {
            case '1':
                printf("\n");
                incluirusuarioss(quantidade);
                break;

            case '2':
                printf("\n");
                editarusuarios();
                break;
        
            case '3':
                getchar();
                printf("\n");
                printf("Qual o e-mail do usuário que você deseja excluir? ");
                fgets(recuperarEmail, 100, stdin);

                while(strchr(recuperarEmail,'@') == NULL){
                    printf("Digitação inválida! Digite um e-mail válido: ");
                    fgets(recuperarEmail, 100, stdin);
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
                fgets(recuperarEmail, 100, stdin);

                while(strchr(recuperarEmail,'@') == NULL){
                    printf("Digitação inválida! Digite um e-mail válido: ");
                    fgets(recuperarEmail, 100, stdin);
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
        
            case '6':
                printf("\n");
                fazerBackupusuarioss();
                break;

            case '7':
                printf("\n");
                restaurarDados();
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
                        printf("(1) - Incluir usuários; Máximo permitido: 1000. \n(2) - Editar um usuário.\n(3) - Excluir um usuário.\n(4) - Buscar um usuário pelo e-mail.\n(5) - Imprimir todos os usuários cadastrados.\n(6) - Fazer um backup de todos os usuários cadastrados.\n(7) - Fazer a restauração dos dados.\n--------------------------------------------------------------------------------");
                        printf("\nO que vai ser hoje? ");
                        break;

                    case '2':
                        editarusuarios();
                        break;
                
                    case '3':
                        getchar();
                        printf("\n");
                        printf("Qual o e-mail do usuário que você deseja editar? ");
                        fgets(recuperarEmail, 100, stdin);

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
                        fgets(recuperarEmail, 100, stdin);

                        while(strchr(recuperarEmail,'@') == NULL){
                            printf("Digitação inválida! Digite um e-mail válido: ");
                            fgets(recuperarEmail, 100, stdin);
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
                
                    case '6':
                        printf("\n");
                        fazerBackupusuarioss();
                        break;

                    case '7':
                        printf("\n");
                        restaurarDados();
                        break;

                    default:
                        printf("Valor inválido. Digite um valor válido: ");
                        break;

                }
            }
    }
}

void incluirusuarioss(quantidadeusuarioss){
    int i = quantidadeusuarioss, valorVacina, contadorPergunta = 0;
    char encerrarAlgoritmo;
    float valorAltura;

    getchar();

    while(i<1000){
        
        while(verificaNumero(i,geraID(i)) == 1){
            geraID(i);
        }

        usuarios[i].ids = geraID(i);

        printf("Digite o nome do usuário %d: ",i);
        fgets(usuarios[i].nomeCompleto, 100, stdin);

        usuarios[i].nomeCompleto[strcspn(usuarios[i].nomeCompleto, "\n")] = '\0';

        printf("Digite o e-mail do usuário %d: ",i);
        fgets(usuarios[i].email, 100, stdin);

        while(strchr(usuarios[i].email,'@') == NULL){
            printf("Digitação inválida! Digite um e-mail válido: ");
            fgets(usuarios[i].email, 100, stdin);
            usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';
        }

        usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';

        printf("Digite o sexo do usuário (Feminino, Masculino e Indiferente) %d: ",i);
        fgets(usuarios[i].sexo, 100, stdin);
        usuarios[i].sexo[strcspn(usuarios[i].sexo, "\n")] = '\0';

        while(strcmp(usuarios[i].sexo,"Feminino")!=0 && strcmp(usuarios[i].sexo,"Masculino")!=0 && strcmp(usuarios[i].sexo,"Indiferente")!=0){
            printf("Digitação inválida! Digite conforme está emntre parenteses. (Feminino, Masculino e Indiferente): ",i);
            fgets(usuarios[i].sexo, 100, stdin);
            usuarios[i].sexo[strcspn(usuarios[i].sexo, "\n")] = '\0';
        }

        printf("Digite o endereço do usuário %d: ",i);
        fgets(usuarios[i].endereco, 100, stdin);

        usuarios[i].endereco[strcspn(usuarios[i].endereco, "\n")] = '\0';

        printf("Digite a altura do usuário %d: ",i);
        scanf("%f",&valorAltura);

        while(valorAltura < 1 || valorAltura > 2){
            printf("Altura inválida! Digite um valor válido entre 1 e 2 metros: ");
            scanf("%f",&valorAltura);
        }

        usuarios[i].altura = valorAltura;

        printf("Digite (1) para se o usuário tomou vacina ou (0) se o usuário não tomou vacina: ");
        scanf("%i",&valorVacina);

        while (valorVacina != 0 && valorVacina != 1)
        {
            printf("Digite (1) para se o usuário tomou vacina ou (0) se o usuário não tomou vacina: ");
            scanf("%i",&valorVacina);
        }

        usuarios[i].vacina = valorVacina;


        if(contadorPergunta == 0){
            getchar();
            printf("\nDeseja parar de incluir usuários agora? (S) para sim. ");
            scanf(" %c",&encerrarAlgoritmo);

            if(encerrarAlgoritmo == 'S'){
                printf("Encerrando a inclusão de novos usuários!\n");
                break;
            } else{
                printf("Deseja incluir quantos funcionários no mínimo até que eu faça essa pergunta novamente? ");
                scanf("%i",&contadorPergunta);
                while (contadorPergunta <= 0)
                {
                    printf("Valor digitado inválido! Deseja incluir quantos funcionários no mínimo até que eu faça essa pergunta novamente? ");
                    scanf("%i",&contadorPergunta);
                }
            }
        }
        
        contadorPergunta--;
        i++;

        getchar();
    }

    int tamanho = retornaTamanhoVetor(); 
    
    menu(tamanho);
    return 0;
}

void editarusuarios(){
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
        fgets(usuarios[i].nomeCompleto, 100, stdin);

        usuarios[i].nomeCompleto[strcspn(usuarios[i].nomeCompleto, "\n")] = '\0';

        printf("Digite o e-mail do usuário %d: ",i);
        fgets(usuarios[i].email, 100, stdin);

        while(strchr(usuarios[i].email,'@') == NULL){
            printf("Digitação inválida! Digite um e-mail válido: ");
            fgets(usuarios[i].email, 100, stdin);
            usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';
        }

        usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';

        printf("Digite o sexo do usuário (Feminino, Masculino e Indiferente) %d: ",i);
        fgets(usuarios[i].sexo, 100, stdin);
        usuarios[i].sexo[strcspn(usuarios[i].sexo, "\n")] = '\0';

        while(strcmp(usuarios[i].sexo,"Feminino")!=0 && strcmp(usuarios[i].sexo,"Masculino")!=0 && strcmp(usuarios[i].sexo,"Indiferente")!=0){
            printf("Digitação inválida! Digite conforme está emntre parenteses. (Feminino, Masculino e Indiferente): ",i);
            fgets(usuarios[i].sexo, 100, stdin);
            usuarios[i].sexo[strcspn(usuarios[i].sexo, "\n")] = '\0';
        }

        printf("Digite o endereço do usuário %d: ",i);
        fgets(usuarios[i].endereco, 100, stdin);

        usuarios[i].endereco[strcspn(usuarios[i].endereco, "\n")] = '\0';

        printf("Digite a altura do usuário %d: ",i);
        scanf("%f",&valorAltura);

        while(valorAltura < 1 || valorAltura > 2){
            printf("Altura inválida! Digite um valor válido entre 1 e 2 metros: ");
            scanf("%f",&valorAltura);
        }

        usuarios[i].altura = valorAltura;

        printf("Digite (1) para se o usuário tomou vacina ou (0) se o usuário não tomou vacina: ");
        scanf("%i",&valorVacina);

        while (valorVacina != 0 && valorVacina != 1)
        {
            printf("Digite (1) para se o usuário tomou vacina ou (0) se o usuário não tomou vacina: ");
            scanf("%i",&valorVacina);
        }

        usuarios[i].vacina = valorVacina;

        getchar();
    }
    else{
        printf("Nenhum usuário encontrado!");
    }

    int tamanho = retornaTamanhoVetor();
    menu(tamanho);
}

void excluirusuarios(int posicao) {
    int tamanho = retornaTamanhoVetor();
    
    for (int m = posicao; m < tamanho - 1; m++) {
        usuarios[m].ids = usuariosBackup[m+1].ids;
        strncpy(usuarios[m].nomeCompleto, usuarios[m + 1].nomeCompleto, 100);
        strncpy(usuarios[m].email, usuarios[m + 1].email, 100);
        strncpy(usuarios[m].sexo, usuarios[m + 1].sexo, 100);
        strncpy(usuarios[m].endereco, usuarios[m + 1].endereco, 100);
        usuarios[m].altura = usuarios[m+1].altura;
        usuarios[m].vacina = usuarios[m+1].vacina;
    }

    usuarios[tamanho-1].ids = -1;
    strcpy(usuarios[tamanho-1].nomeCompleto, "");
    strcpy(usuarios[tamanho-1].email, "");
    strcpy(usuarios[tamanho-1].sexo, "");
    strcpy(usuarios[tamanho-1].endereco, "");
    usuarios[tamanho-1].altura = -1;
    usuarios[tamanho-1].vacina = -1;
    
    menu(tamanho - 1);
}

int retornaTamanhoVetor(){
    int contador = 0;
    for(int j=0;j<1000;j++){
        if(usuarios[j].altura>=1){
            contador++;
        } else{
            return contador;
        }
    }
}

void retornaDadosPessoaPeloEmail(int posicao){
    int tamanho = retornaTamanhoVetor();
    printf("Id: %d\nNome: %s\nEmail: %s\nSexo: %s\nEndereço: %s\nAltura: %.2f\nVacina: %d", usuarios[posicao].ids, usuarios[posicao].nomeCompleto, usuarios[posicao].email, usuarios[posicao].sexo, usuarios[posicao].endereco, usuarios[posicao].altura, usuarios[posicao].vacina);
    menu(tamanho);
}

void imprimirusuarioss(){
    int tamanho = retornaTamanhoVetor();
    for(int x=0;x<tamanho; x++){
        printf("Id: %d\nNome: %s\nEmail: %s\nSexo: %s\nEndereço: %s\nAltura: %.2f\nVacina: %d\n", usuarios[x].ids, usuarios[x].nomeCompleto, usuarios[x].email, usuarios[x].sexo, usuarios[x].endereco, usuarios[x].altura, usuarios[x].vacina);
        printf("\n");
    }
    menu(tamanho);
}

void fazerBackupusuarioss(){
    int tamanho = retornaTamanhoVetor();
    for(int l=0; l<tamanho;l++){
        usuariosBackup[l].ids = usuarios[l].ids;
        strcpy(usuariosBackup[l].nomeCompleto, usuarios[l].nomeCompleto);
        strcpy(usuariosBackup[l].email, usuarios[l].email);
        strcpy(usuariosBackup[l].sexo, usuarios[l].sexo);
        strcpy(usuariosBackup[l].endereco, usuarios[l].endereco);
        usuariosBackup[l].altura = usuarios[l].altura;
        usuariosBackup[l].vacina = usuarios[l].vacina;
    }

    printf("Backup feito com sucesso!");
    menu(tamanho);
}

int retornaTamanhoVetorBackup(){
    int contador = 0;
    for(int j=0;j<1000;j++){
        if(usuariosBackup[j].altura>=1){
            contador++;
        } else{
            return contador;
        }
    }
}

void restaurarDados(){
    int tamanho = retornaTamanhoVetorBackup();
    for(int z=0; z<tamanho;z++){
        usuarios[z].ids = usuariosBackup[z].ids;
        strcpy(usuarios[z].nomeCompleto, usuariosBackup[z].nomeCompleto);
        strcpy(usuarios[z].email, usuariosBackup[z].email);
        strcpy(usuarios[z].sexo, usuariosBackup[z].sexo);
        strcpy(usuarios[z].endereco, usuariosBackup[z].endereco);
        usuarios[z].altura = usuariosBackup[z].altura;
        usuarios[z].vacina = usuariosBackup[z].vacina;
    }
    printf("Restauração concluida com sucesso!");
    menu(tamanho);
}

int recuperaDadosPeloEmail(char emailParaRecuperar[100]){
    int tamanho = retornaTamanhoVetor();
    emailParaRecuperar[strcspn(emailParaRecuperar, "\n")] = '\0';
    for(int k = 0; k<tamanho ;k++){
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
