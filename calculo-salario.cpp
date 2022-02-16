#include <stdio.h>
#include <stdlib.h>

int main () {
	//declaração das variáveis
    float sl_bruto, sl_liquido, vl_outros_descontos, inss, irrf, tx_irrf, deducao_irrf, vl_pensao, vl_dependentes;
    int dependentes;
    char op_outros_descontos, op_pensao;
    char descontado[20];
    
    //textos de apresentação
    printf("||| CALCULADORA DE SALARIO LIQUIDO |||\n");
    printf("||| Para trabalhadores CLT: Empregado, empregado domestico e trabalhador avulso |||\n");
    printf("||| Luiz Baidum (julho de 2021) |||\n");
    
	//inicio do programa
    printf("\nInsira o salario bruto: ");
    scanf("%f", &sl_bruto); //definição do salário bruto
    
    do {

    printf("\nExiste algum outro desconto? (y/n) Exemplo: planos de saude, odonto, adiantamento de salario, etc. > ");
    scanf(" %c", &op_outros_descontos); //difinição da existência de descontos

    if (op_outros_descontos == 'y') {
        printf("\nPor favor, insira o valor desse desconto: ");
        scanf("%f", &vl_outros_descontos);
        
        printf("\nDigite em uma palavra a que o desconto se refere: ");
        scanf("%s", &descontado);

    } else if (op_outros_descontos == 'n') {
        printf("\nJa que nao existem descontos, vamos continuar...");
        vl_outros_descontos=0;

    } else {
        printf("\nReveja o comando digitado.\n");
    } } while ((op_outros_descontos != 'y') && (op_outros_descontos != 'n'));
    
    //definição do valor de INSS a ser descontado
    if (sl_bruto <= 1100.00) {
    	inss=sl_bruto*0.075;
    	
	} else if ((sl_bruto > 1100.00) && (sl_bruto <= 2203.48)) {
		inss=(1100.00*0.075)+((sl_bruto-1100.00)*0.09);
		
	} else if ((sl_bruto > 2203.48) && (sl_bruto <= 3305.22)) {
		inss=(1100.00*0.075)+((2203.48-1100.00)*0.09)+((sl_bruto-2203.48)*0.12);
		
	} else if ((sl_bruto > 3305.22) && (sl_bruto <= 6433.57)) {
		inss=(1100.00*0.075)+((2203.48-1100.00)*0.09)+((3305.22-2203.48)*0.12)+((sl_bruto-3305.22)*0.14);
		
	} else if (sl_bruto > 6433.57) {
		inss=(1100.00*0.075)+((2203.48-1100.00)*0.09)+((3305.22-2203.48)*0.12)+((6433.57-3305.22)*0.14); }
		
	//definição dos dependentes, pensão e valores de IRRF descontados
	deducao_irrf = 0;
	
	do {
		
	printf("\nSobre o IRRF: Existe pagamento de pensao alimenticia? (y/n) > ");
	scanf(" %c", &op_pensao);
	
	if (op_pensao =='y') {
		printf("\nQual e o valor pago por mes? > ");
		scanf("%f", &vl_pensao);
		
	} else if (op_pensao == 'n') {
        printf("\nContinuando...");
        vl_pensao=0;

    } else {
        printf("\nReveja o comando digitado.\n");
    } } while ((op_pensao != 'y') && (op_pensao != 'n'));
	
	printf("\nSobre o IRRF: Existem dependentes? Se sim, informe a quantidade; Se nao, informe '0'; > ");
	scanf("%d", &dependentes);
	if (dependentes == 0) {
		vl_dependentes = 0;
	} else {
		vl_dependentes = dependentes * 189.59;
	}
	
	//definição da taxa do IRRF e da dedução
	tx_irrf=0;
	deducao_irrf=0;
	
	if ((sl_bruto-inss-vl_pensao-vl_dependentes)<1903.99) {
		tx_irrf=1;
		irrf=0;
	
	} else if ((((sl_bruto-inss-vl_pensao-vl_dependentes)>=1903.99)) && ((sl_bruto-inss-vl_pensao-vl_dependentes)<=2826.65)) {
		tx_irrf=0.075;
		deducao_irrf=142.80;
		
	} else if (((sl_bruto-inss-vl_pensao-vl_dependentes)>=2826.66) && ((sl_bruto-inss-vl_pensao-vl_dependentes)<=3751.05)) {
		tx_irrf=0.15;
		deducao_irrf=354.80;
		
	} else if (((sl_bruto-inss-vl_pensao-vl_dependentes)>=3751.06) && ((sl_bruto-inss-vl_pensao-vl_dependentes)<=4664.68)) {
		tx_irrf=0.225;
		deducao_irrf=636.13;
		
	} else if ((sl_bruto-inss-vl_pensao-vl_dependentes)>=4664.69) {
		tx_irrf=0.275;
		deducao_irrf=869.36;
	}
		
	irrf=((sl_bruto-inss-vl_pensao-vl_dependentes)*tx_irrf)-deducao_irrf;
	
	if ((sl_bruto-inss-vl_pensao-vl_dependentes)<1903.99) {
		irrf=0; }//repetição do primeiro IF para definir IRRF como sendo 0;
					
	//calculo e apresentação do salário líquido
	sl_liquido = sl_bruto-vl_outros_descontos-inss-irrf;
	
	printf("\n||RESULTADO...||\n");
	
	printf("\nOutro desconto = %.2f, referente a %s", vl_outros_descontos, descontado);
		
	printf("\n\ndesconto de INSS = %.2f", inss);
	
	printf("\n\ndesconto de IRRF = %.2f", irrf);
	
    printf("\n\nSalario liquido = %.2f\n", sl_liquido);
    
    system ("pause");
    
    return 0;
    
}
