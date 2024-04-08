#include<stdio.h>
#include<time.h>
#include<stdlib.h>
struct time {
    int day;
    int month;
    int year;
};
struct medication {
    char medicationname[100];
    int quantity;
    int price ;
    struct {
        int day;
        int month;
        int year;
    } manifacturingDate;
    struct {
        int day;
        int month;
        int year;
    } expiryDate;
    char brand[100];

  };
    // a proc that let the user enter the informations 
  void entermedication(struct medication med[] , int size){
        int i ;
    for(i=0;i<=size;i++){
            printf("input the medication name :\n");
            scanf("%s",med[i].medicationname);
            printf("input the Available quantity :\n");
            scanf("%d",&med[i].quantity);
            printf("input Unit price:\n");
            scanf("%d",&med[i].price);
            printf("input Manufacturing date:\n");
            scanf("%d/%d/%d",&med[i].manifacturingDate.day,&med[i].manifacturingDate.month,&med[i].manifacturingDate.year);
            printf("input the Expiry date:\n ");
            scanf("%d/%d/%d",&med[i].expiryDate.day,&med[i].expiryDate.month,&med[i].expiryDate.year);
            printf("input the Medication brand:\n");
            scanf("%s",med[i].brand );
            
 
          }
  }
  void displaymedication(struct medication med [] ,int size){
    int i;
    for(i=0;i<=size;i++){
      printf("the medication name:\n%s",med[i].medicationname );
      printf("the Available quantity:\n%d", med[i].quantity);
      printf("Unit price:\n%d",med[i].price );
      printf("the Manufacturing date:\n%d", &med[i].manifacturingDate.day,&med[i].manifacturingDate.month,&med[i].manifacturingDate.year);
      printf("the Expiry date:\n%d",&med[i].expiryDate.day,&med[i].expiryDate.month,&med[i].expiryDate.year);
      printf("the Medication brand:\n%s",med[i].brand );
}
  }
  
   int Expired(struct medication med [], int size ) {
       int i;
    time_t now = time(NULL); // it will give le nombre de sec depuis la premiere horloge Unix (en sec)
    struct tm currentTimeTm = *localtime(&now);  // elle contient les valeurs de l'heur en valeur entiere 
    for(i=0;i<=size;i++){
    struct tm expiryDateTm = {0}; 
    expiryDateTm.tm_mday = med[i].expiryDate.day;
    expiryDateTm.tm_mon = med[i].expiryDate.month - 1; 
    expiryDateTm.tm_year = med[i].expiryDate.year - 1900;
    time_t expiryTime = mktime(&expiryDateTm);
    
    
    if (now >= expiryTime) {
        return 1; // Médicament périmé
    } else {
        return 0; // Médicament valide
    }
}
   }
    

  int main() {
    
    int N,i;
     struct medication medec[100] ;
   
     
    time_t now = time (NULL); //  it stores the current time in the variable `now`.
     printf("\n=== PROJECT ALGO ===\n");

   
    

      // inputing the size of the array
        printf("input the size of your array:\n");
        scanf("%d", &N);

      //let the user enter the informations 
        entermedication(medec,N);
    
      if(Expired(medec,N)==0){
           printf("medicament non perimeee ");
      }
      else {
         printf("medicament perimee:\n");
      }

   
  
        
        


      
        


        
      return 0;
        
  }
