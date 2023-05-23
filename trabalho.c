#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define TAMANHO_MAXIMO 100
int ids[1000], vacina[1000], idsBackup[1000], vacinaBackup[1000];
char nomeCompleto[1000][TAMANHO_MAXIMO], email[1000][TAMANHO_MAXIMO], sexo[1000][TAMANHO_MAXIMO], endereco[1000][TAMANHO_MAXIMO];
char nomeCompletoBackup[1000][TAMANHO_MAXIMO], emailBackup[1000][TAMANHO_MAXIMO], sexoBackup[1000][TAMANHO_MAXIMO], enderecoBackup[1000][TAMANHO_MAXIMO];
double altura[1000], alturaBackup[1000];

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
                incluirUsuarios(quantidade);
                break;

            case '2':
                printf("\n");
                editarUsuario();
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
                    excluirUsuario(valorEmail);
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
                imprimirUsuarios();
                break;
        
            case '6':
                printf("\n");
                fazerBackupUsuarios();
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
                        editarUsuario();
                        break;
                
                    case '3':
                        getchar();
                        printf("\n");
                        printf("Qual o e-mail do usuário que você deseja editar? ");
                        fgets(recuperarEmail, 100, stdin);

                        recuperarEmail[strcspn(recuperarEmail, "\n")] = '\0';

                        valorEmail = recuperaDadosPeloEmail(recuperarEmail);

                        if(valorEmail >= 0){
                            excluirUsuario(valorEmail);
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
                        imprimirUsuarios();
                        break;
                
                    case '6':
                        printf("\n");
                        fazerBackupUsuarios();
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

void incluirUsuarios(quantidadeUsuarios){
    int i = quantidadeUsuarios, valorVacina, contadorPergunta = 0;
    char encerrarAlgoritmo;
    float valorAltura;

    getchar();

    while(i<1000){
        
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

void excluirUsuario(int posicao) {
    int tamanho = retornaTamanhoVetor();
    
    for (int m = posicao; m < tamanho - 1; m++) {
        ids[m] = ids[m + 1];
        strncpy(nomeCompleto[m], nomeCompleto[m + 1], 100);
        strncpy(email[m], email[m + 1], 100);
        strncpy(sexo[m], sexo[m + 1], 100);
        strncpy(endereco[m], endereco[m + 1], 100);
        altura[m] = altura[m + 1];
        vacina[m] = vacina[m + 1];
    }

    ids[tamanho-1] = -1;
    strcpy(nomeCompleto[tamanho-1], "");
    strcpy(email[tamanho-1], "");
    strcpy(sexo[tamanho-1], "");
    strcpy(endereco[tamanho-1], "");
    altura[tamanho-1] = -1;
    vacina[tamanho-1] = -1;
    
    menu(tamanho - 1);
}


void retornaDadosPessoaPeloEmail(int posicao){
    int tamanho = retornaTamanhoVetor();
    printf("Id: %d\nNome: %s\nEmail: %s\nSexo: %s\nEndereço: %s\nAltura: %.2f\nVacina: %d", ids[posicao], nomeCompleto[posicao], email[posicao], sexo[posicao], endereco[posicao], altura[posicao], vacina[posicao]);
    menu(tamanho);
}

void imprimirUsuarios(){
    int tamanho = retornaTamanhoVetor();
    for(int x=0;x<tamanho; x++){
        printf("Id: %d\nNome: %s\nEmail: %s\nSexo: %s\nEndereço: %s\nAltura: %.2f\nVacina: %d\n", ids[x], nomeCompleto[x], email[x], sexo[x], endereco[x], altura[x], vacina[x]);
        printf("\n");
    }
    menu(tamanho);
}

void fazerBackupUsuarios(){
    int tamanho = retornaTamanhoVetor();
    for(int l=0; l<tamanho;l++){
        idsBackup[l] = ids[l];
        strcpy(nomeCompletoBackup[l], nomeCompleto[l]);
        strcpy(emailBackup[l], email[l]);
        strcpy(sexoBackup[l], sexo[l]);
        strcpy(enderecoBackup[l], endereco[l]);
        alturaBackup[l] = altura[l];
        vacinaBackup[l] = vacina[l];
    }

    printf("Backup feito com sucesso!");
    menu(tamanho);
}

void restaurarDados(){
    int tamanho = retornaTamanhoVetorBackup();
    for(int z=0; z<tamanho;z++){
        ids[z] = idsBackup[z];
        strcpy(nomeCompleto[z], nomeCompletoBackup[z]);
        strcpy(email[z], emailBackup[z]);
        strcpy(sexo[z], sexoBackup[z]);
        strcpy(endereco[z], enderecoBackup[z]);
        altura[z] = alturaBackup[z];
        vacina[z] = vacinaBackup[z];
    }
    printf("Restauração concluida com sucesso!");
    menu(tamanho);
}


int recuperaDadosPeloEmail(char emailParaRecuperar[100]){
    int tamanho = retornaTamanhoVetor();
    emailParaRecuperar[strcspn(emailParaRecuperar, "\n")] = '\0';
    for(int k = 0; k<tamanho ;k++){
        if(strcmp(emailParaRecuperar, email[k]) == 0){
            return k;
        }
    }
    return -1;
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

void retornaTamanhoVetorBackup(){
    int contador = 0;
    for(int j=0;j<1000;j++){
        if(alturaBackup[j]>=1){
            contador++;
        } else{
            return contador;
        }
    }
}