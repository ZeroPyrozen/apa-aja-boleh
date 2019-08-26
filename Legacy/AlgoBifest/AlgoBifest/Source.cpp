#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<Windows.h>
#include<conio.h>

struct User
{
    char fullName[100];
    char passWord[100];
    char userName[100];
    char gender[20];
    char phone[20];
}user[1000],temp,profile;
struct Barang
{
    char kotaAsal[100],kotaTujuan[100],kode[100];
    char namaBarang[100];
    int repack,asuransi;
    int checkOut;
    int status,jumlah;
    float panjang,lebar,tinggi;
    float berat;
}barang[1000];
//Misc
void spacing() 
{
    //Tujuan : Untuk membuat 25 spasi diawal program
    int i;
    for(i=1; i<=25; i++)
        printf("\n");
}
void title()
{
    //Tujuan: Untuk menampilkan Judul Menu Utama
    //Preview
    /* 
    ______           __               ________                   __    _       __    __ 
   / ____/___ ______/ /____  _____   /_  __/ /_  ____ _____     / /   (_)___ _/ /_  / /_
  / /_  / __ `/ ___/ __/ _ \/ ___/    / / / __ \/ __ `/ __ \   / /   / / __ `/ __ \/ __/
 / __/ / /_/ (__  ) /_/  __/ /       / / / / / / /_/ / / / /  / /___/ / /_/ / / / / /_  
/_/    \__,_/____/\__/\___/_/       /_/ /_/ /_/\__,_/_/ /_/  /_____/_/\__, /_/ /_/\__/  
                                                                     /____/             */
    Sleep(100);
    printf("    ______           __               ________                   __    _       __    __ ");
    printf("\n");
    Sleep(100);
    printf("   / ____/___ ______/ /____  _____   /_  __/ /_  ____ _____     / /   (_)___ _/ /_  / /_");
    printf("\n");
    Sleep(100);
    printf("  / /_  / __ `/ ___/ __/ _ \\/ ___/    / / / __ \\/ __ `/ __ \\   / /   / / __ `/ __ \\/ __/");
    printf("\n");
    Sleep(100);
    printf(" / __/ / /_/ (__  ) /_/  __/ /       / / / / / / /_/ / / / /  / /___/ / /_/ / / / / /_  ");
    printf("\n");
    Sleep(100);
    printf("/_/    \\__,_/____/\\__/\\___/_/       /_/ /_/ /_/\\__,_/_/ /_/  /_____/_/\\__, /_/ /_/\\__/  ");
    printf("\n");
    Sleep(100);
    printf("                                                                     /____/             ");
    printf("\n");
}

//For User Struct
void openFile(int *counter)
{
    int j = 0;
    FILE *fp = fopen("user.txt","r");
    if(fp)
    {
        while(fscanf(fp,"%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n",&user[j].fullName,&user[j].userName,&user[j].passWord,&user[j].gender,&user[j].phone)!=EOF)
        {
            //printf("%s#%s#%s#%s#%s\n",user[j].fullName,user[j].userName,user[j].passWord,user[j].gender,user[j].phone);
            j++;
        }
        (*counter) = j;
        fclose(fp);
    }
    else
    {
        perror("Can't Open User.txt: ");
        getchar();
        exit(1);
    }
}
void writeFile(int *counter)
{
    int i = (*counter),j;
    FILE *ft = fopen("user.txt","w");
    if(ft)
    {
        for(j=0; j<i; j++)
        {
            fprintf(ft,"%s#%s#%s#%s#%s\n",user[j].fullName,user[j].userName,user[j].passWord,user[j].gender,user[j].phone);
        }
        fclose(ft);
    }
}
void createUser(char userName[])
{
    strcat(userName,".txt");
    FILE *u = fopen(userName,"w+");
    fclose(u);
}
int isUserExist(int *counter, char Username[])
{
    openFile(counter);
    int i = (*counter),j;
    for(j=0; j<i; j++)
    {
        if(strcmp(user[j].userName,Username) == 0)
        {
            return -1;
        }
    }
    return 0;
}
int isPassExist(int *counter, char Password[])
{
    openFile(counter);
    int i = (*counter),j;
    for(j=0; j<i; j++)
    {
        if(strcmp(user[j].passWord,Password) == 0)
        {
            return -1;
        }
    }
    return 0;
}
void registerUser(int *counter)
{
    char userName[100],passWord[100], fullName[100], gender[20], phone[20];
    int flag=0,pjgAngka,x=(*counter),i; 
    printf("_ __                                          _ _ _             \n");
    printf("' )  )             _/_         _/_            ' ) ) )               \n");
    printf(" /--' _  _,  o _   /  __  __.  /  o __ ____    / / / _  ____  . .\n");
    printf("/  \\_</_(_)_<_/_)_<__/ (_(_/|_<__<_(_)/ / <_  / ' (_</_/ / <_(_/_\n");
    printf("         /|                                                      \n");
    printf("        |/                                                       \n\n\n\n\n\n\n\n\n\n");
    do
    {
        flag=0;
        printf("Insert your Full Name [5-30 Characters]: ");
        scanf("%[^\n]",&fullName);
        fflush(stdin);
        if(strlen(fullName)>30 || strlen(fullName)<5)
        {
            flag=0;
        }
        else
        {
            if(strcmpi(fullName,"cancel")==0)
            {
                printf("Cancelling user creation...\nPress Enter to Continue...");
                return;
            }
            else
            {
                flag=1;
            }
        }
    }while(flag==0);
    do
    {
        flag=0;
        printf("Insert your UserName [3-30 Characters]: ");
        scanf("%[^\n]",&userName);
        fflush(stdin);
        if(strlen(userName)>30 || strlen(userName)<3)
        {
            flag=0;
        }
        else
        {
            if(isUserExist(counter,userName)==0)
                flag=1;
            else if(strcmpi(userName,"cancel")==0)
            {
                printf("Username can't be \"Cancel\"\n");
                flag=0;
            }
            else
            {
                printf("This Username has already taken!\n");
                flag=0;
            }
        }
    }while(flag==0);
        do
    {
        flag=0;
        printf("Insert your password [3-30 Characters]: ");
        scanf("%[^\n]",&passWord);
        fflush(stdin);
        if(strlen(passWord)>30 || strlen(passWord)<3)
        {
            flag=0;
        }
        else
        {
            flag=1;
        }
    }while(flag==0);
    do
    {
        flag=0;
        printf("Insert your gender [Male|Female] [Case Sensitive]: ");
        scanf("%[^\n]",&gender);
        fflush(stdin);
        if(strcmp("Male",gender)==0||strcmp("Female",gender)==0)
            flag=1;
        else
            flag=0;
    }while(flag==0);
    do
    {
        flag=0;
        printf("Insert your phone number [Must start with '+62' or '08'] : ");
        scanf("%s",&phone);
        fflush(stdin);
        pjgAngka = strlen(phone);
        if(pjgAngka>13||pjgAngka<11)
            flag=0;
        else
        {
            if((phone[0]=='+'&&phone[1]=='6'&&phone[2]=='2')||(phone[0]=='0'&&phone[1]=='8'))
            {
                flag=1;
                for(i=0; i<pjgAngka; i++)
                {
                    if(i==0)
                    {
                        continue;
                    }
                    else
                    {
                        if(!isdigit(phone[i]))
                        {
                            flag=0;
                            break;
                        }
                    }
                }
            }
            else
            {
                flag=0;
            }
        }
    }while(flag==0);
    printf("Successfully Registering New Account!\n");
    strcpy(user[x].fullName, fullName);
    strcpy(user[x].userName,userName);
    strcpy(user[x].gender,gender);
    strcpy(user[x].passWord,passWord);
    strcpy(user[x].phone,phone);
    x++;
    (*counter) = x;
	writeFile(counter);
	createUser(userName);
}

//For Barang Struct
void openUser(int *isi, char userName[])
{
    int i=0;
    char userName1[100];
    strcpy(userName1,userName);
    strcat(userName1,".txt");
    FILE *fu = fopen(userName1,"r");
    if(fu)
    {
		while(fscanf(fu,"%[^#]#%[^#]#%[^#]#%d#%d#%d#%d#%d#%f#%f#%f#%f\n",
			&barang[i].namaBarang,&barang[i].kotaAsal,&barang[i].kotaTujuan,
			&barang[i].repack,&barang[i].asuransi,&barang[i].checkOut,&barang[i].status,&barang[i].jumlah,
			&barang[i].panjang,&barang[i].lebar,&barang[i].tinggi,&barang[i].berat) !=EOF)
        {
            i++;
        }
        (*isi) = i;
        fclose(fu);
    }

}
void writeUser(int *isi, char userName[])
{
    int j = (*isi),i;
    char temp[100];
    strcpy(temp,userName);
    strcat(temp,".txt");
    FILE *ff = fopen(temp,"w+");
    if(ff)
    {
        for(i=0; i<j; i++)
        {
			fprintf(ff,"%s#%s#%s#%d#%d#%d#%d#%d#%.2f#%.2f#%.2f#%.2f\n",
                barang[i].namaBarang,barang[i].kotaAsal,barang[i].kotaTujuan,
                barang[i].repack,barang[i].asuransi,barang[i].checkOut,barang[i].status,barang[i].jumlah,
				barang[i].panjang,barang[i].lebar,barang[i].tinggi,barang[i].berat);
        }
        fclose(ff);
    }
}

//User Menu
void addNewItem(int *jumlah)
{
    int i,flag,x=(*jumlah);
    system("cls");
    char kode[10];
    char yesNo1[10],yesNo2[10];
    spacing();
    do
    {
        flag=0;
        printf("Input Item Name [3-20 Chars] : ");
        scanf("%[^\n]",&barang[x].namaBarang);
        fflush(stdin);
        if(strlen(barang[x].namaBarang)>20||strlen(barang[x].namaBarang)<3)
        {
            flag=0;
        }
        else
        {
            flag=1;
        }
    }while(flag==0);
    do
    {
        flag=0;
        printf("Input Item's Weight [Kg] : ");
        scanf("%f",&barang[x].berat);
        fflush(stdin);
        if(barang[x].berat>0&&barang[x].berat<=100)
            flag=1;
    }while(flag==0);
    do
    {
        flag=0;
        printf("Input Item Amount : ");
        scanf("%d",&barang[x].jumlah);
        fflush(stdin);
        if(barang[x].jumlah>0)
            flag=1;
    }while(flag==0);
    do
    {
        flag=0;
        printf("Input Item Dimension [Height|Width|Lenght] [centimetres] : ");
        scanf("%f %f %f",&barang[x].tinggi,&barang[x].lebar,&barang[x].panjang);
        fflush(stdin);
        if(barang[x].tinggi*barang[x].lebar*barang[x].panjang !=0)
            flag=1;
    }while(flag==0);
    do
    {
        flag=0;
        printf("Does it need extra repack? [Yes|No]\n>> ");
        scanf("%s",&yesNo1);
        fflush(stdin);
        if(strcmpi(yesNo1,"yes"))
        {
            barang[x].repack = 1;
            flag=1;
        }
        else if(strcmpi(yesNo1,"no"))
        {
            barang[x].repack = 0;
            flag=1; 
        }
        else
        {
            printf("Choose \"Yes\" or \"No\" only!\n");
            flag=0;
        }
    }while(flag==0);
    do
    {
        flag=0;
        printf("Does it need insurance? [Yes|No]\n>> ");
        scanf("%s",&yesNo2);
        fflush(stdin);
        if(strcmpi(yesNo2,"yes"))
        {
            barang[x].asuransi = 1;
            flag=1;
        }
        else if(strcmpi(yesNo2,"no"))
        {
            barang[x].asuransi = 0;
            flag=1; 
        }
        else
        {
            printf("Choose \"Yes\" or \"No\" only!\n");
            flag=0;
        }
    }while(flag==0);
    do
    {
        flag=0;
        printf("Insert City Departure Address [From]: ");
        scanf("%[^\n]",&barang[x].kotaAsal);
        fflush(stdin);
        if(strlen(barang[x].kotaAsal)>3)
            flag=1;
    }while(flag==0);
    do
    {
        flag=0;
        printf("Insert City Destination Address [To]: ");
        scanf("%[^\n]",&barang[x].kotaTujuan);
        fflush(stdin);
        if(strlen(barang[x].kotaTujuan)>3)
            flag=1;
    }while(flag==0);
    barang[x].checkOut = 0;
    barang[x].status = 0;
    //strcat(barang[x].kode,"FTL");
    //itoa(x,kode,10);
    //strcat(barang[x].kode,kode);
    x++;
    (*jumlah) = x;
    printf("Successfully Add New Item!\nPress Enter to Continue");
    getchar();
}
void viewCurrentCart(int *jumlah, int *cek)
{
    system("cls");
    int x = (*jumlah),i,j=1,space;
    printf("Data : %d\n",x);
    printf("|%-4s|%30s|%-20s|%-25s|%-20s|%-20s|%-10s|\n","No.","Item Name","Amount","Dimension","Weight","Insurance","Repacking");
    for(space=0; space<137; space++)
	{
		printf("=");
	}
	printf("\n");
	for(i=0; i<x; i++)
    {
        if(barang[i].checkOut==0)
        {
            if(barang[i].asuransi==1&&barang[i].repack==1)
                printf("|%-4d|%30s|%-20d|%-20.2f cm^3|%-17.0f Kg|%-20s|%-10s|\n",j,
				barang[i].namaBarang,barang[i].jumlah,barang[i].panjang*barang[i].lebar*barang[i].tinggi,barang[i].berat,"Yes","Yes");
            else if(barang[i].asuransi==1&&barang[i].repack==0)
                printf("|%-4d|%30s|%-20d|%-20.2f cm^3|%-17.0f Kg|%-20s|%-10s|\n",j,barang[i].namaBarang,barang[i].jumlah,barang[i].panjang*barang[i].lebar*barang[i].tinggi,barang[i].berat,"Yes","No");
            else if(barang[i].asuransi==0&&barang[i].repack==1)
                printf("|%-4d|%30s|%-20d|%-20.2f cm^3|%-17.0f Kg|%-20s|%-10s|\n",j,barang[i].namaBarang,barang[i].jumlah,barang[i].panjang*barang[i].lebar*barang[i].tinggi,barang[i].berat,"No","Yes");
            else
                printf("|%-4d|%30s|%-20d|%-20.2f cm^3|%-17.0f Kg|%-20s|%-10s|\n",j,barang[i].namaBarang,barang[i].jumlah,barang[i].panjang*barang[i].lebar*barang[i].tinggi,barang[i].berat,"No","No");
            j++;
        }
        else
        {
            continue;
        }
    }
	(*cek) = j;
	for(space=0; space<137; space++)
	{
		printf("=");
	}
	printf("\n");
}
void viewProfile(char userLogin[])
{
    FILE *fp = fopen("user.txt","r");
    if(fp)
    {
        while(fscanf(fp,"%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n",&profile.fullName,&profile.userName,&profile.passWord,&profile.gender,&profile.phone)!=EOF)
        {
            if(strcmp(userLogin,profile.userName)==0)
            {
                break;
            }
        }
        fclose(fp);
        system("cls");
        printf("Full Name   : %-30s\n",profile.fullName);
        printf("Username    : %-30s\n",profile.userName);
        printf("Password    : %-30s\n",profile.passWord);
        printf("Gender      : %-10s\n",profile.gender);
        printf("Phone Num   : %-20s\n",profile.phone);
        getchar();
    }
}
void deleteCart(int *jumlah, int key)
{
	int counter, am=(*jumlah);
	for(counter=key; counter<am-1; counter++)
	{
		barang[counter] = barang[counter+1];
	}
}
void checkOut(int *jumlah, int *cek)
{
	int amount = (*jumlah),i,banyakBarang=0,repack=50000,asuransi=500000;
	float volumeBarang=0, hargaTotal = 0;
	char yesNo[100];
	viewCurrentCart(jumlah,cek);
	for(i=0; i<amount; i++)
	{
		banyakBarang=0;
		volumeBarang=0;
		if(barang[i].checkOut == 0)
		{
			if(barang[i].repack==0&&barang[i].asuransi==0)
			{
				banyakBarang = barang[i].jumlah;
				volumeBarang = barang[i].lebar*barang[i].tinggi*barang[i].panjang;
				hargaTotal+=banyakBarang*volumeBarang*50+barang[i].berat*500+0+0;
			}
			else if(barang[i].repack==1&&barang[i].asuransi==1)
			{
				banyakBarang = barang[i].jumlah;
				volumeBarang = barang[i].lebar*barang[i].tinggi*barang[i].panjang;
				hargaTotal+=banyakBarang*volumeBarang*50+barang[i].berat*500+repack+asuransi;
			}
			else if(barang[i].repack==0&&barang[i].asuransi==1)
			{
				banyakBarang = barang[i].jumlah;
				volumeBarang = barang[i].lebar*barang[i].tinggi*barang[i].panjang;
				hargaTotal+=banyakBarang*volumeBarang*50+barang[i].berat*500+0+asuransi;
			}
			else if(barang[i].repack==1&&barang[i].asuransi==0)
			{
				banyakBarang = barang[i].jumlah;
				volumeBarang = barang[i].lebar*barang[i].tinggi*barang[i].panjang;
				hargaTotal+=banyakBarang*volumeBarang*50+barang[i].berat*500+repack+0;
			}
		}
	}
	printf("Total Price : Rp %.0f\n\n",hargaTotal);
	do
	{
		printf("Are you sure you want to deliver this item? [Yes|No]\n>> ");
		scanf("%s",&yesNo);
		fflush(stdin);
	}while(strcmpi(yesNo,"Yes")!=0&&strcmpi(yesNo,"No")!=0);
	if(strcmpi(yesNo,"Yes")==0)
	{
		for(i=0; i<amount; i++)
		{
			barang[i].checkOut = 1;
		}
		printf("Successfully added items in transaction!\n");
		getchar();
	}
	else
	{
		printf("Purging all items in cart...\nPress Enter to Continue...");
		for(i=0; i<amount; i++)
		{
			if(barang[i].checkOut==0)
			{
				deleteCart(&amount,i);
				amount--;
			}
		}
		getchar();
	}
	(*jumlah) = amount;
}
void viewMyTransaction(int *jumlah, char userName[])
{
	int i,j=1,x=(*jumlah),space;
	//printf("User : %s\n",userName);
	/*printf("|%-4s|%30s|%-20s|%-25s|%-20s|%-20s|%-10s|%-15s|\n","No.","Item Name","Amount","Dimension","Weight","Insurance","Repacking","Status");
    for(space=0; space<137; space++)
	{
		printf("=");
	}
	printf("\n");*/
	for(i=0; i<x; i++)
    {
        if(barang[i].checkOut==1)
        {
           if(barang[i].status==1)
		   {
			   if(barang[i].asuransi==1&&barang[i].repack==1)
			   {
					printf("|%-4d|%30s|%-20d|%-20.2f cm^3|%-17.0f Kg|%-20s|%-10s|%15s\n",j,
				barang[i].namaBarang,barang[i].jumlah,barang[i].panjang*barang[i].lebar*barang[i].tinggi,barang[i].berat,"Yes","Yes","Accepted");
			   }
			   else if(barang[i].repack==0&&barang[i].asuransi==1)
			   {
					printf("|%-4d|%30s|%-20d|%-20.2f cm^3|%-17.0f Kg|%-20s|%-10s|%15s\n",j,
				barang[i].namaBarang,barang[i].jumlah,barang[i].panjang*barang[i].lebar*barang[i].tinggi,barang[i].berat,"No","Yes","Accepted");
			   }
			   else if(barang[i].repack==1&&barang[i].asuransi==0)
			   {
					printf("|%-4d|%30s|%-20d|%-20.2f cm^3|%-17.0f Kg|%-20s|%-10s|%15s\n",j,
				barang[i].namaBarang,barang[i].jumlah,barang[i].panjang*barang[i].lebar*barang[i].tinggi,barang[i].berat,"Yes","No","Accepted");
			   }
			   else if(barang[i].repack==0&&barang[i].asuransi==0)
			   {
					printf("|%-4d|%30s|%-20d|%-20.2f cm^3|%-17.0f Kg|%-20s|%-10s|%15s\n",j,
				barang[i].namaBarang,barang[i].jumlah,barang[i].panjang*barang[i].lebar*barang[i].tinggi,barang[i].berat,"No","No","Accepted");
			   }
		   }
		   else
		   {
				if(barang[i].asuransi==1&&barang[i].repack==1)
			   {
					printf("|%-4d|%30s|%-20d|%-20.2f cm^3|%-17.0f Kg|%-20s|%-10s|%15s\n",j,
				barang[i].namaBarang,barang[i].jumlah,barang[i].panjang*barang[i].lebar*barang[i].tinggi,barang[i].berat,"Yes","Yes","Pending");
			   }
			   else if(barang[i].repack==0&&barang[i].asuransi==1)
			   {
					printf("|%-4d|%30s|%-20d|%-20.2f cm^3|%-17.0f Kg|%-20s|%-10s|%15s\n",j,
				barang[i].namaBarang,barang[i].jumlah,barang[i].panjang*barang[i].lebar*barang[i].tinggi,barang[i].berat,"No","Yes","Pending");
			   }
			   else if(barang[i].repack==1&&barang[i].asuransi==0)
			   {
					printf("|%-4d|%30s|%-20d|%-20.2f cm^3|%-17.0f Kg|%-20s|%-10s|%15s\n",j,
				barang[i].namaBarang,barang[i].jumlah,barang[i].panjang*barang[i].lebar*barang[i].tinggi,barang[i].berat,"Yes","No","Pending");
			   }
			   else if(barang[i].repack==0&&barang[i].asuransi==0)
			   {
					printf("|%-4d|%30s|%-20d|%-20.2f cm^3|%-17.0f Kg|%-20s|%-10s|%15s\n",j,
				barang[i].namaBarang,barang[i].jumlah,barang[i].panjang*barang[i].lebar*barang[i].tinggi,barang[i].berat,"No","No","Pending");
			   }
		   }
			j++;
		}
        else
        {
            continue;
        }
		
    }
	printf("\n");
//    getchar();

}
void userMenu(char userLogin[], int *temp)
{
    int jumlah=0,cek=0;
    //char menu;
    int menu;
    //Baca Data User Tersebut

    do
    {
        openUser(&jumlah,userLogin);
        system("cls");
        printf("1. Add New Item\n");
        printf("2. Checkout\n");
        printf("3. View My Current Cart\n");
        printf("4. View My Transaction\n");
        printf("5. View Profile\n");
        printf("6. Log Out\n");
        printf("Choose : ");
        scanf("%d",&menu);
        fflush(stdin);
        switch(menu)
        {
        case 1:
            addNewItem(&jumlah);
            writeUser(&jumlah,userLogin);
			cek++;
            break;
        case 2:
			if(cek==0)
			{
				printf("There is no item in your cart, make an order first!\n");
				getchar();
			}
			else
			{
				checkOut(&jumlah,&cek);
				writeUser(&jumlah,userLogin);
				cek=0;
			}
			break;
        case 3:
			if(cek==0)
			{
				printf("There is no item in your cart, make an order first!\n");
				getchar();
			}
			else
			{
				openUser(&jumlah,userLogin);
				viewCurrentCart(&jumlah,&cek);
				getchar();
			}
			break;
        case 4:
			if(jumlah==0)
			{
				printf("There is no transaction, make sure to checkout first!\n");
				getchar();
			}
			else
			{
				openUser(&jumlah,userLogin);
				printf("|%-4s|%30s|%-20s|%-25s|%-20s|%-20s|%-10s|%-15s|\n","No.","Item Name","Amount","Dimension","Weight","Insurance","Repacking","Status");
				for(int space=0; space<152; space++)
				{
					printf("=");
				}
				printf("\n");
				viewMyTransaction(&jumlah,userLogin);
				for(int space=0; space<152; space++)
				{
					printf("=");
				}
				printf("\n");
				getchar();
			}
			break;
        case 5:
            viewProfile(userLogin);
            break;
        }
    }while(menu!=6);
    writeUser(&jumlah,userLogin);
    (*temp) = 1;
    printf("\nLogging User Out...\nPress Enter to Continue");
	getchar();
}

//Admin Menu
void openAllUser()
{
	int j = 0,x;
    FILE *fp = fopen("user.txt","r");

    if(fp)
    {
		
        while(fscanf(fp,"%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n",
			&user[j].fullName,
			&user[j].userName,&user[j].passWord,
			&user[j].gender,&user[j].phone)!=EOF)
        {
            j++;
        }
	
        //(*counter) = j;
        fclose(fp);
		printf("|%-4s|%-30s|%-30s|%20s|%20s|%-15s|\n","No.","Full Name","Username","Password","Gender","Phone Number");
		puts("");
		for(x=0; x<j;x++)
		{
			 printf("|%-4d|%-30s|%-30s|%20s|%20s|%-15s|\n",x+1,user[x].fullName,user[x].userName,user[x].passWord,user[x].gender,user[x].phone);
		}
    }
    else
    {
        perror("Can't Open User.txt: ");
        getchar();
        exit(1);
    }
}
void viewAllTrans(int *counter,int *isi)
{
	int count;
	openFile(counter);
	for(count=0; count<(*counter); count++)
	{
		openUser(isi,user[count].userName);
		viewMyTransaction(isi,user[count].userName);
	}
	return;
	getchar();
}
int searchUser(char key[],int *ada)
{
	int x;
	openFile(ada);
	for(x=0; x<(*ada); x++)
	{
		if(strcmp(key,user[x].userName)==0)
		{
			return x;
		}
	}
	return -1;
}
int searchItem(char key[],int count)
{
	int i;
	for(i=0; i<count; i++)
	{
		if(strcmp(key,barang[i].namaBarang)==0)
		{
			barang[i].status=1;
			return i;
		}
	}
	return -1;
}

void proTrans(int *index,char key[])
{
	int flag=0,test=-1;
	char barang[100];
	int count=0;
	openUser(&count,key);
	viewMyTransaction(&count,key);
	do
	{
		flag=0;
		printf("Insert Item Name ['cancel'] to exit this menu: ");
		scanf("%[^\n]",&barang);
		fflush(stdin);
		test = searchItem(barang,count);
		if(test!=-1)
		{
			flag=1;
			writeUser(&count,key);
			break;
		}
		else if(strcmpi(barang,"cancel")==0)
		{
			return;
		}
		else
		{
			flag=0;
		}
	}while(flag==0);
	
}
void adminMenu(int *counter)
{
	int choose, isi=0,count=0,ada=0,index;
	char key[100];
	system("cls");
    do
	{
		system("cls");
		printf("1. View All Transaction\n");
		printf("2. Process a Transaction\n");
		printf("3. View All User\n");
		printf("4. Log Out\n");
		printf("Choose : ");
		scanf("%d",&choose);
		fflush(stdin);
		switch(choose)
		{
		case 1:
			printf("|%-4s|%30s|%-20s|%-25s|%-20s|%-20s|%-10s|%-15s|\n","No.","Item Name","Amount","Dimension","Weight","Insurance","Repacking","Status");
			for(int space=0; space<152; space++)
			{
				printf("=");
			}
			printf("\n");
			viewAllTrans(&count,&isi);
			printf("\n");
			for(int space=0; space<152; space++)
			{
				printf("=");
			}
			printf("\n");
			printf("Press Enter To Continue\n");
			getchar();
			break;
		case 2:
			index = -1;
			printf("Insert username : ");
			scanf("%[^\n]",&key);
			fflush(stdin);
			index = searchUser(key,&ada);
			if(index==-1)
			{
				printf("Can't find %s!\n",key);
				getchar();
			}
			else
			{
				proTrans(&index,key);
				printf("Success!\n");
				getchar();
			}
			break;
		case 3:
			openAllUser();
			getchar();
			break;
		}
	}while(choose!=4);
	printf("Exiting admin menu...\nPress Enter to Continue...");
}



int main()
{
    title();
    char userLogin[100];
    char userPassword[100];
    int flag, counterEntry=0,test=0;
    int choose;
    printf("\nPress ENTER to Continue...");
    getchar();
    //Entering Main Menu
    do
    {
        //Main Menu
        system("cls");
        spacing();
        title();
        printf("\n\n\n\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Exit\nChoose: ");
        scanf("%d",&choose);
        fflush(stdin);
        puts("");
        switch(choose)
        {
        case 1: //Login Menu
			strcpy(userLogin,"");
			strcpy(userPassword,"");
            do
            {
                flag=0;
                system("cls");
                spacing();
                printf("Username : ");
                scanf("%[^\n]",&userLogin);
                fflush(stdin);
                printf("Password : ");
                scanf("%[^\n]",&userPassword);
                fflush(stdin);
                if(strcmp(userLogin,"admin")==0&&strcmp(userPassword,"admin")==0)
                {
                    flag=2;
                    //Entering Admin Menu
                    adminMenu(&counterEntry);
                    getchar();
                }
                else if(strcmpi(userLogin,"cancel")==0)
                {
                    printf("Cancelling user creation...\nPress Enter to Continue...");
                    flag=2;
					getchar();
					break;
                }
                else
                {
                    //Validate for User Menu
                    if(isUserExist(&counterEntry,userLogin)!=0&&isPassExist(&counterEntry,userPassword)!=0)
                    {
                        flag=1;
                    }
                    else
                    {
                        printf("Wrong Username/Password\n");
                        flag=0;
						getchar();
                    }
                }
            }while(flag==0);
            if(flag==1)
                userMenu(userLogin,&choose);
            break;
        case 2: //Register Menu
            system("cls");
            openFile(&counterEntry);
            registerUser(&counterEntry);
            getchar();
            break;
        case 3: //Exit
            exit(0);
            break;
        }

    }while(choose!=3);
	printf("Exiting program...\nPress ENTER to continue...\n");
    getchar();
    return 0;
}
