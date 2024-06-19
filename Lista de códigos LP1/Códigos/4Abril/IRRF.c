/**
 * @file irrf_calculadora.c
 * @brief Programa para calcular impostos (IRRF e INSS) para pessoas físicas e jurídicas.
 *
 * Este programa permite calcular o imposto de renda (IRRF) e a contribuição para o INSS
 * com base no salário bruto e outras informações financeiras fornecidas pelo usuário.
 * Para pessoas jurídicas, são oferecidas opções de tributação simplificada de acordo com
 * o tipo de empresa e regime tributário.
 *
 * Desenvolvido por Bruno Costa Queiroz (202410509) em abril de 2024.
 */

#include <stdio.h>

/**
 * @brief Função principal para calcular o IRRF e INSS para pessoas físicas e jurídicas.
 *
 * A função solicita ao usuário informações financeiras necessárias para o cálculo do IRRF
 * e INSS. Para pessoas físicas, são calculados os descontos de acordo com faixas de renda
 * e deduções permitidas. Para pessoas jurídicas, são oferecidos diferentes regimes de
 * tributação e cálculos de imposto de renda (IRPJ) de acordo com o faturamento e despesas.
 */
void irrf() {
    short int tpes;

    printf("Bem-vindo(a) à calculadora de impostos. Insira:\n1 - \x1b[36mPessoa física\x1b[37m;\n2 - \x1b[36mPessoa jurídica\x1b[37m;\n");
    scanf("%hd", &tpes);
    while (tpes != 1 && tpes != 2) {
        printf("Opção inválida. Tente novamente.\n");
        scanf("%hd", &tpes);
    }

    if (tpes == 1) {
        // Declaração de variáveis para o cálculo do IRRF e INSS para pessoas físicas
        float renda, par1, par2, par3, par4, parI1, parI2, parI3, parI4, dep_val, transp, alim, saud, cred, desc, inss, fgts, val_base, ded1, ded2, ded3, ded4, dedI1, dedI2, dedI3, irrf, liquido;
        short int dependentes, conf;

        // Solicitação de informações financeiras
        printf("\nPor favor, digite o seu salário bruto em R$: ");
        scanf("%f", &renda);
        while (renda <= 0) {
            printf("Valor inválido. Tente novamente.\n");
            scanf("%f", &renda);
        }

        printf("\nDigite o valor do vale transporte em R$: ");
        scanf("%f", &transp);
        while (transp < 0) {
            printf("Valor inválido. Tente novamente.\n");
            scanf("%f", &transp);
        }

        printf("\nDigite o valor do vale alimentação em R$: ");
        scanf("%f", &alim);
        while (alim < 0) {
            printf("Valor inválido. Tente novamente.\n");
            scanf("%f", &alim);
        }

        printf("\nDigite o valor do auxílio saúde em R$: ");
        scanf("%f", &saud);
        while (saud < 0) {
            printf("Valor inválido. Tente novamente.\n");
            scanf("%f", &saud);
        }

        printf("\nDigite o valor de outras rendas tributáveis em R$: ");
        scanf("%f", &cred);
        while (cred < 0) {
            printf("Valor inválido. Tente novamente.\n");
            scanf("%f", &cred);
        }

        printf("\nDigite o valor de outros descontos em R$: ");
        scanf("%f", &desc);
        if (desc < 0) {
            printf("Valor inválido. Tente novamente.\n");
            scanf("%f", &desc);
        }

        printf("\nDigite a quantidade de dependentes: ");
        scanf("%hd", &dependentes);
        if (dependentes < 0) {
            printf("Número inválido. Tente novamente.\n");
            scanf("%hd", &dependentes);
        }

        printf("\nVocê deseja usar os valores padrões \x1b[33m(Fev/2024)\x1b[37m?\n0 - Não;\n1 - Sim\n");
        scanf("%hd", &conf);
        while (conf != 1 && conf != 0) {
            printf("Resposta inválida. Tente novamente.\n");
            scanf("%hd", &conf);
        }

        if (conf == 1) {
            par1 = 2259.2, par2 = 2826.65, par3 = 3751.06, par4 = 4664.68, parI1 = 1412, parI2 = 2666.68, parI3 = 4000.03, parI4 = 7786.02, dep_val = 189.59;
        } else {
            printf("\nDigite os valores da base de cálculo mensal do INSS na ordem crescente em R$. Pressione \x1b[33m'Enter'\x1b[37m para confirmar o valor\n");
            scanf("%f %f %f %f", &parI1, &parI2, &parI3, &parI4);
            while (parI1 < 0 || parI1 >= parI2 || parI2 >= parI3 || parI3 >= parI4) {
                printf("Algum valor digitado é inválido. Tente novamente.\n");
                scanf("%f %f %f %f", &parI1, &parI2, &parI3, &parI4);
            }

            printf("\nDigite os valores da base de cálculo mensal do IRRF na ordem crescente em R$. Pressione \x1b[33m'Enter'\x1b[37m para confirmar o valor\n");
            scanf("%f %f %f %f", &par1, &par2, &par3, &par4);
            while (par1 < 0 || par1 >= par2 || par2 >= par3 || par3 >= par4) {
                printf("Algum valor digitado é inválido. Tente novamente.\n");
                scanf("%f %f %f %f", &par1, &par2, &par3, &par4);
            }

            printf("\nDigite o valor do desconto de dependentes em R$: \n");
            scanf("%f", &dep_val);
            while (dep_val < 0) {
                printf("Valor inválido. Tente novamente.\n");
                scanf("%f", &dep_val);
            }
        }

        // Cálculo do INSS de acordo com faixas de renda
        ded1 = par1 * 0.075;
        ded2 = (par2 * 0.075) + ded1;
        ded3 = (par3 * 0.075) + ded2;
        ded4 = (par4 * 0.05) + ded3;

        dedI1 = parI1 * 0.015;
        dedI2 = (parI2 * 0.03) + dedI1;
        dedI3 = (parI3 * 0.02) + dedI2;

        if (renda <= parI1) {
            inss = renda * 0.075;
        } else if (renda > parI1 && renda <= parI2) {
            inss = (renda * 0.09) - dedI1;
        } else if (renda > parI2 && renda <= parI3) {
            inss = (renda * 0.12) - dedI2;
        } else if (renda > parI3 && renda <= parI4) {
            inss = (renda * 0.14) - dedI3;
        } else {
            inss = (parI4 * 0.14) - dedI3;
        }

        // Cálculo da base de cálculo mensal
        dep_val = dep_val * dependentes;
        val_base = (renda + cred) - inss - dep_val - transp - alim - saud - desc;

        // Cálculo do IRRF de acordo com faixas de renda
        printf("\nEsse é o valor da base de cálculo mensal: \x1b[33mR$%.2f\x1b[37m\n", val_base);
        printf("\nTabela do IRRF:\n");
        printf("Até \x1b[33mR$%.2f\x1b[37m, é isento de imposto de renda;\n", par1);
        printf("De \x1b[33mR$%.2f\x1b[37m até \x1b[33mR$%.2f\x1b[37m, é aplicada a taxa de \x1b[33m7.5%%\x1b[37m;\n", par1, par2);
        printf("De \x1b[33mR$%.2f\x1b[37m até \x1b[33mR$%.2f\x1b[37m, é aplicada a taxa de \x1b[33m15%%\x1b[37m;\n", par2, par3);
        printf("De \x1b[33mR$%.2f\x1b[37m até \x1b[33mR$%.2f\x1b[37m, é aplicada a taxa de \x1b[33m22.5%%\x1b[37m;\n", par3, par4);
        printf("Acima de \x1b[33mR$%.2f\x1b[37m, é aplicada a taxa de \x1b[33m27.5%%\x1b[37m;\n", par4);

        if (val_base <= par1) {
            irrf = 0;
        } else if (val_base > par1 && val_base <= par2) {
            irrf = (val_base * 0.075) - dedI1;
        } else if (val_base > par2 && val_base <= par3) {
            irrf = (val_base * 0.15) - dedI2;
        } else if (val_base > par3 && val_base <= par4) {
            irrf = (val_base * 0.225) - dedI3;
        } else {
            irrf = (val_base * 0.275) - dedI4;
        }

        printf("\nIRRF é igual a: \x1b[33mR$%.2f\x1b[37m\n", irrf);
        liquido = renda - inss - irrf - transp - alim - saud - desc;
        printf("\nSeu salário líquido é: \x1b[33mR$%.2f\x1b[37m\n", liquido);
    }

    else if (tpes == 2) {
        // Declaração de variáveis para o cálculo do IRRF e INSS para pessoas jurídicas
        float rece, deped, desc, inss, liquido;
        short int desc, veicu, transp, alim, saud, cred, dpdr, irrf, flrp;

        // Solicitação de informações financeiras
        printf("\nDigite o faturamento anual em R$: ");
        scanf("%f", &rece);
        while (rece <= 0) {
            printf("Valor inválido. Tente novamente.\n");
            scanf("%f", &rece);
        }

        printf("\nDigite o valor do vale transporte em R$: ");
        scanf("%f", &transp);
        while (transp < 0) {
            printf("Valor inválido. Tente novamente.\n");
            scanf("%f", &transp);
        }

        printf("\nDigite o valor do vale alimentação em R$: ");
        scanf("%f", &alim);
        while (alim < 0) {
            printf("Valor inválido. Tente novamente.\n");
            scanf("%f", &alim);
        }

        printf("\nDigite o valor do auxílio saúde em R$: ");
        scanf("%f", &saud);
        while (saud < 0) {
            printf("Valor inválido. Tente novamente.\n");
            scanf("%f", &saud);
        }

        printf("\nDigite o valor de outras rendas tributáveis em R$: ");
        scanf("%f", &cred);
        while (cred < 0) {
            printf("Valor inválido. Tente novamente.\n");
            scanf("%f", &cred);
        }

        printf("\nDigite o valor de outros descontos em R$: ");
        scanf("%f", &desc);
        if (desc < 0) {
            printf("Valor inválido. Tente novamente.\n");
            scanf("%f", &desc);
        }

        printf("\nDigite a quantidade de dependentes: ");
        scanf("%hd", &dependentes);
        if (dependentes < 0) {
            printf("Número inválido. Tente novamente.\n");
            scanf("%hd", &dependentes);
        }

        printf("\nDigite o valor de bens móveis e de transporte em R$: ");
        scanf("%hd", &transp);
        if (transp < 0) {
            printf("Valor inválido. Tente novamente.\n");
            scanf("%hd", &transp);
        }

        printf("\nDigite o valor dos investimentos em imóveis em R$: ");
        scanf("%hd", &imov);
        if (imov < 0) {
            printf("Valor inválido. Tente novamente.\n");
            scanf("%hd", &imov);
        }

        printf("\nVocê deseja usar os valores padrões \x1b[33m(Fev/2024)\x1b[37m?\n0 - Não;\n1 - Sim\n");
        scanf("%hd", &conf);
        while (conf != 1 && conf != 0) {
            printf("Resposta inválida. Tente novamente.\n");
            scanf("%hd", &conf);
        }

        if (conf == 1) {
            rece = 2259.2, deped = 2826.65, desc = 3751.06, inss = 4664.68, liquido = 7786.02, desc = 1412, veicu = 2666.68, transp = 4000.03, alim = 7786.02, saud = 189.59, cred = 5.0, dpdr = 20.0, irrf = 0.0, flrp = 10.0;
        } else {
            printf("\nDigite os valores da base de cálculo mensal do INSS na ordem crescente em R$. Pressione \x1b[33m'Enter'\x1b[37m para confirmar o valor\n");
            scanf("%f %f %f %f", &parI1, &parI2, &parI3, &parI4);
            while (parI1 < 0 || parI1 >= parI2 || parI2 >= parI3 || parI3 >= parI4) {
                printf("Algum valor digitado é inválido. Tente novamente.\n");
                scanf("%f %f %f %f", &parI1, &parI2, &parI3, &parI4);
            }

            printf("\nDigite os valores da base de cálculo mensal do IRRF na ordem crescente em R$. Pressione \x1b[33m'Enter'\x1b[37m para confirmar o valor\n");
            scanf("%f %f %f %f", &par1, &par2, &par3, &par4);
            while (par1 < 0 || par1 >= par2 || par2 >= par3 || par3 >= par4) {
                printf("Algum valor digitado é inválido. Tente novamente.\n");
                scanf("%f %f %f %f", &par1, &par2, &par3, &par4);
            }

            printf("\nDigite o valor do desconto de dependentes em R$: \n");
            scanf("%f", &dep_val);
            while (dep_val < 0) {
                printf("Valor inválido. Tente novamente.\n");
                scanf("%f", &dep_val);
            }
        }

        // Cálculo do INSS de acordo com faixas de renda
        ded1 = par1 * 0.075;
        ded2 = (par2 * 0.075) + ded1;
        ded3 = (par3 * 0.075) + ded2;
        ded4 = (par4 * 0.05) + ded3;

        dedI1 = parI1 * 0.015;
        dedI2 = (parI2 * 0.03) + dedI1;
        dedI3 = (parI3 * 0.02) + dedI2;

        if (renda <= parI1) {
            inss = renda * 0.075;
        } else if (renda > parI1 && renda <= parI2) {
            inss = (renda * 0.09) - dedI1;
        } else if (renda > parI2 && renda <= parI3) {
            inss = (renda * 0.12) - dedI2;
        } else if (renda > parI3 && renda <= parI4) {
            inss = (renda * 0.14) - dedI3;
        } else {
            inss = (parI4 * 0.14) - dedI3;
        }

        // Cálculo da base de cálculo mensal
        dep_val = dep_val * dependentes;
        val_base = (renda + cred) - (desc + dep_val + transp + alim + saud + dpdr + veicu + flrp + imov);

        // Impostos e deduções no cálculo da base de cálculo mensal
        printf("\nPara renda anual de \x1b[33mR$%.2f\x1b[37m, é aplicada a taxa de \x1b[33m7.5%%\x1b[37m;\n", parI1, parI2);
        printf("De \x1b[33mR$%.2f\x1b[37m até \x1b[33mR$%.2f\x1b[37m, é aplicada a taxa de \x1b[33m9%%\x1b[37m;\n", parI2, parI3);
        printf("De \x1b[33mR$%.2f\x1b[37m até \x1b[33mR$%.2f\x1b[37m, é aplicada a taxa de \x1b[33m12%%\x1b[37m;\n", parI3, parI4);
        printf("Acima de \x1b[33mR$%.2f\x1b[37m, é aplicada a taxa de \x1b[33m14%%\x1b[37m;\n", parI4);

        if (val_base <= par1) {
            irrf = 0;
        } else if (val_base > par1 && val_base <= par2) {
            irrf = (val_base * 0.075) - dedI1;
        } else if (val_base > par2 && val_base <= par3) {
            irrf = (val_base * 0.09) - dedI2;
        } else if (val_base > par3 && val_base <= par4) {
            irrf = (val_base * 0.12) - dedI3;
        } else {
            irrf = (val_base * 0.14) - dedI4;
        }

        printf("\nIRRF é igual a: \x1b[33mR$%.2f\x1b[37m\n", irrf);
        liquido = renda - inss - irrf - transp - alim - saud - desc;
        printf("\nSeu salário líquido é: \x1b[33mR$%.2f\x1b[37m\n", liquido);
    }

    else {
        printf("\nOpção inválida. Tente novamente.\n");
    }

    return 0;
}