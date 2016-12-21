#include <stdio.h>

void **calloc_matrix2(int rows, int cols, int size);

/***************************************************************************
 * MEMORY MANAGEMENT ROUTINES
 ***************************************************************************/ 

void *my_malloc(int size)  /* size in bytes */
{
   void *space;
   
   if ((space = (void *)malloc(size)) == NULL) {
     printf("Error: Insufficient memory in my_malloc, size=%d\n", size);
     exit(-1);
   }
   return(space);
}

/***************************************************************************/ 

void *my_calloc(int num_elem, int size)
{
   void *space;
   
   if ((space = (void *)calloc(num_elem, size)) == NULL)
   {
      fprintf(stderr, "Error: Insufficient memory\n");
      exit(1);
   }
   return(space);
}

/***************************************************************************
 * MALLOC ROUTINES
 ***************************************************************************/ 

void *malloc_vector(int num_elem, int size)
{
   return(my_malloc(num_elem * size));
}

char *malloc_str(int num_elem)
{
   return((char *)my_malloc(num_elem * sizeof(char)));
}

/***************************************************************************/ 

void **malloc_matrix2(int rows, int cols, int size)
{
   register int i; 
   void **m;

   m = (void **) my_malloc(rows * sizeof(void *));
   for (i = 0; i < rows; i++) 
      m[i] = malloc_vector(cols, size);
   return(m);
}

/***************************************************************************/ 

void ***malloc_matrix3(int a, int b, int c, int size)
{
   register int i;
   void ***matrix;

   matrix = (void ***) my_malloc(a * sizeof(void **));
   for (i = 0; i < a; i++)
      matrix[i] = malloc_matrix2(b, c, size);
   return(matrix);
}

/***************************************************************************/ 

void ****malloc_matrix4(int a, int b, int c, int d, int size)
{
   register int i;
   void ****matrix;

   matrix = (void ****) my_malloc(a * sizeof(void ***));
   for (i = 0; i < a; i++)
      matrix[i] = malloc_matrix3(b, c, d, size);
   return(matrix);
}

/***************************************************************************/ 

void *****malloc_matrix5(int a, int b, int c, int d, int e, int size)
{
   register int i;
   void *****matrix;

   matrix = (void *****) my_malloc(a * sizeof(void ****));
   for (i = 0; i < a; i++)
      matrix[i] = malloc_matrix4(b, c, d, e, size);
   return(matrix);
}

/***************************************************************************/ 

/***************************************************************************
 * CALLOC ROUTINES
 ***************************************************************************/ 

void *calloc_vector(int num_elem, int size)
{
   return(my_calloc(num_elem, size));
}

/***************************************************************************/ 

void **calloc_matrix2(int rows, int cols, int size)
{
   register int i; 
   void **m;

   m = (void **) my_calloc(rows, sizeof(void *));
   for (i = 0; i < rows; i++) 
      m[i] = calloc_vector(cols, size);
   return(m);
}

/***************************************************************************/ 

void ***calloc_matrix3(int a, int b, int c, int size)
{
   register int i;
   void ***matrix;

   matrix = (void ***) my_calloc(a, sizeof(void **));
   for (i = 0; i < a; i++)
      matrix[i] = calloc_matrix2(b, c, size);
   return(matrix);
}

/***************************************************************************/ 

void ****calloc_matrix4(int a, int b, int c, int d, int size)
{
   register int i;
   void ****matrix;

   matrix = (void ****) my_calloc(a, sizeof(void ***));
   for (i = 0; i < a; i++)
      matrix[i] = calloc_matrix3(b, c, d, size);
   return(matrix);
}

/***************************************************************************/ 

void *****calloc_matrix5(int a, int b, int c, int d, int e, int size)
{
   register int i;
   void *****matrix;

   matrix = (void *****) my_calloc(a, sizeof(void ****));
   for (i = 0; i < a; i++)
      matrix[i] = calloc_matrix4(b, c, d, e, size);
   return(matrix);
}

/***************************************************************************/ 

void ******calloc_matrix6(int a, int b, int c, int d, int e, int f, int size)
{
   register int i;
   void ******matrix;

   matrix = (void ******) my_calloc(a, sizeof(void *****));
   for (i = 0; i < a; i++)
      matrix[i] = calloc_matrix5(b, c, d, e, f, size);
   return(matrix);
}

/***************************************************************************/ 

void *******calloc_matrix7(int a, int b, int c, int d, int e, int f, int g, int size)
{
   register int i;
   void *******matrix;

   matrix = (void *******) my_calloc(a, sizeof(void ******));
   for (i = 0; i < a; i++)
      matrix[i] = calloc_matrix6(b, c, d, e, f, g, size);
   return(matrix);
}

/***************************************************************************/ 

void ********calloc_matrix8(int a, int b, int c, int d, int e, int f, int g, int h, int size)
{
   register int i;
   void ********matrix;

   matrix = (void ********) my_calloc(a, sizeof(void *******));
   for (i = 0; i < a; i++)
      matrix[i] = calloc_matrix7(b, c, d, e, f, g, h, size);
   return(matrix);
}

/***************************************************************************
 * FREE ROUTINES
 ***************************************************************************/

void free_matrix2(void **matrix, int rows)
{
   register int i; 

   for (i = 0; i < rows; i++)
      free(matrix[i]);
   free(matrix);
}

void free_matrix3(void ***matrix, int a, int b)
{
   register int i; 

   for (i = 0; i < a; i++)
      free_matrix2(matrix[i], b);
   free(matrix);
}

void free_matrix4(void ****matrix, int a, int b, int c)
{
   register int i;

   for (i = 0; i < a; i++)
      free_matrix3(matrix[i], b, c);
   free(matrix);
}

void free_matrix5(void *****matrix, int a, int b, int c, int d)
{
   register int i;

   for (i = 0; i < a; i++)
      free_matrix4(matrix[i], b, c, d);
   free(matrix);
}

void free_matrix6(void ******matrix, int a, int b, int c, int d, int e)
{
   register int i;

   for (i = 0; i < a; i++)
      free_matrix5(matrix[i], b, c, d, e);
   free(matrix);
}

void free_matrix7(void *******matrix, int a, int b, int c, int d, int e, int f)
{
   register int i;

   for (i = 0; i < a; i++)
      free_matrix6(matrix[i], b, c, d, e, f);
   free(matrix);
}

void free_matrix8(void ********matrix, int a, int b, int c, int d, int e, int f, int g)
{
   register int i;

   for (i = 0; i < a; i++)
      free_matrix7(matrix[i], b, c, d, e, f, g);
   free(matrix);
}

/***************************************************************************/ 
