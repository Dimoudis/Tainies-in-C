#include <stdio.h>
#include <stdlib.h>

/*
ena struct Movie tha xei mesa titlo, diarkeia se sec, ton skinotheti, tin timi tis tainias
rwtaw ton user poses taineies exei
gemisma 
display ola
mo timwn olwn twn tainiwn
mo seconds gia taineis pou kostizoun panw apo 3eurw
mo timwn gia tis tainies pou skinothetise o dimoudis
zitaw ton titlo mia tainias kai na ektipwnw tin diarkeia kai tin timi tis h alliws den vrethike
na ektipwsw oles tis tainies tou dimoudi
sorting asc ws pros tin timi
ksana display ola
*/

struct Movie{
	char titlos[15];
	int sec;
	char skinothetis[15];
	double timi;
};

void gemisma(struct Movie t_list[],int tainies);
void display(struct Movie t_list[],int tainies);
void mo_timwn_olwn(struct Movie t_list[],int tainies);
void mo_sec_autes_panw_apo_3eurw(struct Movie t_list[],int tainies);
void mo_timwn_gia_tou_dim(struct Movie t_list[],int tainies);
void searching(struct Movie t_list[],int tainies);
void display_tainies_dim(struct Movie t_list[],int tainies);
void sorting_asc(struct Movie t_list[],int tainies);

int main() {
	
	int tainies;
	printf("Poses tainies exeis? ");
	scanf("%i",&tainies);
	struct Movie t_list[tainies];
	
	gemisma(t_list,tainies);
	display(t_list,tainies);
	mo_timwn_olwn(t_list,tainies);
	mo_sec_autes_panw_apo_3eurw(t_list,tainies);
	mo_timwn_gia_tou_dim(t_list,tainies);
	searching(t_list,tainies);
	display_tainies_dim(t_list,tainies);
	sorting_asc(t_list,tainies);
	printf("\nOi plirofories kathe tainias me afksousa seira:\n\n");
	display(t_list,tainies);

	return 0;
}

void gemisma(struct Movie t_list[],int tainies){
	char titlos[15];
	int sec;
	char skinothetis[15];
	double timi;
	int i;
	for (i=0; i<tainies; i++){
		struct Movie movie;
		printf("Dwse ton titlo tis %ihs tainias: ",i+1);
		scanf("%s",&titlos);
		strcpy(movie.titlos,titlos);
		printf("Dwse tin diarkeia tis %ihs tainias (se sec): ",i+1);
		scanf("%i",&sec);
		movie.sec=sec;
		printf("Dwse ton skinotheti tis %ihs tainias: ",i+1);
		scanf("%s",&skinothetis);
		strcpy(movie.skinothetis,skinothetis);
		printf("Dwse tin timi tis %ihs tainias (se eurw): ",i+1);
		scanf("%lf",&timi);
		movie.timi=timi;
		t_list[i]=movie;
	}
}

void display(struct Movie t_list[],int tainies){
	int i;
	printf("\n");
	for (i=0; i<tainies; i++){
		printf("%i. -> skinothetis: %s, diarkeia: %i sec, timi: %.1f eurw\n",i+1,t_list[i].skinothetis,t_list[i].sec,t_list[i].timi);
	}
	printf("\n");
}

void mo_timwn_olwn(struct Movie t_list[],int tainies){
	int i;
	int sum=0;
	double mo;
	for (i=0; i<tainies; i++){
		sum=sum+t_list[i].timi;
	}
	if (tainies==0){
		mo=0;
	}
	else{
		mo=(double)sum/tainies;
	}
	printf("O mo twn timwn olwn twn tainiwn einai %.2f eurw\n",mo);
}

void mo_sec_autes_panw_apo_3eurw(struct Movie t_list[],int tainies){
	int i;
	int sum=0;
	double mo;
	int count=0;
	for (i=0; i<tainies; i++){
		if (t_list[i].timi>3){
			count++;
			sum=sum+t_list[i].sec;
		}	
	}
	if (count==0){
		mo=0;
	}
	else{
		mo=(double)sum/count;
	}
	printf("O mo twn second gia tis tainies panw apo 3 eurw einai %.2f seconds\n",mo);
}

void mo_timwn_gia_tou_dim(struct Movie t_list[],int tainies){
	int count=0;
	int sum=0;
	double mo;
	for (int i=0; i<tainies; i++){
		if (strcmp("dimoudis",t_list[i].skinothetis)==0){
			sum=sum+t_list[i].timi;
			count++;
		}
	}
	if (count==0){
		mo=0;
	}
	else{
		mo=(double)sum/count;
	}
	printf("O mo twn timwn gia tis tainies me skinotheti ton dimoudi einai %.2f\n",mo);
}

void searching(struct Movie t_list[],int tainies){
	int i;
	int pos=-1;
	char titlos[15];
	printf("\nDwse ton titlo tis tainias: ");
	scanf("%s",&titlos);
	for (i=0; i<tainies; i++){
		if (strcmp(titlos,t_list[i].titlos)==0){
			pos=i;
			printf("H tainia me titlo %s exei diarkeia %i seconds kai kostizei %.2f eurw\n\n",t_list[pos].titlos,t_list[pos].sec,t_list[pos].timi);
		}	
	}
	if (pos==-1){
		printf("Den vrethike tainia me auton ton titlo!!!\n\n");
	} 
}

//na ektipwsw oles tis tainies tou dimoudi
void display_tainies_dim(struct Movie t_list[],int tainies){
	int i;
	int count=0;
	printf("\nTainies me skinotheti ton dimoudi:\n");
	for (i=0; i<tainies; i++){
		if (strcmp("dimoudis",t_list[i].skinothetis)==0){
			count++;
			printf("%i. -> %s\n",i+1,t_list[i].titlos);
		}
	}
	if (count==0){
		printf("Den yparxei tainia me skinotheti ton dimoudi!!!\n\n");
	} 
}

//sorting asc ws pros tin timi
void sorting_asc(struct Movie t_list[],int tainies){
	int i,j;
	struct Movie temp;
	for (i=0; i<tainies-1; i++){
		for (j=0; j<tainies-i-1; j++){
			if (t_list[j].timi>t_list[j+1].timi){
				//swap movie
				temp=t_list[j];
				t_list[j]=t_list[j+1];
				t_list[j+1]=temp;
			}
		}
	}
}



