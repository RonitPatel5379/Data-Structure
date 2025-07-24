#include<stdio.h>
#include<string.h>
int main()
{
    char arr[100];
    printf("Enter the string:");
    scanf(" %[^\n]",&arr);
    for(int i=0;i<strlen(arr);i++){
        int ascii=arr[i];
        if(ascii>=65 && ascii<=97){
            ascii+=32;
            arr[i]=ascii;
        }
        else if(ascii>=97 && ascii<=122){
            ascii-=32;
            arr[i]=ascii;
        }
        else{
             printf("enter valid charcter..");
        }
    }
    for(int i=0;i<strlen(arr);i++){
    printf("%[^\n]",arr[i]);
}
    return 0;
}