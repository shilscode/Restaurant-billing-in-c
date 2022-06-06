#include<stdio.h>
#include<string.h>
#include<stdlib.h>


double price[7] = {150.80 , 100.50 , 190.00 , 140.00 , 100.00 , 220.00 , 16.00 };
double mealTaxPrices[7];
int adultNumber;


void printMeals();
void orderMeals();
double orderForAdult();

int main()
{
    char response = 'y';
    
     
     printMeals();
     while(response == 'y'|| response == 'Y')
    {

            printf("please enter number of People  :");
            scanf("%d",&adultNumber);
            

            
                       
            orderMeals();
            
            printf("\nwould you like to continue(y/n):");
            scanf("\n%c",&response);
    }
  
 printf("\n      ******************** THANK YOU FOR COMING  *************************\n");
 printf("\20**********************   PLEASE VISIT US NEXT TIME  **************************\20 \n");
   system("pause");
   return 0;
}

void printMeals()
{
     
      printf("\20*******************  Welcome to Shil's Coffee House **************************\20\n");
      printf(" \t\t\t Below is the menue:\20\n");
      printf(" \t\t\t Items\t\t\tPRICE:\n");
      printf(" \t\t\t \22*******************************\22\n");
      printf(" \t\t\t 1- Coffee\t\t  150.80\n");
      printf(" \t\t\t 2- Tea\t\t\t  100.50\n");
      printf(" \t\t\t 3- Cold Coffee\t\t  190.00\n");
      printf(" \t\t\t 4- Chicken Chop\t  140.00\n");
      printf(" \t\t\t 5- Snacks\t\t  100.00\n");
      printf(" \t\t\t 6- Mutton chop\t\t  220.00\n");
      printf(" \t\t\t 7- Water Bottle\t  6.00\n");
      
      
      
      printf("\n");
}
void orderMeals()
{
	double totalPriceForAdult;
	double allPayment,discount;
         printf("                      \t\t**** ORDER MENUE****\n");  
         
         
        totalPriceForAdult =  orderForAdult();
        
		allPayment = totalPriceForAdult  ;
        
     printf("\n \t\t       \22**************************************\22    \n");
     printf(" \t\t   ******************  final BILL   ************      \n");
     printf(" \t\t\tPeople\t\tcount\t\ttotal price\n");
     printf(" \t\t\tadults\t\t%d\t\t%5.2f\n",adultNumber,totalPriceForAdult);
     
     printf(" \t\t\tTotal bill\t\t\t%5.2f\n",allPayment );
      
	 
     
     if(allPayment < 10)
		 discount=((allPayment * 0.5)/100);
     else if(allPayment>= 10 && allPayment<20)
          discount=((allPayment * 1)/100);
     else if(allPayment>= 20 && allPayment<30)
          discount=((allPayment * 1.5)/100);
     else if(allPayment>= 30 && allPayment<40)
          discount=((allPayment * 2.0)/100);
	 else 
		  discount= ((allPayment * 5.0)/100);

          printf(" \t\t\tTotal bill after discount\t%5.2f\n",allPayment-discount);

}
double orderForAdult()
{
     int menuOption,i,amount;
      char response = 'y';
      double totalPerPerson = 0.0,totalAllPerson = 0.0;
      double tax = 5.0;
      if(adultNumber <=0)
		   printf("\n ");
	  else 
      printf("*\tadults:\n");
      for(i=0;i<adultNumber;i++)
     {
               printf("Person%d  please enter your orders\n",i+1);
               while(response == 'y' || response == 'Y')
               {
                              printf("please enter your option:");
                              scanf("%d",&menuOption);
							  if(menuOption<1 || menuOption>7)
							  {
								  printf("sorry we don`t have this order \nagain! ");
								  continue;
							  }
                              printf("please enter your amount of order:");
                              scanf("%d",&amount);
                              
                              
                           totalPerPerson = totalPerPerson + (amount * price[menuOption - 1] );
                              
                              printf("\nWould you like to enter more orders(y/n):");
                              scanf("\n%c",&response);
               
                              
                           
               }
               printf("\n");
               totalAllPerson += totalAllPerson +  totalPerPerson;
               totalPerPerson = 0.0;
               response = 'y';
     }
     
     return totalAllPerson + ((totalAllPerson * tax) / 100);
}

