#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;


void matrisilistele(string matris[5][5]){
    cout<<"------------------------------\n";
    for(int i=0;i<5;i++){
    cout<<"|";
     for(int j=0;j<5;j++){
      cout<<setw(5)<<matris[i][j];
     }
      cout<<setw(4)<<"|";
      cout<<endl;
    }
    cout<<"------------------------------\n";
}

int main(){
    srand(time(0));
    string matris[5][5],sayi,mayin[5];  //Daha sonradan uygun sayilarin yerine karakter yazilacagi icin matris string tanimlandi.
    int satir,sutun,deneme=0;
    
    cout<<"---------MATRISLER ILE MAYIN TARLASI OYUNU---------\n\n";
    
    for(int i=0;i<5;i++)
       for(int j=0;j<5;j++){
         int s=rand()%50+1;
         matris[i][j]=to_string(s);
       }
 
 cout<<"->Oyunun Kurallari:\n#5x5'lik matriste 5 tane mayin vardir.\n#Matriste bulunan fakat mayin olmayan sayilari secmelisiniz.\n";
 cout<<"#Eger mayinlardan birini secerseniz oyun biter.\n#Sectiginiz sayi dogru bir secim ise sayi yerine X yazilir.\n";
 cout<<"#Dogru bir secim yaptiysaniz tek uyari sesi, mayin sectiyseniz 3 uyari sesi verilir.\n#Iyi sanslar!\n\n";
 
 //Matristeki mayin olacak sayilari secme
 for(int s=0;s<5;s++){
    int i=rand()%5;
    int j=rand()%5;
 mayin[s]=matris[i][j];
 }
 
 matrisilistele(matris);
 
 do{
     int i;
     bool bulundu=false;
     do{
         cout<<endl<<deneme+1<<". Deneme\n";
 cout<<"\nBir sayi giriniz:"; cin>>sayi;
 
 for(i=0;i<5;i++){
   for(int j=0;j<5;j++)
   if(sayi==matris[i][j]){
       satir=i;
       sutun=j;
       bulundu=true;
       break;
   }
   if(bulundu==true)
   break;
 }
   //Girilen sayi matriste bulunuyor mu?
   if(!bulundu)
   cout<<"Bu sayi matriste bulunmuyor.Tekrar deneyiniz!\n";
   else
   break;
    }while(true);
 
// Sayinin mayin olup olmadigini kontrol etme:
bool mayinbulundu=false;
for(i=0;i<5;i++)
   if(sayi==mayin[i]){
   cout<<"\a\a\aMAYINI SECTINIZ ve maalesef "<<deneme+1<<".denemede kaybettiniz!\n\n";
   cout<<"Matristeki mayinlar:\n";
   for(int j=0;j<4;j++)
   cout<<mayin[j]<<"-";
   cout<<mayin[4];
   mayinbulundu=true;
   break; //for dongusunden cikar
   }
   
   if(mayinbulundu)
   break;  //do while dongusunden cikar
   
   //Bu satira ulasildiysa sayi mayin degildir ve matriste bulunuyordur.
   cout<<"IYI SECIM! Devam edin.\n\n";
   matris[satir][sutun]="X";
   satir=-1,sutun=-1;
   cout<<"Guncellenen matris:\n";
   matrisilistele(matris);
   cout<<"\a";
 
    deneme++;
    }while(deneme!=20);

    if(deneme==20)
    cout<<"\n\n----------OYUNU KAZANDINIZ!----------\nTEBRIKLER BUTUN SAYILARI DOGRU BILDINIZ VE HICBIR MAYINA YAKALANMADINIZ!";
    
    return 0;
}