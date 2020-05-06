#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

char posic [3][3], jogar;
int escolha, computador, vol, vol_comp, vol_vitoria, vol_derrota, vol_empate, vol_set = 1;
bool vitoria = false, derrota = false, empate = false;


void set_before()
{
    posic[0][0] = '1';
    posic[0][1] = '2';
    posic[0][2] = '3';
    posic[1][0] = '4';
    posic[1][1] = '5';
    posic[1][2] = '6';
    posic[2][0] = '7';
    posic[2][1] = '8';
    posic[2][2] = '9';
}

void set_after()
{
    posic[0][0] = '_';
    posic[0][1] = '_';
    posic[0][2] = '_';
    posic[1][0] = '_';
    posic[1][1] = '_';
    posic[1][2] = '_';
    posic[2][0] = ' ';
    posic[2][1] = ' ';
    posic[2][2] = ' ';
}
void caso_empate()
{
    if(posic [0][0] != '_' && posic [0][1] != '_' && posic [0][2] != '_' && posic [1][0] != '_' && posic [1][1] != '_' && posic [1][2]
    != '_' && posic [2][0] != ' ' && posic [2][1] != ' ' && posic [2][2] != ' ')
    {
        empate = true;
    }
}

void caso_vitoria()
{
    if(posic[0][0] == 'X' && posic[0][1] == 'X' && posic [0][2] == 'X')
    {
        vitoria = true;
    }
    if(posic[1][0] == 'X' && posic[1][1] == 'X' && posic [1][2] == 'X')
    {
        vitoria = true;
    }
    if(posic[2][0] == 'X' && posic[2][1] == 'X' && posic [2][2] == 'X')
    {
        vitoria = true;
    }
    if(posic[0][0] == 'X' && posic[1][0] == 'X' && posic [2][0] == 'X')
    {
        vitoria = true;
    }
    if(posic[0][1] == 'X' && posic[1][1] == 'X' && posic [2][1] == 'X')
    {
        vitoria = true;
    }
    if(posic[0][2] == 'X' && posic[1][2] == 'X' && posic [2][2] == 'X')
    {
        vitoria = true;
    }
    if(posic[0][0] == 'X' && posic[1][1] == 'X' && posic [2][2] == 'X')
    {
        vitoria = true;
    }
    if(posic[0][2] == 'X' && posic[1][1] == 'X' && posic [2][0] == 'X')
    {
        vitoria = true;
    }
}

void caso_derrota()
{
    if(posic[0][0] == 'O' && posic[0][1] == 'O' && posic [0][2] == 'O')
    {
        derrota = true;
    }
    if(posic[1][0] == 'O' && posic[1][1] == 'O' && posic [1][2] == 'O')
    {
        derrota = true;
    }
    if(posic[2][0] == 'O' && posic[2][1] == 'O' && posic [2][2] == 'O')
    {
        derrota = true;
    }
    if(posic[0][0] == 'O' && posic[1][0] == 'O' && posic [2][0] == 'O')
    {
        derrota = true;
    }
    if(posic[0][1] == 'O' && posic[1][1] == 'O' && posic [2][1] == 'O')
    {
        derrota = true;
    }
    if(posic[0][2] == 'O' && posic[1][2] == 'O' && posic [2][2] == 'O')
    {
        derrota = true;
    }
    if(posic[0][0] == 'O' && posic[1][1] == 'O' && posic [2][2] == 'O')
    {
        derrota = true;
    }
    if(posic[0][2] == 'O' && posic[1][1] == 'O' && posic [2][0] == 'O')
    {
        derrota = true;
    }
}

void if_escolha()
{
    if(escolha == 1 && posic [0][0] != 'X' && posic [0][0] != 'O')
    {
        posic [0][0] = 'X';
    }else if(escolha == 2 && posic [0][1] != 'X' && posic [0][1] != 'O')
    {
        posic [0][1] = 'X';
    }else if(escolha == 3 && posic [0][2] != 'X' && posic [0][2] != 'O')
    {
        posic [0][2] = 'X';
    }else if(escolha == 4 && posic [1][0] != 'X' && posic [1][0] != 'O')
    {
        posic [1][0] = 'X';
    }else if(escolha == 5 && posic [1][1] != 'X' && posic [1][1] != 'O')
    {
        posic [1][1] = 'X';
    }else if(escolha == 6 && posic [1][2] != 'X' && posic [1][2] != 'O')
    {
        posic [1][2] = 'X';
    }else if(escolha == 7 && posic [2][0] != 'X' && posic [2][0] != 'O')
    {
        posic [2][0] = 'X';
    }else if(escolha == 8 && posic [2][1] != 'X' && posic [2][1] != 'O')
    {
        posic [2][1] = 'X';
    }else if(escolha == 9 && posic [2][2] != 'X' && posic [2][2] != 'O')
    {
        posic [2][2] = 'X';
    }else
    {
        printf("\n\nDigite um valor válido\n\n");
        system("pause");
        vol = 2;
    }
}

void if_escolha_comp()
{
    if(escolha == 1 && posic [0][0] != 'X' && posic [0][0] != 'O')
    {
        posic [0][0] = 'O';
    }else if(escolha == 2 && posic [0][1] != 'X' && posic [0][1] != 'O')
    {
        posic [0][1] = 'O';
    }else if(escolha == 3 && posic [0][2] != 'X' && posic [0][2] != 'O')
    {
        posic [0][2] = 'O';
    }else if(escolha == 4 && posic [1][0] != 'X' && posic [1][0] != 'O')
    {
        posic [1][0] = 'O';
    }else if(escolha == 5 && posic [1][1] != 'X' && posic [1][1] != 'O')
    {
        posic [1][1] = 'O';
    }else if(escolha == 6 && posic [1][2] != 'X' && posic [1][2] != 'O')
    {
        posic [1][2] = 'O';
    }else if(escolha == 7 && posic [2][0] != 'X' && posic [2][0] != 'O')
    {
        posic [2][0] = 'O';
    }else if(escolha == 8 && posic [2][1] != 'X' && posic [2][1] != 'O')
    {
        posic [2][1] = 'O';
    }else if(escolha == 9 && posic [2][2] != 'X' && posic [2][2] != 'O')
    {
        posic [2][2] = 'O';
    }else{
        vol_comp = 2;
    }
}

void corpo ()
{




    printf(" ----------------------------------------------\n");
    printf("|                                              |\n");
    printf("|              JOGO DA VELHA                   |\n");
    printf("|                                              |\n");
    printf(" ----------------------------------------------\n\n\n\n");
    printf("\n\n\n\n\n");

    printf("Escolha um número de 1-9\n\n\n");

    printf("   _%c_|_%c_|_%c_\n", posic[0][0], posic[0][1], posic[0][2]);
    printf("   _%c_|_%c_|_%c_\n", posic[1][0], posic[1][1], posic[1][2]);
    printf("    %c | %c | %c \n\n", posic[2][0], posic[2][1], posic[2][2]);


}


int main()
{


    setlocale(LC_ALL, "Portuguese");

    inicio:
    system("cls");
    setbuf(stdin, NULL);

    srand(time(NULL));
    set_before();

while(vitoria == false && derrota == false)
{
    do{

        system("cls");
        corpo();
        scanf("%d", &escolha);
        setbuf(stdin, NULL);
        if(vol_set == 1)
        {
            set_after();
            vol_set = 2;
        }

        vol = 0;
        if_escolha();

    }while(vol==2);

    system("cls");
    corpo();

    caso_vitoria();

    do
    {
    if(vitoria == true)
    {
        system("cls");
        vol_vitoria = 0;
        corpo();
        printf("\n\n\nVocê ganhou!!!!\n\n");
        printf("Deseja jogar novamente? S/N\n");
        scanf("%c", &jogar);
        setbuf(stdin, NULL);
        jogar = toupper(jogar);
        if(jogar == 'S')
        {
            vitoria = false;
            vol_set = 1;
            goto inicio;
        }else if(jogar == 'N')
        {
            goto fim;
        }else
        {
            printf("Digite uma opção válida\n");
            system("pause");
            vol_vitoria = 1;
        }

    }
    }while(vol_vitoria == 1);

    caso_empate();

    do
    {
    if(empate == true)
    {
        vol_empate = 2;
        printf("O jogo empatou.\n\n");
        printf("Deseja jogar novamente? S/N\n");
        scanf("%c", &jogar);
        setbuf(stdin, NULL);
        jogar = toupper(jogar);
        if(jogar == 'S')
        {
            empate = false;.c
            vol_set = 1;
            goto inicio;
        }else if(jogar == 'N')
        {
            goto fim;
        }else
        {
            printf("Digite uma opção válida\n");
            system("pause");
            vol_empate = 1;
        }
    }
    }while(vol_empate == 1);
    do{
        computador = rand() % 10;
        escolha = computador;
        vol_comp = 1;
        if_escolha_comp();
    }while(vol_comp == 2);


    caso_derrota();


    do
    {
    if(derrota == true)
    {
        system("cls");
        vol_derrota = 0;
        corpo();
        printf("\n\n\nVocê perdeu...\n\n");
        printf("Deseja jogar novamente? S/N\n");
        scanf("%c", &jogar);
        setbuf(stdin, NULL);
        jogar = toupper(jogar);
        if(jogar == 'S')
        {
            derrota = false;
            vol_set = 1;
            goto inicio;
        }else if(jogar == 'N')
        {
            goto fim;
        }else
        {
            printf("Digite uma opção válida\n");
            system("pause");
            vol_derrota = 1;
        }

    }
    }while(vol_derrota == 1);



}
    fim:
    return 0;

    }

