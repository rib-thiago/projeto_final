void limpabuffer (void) {
    char c;
    while ((c = getchar()) != '\n' );
}

void display (void)
{

    printf("\33[H\33[2J");
    printf("Menu:\n");
    printf("1 - Cadastrar Vinho\n2 - Retirar Vinho para ocasião especial\n");
    printf("3 - Retirar Vinho para ocasião NÃO especial\n4 - Listar cinco aquições mais antigas\n");
    printf("5 - Listar cinco últimas aquisições\n6 - Exibir catálogo completo?\n7 - Sair\n");

}