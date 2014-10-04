
 int taille;
 
 void enre(void)
{
  printf("insert your data\n");
  printf("select field --1 math --2 english\n");
  scanf("%d",&input);

  switch(input){
    case 1: 
           wariate(); 
    case 2:
           wariate();
    default:
           printf("invalid option\n");
           break;
    }

 return; 
}

 void wariate(void)
{
  printf("how many field you need to add?\n");
  
  struct cordonnees *memo=malloc(taille); /* indicate the memory you need */
   
}
