    #include<stdio.h>  
    struct student  
    {  
        char name[10];  
        int id;  
        float marks;  
    };  
    void main()  
    {  
        struct student s1,s2,s3;  
        s1.name[1]='c';
        s1.id=1;
        s1.marks=10;

        s2.name[2]='b';
        s2.id=1;
        s2.marks=10;
        
        s3.name[3]='a';
        s3.id=1;
        s3.marks=10;

        printf("%c,%d,%f",s1.name,s1.id,s1.marks);
        printf("%c,%d,%f",s2.name,s2.id,s2.marks);
        printf("%c,%d,%f",s3.name,s3.id,s3.marks);

     }  

