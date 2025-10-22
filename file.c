#include <stdio.h>
#include<stdlib.h>
#include "file.h"


void saveContactsToFile(AddressBook *addressBook) 
{
    
    FILE *fptr = fopen("contacts.csv","w");
    
    fprintf(fptr,"%d\n",addressBook->contactCount);
    int i ;
    for(i = 0;i< addressBook->contactCount; i++)
    {
        fprintf(fptr,"%s,",addressBook->contacts[i].name);
        fprintf(fptr,"%s,",addressBook->contacts[i].phone);
        fprintf(fptr,"%s\n",addressBook->contacts[i].email);
    }
    fclose(fptr);
  
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fptr = fopen("contacts.csv","r");
    if(fptr == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }
    char str[100];
    fscanf(fptr,"%s\n",str);
    int count = atoi(str);
    addressBook->contactCount = count;
    for(int i = 0;i < addressBook->contactCount ; i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fptr);
    
}
