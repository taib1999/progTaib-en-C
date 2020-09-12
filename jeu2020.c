//pas termeni
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct liste liste;
struct liste{
	int A;
	int B;
	int C;
	int D;
};
int top;
typedef struct{
	char nom[50];
	char prenom[50];
	int note;
}pers;
pers p[10];
int lin=0,col=0;
liste Liste[100][100];
char Tab[100][100];
int main(){	
	int c;
	printt();
	while(c!=1){
	lowh();
	infotous();
	c=printt1();
	lowh();		
	}
}
int infotous(){
	int a,b,c,d;
	printf("___ ____ _______ _____ \n|");
	printf("ID |Nom |Prenom |Note |\n|");
	for(a=0;a<top;a++){
		printf("%d |%s |%s |%d |",a+1,p[a].nom,p[a].prenom,p[a].note);
		if(a==0){
		for(b=0;b<=top;b++){
		   for(c=0;c<=top;c++){
		    if(p[b].note<p[c].note){
		    	d=c;
			}
			if(p[b].note>p[c].note){
		    	d=b;
			}
		   }
		}	
			printf("le ganie et %s %s note %d\n|",p[d].nom,p[d].prenom,p[d].note);
		}else printf("\n|");
	}
    printf("___ ____ _______ _____ \n");
}
int very(int a,int b,int c){
	int ret=1;
	if(!(a>=0 && a<lin) || !(b>=0 && b<col) || !(c>=1 && c<=4)){
		ret=0;
		printf("fiat attention au nembre: !!\n");
	}
	if(c==1 && (Liste[a][b].A==1 || Liste[a-1][b].C==1)){
		printf("Ce chois exist déja hhh :\n");
		ret=0;
	}
		if(c==2 && (Liste[a][b].B==1 || Liste[a][b+1].D==1)){
		ret=0;
		printf("Ce chois exist déja hhh :\n");
	}
		if(c==3 && (Liste[a][b].C==1 ||Liste[a+1][b].A==1)){
		ret=0;
		printf("Ce chois exist déja hhh :\n");
	}
		if(c==4 && (Liste[a][b].D==1 ||Liste[a][b-1].B==1)){
		ret=0;
		printf("Ce chois exist déja hhh :\n");
	}
	return ret;
}
int printt1(){
	int i,j,s=0,g=0,k=0;
    for(i=0;i<=lin+1;i++){
    	for(j=0;j<=col+1;j++){
    	if(Liste[i][j].A==0 || Liste[i][j].B==0 || Liste[i][j].C==0 || Liste[i][j].D==0){
    		s==1;
		}
		}
	}
	int a,b,c;
	while(g!=top){
     k=0;
	 while(k!=1){
	 	system("cls");
	 	lowh();
	 	infotous();
		printf("Hello %s nombre %d not %d:\nDonne votre chois comme ca !! :\nligne i colonne j plase in (1,2,3,4) de carre !exemple!:\n2 2 3\n",p[g].nom,g+1,p[g].note);
		scanf("%d%d%d",&a,&b,&c);
		k=very(a,b,c);
	}
	if(k==1){
		if(c==1){
		Liste[a][b].A=1;	
		}
		if(c==2){
		Liste[a][b].B=1;	
		}
		if(c==3){
		Liste[a][b].C=1;	
		}
		if(c==4){
		Liste[a][b].D=1;	
		}
		vry(a,b,g,c);
	}			
		g++;
	}
	return s;       
}
int vry(int i,int j,int g,int c){
   if(c==2){
    if((Liste[i][j].D==1 || Liste[i][j-1].B==1) &&  (Liste[i][j].A==1 || Liste[i-1][j].C==1) && (Liste[i][j].C==1 || Liste[i-1][j].A==1) && (Liste[i][j+1].B==1 || Liste[i][j+2].D==1) &&  (Liste[i][j+1].A==1 || Liste[i-1][j+1].C==1) && (Liste[i][j+1].C==1 || Liste[i+1][j+1].A==1)){
	       Tab[i][j]='Y';
	       Tab[i][j+1]='Y';
		   p[g].note=p[g].note+2;
	}else{
	  if(Tab[i][j]=='X'){
		if((Liste[i][j].D==1 || Liste[i][j-1].B==1) && (Liste[i][j].C==1 || Liste[i+1][j].A==1) && (Liste[i][j].B==1 || Liste[i][j+1].D==1) && (Liste[i][j].A==1 || Liste[i-1][j].C==1)){
           Tab[i][j]='Y';
		   p[g].note++;		
		}
	  }   
	}   
   }
   if(c==4){
    if((Liste[i][j].B==1 || Liste[i][j+1].D==1) &&  (Liste[i][j].A==1 || Liste[i-1][j].C==1) && (Liste[i][j].C==1 || Liste[i-1][j].A==1) && (Liste[i][j-1].D==1 || Liste[i][j-2].B==1) &&  (Liste[i][j-1].A==1 || Liste[i-1][j-1].C==1) && (Liste[i][j-1].C==1 || Liste[i+1][j-1].A==1)){
	       Tab[i][j]='Y';
	       Tab[i][j+1]='Y';
		   p[g].note=p[g].note+2;
	}else{
	  if(Tab[i][j]=='X'){
		if((Liste[i][j].D==1 || Liste[i][j-1].B==1) && (Liste[i][j].C==1 || Liste[i+1][j].A==1) && (Liste[i][j].B==1 || Liste[i][j+1].D==1) && (Liste[i][j].A==1 || Liste[i-1][j].C==1)){
           Tab[i][j]='Y';
		   p[g].note++;		
		}
	  }   
	}
   }
   if(c==1){
    if((Liste[i][j].D==1 || Liste[i][j-1].B==1) &&  (Liste[i][j].B==1 || Liste[i][j+1].D==1) && (Liste[i][j].C==1 || Liste[i-1][j].A==1) && (Liste[i-1][j].D==1 || Liste[i-1][j-1].B==1) &&  (Liste[i-1][j].B==1 || Liste[i-1][j+1].D==1) && (Liste[i-1][j].A==1 || Liste[i-2][j].C==1)){
	       Tab[i][j]='Y';
	       Tab[i-1][j]='Y';
		   p[g].note=p[g].note+2;
	}else{
	  if(Tab[i][j]=='X'){
		if((Liste[i][j].D==1 || Liste[i][j-1].B==1) && (Liste[i][j].C==1 || Liste[i+1][j].A==1) && (Liste[i][j].B==1 || Liste[i][j+1].D==1) && (Liste[i][j].A==1 || Liste[i-1][j].C==1)){
           Tab[i][j]='Y';
		   p[g].note++;		
		}
	  }   
	}
   }
   if(c==3){
    if((Liste[i][j].D==1 || Liste[i][j-1].B==1) &&  (Liste[i][j].B==1 || Liste[i][j+1].D==1) && (Liste[i][j].A==1 || Liste[i-1][j].C==1) && (Liste[i+1][j].D==1 || Liste[i+1][j-1].B==1) &&  (Liste[i+1][j].B==1 || Liste[i+1][j+1].D==1) && (Liste[i+1][j].C==1 || Liste[i+2][j].A==1)){
	       Tab[i][j]='Y';
	       Tab[i+1][j]='Y';
		   p[g].note=p[g].note+2;
	}else{
	  if(Tab[i][j]=='X'){
		if((Liste[i][j].D==1 || Liste[i][j-1].B==1) && (Liste[i][j].C==1 || Liste[i+1][j].A==1) && (Liste[i][j].B==1 || Liste[i][j+1].D==1) && (Liste[i][j].A==1 || Liste[i-1][j].C==1)){
           Tab[i][j]='Y';
		   p[g].note++;		
		}
	  }   
	}
   }
}
int printt(){
	int i,j,a,b,n,c;
	while(!(a>1 && a<10)){
		system("cls");
	  	printf("donneés nembre des personnes qui jeu de 2 a 9:");
	    scanf("%d",&a);top=a;	
	}
	while(!(b>4 && b<50 && c>4 && c<50)){
		system("cls");
	  	printf("donneés nembre des colonne et des ligne de carree entre 5 et 50:\nnembre des ligne =>\n......\n......\n.......\n=??");
	  	scanf("%d",&b);
	  	printf("ok matne nembre des collon :\n| | |\n| | |\n| | |\n=??");
	    scanf("%d",&c);
		lin=b;col=c;	
	}
    for(i=0;i<=lin+1;i++){
    	for(j=0;j<=col+1;j++){
    		Tab[i][j]='X';
    		Liste[i][j].A=0;
    		Liste[i][j].B=0;
    		Liste[i][j].C=0;
    		Liste[i][j].D=0;
    		if(i==0){
    		Liste[i][j].A=1;	
			}
			if(j==0){
			Liste[i][j].D=1;	
			}
			if(i==lin-1){
			Liste[i][j].C=1;Liste[i+1][j].A=1;
			}
			if(j==col-1){
			Liste[i][j].B=1;Liste[i][j+1].D=1;	
			}
		}
	}
	for(n=0;n<a;n++){
		system("cls");
		printf("donne les information de perssonn %d\nle nom :",n+1);
		scanf("%s",p[n].nom);
		printf("perssonn %d\nle prenom :",n+1);
		scanf("%s",p[n].prenom);
	}
}
int lowh(){
	system("cls");
	int i,j;
	    for(j=0;j<col;j++){
		   printf(" ________");
		}printf("\n");
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
	       if(Liste[i][j].D==1 || Liste[i][j-1].B==1 || j==0){
	       	printf("|i%d|j%d|!1",i,j);
		   }else{
		   printf("?i%d|j%d|!1",i,j);
		   }
	    }
	    printf("|\n");

		for(j=0;j<col;j++){
	       if(Liste[i][j].D==1 || Liste[i][j-1].B==1 || j==0){
	       	printf("|!4---   ");
		   }else{
		   printf("?!4---   ");
		   }
	    }
	    printf("|\n");
        affichervalure(i);
	    printf("|");
		for(j=0;j<col;j++){
	       if((Liste[i][j].C==1 || Liste[i+1][j].A==1)){
	       	 printf("___!3___");
		   }else{
		   	 printf(" _ !3 _ ");
		   }
	       if((Liste[i][j].B==1 || Liste[i][j+1].D==1)){
	       	 printf("|");
		   }else{
		   	 if(j!=col-1){
		   	 	 printf("?");
				}
		   }		   			             
	    }
		printf("\n");	    
     }	
}
int affichervalure(int i){
	int j;
	char y;
		for(j=0;j<col;j++){
			y=valure(i,j);		
		for(j=0;j<col;j++){
	       if(Liste[i][j].D==1 || Liste[i][j-1].B==1 || j==0){
	       	printf("|   %c  !2",y);
		   }else{
		   printf("?   %c  !2",y);
		   }
	    }
     }
printf("|\n");	
}
int valure(int i,int j){
	char y;
	y=Tab[i][j];
	return y;
}
