#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include <stdarg.h>
#include <errno.h>


#define QUERY_SIZE 256

#define BUFFER_SIZE 80

static void error_fatal (char *format, ...);

int
main (int argc, char **argv)
{
    MYSQL *konekcija2;
    MYSQL *konekcija;
    MYSQL_RES *rezultat;
    MYSQL_ROW red;
    MYSQL_FIELD *polje;
    int i;
    int broj;

    char query[QUERY_SIZE];
    char buffer[BUFFER_SIZE];

    konekcija = mysql_init (NULL);
    
    if (mysql_real_connect
        (konekcija, "localhost", "nikola", "nikola", "veleprodaja", 0, NULL,
        0) == NULL)
        error_fatal ("Greska u konekciji. %s\n", mysql_error (konekcija));
        
    konekcija2 = mysql_init (NULL);
    
    if (mysql_real_connect
        (konekcija2, "localhost", "pera", "pera", "veleprodaja", 0, NULL,
        0) == NULL)
        error_fatal ("Greska u konekciji. %s\n", mysql_error (konekcija2));    

    sprintf (query, "select * from Porudzbina");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("PORUDZBINE:\n");
    
    printf ("%s\t%s\t%s\n", polje[0].name, polje[1].name, polje[2].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    sprintf (query, "select * from Dokument");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("DOKUMENTI:\n");
    
    printf ("%s\t%s\t\t\t%s\t\t\t%s\n", polje[0].name, polje[1].name, polje[2].name, polje[3].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    sprintf (query, "select * from Izradjuje");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("KO IZRADJUJE DOKUMENTE:\n");
    
    printf ("%s\t%s\t\%s\n", polje[0].name, polje[1].name, polje[2].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    int idKupca;
    char datum[20];
    printf("Unosenje nove porudzbine.\nUnesite idKupca:");
    scanf("%d", &idKupca);
  
    printf("Koji je datum pristizanja porudzbine:\n");
    scanf("%s", &datum);

    sprintf(query, "INSERT INTO `Porudzbina`(Kupac_idKupac, DatumPorudzbine) VALUES (\"%d\", \"%s\");", idKupca, datum);

    if (mysql_query(konekcija, query) != 0)
        error_fatal("Greska u upitu %s\n", mysql_error (konekcija));
        
    mysql_free_result (rezultat);    
        
    sprintf (query, "select * from Porudzbina");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("PORUDZBINE:\n");
    
    printf ("%s\t%s\t%s\n", polje[0].name, polje[1].name, polje[2].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    sprintf (query, "select * from Dokument");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("DOKUMENTI:\n");
    
    printf ("%s\t%s\t\t\t%s\t\t\t%s\n", polje[0].name, polje[1].name, polje[2].name, polje[3].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    sprintf (query, "select * from Izradjuje");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("KO IZRADJUJE DOKUMENTE:\n");
    
    printf ("%s\t%s\t\%s\n", polje[0].name, polje[1].name, polje[2].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);    

    printf("Azuriranje porudzbine od strane drugog korisnika.\n");
    
    int idPorudzbine;
    printf("Unesite idPorudzbine:\n");
    scanf("%d", &idPorudzbine);
    
    printf("Datum pristizanja porudzbine:\n");
    scanf("%s", &datum);

    sprintf(query,  "UPDATE Porudzbina SET DatumPorudzbine = \"%s\" WHERE idPorudzbina = \"%d\";", datum,idPorudzbine);

    if (mysql_query(konekcija2, query) != 0)
        error_fatal("Greska u upitu %s\n", mysql_error (konekcija2));
        
    mysql_free_result (rezultat);  
    
    sprintf (query, "select * from Porudzbina");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("PORUDZBINE:\n");
    
    printf ("%s\t%s\t%s\n", polje[0].name, polje[1].name, polje[2].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    sprintf (query, "select * from Dokument");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("DOKUMENTI:\n");
    
    printf ("%s\t%s\t\t\t%s\t\t\t%s\n", polje[0].name, polje[1].name, polje[2].name, polje[3].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    sprintf (query, "select * from Izradjuje");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("KO IZRADJUJE DOKUMENTE:\n");
    
    printf ("%s\t%s\t\%s\n", polje[0].name, polje[1].name, polje[2].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);  
    
    mysql_close (konekcija);

    exit(EXIT_SUCCESS);
}

static void error_fatal (char *format, ...)
{
    va_list arguments;		/* Lista argumenata funkcije. */

    /* Stampa se string predstavljen argumentima funkcije. */
    va_start (arguments, format);
    vfprintf (stderr, format, arguments);
    va_end (arguments);

    /* Prekida se program. */
    exit (EXIT_FAILURE);
}
