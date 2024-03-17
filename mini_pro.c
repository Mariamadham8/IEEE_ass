#include<stdio.h>
#include <time.h>
#include<string.h>
#include<stdbool.h>


//our needed global variables
float totalprice=0;
char ordered[][20];
int amount[200];
float f_prices[]={20,30,40,50,50};
float d_prices[]={10,5,12,20};
float fa_prices[]={100,140,80};
float s_prices[]={2,15,10};
char name[100];
char address[100];
int phone ,num_ordered_items=0 ,pricee;
float item_prices[200]; // Array to store the price of each item


//functions proto_types
void cos_info();
void fr_item();
void fats();
void sweets();
void dairies();
void category();
void choice();
void keep_shopping();
void recipt();
void delivery_option();
void discount();
bool checkDeliveryCost() ;



//------------------------------------------------------------------------------
int main(){
     printf("               Welcome to our store!                 \n");
     printf("--------------------------------------------------------\n");

      printf("Services:\n"
           "Press 1 to choose category\n"
           "Press 2 to print the receipt\n"
           "Press 3 to know the latest offers\n"
           "press 4 to delete specific item\n");

     printf("--------------------------------------------------------\n");
       

cos_info();
choice();


}
//--------------------------------------------------------------------------------------
void fr_item() {
    char available[][20] = {"orang", "tomato", "banana", "onion", "potato"};
    char item[20];

    printf("Enter the item you want to check: ");
    scanf("%s", &item);

    int found = 0;
   
    for (int i = 0; i < sizeof(available) / sizeof(available[0]); i++) {
        if (strcmp(item, available[i]) == 0) {
            found = 1;
            pricee =i;
            break;
        }
    }

    if (found) {
        int num;
        printf("%s is available.\n", item);
        printf("Price per item: $%.2f\n", f_prices[pricee]); // Print price if item is found
        printf("Enter number of items: ");
        scanf("%d", &num);
        strcpy(ordered[num_ordered_items], item); // Copy the item name to the ordered array
        amount[num_ordered_items] = num;   // Assuming amount is an array of integers
        item_prices[num_ordered_items] = f_prices[pricee]; // Store the price of the current item
          num_ordered_items++; 
       
        totalprice = totalprice +(f_prices[pricee]*num); 
        
        
        printf("the total till now = %.2f\n",totalprice);
        keep_shopping();
    } else {
        printf("%s is not available.\n", item);
       keep_shopping();
    }
}
//--------------------------------------------------------------------------------------
 void dairies(){
 char available[][20] = {"milk", "egg", "cheese", "yougrt"};
    char item[20];

    printf("Enter the item you want to check: ");
    scanf("%s", &item);

    int found = 0;
   
    for (int i = 0; i < sizeof(available) / sizeof(available[0]); i++) {
        if (strcmp(item, available[i]) == 0) {
            found = 1;
            pricee =i;
            break;
        }
    }

    if (found) {
        int num;
        printf("%s is available.\n", item);
        printf("Price per item: $%.2f\n", d_prices[pricee]); // Print price if item is found
        printf("Enter number of items: ");
        scanf("%d", &num);
         strcpy(ordered[num_ordered_items], item); // Copy the item name to the ordered array
          amount[num_ordered_items] = num;   // Assuming amount is an array of integers
           item_prices[num_ordered_items] = d_prices[pricee]; // Store the price of the current item
          num_ordered_items++; 
       
        totalprice = totalprice +(d_prices[pricee]*num);
        
        printf("the total till now = %.2f\n",totalprice);
        keep_shopping();
    } else {
        printf("%s is not available.\n", item);
       keep_shopping();
    }
}
//----------------------------------------------------------------------------------------
void fats(){
 char available[][20] = {"meet", "chicken", "fish"};
    char item[20];

    printf("Enter the item you want to check: ");
    scanf("%s", &item);

    int found = 0;
   
    for (int i = 0; i < sizeof(available) / sizeof(available[0]); i++) {
        if (strcmp(item, available[i]) == 0) {
            found = 1;
            pricee =i;
            break;
        }
    }

    if (found) {
        int num;
        printf("%s is available.\n", item);
        printf("Price per item: $%.2f\n", fa_prices[pricee]); // Print price if item is found
        printf("Enter number of items: ");
        scanf("%d", &num);
         strcpy(ordered[num_ordered_items], item); // Copy the item name to the ordered array
          amount[num_ordered_items] = num;   // Assuming amount is an array of integers
           item_prices[num_ordered_items] = fa_prices[pricee]; // Store the price of the current item
          num_ordered_items++; 
       
        totalprice = totalprice +(fa_prices[pricee]*num);
        
        printf("the total till now = %.2f\n",totalprice);
        keep_shopping();
    } else {
        printf("%s is not available.\n", item);
       keep_shopping();
    }
}

//-----------------------------------------------------------------------------------------
 sweets(){
    char available[][20] = {"candy", "cokiess", "chips"};
    char item[20];

    printf("Enter the item you want to check: ");
    scanf("%s", &item);

    int found = 0;
   
    for (int i = 0; i < sizeof(available) / sizeof(available[0]); i++) {
        if (strcmp(item, available[i]) == 0) {
            found = 1;
            pricee =i;
            break;
        }
    }

    if (found) {
        int num;
        printf("%s is available.\n", item);
        printf("Price per item: $%.2f\n", s_prices[pricee]); // Print price if item is found
        printf("Enter number of items: ");
        scanf("%d", &num);
         strcpy(ordered[num_ordered_items], item); // Copy the item name to the ordered array
          amount[num_ordered_items] = num;   // Assuming amount is an array of integers
           item_prices[num_ordered_items] = s_prices[pricee]; // Store the price of the current item
          num_ordered_items++; 
       
        totalprice = totalprice +(s_prices[pricee]*num);
        
        printf("the total till now = %.2f\n",totalprice);
        keep_shopping();
    } else {
        printf("%s is not available.\n", item);
       keep_shopping();
    }

 }
//------------------------------------------------------------------------------------
void category() {
    int ch;
    printf("-------------------------\n");
    printf("Fruits & Vegetables --> Press 1\n"
           "Dairies --> Press 2\n"
           "Fats --> Press 3\n"
           "Sweets --> Press 4\n");
    scanf("%d", &ch);
    switch (ch) {
        case 1:
            fr_item();
            break;
        case 2:
             dairies();
            break;
        case 3:
             fats();
            break;
        case 4:
             sweets();
            break;
    }
}
//---------------------------------------------------------------------------------
void recipt() {
    printf("\n");
    printf("-----------------------------------RECIPT INFO------------------------------------------\n");
        int y=0,v=0;
          printf("hello MR/MSS:");
         while (name[y] != '\0') {
        printf("%c", name[y]);
        y++;
    }
    printf("\n");
    printf("your address is:");
     while (address[v] != '\0') {
        printf("%c", address[v]);
        v++;
    }
    printf("\n");
    printf("your phone number:%d\n",phone);
    printf("--------------------------------------------------------------------------------\n");
     for (int i = 0; i < num_ordered_items; i++) { 
    printf("your list of oreders:%s        amount:%d         price of this item:%.2f      total price of the item amount :%.2f \n",ordered[i],amount[i],item_prices[i],item_prices[i]*amount[i]);
    }

    printf("-------------------------------------------\n");
    printf("total price without delivery = %.2f \n",totalprice );
    printf("-------------------------------------------\n");
     delivery_option();
       discount();
   
   
    }
    

//-----------------------------------------------------------------------------------

void choice() {
    int n;
    printf("Enter needed service: ");
    scanf("%d", &n);
    switch (n) {
        case 1:
            category();
            break;
        case 2:
            recipt();
            break;
        case 3:
            printf("Buy more than 5 items and gain 20 percent off.\n");
            break;
        case 4:
            // delete();
            break;
        case 5:
            category();
            break;
    }
}

//------------------------------------------------------------------------------------
void cos_info(){

printf("               contact info       \n");


printf("please enter your 2 name : \n");
for(int i=0;i<100;i++){
  scanf("%c",&name[i]);
   if (name[i] == '\n') {
            name[i] = '\0'; // Null-terminate the string
            break; // Exit the loop
   }
  
}

 printf("Please enter your address:       (format:town-street_name-bulding_number )\n");
    for (int i = 0; i < 100; i++) {
        scanf("%c", &address[i]);
        if (address[i] == '\n') {
            address[i] = '\0'; // Null-terminate the string
            break; // Exit the loop
        }
    }

printf("please enter your phone_ number: \n");
scanf("%d",&phone);
}
//----------------------------------------------------------------------------------------




void keep_shopping(){
   printf("do you want continue? (1 for yes/2 for no print recipt /3 end the whole process)");
        int x;
        scanf("%d",&x);
        if(x==1){
            printf("choose service");
            choice();
        }
        else if(x==2){
          recipt();
        }
        else{
            printf("thank you for visiting us");
        }
}


//------------------------------------------------------------------------------------------


void delivery_option(){
    
   int sum = 0; 
   for (int i = 0; i < sizeof(amount) / sizeof(amount[0]); i++) {
    sum += amount[i];
    }

    if(sum <2){
        printf("we are sorry to inform you that we can not deliver less than 2 items\n");
        keep_shopping();
    }
   
    else if(totalprice<10){
        printf("the total shipping =2\n");
        printf("total count =%.2f",totalprice+2);
        if( checkDeliveryCost()) {
        printf("total cosst =%.2f ",totalprice+5);
        printf("---------------------------------------");
        keep_shopping();

    }
    }
    else if(totalprice>10){
        printf("the total shipping =3$\n");
       totalprice += 3;
        printf("total count =%.2f$\n",totalprice);
        if( checkDeliveryCost()) {
             totalprice +=5;
        printf("total cosst =%.2f\n ",totalprice);
        printf("---------------------------------------");
        keep_shopping();
    }
    }
}
//-----------------------------------------------------------------------------------
void discount(){
     int sum = 0; 
   for (int i = 0; i < sizeof(amount) / sizeof(amount[0]); i++) {
    sum += amount[i];
    }
    if(sum>=5){
        printf("thank you to use our offer due to buying more than 5 items you have 20 percent discount\n ");
        printf("total peice = %.2f \n",totalprice-(totalprice*.2));
    }
}
//-----------------------------------------------------------------------------------
bool checkDeliveryCost() {
      // Get the current time
    time_t current_time = time(NULL);
    int current_hour = localtime(&current_time)->tm_hour;

    // Check if the current hour is greater than or equal to midnight (0)
    if (current_hour >= 0 && current_hour < 5) { // Assuming midnight to 5 AM
        printf("It's past midnight. The delivery cost will be $5.\n");
        return true;
    } else {
        printf("It's not past midnight. No additional delivery cost.\n");
        return false;
    }
}
