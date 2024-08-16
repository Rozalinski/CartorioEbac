#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings
int registro() //Funcao de registar os nomes
{
   char arquivo[40];//Cria��o das vari�veis/string
   char cpf[40];
   char nome [40];
   char sobrenome [40];
   char cargo [40];//Fim da cria��o das string
   
   printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usuario
   scanf("%s", cpf);//armazenando as strings do usu�rio, refere-se as string
   strcpy(arquivo, cpf); //Respons�vel por copiar os valores da string
   
   FILE *file; //cria o arquivo no banco de dados 
   file = fopen(arquivo, "w"); // cria o arquivo e o w significa escrever
   fprintf(file,cpf); //salva o valor da variavel
   fclose(file); // fecha o arquivo 
   
   file=fopen(arquivo, "a"); //cria o arquivo 
   fprintf(file, ",");
   fclose(file);
   
   printf("Digite o nome a ser cadastrado: ");//coleta informacao do usuario
   scanf("%s", nome);//armazena a stringo do usuario, refere-se a string
   file = fopen(arquivo, "a");//criar o arquivo e 
   fprintf(file,nome);
   fclose(file);
   
   file=fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   printf("Digite o sobrenome a ser cadastrado: ");//coletando informa�oes do usu�rio 
   scanf("%s", sobrenome);
   file = fopen(arquivo, "a");
   fprintf(file, sobrenome);
   fclose(file);
   
   file=fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   printf("Digite o cargo a ser cadastrado: ");//coletando informa��es do usuario
   scanf("%s", cargo);//registro da stringo do usu�rio
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
   
   system("pause");
}

int consulta()
{
   
   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
   
   char cpf[40];
   char conteudo[200];
   
   printf("Digite o CPF a ser consultado: ");
   scanf("%s", cpf);
   
   FILE*file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
  {
  	printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
   } 

   while(fgets(conteudo, 200, file) !=NULL)
   {
   	
   	printf("\nEssas s�o as informa��es do usu�rio: ");
   	printf("%s", conteudo);
   	printf("\n\n");
   	
   }


      system("pause");

}


int deletar()
{
	char cpf[40];
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}
int main()
{ 
    int opcao=0; //Definindo variaveis 
    int laco=1;
    
	for(laco=1;laco=1;)
    {
	
    system ("cls");//respons�vel por limpar a tela
     setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
  
  
    printf("#### Cart�rio da EBAC ####\n\n");// inicio do menu
    printf("Escolha a op��o desejada do menu:\n\n");
    printf("\t1 - Registrar nomes\n");
    printf("\t2 - Consultar nomes\n");
    printf("\t3 - Deletar nomes\n"); 
    printf("\t4 - Sair do sistema\n\n");
    printf("Op��o:  ");//fim do menu
   
     
    scanf("%d", &opcao); //armazenando a escolha do usuario
    
    system("cls");
    
    switch(opcao)
    {
    	case 1:
        registro();
  	    break;
  	    
  	    case 2:
  	    consulta();
    	break;
    	
        case 3:
        
    	deletar();
    	break;

        case 4:
        printf("Obrigado por utilizar o sistema\n\n");
        return 0;
        break ;
    	
    	
    	
    	default:
    	printf("Essa op��o n�o est� disponivel\n");
		system("pause");
		break;
        	
  	    	
	}

    
	
}
  
  
  
}
