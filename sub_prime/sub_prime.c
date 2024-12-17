#include <stdio.h>
#define MAXBANCOS 20
#define MAXDEBENTURES 20

int main() {
 	
	int reservas[MAXBANCOS] = {0}; 
	int dividas_descritas[MAXDEBENTURES][3] = {0};
	//cada divida eh da forma D C V, em que: D = Devedor, C = Credor e V = Valor
	
	int flag; //se acender essa flag, algum banco ficou negativado
    int bancos = 1;
	int debentures = 1;
	
	while(bancos != 0 && debentures != 0) {
		flag = 0;
		
		//entrada da quantidade de bancos
		scanf("%d", &bancos);
		scanf("%d", &debentures);
		
		//entrada das reservas de cada banco
		for (int i = 0; i < bancos; i++) {
			scanf("%d", reservas + i);
		}
		
		//entrada das dividas a serem quitadas
		for (int i = 0; i < debentures; i++) {
			scanf("%d", &dividas_descritas[i][0]);
			scanf("%d", &dividas_descritas[i][1]);
			scanf("%d", &dividas_descritas[i][2]);
		}
		
		//reducao em uma unidade do identificador do banco
		//pra facilitar minha vida
		for (int i = 0; i < debentures; i++) {
			dividas_descritas[i][0]--;
			dividas_descritas[i][1]--;
		}
		
		//subtrai da reserva do banco o valor da sua divida
		//soma ao a reserva do banco o valor de seu debenture
		for (int i = 0; i < debentures; i++) {
			reservas[dividas_descritas[i][0]] -= dividas_descritas[i][2];
			reservas[dividas_descritas[i][1]] += dividas_descritas[i][2];
		}
		
		//aciona a flag
		for (int i = 0; i < bancos; i++) {
			if (reservas[i] < 0)
				flag += 1;
		}
		
		if (flag && bancos != 0 && debentures != 0) 
			printf("N\n");
		if (!flag && bancos != 0 && debentures != 0)
			printf("S\n");
	}
	
    return 0;
}