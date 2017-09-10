#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <Teclado.h>


int main( ) {

    extern char codigo[4];
    char adiciona[100];
    char recarga[20];
    int i=0;
    int j=0;
    int k = 0;
    int moedas = 0;
    float saldo = 0;
    float preco;
    bool ok;
    ok = false;
    bool soltar = false;
    int estoque10=20;
    int estoque25=10;
    int estoque5=50;
    int estoque50=20;
    int senha1 = 1234;
    int n = 0;
    int *t;
    char *m;
    float troco;
    bool especial = false;
    bool especial2 = false;
    bool senhaA = false;


    int saldo1 = 12;
    int saldo2 = 12;
    int saldo3 = 12;
    int saldo4 = 12;
    int saldo5 = 12;
    int saldo6 = 12;
    int saldo7 = 12;
    int saldo8 = 12;
    int saldo9 = 12;
    int saldo10 = 12;

    while(1){
        printf( "Bem-vindo! Os produtos disponíveis são:\n");
        printf("Posição         Produto             Preço        Unidades       \n");
        printf("    1           Telefone celular    R$2,00          %d\n", saldo1);
        printf("    2           Salgadinho          R$0,20          %d\n", saldo2);
        printf("    3           Fones de ouvido     R$1,15          %d\n", saldo3);
        printf("    4           Refrigerante        R$0,25          %d\n", saldo4);
        printf("    5           Suco                R$0,75          %d\n", saldo5);
        printf("    6           Tablet              R$2,50          %d\n", saldo6);
        printf("    7           Brinquedo           R$1,10          %d\n", saldo7);
        printf("    8           Chocolate           R$0,40          %d\n", saldo8);
        printf("    9           Jóia                R$1,90          %d\n", saldo9);
        printf("   10           Pen drive           R$1,15          %d\n", saldo10);
        printf("\nSelecione o seu produto ou insira moedas: ");
        if(estoque5 == 0 && estoque10 == 0 && estoque25 == 0 && estoque50 == 0){
            printf("Não há mais moedas disponíveis para troco");
        }
        void DevolveTroco(){
            troco = saldo-preco;

            if(troco>0){
                        printf("Seu troco é de R$%.2f, dividido em:\n", troco);
                    }
                    if(especial2){
                        troco-=0.25;
                    }
                    while (troco-0.5>=-0.01 && estoque50>0){
                        troco-=0.5;
                        estoque50-=1;
                        n+=1;
                    }
                    if(n>0){
                        printf(" -> %d moeda(s) de 50 centavos\n", n);
                    }
                    n=0;
                    if(especial2){
                        n=1;
                    }
                    else if(estoque5 == 0){
                        n=0;
                    }
                    else{
                        while (troco-0.25>=-0.01 && estoque25>0 ){
                            troco-=0.25;
                            estoque25-=1;
                            n+=1;
                        }
                    }
                    if(n>0){
                        printf(" -> %d moeda(s) de 25 centavos\n", n);
                    }
                    n=0;
                    while (troco-0.1>=-0.01 && estoque10>0){
                        troco-=0.1;
                        estoque10-=1;
                        n+=1;
                    }
                    if(n>0){
                        printf(" -> %d moeda(s) de 10 centavos\n", n);
                    }
                    n=0;
                    while (troco-0.05>=-0.01 && estoque5>0){
                        troco-=0.05;
                        estoque5-=1;
                        n+=1;
                    }
                    if(n>0){
                        printf(" -> %d moeda(s) de 5 centavos\n", n);
                    }
                    n=0;
        }

        bool senha(){
            printf("Digite a senha: ");
            int senhad;
            senhad = teclado();
            if(senhad != senha1){
                printf("Senha Rejeitada \n\n");
                senhaA = false;
                return false;
                }
            else{
                printf("Senha Confirmada \n\n");
                senhaA = true;
                return true;
            }
        }

        void DefineSenha(){
            printf("Você selecionou mudar a senha. Digite a nova senha: ");
            int senhanova;
            moedas = 0;
            senhanova = teclado();
            senha1 = senhanova;
            soltar = true;
            printf("a senha nova é %4d\n\n\n\n\n\n\n\n\n", senha1);
            senhaA = false;
            moedas = 0;
        }

        void reestoque(){
            printf("Você selecionou o modo manutenção.\n");
            printf("Há %d moedas de 5 centavos. Selecione quantas moedas deste valor deseja adicionar: ", estoque5);
            moedas = 0;
            moedas = teclado();
            estoque5 += moedas;
            moedas = 0;

            printf("Há %d moedas de 10 centavos. Selecione quantas moedas deste valor deseja adicionar: ", estoque10);

            moedas = teclado();
            estoque10 += moedas;
            moedas = 0;

            printf("Há %d moedas de 25 centavos. Selecione quantas moedas deste valor deseja adicionar: ", estoque25);
            moedas = teclado();
            estoque25 += moedas;
            moedas = 0;

            printf("Há %d moedas de 50 centavos. Selecione quantas moedas deste valor deseja adicionar: ", estoque50);
            moedas = teclado();
            estoque50 += moedas;
            moedas = 0;

            printf("Reestoque realizado.\n");
            printf("Há agora %d moedas de 5 centavos, %d moedas de 10 centavos, %d moedas de 25 centavos e %d moedas de 50 centavos.\n\n\n", estoque5, estoque10, estoque25, estoque50);
            int reest = 0;
            printf("Há %d unidades do produto 1. Selecione quantos deseja adicionar: ", saldo1);
            reest = teclado();
            saldo1 += reest;
            reest = 0; moedas = 0;
            printf("Há %d unidades do produto 2. Selecione quantos deseja adicionar: ", saldo2);
            reest = teclado();
            saldo2 += reest;
            reest = 0; moedas = 0;
            printf("Há %d unidades do produto 3. Selecione quantos deseja adicionar: ", saldo3);
            reest = teclado();
            saldo3 += reest;
            reest = 0; moedas = 0;
            printf("Há %d unidades do produto 4. Selecione quantos deseja adicionar: ", saldo4);
            reest = teclado();
            saldo4 += reest;
            reest = 0; moedas = 0;
            printf("Há %d unidades do produto 5. Selecione quantos deseja adicionar: ", saldo5);
            reest = teclado();
            saldo5 += reest;
            reest = 0; moedas = 0;
            printf("Há %d unidades do produto 6. Selecione quantos deseja adicionar: ", saldo6);
            reest = teclado();
            saldo6 += reest;
            reest = 0; moedas = 0;
            printf("Há %d unidades do produto 7. Selecione quantos deseja adicionar: ", saldo7);
            reest = teclado();
            saldo7 += reest;
            reest = 0; moedas = 0;
            printf("Há %d unidades do produto 8. Selecione quantos deseja adicionar: ", saldo8);
            reest = teclado();
            saldo8 += reest;
            reest = 0; moedas = 0;
            printf("Há %d unidades do produto 9. Selecione quantos deseja adicionar: ", saldo9);
            reest = teclado();
            saldo9 += reest;
            reest = 0; moedas = 0;
            printf("Há %d unidades do produto 10. Selecione quantos deseja adicionar: ", saldo10);
            reest = teclado();
            saldo10 += reest;
            reest = 0; moedas = 0;

        }

        void EntregaProduto(){
            printf("O seu produto foi liberado!");
        }


        void AtualizaEstoque(){
            *t-=1;
        }

        while(ok==false){
            teclado2();
            if (codigo[0]=='1' && codigo[1]=='\n'){
                preco = 2.0;
                printf( "\nVocê selecionou: Telefone Celular, que custa R$%.2f", preco);
                ok = true;
                t = &saldo1;
            }
            else if (codigo[0]=='2' && codigo[1]=='\n'){
                preco = 0.2;
                printf( "\nVocê selecionou: Salgadinho, que custa R$%.2f", preco);
                ok = true;
                t = &saldo2;
            }
            else if (codigo[0]=='3' && codigo[1]=='\n'){
                preco = 1.15;
                printf( "\nVocê selecionou: Fones de ouvido, que custam R$%.2f", preco);
                ok = true;
                t = &saldo3;
            }
            else if (codigo[0]=='4' && codigo[1]=='\n'){
                preco = 0.25;
                printf( "\nVocê selecionou: Refrigerante, que custa R$%.2f", preco);
                ok = true;
                t = &saldo4;
            }
            else if (codigo[0]=='5' && codigo[1]=='\n'){
                preco = 0.75;
                printf( "\nVocê selecionou: Suco, que custa R$%.2f", preco);
                ok = true;
                t = &saldo5;
            }
            else if (codigo[0]=='6' && codigo[1]=='\n'){
                preco = 02.5;
                printf( "\nVocê selecionou: Tablet, que custa R$%.2f", preco);
                ok = true;
                t = &saldo6;
            }
            else if (codigo[0]=='7' && codigo[1]=='\n'){
                preco = 1.1;
                printf( "\nVocê selecionou: Brinquedo, que custa R$%.2f", preco);
                ok = true;
                t = &saldo7;
            }
            else if (codigo[0]=='8' && codigo[1]=='\n'){
                preco = 0.4;
                printf( "\nVocê selecionou: Chocolate, que custa R$%.2f", preco);
                ok = true;
                t = &saldo8;
            }
            else if (codigo[0]=='9' && codigo[1]=='\n'){
                preco = 1.9;
                printf( "\nVocê selecionou: Jóia, que custa R$%.2f", preco);
                ok = true;
                t = &saldo9;
            }
            else if (codigo[0]=='1' && codigo[1] == '0' && codigo[2]=='\n'){
                preco = 1.15;
                printf( "\nVocê selecionou: Pen drive, que custa R$%.2f", preco);
                ok = true;
                t = &saldo10;
            }
            else if(codigo[0] == 'R'){
                senha();
                if(senhaA){
                    reestoque();
                    soltar = true;
                    printf("\n\n\n\n\n\n\n\n\n");
                    senhaA = false;
                    break;
                }
                else{
                    soltar = true;
                    break;

                }
            }
            else if(codigo[0] == 'M'){
                senha();
                if(senhaA){
                    DefineSenha();
                    senhaA = false;
                    break;
                }
                else{
                    soltar = true;
                    break;

                }
            }
            else if(codigo[0] == 'E'){
                printf("Há %d moedas de 5 centfgets(recarga, 20, stdin);avos, %d moedas de 10 centavos, %d moedas de 25 centavos e %d moedas de 50 centavos disponíveis para troco.", estoque5, estoque10, estoque25, estoque50);
                soltar = true;
                printf("\n\n\n\n\n\n\n\n\n");
                break;
            }

            else if(codigo[0] == '+'){
                saldo+=0.1;
                printf("\nVocê já depositou R$%.2f\n", saldo);
            }
            else{
                printf("O código selecionado não corresponde a nenhum produto, digite novamente:");
            }
            if(*t==0){
                printf("\nO produto selecionado está esgotado. Escolha outro:");
                ok = false;
            }
            if(estoque5 == 0){
                float preco100 = preco*100;
                int pre = (int)preco100;
                if(pre%10 != 0){
                    if(estoque25 != 0){
                        printf("\nO estoque de moedas de 5 centavos para troco não é suficiente para este produto. Se você deseja continuar com a compra, deve depositar pelo menos 25 centavos a mais para que o troco possa ser dado em moedas de 25 centavos.");
                        especial = true;
                        especial2 = true;
                    }
                    else{
                        printf("\nO estoque de moedas para troco não é suficiente para este produto. \nEscolha outro:");
                        ok = false;
                    }
                }
            }
        }

        printf("\n");

        while((saldo<preco && soltar == false) || especial == true){
            printf("Insira moedas:");
            teclado2();
            if(codigo[0] == '+'){
                saldo+=0.1;
                printf("\nVocê já depositou R$%.2f\n", saldo);
            }
            else if(codigo[0] == 'x'){
                soltar = true;

                if(saldo>0){
                    printf("Você cancelou a operação. Sua(s) %g moeda(s) de 10 centavos serão devolvidas.\n\n\n\n\n", saldo/0.1);
                }
                else{
                    printf("Operação cancelada.\n\n\n\n\n");
                }
            }
            if(especial==true && saldo>preco){
                if(saldo-preco>=0.25){
                    especial = false;
                }
                else{
                    printf("Você já tem saldo suficiente, porém ainda não há moedas para fazer seu troco. Continue.\n");
                }
            }
        }

        while (soltar == false){
            printf("Você já depositou dinheiro suficiente. Pressione 's' para soltar o produto.");
            teclado2();
            if(codigo[0] == '+'){
                saldo+=0.1;
                printf("\nVocê já depositou R$");
                printf("%.2f\n", saldo);
            }
            else if(codigo[0] == 'x'){
                soltar = true;
                if(saldo>0){
                    printf("Você cancelou a operação. Suas %g moedas de 10 centavos serão devolvidas.\n\n\n\n\n", saldo/0.1);
                }
                else{
                    printf("Operação cancelada.\n\n\n\n\n");
                }
            }
            else if(codigo[0] == 's'){
                soltar = true;
                estoque10 += (saldo/0.1);
                EntregaProduto();
                DevolveTroco();
                AtualizaEstoque();
                printf("\nObrigado por utilizar esta máquina!\n\n\n\n\n\n\n");

            }
        }
    saldo = 0;
    soltar = false;
    ok = false;
    }
    return 0;
}


