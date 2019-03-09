#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


  typedef struct
  {
  	int personelno;
    char isim[100];
    char TCKimlikNo[11];
    char telefon[11];
    char eposta[100];
    char adres[100];
  }personel;//328

void kayitEkle()
{
char secim;

   FILE *fp1;
   personel personell;
   if((fp1=fopen("personel.txt","ab+"))==NULL)
   {
       printf("Dosya a��lamad�");
       exit(1);
   }
   printf("\nPersonel kay�t giri�i\n");
   printf("��kmak i�in personel no yu  0 giriniz.\n\n");

   while(1==1)
   {

   	  printf("personel no:");
   	  scanf("%d",&personell.personelno);
       if(personell.personelno==0)
       {
       	 break;
	   }
	    printf("Personel isim:");
   	   scanf("%s",personell.isim);

   	   printf("Personel TC kimlik no:");
   	   scanf("%s",personell.TCKimlikNo);

   	   printf("Personel telofon:");
   	   scanf("%s",personell.telefon);

   	   printf("Personel eposta:");
   	   scanf("%s",personell.eposta);

   	   printf("Personel adres:");
   	   scanf("%s",personell.adres);

   	 if(fwrite(&personell,sizeof(personell),1,fp1) !=1)
        {
            printf("yazma hatasi");
            exit(1);
        }
        printf("\n");

   }
   fclose(fp1);
   printf("Yeni kay�t i�in Y ye , ana menuye d�nmek i�in herhangi bir tu�a bas�n.   ");
   secim=getch();
   if(secim== 'y' || secim =='Y')
   {
   	system("CLS");
   	 kayitEkle();
   }
   else
   {
   	system("CLS");
   	 main();
   }

}

void personelListele()
{
	char secim;
	FILE *fp2;
	personel personell2;
        fp2=fopen("personel.txt","rb");
        system("cls");
        printf("\n*****PERSONEL L�STES�*****\n");
         while(fread(&personell2, sizeof(personell2), 1, fp2))
      {
      	 printf("\nPersonel no:%d",personell2.personelno);
         printf("\nPersonel isim:%s",personell2.isim);

   	     printf("\nPersonel TC kimlik no:%s",personell2.TCKimlikNo);

   	     printf("\nPersonel telefon:%s",personell2.telefon);

   	     printf("\nPersonel eposta:%s",personell2.eposta);

   	     printf("\nPersonel adres:%s",personell2.adres);
         printf("\n");
      }
      fclose(fp2);
       printf("Ana menuye d�nmek i�in herhangi bir tu�a bas�n. ��k�� yapmak i�in E ye bas�n");
       secim=getch();
  if(secim=='E' || secim =='e')
  {
  	fclose(fp2);
  }
   else
   {
   	system("CLS");
   	 main();
   }

}
void KaydiDuzenle()
{
char secim,aranan[20];
       FILE *fp1;
     personel personell;
     fp1=fopen("personel.txt","rb+");
    int bulundu=0;
    printf("aranacak kayd�n ismi? :");
    scanf("%s",&aranan);

	while(fread(&personell, sizeof(personell), 1, fp1))
      {
      	if(strcmp(aranan,personell.isim)==0)
      	{
      		bulundu=1;
	   printf("Personel isim:");
   	   scanf("%s",personell.isim);

   	   printf("Personel TC kimlik no:");
   	   scanf("%s",personell.TCKimlikNo);

   	   printf("Personel telofon:");
   	   scanf("%s",personell.telefon);

   	   printf("Personel eposta:");
   	   scanf("%s",personell.eposta);

   	   printf("Personel adres:");
   	   scanf("%s",personell.adres);
   	   break;     
       }
       
      
  }
   
        if(bulundu==0)
        {
        	printf("Arad���n�z kay�t bulunamad�...\nTekrar aramak i�in T ye ana menu i�in herhngi bir tu�a bas�n�z.");
	         secim=getch();
           if(secim== 't' || secim =='T')
             {
               	system("CLS");
              	KaydiDuzenle();
              }
             else
            {
              	system("CLS");
             	 main();
            }
	
		}
		else
		{
			
		fseek(fp1,ftell(fp1)-328,SEEK_SET);
        fwrite(&personell,sizeof(personell),1,fp1);
        fclose(fp1);
             
		      printf("Yeni kay�t d�zenlemek i�in Y ye , ana menuye d�nmek i�in herhangi bir tu�a bas�n.");
             secim=getch();
           if(secim== 'y' || secim =='Y')
               {
               	system("CLS");
              	KaydiDuzenle();
              }
             else
            {
              	system("CLS");
             	 main();
            }
        }
    }
void tcKayitBulma()
{
      char secim;
      char aranan[11];
      int bulundu = 0;
      FILE *fp2;
      personel personell2;
      fp2=fopen("personel.txt","rb+");
    printf("aranacak kayd�n tc si ? :");
    scanf("%s",&aranan);
   
	while(fread(&personell2, sizeof(personell2), 1, fp2))
      {
      	if(strcmp(aranan,personell2.TCKimlikNo)==0)
      	{
          bulundu=1;
         printf("\nPersonel isim:%s",personell2.isim);

   	     printf("\nPersonel TC kimlik no:%s",personell2.TCKimlikNo);

   	     printf("\nPersonel telefon:%s",personell2.telefon);

   	     printf("\nPersonel eposta:%s",personell2.eposta);

   	     printf("\nPersonel adres:%s",personell2.adres);
         printf("\n");
         
         break;
	  }

      }
      fclose(fp2);
       if(bulundu==0)
        {
        	printf("Arad���n�z kay�t bulunamad�...\nTekrar aramak i�in T ye ana menu i�in herhngi bir tu�a bas�n�z.");
	         secim=getch();
           if(secim== 't' || secim =='T')
             {
               	system("CLS");
              	tcKayitBulma();
              }
             else
            {
              	system("CLS");
             	 main();
            }
	
		}
		else{
     printf("Yeni arama icin A ya , ana menuye d�nmek i�in herhangi bir tu�a bas�n.   ");
   secim=getch();
   if(secim== 'A' || secim =='a')
   {
   	system("CLS");
   	 tcKayitBulma();
   }
   else
   {
   	system("CLS");
   	 main();
   }
}
}
void IsimKayitBulma()
{
        char aranan[50];
       char secim;
       int bulundu = 0;
      FILE *fp2;
      personel personell2;
      fp2=fopen("personel.txt","rb+");
    printf("aranacak kayd�n ismi ? :");
    scanf("%s",&aranan);
  
	while(fread(&personell2, sizeof(personell2), 1, fp2))
      {
      	if(strcmp(aranan,personell2.isim)==0)
      	{

         printf("\nPersonel isim:%s",personell2.isim);

   	     printf("\nPersonel TC kimlik no:%s",personell2.TCKimlikNo);

   	     printf("\nPersonel telefon:%s",personell2.telefon);

   	     printf("\nPersonel eposta:%s",personell2.eposta);

   	     printf("\nPersonel adres:%s",personell2.adres);
         printf("\n");
        
         break;
	  }
  }
  fclose(fp2);
  if(bulundu==0)
        {
        	printf("Arad���n�z kay�t bulunamad�...\nTekrar aramak i�in T ye ana menu i�in herhngi bir tu�a bas�n�z.");
	         secim=getch();
           if(secim== 't' || secim =='T')
             {
               	system("CLS");
              	IsimKayitBulma();
              }
             else
            {
              	system("CLS");
             	 main();
            }
	
		}
		else{
   printf("Yeni arama i�in A ya , ana men�ye d�nmek i�in herhangi bir tu�a bas�n�z.");
   secim=getch();
     
      if(secim== 'A' || secim =='a')
      {
      	system("cls");
      	IsimKayitBulma();
	  }
	  else
	  {
	  	system("cls");
	  	menu();
	  }
}
}
void KayitSil()
{
	FILE *eski,*yeni;
    personel personelll;
     int bulundu = 0;
    char secim;
    char aranan[50];
    
    printf("Aranacak kayd�n TC si:");
    scanf("%s",aranan);
    
	 eski=fopen("personel.txt","rb");
    
	if(eski==NULL)
    printf("dosay a��lamad�");
    
    
    rewind(eski);
	yeni=fopen("yeni.txt","wb");
    if(yeni==NULL)
     printf("dosya okuanamd� yeni");    
    while(fread(&personelll,sizeof(personel),1,eski))
    {
    	if(strcmp(aranan,personelll.TCKimlikNo)==0)
    	{ 
		    printf("\nPersonel no:%d",personelll.personelno);
         printf("\nPersonel isim:%s",personelll.isim);

   	     printf("\nPersonel TC kimlik no:%s",personelll.TCKimlikNo);

   	     printf("\nPersonel telefon:%s",personelll.telefon);

   	     printf("\nPersonel eposta:%s",personelll.eposta);

   	     printf("\nPersonel adres:%s",personelll.adres);
         printf("\n");
		}
		else
		{
		   fwrite(&personelll,sizeof(personelll),1,yeni);
		}
	}
		
	fclose(yeni);
	fclose(eski);
	
	remove("personel.txt");
	rename("yeni.txt","personel.txt");

	if(bulundu=0)
	{
		printf("\nAranan kay�t bulunamad� !\n\n");
		 printf("Yeniden silme i�lemi i�in Y ye bas�n�z. Ana menuye d�nemk i�in herhangi bir tu�a bas�n�z. ");	
	     secim=getch();
		 if(secim=='Y' || secim=='y'){
		 system("cls");
	     KayitSil();}
	     else{
		 system("cls");
	     menu();}
	}
	else
	{
	     printf("Kay�t silindi.");
		 printf("Yeniden silme i�lemi i�in Y ye bas�n�z. Ana menuye d�nemk i�in herhangi bir tu�a bas�n�z. ");	
	     secim=getch();
		 if(secim=='Y' || secim=='y'){
		 system("cls");
	     KayitSil();}
	     else{
		 system("cls");
	     menu();}
	}

}
void Cikis()
{
    exit(1);
}
void menu()
{

    int secim;
    printf("\n*********Personel kay�t sistemi*******\n");

    printf("\n1-KAYIT EKLE");
    printf("\n2-PERSONEL L�STELE");
    printf("\n3-KAYDI D�ZENLE");
    printf("\n4-TC K�ML�K NO �LE KAYIT BUL");
    printf("\n5-�S�M �LE KAYIT BUL");
    printf("\n6-KAYIT S�L");
    printf("\n7-�IKI�");
    printf("\n\nB�R ��LEM SE��N�Z:");

    scanf("%d",&secim);

    if(secim == 1)
    kayitEkle();

    else if(secim == 2)
     personelListele();
    else if (secim==3)
     KaydiDuzenle();
     else if (secim==4)
        tcKayitBulma();
    else if(secim==5)
        IsimKayitBulma();
    else if(secim == 6)
    KayitSil();
    else if(secim==7)
        Cikis();
    else
    {
        system("CLS");
        printf("Gecersiz secim yaptiniz!");
        main();

    }


}
int main()
{
    setlocale(LC_ALL, "Turkish");


     menu();
    return 0;
}
